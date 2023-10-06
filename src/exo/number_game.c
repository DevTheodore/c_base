#include "../headers/general.h"

int number_game(int numc, int numv[]){
    int min = 1;
    int max = 100;
    int r_coups = 10;
    if (numc > 0){
        min = numv[0];
        if (numc > 1){
            max = numv[1];
            if (numc > 2){
                r_coups =  numv[2];
            }
        }
    }
    srandom(time(NULL));
    int r = random()%max + min;
    int t = max+1;
    printf("Trouve le nombre entre %d et %d (en %d essais) : ",min,max,r_coups);
    while (r_coups > 0 && (t != r)){
        scanf("%d", &t);  
        if (t > r){
            printf("Plus petit (encore %d essais) : ",r_coups-1);
        }
        if (t < r){
            printf("Plus grand (encore %d essais) : ",r_coups-1);
        }
        r_coups -= 1;
    }
    if (t == r){
        printf("Gagné!\n");
    } else {
        printf("Perdu c'était %d\n", r);
    }
    return 0;
}
