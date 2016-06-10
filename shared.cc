#include <dlfcn.h>
#include <malloc.h>

#include <iostream>

extern "C" {
// make the libc mallinfo be visible
extern typeof(mallinfo) __libc_mallinfo;
extern typeof(mallinfo) tc_mallinfo;
}

__attribute__((constructor)) void initshared() {
  std::cout << "loading libtcmalloc.so\n";
  void *handle = dlopen("libtcmalloc.so", RTLD_NOW | RTLD_DEEPBIND);
  std::cout << "tcmalloc.so handle = " << handle << "\n";
  std::cout << "allocating 100 bytes in shared.cc\n";
}
