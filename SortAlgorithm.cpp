#include <iostream>
#include <fstream>
#include <cstring>

#include <chrono> 

#include "Header.h"
#include "Generator.h"
using namespace std;


//Count Comparision 
void shakerSort(int a[], int begin, int end, long long& count) //0->n-1
{
	int pos = begin;
	while (++count&& begin < end)
	{
		for (int i = begin; ++count && i < end; ++i)
		{
			if (++count && a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				pos = i;
			}
		}
		end = pos;


		for (int i = end; ++count && i > begin; --i)
		{
			if (++count && a[i - 1] > a[i])
			{
				swap(a[i - 1], a[i]);
				pos = i;
			}
		}
		begin = pos;
	}
}

void flashSort(int a[], int n, long long& count)
{
	//number of buckets
	int bucket = n * 0.45;
	int mmin = a[0], mmax = a[0];
	int* sortArray = new int[bucket];

	for (int i = 0; ++count && i < bucket; ++i)
		sortArray[i] = 0;

	//find min,max
	for (int i = 1; ++count && i < n; ++i)
	{
		if (++count && a[i] < mmin)
			mmin = a[i];
		if (++count && a[i] > mmax)
			mmax = a[i];
	}

	double c = (double)(bucket - 1) / (double)(mmax - mmin);

	//last element position
	for (int i = 0; ++count && i < n; ++i)
		++sortArray[(int)(c * (a[i] - mmin))];
	for (int i = 1; ++count && i < bucket; ++i)
		sortArray[i] += sortArray[i - 1];

	//move elements to their right buckets
	int k;
	for (int i = 0; ++count && i < n; ++i)
	{
		k = (int)(c * (a[i] - mmin));
		while (++count && i >= sortArray[k] && ++count && sortArray[k] > 0)
		{
			swap(a[i], a[--sortArray[k]]);
			k = (int)(c * (a[i] - mmin));
		}

	}

	//insertion sort
	int tmp, j;
	for (int i = 0; ++count && i < n; ++i)
	{
		tmp = a[i];
		for (j = i - 1; ++count && j >= 0 && ++count && a[j] > tmp; --j)
		{
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = tmp;
	}
	delete[] sortArray;
}



void insertionSort(int array[], int size, long long& count) {
	int j, temp;
	for (int i = 1; ++count && i < size; i++) {
		j = i;
		while (++count && j > 0 && ++count && array[j] < array[j - 1]) {
			temp = array[j - 1];
			array[j - 1] = array[j];
			array[j] = temp;
			j--;
		}
	}
}

void bubbleSort(int array[], int size, long long& count) {
	bool ordered = 1;
	for (int i = 0; ++count && i < size; i++) {
		for (int j = 0; ++count && j < size - 1 - i; j++) {
			if (++count && array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
				ordered = 0;
			}
		}
		if (++count && ordered)
			break;
		ordered = 1;
	}
}

void heapRebuild(int position, int array[], int size, long long& count) {
	int parent = position, child = 2 * parent + 1;      // Initialize the first child value

	while (++count && child < size) {

		// Get the max value out of the 2 children
		// If the parent only have 1 child then do nothing
		if (++count && child < size - 1) {
			if (++count && array[child] < array[child + 1])
				child += 1;
		}

		if (++count && array[parent] > array[child]) return;   // Return if current subtree is already a heap

		int temp = array[child];

		array[child] = array[parent];
		array[parent] = temp;

		parent = child;             // Update the parent
		child = 2 * parent + 1;     // Check the child of the new parent
	}
}

void heapConstruct(int array[], int size, long long& count) {
	for (int index = size / 2 - 1; ++count && index >= 0; index--)
		heapRebuild(index, array, size, count);
}

void heapSort(int array[], int size, long long& count) {
	heapConstruct(array, size, count);
	for (int i = size - 1; ++count && i > 0; i--) {
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		heapRebuild(0, array, i, count);
	}
}

void selectionSort(int a[], int n, long long& count)
{
	int mmin, index = 0;
	for (int i = 0; ++count && i < n; i++)
	{
		mmin = a[i];
		index = i;
		for (int j = i + 1; ++count && j < n; j++)
		{
			if (++count && a[j] < mmin)
			{
				mmin = a[j];
				index = j;
			}
		}
		swap(a[i], a[index]);
	}
}

void merge(int a[], int left, int mid, int right, long long& count)
{
	int* b = new int[right - left + 1];
	int temp1 = left, temp = mid + 1, cur = 0;
	while (++count && temp1 < mid + 1 && ++count && temp < right + 1)			//put in temp array
	{
		if (++count && a[temp1] < a[temp])
		{
			b[cur] = a[temp1];
			cur++;
			temp1++;
		}
		else
		{
			b[cur] = a[temp];
			cur++;
			temp++;
		}
	}
	if (++count && cur < right - left + 1)			//continue putting to temp array if haven't finish because left/right array is done
	{
		for (int i = temp1; ++count && i < mid + 1; i++)
		{
			b[cur] = a[i];
			cur++;
		}
		for (int i = temp; ++count && i < right + 1; i++)
		{
			b[cur] = a[i];
			cur++;
		}
	}
	temp1 = left;			//copy temp array to the array
	for (int i = 0; ++count && i < right - left + 1; i++)
	{
		a[temp1] = b[i];
		temp1++;
	}
	delete[] b;
}

void mergeSort(int a[], int left, int right, long long& count)
{
	int mid;
	if (++count && left < right)
	{
		mid = (left + right) / 2;			//spliting the array
		mergeSort(a, left, mid, count);
		mergeSort(a, mid + 1, right, count);
		merge(a, left, mid, right, count);
	}
}

void choosePartition(int a[], int left, int& mid, int right, long long& count)
{
	swap(a[right], a[mid]);
	int j = left - 1;		    //indicate last element of S1
	for (int i = left; ++count && i < right; i++)
		if (++count && a[i] < a[right])
		{
			j++;
			swap(a[i], a[j]);	//swap element of S1 with S2
		}
	swap(a[++j], a[right]);		//move to first element of S2
	mid = j;

}

void quickSort(int a[], int left, int right, long long& count)
{
	if (++count && left < right)
	{
		int mid = (left + right) / 2;
		choosePartition(a, left, mid, right, count);
		quickSort(a, left, mid - 1, count);		//quick Sort S1
		quickSort(a, mid + 1, right, count);	//quick sort S2
	}
}

void shellSort(int array[], int size, long long& count) {

	int space = 1;
	while (++count && space < size / 3)
		space = space * 3 + 1;
	while (++count && space > 0)
	{
		for (int i = space; ++count && i < size; i++)
		{
			int x = array[i];
			int j = i;
			while (++count && j - space >= 0 && ++count && array[j - space] > x && ++count && j > space - 1)
			{
				array[j] = array[j - space];
				j -= space;
			}
			array[j] = x;
		}
		space = (space - 1) / 3;

	}
}

int getMax(int arr[], int size, long long& count) {
	int mmax = arr[0];
	for (int i = 1; ++count && i < size; i++) {
		if (++count && arr[i] > mmax) {
			mmax = arr[i];
		}
	}
	return mmax;
}


void radixSort(int arr[], int size, long long& count) {
	int i, mmax, * temp = new int[size], countDigit[10], expo = 1;

	//tim max value
	mmax = getMax(arr, size, count);
	
	while (++count && mmax / expo > 0) {


		for (i = 0; ++count && i < 10; i++) {
			countDigit[i] = 0;
		}

		//luu bien dem vao array khac
		for (i = 0; ++count && i < size; i++) {
			countDigit[(arr[i] / expo) % 10]++;
		}

		//vi tri dau tien
		countDigit[9] = size - countDigit[9];
		for (i = 8; ++count && i >= 0; --i)
			countDigit[i] = countDigit[i + 1] - countDigit[i];

		for (i = 0; ++count && i < size; i++)
			temp[countDigit[arr[i] / expo % 10]++] = arr[i];

		for (i = 0; ++count && i < size; i++)
			arr[i] = temp[i];

		expo *= 10;
	}
	delete[] temp;
}

void countingSort(int a[], int n, long long& count)
{
	int mmax = getMax(a, n, count);
	int* frq = new int[mmax+1];

	for (int i = 0; ++count && i <= mmax; i++)
		frq[i] = 0;
	
	//count
	for (int i = 0; ++count && i < n; i++)
		frq[a[i]]++;

	int index = 0;
	for (int i = 0; ++count && i <= mmax; i++)
	{
		while (++count && frq[i]--)
			a[index++] = i;
	}
	delete[] frq;
}






//Origin 

void shakerSortOrigin(int a[], int begin, int end) //0->n-1
{
	int pos = begin;
	while (begin < end)
	{

		for (int i = begin; i < end; ++i)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				pos = i;
			}
		}
		end = pos;


		for (int i = end; i > begin; --i)
		{
			if (a[i - 1] > a[i])
			{
				swap(a[i - 1], a[i]);
				pos = i;
			}
		}
		begin = pos;
	}
}


