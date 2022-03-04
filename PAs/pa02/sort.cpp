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

	// Instantiate variables to hold selected algorithm, input file, and output file
	// as well as if time was specified
	std::string algorithm = "";
	std::string filename_in = "";
	std::string filename_out = "";
	bool time = false;

	// Parse the arguments
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

	// Before we can instantiate the array to be sorted, we need its size
	// Get size from cin, else from file (depending on what the user specified)
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

	// Instantiate array
	int *arr = new int[size];

	// Read the actual input from either the file or cin (depending on user specification)
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

	// Set up timer
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

	// Stop timer and computer difference (elapsed time)
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

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

	// If -t was set, print the elapsed time
	if (time)
	{
		std::cout << "Elapsed Time: " << duration.count() << std::endl;
	}

	// Cleanup
	delete [] arr;

	return 0;
}