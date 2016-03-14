/*	{P} = lenght of the array must be greater or equal than 0
	{Q} = r is the number of times that a position v[i] is equal to the sum of the next positions of the array
	 I = { (n ≧ 0) ∧ (j = i + 1) ∧ r = (#i: 0 ≦ i < n: add = (∑j: j < n: v[j])) }

	 Complexity:
		body while: 1 + 1 + 2 + 2 + 1 + 1 = 8
		while loop: n(8 + 1) + 1 = 8n + 9
		Total: (initializations) 1 + 1 + 1 + 8n + 9 = 8n + 12
*/
#include <iostream>
using namespace std;

const int N = 10;
int algorithm(int v[], int n);

int main()
{
	int v[N] = { 4, 0, 0, 0, 0, 0, 0, 2, 1, 1 };
	// int v[N] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	// int v[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	// int v[N] = { 9, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	cout << algorithm(v, N) << endl;

	system("pause");
	return 0;
}

int algorithm(int v[], int n) {
	int r = 0;
	int i = n - 1;
	int j, add = 0;

	while (i >= 0) {
		j = i + 1;
		if (j < n) {
			add = add + v[j];
			if (v[i] == add)
				r++;
		}
		i--;
	}

	return r;
}