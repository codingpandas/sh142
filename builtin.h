void motd(){
	printf("\tComputer Engineering @ San Jose State University\n");
	printf("\tCreated by: Alben Cheung, Timothy Quan, Greg Mathews, David Kwong\n");
}

void checkFunctions(char * command, char ** args){
	
	//Local Variables
	char cmdStr[100];

	//VIM
	if(strcmp("vim", command) == 0){
		if(args[1] == NULL){
			system("vim");
		}else{
		}
	}

	//VI
	if(strcmp("vi", command) == 0){
		system("vi");
	}

	//Clear Screen
	if(strcmp("clear", command) == 0){
		system("clear");
	}

	//Change Directory
	if(strcmp("cd", command) == 0){
		if(args[1] == NULL){
			chdir(getenv("HOME"));
		}else{
			if(chdir(args[1]) == -1){
				printf(" %s: No such directory\n", args[1]);
			}
		}
	}

	//Exit
	if(strcmp("exit", command) == 0){
		printf("Exiting Shell...\n");
		exit(0);
	}

}