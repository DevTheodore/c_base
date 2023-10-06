#include "../headers/general.h"

int get_fibo(int numc, int numv[]){
    int o[] = {0,1};
    int max = 100;
    if (numc>0){
        max = numv[0];
    }
    int x;
    int b = 1;
    for (int n = 1; n <= max; n++)
    {
        x = o[0];
        o[0] = o[1];
        o[1] = x+o[1];
        if (o[1]<0 && b){
            printf("Erreur dépassement de valeur maximal.\n");
            b = 0;
        }
    }
    return o[1];
    
}