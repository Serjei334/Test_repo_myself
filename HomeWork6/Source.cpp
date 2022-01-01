#include<iostream>
#include<ctime>
#include<fstream>
#include<math.h>
#include<string>
using namespace std;

void task1(int *arr, size_t size)
{
    cout << "TASK 1.\n";
    for (int i = 0; i < size; i++)
    {
        arr[i] =static_cast<int>(pow(2, i));
        cout << arr[i] << " ";                      // ¬ Ubuntu такой вывод после 7-го числа выдавал неверные значени€. «десь, вроде, работает нормально.
    }
    delete[] arr;
    arr = nullptr;
}
void task2(int** arr, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = (rand() % 89) + 10;
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

}
void task2Creation(int** arr, size_t size)
{
    cout << "\nTASK 2\n";
    for (int i = 0; i < size; i++)
    {
        arr[i] = new int[size];
    }
}
void task2Fill(int** arr, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = (rand() % 89) + 10;
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
void task2Destroy(int** arr, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        delete arr[i];
    }
}
void task3(string* name1, string* name2)
{
    cout << "\nTASK 3.\nName your first file: ";
    cin >> *name1;
    *name1 += ".txt";
    cout << "\nName your second file: ";
    cin >> *name2;
    *name2 += ".txt";

    char randLetr;
    ofstream fout2;
    fout2.open(*name1);
    if (fout2.is_open())
        cout << "File " << *name1 << " was created and filled with 50 random letters\n";
    for (int i = 0; i < 60; i++) {
        randLetr = (rand() % 25) + 65;
        fout2 << randLetr;
    }
    fout2.close();
    fout2.open(*name2);
    if (fout2.is_open())
        cout << "File " << *name2 << " was created and filled with 50 random letters\n";
    for (int i = 0; i < 60; i++) {
        randLetr = (rand() % 25) + 65;
        fout2 << randLetr;
    }
    fout2.close();
}
void task4(string* name1, string* name2, string* name3, string* buffer)
{
    cout << "\nTASK 4\n\n";

    ifstream fin(*name1);
    if (fin.is_open())
    {
        const size_t size = 255;
        char buf[size];
        while (!fin.eof())
        {
            fin.getline(buf, size);
            *buffer += buf;
        }

        fin.close();
    }

    ifstream fin2(*name2);
    if (fin2.is_open())
    {
        const size_t size = 255;
        char buf[size];
        while (!fin2.eof())
        {
            fin2.getline(buf, size);
            *buffer += buf;
        }


    }
    fin2.close();

    cout << "Enter third file name\n";
    cin >> *name3;
    *name3 += ".txt";
    ofstream fout;
    fout.open(*name3);
    if (fout.is_open())
    {
        fout << *buffer << endl;
        cout << "File " << *name3 << " was created and filled with " << *name1 << " and " << *name2 << " data\n";
    }
    fout.close();
}
void task5(string*ptrPath, string*ptrBuff)
{
    cout << "\nEnter path to your file\n EXAMPLE for Ubuntu: //home//ser//projects//helloworld//Grib.txt\nEXAMPLE for Windows: C:\\Users\\Serjei\\Downloads\\code.txt\n";

    cin >> *ptrPath;
    ifstream fin3(*ptrPath);
    if (fin3.is_open())
    {
        const size_t size = 255;
        char buf[size];
        while (!fin3.eof())
        {
            fin3.getline(buf, size);
            *ptrBuff += buf;
        }

        cout << *ptrBuff << "\n";
        cout << "Enter word you want to find: ";
        cin >> *ptrPath;
        fin3.close();
    }
    else
    {
        cout << "Failed to open file! " << *ptrPath << "\n";
        fin3.close();
        goto label1;
    }

    if ((*ptrBuff).find(*ptrPath) != string::npos)
    {
        cout << "\n Word was found\n";
    }
    else
    {
        cout << "\n Word was'nt found\n";
    }
    //================================
label1:;
}
int main()
{
    srand(time(0));
    //=================         TASK 1
    size_t size1 = 0;
    cout << "Please enter array size: ";
    cin >> size1;
    int* pArr = new int [size1];
    task1(pArr, size1);
 
    //=================         TASK 2
    size1 = 4;                      // повторное использование size1 т.к. она больше не нужна дл€ первого задани€.
    int** pArr2 = new int*[size1];
    task2Creation(pArr2, size1);
    task2Fill(pArr2, size1);
    task2Destroy(pArr2, size1);
    delete[] pArr2;
    pArr2 = nullptr;

    //=================         TASK 3
    const size_t NameNum = 4;
    string name[NameNum];
    string* ptrName[NameNum];
    for (int i = 0; i < NameNum; i++){ //—перва создал все имена отдельно, но потом это зан€ло слишком много места, т.к. и дл€ 4-го они тоже нужны. ћассивы дл€ экономии места визуально.
        ptrName[i] = &name[i];
    }
    task3(ptrName[0],ptrName[1]);

    //=================         TASK 4

    task4(ptrName[0], ptrName[1], ptrName[2], ptrName[3]);
    
    //=================         TASK 5

    string path;
    string buffer2;
    string* ptrPath = &path;
    string* ptrBuff = &buffer2;
    
    task5(ptrPath, ptrBuff);
    
    return 0;
}