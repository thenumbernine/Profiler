#pragma once

#include "Profiler/System.h"
#include "Common/Singleton.h"

namespace Profiler {

extern Common::Singleton<System> system;

};

//http://stackoverflow.com/questions/3859944/combining-string-literals-and-integer-constants
#define STRINGIZE_DETAIL_(v)	#v
#define STRINGIZE(v) STRINGIZE_DETAIL_(v)
#define FUNCTION_STRING	STRINGIZE(__func__)	//not working ... either in macro or inline
#define LINE_STRING	STRINGIZE(__LINE__)
#define PROFILE_NAME __FILE__ "(" LINE_STRING ")" //FUNCTION_STRING //function not expanding 

//these are to be used externally:

//place this at the start of any block you want timed:
#define PROFILE()	::Profiler::Block profiler##__LINE__(PROFILE_NAME);

//place this at the beginning of your program update loop
#define PROFILE_BEGIN_FRAME()	::Profiler::system->beginFrame();

//place this at the end of your program update loop
#define PROFILE_END_FRAME()		::Profiler::system->endFrame();

