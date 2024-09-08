#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main(void)
{
  // Data types
  int some_int = 26;
  float some_float = 3.14;
  char *some_string = "Hello, World!";
  printf("%s The integer is %d and the float is %f\n", some_string, some_int, some_float);

  int truthy_int = 1; // Non zero values are evaluated as true and can be used as booleans
  if (truthy_int)
  {
    printf("The expression evaluated to true!\n");
  }

  int falsy_int = 0;
  if (!falsy_int)
  {
    printf("I am false!\n");
  }

  bool a_bool = true;
  if (a_bool)
  {
    printf("This is true, too!\n");
  }

  int input_number;
  printf("Enter a whole number\n");
  scanf("%d", &input_number);
  printf("%d is %s\n", input_number, input_number % 2 == 0 ? "even" : "odd"); // Ternary operator evaluates to a bool

  /*
  With pre-increment and pre-decrement, the value of the variable is incremented or decremented before the expression is evaluated.
  Then the expression is evaluated with the new value.

  With post-increment and post-decrement, the value of the expression is first computed with the value as-is,
  and then the value is incremented or decremented after the value of the expression has been determined.
  */

  some_int = 10;
  int some_other_int = 5 + some_int++;          // Compute 5 + some_int, _then_ increment some_int
  printf("%d, %d\n", some_int, some_other_int); // Prints 11, 15

  some_int = 10;
  some_other_int = 5 + ++some_int;
  printf("%d, %d\n", some_int, some_other_int); // Prints 11, 16

  // The sizeof operator
  printf("The size of a float is %zu on my system\n", sizeof some_float);
  printf("The size of an int is %zu on my system\n", sizeof some_int);
  printf("The size of a char is always %zu on all systems\n", sizeof(char));

  int random_number;
  do {
    random_number = rand() % 100;
    printf("Random number: %d\n", random_number);
  } while (random_number != 45);

  // Switch statement

  int i = 2;
  switch (i) {
    case 0:
    printf("The number is zero\n");
    break;
    case 1:
    printf("The number is one\n");
    break;
    case 2:
    printf("The number is two\n");
    break;
    default:
    printf("I don't know that number\n");
    break;
  }
  

  return 0;
}