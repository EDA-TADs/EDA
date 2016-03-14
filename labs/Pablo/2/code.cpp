
#include <iostream>


// The function returns the number of elements in the array with the same value as the sum of all the elements after that one.
// {n >= 0 ^ length(v) >= n}
int algorithm(int v[], int n) {
	int r = 0, tempSum = 0, i = n;
	while (i > 0) {
		if (v[i - 1] == tempSum) {
			r++;
		}
		tempSum += v[i - 1];
		i--;
	}
	return r;
}
// { r = (#i : 0 <= i < n : v[i] = (SUM j : i + 1 <= j <= n - 1 : v[j])) }

// Invariant:   I =   { (0 <= i <= n) ^ (tempSum = SUM w : i <= w < n : v[w]) ^  [r = (#j : i <= j < n : v[j] = (SUM j : i + 1 <= j <= n - 1 : v[j])  )]  }

// Complexity: linear. (1 loop, to be executed n-1 times).   O(n)


// Test:
int main() {
	
	int testArray[5] = {};


	std::cout << "  Test Array   | " << "r" << " | Correct value" << std::endl;
	std::cout << "----------------------------------" << std::endl;

	testArray[0] = 0;
	std::cout << "{0}            | " << algorithm(testArray, 1) << " |    1 " << std::endl;

	testArray[0] = 1;
	std::cout << "{1}            | " << algorithm(testArray, 1) << " |    0 " << std::endl;

	testArray[0] = 0; testArray[1] = 0; testArray[2] = 0;
	std::cout << "{0, 0, 0}      | " << algorithm(testArray, 3) << " |    3 " << std::endl;

	testArray[0] = 1; testArray[1] = 1;
	std::cout << "{1, 1}         | " << algorithm(testArray, 2) << " |    1 " << std::endl;
	
	testArray[0] = 4; testArray[1] = 2; testArray[2] = 1; testArray[3] = 1;
	std::cout << "{4, 2, 1, 1}   | " << algorithm(testArray, 4) << " |    3 " << std::endl;

	testArray[0] = 1; testArray[1] = 2; testArray[2] = 3; testArray[3] = 4;
	std::cout << "{1, 2, 3, 4}   | " << algorithm(testArray, 4) << " |    0 " << std::endl;

	testArray[0] = 1; testArray[1] = 1; testArray[2] = 1; testArray[3] = 1;
	std::cout << "{1, 1, 1, 1}   | " << algorithm(testArray, 4) << " |    1 " << std::endl;

	testArray[0] = 0; testArray[1] = 0; testArray[2] = 0; testArray[3] = 0; testArray[4] = 0;
	std::cout << "{0, 0, 0, 0, 0}| " << algorithm(testArray, 5) << " |    5 " << std::endl;
	
	testArray[0] = 8; testArray[1] = 4; testArray[2] = 2; testArray[3] = 1; testArray[4] = 1;
	std::cout << "{8, 4, 2, 1, 1}| " << algorithm(testArray, 5) << " |    4 " << std::endl;


	return 0;
}