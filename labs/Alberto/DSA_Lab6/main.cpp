/* DSA_Lab7 Alberto Rodríguez - Rabadán Manzanares */

#include <iostream>
#include "Queue.h"
using namespace std;

const int N = 20;

Queue<int> luckyNumbers(int N);

int main() {
	
	luckyNumbers(N);


	system("pause");
	return 0;
}

Queue<int> luckyNumbers(int N) {
	Queue<int> queue = Queue<int>();

	if (N >= 2) {
		// Pushes all the elements to the queue
		for (int i = 1; i <= N; i++)
		{
			queue.push_back(i);
		}

		int m = 1;
		while (m < queue.size()) // Mientras el número de elementos a sacar sea menor que el tamaño, entramos
		{
			int count = 0, j = 0, size;

			size = queue.size();

			// Recorremos la cola
			while (j < size) {
				if (count == 0) { // Sacamos el primer elemento
					queue.pop_front();
					count++;
				}
				else { // Guardamos los elementos siguientes hasta que count sea distinto de m
					queue.push_back(queue.front());
					queue.pop_front();
					if (count == m)
						count = 0;
					else
						count++;
				}
				j++;
			}
			m++;
		}
	}
	return queue;
}