void flashSortOrigin(int a[], int n)
{

	int bucket = n * 0.45;

	int mmin = a[0], mmax = a[0];
	int* sortArray = new int[bucket];

	for (int i = 0; i < bucket; ++i)
		sortArray[i] = 0;

	for (int i = 1; i < n; ++i)
	{
		if (a[i] < mmin)
			mmin = a[i];
		if (a[i] > mmax)
			mmax = a[i];
	}

	double c = (double)(bucket - 1) / (double)(mmax - mmin);

	for (int i = 0; i < n; ++i)
		++sortArray[(int)(c * (a[i] - mmin))];
	for (int i = 1; i < bucket; ++i)
		sortArray[i] += sortArray[i - 1];

	int k;
	for (int i = 0; i < n; ++i)
	{
		k = (int)(c * (a[i] - mmin));
		while (i >= sortArray[k] && sortArray[k] > 0)
		{
			swap(a[i], a[--sortArray[k]]);
			k = (int)(c * (a[i] - mmin));
		}
	}

	int tmp, j;
	for (int i = 0; i < n; ++i)
	{
		tmp = a[i];
		for (j = i - 1; j >= 0 && a[j] > tmp; --j)
		{
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = tmp;
	}
	delete[] sortArray;
}



void insertionSortOrigin(int array[], int size) {
	int j, temp;
	for (int i = 1; i < size; i++) {
		j = i;
		while (j > 0 && array[j] < array[j - 1]) {
			temp = array[j - 1];
			array[j - 1] = array[j];
			array[j] = temp;
			j--;
		}
	}
}

void bubbleSortOrigin(int array[], int size) {
	bool ordered = 1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
				ordered = 0;
			}
		}
		if (ordered)
			break;
		ordered = 1;
	}
}

