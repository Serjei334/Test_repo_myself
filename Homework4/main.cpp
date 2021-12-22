#include<iostream>
using namespace std;

int LeapYear(int year)  // Задание № 5
{
	cout << "Задание №5\n";
	for (int i =0; i<1 ; i++)   // Нужно для возможности проверить дату несколько раз. Для этого 1 нужно поменять на число повторов запроса даты.
	{
		label2:
		cout << " Введит год, который хотите проверить (от 0 до 3000)\n";
		cin >> year;
		if (year < 0 || year > 3000)
			goto label2;
		if (((year % 4) == 0 && (year%100) != 0) || (year%400) == 0)
		{
			cout << "\n Введенный вами год является високосным \n\n";
		}
		else
		{
			cout << "\n Введенный вами год НЕ является високосным \n\n";
		}

		
	}
	return 0;
}

int IsSimple(int bravo) // Задание № 4
{
	cout << "Задание №4\n";
	cout << "введите число\n";
label1:
	for (int i =0 ; i < 1 ; i++ )    // Нужно для возможности проверить число несколько раз. Для этого 1 нужно поменять на количество повторов запроса числа.
	{
		cin >> bravo;
		cout << "\n\n";
		int compare = 0;
		bool compare2 = false;
		if (bravo == 2)
			compare2 = false;
		if (bravo <= 1)
		{
			cout << "Числа не являющиеся простыми появляются только с положительного 2 \nПопробуйте что-то большее\nВыберите число большее единицы\nДанное число простым не является\n\n";
			goto label1;
		}
		else
		{

			for (int i = 2; i < bravo; i++)
			{
				compare = bravo % i;
				if (compare == 0)
				{
					compare2 = true;
					cout << "Первое число для деления: \t" << i << "\n";
					break;
				}

			}
		}


		if (compare2 == true)
			cout << "число не является простым\n\n";
		else
			cout << "число простое\n\n";
	}
	return 0;
}

int Sum(int a, int b) // Задание №1
{
	cout << "Задание №1\n";
	cout << "Введите первое число\n";
	cin >> a;
	cout << "\nВведите второе число\n";
	cin >> b;
	cout << "Число находится в пределах от 10 до 20 включительно (true/false)?: ";
	if (((a + b) >= 10) && (a + b) <= 20)
		cout << "true\n";
	else
		cout << "false\n";
	cout << "\n";
	return 0;
}

void SecondTask(int a, int b) //Задание №2
{
	cout << "Задание №2\n Суммируемые и сравниваемые числа a и b находятся в функции main()\nВ данный момент это числа " << a << " и " << b << "\n";
	if ((a == 10) && (b == 10) || (a + b) == 10)
		cout << "Функция задания №2 выдаёт TRUE\n\n";
	else
	{
		cout << "Функция задания №2 выдаёт FALSE\n\n";
	}
}

void OddOut(int a) // Задание №3
{
	cout << "Задание №3\n";
	int i = 0;
	while (i <= 50)
	{
		if ((i % 2) == 0)
		{
		
		}
		else
		{
			cout << i << " ";
		
		}
		++i;
	} 
	cout << "\n\n";
}

int main()
{
	setlocale(LC_ALL, "ru");
	const int a = 10;
	const int b = 10;
	int alpha = 0;
	int beta = 0;
	Sum(alpha, beta); // Задание № 1
	SecondTask(a, b); // Задание № 2
	OddOut(alpha); // Задание №3
	IsSimple(alpha); // Задание № 4
	LeapYear(beta); // Задание № 5
	return 0;
}