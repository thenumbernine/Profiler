#pragma once

namespace Profiler {

struct Block {
	
	const char *name;
	double startTime, subDurations;

	Block *lastProfiler;
	
	Block(const char *name_);
	~Block();
};

};

