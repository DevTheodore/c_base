int *load_int_args(int argc, char *argv[], int *size);
int exec(char name[], int (*function)(int, int *) , int argc, char *argv[]);