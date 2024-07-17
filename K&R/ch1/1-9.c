#include <stdio.h>

/* Program to copy input to output, replacing multiple blanks with single blanks*/
main () {
    int c;
    int blank = 0;

    while ( (c = getchar()) != 'z') {
        if (c = ' ') {
            blank++;
        }
        // signifies that pattern of blanks ended, reset flag, then put current c;
        else if (blank >= 1) {
            blank = 0;
            putchar(' ');
            putchar(c);
        }
        else {
            putchar(c);
            printf("here");
        }
    }
}