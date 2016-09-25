#pragma once

#include "Profiler/Entry.h"
#include "Profiler/Block.h"
#include <map>

namespace Profiler {

struct System {
	std::map<const char *, Entry> profileMap;
	Block *currentProfiler;
	const char *rootName;
	double beginTime;
	double frames;
	
	System();
	~System();
	void beginFrame();
	void endFrame();
};

};
