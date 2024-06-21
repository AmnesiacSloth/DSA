#include <stdio.h>

int main() {
    /* Print farenheit -> celsius conversion 0-300F */
    float celsius, farenheit;
    int lowBound, upBound, step;

    lowBound = 0; // low limit of temp scale
    upBound = 300; // upper limit
    step = 20; // step size

    farenheit = lowBound;
    printf("Farenheit -> celsius\n");
    while (farenheit <= upBound) {
        celsius = (5.0)/(9.0) * (farenheit-32.0);
        printf("%3.0f %6.1f\n", farenheit, celsius);
        farenheit = farenheit+step;
    }
}