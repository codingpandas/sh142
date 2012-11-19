void motd(){
	printf("\tComputer Engineering @ San Jose State University\n");
	printf("\tCreated by: Alben Cheung, Timothy Quan, Greg Mathews, David Kwong\n");
}

void checkFunctions(char * command[100]){
	if(strcmp("exit",command) == 0){
		printf("exiting...\n");
		exit(0);
	}
	if(strcmp("cd",command) == 0){
		changeDir(command);
		return 1;
	}
}

void changeDir(char * command[100]){
	if(command[1] == NULL){
		printf("HOME");
		chdir(getenv("HOME"));
	}else{
		if(chdir(command[1] == -1)){
			printf("No directory");
		}
	}
}