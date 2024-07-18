#include <stdio.h>

/* Program to count blanks, tabs, and newlines*/

main () {
    int c, blank, tab, nl;
    nl = 0;
    blank = 0;
    tab = 0;
    while ((c = getchar) != EOF) {
        if (c == '  ') ++tab;
        else if (c == ' ') ++blank;
        else if (c == '\n') ++nl;
        else continue;
    }
}