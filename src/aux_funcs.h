#include <iostream>
#include <fstream>
#include <string>
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

using namespace std;

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
	{
    vector<string> names;
    string search_path = getdir() + "/*.*";
    WIN32_FIND_DATA fd; 
    HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd); 
    if(hFind != INVALID_HANDLE_VALUE) { 
        do { 
            // read all (real) files in current folder
            // , delete '!' read other 2 default folder . and ..
            if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ) {
                names.push_back(fd.cFileName);
            }
        }while(::FindNextFile(hFind, &fd)); 
        ::FindClose(hFind); 
    } 
    return names;
}
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
