#include "Profiler/Entry.h"
#include "Profiler/Profiler.h"
#include <iostream>
#include <algorithm>

namespace Profiler {

Entry::Entry()
: accumDuration(0)
, accumDurationExcludingChildren(0)
, name(NULL)
, parentName(NULL)
, order(0)
{}

void Entry::print(int spaces) {
	std::cout << "#" << order << "\t";
	for (int i = 0; i < spaces; ++i) std::cout << " ";
	std::cout 
		<< "duration " << durationExcludingChildren
		<< " inclusive " << duration
		<< " \t"
		<< name << std::endl;
	++spaces;	
	std::for_each(childNames.begin(), childNames.end(), [&](std::pair<const char *, bool> v) {
		system->profileMap[v.first].print(spaces);
	});
}

};

