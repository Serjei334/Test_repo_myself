#include<iostream>
using namespace std;


void task4(int* arr, int size, int displasement) //		������� 4
{
	
	int buf1 = 0;
	int k = 0;
	if (displasement < (-1 * size))																	//������ �� ������� ������ �����. ������� ��������, ����� ������� �� ����� ���������� ����� � ��������, ���� ����� ���� size*(-1), ����� ���� �������� ������ ����� ��������. 
		displasement = displasement + (- 1)* size* (static_cast<int> (displasement / size));		// ������ �����, ��� �������� �������� ����� ���� ������ ���������� � �� �������� ��, ��� �������� ����. �������� �� ��� ���� ���������� ��� ��������, ������� ������� ��� � �� ����.
	////////////////////////////
	while (k != (displasement+size)) // ������, ��� ��� ������ �������� � ��� �������, ���� ������������� ������ ��� ������������� ��������.
	{								 // ����������� �� size+n, � �.�. n ������������, �� ������ �������� ������ �����, ���� �������� ������ ������.
		buf1 = arr[size-1];
		for (int i = (size - 1); i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = buf1;
		k++;
	}
	///////////////////////////
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	
	
}
void ArrayRestore(int* arr, int size)
{
	for (int i = 0; i < size; i++)								// ����� ��� �������������� ��������� �������� �������. ��� ����� ��������� �����������������.
	{
		arr[i] = i + 1;
	}
}

void task5(int *arr, int size) //������� 5
{
	int sum1{ 0 }, sum2{ 0 };
	
	for (int i = 0; i < size; i++)				// ������ ������� ������ �� ����� ��� �������� ��������� � ������ ��������.
	{
		cout << arr[i] << "\t";
	}
	cout << "\n";

	for (int i = 0; i < size; i++)				//�������� ��� ��������� �� ����������, �� ���� ��������.
	{
		sum1 = sum1 + arr[i];					//���������� ����� �������� �������
		cout << "Sum1: " << sum1 << "\n";
		for (int j = (i + 1); j < (size); j++)  //����������� �������� ������� ������ �������� i
		{
			sum2 = sum2 + arr[j];				// ���������� ������ �������� �������
			
		}
		cout << "Sum2: " << sum2 << "\n";		// ������� ����� ��������� ������� ������ i
		
		if (sum1 == sum2)						// ������� ����� ��������� ����� i ������������ � �������� ������ i, ��� ����� i ��������
		{
			cout << "Balance Point found at : " << i+1 << "\n"; //������� i+1 (+1 ��� �������� ���������) ���� ����� ����� � ��������� ����.
			for (int k = 0; k < size; k++)		// ������� ������ �� �����
			{
				if (k == (i+1)){
					cout << " ! \t";			// ������ ��������������� ���� � ����� �������.
				}
				cout << arr[k] << "\t";			// ������� ����� ����� �������
			}
			cout << "\n";
			break;								// ��������� ����, �.�. ����� ������� ������� � ���������� ������������ ���� �� ����� ������
		}
		else
		{
			cout  << "There no balance point" << " at " << i + 1 << "\n"; // ������� i+1 � ��������, ��� � ���� ����� ������ �� ������.
			sum2 = 0;							// �������� ������ �����, ����� � ������� ���������� ��� � ���������.
		}
	}
}

void task1(double * arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << "\t";
	cout << "\n\n";
}

void task2(int* arr, int size)
{
	


	for (int i = 0; i < size; i++)
		cout << arr[i] << "\t";
	cout << endl;

	for (int i = 0; i < size; i++)
	{
	if (arr[i] == 0)
		arr[i] = 1;
	else
		arr[i] = 0;
	}
	for (int i = 0; i < size; i++)
		cout << arr[i] << "\t";
	cout << "\n\n";
}

void task3(int* arr, int size)
{
	arr[0] = 1;
	for (int i = 1; i < size; i++)
		arr[i] = arr[i - 1] + 3;

	for (int i = 0; i < size; i++)
		cout << arr[i] << "\t";
	cout << "\n\n";

}
int main()
{
	const int size = 15;
	const int size2 = 7;
	const int size3 = 10;
	int arr[size] = {0};
	int arr2[size2] = {18,2,1,6,8,3,2};
	int arr4[size2] = {0,1,1,1,0,1,0};
	int arr5[size3] = { 0 };
	double arr3[size2] = { 1.345,2.4654,3.44545,8.223,5.22234,9.1198,6.22554 };
	int k = 0;

	task1(arr3, size2); // ������� �1
	task2(arr4,size2); //������� �2
	task3(arr5, size3); //������� �3
	task5(arr2, size2);//������� �5


	//===============================================								������� �4
	
		ArrayRestore(arr, size);
		cout << "\n\n";
		
		//label1:
			cout << "\n\nEnter displacement parameter: ";
			cin >> k;
			cout << "\n";
			task4(arr, size, k); //������� �4
			//ArrayRestore(arr, size);						// ����� ��� �������� �������� ������� �� ���� �����, �� ���� ������ �������������� ������.
		//goto label1;										// ��� �������� �������� �����������������, ����� �������, ��� � label1 �� ������ 143.

	

}