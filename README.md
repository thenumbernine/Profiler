### C++ profiling code

[![Donate via Stripe](https://img.shields.io/badge/Donate-Stripe-green.svg)](https://buy.stripe.com/00gbJZ0OdcNs9zi288)<br>

## usage:

just put `PROFILE()` at the beginning of whatever code you want to profile
optionally `PROFILE_BEGIN_FRAME()` and `PROFILE_END_FRAME()` around your execution loop

upon exit produces a call stack of functions with the following information:
- how much time, including child calls, it contributed to each frame's execution
- how much time, excluding child calls, it contributed to each frame's execution
- what order it was in performance based on the exclusive time calculations
- who called who

it currently depends on headers found in the Common project
