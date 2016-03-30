/*	Data Structures and Algorithms: Lab 7
	Alberto Rodríguez - Rabadán Manzanares
	DNI: 71229492 - X
	*/
#include <iostream>
#include "List.h"
using namespace std;

void palindrom(List<int> list);

int main() {
	List<int> list = List<int>();

	list.push_front(1);
	list.push_front(2);
	list.push_front(2);
	list.push_front(1);

	palindrom(list);

	system("pause");
	return 0;
}

void palindrom(List<int> list) {
	List<int>::ConstIterator it = list.cbegin();
	List<int>::ReverseIterator rev_it = list.reverse_begin();
	bool palindrom = true;

	while (it != list.cend() && rev_it != list.reverse_end() && palindrom) 
	{ 
		if (it.elem() == rev_it.elem()) {
			it.next();
			rev_it.next();
		}
		else
			palindrom = false;
	}

	if (palindrom)
		cout << "it is palindrom!" << endl;
	else
		cout << "It is not palindrom!" << endl;
}