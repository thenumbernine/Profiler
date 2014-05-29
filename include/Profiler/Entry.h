#pragma once

#include "Profiler/Stat.h"
#include <map>

namespace Profiler {

struct Entry {
	Stat duration;
	Stat durationExcludingChildren;
	double accumDuration;
	double accumDurationExcludingChildren;
	const char *name;
	const char *parentName;
	int order;

	Entry();
	void print(int spaces = 0);
	std::map<const char *, bool> childNames;
};

};

