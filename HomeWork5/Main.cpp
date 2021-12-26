#include<iostream>
using namespace std;


void task4(int* arr, int size, int displasement) //		ЗАДАНИЕ 4
{
	
	int buf1 = 0;
	int k = 0;
	if (displasement < (-1 * size))																	//Защита от слишком низких чисел. Нашлась проблема, когда функция не могла произвести сдвиг и зависала, если число ниже size*(-1), после чего пришлось ввести такую проверку. 
		displasement = displasement + (- 1)* size* (static_cast<int> (displasement / size));		// Сейчас понял, что подобную проверку можно было ввести изначально и не городить то, что написано ниже. Несмотря на это ниже написанный код работает, поэтому трогать его я не буду.
	////////////////////////////
	while (k != (displasement+size)) // Похоже, что это теперь работает в обе стороны, хотя планировалось только для отрицательных значений.
	{								 // Проматывает на size+n, а т.к. n отрицательна, то создаёт имитацию сдвига влево, хотя сдвигает только вправо.
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
	for (int i = 0; i < size; i++)								// Нужно для восстановления начальных значений массива. Так легче проверять работоспособность.
	{
		arr[i] = i + 1;
	}
}

void task5(int *arr, int size) //Задание 5
{
	int sum1{ 0 }, sum2{ 0 };
	
	for (int i = 0; i < size; i++)				// просто выводим массив на экран для удобства просмотра и ручной проверки.
	{
		cout << arr[i] << "\t";
	}
	cout << "\n";

	for (int i = 0; i < size; i++)				//Работает как алкоголик на анаболиках, но пока работает.
	{
		sum1 = sum1 + arr[i];					//Складываем левые элементы массива
		cout << "Sum1: " << sum1 << "\n";
		for (int j = (i + 1); j < (size); j++)  //Перечисляем элементы массива правее текущего i
		{
			sum2 = sum2 + arr[j];				// Складываем правые элементы массива
			
		}
		cout << "Sum2: " << sum2 << "\n";		// Выводим сумму элементов массива правее i
		
		if (sum1 == sum2)						// Сверяем сумму элементов левее i включительно и элементы правее i, без учёта i элемента
		{
			cout << "Balance Point found at : " << i+1 << "\n"; //Выводим i+1 (+1 для удобства понимания) если суммы равны и прерываем цикл.
			for (int k = 0; k < size; k++)		// Выводим массив на экран
			{
				if (k == (i+1)){
					cout << " ! \t";			// Ставим восклицательный знак в место баланса.
				}
				cout << arr[k] << "\t";			// Выводим номер места баланса
			}
			cout << "\n";
			break;								// Прерываем цикл, т.к. место баланса найдено и продолжать перечисление пока не имеет смысла
		}
		else
		{
			cout  << "There no balance point" << " at " << i + 1 << "\n"; // Выводим i+1 и сообщаем, что в этой точке баланс не найден.
			sum2 = 0;							// Зануляем вторую сумму, иначе к текущей прибавится еще и следующая.
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

	task1(arr3, size2); // задание №1
	task2(arr4,size2); //Задание №2
	task3(arr5, size3); //Задание №3
	task5(arr2, size2);//Задание №5


	//===============================================								ЗАДАНИЕ №4
	
		ArrayRestore(arr, size);
		cout << "\n\n";
		
		//label1:
			cout << "\n\nEnter displacement parameter: ";
			cin >> k;
			cout << "\n";
			task4(arr, size, k); //Задание №4
			//ArrayRestore(arr, size);						// Нужен для возврата значений функции на свои места, по сути просто перезаписывает массив.
		//goto label1;										// для удобства проверки работоспособности, можно удалять, как и label1 на строке 143.

	

}