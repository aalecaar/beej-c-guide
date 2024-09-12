#include <stdio.h>

struct car {
  char *name;
  float price;
  int speed; 
};

void set_price(struct car *car, float new_price) {
  // car.price = new_price // You can't do this! You can't use dot notation with a pointer
  // (*car).price = new_price; // You have to dereference the pointer first in order to get the struct it points to
  car->price = new_price; // But there's this syntactic sugat that is most commonly used: the arrow operator
  // If you have a struct, use dot notation; if you have a pointer to a struct, use the arrow operator to access its fields
}

int main(void) {
  // A struct is a user-defined type. It only has properties, not methods.
  struct car honda = { "Civic", 15999.00, 140}; // The fields of a struct need to be initialized in the order the where defined in the struct body. If a field is omitted, it is given a zero-value
  struct car mazda = {
    .speed = 190,
    .name = "CX3",
    .price = 25999.00
    }; // By initializing the struct this way, you can initilize every argument in any order. It's safer.

  printf("The %s costs $%.2f and has a max speed of %d kms per hour\n", honda.name, honda.price, honda.speed);
  printf("The %s costs $%.2f and has a max speed of %d kms per hour\n", mazda.name, mazda.price, mazda.speed);
  set_price(&mazda, 17999.00);
  printf("The price of the mazda was set to a new price of $%.2f\n", mazda.price);
  return 0;
}