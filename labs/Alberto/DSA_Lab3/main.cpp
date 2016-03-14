/* 1.
	{P} = { n ≥ 0 ∧ m ≥ 0 }
	int numElements(int v[], int u[], int n, int m) return x
	{Q} = { x = #i: 0 ≤ i < n: (∃!j: 0 ≤ j < m: v[i] = u[j]) }

   2.
	d(v, u, n, m): n ≤ 0 ∧ m ≤ 0
	r(v, u, n, m); n > 0 ∧ m > 0
   
   3.
	{P0 ∧ d(v, u, n, m)} A {Q}
	A: x = 0
   
   4.
	if v[n-1] = u[m-1] then s(v, u, n, m) = (v, u, n - 1, m - 1)
	if v[n-1] > u[m-1] then s(v, u, n, m) = (v, u, n - 1, m)
	if v[n-1] < u[m-1] then s(v, u, n, m) = (v, u, n, m - 1)

   5.
	t(v, u, n, m) = n ∧ m

   6.
	P0 ∧ r(v, u, n, m) => P0(s(v, u, n, m))
	n ≥ 0 ∧ m ≥ 0 ∧ n > 0 ∧ m > 0 => n - 1 ≥ 0 ∧ m - 1 ≥ 0

   7.
	x = x' + 1

   8.
	P0 ∧ r(v, u, n, m)
	x = numElements(v, u, n - 1, m - 1) + 1;

 */

#include <iostream>
using namespace std;

int numElements(int v[], int u[], int n, int m);

int main()
{   
	/*
	const int n = 1;
	const int m = 1;
	int v[n] = { 1 };
	int u[m] = { 2 };
	*/

	/*
	const int n = 1;
	const int m = 1;
	int v[n] = { 1 };
	int u[m] = { 1 };
	*/
	
	/*
	const int n = 9;
	const int m = 9;
	int v[n] = { 0,0,0,0,0,0,0,0,0 };
	int u[m] = { 0,0,0,0,0,0,0,1,2 };
	*/

	const int n = 10;
	const int m = 5;
	int v[n] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
	int u[m] = { 2, 3, 6, 9, 12 }; 

	cout << numElements(v, u, n, m) << endl;

	system("pause");
	return 0;
}

int numElements(int v[], int u[], int n, int m) {
	int x;

	if ((n <= 0) || (m <= 0))
		x = 0;
	else {
		if (v[n - 1] == u[m - 1])
			x = numElements(v, u, n - 1, m - 1) + 1;
		else if (v[n - 1] > u[m - 1])
			x = numElements(v, u, n - 1, m);
		else
			x = numElements(v, u, n, m - 1);
	}

	return x;
}