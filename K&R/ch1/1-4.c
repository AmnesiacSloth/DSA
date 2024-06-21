#include <stdio.h>

int main() {
    /* Print celsius -> farenheit conversion 0-300F */
    float celsius, farenheit;
    float lowBound, upBound, step;

    lowBound = 0; // low limit of temp scale
    upBound = 300; // upper limit
    step = 10; // step size

    celsius = lowBound;
    printf("Celsius -> Farenheit\n");
    while (celsius <= upBound) {
        farenheit = ((9.0 * celsius)/(5.0)) + 32;
        printf("%6.1f %3.0f\n", celsius, farenheit);
        celsius = celsius+step;
    }
}