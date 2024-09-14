#include <stdio.h>

int main(void) {
  // typedef is kinda of an alias for another type

  typedef int antelope; // antelope is an alias for int
  antelope n = 10;      // this is the same as int n = 10

  typedef int antelope, bagel, mushroom;  // These are all "int"
  bagel n2 = 31;
  printf("%d\n", n2);

  // typedef and structs. 

  struct animal {
    char *name;
    int speed;
    int leg_count;
  };

  //  original name      new name
  //            |         |
  //            v         v
  //      |-----------| |----|
  typedef struct animal animal; // Sometimes a struct will be typedef’d to a new name so you don’t have to type the word struct over and over.
  struct animal y;  // This works
  animal z;         // This also works because "animal" is an alias
  
  // There's a shorther way to do that:
  //  original name
  //            |
  //            v
  //      |-----------|
  typedef struct animal {
    char *name;
    int leg_count, speed;
  } animal;                         // <-- new name

  struct animal k;  // This works
  animal l;         // This also works because "animal" is an alias

  // There's an even shorter way using anonymous structs:
  //  Anonymous struct! It has no name!
  //         |
  //         v
  //      |----|
  typedef struct {
    char *name;
    int leg_count, speed;
  } animal;                         // <-- new name

  struct animal n;  // ERROR: this no longer works--no such struct!
  animal m;         // This works because "animal" is an alias
  return 0;
}