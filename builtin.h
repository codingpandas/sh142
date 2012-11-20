void motd(){
	printf("\tComputer Engineering @ San Jose State University\n");
	printf("\tCreated by: Alben Cheung, Timothy Quan, Greg Mathews, David Kwong\n");
}

void checkFunctions(char * command, char * args){
	
	if(strcmp("cd", command) == 0){
		printf("%s\n", &args[1]);
		if(args[1] == NULL){
			printf("HOME dir");
			chdir(getenv("HOME"));
		}else{
			if(chdir(args[1]) == -1){
				printf("No such directory");
			}
		}
		return 1;
	}

	if(strcmp("exit", command) == 0){
		printf("exiting...\n");
		exit(0);
	}

}