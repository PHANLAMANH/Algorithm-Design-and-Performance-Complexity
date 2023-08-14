#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <chrono> 

#include "SortAlgorithm.h"
#include "Generator.h"

using namespace std;

void printArray(int* a, int n);
bool checkOrder(int a[], int n);

void copyArray(int* a, int* b, int n)
{
	for (int i = 0; i < n; ++i)
		b[i] = a[i];
}


int chooseMode(char* mode)
{
	if (strcmp(mode, "-time") == 0)
		return 0;
	else if (strcmp(mode, "-comp") == 0)
		return 1;
	else if (strcmp(mode, "-both") == 0)
		return 2;
	else return -1;
}

bool chooseGenerator(char* mode, int* a, int n)
{
	if (strcmp(mode, "-rand") == 0)
	{
		GenerateRandomData(a, n);
		return 1;
	}
		

	else if (strcmp(mode, "-nsorted") == 0)
	{
		GenerateNearlySortedData(a, n);
		return 1;
	}

	else if (strcmp(mode, "-sorted") == 0) 
	{
		GenerateSortedData(a, n);
		return 1;
	}
		

	else if (strcmp(mode, "-rev") == 0)
	{
		GenerateReverseData(a, n);
		return 1;
	}
		
	return 0;
}

void chooseSort(char* algorithm, int mode, int* a, int n, long long& count, double& time)
{
	int* b;
	b = new int[n];
	copyArray(a, b, n);

	if (strcmp(algorithm, "selection-sort") == 0)
	{
		if (mode == 0 || mode == 2)
		{
			auto start = std::chrono::high_resolution_clock::now();
			selectionSortOrigin(a, n);
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
			time = duration.count();
		}
		if (mode == 2)
			selectionSort(b, n, count);
		if (mode == 1)
			selectionSort(a, n, count);
	}
	else if (strcmp(algorithm, "insertion-sort") == 0)
	{
		if (mode == 0 || mode == 2)
		{
			auto start = std::chrono::high_resolution_clock::now();
			insertionSortOrigin(a, n);
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
			time = duration.count();
		}
		if (mode == 2)
			insertionSort(b, n, count);
		if (mode == 1)
			insertionSort(a, n, count);
	}
	else if (strcmp(algorithm, "bubble-sort") == 0)
	{
		if (mode == 0 || mode == 2)
		{
			auto start = std::chrono::high_resolution_clock::now();
			bubbleSortOrigin(a, n);
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
			time = duration.count();
		}
		if (mode == 2)
			bubbleSort(b, n, count);
		if (mode == 1)
			bubbleSort(a, n, count);
	}
	else if (strcmp(algorithm, "shaker-sort") == 0)
	{
		if (mode == 0 || mode == 2)
		{
			auto start = std::chrono::high_resolution_clock::now();
			shakerSortOrigin(a, 0, n - 1);
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
			time = duration.count();
		}
		if (mode == 2)
			shakerSort(b, 0, n - 1, count);
		if (mode == 1)
			shakerSort(a, 0, n - 1, count);
	}
	else if (strcmp(algorithm, "shell-sort") == 0)
	{
		if (mode == 0 || mode == 2)
		{
			auto start = std::chrono::high_resolution_clock::now();
			shellSortOrigin(a, n);
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
			time = duration.count();
		}
		if (mode == 2)
			shellSort(b, n, count);
		if (mode == 1)
			shellSort(a, n, count);
	}
	else if (strcmp(algorithm, "heap-sort") == 0)
	{
		if (mode == 0 || mode == 2)
		{
			auto start = std::chrono::high_resolution_clock::now();
			heapSortOrigin(a, n);
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
			time = duration.count();
		}
		if (mode == 2)
			heapSort(b, n, count);
		if (mode == 1)
			heapSort(a, n, count);
	}
	else if (strcmp(algorithm, "merge-sort") == 0)
	{
		if (mode == 0 || mode == 2)
		{
			auto start = std::chrono::high_resolution_clock::now();
			mergeSortOrigin(a, 0, n - 1);
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
			time = duration.count();
		}
		if (mode == 2)
			mergeSort(b, 0, n - 1, count);
		if (mode == 1)
			mergeSort(a, 0, n - 1, count);
	}
	else if (strcmp(algorithm, "quick-sort") == 0)
	{
		if (mode == 0 || mode == 2)
		{
			auto start = std::chrono::high_resolution_clock::now();
			quickSortOrigin(a, 0, n - 1);
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
			time = duration.count();

		}
		if (mode == 2)
			quickSort(b, 0, n - 1, count);
		if (mode == 1)
			quickSort(a, 0, n - 1, count);
	}
	else if (strcmp(algorithm, "counting-sort") == 0)
	{
		if (mode == 0 || mode == 2)
		{
			auto start = std::chrono::high_resolution_clock::now();
			countingSortOrigin(a, n);
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
			time = duration.count();
		}
		if (mode == 2)
			countingSort(b, n, count);
		if (mode == 1)
			countingSort(a, n, count);
	}
	else if (strcmp(algorithm, "radix-sort") == 0)
	{
		if (mode == 0 || mode == 2)
		{
			auto start = std::chrono::high_resolution_clock::now();
			radixSortOrigin(a, n);
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
			time = duration.count();
		}
		if (mode == 2)
			radixSort(b, n, count);
		if (mode == 1)
			radixSort(a, n, count);
	}
	else if (strcmp(algorithm, "flash-sort") == 0)
	{

		if (mode == 0 || mode == 2)
		{
			auto start = std::chrono::high_resolution_clock::now();
			flashSortOrigin(a, n);
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
			time = duration.count();
		}
		if (mode == 2)
			flashSort(b, n, count);
		if (mode == 1)
			flashSort(a, n, count);
	}
	else
	{
		cout << "Error: Invalid sorting algorithm name\n";
		return;
	}
	
	if (checkOrder(a, n) == 0)
		cout << "Sort unsuccessfully\n";
	
	if (mode == 2)
	{
		if (checkOrder(b, n) == 0)
			cout << "Sort unsuccessfully\n";
	}

	time /= 1000;

	delete[] b;
}

