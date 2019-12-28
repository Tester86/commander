#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void init_fw(const string filename, const string mode){
	
	string line;
	
	if(mode == "w"){
		ofstream efile;
		efile.open(filename.c_str());
		while(1){
			cout << "--> ";
			getline(cin, line);
			if(line == "abort"){
				break;
			}
			efile << line << endl;
		}
		efile.close();
	}
	else if(mode == "r"){
		FILE *f = fopen(filename.c_str(), "r");
		char c;
		
		c  = fgetc(f);
		
		while(c != EOF){
			cout << c;
			c = fgetc(f);
		}
		fclose(f);
	}
	else if(mode == "a"){
		ofstream efile;
		efile.open(filename.c_str(), ios_base::app);
		while(1){
			cout << "--> ";
			getline(cin, line);
			if(line == "abort"){
				break;
			}
			efile << line << endl;
		}
	}
	}
	
void copy(const string first_filename, const string second_filename){
	string line;
	
	ifstream f1(first_filename.c_str(), ios_base::in);
	ofstream f2(second_filename.c_str(), ios_base::out);
	
	while(getline(f1, line)){
		f2 << line << endl;
	}
	f1.close();
	f2.close();
}

bool isFile(vector<string> elems){
	for(int i = 0; i < elems.size(); i++){
		
	}
}