void heapRebuildOrigin(int position, int array[], int size) {
	int parent = position, child = 2 * parent + 1;      // Initialize the first child value

	while (child < size) {

		// Get the max value out of the 2 children
		// If the parent only have 1 child then do nothing
		if (child < size - 1) {
			if (array[child] < array[child + 1])
				child += 1;
		}

		if (array[parent] > array[child]) return;   // Return if current subtree is already a heap

		int temp = array[child];

		array[child] = array[parent];
		array[parent] = temp;

		parent = child;             // Update the parent
		child = 2 * parent + 1;     // Check the child of the new parent
	}
}

void heapConstructOrigin(int array[], int size) {
	for (int index = size / 2 - 1; index >= 0; index--)
		heapRebuildOrigin(index, array, size);
}

void heapSortOrigin(int array[], int size) {
	heapConstructOrigin(array, size);
	for (int i = size - 1; i > 0; i--) {
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		heapRebuildOrigin(0, array, i);
	}
}

void selectionSortOrigin(int a[], int n)
{
	int mmin, index = 0;
	for (int i = 0; i < n; i++)
	{
		mmin = a[i];
		index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < mmin)
			{
				mmin = a[j];
				index = j;
			}
		}
		swap(a[i], a[index]);
	}
}

void mergeOrigin(int a[], int left, int mid, int right)
{
	int* b = new int[right - left + 1];
	int temp1 = left, temp = mid + 1, cur = 0;
	while (temp1 < mid + 1 && temp < right + 1)			//put in temp array
	{
		if (a[temp1] < a[temp])
		{
			b[cur] = a[temp1];
			cur++;
			temp1++;
		}
		else
		{
			b[cur] = a[temp];
			cur++;
			temp++;
		}
	}
	if (cur < right - left + 1)			//continue putting to temp array if haven't finish because left/right array is done
	{
		for (int i = temp1; i < mid + 1; i++)
		{
			b[cur] = a[i];
			cur++;
		}
		for (int i = temp; i < right + 1; i++)
		{
			b[cur] = a[i];
			cur++;
		}
	}
	temp1 = left;			//copy temp array to the array
	for (int i = 0; i < right - left + 1; i++)
	{
		a[temp1] = b[i];
		temp1++;
	}
	delete[] b;
}

