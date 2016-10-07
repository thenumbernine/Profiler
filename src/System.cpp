#include "Profiler/System.h"
#include "Common/Exception.h"
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

namespace Profiler {

System::System()
: currentProfiler(NULL)
, rootName(NULL)
, frames(0)
{}

System::~System() {
	if (rootName) {
	
		//sort profiles by minimum duration excluding children
		std::vector<std::pair<const char *, double> > profileOrder;
		std::for_each(profileMap.begin(), profileMap.end(), [&](const std::pair<const char *, Entry> &pair) {
			profileOrder.push_back(std::pair<const char *, double>(pair.first, pair.second.durationExcludingChildren.min));
		});
		std::sort(profileOrder.begin(), profileOrder.end(), [&](std::pair<const char *, double> a, std::pair<const char *, double> b) {
			return a.second > b.second;
		});
		int order = 0;
		std::for_each(profileOrder.begin(), profileOrder.end(), [&](std::pair<const char *, double> pair){
			profileMap[pair.first].order = ++order;
		});
		
		profileMap[rootName].print();
	}
	//else throw Exception() << "need to run Profiler at least once";
	
	std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = endTime - beginTime;
	double duration = diff.count();
	std::cout << "Average FPS: " << frames / duration << std::endl;
}


void System::beginFrame() {
	static bool initd = false;
	if (!initd) {
		initd = true;
		beginTime = std::chrono::high_resolution_clock::now();
		frames = 0;
	}
	//initialize accum values of all entries to zero
	for (std::map<const char *, Entry>::iterator i = profileMap.begin(); i != profileMap.end(); ++i) {
		i->second.accumDuration = 0;
		i->second.accumDurationExcludingChildren = 0;
	}
}

void System::endFrame() {
	//record accum values into stat values 
	for (std::map<const char *, Entry>::iterator i = profileMap.begin(); i != profileMap.end(); ++i) {
		i->second.duration.accum(i->second.accumDuration);
		i->second.durationExcludingChildren.accum(i->second.accumDurationExcludingChildren);
	}
	++frames;
}

};

