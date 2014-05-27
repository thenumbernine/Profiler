DIST_FILENAME=libProfiler.dylib
DIST_TYPE=dylib

include ../GLApp/Makefile.mk

# I'm still keeping Common include files here.  I should move them ...
CFLAGS_BASE+= -I../GLApp/include
