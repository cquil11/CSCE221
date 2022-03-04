#include "SortLib.h"
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

int main(int argc, char *argv[])
{

	if (argc < 3)
	{ // must have at least 3 arguments for ./sort -a <algorithm>
		std::cerr << "Usage: " << argv[0] << " -a <algorithm> [-i <infile> -o <outfile> -t]" << std::endl;
		return 1;
	}

	// Parse the arguments
	// You can assume if -a is present, so is the algorithm
	// And if -i is present, so is the filename, and so on
	std::string algorithm = "";
	std::string filename_in = "";
	std::string filename_out = "";
	bool time = false;

	int i = 0;
	while (i < argc)
	{
		std::string currentArg = std::string(argv[i]);
		if (currentArg == "-a")
		{
			i++;
			algorithm = std::string(argv[i]);
		}
		else if (currentArg == "-i")
		{
			i++;
			filename_in = std::string(argv[i]);
		}
		else if (currentArg == "-o")
		{
			i++;
			filename_out = std::string(argv[i]);
		}
		else if (currentArg == "-t")
		{
			time = true;
			i++;
		}
		else
		{
			i++;
		}
	}


	// Read the input data
	// If a file was provided with -i, read from the file
	// Else, read from stdin (cin)
	unsigned size = 0;
	std::ifstream fileReader;

	if (filename_in == "")
	{
		std::cin >> size;
	}
	else
	{
		fileReader.open(filename_in);
		if (!fileReader.good())
		{
			std::cerr << "Unable to open input file." << std::endl;
			return 1;
		}
		fileReader >> size;
	}

	int arr[size];

	if (filename_in == "")
	{
		for (int i = 0; i < size; i++)
		{
			std::cin >> arr[i];
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			fileReader >> arr[i];
		}
	}

	fileReader.close();

	// Set up your timer
	// You can use the included "chrono" library from C++11!
	// Hint: The following line of code would give you the current time
	auto start = std::chrono::high_resolution_clock::now();

	// Apply the sorting algorithm based on the given argument
	if (algorithm == "merge")
	{
		SortLib::MergeSort(arr, size);
	}
	else if (algorithm == "insertion")
	{
		SortLib::InsertionSort(arr, size);
	}
	else if (algorithm == "radix")
	{
		SortLib::RadixSort(arr, size);
	}
	auto end = std::chrono::high_resolution_clock::now();

	// Stop your timer and find the difference
	// Hint: The following line can compute the difference of two times in microseconds
	// auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::chrono::duration<double> duration = end - start;

	// Write the output data
	// If a file was provided with -o, write to that file
	// Else, write to stdout (cout)
	if (filename_out == "")
	{
		for (int i = 0; i < size; i++)
		{
			if (i == size - 1)
			{
				std::cout << arr[i] << std::endl;
			}
			else
			{
				std::cout << arr[i] << " ";
			}
		}
	}
	else
	{
		std::ofstream fileWriter(filename_out);
		if (!fileWriter.is_open())
		{
			std::cerr << "Unable to open output file." << std::endl;
			return 1;
		}

		for (int i = 0; i < size; i++)
		{
			if (i == size - 1)
			{
				fileWriter << arr[i] << std::endl;
			}
			else
			{
				fileWriter << arr[i] << " ";
			}
		}
	}

	// If -t was set, print the elapsed time as "Elapsed Time: <duration>"
	if (time)
	{
		std::cout << "Elapsed Time: " << duration.count() << std::endl;
	}

	// Cleanup; remember to delete your dynamic data array!
	// delete[] argv;

	return 0;
}