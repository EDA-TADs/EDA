/*
 * Source.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: DevPGSV
 */

// Needs Deque.h and Exceptions.h

//#define DEV_DEBUG


#include <iostream>
#include "Deque.h"

template <class T>
void printQueueInverse(Deque<T> q) {
	while (q.size() > 0){
		std::cout << " " << q.back();
		q.pop_back();
	}
	std::cout << std::endl;
}

template <class T>
void printQueue(Deque<T> q) {
	while (q.size() > 0){
		std::cout << " " << q.front();
		q.pop_front();
	}
	std::cout << std::endl;
}

int main() {
	int n, step;
	Deque<int> q, q2;
	std::cin >> n;
	while (n != 0) {
		q = Deque<int>();
		for (int i = 1; i <= n; i++) {
			q.push_back(i);
		}
		step = 2;
		#ifdef DEV_DEBUG
		std::cout << "DEBUG q (" << q.size() << ") elem:";
		printQueue(q);
		#endif
		while (step < q.size()) {
			#ifdef DEV_DEBUG
			std::cout << "DEBUG   step: " << step << std::endl;
			#endif
			q2 = Deque<int>();
			int i = 1;
			while (!q.empty()) {
				#ifdef DEV_DEBUG
				std::cout << "DEBUG     chek " << q.front() << std::endl;
				#endif
				if (i % step != 1) {
					q2.push_back(q.front());
					#ifdef DEV_DEBUG
					std::cout << "DEBUG       add " << q.front() << std::endl;
					#endif
				} else {
					#ifdef DEV_DEBUG
					std::cout << "DEBUG       rem " << q.front() << std::endl;
					#endif
				}
				q.pop_front();
				i++;
			}
			q = q2;
			step++;
		}

		std::cout << n << ":";
		printQueueInverse(q);
		std::cin >> n;
	}



	return 0;
}

