#include "Header.h"

using namespace std;


int main(int argc, char** argv)
{

	int* a = NULL, * b = NULL, n = 0;
	long long count1 = 0, count2 = 0;
	double time1 = 0, time2 = 0;
	int mode = 2;

	if (argc <= 1)
	{
		//Test

		a = new int[500000];
		n = 500000;
		inputArrayWithFile(a, n, "test.txt");
		//GenerateRandomData(a, n);
		//cout << checkOrder(a, n);
		//printFile(a, n, "output2.txt");
		auto start = std::chrono::high_resolution_clock::now();
		//mergeSort(a, 0, n - 1, count1);

		flashSortOrigin(a, n);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		//printArray(a, DATATYPE4);
		cout << checkOrder(a, n) << "\n";
		cout << "Count: " << count1 << "\n";
		cout << "Time: " << duration.count() << endl;
		delete[] a;
		return 0;
	}


	if (strcmp(argv[1], "-a") == 0)
	{

		mode = chooseMode(argv[argc - 1]);
		if (mode == -1)
		{
			cout << "Error: Unknown output parameters!\n";
			return 0;
		}
		if (argc == 5)
		{
			bool fileInput = 0;
			for (int i = 0; i < strlen(argv[3]); ++i)
			{
				if (argv[3][i] == '.')
				{
					fileInput = 1;
					break;
				}
			}

			if (fileInput == 1)
			{
				inputArrayWithFile(a, n, argv[3]);
				if (a == NULL)
					return 0;
				chooseSort(argv[2], mode, a, n, count1, time1);
				printFile(a, n, "output.txt");
				//C1
				command1Output(argv[2], mode, argv[3], n, time1, count1);
				delete[] a;
			}
			else
			{
				n = atol(argv[3]);
				if (n < 0)
					return 0;
				long long c1 = 0, c2 = 0, c3 = 0, c4 = 0;
				double t1 = 0, t2 = 0, t3 = 0, t4 = 0;
				a = new int[n];

				GenerateRandomData(a, n);
				printFile(a, n, "input_1.txt");
				chooseSort(argv[2], mode, a, n, c1, t1);


				GenerateNearlySortedData(a, n);
				printFile(a, n, "input_2.txt");
				chooseSort(argv[2], mode, a, n, c2, t2);


				GenerateSortedData(a, n);
				printFile(a, n, "input_3.txt");
				chooseSort(argv[2], mode, a, n, c3, t3);


				GenerateReverseData(a, n);
				printFile(a, n, "input_4.txt");
				chooseSort(argv[2], mode, a, n, c4, t4);

				//C3
				command3Output(argv[2], mode, n, t1, c1, t2, c2, t3, c3, t4, c4);

				delete[] a;
				
			}

		}
		else
		{
			int n = atol(argv[3]);
			if (n < 0)
				return 0;
			a = new int[n];
			chooseGenerator(argv[4], a, n);
			if (a == NULL)
			{
				cout << "Error: unknown data type!\n";
			}
			printFile(a, n, "input.txt");
			chooseSort(argv[2], mode, a, n, count1, time1);
			//C2
			command2Output(argv[2], mode, argv[4], n, time1, count1);
			printFile(a, n, "output.txt");
			delete[] a;
		}

	}

	else if (strcmp(argv[1], "-c") == 0)
	{
		if (argc == 5)
		{
			inputArrayWithFile(a, n, argv[4]);
			b = new int[n];
			copyArray(a, b, n);
			chooseSort(argv[2], mode, a, n, count1, time1);
			chooseSort(argv[3], mode, b, n, count2, time2);
			//C4
			command4Output(argv[2], argv[3], mode, argv[argc - 1], n, time1, count1, time2, count2);
			delete[] a;
			delete[] b;
		}
		else
		{
			int n = atol(argv[4]);
			if (n < 0)
				return 0;
			a = new int[n];
			b = new int[n];
			if(!chooseGenerator(argv[5], a, n))
			{
				cout << "Error: unknown data type!\n";
				return 0;
			}
			printFile(a, n, "input.txt");
			copyArray(a, b, n);
			chooseSort(argv[2], mode, a, n, count1, time1);
			chooseSort(argv[3], mode, b, n, count2, time2);
			//C5
			command5Output(argv[2], argv[3], mode, argv[argc - 1], n, time1, count1, time2, count2);
			delete[] a;
			delete[] b;
		}
	}

	return 0;
}