#include <math.h>

float CONV_TAXA (float x) {

double TAXA_CONV, TAXA_TEMP;

TAXA_TEMP = x/100;

TAXA_CONV = (pow ((1 + TAXA_TEMP), 1/365) - 1) * 100;

return TAXA_CONV;

}

int main () {

    float taxa;

    scanf ("%f", &taxa);

    printf ("%lf", CONV_TAXA(taxa));

    return 0;
}