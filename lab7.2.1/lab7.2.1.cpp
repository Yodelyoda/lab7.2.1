#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int k, const int Low, const int High);
void Print(int** a, const int n, const int k);
void Change(int** a, const int n, const int k, int& min, int& max);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n,k;
	cout << "n = "; cin >> n;//rowCount
	cout << "k = "; cin >> k;//colCount
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];
	Create(a, n,k, Low, High);
	Print(a, n,k);
	int min;
	int max;
	Change(a, n,k, min,max);
	Print(a, n,k);
		for (int i = 0; i < n; i++)
			delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int n, const int k, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n,const int k)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void Change(int** a, const int n, const int k, int& min, int& max)
{
	max = a[0][0];
	min = a[0][0];
	
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < k; j++)
		{
			if (j % 2 != 0)
			{
				if (max < a[i][j]) max = a[i][j];
				if (min > a[i][j]) min = a[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (j % 2 != 0)
			{
				if (a[i][j] == min) a[i][j] = max;
				else if (a[i][j] == max) a[i][j] = min;
			}
		}
	}
}

