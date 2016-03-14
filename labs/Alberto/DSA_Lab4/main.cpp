#include <iostream>
using namespace std;

const int n = 16;
int longTableland(int v[], int n, int i);

int main() {
	int v[] = { 0, 7, 3, 3, 3, 1, 5, 4, 4, 4, 4, 0, 5, 1, 2, 2 };
	int i = n - 1;

	cout << longTableland(v, n, i) << endl;

	system("pause");
	return 0;
}

int longTableland(int v[], int n, int i) {
	int x = 0, lenght = 0;

	if (i == 0)
		x = 0;
	else {
		if (v[i] == v[i - 1]) {
			x = longTableland(v, n, i - 1) + 1;
		}
		else {
			n = i;
			lenght = longTableland(v, n, i - 1);
		}
		if (x < lenght) {
			x = lenght;
			lenght = 0;
		}
	}

	return x;
}