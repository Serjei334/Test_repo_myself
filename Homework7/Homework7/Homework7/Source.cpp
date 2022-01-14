#include<iostream>
#include<math.h>
#include<string>
#include<fstream>
#include"Task1.h"

#define Task2(a,b) ((a >= 0) && (a < b) ? std::cout << "true" : std::cout << "false")
#define T3SIZE 4
#define SwapInt(a,b,c) ((c = a), (a = b), (b = c))
using namespace std;

struct EmployeeTest // —труктура дл€ сравнени€ размера в 4-м. ”далить перед отправкой.
{
	long int ID = 0;
	int age = 0;
	string Name = " -- ";
	int salary = 0;

};


#pragma pack (push,1)
struct Employee
{
	long int ID = 0;
	int age = 0;
	string Name = " -- ";
	int salary = 0;

};
#pragma pack (pop)




int main() {
	
	const int size = 10;
	float arr1[size];
	int arr[T3SIZE];
	int tsk2[2];

	//=============================================================================== TASK 1 && 5
	cout  << "\nTask 1:\n";
		T1::ArrayInit(arr1, size);
		T1::ArrayPrint(arr1, size);
		T1::ArrayResults(arr1, size);
	

	// ================================================================================== TASK 2

		cout << "\n" << "\nTask 2:";
	cout << "\n" << "\nEnter first number ";
	cin >> tsk2[0]; 
	cout << "\n" << "\nEnter second number ";
	cin >> tsk2[1];

	if ((tsk2[0] < 0) && (tsk2[1] < 0)) { // ≈сли оба числа отрицательны, то так-же можно проверить находитс€ ли первое число в промежутке между 0 и вторым, дл€ этого возьмем их модули.
		tsk2[0] = fabs(tsk2[0]);
		tsk2[1] = fabs(tsk2[1]);
	}

	cout << "\n";
	Task2(tsk2[0], tsk2[1]);
	cout << "\n\n";

	//====================================================================================== TASK 3
	cout << "\n" << "\nTask 3:\n";
	for (int i = 0; i < T3SIZE; i++) {
		cout << "Enter value for element: " << (i+1) << "  ";
		cin >> arr[i];
		cout << endl;
	}
	cout << "|| ";
	for (int i = 0; i < T3SIZE; i++) {
		cout << arr[i] << " || ";
	}
	cout << "\n";

	// Sorting
	int temp = 0;
	for (int i = 0; i < T3SIZE - 1; i++) {
		for (int j = 0; j < T3SIZE - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				SwapInt(arr[j], arr[j + 1], temp);
			}
		}
	}
	// Out
	cout << "|| ";
	for (int i = 0; i < T3SIZE; i++) {
		cout << arr[i] << " || ";
	}
	cout << "\n" << "\nTask 4:";

	// =========================================================================================== TASK 4
	
	Employee* staff = new Employee;
	staff->Name = "Johnny Silverhand";
	staff->ID = 10001;
	staff->age = 34;
	staff->salary = 1200;

	cout << "Size of 1 struct element now: " << sizeof(Employee) << "\n";  //имет тот-же размер, что и каждый отдельный элемент массива.
	cout << "Size of 1 struct element before <<Pragma pack>>: " << sizeof(EmployeeTest) << "\n\n";

	cout << "ID: " << staff->ID << "\n" << "Name: " << staff->Name << "\n" << "Age: " << staff->age << "\n" << "Salary: " << staff->salary << "\n\n";

	ofstream fout("hw7.txt");
	if (!fout.is_open()){
	}
	else
	{
	fout << staff->ID << "\n" << staff->Name << "\n" << staff->age << "\n" << staff->salary << "\n";
	
		fout.close();
		delete staff;
	}
	return 0;
}