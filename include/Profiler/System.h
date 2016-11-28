#pragma once

#include "Profiler/Entry.h"
#include "Profiler/Block.h"
#include <map>
#include <chrono>

namespace Profiler {

struct System {
	std::map<const char *, Entry> profileMap;
	Block *currentProfiler;
	const char *rootName;
	std::chrono::high_resolution_clock::time_point beginTime;
	double frames;
	
	System();
	~System();
	void beginFrame();
	void endFrame();
};

}
