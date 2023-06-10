#pragma once
#include <iostream>
#ifdef DEBUG
#define DEBUG_OUTPUT(x) std::cout << "Debug output: " << x << std::endl;
#else
#define DEBUG_OUTPUT(x)
#endif // DEBUG