string outputOrder(char* input)
{
	string output = "";
	if (strcmp(input, "-rand") == 0)
		output = "Randomize";

	else if (strcmp(input, "-nsorted") == 0)
		output = "Nearly Sorted";

	else if (strcmp(input, "-sorted") == 0)
		output = "Sorted";

	else if (strcmp(input, "-rev") == 0)
		output = "Reversed";

	return output;

}

//print 5 command 
void command1Output(char* algorithm, int mode, char* file, int size, double runtime, long long comparision)
{
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << algorithm << "\n";
	cout << "Input file: " << file << "\n";
	cout << "Input size: " << size << "\n";
	cout << string(25, '-') << "\n";
	cout << "\n";
	if (mode == 0 || mode == 2)
		cout << "Running time: " << runtime << "s" << "\n";
	if (mode == 1 || mode == 2)
		cout << "Comparisions: " << comparision << "\n";
	cout << "\n\n";
}


void command2Output(char* algorithm, int mode, char* order, int size, double runtime, long long comparision)
{
	string orderOutput = outputOrder(order);
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << algorithm << "\n";
	cout << "Input size: " << size << "\n";
	cout << "Input order: " << orderOutput << "\n";

	cout << string(25, '-') << "\n";

	if (mode == 0 || mode == 2)
		cout << "Running time: " << runtime << "s" << "\n";
	if (mode == 1 || mode == 2)
		cout << "Comparisions: " << comparision << "\n";
	cout << "\n\n";
}
void command3Output(char* algorithm, int mode, int size, double runtime1, long long comparision1, double runtime2, long long comparision2, double runtime3, long long comparision3, double runtime4, long long comparision4)
{
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << algorithm << "\n";
	cout << "Input size: " << size << "\n\n";


	cout << "Input order: Randomize\n";
	cout << string(25, '-') << "\n";
	if (mode == 0 || mode == 2)
		cout << "Running time: " << runtime1 << "s" << "\n";
	if (mode == 1 || mode == 2)
		cout << "Comparisions: " << comparision1 << "\n";
	cout << "\n";

	cout << "Input order: Nearly Sorted\n";
	cout << string(25, '-') << "\n";
	if (mode == 0 || mode == 2)
		cout << "Running time: " << runtime2 << "s" << "\n";
	if (mode == 1 || mode == 2)
		cout << "Comparisions: " << comparision2 << "\n";
	cout << "\n";

	cout << "Input order: Sorted\n";
	cout << string(25, '-') << "\n";
	if (mode == 0 || mode == 2)
		cout << "Running time: " << runtime3 << "s" << "\n";
	if (mode == 1 || mode == 2)
		cout << "Comparisions: " << comparision3 << "\n";
	cout << "\n";

	cout << "Input order: Reversed\n";
	cout << string(25, '-') << "\n";
	if (mode == 0 || mode == 2)
		cout << "Running time: " << runtime4 << "s" << "\n";
	if (mode == 1 || mode == 2)
		cout << "Comparisions: " << comparision4 << "\n";

	cout << "\n\n";
}

