//
//  builtin.h
//  sh142
//
//  Created by Alben Cheung on 11/24/12.
//  Copyright (c) 2012 Alben Cheung. All rights reserved.
//

#ifndef sh142_builtin_h
#define sh142_builtin_h
#include <inttypes.h>
#include <iso646.h>
#include <sys/types.h>
#include <cstdlib>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
//#define _POSIX_SOURCE
#include <termios.h>


using namespace std;

//Global Return Status Variables
int exitStatus[10];
int retStat = -10;
int statusIndex = 0;

void motd(){
    printf("\tComputer Engineering @ San Jose State University\n");
    printf("\tCreated by: Alben Cheung, Timothy Quan, Greg Mathews, David Kwong\n");
}

//Load User Defined Variables
void loadVariables(){


}

void returnStatus(){
    if(retStat != -10){
        exitStatus[statusIndex] = retStat;
        retStat = -10;
        statusIndex++;
    }
}

int checkExitStatus(string command, char ** args){
    string checkStat("$?");

    if (command.find(checkStat) == 0) {

        //Last 1st Command
        if(command.compare("$?1") == 0 ){
            int i = statusIndex - 1 ;
            cout << exitStatus[i] << endl;
        }

        //Last 2nd Command
        if(command.compare("$?2") == 0 ){
            int i = statusIndex - 2 ;
            cout << exitStatus[i] << endl;
        }

        //Last 3rd Command
        if(command.compare("$?3") == 0 ){
            int i = statusIndex - 3 ;
            cout << exitStatus[i] << endl;
        }

        //Last 4th Command
        if(command.compare("$?4") == 0 ){
            int i = statusIndex - 4 ;
            cout << exitStatus[i] << endl;
        }

        //Last 5th Command
        if(command.compare("$?5") == 0 ){
            int i = statusIndex - 5 ;
            cout << exitStatus[i] << endl;
        }

        //Last 6th Command
        if(command.compare("$?6") == 0 ){
            int i = statusIndex - 6 ;
            cout << exitStatus[i] << endl;
        }

        //Last 7th Command
        if(command.compare("$?7") == 0 ){
            int i = statusIndex - 7 ;
            cout << exitStatus[i] << endl;
        }

        //Last 8th Command
        if(command.compare("$?8") == 0 ){
            int i = statusIndex - 8 ;
            cout << exitStatus[i] << endl;
        }

        //Last 9th Command
        if(command.compare("$?9") == 0 ){
            int i = statusIndex - 9 ;
            cout << exitStatus[i] << endl;
        }

        //Last 10th Command
        if(command.compare("$?10") == 0 ){
            int i = statusIndex - 10 ;
            cout << exitStatus[i] << endl;
        }

        retStat = 0;
        return 0;
    }else{
        //cout << "Please use a valid format: $?<number>" << endl;
    }

    return 0;
}

