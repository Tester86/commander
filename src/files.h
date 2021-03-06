#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>

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
	string line;
	ifstream dtbs(filename.c_str());
	while(getline(dtbs, line)){
		cout << line << endl;
	}
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

bool isFile(const string elem){
	DIR* directory = opendir(elem.c_str());

    if(directory != NULL)
    {
     closedir(directory);
     return false;
    }

    if(errno == ENOTDIR)
    {
     return true;
    }

    return false;
}

bool isDir(const string elem){
	if(chdir(elem.c_str()) == 0){
		return true;
	}
	return false;
}

/*void add_to_playlist(const string elem){
	ofstream elem;
}*/
