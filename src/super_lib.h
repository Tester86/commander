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


