#include<iostream>
using namespace std;

int LeapYear(int year)  // ������� � 5
{
	cout << "������� �5\n";
	for (int i =0; i<1 ; i++)   // ����� ��� ����������� ��������� ���� ��������� ���. ��� ����� 1 ����� �������� �� ����� �������� ������� ����.
	{
		label2:
		cout << " ������ ���, ������� ������ ��������� (�� 0 �� 3000)\n";
		cin >> year;
		if (year < 0 || year > 3000)
			goto label2;
		if (((year % 4) == 0 && (year%100) != 0) || (year%400) == 0)
		{
			cout << "\n ��������� ���� ��� �������� ���������� \n\n";
		}
		else
		{
			cout << "\n ��������� ���� ��� �� �������� ���������� \n\n";
		}

		
	}
	return 0;
}

int IsSimple(int bravo) // ������� � 4
{
	cout << "������� �4\n";
	cout << "������� �����\n";
label1:
	for (int i =0 ; i < 1 ; i++ )    // ����� ��� ����������� ��������� ����� ��������� ���. ��� ����� 1 ����� �������� �� ���������� �������� ������� �����.
	{
		cin >> bravo;
		cout << "\n\n";
		int compare = 0;
		bool compare2 = false;
		if (bravo == 2)
			compare2 = false;
		if (bravo <= 1)
		{
			cout << "����� �� ���������� �������� ���������� ������ � �������������� 2 \n���������� ���-�� �������\n�������� ����� ������� �������\n������ ����� ������� �� ��������\n\n";
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
					cout << "������ ����� ��� �������: \t" << i << "\n";
					break;
				}

			}
		}


		if (compare2 == true)
			cout << "����� �� �������� �������\n\n";
		else
			cout << "����� �������\n\n";
	}
	return 0;
}

int Sum(int a, int b) // ������� �1
{
	cout << "������� �1\n";
	cout << "������� ������ �����\n";
	cin >> a;
	cout << "\n������� ������ �����\n";
	cin >> b;
	cout << "����� ��������� � �������� �� 10 �� 20 ������������ (true/false)?: ";
	if (((a + b) >= 10) && (a + b) <= 20)
		cout << "true\n";
	else
		cout << "false\n";
	cout << "\n";
	return 0;
}

void SecondTask(int a, int b) //������� �2
{
	cout << "������� �2\n ����������� � ������������ ����� a � b ��������� � ������� main()\n� ������ ������ ��� ����� " << a << " � " << b << "\n";
	if ((a == 10) && (b == 10) || (a + b) == 10)
		cout << "������� ������� �2 ����� TRUE\n\n";
	else
	{
		cout << "������� ������� �2 ����� FALSE\n\n";
	}
}

void OddOut(int a) // ������� �3
{
	cout << "������� �3\n";
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
	Sum(alpha, beta); // ������� � 1
	SecondTask(a, b); // ������� � 2
	OddOut(alpha); // ������� �3
	IsSimple(alpha); // ������� � 4
	LeapYear(beta); // ������� � 5
	return 0;
}