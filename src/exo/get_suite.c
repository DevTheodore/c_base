#include "../headers/general.h"

int get_suite(int numc, int numv[]){
    if (numc > 2){
        int u = numv[0];
        int added = 1515;
        if (numc>3){
            added = numv[3];
        }
        for (int i = 0; i < numv[2]; i++)
        {
            u = u*numv[1] + added;
        }
        return u;
    }
    else {
        printf("To less parameters.\n");
        return 1;
    }
}