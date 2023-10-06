#include "../headers/general.h"

int get_rec_sum(int numc, int numv[]){
    int s=0;
    int min = 1;
    int max = 2048;
    int inter = 1;
    if (numc>0){
        min = numv[0];
        if (numc>1)
        {
            max = numv[1];
            if (numc>2)
            {
                inter = numv[2];
            }
            
        }
        
    }

    int i;
    for (i = min; i <= max; i+=inter){
        s+=i;
    }
    
    return s;
}