#include "../headers/general.h"

int get_moy(int numc, int numv[]){
    int x=0;
    int i;
    for (i = 0; i < numc; i++){
        x+=numv[i];
    }
    float z = ((float) x)/((float) (numc));
    printf("Valeur calculée : %f\n",z);
    return (int)(round(z));
}