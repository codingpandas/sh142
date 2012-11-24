//
//  builtin.h
//  sh142
//
//  Created by Alben Cheung on 11/24/12.
//  Copyright (c) 2012 Alben Cheung. All rights reserved.
//

#ifndef sh142_builtin_h
#define sh142_builtin_h

using namespace std;

void motd(){
	printf("\tComputer Engineering @ San Jose State University\n");
	printf("\tCreated by: Alben Cheung, Timothy Quan, Greg Mathews, David Kwong\n");
}

void loadDefaults(){
    
}

int checkFunctions(string command, char ** args){
	
	//Local Variables
	string cmdStr;
    
    //Predefine commands
    string clearCMD("clear");
    string cdCMD("cd");
    string exitCMD("exit");
    
	//Clear Screen
    if(clearCMD.compare(command) == 0){
		system("clear");
		return 0;
	}
    
	//Change Directory
    if(cdCMD.compare(command) == 0){
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
	if(exitCMD.compare(command) == 0){
		printf("Exiting Shell...\n");
		exit(EXIT_SUCCESS);
	}
    
	return 0;
}

int checkPATH(string command, char ** args){
    ofstream sh142, sh142tmp;
	int temp = 1;
	char c;
    string pathCMD("PATH=");
    
    if(command.find(pathCMD) == 0){
		printf("PATH change detected\n");
        sh142.open(".sh142");
        char output[100];
        if(sh142.is_open()){
            while(!sh142.eof()){
                sh142 >> output;
                cout << output;
            }
        }
        
        sh142.close();
    }
		/*sh142 = fopen(".sh142","r");
		//c = getc(sh142);
		//prints settings from the config file
		do {
			c = fgetc(sh142);
			printf("%c", c);
		} while(c != EOF);
		
		printf("test");
		sh142tmp = fopen(".sh142tmp", "w");
		do{
			c = fgetc(sh142tmp);
			if(c == ' '){}
			temp++;
            
		}while (c != EOF);
        
		if(temp != 1){
			putc(c, sh142tmp);
		}else{
			while((c = getc(sh142)) != ' '){
			}
			printf("Enter new text");
			fflush(stdin);
			putc(' ', sh142tmp);
			while((c = getchar()) != ' '){
				putc(c, sh142tmp);
				fputs(" ", sh142tmp);
				temp++;
			}
			c = getc(sh142);
		}
        
		fclose(sh142);
		fclose(sh142tmp);*/
    
	return 0;
}

int checkDATA(char * command, char ** args){
	return 0;
}

#endif
