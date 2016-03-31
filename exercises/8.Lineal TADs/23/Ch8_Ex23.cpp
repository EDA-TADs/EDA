/* Data Structures and Algorithms: Exercise 23
   Alberto Rodríguez - Rabadán Manzanares
*/
#include <iostream>
#include "Deque.h"
using namespace std;

const int N = 6;

void minimumValues(int v[], int k);

int main() {
	int v[N] = { 1, 3, 2, 5, 8, 5 };

	minimumValues(v, 3);

	system("pause");
	return 0;
}
 
//--------------------Linear solution----------------------
void minimumValues(int v[], int k) {
	Deque<int> d = Deque<int>(); // In the queue I store positions, no elements

	for (int i = 0; i < N; i++)
	{
		if (i >= k) // Until we have not consider a subarray, we can not print the minimums.
			cout << v[d.front()] << " ";

		while (!d.empty() && v[d.back()] >= v[i]) { // While the queue is not empty and the element I want to insert is
												   // greater or equal than the last one I extract the last element
			d.pop_back();
		}
		d.push_back(i); // I insert the new element

		if (d.front() <= i - k) //This remove the minimum once is out of the subarray
			d.pop_front();
	}
	cout << v[d.front()] << endl;
}

//-------------This is a non-linear solution-----------------
//int min;
//int i = 0;
//while (i + k <= N)
//{
//	min = v[i];
//	for (int j = i; j < i + 3; j++)
//	{
//		if (v[j] < min)
//			min = v[j];
//	}
//	cout << min;
//	i++;
//}
//cout << endl;