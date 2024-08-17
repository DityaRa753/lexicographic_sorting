#include <stdio.h>
#include "dll.hpp"
#include "dynarr.hpp"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
  if(argc < 2) {
    printf("Please, pass the input file name argument\n");
    return 1;
  }
  if(0 == strcmp(argv[1], "-h") || 0 == strcmp(argv[1], "--help")) {
    printf("An example of using lexicographic sorting of the input"
        "file using the bubble method.\nPass the input"
        "file name argument.\n");
    return 0;
  }
  DLL dlist;
  FILE *file = fopen(argv[1], "r");
  if(!file) {
    perror(argv[1]);
    return 2;
  }
  int ch;
  DynArr dy;
  while((ch = fgetc(file)) != EOF) {
    if(ch == ' ' || ch == '\n') {
      dlist.PushBack(dy.Access());
      dy.Clean();
      continue; // skip space char
    }
    dy.Push(ch);
  }
  dlist.PushBack(dy.Access());
  dlist.RemoveLast();
 	dlist.SortLexicographic();
  dlist.PrintLIFO();
	
	fclose(file);
  return 0;
}
