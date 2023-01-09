#pragma once

#include "Profiler/System.h"
#include "Common/Singleton.h"
#include "Common/Macros.h"	// LINE_STRING

namespace Profiler {

extern Common::Singleton<System> system;

};

#define FUNCTION_STRING	STRINGIZE(__func__)	//not working ... either in macro or inline
#define PROFILE_NAME __FILE__ "(" LINE_STRING ")" //FUNCTION_STRING //function not expanding 

//these are to be used externally:

//place this at the start of any block you want timed:
#define PROFILE()	::Profiler::Block profiler##__LINE__(PROFILE_NAME);

//place this at the beginning of your program update loop
#define PROFILE_BEGIN_FRAME()	::Profiler::system->beginFrame();

//place this at the end of your program update loop
#define PROFILE_END_FRAME()		::Profiler::system->endFrame();
