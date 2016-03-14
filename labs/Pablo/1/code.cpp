
#include <iostream>
#include <string>
using namespace std;


bool subString(char v1[], char v2[], int l1, int l2);

int main() {
	const int MAX_LENGHT = 16;
	char testString[MAX_LENGHT];
	string testSubString = "";
	int testStringLenght = 0, testSubStringLenght = 0;
	static const char characters[] = "123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	
	for (int i = 0; i < 5000; i++) { // Number of tests

		// Create a random string (5 to 16 chars)
		testStringLenght = 5 + rand() % (MAX_LENGHT - 5);
		for (int i = 0; i < testStringLenght; ++i) {
			testString[i] = characters[rand() % (sizeof(characters) - 1)];
		}

		// Create substring from string
		testSubString = string(testString).substr(rand() % 3, testStringLenght - 1 - rand() % 2);
		testSubStringLenght = testSubString.length();

		// It should be true:
		cout << string(testString).substr(0, testStringLenght) << " --- " << testSubString.substr(0, testSubStringLenght) << ": true? " << (subString(testString, &testSubString[0u], testStringLenght, testSubStringLenght) ? "true" : "false !!!!!!!!!!!!!!");
		cout << endl;

		// It should be false:
		testSubString[rand() % (sizeof(testSubStringLenght) - 1)] = '0';
		cout << string(testString).substr(0, testStringLenght) << " --- " << testSubString.substr(0, testSubStringLenght) << ": false? " << (subString(testString, &testSubString[0u], testStringLenght, testSubStringLenght) ? "true !!!!!!!!!!!!!!" : "false");
		cout << endl;
	}
	return 0;
}




// Order: in the worst case: cuadratic
// P =   {l1 = lenght(v1) ^ l2 = lenght(v2) ^ l1 => l2 >= 0}
bool subString(char v1[], char v2[], int l1, int l2) {
	bool found = false;
	int i = 0, j = 0;
	while (i < l1 && !found) { // Loop chars in v1
		j = 0;
		while (j < l2 && (v1[i + j] == v2[j])) { // Loop chars in v2
			j++;
		}
		if (j == l2) found = true;
		i++;
	}
	return found;
}

// Q = {E i, j : 0 <= i < l1 ^ 0 <= j < l2 : V w : 0 <= }....
// Exists i and j; i going from 0 (inclusive) to l1 and j going from 0 (inclusive) to l2; then for all w; goinf from 0
