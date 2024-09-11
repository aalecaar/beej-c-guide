#include <stdio.h>



void times2(int *p, int len) {
    for (int i = 0; i < len; i++) {
      printf("%d \n", p[i] * 2);
    }
  }

void double_array(int *a, int len) {
  for (int i = 0; i < len; i++) {
    a[i] *= 2;
  }
}

void print_2D_array(int a[][3]) // You could also do [2][3]
{
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++)
            printf("%d ", a[row][col]);
        printf("\n");
    }
}


int main(void) {
  float floats_arr[4]; // An array has a fixed sized that needs to be specified beforehand.
  floats_arr[0] = 23.93686;
  floats_arr[1] = 341.834;
  floats_arr[2] = 34.2578;
  floats_arr[3] = 12.267;

  for (int i = 0; i < 4; i++) {
    printf("Index %d: %.2f\n", i, floats_arr[i]);
  }

  // Getting the length of an array
  int ints_arr[12];
  printf("The size of an int type is %zu on my system\n", sizeof(int));
  printf("The size of the ints_arr is %zu, which is 4 * 12\n", sizeof ints_arr);

  /*
  "If it’s an array of chars, then sizeof the array is the number of elements, since sizeof(char) is defined to be 1.
  For anything else, you have to divide by the size of each element.
  But this trick only works in the scope in which the array was defined. 
  If you pass the array to a function, it doesn’t work. Even if you make it “big” in the function signature
  This is because when you “pass” arrays to functions, you’re only passing a pointer to the first element, and that’s what sizeof measures." 
  */
  printf("The length of ints_arr is %lu, which is 48 / 4\n", (sizeof ints_arr) / sizeof(int));
 
  // Another way to see how many bytes there are in an array:
  printf("%zu\n", sizeof(int [34]));

  // int other_arr[3] = {1, 2, 3, 4}; // ERROR: You can't initialize a greater number of elements than initially stated.
  int another_arr[3] = {2}; // But you can have less. In that case, the rest will be set to 0.
  for (int i = 0; i < 3; i++) {
    printf("%d\n", another_arr[i]);
  }

  // The size of the array can be inferred, so you don't need to declare the size in advance:
  int ints[] = {3, 7, 9};
  for (int i = 0; i < 4; i++) {
    printf("%d\n", ints[i]);
  }
  printf("The length of the ints arr is %lu\n", sizeof ints / sizeof(int));

  // Out of bounds indexing causes undefined behavior. In this case, garge will be printed after the third element
  for (int i = 0; i < 10; i++) {
    printf("%d\n", ints[i]); 
  }

  //Multidimensional arrays
  int a_2d_arr[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
  for (int row = 0; row < 2; row++) {
    for (int col = 0; col < 5; col++) {
      printf("(Row :%d, Col: %d) = %d\n", row + 1, col + 1, a_2d_arr[row][col]);
    }
  }
  // You can also initilize explicit indexes:

  int bar[3][3] = {[0][0]=1, [1][1]=1, [2][2]=1};
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      printf("%d ", bar[row][col]);
    }
    printf("\n");
  }

  // Pointers to arrays
  int foo[3] = {45, 34, 93};
  int *p = &foo[0];
  printf("%d\n", *p);

  // There's a shorthand to do the same as above:
  int *arr_ptr = foo; // A pointer to an array is really pointing to the first element of the array.
  printf("First element: %d\n", *arr_ptr);


  // Passing single dimensional arrays to functions:
  times2(p, 3); // Passing as a pointer to the first element is the most common way

  int my_arr[3] = {1, 2, 3};
  double_array(my_arr, 3); // Modifying the array inside a function modifies teh array in the outer scope
  for (int i = 0; i < 3; i++) {
    printf("%d\n", my_arr[i]);
  }

  // Passing multi dimensional arrays to functions:
  int x[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    print_2D_array(x); // In the case of passing multi dimensional arrays to functions, you need to specify the size of every dimension, except for the first one.
  
  return 0;
}