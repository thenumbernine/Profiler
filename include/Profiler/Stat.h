#pragma once

#include <iostream>

namespace Profiler {

//taken from universe/offline/Stat
//put in Math::Stat?
struct Stat {
	double v, n;
	double avg, sqavg;
	double min, max;
	
	Stat();
	void accum(double v);
	double stddev();
};

std::ostream &operator<<(std::ostream &o, Stat &stat);

};
