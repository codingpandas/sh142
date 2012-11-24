void motd(){
	printf("\tComputer Engineering @ San Jose State University\n");
	printf("\tCreated by: Alben Cheung, Timothy Quan, Greg Mathews, David Kwong\n");
}

void loadDefaults(){

}

int checkFunctions(char * command, char ** args){
	
	//Local Variables
	char cmdStr[100];

	//Clear Screen
	if(strcmp("clear", command) == 0){
		system("clear");
		return 0;
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
		return 0;
	}

	//Exit
	if(strcmp("exit", command) == 0){
		printf("Exiting Shell...\n");
		exit(0);
	}

	return 0;
}

int checkPATH(char * command, char ** args){
	FILE *sh142, *sh142tmp;
	int temp = 1;
	char c;

	if(strstr("PATH=", command)==0){
		printf("PATH change detected\n");
		sh142 = fopen(".sh142","r");		
		c = getc(sh142);	
		//prints settings from the config file
		while (c != EOF){
			printf("%c", c);
			c = getc(sh142);
		}
		//revert to file start point
		rewind(sh142);
			
		sh142tmp = fopen(".sh142tmp", "w");
		c = getc(sh142tmp);

		fclose(sh142);
		fclose(sh142tmp);
	}

	return 0;
}

int checkDATA(char * command, char ** args){
	return 0;
}