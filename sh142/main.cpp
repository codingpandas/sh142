//
//  main.cpp
//  sh142
//
//  Created by Alben Cheung on 11/24/12.
//  Copyright (c) 2012 Alben Cheung. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <algorithm>
#include <sys/types.h>
#include <vector>
#include <regex.h>
#include "builtin.h"
#include "parser.h"
#include "hwutil.h"
#include "io.h"
#define BUFFER_SIZE 1<<16
#define ARR_SIZE 1<<16
using namespace std;

//Global Variables
string cmd;
int process[10];
int numProcess = 0;


//Environmental Variables
string pathVar;
string dataVar;

//Check Saved Environment Variables
int checkenvVar(string command, char ** args){
    string pathCheckUpper("PATH");
    string dataCheckUpper("DATA");
    string pathCheckLower("path");
    string dataCheckLower("data");

    if(pathCheckUpper.compare(command) == 0){
        ifstream sh142 (".sh142");
        bool path = true;
        bool data = false;
        string output;
        if(sh142.is_open()){
            while(!sh142.eof()){
                if(path){
                    getline(sh142,output);
                    pathVar = output;
                    path = false;
                    data = true;
                }
                if(data){
                    getline(sh142,output);
                    dataVar = output;
                    data = false;
                }
                else{
                    break;
                }
            }
        }
        sh142.close();
        cout << pathVar << endl;
    }

    if(dataCheckUpper.compare(command) == 0){
        ifstream sh142 (".sh142");
        bool path = true;
        bool data = false;
        string output;
        if(sh142.is_open()){
            while(!sh142.eof()){
                if(path){
                    getline(sh142,output);
                    pathVar = output;
                    path = false;
                    data = true;
                }
                if(data){
                    getline(sh142,output);
                    dataVar = output;
                    data = false;
                }
                else{
                    break;
                }
            }
        }
        sh142.close();
        cout << dataVar << endl;
    }

    if(pathCheckLower.compare(command) == 0){
        ifstream sh142 (".sh142");
        bool path = true;
        bool data = false;
        string output;
        if(sh142.is_open()){
            while(!sh142.eof()){
                if(path){
                    getline(sh142,output);
                    pathVar = output;
                    path = false;
                    data = true;
                }
                if(data){
                    getline(sh142,output);
                    dataVar = output;
                    data = false;
                }
                else{
                    break;
                }
            }
        }
        sh142.close();
        cout << pathVar << endl;
    }

    if(dataCheckLower.compare(command) == 0){
        ifstream sh142 (".sh142");
        bool path = true;
        bool data = false;
        string output;
        if(sh142.is_open()){
            while(!sh142.eof()){
                if(path){
                    getline(sh142,output);
                    pathVar = output;
                    path = false;
                    data = true;
                }
                if(data){
                    getline(sh142,output);
                    dataVar = output;
                    data = false;
                }
                else{
                    break;
                }
            }
        }
        sh142.close();
        cout << dataVar << endl;
    }

    return 0;
}

//Main Function
int main(){
    // variables for background info
    pid_t shellPgid;
    shellPgid = getpid();
    process[0] = shellPgid;

    //Local Variables
    char buffer[BUFFER_SIZE];
    char *args[ARR_SIZE];
    //int *ret_status;
    size_t nargs;
    pid_t pid;

    //Configuration File Variables
    FILE *sh142;

    //Message of the Day
    motd();

    //Create the .sh142 with defaults, if it doesn't exist
    if(access(".sh142", F_OK) != -1){
        printf("Loading shell configuration file...\n");

        ifstream sh142 (".sh142");
        bool path = true;
        bool data = false;
        string output;
        if(sh142.is_open()){
            while(!sh142.eof()){
                if(path){
                    getline(sh142,output);
                    pathVar = output;
                    path = false;
                    data = true;
                }
                if(data){
                    getline(sh142,output);
                    dataVar = output;
                    data = false;
                }
                else{
                    break;
                }
            }
        }
        sh142.close();

    }else{
        printf("Shell configuration is missing...\n");
        printf("Creating shell configuration with defaults...\n");
        sh142 = fopen(".sh142","w");
        fprintf(sh142, "PATH=/home/usr/myname:/usr/bin\n");
        fprintf(sh142, "DATA=/data/files:/home/usr/myname\n");
        fprintf(sh142, "CPUMAX=99:200\n");
        fprintf(sh142, "MEMMAX=50M:360\n");
        fprintf(sh142, "TIMEMAX=250\n");
        fclose(sh142);
    }

    void loadVariables();

    while(1){
        printf("$sh142 ->");
        fgets(buffer, BUFFER_SIZE, stdin);
        parse_args(buffer, args, ARR_SIZE, &nargs);

        // Checks if function should be run in the background
        background(buffer, args, shellPgid, process, &numProcess);

        //Checks for Built-in Functions
        checkFunctions(buffer, args);

        //Change PATH settings
        checkPATH(buffer, args);

        //Change DATA settings
        checkDATA(buffer, args);

        //Change Utility Settings
        checkUTILITY(buffer, args);

        //Variable Setter
        variableSetter(buffer, args);

        //Variable Unsetter
        variableUnsetter(buffer, args);

        //Check Environment Variables
        checkenvVar(buffer, args);

        //Check File to File Ourput
        fileOutput(buffer, args);

        //Check File to File Input
        fileInput(buffer, args);

        //Exit Status
        checkExitStatus(buffer, args);
    }

    return 0;
}


