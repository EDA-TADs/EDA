/*Alberto Rodríguez - Rabadán Manzanares DNI: 71229492-X*/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#include "DSA_Lab5.h"

int main() {
	int sol = 2;

	Polynomial<int> p1 = Polynomial<int>();
	p1.setElement(0, 2);
	Polynomial<int> p2 = Polynomial<int>();
	p2.setElement(0, 3);
	p2.setElement(4, 7);
	Polynomial<int> p3 = Polynomial<int>();
	Polynomial<int> p4 = Polynomial<int>();
	p3 = p1 + p2;
	p4 = p3;
	cout << "Polynomial: ";
	p3.print();
	cout << "Solution for x = "	<< sol << " is: " << p3.solution(sol) << endl;
	if (p4 == p3)
		cout << "Ok" << endl;
	p3.destroy();
	cout << "Then destroying it..." << endl;
	p3.print();
	

	system("pause");
	return 0;

}