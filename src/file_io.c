#include <stdio.h>

int main(void) {
  // Reading a file a character at a time
  FILE *fp = fopen("hello.txt", "r"); // Variable to represent an open file
  int c = fgetc(fp);                  // We get a a character from the open file
  printf("%c\n", c);                  // Prints H
  c = fgetc(fp);                      // Each time we call fgetc(), we get the next char
  printf("%c\n", c);                  // Prints e
  fclose(fp);                         // We close the file

  // A better way to do the same as above
  FILE *fp2 = fopen("hello.txt", "r");
  int c2;
  while ((c2 = fgetc(fp2)) != EOF) { // When fgetc() reaches the end of a file, it return EOF
    printf("%c", c2); // Prints Hello, World!
  }
  printf("\n");
  fclose(fp2);


  // Reading a file a line at a time
  FILE *fp3 = fopen("quote.txt", "r");
  char s[1024];
  int line_count = 0;

  while (fgets(s, sizeof s, fp3) != NULL) { // it takes a pointer to a char buffer to hold bytes, a maximum number of bytes to read, and a FILE* to read from. It returns NULL on end-of-file or error.
    printf("%s", s);
  }
  printf("\n");

// Formatted input
  FILE *fp4 = fopen("whales.txt", "r");
  char name[1024];
  float length;
  int mass;

  while (fscanf(fp4, "%s %f %d", name, &length, &mass) != EOF) {
    printf("%s whale, %.1f meters, %d tonnes\n", name, length, mass);
  }

  // Writing text files. In much the same way we can use fgetc(), fgets(), and fscanf() to read text streams, we can use fputc(), fputs(), and fprintf() to write text streams.  
  /* 
  To do so, we have to fopen() the file in write mode by passing "w" as the second argument.
  Opening an existing file in "w" mode will instantly truncate that file to 0 bytes for a full overwrite.
  */
  
  FILE *fp5 = fopen("output.txt", "w"); // stdout is a file, so if we replace fopen("output.txt", "w") with stdout, it will print to the console the things we write to it!
  int x = 55;
  fputc('H', fp5);  // Write this character to output.txt
  fputc('\n', fp5); // Write a new line to output.txt
  fprintf(fp5, "x = %d\n", x); // Write a formatted output to output.txt
  fputs("Hello, World!\n", fp5); // Write an entire line to output.txt
  
  // Now output.txt should look like this:
  // H
  // x = 55
  // Hello, World!

  // Binary I/O 

  /*
  streams of bytes can contain NUL characters,
  and the NUL character is the end-of-string marker in C,
  it’s rare that people use the fprintf()-and-friends functions to operate on binary files.
  Instead the most common functions are fread() and fwrite().
   The functions read and write a specified number of bytes to the stream.
  */

  FILE *fp6 = fopen("output.bin", "wb"); // wb = write binary
  unsigned char bytes[6] = {5, 37, 0, 88, 255, 12};
  // In the call to fwrite, the arguments are:
  //
  // * Pointer to data to write
  // * Size of each "piece" of data
  // * Count of each "piece" of data
  // * FILE*

  fwrite(bytes, sizeof(char), 6, fp6);
  fclose(fp6);

  FILE *fp7;
  unsigned char c3;

  fp = fopen("output.bin", "rb"); // rb for "read binary"!

  while (fread(&c3, sizeof(char), 1, fp7) > 0) {
    printf("%d\n", c3);
  }

  fclose(fp7);

  return 0;
}