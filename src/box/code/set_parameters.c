#include "../headers/files/set_parameters.h"

config getConfig(void) {
    return CONFIG_VAR;
}

void setInfoOn(void){
    CONFIG_VAR.show_info = true;
}

void setLogPath(char* path){
    CONFIG_VAR.log_file = path;
}
void setLangDir(char* path){
    CONFIG_VAR.lang_dir = path;
}
void setLang(char c1, char c2){
    CONFIG_VAR.lang[0] = c1;
    CONFIG_VAR.lang[1] = c2;
}
bool isAArg(char* arg)
{
    return strncmp(PREFIX, arg, strlen(PREFIX)) == 0;
}

bool isArg(char* arg_name, char* arg)
{
    char* f_arg_name = malloc(sizeof(char)*(strlen(arg_name)+strlen(PREFIX)));
    strcpy(f_arg_name, PREFIX);
    strcat(f_arg_name,arg_name);
    bool ret = (strcmp(arg, f_arg_name) == 0);
    free(f_arg_name);
    return ret;
}

bool getValue(int* i, int argc, char *argv[])
{
    bool ret = true;
    if (*i+1<argc  && !isAArg(argv[*i+1])){
        char l = argv[*i+1][0];
        if (l=='N' || l=='n' || l=='F' || l=='f' || l=='0'){
            ret = false;
        } else if (l=='Y' || l=='y' || l=='V' || l=='v' || l=='O' || l=='o' || l=='1')
        {
            (*i)++;
        }
    }
    return ret;
}

bool setConfig(int argc, char *argv[], char* err_output[]) {
    int t = 0;
    for (int i = 0; i<argc; i++){
        t+=strlen(argv[i])+2;
    }
    char* l = malloc(t);
    strcpy(l, "");
    bool ret = true;
    int i = 1;
    while (i < argc)
    {
        if (isArg("help",argv[i]) || isArg("?",argv[i])){ //Help
            CONFIG_VAR.help = true;
        } else if (isArg("show-info",argv[i]) || isArg("?",argv[i])){ //Show info
            CONFIG_VAR.show_info = getValue(&i,argc,argv);
        } else if (isArg("show-warn",argv[i]) || isArg("?",argv[i])){ //Show Warning
            CONFIG_VAR.show_warn = getValue(&i,argc,argv);
        } else if (isArg("warn-are-error",argv[i]) || isArg("?",argv[i])){ //Warning are error
            CONFIG_VAR.warn_are_err = getValue(&i,argc,argv);
        } else if (isArg("save-info-in-log",argv[i]) || isArg("?",argv[i])){ //Save info in log
            CONFIG_VAR.save_info_in_log = getValue(&i,argc,argv);
        } else if (isArg("log",argv[i])){
            CONFIG_VAR.save_log = true;
            if (i+1<argc && !isAArg(argv[i+1])){
                CONFIG_VAR.log_file = argv[i+1];
            } else {
                CONFIG_VAR.save_log = false;
                err_output[1][0] = 1;
                ret = false;
            }
        } else if (isArg("lang-dir",argv[i])){
            if (i+1<argc && !isAArg(argv[i+1])){
                CONFIG_VAR.lang_dir = argv[i+1];
                if (
                    #ifdef WIN32
                     CONFIG_VAR.lang_dir[strlen(CONFIG_VAR.lang_dir) - 1] == '\\'
                    #else
                     CONFIG_VAR.lang_dir[strlen(CONFIG_VAR.lang_dir) - 1] == '/'
                    #endif
                ){
                    CONFIG_VAR.lang_dir[strlen(CONFIG_VAR.lang_dir) - 1] = '\0';
                }
            } else {
                err_output[3][0] = 1;
                ret = false;
            }
        } else if (isArg("lang",argv[i])) { //Set language
            if (i+1<argc && strlen(argv[i+1])>1 && !isAArg(argv[i+1])){
                CONFIG_VAR.lang[0] = argv[i+1][0];
                CONFIG_VAR.lang[1] = argv[i+1][1];
                if (CONFIG_VAR.lang[0]>='a'){
                    CONFIG_VAR.lang[0] -= ('a'-'A'); 
                }
                if (CONFIG_VAR.lang[1]>='a'){
                    CONFIG_VAR.lang[1] -= ('a'-'A'); 
                }
                i++;
            } else {
                err_output[0][0] = 1;
                ret = false;
            }
        } else {
            if (err_output[4][0] != '\0'){
                strcat(err_output[4],", ");
            }
            strcat(err_output[4],argv[i]);
            ret = false;
        }

        i++;
    }
    return ret;
}
