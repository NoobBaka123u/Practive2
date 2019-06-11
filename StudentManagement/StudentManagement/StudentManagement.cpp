#include <iostream>
#include <string>
#include <fstream>
#define MAX 50

using namespace std;

struct student
{
	string name;
	int id;
	float score;
};

typedef struct student Student;

struct liststudent
{
	Student *arr;
	int n;
};

typedef struct liststudent ListStudent;

void PrintMenu(); //menu

void InputStudent(); //Input a sutdent 

void OutputStudent();

void InputListStudent(ListStudent &ls);

void OutputListStudent(ListStudent ls);

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

void InputStudent(Student &s)
{
	Student student;
	cout << "id: ";
	cin >> student.id;
	
	fflush(stdin);
	 
	cout << "full name: ";
	getline(cin, student.name);

	cout << "score: ";
	cin >> student.score;

}

void OutputStudent(Student &s)
{
	cout << s.id << " " << s.name << "       " << s.score;
}

void InputListStudent(ListStudent &ls)
{
	for (int i = 0; i < ls.n; i++)
	{
		cout << "\nInput student " << i + 1 << endl;
		InputStudent(ls.arr[i]);
	}
}

void OutputListStudent(ListStudent ls)
{
	for (int i = 0; i < ls.n; i++)
	{
		cout << "\nStudent " << i + 1 << endl;
		OutputStudent(ls.arr[i]);
	}
}

void PrintList()
{
	printf("%--5s %-20s %s\n", "ID", "FULL NAME", "SCORE");
	
}

void Process(int choose)
{
	if (choose == 1)
	{
		InputStudent();
		
	}
	if (choose == 2)
	{
		cout << endl;
		PrintList();
		cout << endl;
	}
	else if (choose == 3)
	{
		SaveToFile("saveFile.txt");
	}
	else if (choose == 4)
	{
		LoadFromFile("loadFile.txt");
		PrintList();
	}
	else if (choose < 1 || choose > 4)
	{
		cout << "Your choose wrong!";
	}
}
