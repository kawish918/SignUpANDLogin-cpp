#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<iomanip>
#include<windows.h>
using namespace std;

void signUp() {
	
	char ch;
	string username, password, passwordstar;
	cout << endl << endl << endl;
	
	cout << "\t\t___________________________________" << endl;
	cout << "\t\t" << setw(20) << "Signup" << setw(20) << endl << endl;
	cout << "\t\tEnter username: ";
	cin >> username;
	cout << "\n\t\tEnter password: ";
	
  ch = getch(); // getch() reads a character from the keyboard without displaying it on the screen 
  while (ch != 13) {  
    password.push_back(ch);  // add the character to the password string
    cout << "*"; // displays an asterisk on the screen
	ch = getch(); 
  }
	cout << "\n\t\tConfirm password: ";
	
  ch = getch(); // getch() reads a character from the keyboard without displaying it on the screen 
  while (ch != 13) {  
    passwordstar.push_back(ch);  // add the character to the password string
    cout << "*"; // displays an asterisk on the screen
	ch = getch(); 
  }
  cout << endl << endl;
	if(password == passwordstar)
	{
	ofstream outfile;
	outfile.open("users.txt", ios :: app);
	
	outfile << username << " " << password << endl;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\t\t    Signup successful!" << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	outfile.close();
	}else{
		system("cls");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t\t          Invalid!";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		return signUp();
	}
}

void login() {
	
	string username, password;
	cout << endl << endl << endl;
	cout << "\t\t___________________________________" << endl;
	cout << "\t\t" << setw(20) << "Login" << setw(20) << endl << endl;
	cout << "\t\tUsername: ";
	cin >> username;
	cout << "\n\t\t        Password: ";
    char ch;
  ch = getch(); // getch() reads a character from the keyboard without displaying it on the screen 
  while (ch != 13) {  
    password.push_back(ch);  // add the character to the password string
    cout << "*"; // displays an asterisk on the screen
	ch = getch(); 
  }
  cout << endl << endl;
	
	ifstream infile;
	infile.open("users.txt");
	
	string file_username, file_password;
	
	bool found = false;
	while(infile >> file_username >> file_password)
	{
		if(username == file_username && password == file_password)
		{
			found = true;
			break;
		}
	}
	
	if(found)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "\t\t       Login successful!" << endl;
		cout << "\t\t\tWELCOME " << username << "!";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	} 
	else{
		system("cls");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t\tIncorrect username or password." << endl;
		cout << "\t\t        Try Again!";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		return login();
	}
	infile.close();	
}

int main() {
	
	int choice;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\t\t\t_____________________________________________________________________________\n\n";
	cout << "\t\t\t" << setw(40) << "Welcome" << setw(35) << "\n";
	cout << "\t\t\t_____________________________________________________________________________\n\n";
    cout << setw(66) << "Please Login" << endl << endl;
    cout << setw(78) << "If you don't have an account Signup!\n" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	
	cout << setw(30) << "\t\t1. Signup" << endl;
	cout << setw(30) << "\t\t2. Login" << endl;
	cout << setw(30) << "\t\t3. Exit" << endl << endl;
	cout << setw(30) << "\t\tEnter choice: ";
	cin >> choice;
		cout << "-------------------------------";
	system("cls");
	
	switch(choice){
	case 1:
		signUp();
		break;
	case 2:
	    login();
		break;
	case 3:
		system("exit");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << setw(20) <<  "BYE!" << endl;
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << "Press any key.";
	}
}

