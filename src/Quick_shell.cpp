#include "super_lib.h"

using namespace std;

void help(const string elem);
void sleep(const int seconds);
vector<string> split_string(const string& str, const string& delimiter);
void main_loop();

int main(){
 
 main_loop();

    return 0;
}

void main_loop(){

string cmd_mob;
vector<string> cmd;

while(1){
	cout << getdir() << "> " ;
	getline(cin, cmd_mob);
	cmd = split_string(cmd_mob, " ");
	if(cmd[0] == "help"){
		if(cmd_mob == "help"){
			help("a");
		}
		else{
			help(cmd[1]);
	}
}
	 else if(cmd[0] == "write"){
	 	init_fw(cmd[1], "w");
	 }
	 else if(cmd[0] == "read"){
	 	init_fw(cmd[1], "r");
	 }
	 else if(cmd[0] == "append"){
	 	init_fw(cmd[1], "a");
	 }
	 else if(cmd[0] == "copy"){
	 	copy(cmd[1], cmd[3]);
	 }
	 else if(cmd[0] == "clear" || cmd[0] == "cls"){
	 	clear();
	 }
	 else if(cmd[0] == "ls"){
	 	vector<string> elems = listdir();
	 	vector<string> files;
	 	vector<string> dirs;
	 	
	 	for(int i = 0; i < elems.size(); i++){
	 		if(isFile(elems[i])){
	 			files.push_back(elems[i]);
			 } else dirs.push_back(elems[i]);
		 }
		 
		 for(int i = 0; i < files.size(); i++){
		 	cout << colorize(files[i], "green") << endl;
		 }
		 end_colorize();
		 for(int i = 0; i < dirs.size(); i++){
		 	cout<< colorize(dirs[i], "blue") << endl;
		 }
		 end_colorize();
	 }
	 else if(cmd[0] == "cd"){
	 		if(cmd_mob == "cd"){
	 			help("file");
			 } else{
			 	if(chdir(cmd[1].c_str()) != 0){
			 	cout << colorize("This directory does not exist: ", "red") << colorize(cmd[1], "red") << endl;
			 	end_colorize();
			 }
	 }
}
	 else if(cmd[0] == "rm" || cmd[0] == "remove"){
	 	for(int i = 1; i < cmd.size(); i++){
	 		rmfile(cmd[i]);
		 }
	 }
	 else if(cmd[0] == "music"){
	 	music_menu();
	 }
	 else if(cmd[0] == "play"){
	 	play_song(cmd[1]);
	 }
	 else if(cmd[0] == "exit"){
	 	exit(1);
	 }
	 else{
	 	if(!(cmd_mob == "")){
	 		help("a");
		 }
	 }
}
}


void help(const string elem){
	if(elem == "miscelanea" || elem == "general" || elem == "overall"){
	cout << "\nTask:                                Function:" << endl << endl;
	cout << "  help                                  Shows help menu" << endl;
	cout << "  clear / cls                           Clear screen" << endl << endl;
} else if(elem == "files"){
	cout << "\nFiles:" << endl;
	cout << "  write [file]                                 Opens code editor to write a file" << endl;
	cout << "  append [file]                                Opens code editor to append to a file" << endl;
	cout << "  read [file]                                  Prints content of a file onscreen" << endl;
	cout << "  copy [file] to [new file path]               Copies the content of a file to another file" << endl;
	cout << "  remove / rm [file / dir]                     Removes a file" << endl << endl;
} else if(elem == "music"){
	cout << "\n  music                                           Opens music menu" << endl;
	cout << "  play [song filename]                            Plays a song in predetermined music player" << endl;
	cout << "  *download / dw [youtube or google link]         Downloads .mp3 file to Music folder" << endl << endl;
} else{
	cout << "\nUsage of help:" << endl;
	cout << "   Help [element]";
	cout << "\n\nElements available: \n" << endl;
	cout << "files" << endl << "music" << endl << "overall / miscelanea / general" << endl << endl;
}
}
