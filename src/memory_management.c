#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
  /*
  All the allocation functions return a pointer to the newly-allocated stretch of memory,
  or NULL if the memory cannot be allocated for some reason.
  */

  // malloc(): accepts a number of bytes to allocate, and returns a void pointer to that block of newly-allocated memory.
  int *p = malloc(sizeof(int)); // We allocate the memory for a single int
  // int *p = malloc(sizeof *p);  // Alternative option: *p is an int, so same as sizeof(int)

  *p = 5;
  printf("%d\n", *p); // 5
  free(p);
  // printf("%d\n", *p); // We already freed p, so this causes undefined behavior. In this case, it printed 0

  // Error handling
  int *x;

  x = malloc(sizeof(int) * 10);

  if (x == NULL) {
    printf("Error allocating 10 ints\n");
    // do something here to handle it
  }

  // Alocating space for an array

  int *p2 = malloc(sizeof(int) * 10); // Allocate space for 10 ints

  for (int i = 0; i < 10; i++)  // Assign them values 0-45:
      p2[i] = i * 5;

  // Print all values 0, 5, 10, 15, ..., 40, 45
  for (int i = 0; i < 10; i++)
      printf("%d\n", p2[i]);

  // Free the space
  free(p2);

  // calloc(), an alternative to malloc()
  
  int *p3 = calloc(10, sizeof(int)); // Allocate space for 10 ints with calloc(), initialized to 0:

  int *q = malloc(10 * sizeof(int)); // Allocate space for 10 ints with malloc(), initialized to 0:
  memset(q, 0, 10 * sizeof(int));   // set to 0
  // The result is the same for both except malloc() doesn’t zero the memory by default.

  // Changing allocated size with realloc()

  // Allocate space for 20 floats
    float *p4 = malloc(sizeof *p4 * 20);  // sizeof *p same as sizeof(float)

    // Assign them fractional values 0.0-1.0:
    for (int i = 0; i < 20; i++)
        p4[i] = i / 20.0;

    // But wait! Let's actually make this an array of 40 elements
    float *new_p = realloc(p4, sizeof *p * 40);

    // Check to see if we successfully reallocated
    if (new_p == NULL) {
        printf("Error reallocing\n");
        return 1;
    }

    // If we did, we can just reassign p
    p4 = new_p;

    // And assign the new elements values in the range 1.0-2.0
    for (int i = 20; i < 40; i++)
        p4[i] = 1.0 + (i - 20) / 20.0;

    // Print all values 0.0-2.0 in the 40 elements:
    for (int i = 0; i < 40; i++)
        printf("%f\n", p4[i]);

    // Free the space
    free(p4);
}