#pragma once
#include <iostream>
#include <cstring>
#include <fstream>

#include <chrono> 

#include "SortAlgorithm.h"
#include "Generator.h"


//Functions
void copyArray(int* a, int* b, int n);
void inputArrayWithFile(int*& a, int& n, string file);
void printArray(int* a, int n);
bool checkOrder(int a[], int n);
void chooseSort(char* algorithm, int mode, int* a, int n, long long& count, double& time);
int chooseMode(char* mode);
bool chooseGenerator(char* mode, int* a, int n);
void printFile(int* a, int n, string file);

//Commands output
void command1Output(char* algorithm, int mode, char* file, int size, double runtime, long long comparision);
void command2Output(char* algorithm, int mode, char* order, int size, double runtime, long long comparision);
void command3Output(char* algorithm, int mode, int size, double runtime1, long long comparision1, double runtime2, long long comparision2, double runtime3, long long comparision3, double runtime4, long long comparision4);
void command4Output(char* algorithm1, char* algorithm2, int mode, char* file, int size, double runtime1, long long comparision1, double runtime2, long long comparision2);
void command5Output(char* algorithm1, char* algorithm2, int mode, char* order, int size, double runtime1, long long comparision1, double runtime2, long long comparision2);

