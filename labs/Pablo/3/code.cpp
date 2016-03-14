
#include <iostream>
#include <limits>

int countCommonElements(int u[], int v[], int nu, int nv, int top);
int countCommonElements(int u[], int v[], int nu, int nv);

int main() {

	int u[100] = {0}; // u = {0, 0, 0, 0, 0, .....}
	int v[200] = {0}; // v = {0, 0, 0, 0, 0, .....}

	int c;
	
	c = countCommonElements(u, v, sizeof(u) / sizeof(int), sizeof(v) / sizeof(int));  // Should return 1
	std::cout << "1? " << c << std::endl;


	u[0] = 1; // u = {1, 0, 0, 0, 0, .....}
	v[0] = 1; // v = {1, 0, 0, 0, 0, .....}
	c = countCommonElements(u, v, sizeof(u) / sizeof(int), sizeof(v) / sizeof(int));  // Should return 2
	std::cout << "2? " << c << std::endl;


	u[0] = 0; u[1] = 1; u[2] = 2; u[3] = 3; // u = {0, 1, 2, 3}
	v[0] = 0; v[1] = 1; v[2] = 2; v[3] = 3; // v = {0, 1, 2, 3}
	c = countCommonElements(u, v, 4, 4); // Should return 4
	std::cout << "4? " << c << std::endl;


	u[0] = 0; u[1] = 1; u[2] = 2; u[3] = 3; u[4] = 3; u[5] = 3; // u = {0, 1, 2, 3, 3, 3}
	v[0] = 0; v[1] = 1; v[2] = 2; v[3] = 3; v[4] = 3; v[5] = 3; // v = {0, 1, 2, 3, 3, 3}
	c = countCommonElements(u, v, 6, 6); // Should return 4
	std::cout << "4? " << c << std::endl;


	u[0] = 0; u[1] = 100; u[2] = 300; u[3] = 350; u[4] = 450; u[5] = 600; // u = {0, 100, 300, 350, 450, 600}
	v[0] = 0; v[1] = 100; v[2] = 200; v[3] = 300; v[4] = 400; v[5] = 500; // v = {0, 100, 200, 300, 400, 500}
	c = countCommonElements(u, v, 6, 6); // Should return 3
	std::cout << "3? " << c << std::endl;


	u[0] = -1000; u[1] = -100; u[2] = 0; u[3] = 100; u[4] = 200; u[5] = 4000; // u = {-1000, -100, 0, 100, 200, 4000}
	v[0] = 0; v[1] = 100; v[2] = 200; v[3] = 300; v[4] = 400; v[5] = 500; // v = {0, 100, 200, 300, 400, 500}
	c = countCommonElements(u, v, 6, 6); // Should return 3
	std::cout << "3? " << c << std::endl;


	u[0] = -1000; u[1] = -100; u[2] = 0; u[3] = 100; u[4] = 200; u[5] = 4000; // u = {-1000, -100, 0, 100, 200, 4000}
	v[0] = 0; v[1] = 100; v[2] = 200; v[3] = 300; v[4] = 400; v[5] = 500; // v = {0, 100, 200, 300, 400, 500}
	c = countCommonElements(u, v, 6, 6); // Should return 3
	std::cout << "3? " << c << std::endl;

	for (int i = 0; i < sizeof(u) / sizeof(int); i++) // u = {0, 1, 2, 3, 4, 5, 6, ...}
		u[i] = i;
	for (int i = 0; i < sizeof(v) / sizeof(int); i++) // v = {0, 1, 2, 3, 4, 5, 6, ...}
		v[i] = i;
	c = countCommonElements(u, v, sizeof(u) / sizeof(int), sizeof(v) / sizeof(int));  // Should return: min(sizeof(u) / sizeof(int), sizeof(v) / sizeof(int))
	std::cout << ((sizeof(u) / sizeof(int) > sizeof(v) / sizeof(int)) ? sizeof(v) / sizeof(int) : sizeof(u) / sizeof(int)) << "? " << c << std::endl;


	for (int i = 0; i < sizeof(u) / sizeof(int); i++) // u = {0, 1, 2, 3, 4, 5, 6, ...}
		u[i] = i;
	for (int i = 0; i < sizeof(v) / sizeof(int); i++) // v = {0, 2, 4, 6, 8, 10, 12, ...}
		v[i] = 2 * i;
	c = countCommonElements(u, v, sizeof(u) / sizeof(int), sizeof(v) / sizeof(int)); // Should return?: min[(sizeof(u) / sizeof(int)) / 2 + ((sizeof(u) / sizeof(int)) % 2 == 1 ? 1 : 0) , sizeof(v) / sizeof(int)]
	std::cout << ((((sizeof(u) / sizeof(int)) / 2 + ((sizeof(u) / sizeof(int)) % 2 == 0 ? 0 : 1)) < sizeof(v) / sizeof(int)) ? ((sizeof(u) / sizeof(int)) / 2 + ((sizeof(u) / sizeof(int)) % 2 == 0 ? 0 : 1)) : sizeof(v) / sizeof(int)) << "? " << c << std::endl;


	for (int i = 0; i < sizeof(u) / sizeof(int); i++) // u = {0, 1, 2, 3, 4, 5, 6, ...}
		u[i] = i;
	for (int i = 0; i < sizeof(v) / sizeof(int); i++) // v = {0, 2, 4, 6, 8, 10, 12, ...}
		v[i] = 3 * i;
	c = countCommonElements(u, v, sizeof(u) / sizeof(int), sizeof(v) / sizeof(int)); // Should return?: min[(sizeof(u) / sizeof(int)) / 3 + ((sizeof(u) / sizeof(int)) % 3 == 0 ? 0 : 1) , sizeof(v) / sizeof(int)]
	std::cout << ((((sizeof(u) / sizeof(int)) / 3 + ((sizeof(u) / sizeof(int)) % 3 == 0 ? 0 : 1)) < sizeof(v) / sizeof(int)) ? ((sizeof(u) / sizeof(int)) / 3 + ((sizeof(u) / sizeof(int)) % 3 == 0 ? 0 : 1)) : sizeof(v) / sizeof(int)) << "? " << c << std::endl;

	

	return 0;
}


