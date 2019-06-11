#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

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

void SaveToFile(string fileName, ListStudent ls); //save all student to file

void LoadFromFile(string fileName);

void Replace(string &str);

ListStudent ls;

int main() {
	cout << "Input student numbers: ";
	cin >> ls.n;
	ls.arr = new Student[ls.n];

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
	system("pause");
	return 0;
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
	
	cin.ignore();
	 
	cout << "full name: ";
	getline(cin, student.name);

	cout << "score: ";
	cin >> student.score;
	s = student;
}

void OutputStudent(Student &s)
{
	cout << s.id << "      " << s.name << "          " << s.score;
}

void InputListStudent(ListStudent &ls)
{
	for (int i = 0; i < ls.n; i++)
	{
		cout << "/nInput student " << i + 1 << endl;
		InputStudent(ls.arr[i]);
	}
}

void OutputListStudent(ListStudent ls)
{
	for (int i = 0; i < ls.n; i++)
	{
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
		InputListStudent(ls);
		
	}
	if (choose == 2)
	{
		cout << endl;
		PrintList();
		OutputListStudent(ls);
		cout << endl;
	}
	else if (choose == 3)
	{
//		SaveToFile("saveFile.txt");
	}
	else if (choose == 4)
	{
//		LoadFromFile("loadFile.txt");
		PrintList();
	}
	else if (choose < 1 || choose > 4)
	{
		cout << "Your choose wrong!";
	}
}
/*
void SaveToFile(string fileName, ListStudent ls)
{
	FILE *f = fopen(fileName.c_str(), "w");
	if (f != nullptr)
	{
		//save number
		fprintf(f, "%d", ls.n);
		for (int i = 0; i < ls.n; i++)
		{
			Person p = g_PersonList.at(i);

			string name(p.name);
			string address(p.address);
			Replace(name, ' ', '_');
			Replace(address, ' ', '_');

			fprintf(f, "\n%s %d %s", name.c_str(), p.age, address.c_str());
		}

		cout << "Save to " << fileName << endl;

		fclose(f);
	}
	else
	{
		cout << "ERROR" << endl;
	}
}
*/


