PROFILER_PATH:=$(dir $(lastword $(MAKEFILE_LIST)))

INCLUDE+=$(PROFILER_PATH)include
LIBPATHS+=$(PROFILER_PATH)dist/$(PLATFORM)/$(BUILD)
LIBS+=Profiler

