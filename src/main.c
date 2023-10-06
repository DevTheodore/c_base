#include "headers/general.h"

int main(int argc, char *argv[]){
    
    if (argc < 2){
        printf("No parameters or invalide parameters!\n");
        return 1;
    }
    char *invoke_name = argv[1];
    int (*function)(int, int*);
    if (strcmp(invoke_name, "max") == 0){
        function = &get_max;
    } else if (strcmp(invoke_name, "moy") == 0){
        function = &get_moy;
    } else if (strcmp(invoke_name, "rec_sum") == 0){
        function = &get_rec_sum;
    } else if (strcmp(invoke_name, "fibo") == 0){
        function = &get_fibo;
    } else if (strcmp(invoke_name, "number_game") == 0){
        function = &number_game;
    } else if (strcmp(invoke_name, "puissance") == 0){
        function = &get_puissance;
    } else if (strcmp(invoke_name, "suite") == 0){
        function = &get_suite;
    } else if (strcmp(invoke_name, "approx_pi") == 0){
        function = &get_approx_pi;
    } else if (strcmp(invoke_name, "index_suite") == 0){
        function = &get_index_suite;
    } else if (strcmp(invoke_name, "k_rec_p_sum") == 0){
        function = &get_k_rec_p_sum;
    } else if (strcmp(invoke_name, "get_rec_p_sum") == 0){
        function = &get_rec_p_sum;
    } else{
        printf("Invalide name (%s)\n", invoke_name);
        return 1;
    }
    return exec(invoke_name, function, argc, argv);
}