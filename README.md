[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=KYWUWS86GSFGL)

### C++ profiling code

## usage:

just put `PROFILE()` at the beginning of whatever code you want to profile
optionally `PROFILE_BEGIN_FRAME()` and `PROFILE_END_FRAME()` around your execution loop

upon exit produces a call stack of functions with the following information:
- how much time, including child calls, it contributed to each frame's execution
- how much time, excluding child calls, it contributed to each frame's execution
- what order it was in performance based on the exclusive time calculations
- who called who

it currently depends on headers found in the Common project
