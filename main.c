#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "builtin.h"
#define MAXLINE 4096

//Global Variables
char cmd[100];

int main(){

	motd();
	printf("$sh142 ->");
	scanf("%[^\n]", &cmd);
	printf("Entered Command: %s\n", cmd);
	checkFunctions(cmd);
	return 0;
}
