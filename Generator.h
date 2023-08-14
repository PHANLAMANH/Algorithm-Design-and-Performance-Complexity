#pragma once
#include <iostream>
using namespace std;


#define DATATYPE0 10000
#define DATATYPE1 30000
#define DATATYPE2 50000
#define DATATYPE3 100000
#define DATATYPE4 300000
#define DATATYPE5 500000

//Data Generate
template <class T>
void HoanVi(T& a, T& b);
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);