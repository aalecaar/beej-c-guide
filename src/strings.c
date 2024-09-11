#include <stdio.h>
#include <string.h>

int my_strlen(char *s) {
  int count = 0;
  while (s[count] != '\0') {
    count++;
  }
  return count;
}

int main(void) {
  char *greetings = "Hello, World!"; // A string is a pointer 
  char greetings2[13] = "Hello, World!"; // This is equivalent as above
  char greetings3[] = "Hello, World!"; // Or you just can let the compiler figure the length out
  printf("%s\n", &greetings[0]); // This is the exact same thing we did with arrays: this points to the first element of the string, but you can use that to get back the entire string
  printf("%s\n", greetings2);
  printf("%s\n", &greetings3[0]);
  
  for (int i = 0; i < 13; i++) {
    printf("%c\n", greetings[i]); // You can use the char format specifier to get each character
  }

  // String initialization. When initializing a string, both char *s y char s[] get teh job done, but there's a difference:
  char *foo = "A cute cat"; // This is a string literal. It's immutable, (but you can reassign it, which is not the same as mutating) and the memory management of it is done by the compiler
  foo = "A lovely dog"; // Allowed
  // foo[0] = 'O'; // Not allowed, or allowed but is undefined behaviour that will probably end crasing the program
  printf("%s\n", foo);
  char baz[] = "Another cute cat"; // This is actually not a string literal (though it seems like one). You can mutate this but you cannot reassign it. You have to manage its memory
  // baz = "Oops"; // Reassignment not allowd
  baz[0] = 'I'; // Mutation allowed
  printf("%s\n", baz);
  
  // Getting the length of a string
  printf("The length in bytes of foo is %zu. And that's actually its real length!\n", strlen(foo)); //  A char size is always 1 byte, that way we now the length of a string
  
  // String termination. In C, you know when a string ends when you find a zero-value byte or NUL character
  char *str = "Hi there!"; // C implicitly adds the NUL character \0 for you, so this string is the same as "Hi there!\0"
  int len = my_strlen(str); // This function is basically the same as the one in string.h
  printf("The length of \"Hi there!\" is %d\n", len);
  
  // Copying a string
  char *hello = "Hello, World!";
  char hello_copy[14]; // You need to include all the source string bytes + 1 corresponding to the NUL character
  strcpy(hello_copy, hello); // A mnemonic for this operation is to imagine that you are doing a normal assignment, hello_copy = hello;
  hello_copy[0] = 'J';
  printf("Original: %s\nCopy: %s\n", hello, hello_copy); // The original string is not changed!

return 0;
}