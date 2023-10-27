#include "../headers/general.h"

int print_car(int numc, int numv[]){
    if (numc<2){
        return 0;
    }
    if (numv[0])
    {
        for (int i = 0; i < numv[1]; i++){
            for (int y = 0; y < numv[1]; y++){
                printf(" *");
            }
            printf("\n");
        }
    } else {
        for (int i = 0; i < numv[1]; i++){
            for (int y = 0; y < i+1; y++){
                printf(" *");
            }
            printf("\n");
        }
    }
    return 0;
}