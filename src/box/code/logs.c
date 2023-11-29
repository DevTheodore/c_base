#include "../headers/files/logs.h"
#include "../headers/files/set_parameters.h"
#include "../headers/libs.h"
#include "../headers/files/lang.h"

bool log_open = false;

bool initLog(void){
    
    return true;
}
bool openLog(void){
    return true;
}
bool closeLog(void){
    if (log_open){
        //Fermer log

    }
    return true;
}
void LOG(int msg, int TYPE, char *param[], int paramc){
    char* tmsg = getMsg(msg);
    int s = strlen(tmsg);
    for (int i=0; i<paramc; i++){
        s+=strlen(param[i]);
    }
    
    char* ll = malloc(s);

    int pn = 0;
    if (TYPE > WARNING || (getConfig().show_info && TYPE == INFO) || (getConfig().show_warn && TYPE == WARNING)){
        bool adds = false;
        int sc = 0;
        for (int i = 0; i<strlen(tmsg); i++){
            
            if (tmsg[i] == '\\' && (!adds)){
                adds = true;
            } else if (tmsg[i] == '\\'){
                adds=false;
                ll[sc] = '\\';
                sc++;
            } else if (tmsg[i] == '@' && (!adds) && pn<paramc) {
                
                for (int y = 0; y<strlen(param[pn]); y++){
                    ll[sc+y] = param[pn][y];
                }
                sc+=strlen(param[pn]);
                pn++;
            } else if (tmsg[i] == '@') {
                adds=false;
                ll[sc] = '@';
                sc++;
            } else {
                
                ll[sc] = tmsg[i];
                sc++;
                
            }
        }
        if (TYPE == CRASH){
            printf("\033[31m\033[1m%s : %s\033[0m\n", getMsg(13), ll);
        } else if (TYPE == ERROR)
        {
             printf("\033[31m\033[1m%s\033[0m\033[1m : %s\033[0m\n", getMsg(12), ll);
        } else if (TYPE == WARNING)
        {
            printf("\033[1m%s : %s\033[0m\n", getMsg(11), ll);
        } else if (TYPE == INFO || TYPE == OINFO)
        {
            printf("%s\n", ll);
        }
        
    }
}