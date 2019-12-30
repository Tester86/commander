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

void first_time_login(){
	string music_path_confirm;
	string home_path_confirm;
	
    TCHAR username[UNLEN + 1];
    DWORD size = UNLEN + 1;
    GetUserName((TCHAR*)username, &size);
    string password;
    ofstream dtbs;
    dtbs.open("dtbs.txt", ios::out);

    cout << "\nChoose a password > ";
    cin >> password;
    dtbs << password << endl;
    
    cout << endl << "Enter path for music folder > ";
    cin >> music_path;
    cout << endl << "Confirm your music folder's path > ";
    cin >> music_path_confirm;
    
    if(music_path != music_path_confirm){
    	cout << endl << "Paths do not match";
    	exit(1);
	}
	else{
		dtbs << music_path << endl;
	}
	
	cout << endl << "Enter path to home > ";
	cin >> home_path;
	cout << endl << "Confirm path to home > ";
	cin >> home_path_confirm;
	
	if(home_path != home_path_confirm){
		cout << "Paths do not match";
		exit(1);
	}
	else{
		dtbs << home_path << endl;
	}
    
    cout << "\n\nWelcome to Rubicon Shell, " << username << "!\n\n";
    sleep(3);
    main_loop();
}

void login(){
	string username;
	string try_username;
    string try_password;
    string password;
    string home_path;
    string music_path;
    TCHAR default_username[UNLEN + 1];
    DWORD size = UNLEN + 1;
    GetUserName((TCHAR*)default_username, &size);
    ifstream dtbs("dtbs.txt");

    while(!dtbs.eof()){
    	dtbs >> username;
    	dtbs >> password;
    	dtbs >> home_path;
    	dtbs >> music_path;
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

