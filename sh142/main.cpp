//
//  main.cpp
//  sh142
//
//  Created by Alben Cheung on 11/24/12.
//  Copyright (c) 2012 Alben Cheung. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "builtin.h"
#include "parser.h"
#include "hwutil.h"
#include "io.h"
#define BUFFER_SIZE 1<<16
#define ARR_SIZE 1<<16

//Global Variables
char cmd[100];

int main(){
    
	//Local Variables
	char buffer[BUFFER_SIZE];
	char *args[ARR_SIZE];
    int *ret_status;
    size_t nargs;
    pid_t pid;
    
    //Configuration FIle Variables
    FILE *sh142, *sh142tmp;
    char c;
    int temp = 1;
    
    //Message of the Day
	motd();
    
	//Create the .sh142 with defaults, if it doesn't exist
	if(access(".sh142", F_OK) != -1){
		printf("Loading shell configuration file...\n");
	}else{
		printf("Shell configuration is missing...\n");
		printf("Creating shell configuration with defaults...\n");
		sh142 = fopen(".sh142","w");
		fprintf(sh142, "PATH=/home/usr/myname:/usr/bin\n");
		fprintf(sh142, "DATA=/data/files:/home/usr/myname\n");
		fclose(sh142);
        
	}
    
    while(1){
    	printf("$sh142 ->");
    	fgets(buffer, BUFFER_SIZE, stdin);
    	parse_args(buffer, args, ARR_SIZE, &nargs);
    	
    	//Checks for Built-in Functions
    	checkFunctions(buffer, args);
        
    	//Change PATH settings
    	checkPATH(buffer, args);
        
    	//Change DATA settings
    	checkDATA(buffer, args);
   	}
    
	return 0;
}


