#ifndef __P_INCLUDE__
#define __P_INCLUDE__ 
#include "../libs.h"
#include "../syntax.h"
typedef struct config {
    bool help;
    char lang[2];
    bool show_info;
    bool show_warn;
    bool warn_are_err;
    bool save_log;
    bool save_info_in_log;
    char* log_file;
    char* lang_dir;
} config;

static config CONFIG_VAR = {
    .help = false,
    .lang = "FR",
    .show_info = false,
    .show_warn = true,
    .warn_are_err = false,
    .save_log = false,
    .save_info_in_log = true,
    .log_file = "myprog.log",
    .lang_dir = "./lang"
};

config getConfig(void);

void setInfoOn(void);

void setLogPath(char* path);

void setLangDir(char* path);

void setLang(char c1, char c2);

bool isAArg(char* arg);

bool isArg(char* arg_name, char* arg);

bool getValue(int* i, int argc, char *argv[]);

bool setConfig(int argc, char *argv[], char* err_output[]);
#endif