/*
P: {
	nu = lenght(u) ^
	nu = lenght(v) ^
	nu >= 0 ^
	nv >= 0 ^
	ForAll wu : 0 <= wu < nu - 1 : u[wu] <= u[wu + 1] ^ // u is sorted in ascending order
	ForAll wv : 0 <= wv < nv - 1 : v[wv] <= u[wv + 1] ^ // v is sorted in ascending order
	u[nu - 1] < INT_MAX ^ // Values have to be less than INT_MAX
	v[vu - 1] < INT_MAX   // Values have to be less than INT_MAX
}

*/
int countCommonElements(int u[], int v[], int nu, int nv) {
	return countCommonElements(u, v, nu, nv, std::numeric_limits<int>::max());
}
/*
Q: { // Returned value "r"
	r =
	(# wv : 0 <= wv < nv :
		( Exists wu : 0 <= wu < nu : nu[wu] = nv[wv] )
	)
}
*/



int countCommonElements(int u[], int v[], int nu, int nv, int top) {
	if (nu == 0 || nv == 0) { // When the size of any array is 0, there is no element to compare. Return 0.
		return 0;
	}
	else {
		if		(v[nv - 1] == top)			return countCommonElements(u, v, nu		, nv - 1, top		);		// If the last elemet of the array v is the same as the last element compared, ignore it. Check again with one element less.
		else if	(u[nu - 1] == top)			return countCommonElements(u, v, nu - 1	, nv	, top		);		// The same, but with u
		else if	(v[nv - 1] == u[nu - 1])	return countCommonElements(u, v, nu - 1	, nv - 1, v[nv - 1]	) + 1;	// If the last element of both arrays is the same, check again with one element less in each array, ignoring that last element. The last argument (top) becomes that element. Add one to the result of that "smaller problem" ('tail' recursion broken here).
		else if (v[nv - 1] <  u[nu - 1])	return countCommonElements(u, v, nu - 1	, nv	, top		);		// If the last element in u is greater than the last element in v, check again ignoring the last element in u
		else if	(v[nv - 1] >  u[nu - 1])	return countCommonElements(u, v, nu		, nv - 1, top		);		// The same, but with v
		// It should never come out of the if-else. All cases are taken into account.
	}
}

/*
In ALL recursive calls, at least one of "nv" or "nu" is decreased ==> The size of the problem decreases.
The base case happens when the size of the problem is small enought (at least one array has size 0).
The recursive case takes into account all cases from the last 3 else-if cases, one always happens).

The result of the problem is the result of a smaller problem (at least one of the arrays is smaller), plus one if the result for the current problem is the one checked.

(It is not tail recursion, as in one of the resursive calls, 1 is added after the recursive call)

*/






