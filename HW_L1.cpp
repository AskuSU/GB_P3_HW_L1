#include<iosfwd>
#include<windows.h>
#include<memory>
#include<ctime>
#include"MyLib.h"
//#include"Task1.h"
//#include"Task2.h"
//#include"Task3.h"

using namespace std;
using namespace myLib;

void Task1()
{
	cout << "Работа с Функцией div:" << endl << endl;
	
}

void Task2()
{
	cout << "Работа с классом Bar:" << endl << endl;
	
}

void Task3()
{
	

}


int main()
{
	setlocale(LC_ALL, "RU");
	//srand(time(0));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	unsigned short taskNumber = 0;
	while (true)
	{
		taskNumber = getUserSelectedTask(3);
		switch (taskNumber)
		{
		case 1: Task1();
			break;
		case 2: Task2();
			break;
		case 3: Task3();
			break;
		}
		cout << endl;
	}
}