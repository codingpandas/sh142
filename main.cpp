#include <iostream>
#include <string.h>

using namespace std;

int getFirstWhiteSpace(string);

int main(){
	string cmd = "";
	char lastCMDS[9];
	int cmdCount = 0;
	int cmdPosition = 0;
	cout << "\tA Custom Unix Shell 142\n\tCreated by: Alben Cheung\n";

	while(cmd != "exit"){
		if(cmd != ""){
			system(cmd.c_str());
			cmd = "";
		}
		cout << "#sh142 ->";
		cin >> cmd;
	}
	return 0;
}