#include <iostream>
#include <limits>

int longestTableland(int v[], int n);
void longestTableland(int v[], int n, int i, int &ml, int &mn, int &cn, int &cl);

int main() {
	int v[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	std::cout << " 0 ? ->  " << longestTableland(v, 0) << std::endl;
	std::cout << " 1 ? ->  " << longestTableland(v, 1) << std::endl;
	std::cout << " 2 ? ->  " << longestTableland(v, 2) << std::endl;
	std::cout << " 3 ? ->  " << longestTableland(v, 3) << std::endl;
	std::cout << " 4 ? ->  " << longestTableland(v, 4) << std::endl;
	std::cout << " 5 ? ->  " << longestTableland(v, 5) << std::endl;
	std::cout << " 6 ? ->  " << longestTableland(v, 6) << std::endl;
	std::cout << " 7 ? ->  " << longestTableland(v, 7) << std::endl;
	std::cout << " 8 ? ->  " << longestTableland(v, 8) << std::endl;
	std::cout << " 9 ? ->  " << longestTableland(v, 9) << std::endl;

	v[1] = 1; // v[] = {0, 1, 0, 0, 0, 0, 0, 0, 0};
	std::cout << " 7 ? ->  " << longestTableland(v, 9) << std::endl; // 7


	v[1] = 0; v[7] = 1; // v[] = {0, 0, 0, 0, 0, 0, 0, 1, 0};
	std::cout << " 7 ? ->  " << longestTableland(v, 9) << std::endl; // 7


	int v1[] = {654, 654, 654, 4, 654, 546, 654, 564 };
	std::cout << " 3 ? ->  " << longestTableland(v1, sizeof(v1) / sizeof(int)) << std::endl; // 3


	int v2[999] = { 0 };
	std::cout << " 999 ? ->  " << longestTableland(v2, sizeof(v2) / sizeof(int)) << std::endl; // 999

	int v3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17, 18, 19};
	std::cout << " 1 ? ->  " << longestTableland(v3, sizeof(v3) / sizeof(int)) << std::endl; // 1

	return 0;
}




// P = [  (n >= 0) ^ (lenght(v) >= n) ^ (ForAll w : 0 <= w < n : INT_MIN < v[w] <= INT_MAX)  ]
// function longestTableland(int v[], int n) return int ml;
int longestTableland(int v[], int n) {
	int ml = 0, mn = INT_MIN, cl = 0, cn = INT_MIN;
	longestTableland(v, n, 0, ml, mn, cn, cl);
	return ml;
}
// Q = [ ml = (max a : 0 <= a < n - 1 : v[a] == v[a + 1]) ]

void longestTableland(int v[], int n, int i, int &ml, int &mn, int &cn, int &cl) {
	/*
	if (i >= n) { // Base case
	} else ...
	*/
	if (i < n) { // Recursive case
		if (v[i] == cn) {
			cl++;
		} else {
			cn = v[i];
			cl = 1;
		}

		if (cl > ml) { // This can't be in [(v[i] == cn)]: max tablelands with 1 element would be skiped.
			ml = cl;
			mn = cn;
		}
		longestTableland(v, n, i+1, ml, mn, cn, cl);
	}
}

/*

	Recursive approach description:	
		Starting with an index i = 0, each call to the recursive function increases i by 1, while i is less than the lenght of the array.
		Each call:
			Compare if element with index i is the same as the one temporarily saved in cn.
				If so, one more number in this tableland has been found
					increase cl
				If not, we have found a new tableland
					set cl to 1, and cn to the value of the numbers in this tableland
			Before the recursive call, check if cl (current tableland lenght) is greater than ml (max tableland lenght). 
				If so, the tableland we are working with has more elements than the ones before
					set the max tableland lenght to the current tableland lenght.
			Recursive call to check againg, this time with an array with 1 element less. (index i increased by 1)


		If the array has 0 elements, the recursive function does nothing (empty base case). 0 is returned.


	Termination function:
		t = n - i


	Recurrence equation: 
		T(0) = 1
		T(n) = 1*T(n - 1) + 10

		Recurrence by subtraction:
		T(n) € O(n) --> Linear complexity
*/