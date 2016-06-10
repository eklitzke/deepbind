#include <dlfcn.h>
#include <malloc.h>

#include <iostream>

extern "C" {
// make the libc mallinfo be visible
extern typeof(mallinfo) __libc_mallinfo;
}

void ShowMallinfo() {
  struct mallinfo info = __libc_mallinfo();
  std::cout << "__libc_mallinfo: heap = " << info.hblks
            << ", blocks = " << info.uordblks << "\n";
}

int main(int argc, char **argv) {
  std::cout << "program start\n";
  ShowMallinfo();
  std::cout << "allocating 100 bytes\n";
  malloc(100);
  ShowMallinfo();
  std::cout << "loading shared.so\n";
  void *handle = dlopen("./shared.so", RTLD_NOW);
  std::cout << "shared.so handle = " << handle << "\n";
  ShowMallinfo();
  std::cout << "allocating 100 bytes\n";
  malloc(100);
  ShowMallinfo();
  return 0;
}
