#include "Profiler/System.h"
#include "Profiler/getTime.h"
#include "Common/Exception.h"
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

namespace Profiler {

System::System()
: currentProfiler(NULL)
, rootName(NULL)
, beginTime(0)
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
	
	std::cout << "Average FPS: " << frames / (getTime() - beginTime) << std::endl;
}


void System::beginFrame() {
	static bool initd = false;
	if (!initd) {
		initd = true;
		beginTime = getTime();
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

