#include "../headers/general.h"

int r_p(int x, int n){
    if (n == 1) {return x;}
    else if (n%2 == 0) {
        return r_p(x*x, (int)n/(int)2);
    } else {
        return x*r_p(x*x, (int)(n-1)/(int)2);
    }
}
int get_puissance(int numc, int numv[]){
    if (numc > 1){
        return r_p(numv[0],numv[1]);
    }
    else {
        printf("To less parameters.\n");
        return 1;
    }
}