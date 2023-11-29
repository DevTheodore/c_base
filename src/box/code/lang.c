#include "../headers/files/lang.h"
#include "../headers/files/logs.h"
#include "../headers/libs.h"
#include "../headers/syntax.h"
#include "../headers/files/set_parameters.h"
#include "lang/FR.c"
#include "lang/EN.c"

char* getMsg(int msg) {
    return getMSGDB()[msg];
}

char** getSetMSGDB(bool set, char** v) {
    static char** MSG_DB = 0;
    if (set){
        return (MSG_DB = v);
    }
    return MSG_DB;
}
char** getMSGDB(void) {
    return getSetMSGDB(false, NULL);
}
void setMSGDB(char** v) {
    getSetMSGDB(true, v);
}

char* boolToText(bool b){
    if (b) {
        return getMsg(5);
    } else {
        return getMsg(6);
    }
}
int YNmemStock(void) {
    if (strlen(boolToText(true)) > strlen(boolToText(false))){return strlen(boolToText(true));} else {return strlen(boolToText(false));}
}

bool initLang(void){
    char lang[2];
    initEn();
    lang[0] = getConfig().lang[0];
    lang[1] = getConfig().lang[1];
    char** tgde = getEN();
    setMSGDB(tgde);
    if (lang[0]=='F' && lang[1] == 'R'){
        initFr();
        setMSGDB(getFR());

    } else if (lang[0]=='E' && lang[1] == 'N'){
        char* f_lang_name = malloc(sizeof(char)*(strlen(getConfig().lang_dir)+8));
        strcpy(f_lang_name,getConfig().lang_dir);
        #ifdef WIN32
         strcat(f_lang_name,"\\");
        #else
         strcat(f_lang_name,"/");
        #endif
        strcat(f_lang_name,lang);
        strcat(f_lang_name,".lang");
        FILE *fptr = fopen(f_lang_name,"r"); 
        if (fptr == NULL){
            LOG(7,ERROR,&(f_lang_name),1);
            return false;
        } 
        char** MSG_DB_A = malloc(4096);
        int c = 0;
        bool k=true;
        int ll = 0;
        int ss = 4096;
        while (k)
        {
            int s = 4096;
            char* l = malloc(s);
            bool adds = false;
            int i = 0;
            c = fgetc(fptr);
            while ((c != '\n' || adds) && k)
            {
                if (adds && (c != '\n' || c != '\\')){
                    
                    l[i]=c;
                    adds = false;
                    i++;
                } else if (c == '\\'){
                    adds = true;
                } else {
                    
                    l[i]=c;
                    adds = false;
                    i++;
                }
                if (i == s-2){
                    s+=4096;
                    char* lo;
                    if ((lo = realloc(l, s)) == NULL) {
                        lo = malloc(s);
                        for (int y = 0; y<s-4096; y++){
                            lo[y]=l[y];
                        }
                    }
                    l = lo;
                }
                c = fgetc(fptr);
                k = (c != EOF);
            }
            
            if (ll == ss-2){
                ss+=4096;
                char** MSG_DB_AA;
                if ((MSG_DB_AA = realloc(MSG_DB_A, ss)) == NULL) {
                    MSG_DB_AA = malloc(ss);
                    for (int y = 0; y<ss-4096; y++){
                        MSG_DB_AA[y]=MSG_DB_A[y];
                    }
                }
                MSG_DB_A = MSG_DB_AA;
            }
            char* lf = malloc(strlen(l));
            strcpy(lf,l);
            free(l);
            MSG_DB_A[ll] = lf;
            ll++;     
        }
        setMSGDB(MSG_DB_A);
    } else {
        printf("errr\n");
    }
    return true;
}
