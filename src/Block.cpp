#include "Profiler/Block.h"
#include "Profiler/Profiler.h"
#include "Profiler/getTime.h"

namespace Profiler {

Block::Block(const char *name_) : name(name_) {
	lastProfiler = system->currentProfiler;
	system->currentProfiler = this;
	startTime = getTime();
	subDurations = 0;
}

Block::~Block() {
	double endTime = getTime();
	double duration = endTime - startTime;
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

