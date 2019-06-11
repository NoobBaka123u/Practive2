#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Student
{
	string name;
	int id;
	float score;

};

void PrintMenu(); //menu

Student Input(); //Input a sutdent 

void PrintList(); //print studen list

void Process(int choose); //choose value

void SaveToFile(string fileName); //save all student to file

void LoadFromFile(string fileName);

void Replace(string &str);


void main() {

}

void PrintMenu() 
{
	cout << "----------------------MENU--------------------" << endl;
	cout << "1. Input" << endl;
	cout << "2. Display" << endl;
	cout << "3. Save to file" << endl;
	cout << "4. Load from file" << endl;
	cout << "0. Exit" << endl;
}


Student Input()
{
	Student student;
	cout << "id: ";
	cin >> student.id;
	
	fflush(stdin);
	 
	cout << "full name: ";
	getline(cin, student.name);

	cout << "score: ";
	cin >> student.score;

	return student;
}