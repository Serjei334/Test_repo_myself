#include<iostream>
#include<typeinfo>
using namespace std;

//  1-� ����� 2�� �������
enum GmSymbols {Cross, Zero, Empt}; //  ������������ 0, 1, 2 - ��������������.

//  4-� �������
struct GameData // ��������� � �������� �������.
{
	int nFirstPlayerID = 0;      // ID ������ 1
	string sFirestPlayerName;  // ��� ������ 1.
	int nSecondPlayerID = 0;       // ID ������ 2
	string sSecondPlayerName; // ��� ����� 2.
	int nScore = 0 ;  //���� �� ��������� ���, ���� ����� �� �����������.
	int TurnCount =0 ; // ���������� ����� � ����� ����. ���� ����� �� �����������.
};


// 1-� ����� 5-�� �������.
struct MyVariant
{
	union MyUnion
	{
		int ThisInt;
		float ThisFloat;
		char ThisChar;
	};
	MyUnion Beta;
	unsigned int isInt : 1 ;
	unsigned int isFloat : 1;
	unsigned int isChar : 1;
};



int main()
{
	setlocale(LC_ALL, "ru"); //

	// 1-�. �������� � ������������� ���������� ���������� �����.

	short int nA = 0;
	int nB = 0;
	long long llC = 0;
	char sD = 'X';
	bool bE = true;
	float fF = 1.15f;
	double dG = 51.1;
	string sType;
	
	// 2-� ����� 2�� �������
	
	GmSymbols sXO[3] = { Zero, Empt, Cross }; //������������� ������� � �������������. �������� ������� ���������. 1, 2, 0 ��� ������ - ��������������.
	

	// 2-� ����� 5-�� �������.
	
	MyVariant VarType;

	
	VarType.Beta.ThisInt = 20;				// ���������� �������� �����
	VarType.Beta.ThisChar = 'Y';
	VarType.Beta.ThisFloat = 15.15f;
	
	
	
	VarType.Beta.ThisInt = 20;
	VarType.isChar = 0;
	VarType.isFloat = 0;
	VarType.isInt = 1;

	sType = typeid(VarType.Beta.ThisInt).name();
	cout << "Now is " << sType << "\t" << VarType.Beta.ThisInt << "\n\n";
	
	VarType.Beta.ThisChar = 'Y';
	VarType.isChar = 1;
	VarType.isFloat = 0;
	VarType.isInt = 0;

	sType = typeid(VarType.Beta.ThisChar).name();
	cout << "Now is " << sType << "\t" << VarType.Beta.ThisChar << "\n\n";
	
	VarType.Beta.ThisFloat = 15.15f;
	VarType.isChar = 0;
	VarType.isFloat = 1;
	VarType.isInt = 0;
	
	sType = typeid(VarType.Beta.ThisFloat).name();
	cout << "Now is " << sType << "\t" << VarType.Beta.ThisFloat << "\n\n";


																		// ������� ������� ������������� GameData
	
	/*
	GameData p1, p2;												
	p1.nFirstPlayerID = rand()%1000;
	p1.sFirestPlayerName = "Charlie";
	cout << "Enter first player name\t\t";
	cin >> p1.sFirestPlayerName;
	cout << "\n" << "Enter second player name\t";
	p2.nSecondPlayerID = rand() % 1000;
	p2.sSecondPlayerName = "Tango";
	cin >> p2.sSecondPlayerName;
	cout << "\nPlayers\t\t" << "ID" << "\tName" << "\n";
	cout << "\n" << "First Player:\t" << p1.nFirstPlayerID << "\t" << p1.sFirestPlayerName << "\n";
	cout << "Second Player:\t" << p2.nSecondPlayerID << "\t" << p2.sSecondPlayerName << "\n";
	*/

	return 0;
}