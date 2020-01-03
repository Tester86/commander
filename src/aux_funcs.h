#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <lmcons.h>
#include <limits.h>
#include <cstring>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <bits/stdc++.h>
#include <io.h>

using namespace std;

string music_path;
string home_path;

void first_time_dtbs_login(){
	mkdir("../etc");
		chdir("../etc");
		
		ofstream dtbs_first_time("dtbs.txt");
		string music_path_confirm, home_path_confirm;
		cout << endl << "Enter path to music directory > ";
		cin >> music_path;
		cout << endl << "Confirm path to music directory > ";
		cin >> music_path_confirm;
		cout << endl << "Enter home path > ";
		cin >> home_path;
		cout << endl << "Confirm home path > ";
		cin >> home_path_confirm;
		if(home_path != home_path_confirm){
			cout << endl << "Home paths are not the same!";
			Sleep(3);
			exit(1);
		}
		else{
			dtbs_first_time << home_path << endl;
		}
		if(music_path != music_path_confirm){
			cout << endl << "Music paths are not the same";
			Sleep(3);
			exit(1);
		} else{
			dtbs_first_time << music_path;
		}
}

string get_music_path(){
	if(chdir("../etc") != 0){
		first_time_dtbs_login();
} else{
	ifstream dtbs("dtbs.txt");
	dtbs >> music_path;
	dtbs >> music_path;
} return music_path;
}

string get_home_path(){
	if(chdir("../etc") != 0){
		first_time_dtbs_login();
	} else{
		ifstream dtbs("dtbs.txt");
		dtbs >> home_path;
	} return home_path;
}

string get_data(){
	string music_path, home_path;
	if(chdir("../etc") != 0){
		mkdir("../etc");
		chdir("../etc");
		
		ofstream dtbs_first_time("dtbs.txt");
		string music_path_confirm, home_path_confirm;
		
		cout << endl << "Enter path to music directory > ";
		cin >> music_path;
		cout << endl << "Confirm path to music directory > ";
		cin >> music_path_confirm;
		if(music_path != music_path_confirm){
			cout << endl << "Paths are not the same";
			Sleep(3);
			exit(1);
		} else{
			dtbs_first_time << music_path << endl;
		}
		cout << endl << "Enter path to home > ";
		cin >> home_path;
		cout << endl << "Confirm path to home > ";
		cin >> home_path_confirm;
		if(home_path != home_path_confirm){
			cout << endl << "Paths are not the same > ";
			Sleep(3);
			exit(1);
		} else{
			dtbs_first_time << home_path << endl;
		}
		return music_path, home_path;
	} else{
		ifstream dtbs("dtbs.txt");
		while(!dtbs.eof()){
			dtbs >> music_path;
			dtbs >> home_path;
			cout << music_path << endl << home_path;
			return music_path, home_path;
		}
	}
	
}

wstring string_to_wstring(const string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0); 
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    wstring r(buf);
    delete[] buf;
    return r;
}

string toString(char arr[]){
	string s(arr);
	return s;
}

int exists(const char *filename){
    FILE *f;
    if ((f = fopen(filename, "r"))){
        fclose(f);
        return 1;
    }
    else{
        return 0;
    }
}

void sleep(const int seconds){
    clock_t time_end;
    time_end = clock() + seconds*1000 + CLOCKS_PER_SEC/1000;
    while(clock() < time_end){}
}

vector<string> split_string(const string& str,
                                      const string& delimiter)
{
    vector<string> strings;

    string::size_type pos = 0;
    string::size_type prev = 0;
    while ((pos = str.find(delimiter, prev)) != string::npos)
    {
        strings.push_back(str.substr(prev, pos - prev));
        prev = pos + 1;
    }

    // To get the last substring (or only, if delimiter is not found)
    strings.push_back(str.substr(prev));

    return strings;
}

int check(string word, vector<string> word_list){
	for(int i = 0; i < word_list.size(); i++){
		if(word_list[i] == word){
			return 1;
		} else return 0;
	}
}

int get_pos(string word, vector<string> word_list){
	for(int i = 0; i < word_list.size(); i++){
		if(word_list[i] == word){
			return i;
		}
		else return -1;
	}
}

void clear(){
	system("@cls");
}

string getdir(){
   char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       return toString(cwd);
   } 
}

vector<string> listdir(){
  vector<string> names;
  string name;
  DIR *dp;
  struct dirent *ep;  
  dp = opendir ("./");

  if (dp != NULL)
  {
    while (ep = readdir (dp)){
      name = ep->d_name;
      if(name.rfind(".", 0)!=0){
      names.push_back(ep->d_name);
  }
}
    (void) closedir (dp);
  }
  return names;
}

string colorize(const string word, const string color){
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD final_color;
	if(color == "red"){
		final_color = FOREGROUND_RED | FOREGROUND_INTENSITY;
	}
	else if(color == "blue"){
		final_color = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	}
	else if(color == "green"){
		final_color = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	}
	SetConsoleTextAttribute(outcon, final_color);
	return word;
}

void end_colorize(){
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(outcon, 15);
}

bool endswith(const string &full_str, const string &ending){
	if (full_str.length() >= ending.length()) {
        return (0 == full_str.compare (full_str.length() - ending.length(), ending.length(), ending));
    } else return false;
}


