#include "../headers/general.h"

int get_index_suite(int numc, int numv[]){
    if (numc > 2){
        int u = numv[0];
        int max = numv[2];
        int k = 0;
        int added = 1515;
        if (numc>3){
            added = numv[3];
        }
        while (u <= max)
        {
            u = u*numv[1] + added;
            k++;
        }
        return k;
    }
    else {
        printf("To less parameters.\n");
        return 1;
    }
    
}