int checkFunctions(string command, char ** args){

    //Local Variables
    char cmdStr[500];

    //Predefine commands
    string clearCMD("clear");
    string cdCMD("cd");
    string exitCMD("exit");
    string lsCMD("ls");
    string sshCMD("ssh");
    string scpCMD("scp");
    string screenCMD("screen");
    string rmCMD("rm");

    //List Files in Directory
    if(lsCMD.compare(command) == 0){
        if(args[1] == NULL){
            system("ls");
            retStat = 0;
            returnStatus();
        }
        if(args[1] != NULL){
            strcpy(cmdStr, "ls ");
            strcat(cmdStr, args[1]);
            system(cmdStr);
            retStat = 0;
            returnStatus();
        }
        return 0;
    }

    //Secure Shell Program
    if(sshCMD.compare(command) == 0){
        if (args[1] != NULL) {
            strcpy(cmdStr, "ssh ");
            strcat(cmdStr, args[1]);
            system(cmdStr);
            retStat = 0;
        }
        if(args[1] != NULL && args[2] != NULL && args[3] != NULL){
            strcpy(cmdStr, "ssh ");
            strcat(cmdStr, args[1]);
            strcat(cmdStr, " ");
            strcat(cmdStr, args[2]);
            strcat(cmdStr, " ");
            strcat(cmdStr, args[3]);
            system(cmdStr);
            retStat = 0;
        }
        else{
            system("ssh");
            retStat = 100;
        }
    }

    //Secure Copy Program
    if(scpCMD.compare(command) == 0){
        if (args[1] != NULL && args[2] != NULL) {
            strcpy(cmdStr, "scp ");
            strcat(cmdStr, args[1]);
            strcat(cmdStr, " ");
            strcat(cmdStr, args[2]);
            system(cmdStr);
            retStat = 0;
        }
        if(args[1] != NULL && args[2] != NULL && args[3] != NULL && args[4] != NULL){
            strcpy(cmdStr, "scp ");
            strcat(cmdStr, args[1]);
            strcat(cmdStr, " ");
            strcat(cmdStr, args[2]);
            strcat(cmdStr, " ");
            strcat(cmdStr, args[3]);
            strcat(cmdStr, " ");
            strcat(cmdStr, args[4]);
            system(cmdStr);
            retStat = 0;
        }
        else{
            system("scp");
            retStat = 100;
        }
    }

    //Screen Program
    if(screenCMD.compare(command) == 0){
        system("screen");
        retStat = 0;
        return 0;
    }

    //Clear Screen
    if(clearCMD.compare(command) == 0){
        system("clear");
        retStat = 0;
        return 0;
    }

    //Remove Files
    if(rmCMD.compare(command) == 0){
        if(args[1] == NULL){
            system("rm");
            retStat = 0;
            returnStatus();
        }
        if(args[1] != NULL){
            strcpy(cmdStr, "rm ");
            strcat(cmdStr, args[1]);
            system(cmdStr);
            retStat = 0;
            returnStatus();
        }
        if(args[1] != NULL && args[2] != NULL){
            strcpy(cmdStr, "rm ");
            strcat(cmdStr, args[1]);
            strcat(cmdStr, " ");
            strcat(cmdStr, args[2]);
            cout << cmdStr << endl;
            system(cmdStr);
            retStat = 0;
        }
    }


    //Change Directory
    if(cdCMD.compare(command) == 0){
        if(args[1] == NULL){
            chdir(getenv("HOME"));
            retStat = 0;
            returnStatus();
        }else{
            if(chdir(args[1]) == -1){
                printf(" %s: No such directory\n", args[1]);
                retStat = -1;
                returnStatus();
                return -1;
            }
        }
        return 0;
    }

    //Exit
    if(exitCMD.compare(command) == 0){
        printf("Exiting Shell...\n");
        retStat = 0;
        exit(EXIT_SUCCESS);
    }

    return 0;
}

int checkPATH(string command, char ** args){
    string pathCMD("PATH=");

    if(command.find(pathCMD) == 0){
        printf("ENVIRONMENT PATH VARIABLE CHANGE DETECTED!\n\n");

        ofstream sh142tmp;
        sh142tmp.open(".sh142tmp");
        sh142tmp << command << endl;

        ifstream sh142 (".sh142");
        bool first = true;
        string output;
        if(sh142.is_open()){
            while(!sh142.eof()){
                if(first){
                    getline(sh142,output);
                    first = false;
                }else{
                    getline(sh142,output);
                    sh142tmp << output;
                }
            }
        }
        sh142tmp.close();
        sh142.close();
        remove(".sh142");
        rename(".sh142tmp", ".sh142");
        retStat = 0;
    }
    return 0;
}

