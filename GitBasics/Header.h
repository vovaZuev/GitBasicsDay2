#pragma once
#include<iostream>
using namespace std;

const int ROWS = 8;	//ROW - ������
const int COLS = 7; //COLUMN - �������

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