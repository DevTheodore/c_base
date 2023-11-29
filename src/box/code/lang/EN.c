static char** EN;
char** getEN(void) {
    return EN;
}
void initEn(void) {
    EN = malloc(8192);
    EN[0] = "English";
    EN[1] = "Language loaded";
    EN[2] = "Command line parameters: ";
    EN[3] = "Argument @ not recognized,\nType @ @help, to display help.";
    EN[4] = "Parameters: \n Show help: @\n  Selected language: @\n  Show Information: @\n Show advertisement: @\n    Consider advertisements as errors: @\n  Save logs: @\n  Show information in logs: @\n   Log file:   @\n    Folder to store language files:   @\n",
    EN[5] = "Yes";
    EN[6] = "No";
    EN[7] = "Unable to open language file (Path: @).";
    EN[8] = "Language not loaded, English selected.";
    EN[9] = "Rewriting";
    EN[10] = "Information";
    EN[11] = "Advertisement";
    EN[12] = "Error";
    EN[13] = "Crash";
    EN[14] = "Startup";
    EN[15] = "Unable to open log file (Path: @).";
    EN[16] = "Normal shutdown";
    EN[17] = "Emergency shutdown";
    EN[18] = "Invalid language parameter";
    EN[19] = "Invalid language folder path parameter";
    EN[20] = "Invalid log file path parameter";
    EN[21] = "Anomalies have been detected, do you want to continue?";
    EN[22] = "Some parameters are invalid, do you want to rectify them?";
    EN[23] = "Log file location: ";
    EN[24] = "Languages folder location: ";
    EN[25] = "Language name (example: French / fr / FR): ";
    EN[26] = "Unable to write to log file.";
    EN[27] = "Switching to logless mode";
    EN[28] = "Message (@) not found";
}