int checkDATA(string command, char ** args){
    string pathCMD("DATA=");

    if(command.find(pathCMD) == 0){
        printf("ENVIRONMENT DATA VARIABLE CHANGE DETECTED!\n\n");

        ofstream sh142tmp;
        sh142tmp.open(".sh142tmp");

        ifstream sh142 (".sh142");
        bool first = true;
        bool second = false;
        string output;
        if(sh142.is_open()){
            while(!sh142.eof()){
                if(first){
                    getline(sh142,output);
                    sh142tmp << output << endl;
                    first = false;
                    second = true;
                }
                if (second) {
                    getline(sh142, output);
                    sh142tmp << command << endl;
                    second = false;
                }
                else{
                    getline(sh142,output);
                    sh142tmp << output;
                }
            }
        }
        sh142tmp.close();
        sh142.close();
        remove(".sh142");
        rename(".sh142tmp", ".sh142");
        retStat = 0;

    }
    return 0;
}

int checkUTILITY(string command, char ** args){

    if(command.find("CPUMAX=") == 0){
        printf("CPU UTILITY VARIABLE CHANGE DETECTED!\n\n");

        ofstream sh142tmp;
        sh142tmp.open(".sh142tmp");

        ifstream sh142 (".sh142");
        bool first = true;
        bool second = false;
        bool third = false;
        string output;
        if(sh142.is_open()){
            while(!sh142.eof()){
                if(first){
                    getline(sh142,output);
                    sh142tmp << output << endl;
                    first = false;
                    second = true;
                }
                if (second) {
                    getline(sh142, output);
                    sh142tmp << output << endl;
                    second = false;
                    third = true;
                }
                if (third){
                    getline(sh142, output);
                    sh142tmp << command << endl;
                    third = false;
                }
                else{
                    getline(sh142,output);
                    sh142tmp << output;
                }
            }
        }
        sh142tmp.close();
        sh142.close();
        remove(".sh142");
        rename(".sh142tmp", ".sh142");
        retStat = 0;

    }

    if(command.find("MEMMAX=") == 0){
        printf("MEM UTILITY VARIABLE CHANGE DETECTED!\n\n");

        ofstream sh142tmp;
        sh142tmp.open(".sh142tmp");

        ifstream sh142 (".sh142");
        bool first = true;
        bool second = false;
        bool third = false;
        bool fourth = false;
        string output;
        if(sh142.is_open()){
            while(!sh142.eof()){
                if(first){
                    getline(sh142,output);
                    sh142tmp << output << endl;
                    first = false;
                    second = true;
                }
                if (second) {
                    getline(sh142, output);
                    sh142tmp << output << endl;
                    second = false;
                    third = true;
                }
                if (third){
                    getline(sh142, output);
                    sh142tmp << output << endl;
                    third = false;
                    fourth = true;
                }
                if (fourth){
                    getline(sh142, output);
                    sh142tmp << command << endl;
                    fourth = false;
                }
                else{
                    getline(sh142,output);
                    sh142tmp << output;
                }
            }
        }
        sh142tmp.close();
        sh142.close();
        remove(".sh142");
        rename(".sh142tmp", ".sh142");
        retStat = 0;

    }

    if(command.find("TIMEMAX=") == 0){
        printf("TIME UTILITY VARIABLE CHANGE DETECTED!\n\n");

        ofstream sh142tmp;
        sh142tmp.open(".sh142tmp");

        ifstream sh142 (".sh142");
        bool first = true;
        bool second = false;
        bool third = false;
        bool fourth = false;
        bool fifth = false;
        string output;
        if(sh142.is_open()){
            while(!sh142.eof()){
                if(first){
                    getline(sh142,output);
                    sh142tmp << output << endl;
                    first = false;
                    second = true;
                }
                if (second) {
                    getline(sh142, output);
                    sh142tmp << output << endl;
                    second = false;
                    third = true;
                }
                if (third){
                    getline(sh142, output);
                    sh142tmp << output << endl;
                    third = false;
                    fourth = true;
                }
                if (fourth){
                    getline(sh142, output);
                    sh142tmp << output << endl;
                    fourth = false;
                    fifth = true;
                }
                if (fifth){
                    getline(sh142, output);
                    sh142tmp << command << endl;
                    fifth = false;
                }
                else{
                    getline(sh142,output);
                    sh142tmp << output;
                }
            }
        }
        sh142tmp.close();
        sh142.close();
        remove(".sh142");
        rename(".sh142tmp", ".sh142");
        retStat = 0;

    }


    return 0;
}


