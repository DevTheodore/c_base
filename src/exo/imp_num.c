#include "../headers/general.h"

int imp_num(int numc, int numv[]){
    printf("int numv[%d] = {", numc);
    for (int i=0; i<numc; i++){
        printf("%d",numv[i]);
        if (i != numc-1){
            printf(", ");
        }
    }
    printf("};\n");
    return 0;
}