#include <stdio.h>
#include <string.h>

  int my_strlen(char* s) {
    char* p = s;
    while (*p != '\0') {
      p++;
    }
    return p - s;
  }

int main(void) {
  int a[5] = {11, 22, 33, 44, 55};
  int* ptr = &a[0];
  printf("First element: %d\n", *ptr); // 11
  printf("Second element: %d\n", *(ptr + 1)); // 22
  // C knows the type of the value the ptr points to, so it knows how many bytes to jump when you add to the address
  // For example, if the address of the element 11 is 100, when you add + 1, it jumps to the address 104, where the next element is located, and so on

  int* ptr2 = a; // This is the same as &a[0]

  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    printf("%d\n", *(ptr2 + i));
  }

  // Changing pointers
  int arr[6] = {1, 2, 3, 4, 5, 99};
  int* ptr3 = &arr[0];
  while (*ptr3 != 99) {
    printf("%d\n", *ptr3);
    ptr3++;               // We increment the pointer itself
  }

  // Subtracting pointers 
  char* str = "Hello, World!";
  printf("The length of %s is %d\n", str, my_strlen(str)); // You can only use pointer substraction between two pointers that point to the same array
  
  
  // Void pointers
  char s[] = "Goats!";
  char t[100];

  memcpy(t, s, 7);  // Copy 7 bytes--including the NUL terminator!
  printf("%s\n", t);  // "Goats!"

  int a2[] = {11, 22, 33};
  int b2[3];

  memcpy(b2, a2, 3 * sizeof(int));  // Copy 3 ints of data
  printf("%d\n", b2[1]);  // 22

  return 0;
}