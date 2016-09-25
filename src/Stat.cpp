#include "Profiler/Stat.h"
#include <cmath>

namespace Profiler {

Stat::Stat() 
: v(0)
, n(0)
, avg(0)
, sqavg(0)
, min(HUGE_VAL)
, max(-HUGE_VAL)
{}

void Stat::accum(double v) {
	++n;
	min = std::min(min, v);
	max = std::max(max, v);
	avg += (v - avg) / n;
	sqavg += (v * v - sqavg) / n;
}

double Stat::stddev() { 
	return sqrt(sqavg - avg * avg);
}

std::ostream &operator<<(std::ostream &o, Stat &stat) {
	return o << "[" << stat.min << " ... " << stat.avg << " +- " << stat.stddev() << " ... " << stat.max << "]";
}

};

