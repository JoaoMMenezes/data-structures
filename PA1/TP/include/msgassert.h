#ifndef MSGASSERT_H
#define MSGASSERT_H

#include <iostream>
#include <cstdlib>

#define msgassert(cond, msg) \
    if (!(cond)) { std::cerr << "Erro: " << msg << std::endl; std::exit(1); }

#endif
