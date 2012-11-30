//
//  io.h
//  sh142
//
//  Created by Alben Cheung on 11/24/12.
//  Copyright (c) 2012 Alben Cheung. All rights reserved.
//

#ifndef sh142_io_h
#define sh142_io_h

#include <iostream>
#include <stdio.h>
#include "builtin.h"
using namespace std;


void dump(string command, char **args){

    if(string(args[1]).compare(">") == 0){
        ofstream myfile;
        myfile.open("name_age.dat",ios::app);
        int i = 0;
            while(i < sizeof(args)){
                myfile << args[i];
            }
            myfile << endl;
        myfile.close();
        retStat = 0;
    }
}

//For File to File Output (Copying)
void fileOutput(string command, char **args){

    if(args[1] != NULL && string(args[1]).compare(">") == 0){
        ofstream myfile;
        myfile.open (args[2]);

        ifstream infile;
        infile.open(args[0]);

        string output;
        if(infile.is_open()){
            while(!infile.eof()){
                getline(infile, output);
                myfile << output << endl;
            }
        }
        infile.close();
        myfile.close();
        retStat = 0;
    }

    if(args[1] != NULL && string(args[1]).compare(">") == 0 && string(args[3]).compare("app") == 0){
        ofstream myfile;
        myfile.open (args[2]);

        ifstream infile;
        infile.open(args[0], ios::app);

        string output;
        if(infile.is_open()){
            while(!infile.eof()){
                getline(infile, output);
                myfile << output << endl;
            }
        }
        infile.close();
        myfile.close();
        retStat = 0;
    }
}

//For File to File Input (Inputing)
void fileInput(string command, char **args){

    if(args[1] != NULL && string(args[1]).compare("<") == 0){
        ofstream myfile;
        myfile.open (args[0], ios::app);

        ifstream infile (args[2]);
        string output;
        if(infile.is_open()){
            while(!infile.eof()){
                getline(infile, output);
                myfile << output << endl;
            }
        }
        infile.close();
        myfile.close();
        retStat = 0;
    }

}

// For Input or < (for commands/programs)
void cmdInput(string command, char **args){

}

// For Error Redirection or 2>
void errorRedir(string command, char **args){


}

#endif
