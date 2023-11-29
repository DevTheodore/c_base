#include "../headers/general.h"
#include "../headers/files/set_parameters.h"
#include "../headers/files/logs.h"
#include "../headers/files/lang.h"


int main(int argc, char *argv[]){
    char* err_output[5];
    for (int i = 0; i < 5; i++){
        err_output[i] = malloc(1);
        err_output[i][0] = 0;
    }
    if (!setConfig(argc, argv, err_output)){
        config c = getConfig();
        initLang();
        if (err_output[4][0] != 0){
            char* params[3];
            params[0] = err_output[4];
            params[1] = argv[0];
            params[2] = PREFIX;
            LOG(3,OINFO,params,3);
            return 0;
        }
        if (err_output[0][0] != 0){
            LOG(18,ERROR,NULL,0);
        }
        if (err_output[1][0] != 0){
            LOG(20,ERROR,NULL,0);
        }
        if (err_output[3][0] != 0){
            LOG(19,ERROR,NULL,0);
        }
        if (c.show_warn){
            LOG(21,WARNING,NULL,0);
            char rep[3];
            if (scanf(" %3c", rep)>0){
                if (rep[0]!='Y' && rep[0]!='y' && rep[0]!='V' && rep[0]!='v' && rep[0]!='O' && rep[0]!='o' && rep[0]!='1'){
                    LOG(17,CRASH,NULL,0);
                    return 0;
                }
                LOG(22,WARNING,NULL,0);
                if (scanf(" %3c", rep)>0){
                    if (rep[0]=='Y' || rep[0]=='y' || rep[0]=='V' || rep[0]=='v' || rep[0]=='O' || rep[0]=='o' || rep[0]=='1'){
                        
                        if (err_output[0][0] != 0){
                            LOG(25,OINFO,NULL,0);
                            char c1 = 0;
                            char c2 = 0;
                            if (scanf(" %c%c", &c1,&c2) == 0) {
                                LOG(28,CRASH,NULL,0);
                                return 0;
                            }
                            if (c1>='a'){
                                c1 -= ('a'-'A'); 
                            }
                            if (c2>='a'){
                                c2 -= ('a'-'A'); 
                            }
                            setLang(c1,c2);
                        }

                        if (err_output[1][0] != 0){
                            LOG(23,OINFO,NULL,0);
                            char* rp = malloc(4096);
                            if (scanf(" %4095s",rp) == 0) {
                                LOG(28,CRASH,NULL,0);
                                return 0;
                            }
                            char* frp = malloc(strlen(rp));
                            strcpy(frp,rp);
                            free(rp);
                            setLogPath(frp);
                        }

                        if (err_output[3][0] != 0){
                            LOG(24,OINFO,NULL,0);
                            char* rp = malloc(4096);
                            if (scanf(" %4095s",rp) == 0) {
                                LOG(28,CRASH,NULL,0);
                                return 0;
                            }
                            char* frp = malloc(strlen(rp));
                            strcpy(frp,rp);
                            free(rp);
                            setLangDir(frp);
                        }
                    }
                } else {
                    LOG(28,CRASH,NULL,0);
                    return 0;
                }
            } else {
                LOG(28,CRASH,NULL,0);
                return 0;
            }
        }
    }
    config c = getConfig();
    initLang();
    char* params[9];
    params[0]=boolToText(c.help);
    params[1]=(getConfig().lang);
    params[2]=boolToText(c.show_info);
    params[3]=boolToText(c.show_warn);
    params[4]=boolToText(c.warn_are_err);
    params[5]=boolToText(c.save_log);
    params[6]=boolToText(c.save_info_in_log);
    params[7]=c.log_file;
    params[8]=c.lang_dir;

    LOG(4,INFO,params,9);

}