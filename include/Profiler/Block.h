#pragma once

#include <chrono>

namespace Profiler {

struct Block {
	
	const char *name;
	std::chrono::high_resolution_clock::time_point startTime;
	double subDurations;

	Block *lastProfiler;
	
	Block(const char *name_);
	~Block();
};

}
