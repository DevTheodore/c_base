#include "../headers/general.h"

int get_k_rec_p_sum(int numc, int numv[]){
    int s=0;
    int min = 0;
    int max = 1000;
    int inter = 2;
    int puissance = 3;
    if (numc>0){
        min = numv[0];
        if (numc>1)
        {
            max = numv[1];
            if (numc>2)
            {
                puissance = numv[2];
                if (numc>3)
                {
                    puissance = numv[3];
                }
            }
        }
    } else {
        printf("To less parameters.\n");
        return 1;
    }

    int i;
    for (i = min; i <= max; i+=inter){
        for (int y = min; y <= max; y+=inter){
            s+=get_puissance(2, (int[]){i+y, puissance});
        }
    }
    
    return s;
}