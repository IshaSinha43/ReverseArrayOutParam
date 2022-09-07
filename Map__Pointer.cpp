#include <iostream>	  
#include <Windows.h>  
#include <map>		  

using namespace std;

typedef struct Student
{
	char name[256];
	char address[256];

}Student;

class MapClass
{
public:
	map<int, Student*> students;
	int roll=0;

	MapClass()
	{
		map<int, Student*> students;
	}

	~MapClass()
	{
		/* if (students.size() > 0) {
			for (map<int, Student*>::iterator it = students.begin(); it != students.end(); ++it)
			{
				delete it->second;
			}
			students.clear();		 
		}*/
	
	for (map<int, Student*>::iterator it = students.begin(); it != students.end(); ++it)
		{
			if ((*it).second)
			{
				delete ((*it).second);
				((*it).second) = NULL;
			}
		}

		students.clear(); //This will release all objects the map has allocated internally
	};
	void AddStudent()
	{
		for (auto cntr = 0; cntr < 10; cntr++)
		{
			//Student* objStudents;
			cout << "Enter student's Roll number, Name and Address: ";
			cin >> roll;
			Student* objStudents = new Student();
			objStudents->name;
			cin >> (*objStudents).name;
			objStudents->address;
			cin >> (*objStudents).address;
			students.insert(pair <int, Student*>(roll, objStudents));
		}
		cout << "size of Map: " << students.size() << endl;
	}
	void Display()
	{
		map<int, Student*>::iterator it;
		cout << "ROLL" << '\t' << "NAME" << '\t' << "ADDRESS" << endl;
		for (it = students.begin(); it != students.end(); ++it)
		{
			cout << it->first << '\t' << (*it).second->name << '\t' << (*it).second->address << endl;
		}
	}
};

int main()
{
	MapClass map;
	map.AddStudent();
	map.Display();
	system("pause");
	return 0;
}