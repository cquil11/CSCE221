#include "SortLib.h"
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

int main(int argc, char* argv[]) {

	if (argc < 3) { // must have at least 3 arguments for ./sort -a <algorithm>
		std::cerr << "Usage: " << argv[0] << " -a <algorithm> [-i <infile> -o <outfile> -t]" << std::endl;
        return 1;
	}

	// Parse the arguments
	// You can assume if -a is present, so is the algorithm
	// And if -i is present, so is the filename, and so on


	// Read the input data
	// If a file was provided with -i, read from the file
	// Else, read from stdin (cin)

	// Set up your timer
	// You can use the included "chrono" library from C++11!
	// Hint: The following line of code would give you the current time
	// auto start = std::chrono::high_resolution_clock::now();

	// Apply the sorting algorithm based on the given argument
	
	// Stop your timer and find the difference
	// Hint: The following line can compute the difference of two times in microseconds
	// auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	// Write the output data
	// If a file was provided with -o, write to that file
	// Else, write to stdout (cout)

	// If -t was set, print the elapsed time as "Elapsed Time: <duration>"

	// Cleanup; remember to delete your dynamic data array!

	return 0;
}