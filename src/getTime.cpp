#include <sys/time.h>

namespace Profiler {

double getTime() {
	timeval t;
	gettimeofday(&t, nullptr);
	return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
}

};

