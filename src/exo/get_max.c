#include "../headers/general.h"

int get_max(int numc, int numv[]){
    if (numc > 0){
        int max = numv[0];
        for (int i = 1; i < numc; i++)
        {
            if (numv[i]>max){
                max = numv[i];
            }
        }
        return max;
    } else {
        printf("Error no number in input\n");
        return 0;
    }
}