int variableSetter(string command, char ** args){
    string varSet("setvar");
    string equalsVar("=");
    size_t found;
    found = command.find(equalsVar);
    if(command.find(varSet) == 0){
        //if(found!=string::npos){
            ofstream sh142;
            sh142.open(".sh142",ios::app);
            cout << args[1];
            sh142 << args[1] << endl;
            sh142.close();
        //}
        retStat = 0;
    }

    return 0;
}

int variableUnsetter(string command, char ** args){
    string varUnset("unsetvar");

    if(command.find(varUnset) == 0){
        ofstream sh142tmp;
        sh142tmp.open(".sh142tmp");

        ifstream sh142 (".sh142");
        string output;
        if(sh142.is_open()){
            while(!sh142.eof()){
                getline(sh142,output);
                if(output == args[1]){

                }
                if(output != args[1]){
                    sh142tmp << output << endl;
                }
            }
        }
        sh142tmp.close();
        sh142.close();
        remove(".sh142");
        rename(".sh142tmp", ".sh142");
        retStat = 0;
    }

    return 0;
}

void background(string command, char ** args, pid_t shellPgid, int *process, int *numProcess){
    int i = 0;
    int ampFlag = 0;
    int status;
    int shellTerminal = STDIN_FILENO;
    int shellIsInteractive = isatty(shellTerminal);
    char *tmp;
    intmax_t xmax;

    if(command.compare("lsproc") == 0){
        int i = 0;
        cout << "Processes: \n";
        while(i <= *numProcess){
            cout << process[i] << "\n";
            i++;
        }
    }
    //Check current Process ID
    if(command.compare("curp") == 0){
        cout << getpid() << "\n";
        retStat = 0;
    }

    // Switch Processes
    if(command.compare("switch") == 0){
        pid_t newForeground, newBackground;
        newBackground = getpid();
        cout << "new background process: " << newBackground;
        if(args[1] != NULL){
            newForeground = (pid_t)strtoimax(args[1], &tmp, 10);

            tcsetpgrp(STDIN_FILENO, newForeground);

            if (kill(newForeground, SIGCONT) < 0)
                perror("kill (SIGCONT)");

            waitpid(newForeground, &status, 0);


            if (kill(newBackground, SIGCONT) < 0) {
              perror("kill (SIGCONT)");
            }
            tcsetpgrp (STDIN_FILENO, shellPgid);
            retStat = 0;
        }
    }
    // Create background Process
    if (args[1] != NULL && string(args[1]).compare("&") == 0 ){
        int pid = fork();
        ampFlag = 1;
          switch (pid) {
            case -1:
              perror("sh142");
              exit(EXIT_FAILURE);
              break;
            case 0: /* for child process */

              setpgid(pid, pid);


              if (kill(getpid(), SIGCONT) < 0) {
                perror("kill (SIGCONT)");
              }
              break;
            default: /* for parent process */
                setpgid(getpid(), getpid());
                cout << "Parent Process ID " << getpid() << "\n";
                cout << "PID of Child: " << pid << "\n";
                cout << *numProcess;
                *numProcess = *numProcess + 1;
                cout << *numProcess;
                process[*numProcess] = pid;
                struct termios shell_tmodes;
                tcsetpgrp(STDIN_FILENO, getpid());

                if (kill(getpid(), SIGCONT) < 0)
                    perror("kill (SIGCONT)");

                // waitpid(getpid(), &status, 0);
                tcsetpgrp (STDIN_FILENO, shellPgid);
              break;
          }
          retStat = 0;
    }

}

#endif
