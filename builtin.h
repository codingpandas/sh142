void motd(){
	printf("\tComputer Engineering @ San Jose State University\n");
	printf("\tCreated by: Alben Cheung, Timothy Quan, Greg Mathews, David Kwong\n");
}

void checkFunctions(char * nargs){
	if(strcmp("exit",nargs) == 0){
		printf("exiting...\n");
		exit(0);
	}

}