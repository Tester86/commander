#include "aux_funcs.h"
#include "files.h"

/////////////////////////////// MUSIC ///////////////////////////

void play_song(const string filename){
	string win_cmd;
	
	if(exists(filename.c_str()) && (endswith(filename, ".mp3") || endswith(filename, ".wav"))){
		win_cmd = "start " + filename;
		system(win_cmd.c_str());
		} else{
		cout << colorize("This song does not exist: ", "red") << colorize(filename, "red") << endl;
		end_colorize();
	}
}

int choose_song(int vsize){
	int song_number;
	while(1){
		cout << "Choose a song number > ";
		cin >> song_number;
		if(song_number == 99) break;
		else if(song_number > vsize || song_number < 1){
			cout << "Invalid number" << endl;
			choose_song(vsize);
		} else return song_number;
	}
}

void music_menu(){
	vector<string> files = listdir();
	vector<string> music_files;
	int counter;
	int song_num;
	string win_cmd;
	for(int i = 0; i < files.size(); i++){
		if(endswith(files[i], ".mp3") || endswith(files[i], ".wav")){
			music_files.push_back(files[i]);
		}
	}
	if(music_files.size() > 0){
	cout << endl;
	for(int i = 0; i < music_files.size(); i++){
		counter = i + 1;
		cout << counter << ". " << music_files[i] << endl;
	}
	while(1){
	cout << endl;
	song_num = choose_song(music_files.size());
	if(song_num == 99){
		break;
	} else{
	win_cmd = "start " + music_files[song_num - 1];
	
	system(win_cmd.c_str());
}
}
}
}

void adapt(){
	vector<string> elems = listdir();
	int result;
	for(int i = 0; i < elems.size(); i++){
		if(endswith(elems[i], ".webm")){
			string new_name;
			cout << "Save downloaded song as... > ";
			cin >> new_name;
			if(!endswith(new_name, ".mp3")){
				new_name += ".mp3";
			}
			result = rename(elems[i].c_str(), new_name.c_str());
			if(result != 0){
				cout << "An error occurred while trying to rename the downloaded file" << endl;
			} else cout << new_name << " successfully downloaded" << endl;
		}
	}
}

void play_list(const string filename){
	if(!exists(filename.c_str())){
		cout << colorize("This file does not exist: ", "red") << filename << endl;
		end_colorize();
	}
	else{
		ifstream song_dtbs;
		song_dtbs.open(filename.c_str());
		string line, win_cmd;
		vector<string> songs;
		
		while(getline(song_dtbs, line)){
			songs.push_back(line);
		}
		for(int i = 0; i < songs.size(); i++){
			if(exists(songs[i].c_str())){
				win_cmd = "start " + songs[i];
				system(win_cmd.c_str());
			}
			else{
				cout << colorize("This file does not exist: ", "red") << songs[i] << endl;
				end_colorize();
				continue;
			}
		}
	}
}
/////// FILES ///////////

void rmdirec(const string dirname){
	if(rmdir(dirname.c_str()) != 0){
		cout << "Error" << endl;
	}
}

void rmfile(const string filename){
	if(isFile(filename)){
		if(remove(filename.c_str()) != 0){
			cout << colorize("This file does not exist: ", "red") << filename << endl;
			end_colorize();
		}
	}
	else if(isDir(filename)){
		chdir(filename.c_str());
		vector<string> elems = listdir();
		for(int i = 0; i < elems.size(); i++){
			if(isFile(elems[i])){
				if(remove(elems[i].c_str()) != 0){
					cout << colorize("An error occurred when trying to delete this file: ", "red") << elems[i] << endl;
					end_colorize();
				}
			} else{
				rmfile(elems[i]);
			}
	}
	chdir("..");
	rmdir(filename.c_str());
}
}

void move_file(const string filename, const string dir){
		if(exists(filename.c_str())){
			string f2 = dir + "/" + filename;
			string win_cmd = "del " + filename;
			ifstream file1(filename.c_str(), ios::in | ios::binary);
			ofstream file2(f2.c_str(), ios::out | ios::binary);
			file2 << file1.rdbuf();
			file1.close();
			file2.close();
			rmfile(filename);
			} else{
			cout << colorize("This file does not exist: ", "red") << colorize(filename, "red");
			end_colorize();
		}
}

bool containsFileType(const string filetype){
	vector<string> elems = listdir();
	for(int i = 0; i < elems.size(); i++){
		if(endswith(elems[i], filetype)) return true;
		else return false;
	}
}
