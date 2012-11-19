#include <stdio.h>
#include <errno.h>
#include <string.h>
#define MAXLINE 4096

//Global Variables
char cmd[100];

int main(){

	printf("\tComputer Engineering @ San Jose State University\n\tCreated by: Alben Cheung, Timothy Quan, Greg Mathews, David Kwong\n");
	printf("$sh142 ->");
	scanf("%[^\n]", &cmd);
	printf("Entered Command: %s\n", cmd);
	return 0;
}
