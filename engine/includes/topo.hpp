#ifndef TOPO_HPP
#define TOPO_HPP

#include <cstring>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include <stack>
#include <vector>
#include <deque>
#include <functional>

#include "./defined.hpp"
#include "./engine/Environ.hpp"
#include "./utils/utils.hpp"

typedef struct              s_task {
	int                     id;
	std::function<void()>   func;
}                           t_task;

#endif