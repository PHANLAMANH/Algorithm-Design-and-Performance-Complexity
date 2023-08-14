#pragma once


//Sorting Algorithm


//Count comparision
void shakerSort(int a[], int begin, int end, long long& count);
void shellSort(int array[], int size, long long &count);
void insertionSort(int array[], int size, long long& count);
void bubbleSort(int array[], int size, long long& count);
void heapRebuild(int position, int array[], int size, long long& count);
void heapConstruct(int array[], int size, long long& count);
void heapSort(int array[], int size, long long& count);
void flashSort(int a[], int n, long long &count);
void selectionSort(int a[], int n, long long& count);
void merge(int a[], int left, int mid, int right, long long& count);
void mergeSort(int a[], int left, int right, long long& count);
void radixSort(int arr[], int size, long long& count);
void quickSort(int a[], int left, int right, long long& count);
void choosePartition(int a[], int left, int& mid, int right, long long& count);
void countingSort(int a[], int n, long long& count);

//Origin 
void shakerSortOrigin(int a[], int begin, int end);
void shellSortOrigin(int array[], int size);
void insertionSortOrigin(int array[], int size);
void bubbleSortOrigin(int array[], int size);
void heapRebuildOrigin(int position, int array[], int size);
void heapConstructOrigin(int array[], int size);
void heapSortOrigin(int array[], int size);
void flashSortOrigin(int a[], int n);
void selectionSortOrigin(int a[], int n);
void mergeOrigin(int a[], int left, int mid, int right);
void mergeSortOrigin(int a[], int left, int right);
void radixSortOrigin(int arr[], int size);
void quickSortOrigin(int a[], int left, int right);
void choosePartitionOrigin(int a[], int left, int& mid, int right);
void countingSortOrigin(int a[], int n);