void command4Output(char* algorithm1, char* algorithm2, int mode, char* file, int size, double runtime1, long long comparision1, double runtime2, long long comparision2)
{
	cout << "COMPARE MODE\n";
	cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << "\n";
	cout << "Input file: " << file << "\n";
	cout << "Input size: " << size << "\n";

	cout << string(25, '-') << "\n";
	if (mode == 0 || mode == 2)
		cout << "Running time: " << runtime1 << "s" << " | " << runtime2 << "s" << "\n";
	if (mode == 1 || mode == 2)
		cout << "Comparisions: " << comparision1 << " | " << comparision2 << "\n";
	cout << "\n\n";
}


void command5Output(char* algorithm1, char* algorithm2, int mode, char* order, int size, double runtime1, long long comparision1, double runtime2, long long comparision2)
{
	cout << "COMPARE MODE\n";
	cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << "\n";
	cout << "Input size: " << size << "\n";
	cout << "Input order: " << outputOrder(order) << "\n";
	cout << string(25, '-') << "\n";
	if (mode == 0 || mode == 2)
		cout << "Running time: " << runtime1 << "s" << " | " << runtime2 << "s" << "\n";
	if (mode == 1 || mode == 2)
		cout << "Comparisions: " << comparision1 << " | " << comparision2 << "\n";
	cout << "\n\n";
}






// I/O
void inputArrayWithFile(int*& a, int& n, string file)
{
	fstream f;
	f.open(file, ios::in);
	if (f.fail())
	{
		cout << "Error: Invalid file!\n";
		return;
	}
	f >> n;
	a = new int[n];
	for (int i = 0; i < n; ++i)
		f >> a[i];


	f.close();
}

void printArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << "\n";
}


void printFile(int* a, int n, string file)
{
	fstream f;
	f.open(file, ios::out);
	f << n << "\n";
	for (int i = 0; i < n; ++i)
	{
		f << a[i] << " ";
	}

	f.close();
}




//TESTING AREA

//Check order
bool checkOrder(int a[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		if (a[i] > a[i + 1])
		{
			//cout << a[i] << "  " << a[i + 1] << "\n\n";
			return 0;
		}

	}
	return 1;
}


//Test for flash sort
bool checkbucket(int* a, int n)
{
	int bucket = n * 0.45;
	int mx = a[0], mn = a[0];
	int* sortArray = new int[bucket];
	for (int i = 1; i < n; ++i)
	{
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	double c = (double)(bucket - 1) / (double)(mx - mn);

	for (int i = 0; i < bucket; ++i)
		sortArray[i] = 0;

	for (int i = 0; i < n; ++i)
		++sortArray[(int)(c * (a[i] - mn))];


	for (int i = 1; i < bucket; ++i)
		sortArray[i] += sortArray[i - 1];

	int j = 0;
	for (int i = 0; i < bucket; ++i)
	{
		for (; j < sortArray[i]; ++j)
		{

			if ((int)(c * (a[j] - mn)) != i)
			{
				//cout <<a[j] << " " << i << " " << (int)(c * (a[j] - mn)) << "\n";
				return 0;
			}

		}
	}

	return 1;
}
