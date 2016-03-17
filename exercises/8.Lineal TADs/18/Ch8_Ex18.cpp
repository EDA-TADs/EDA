#include <iostream>
#include "Queue.h"
using namespace std;

int selection(int n);

const int n = 15;

int main() {
	
	cout << selection(n) << endl;

	system("pause");
	return 0;
}

int selection(int n) {
	int selected;
	Queue<int> queue = Queue<int>();

	for (int i = 1; i <= n; i++)
	{
		queue.push_back(i);
	}

	int count = 0;
	while (queue.size() > 1) {
		if (count == 0) {
			queue.pop_front();
			count++;
		}
		else {
			queue.push_back(queue.front());
			queue.pop_front();
			count = 0;
		}
	}
	selected = queue.front();

	return selected;
}