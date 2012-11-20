#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "builtin.h"
#include "parser.h"
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

	motd();

    while(1){
    	printf("$sh142 ->");
    	fgets(buffer, BUFFER_SIZE, stdin);
    	parse_args(buffer, args, ARR_SIZE, &nargs);
    	
    	//Checks for Built-in Functions
    	checkFunctions(buffer, args);
   	}

	return 0;
}
