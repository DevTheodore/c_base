#include "../headers/general.h"

int get_approx_pi(int numc, int numv[]){
    if (numc > 0){
        double l = ((double)numv[0]/(double)1000000);
        printf("l = %lf\n",l);
        int n = 0;
        int st[] = {(int)(0-1),0};
        double s = 0;
        double var = 3;
        while (var>=l || (0-var)>=l)
        {
            st[1] = n;
            var=((double)get_puissance(2,st))*(((double) 1)/((double) 2*n+1));
            n++;
            s += var;
        }
        s*=4;
        printf("Valeur calculée : %lG (en %d étapes)\n",s,n);
        return s;

    }
    else {
        printf("To less parameters.\n");
        return 1;
    }  
}