#include <stdio.h>

main () {
 int blank = 0;
 int tab = 0;
 int newl = 0;
 int c;
 while ((c = getchar()) != 'z') {
    if (c == ' ') blank++;
    else if (c == '	') tab++;
    else if (c == '\n') newl++;

 }
 printf("Blanks found: %d \n Tabs found: %d, \n Newlines found: %d \n", blank, tab, newl);
}