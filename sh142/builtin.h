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

//Global Return Status Variables
int exitStatus[10];
int retStat = -10;
int statusIndex = 0;

void motd(){
	printf("\tComputer Engineering @ San Jose State University\n");
	printf("\tCreated by: Alben Cheung, Timothy Quan, Greg Mathews, David Kwong\n");
}

void returnStatus(){
    if(retStat != -10){
        exitStatus[statusIndex] = retStat;
        retStat = -10;
        statusIndex++;
    }
}

int checkExitStatus(string command, char ** args){
    string checkStat("$?");
    
    if (command.find(checkStat) == 0) {
        
        if(command.compare("$?1") == 0 ){
            int i = statusIndex - 1 ;
            cout << exitStatus[i] << endl;
        }
        
        if(command.compare("$?2") == 0 ){
            int i = statusIndex - 2 ;
            cout << exitStatus[i] << endl;
        }
        
        if(command.compare("$?3") == 0 ){
            int i = statusIndex - 3 ;
            cout << exitStatus[i] << endl;
        }
        
        if(command.compare("$?4") == 0 ){
            int i = statusIndex - 4 ;
            cout << exitStatus[i] << endl;
        }
        
        if(command.compare("$?5") == 0 ){
            int i = statusIndex - 5 ;
            cout << exitStatus[i] << endl;
        }
        
        if(command.compare("$?6") == 0 ){
            int i = statusIndex - 6 ;
            cout << exitStatus[i] << endl;
        }
        
        if(command.compare("$?7") == 0 ){
            int i = statusIndex - 7 ;
            cout << exitStatus[i] << endl;
        }
        
        if(command.compare("$?8") == 0 ){
            int i = statusIndex - 8 ;
            cout << exitStatus[i] << endl;
        }
        
        if(command.compare("$?9") == 0 ){
            int i = statusIndex - 9 ;
            cout << exitStatus[i] << endl;
        }
        
        if(command.compare("$?10") == 0 ){
            int i = statusIndex - 10 ;
            cout << exitStatus[i] << endl;
        }
        
        retStat = 0;
        return 0;
    }else{
        cout << "Please use a valid format: $?<number>" << endl;
    }
    
    return 0;
}

int checkFunctions(string command, char ** args){
	
	//Local Variables
	char cmdStr[100];
    
    //Predefine commands
    string clearCMD("clear");
    string cdCMD("cd");
    string exitCMD("exit");
    string lsCMD("ls");
    
    //List Files in Directory
    if(lsCMD.compare(command) == 0){
   		if(args[1] == NULL){
            system("ls");
            retStat = 0;
            returnStatus();
        }
        if(args[1] != NULL){
            strcpy(cmdStr, "ls ");
            strcat(cmdStr, args[1]);
            system(cmdStr);
            retStat = 0;
            returnStatus();
        }
		return 0;
    }    


	//Clear Screen
    if(clearCMD.compare(command) == 0){
		system("clear");
        retStat = 0;
		return 0;
	}
    
	//Change Directory
    if(cdCMD.compare(command) == 0){
		if(args[1] == NULL){
			chdir(getenv("HOME"));
            retStat = 0;
            returnStatus();
		}else{
			if(chdir(args[1]) == -1){
				printf(" %s: No such directory\n", args[1]);
                retStat = -1;
                returnStatus();
                return -1;
			}
		}
		return 0;
	}
    
	//Exit
	if(exitCMD.compare(command) == 0){
		printf("Exiting Shell...\n");
        retStat = 0;
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
                    sh142tmp << output;
                }
            }
        }
        sh142tmp.close();
        sh142.close();
        remove(".sh142");
        rename(".sh142tmp", ".sh142");
        retStat = 0;
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
                    sh142tmp << command << endl;
                    second = false;
                }
                else{
                    getline(sh142,output);
                    sh142tmp << output;
                }
            }
        }
        sh142tmp.close();
        sh142.close();
        remove(".sh142");
        rename(".sh142tmp", ".sh142");
        retStat = 0;
        
    }
	return 0;
}

int variableSetter(string command, char ** args){
    string varSet("setvar");
    string equalsVar("=");
    size_t found;
    found = command.find(equalsVar);
    if(command.find(varSet) == 0){
        //if(found!=string::npos){
            ofstream sh142;
            sh142.open(".sh142",ios::app);
            cout << args[1];
            sh142 << args[1] << endl;
            sh142.close();
        //}
        retStat = 0;
    }
    
    return 0;
}

int variableUnsetter(string command, char ** args){
    string varUnset("unsetvar");
    
    if(command.find(varUnset) == 0){
        ofstream sh142tmp;
        sh142tmp.open(".sh142tmp");
        
        ifstream sh142 (".sh142");
        string output;
        if(sh142.is_open()){
            while(!sh142.eof()){
                getline(sh142,output);
                if(output == args[1]){
                    
                }
                if(output != args[1]){
                    sh142tmp << output << endl;
                }
            }
        }
        sh142tmp.close();
        sh142.close();
        remove(".sh142");
        rename(".sh142tmp", ".sh142");
        retStat = 0;
    }
    
    return 0;
}

#endif
