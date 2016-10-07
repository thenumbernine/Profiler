#include "Profiler/Block.h"
#include "Profiler/Profiler.h"

namespace Profiler {

Block::Block(const char *name_) : name(name_) {
	lastProfiler = system->currentProfiler;
	system->currentProfiler = this;
	startTime = std::chrono::high_resolution_clock::now();
	subDurations = 0;
}

Block::~Block() {
	std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = endTime - startTime;
	double duration = diff.count();
	if (lastProfiler) {
		lastProfiler->subDurations += duration;
	}

	system->rootName = name;
	system->currentProfiler = lastProfiler;

	Entry &entry = system->profileMap[name];
	entry.name = name;
	entry.accumDuration += duration;
	entry.accumDurationExcludingChildren += duration - subDurations;
	if (lastProfiler) {
		entry.parentName = lastProfiler->name;
		system->profileMap[lastProfiler->name].childNames[entry.name] = true;
	}
}

};

