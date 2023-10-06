#include "headers/general.h"

int *load_int_args(int argc, char *argv[], int *numc){
    int s_size = 0;
    if (argc>2){
        s_size = (argc - 2);
    }
    *numc = s_size;
    int* ret = (int*)malloc(sizeof(int)*(s_size+1));

    for (int i = 2; i-2<s_size; i++){
        sscanf(argv[i], "%d", &(ret[i-2])); 
    }
    return ret;
}

int exec(char name[], int (*function)(int, int *) , int argc, char *argv[]){
    //Init
    int numc;
    int *numv = load_int_args(argc, argv, &numc);

    printf("Fonction Choisie : %s\n",name);
    //Exec
    int ret = (*function)(numc, numv);

    //Return
    printf("Valeur retounée : %d\n",ret);

    //Free
    free(numv);
    
    return 0;
}