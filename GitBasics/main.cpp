#include<iostream>
using namespace std;

const int ROWS = 8;	//ROW - строка
const int COLS = 7; //COLUMN - столбец

void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(int arr[ROWS][COLS], const int m, const int n);

template <typename T>
void Print(T arr[], const int n);
template <typename T>
void Print(T arr[ROWS][COLS], const int m, const int n);

template <typename T>
void Sort(T arr[], const int n);
template <typename T>
void Sort(T arr[ROWS][COLS], const int m, const int n);

template <typename T>
T Sum(T arr[], const int n);
template <typename T>
T Sum(T arr[ROWS][COLS], const int m, const int n);

template <typename T>
double Avg(T arr[], const int n);
template <typename T>
double Avg(T arr[ROWS][COLS], const int m, const int n);

#define delimiter "\n---------------------------------------------------\n"
#define DEBUG
void main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 13;
	int i_arr[n];
	FillRand(i_arr, n);
	Print(i_arr, n);
	Sort(i_arr, n);
	Print(i_arr, n);
	cout << "Сумма элементов массива: " << Sum(i_arr, n) << endl;
	cout << "Среднее арифметическое: " << Avg(i_arr, n) << endl;
	cout << delimiter << endl;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	double d_arr[n];
	FillRand(d_arr, n);
	Print(d_arr, n);
	Sort(d_arr, n);
	Print(d_arr, n);
	cout << "Сумма элементов массива: " << Sum(d_arr, n) << endl;
	cout << "Среднее арифметическое: " << Avg(d_arr, n) << endl;
	cout << delimiter << endl;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/*const int m = 8;
	int crr[m];
	FillRand(crr,m);
	Print(crr, m);
	Sort(crr, m);
	Print(crr, m);*/


	int i_arr2[ROWS][COLS];
	FillRand(i_arr2, ROWS, COLS);
	Print(i_arr2, ROWS, COLS);
	cout << "Сумма элементов массива: " << Sum(i_arr2, ROWS, COLS) << endl;
	cout << "Среднее арифметическое: " << Avg(i_arr2, ROWS, COLS) << endl;
	cout << "Отсортированный массив: " << endl;
	Sort(i_arr2, ROWS, COLS);
	Print(i_arr2, ROWS, COLS);
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		arr[i] /= 10;
	}
}
void FillRand(int arr[ROWS][COLS], const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

template <typename T>
void Print(T arr[], const int n)
{
	//Вывод массива на экран:
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

template <typename T>
void Print(T arr[ROWS][COLS], const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

template <typename T>
void Sort(T arr[], const int n)
{
	//Сортировка:
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				double buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}
template <typename T>
void Sort(T arr[ROWS][COLS], const int m, const int n)
{
#ifdef DEBUG
	int iterations = 0;
	int exchanges = 0;
#endif // DEBUG

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = i; k < m; k++)
			{
				/*for (;;)
				{

				}*/

				int l;
				if (k == i)l = j + 1;
				else l = 0;

				//			condition ? value1 : value2;
				for (/*int l = (k == i) ? j + 1 : 0*/; l < n; l++)
				{
#ifdef DEBUG
					iterations++;
#endif // DEBUG
					if (/*ПЕРЕБИРАЕМЫЙ ЭЛЕМЕН*/arr[k][l] < arr[i][j]/*ВЫБРАННЫЙ ЭЛЕМЕН*/)
					{
						int buffer = arr[i][j];
						arr[i][j] = arr[k][l];
						arr[k][l] = buffer;
#ifdef DEBUG
						exchanges++;
#endif // DEBUG
					}
				}
			}
		}
	}
#ifdef DEBUG
	cout << "Массив отсортирован за " << iterations << " итераций\n";
	cout << "При этом, было выполнено " << exchanges << " обменов элементов\n";
#endif // DEBUG
}

template <typename T>
T Sum(T arr[], const int n)
{
	T Sum = 0;
	for (int i = 0; i < n; i++)
	{
		Sum += arr[i];
	}
	return Sum;
}

template <typename T>
T Sum(T arr[ROWS][COLS], const int m, const int n)
{
	T sum = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}

template <typename T>
double Avg(T arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
template <typename T>
double Avg(T arr[ROWS][COLS], const int m, const int n)
{
	return (double)Sum(arr, m, n) / (m * n);
}