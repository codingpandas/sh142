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
using namespace std;

//For Output or >
void output(string command, char **args){
    FILE *read_pipe;
    char *dest;
    long bytes_read;
    const char *cmd;
    cmd = command.c_str();
    dest = args[2];
    
    if (args[1] == ">"){
    	read_pipe = popen(cmd, "r");
    	bytes_read = getdelim (dest, 1000, '\0', read_pipe);
	}
}


// For Input or <
void input(string command, char **args){
    
}

// For Error Redirection or 2>
void errorRedir(string command, char **args){


}

#endif
