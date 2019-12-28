#include "aux_funcs.h"
#include "files.h"

using namespace std;

void help(const string elem);

void sleep(const int seconds);
vector<string> split_string(const string& str, const string& delimiter);

void login();
void first_time_login();
void main_loop();

class User_Acc{
    public:
        User_Acc(){
            int isLogged = exists("dtbs.txt");
            if (isLogged == 0){
            first_time_login();
            }
            else{
                login();
            }
        }
};

int main(){


 // User_Acc acc;
 
 main_loop();

    return 0;
}



void first_time_login(){
    TCHAR username[UNLEN + 1];
    DWORD size = UNLEN + 1;
    GetUserName((TCHAR*)username, &size);
    string password;
    ofstream dtbs;
    dtbs.open("dtbs.txt", ios::out);

    cout << "\nChoose a password > ";
    cin >> password;
    dtbs << password << endl;

    cout << "\n\nWelcome to Rubicon Shell, " << username << "!\n\n";
    sleep(3);
    main_loop();
}

void login(){
	string username;
	string try_username;
    string try_password;
    string password;
    TCHAR default_username[UNLEN + 1];
    DWORD size = UNLEN + 1;
    GetUserName((TCHAR*)default_username, &size);
    ifstream dtbs("dtbs.txt");

    while(!dtbs.eof()){
    	dtbs >> username;
    	dtbs >> password;
    }
    dtbs.close();
    cout << "Username > ";
    cin >> try_username;
    cout << "\nPassword > ";
    cin >> try_password;

    if(try_password == password){
    	if(try_username == username){
            cout << "Welcome to Rubicon Shell, @" << username << "!";
            sleep(3);
            system("@cls||clear");
            main_loop();
        } else cout << "Incorrect Username";
} else cout << "Incorrect Password";
}

void main_loop(){

string cmd_mob;
vector<string> cmd;

while(1){
	cout << getdir() << " > " ;
	getline(cin, cmd_mob);
	cmd = split_string(cmd_mob, " ");
	if(cmd[0] == "help"){
		try{
			help(cmd[1]);
		} catch(...){
			help("a");
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
	 	vector<string> dirs = listdir();
	 	cout << endl;
	 	for(int i = 0; i < dirs.size(); i++){
	 		cout << dirs[i] << endl;
		 }
		 cout << endl;
	 }
	 else if(cmd[0] == "cd"){
	 		if(cmd_mob == "cd"){
	 			help("file");
			 } else{
			 	if(chdir(cmd[1].c_str()) != NULL){
			 		cout << colorize("This directory does not exist: ", "red") << colorize(cmd[1], "red") << endl;
			 		end_colorize();
				 }
	 }
}
	 else if(cmd[0] == "music"){
	 	//music_menu();
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
	cout << "  clear                                 Clear screen" << endl;
	cout << "  music                                 Opens music menu" << endl << endl << endl;
} else if(elem == "file"){
	cout << "Files:" << endl;
	cout << "  write to [file]                                 Opens code editor to write a file" << endl;
	cout << "  append to [file]                                Opens code editor to append to a file" << endl;
	cout << "  read [file]                                     Prints content of a file onscreen" << endl;
	cout << "  copy [file] to [new file path]                  Copies the content of a file to another file" << endl;
	cout << "  remove or rm [file]                             Removes a file" << endl;
} else if(elem == "music"){
	cout << "  play [song filename]                            Plays a song in predetermined music player" << endl;
	cout << "  play cmd [song filename]                        Plays a song in the console" << endl;
	cout << "  *download or dw [youtube or google link]        Downloads .mp3 file to Music folder" << endl;
} else{
	cout << "\nUsage of help:" << endl;
	cout << "   Help [element]";
	cout << "\n\nElements available: \n" << endl;
	cout << "file" << endl << "music" << endl << "overall / miscelanea / general" << endl << endl;
}
}
