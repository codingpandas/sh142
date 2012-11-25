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
    string pathCMD("PATH=");
    
    if(command.find(pathCMD) == 0){
		printf("ENVIRONMENT PATH VARIABLE CHANGE DETECTED!\n\n");
        
        ofstream sh142tmp;
        sh142tmp.open(".sh142tmp");
        sh142tmp << command << endl;
        
        ifstream sh142 (".sh142");
        bool first = true;
        string output;
        if(sh142.is_open()){
            while(!sh142.eof()){
                if(first){
                    getline(sh142,output);
                    first = false;
                }else{
                    getline(sh142,output);
                    sh142tmp << output << endl;
                }
            }
        }
        sh142tmp.close();
        sh142.close();
        remove(".sh142");
        rename(".sh142tmp", ".sh142");
    }
	return 0;
}

int checkDATA(string command, char ** args){
    string pathCMD("DATA=");
    
    if(command.find(pathCMD) == 0){
		printf("ENVIRONMENT DATA VARIABLE CHANGE DETECTED!\n\n");
        
        ofstream sh142tmp;
        sh142tmp.open(".sh142tmp");
        
        ifstream sh142 (".sh142");
        bool first = true;
        bool second = false;
        string output;
        if(sh142.is_open()){
            while(!sh142.eof()){
                if(first){
                    getline(sh142,output);
                    sh142tmp << output << endl;
                    first = false;
                    second = true;
                }
                if (second) {
                    getline(sh142, output);
                    cout << command << endl;
                    sh142tmp << command << endl;
                    second = false;
                }
                else{
                    getline(sh142,output);
                    sh142tmp << output << endl;
                }
            }
        }
        sh142tmp.close();
        sh142.close();
        remove(".sh142");
        rename(".sh142tmp", ".sh142");
        
    }
	return 0;
}

/*int variableSetter(string command, char ** args){
    regex cmdREGEX("[a-z]+\\(*)=[a-z]+\\");
    if(regex_match(command, cmdREGEX)){
        cout << "variable detected";
    }else{
    }
    return 0;
}*/

#endif