void mergeSortOrigin(int a[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;			//spliting the array
		mergeSortOrigin(a, left, mid);
		mergeSortOrigin(a, mid + 1, right);
		mergeOrigin(a, left, mid, right);
	}
}

void choosePartitionOrigin(int a[], int left, int& mid, int right)
{
	swap(a[right], a[mid]);
	int j = left - 1;		    //indicate last element of S1
	for (int i = left; i < right; i++)
		if (a[i] < a[right])
		{
			j++;
			swap(a[i], a[j]);	//swap element of S1 with S2
		}
	swap(a[++j], a[right]);		//move to first element of S2
	mid = j;

}

void quickSortOrigin(int a[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		choosePartitionOrigin(a, left, mid, right);
		quickSortOrigin(a, left, mid - 1);		//quick Sort S1
		quickSortOrigin(a, mid + 1, right);	//quick sort S2
	}
}

void shellSortOrigin(int array[], int size) {

	int space = 1;
	while (space < size / 3)
		space = space * 3 + 1;
	while (space > 0)
	{
		for (int i = space; i < size; i++)
		{
			int x = array[i];
			int j = i;
			while (j - space >= 0 && array[j - space] > x && j > space - 1)
			{
				array[j] = array[j - space];
				j -= space;
			}
			array[j] = x;
		}
		space = (space - 1) / 3;

	}
}

//getMax cho radixsort
int getMaxOrigin(int arr[], int size) {
	int mmax = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > mmax) {
			mmax = arr[i];
		}
	}
	return mmax;
}


void radixSortOrigin(int arr[], int size) {
	int i, mmax, * temp = new int[size], countDigit[10], expo = 1;

	//tim max value
	mmax = getMaxOrigin(arr, size);

	while (mmax / expo > 0) {
		//reset count
		for (i = 0; i < 10; i++) {
			countDigit[i] = 0;
		}

		//luu bien dem vao array khac
		for (i = 0; i < size; i++) {
			countDigit[(arr[i] / expo) % 10]++;
		}

		//vi tri dau tien
		countDigit[9] = size - countDigit[9];
		for (i = 8; i >= 0; --i)
			countDigit[i] = countDigit[i + 1] - countDigit[i];

		for (i = 0; i < size; i++)
			temp[countDigit[arr[i] / expo % 10]++] = arr[i];

		for (i = 0; i < size; i++)
			arr[i] = temp[i];

		expo *= 10;
	}
	delete[] temp;
}

void countingSortOrigin(int a[], int n)
{
	int mmax = getMaxOrigin(a, n);
	int* frq = new int[mmax+1];

	for (int i = 0; i <= mmax; i++)
		frq[i] = 0;

	//count
	for (int i = 0; i < n; i++)
		frq[a[i]]++;

	int index = 0;
	for (int i = 0; i <= mmax; i++)
	{
		while (frq[i]--)
			a[index++] = i;
	}
	delete[] frq;
}
