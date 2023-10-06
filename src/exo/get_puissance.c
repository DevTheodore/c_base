#include "../headers/general.h"

int get_puissance(int numc, int numv[]){
    if (numc > 1){
        int ret = 1;
        for (int i = 0; i < numv[1]; i++)
        {
            ret *= numv[0];
        }
        return ret;
    }
    else {
        printf("To less parameters.\n");
        return 1;
    }
}