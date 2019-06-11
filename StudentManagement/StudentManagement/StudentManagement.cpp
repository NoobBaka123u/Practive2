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

	void print()
	{
		printf("%-5d %-20s %-f", id, name.c_str(), score);
	}
};

typedef struct student Student;

Student *student = new Student[MAX];

static int length = 0;

void PrintMenu(); //menu

void Input();

void PrintList(); //print studen list

void Process(int); //choose value

void SaveToFile(string); //save all student to file

void LoadFromFile(string);

void Replace(string &, char, char);

void main()
{
	int choose;

	while (true)
	{
		PrintMenu();
		cout << "Choose: ";
		cin >> choose;

		fflush(stdin);

		Process(choose);

		if (choose == 0) {
			break;
		}
	}
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


void Input()
{
	Student *pStudent = &student[length++];

	cout << "Id: ";
	cin >> pStudent->id;

	cin.ignore();

	cout << "Name: ";
	getline(cin, pStudent->name);

	cout << "Score: ";
	cin >> pStudent->score;

}

void PrintList()
{
	Student *pStudent = student;
	printf("%-5s %-20s %s\n", "ID", "FULL NAME", "SCORE");
	for (int i = 0; i < length; i++)
	{
		(pStudent + i)->print();
		cout << endl;
	}
}

void Process(int choose)
{
	if (choose == 1)
	{
		Input();
	}
	else if (choose == 2)
	{
		cout << endl;
		PrintList();
		cout << endl;
	}
	else if (choose == 3)
	{
		SaveToFile("save.txt");
	}
	else if (choose == 4)
	{
		LoadFromFile("save.txt");
		PrintList();
	}

}

void SaveToFile(string fileName)
{
	ofstream outFile;
	outFile.open(fileName);
	if (outFile.is_open())
	{
		//save number
		outFile << length << endl;
		Student *pStudent = student;
		for (int i = 0; i < length; i++)
		{
			
			string name(pStudent->name);
			Replace(name, ' ', '_');


			outFile << pStudent->id << " " << name << " " << pStudent->score << endl;
		}

		cout << "Save to " << fileName << endl;

		outFile.close();
	}
	else
	{
		cout << "ERROR" << endl;
	}
}

void LoadFromFile(string fileName)
{
	ifstream inFile;
	inFile.open(fileName);
	student = new Student[MAX];
	if (inFile.is_open())
	{

		inFile >> length;

		for (int i = 0; i < length; i++)
		{
			Student *pStudent = &student[i];
			inFile >> (pStudent)->id;

			string name;
			inFile >> name;
			Replace(name, '_', ' ');
			(pStudent)->name = name;

			inFile >> (pStudent)->score;
		}

		inFile.close();
	}
	else
	{
		cout << "LOAD ERROR" << endl;
	}
}

void Replace(string &str, char to, char by)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == to)
		{
			str.at(i) = by;
		}
	}
}
