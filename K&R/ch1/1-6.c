#include <stdio.h>

/* copy input to output, version 2 */

int main () {
    int c; 

    printf("Please enter a char: ");
    c = getchar() != EOF;

    printf("You entered: %i\n", c);
    
    return 0;
}

