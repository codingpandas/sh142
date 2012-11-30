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

//For Output or >
/*    FILE *read_pipe;
    char *dest;
    long bytes_read;
    const char *cmd;
    cmd = command.c_str();
    dest = args[2];

    if (args[1] == ">"){
    	read_pipe = popen(cmd, "r");
    	bytes_read = getdelim (dest, 1000, '\0', read_pipe);
	}
}*/

//For File to File Output (Copying)
void fileOutput(string command, char **args){

    if(string(args[1]).compare(">") == 0){
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

    if(string(args[1]).compare(">") == 0 && string(args[3]).compare("app") == 0){
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

    if(string(args[1]).compare("<") == 0){
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
