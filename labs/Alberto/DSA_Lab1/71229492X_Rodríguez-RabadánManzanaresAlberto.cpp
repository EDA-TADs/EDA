/* Specification
	{ (l1 >= l2 >= 0) && (lenght(V1) >= length(V2)) } 
	bool subString(inout char v1[], v2[], in int l1, l2) return found
	{ ∀j: 0 <= j < l2 : (∃i: 0 <= i < l1: V[i] = V[j])  }
	
*/

#include <iostream>
using namespace std;

const int l1 = 10, l2 = 5;
bool subString(char v1[], char v2[], const int l1, const int l2);

int main()
{   //Correct substring
	char v1[l1] = { 'a', 'w', 'd', 'w', 'w', 'o', 'r', 'k', 's', 'm'};
	char v2[l2] = {'w', 'o', 'r', 'k', 's'};
	//Incorrect substring
	//char v1[l1] = { 'a', 'w', 'd', 'w', 'w', 'o', 'r', 'r', 's', 'm'};
	//char v2[l2] = { 'w', 'o', 'r', 'k', 's' };

	cout << subString(v1, v2, l1, l2) << endl; //Prints 1 if it works, 0 if not.

	system("pause");
	return 0;
}

bool subString(char v1[], char v2[], const int l1, const int l2) {
	bool found = false;
	int i = 0;
	int j = 0;

	while (!found && (i < l1)) {
		if ((v2[j] == v1[i]) && (j < l2)) {
			if (j == l2 - 1)
				found = true;
			else if (v2[j + 1] == v1[i + 1]) {
				i++;
				j++;
			}
			else
				i++;
		}
		else {
			if (j != 0)
			j = 0;

			i++;
		}
	}

	return found;
}