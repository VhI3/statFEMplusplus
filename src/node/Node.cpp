#include "Node.h"
#include "Node.hpp"

#ifdef _MSC_VER // This block will be used if MSVC is the compiler
template class Node<double>;
#elif defined(__GNUC__) || defined(__clang__) // This block will be used if GCC or Clang is the compiler
template class __attribute__((visibility("default"))) Node<double>;
#else
#error "Unsupported compiler"
#endif
