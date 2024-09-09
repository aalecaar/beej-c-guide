#include <stdio.h>

int increment(int *p) { // Arguments are always copied, so the original variable is not modified inside the function because we are working on a copy of it. In order to modify it, we pass a pointer to that variable and then dereference it. The pointers is still copie, but it doesn't matter because we have the exact same address as the original pointer variable.
  return *p += 1; 
}

int main(void) {
  int i = 1;
  printf("i is %d\n", i);

  int *ptr_to_i = &i; // This holds the memory address of i 
  printf("The address of i is %p\n", ptr_to_i);

  *ptr_to_i = 300; // Now we dereference the pointer variable in order to modify the variable it points to, namely i
  printf("We dereferenced i to see its current value, which is %d\n", *ptr_to_i);

  printf("After adding 1, i is now %d\n", increment(ptr_to_i));

  int *foo, bar; // In this case, only foo is a pointer, bar isn't.
}
