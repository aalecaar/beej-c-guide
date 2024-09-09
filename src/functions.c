#include <stdio.h>

int add_one(int number) {
  return number + 1;
}

int foo(void); // Function prototype declaration. You can't call a function without it being defined first before main. But with a prototype, you can call a function before it's defined (but you HAVE TO define it later after main anyways).

int main(void) {
  int i = 10;
  int j = add_one(i); // Arguments are passed by value. In C, every argument passed to a function is passed by value, without exception.
  printf("j is %d and i is still %d\n", j, i);

  int baz = foo();
  // Function prototypes
  printf("%d\n", baz);

  return 0;
}

 int foo(void) {
  return 345;
}