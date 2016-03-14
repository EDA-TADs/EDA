#include <iostream>
using namespace std;

#include "Polynomial.h"

int main() {


	Polynomial<int> p1 = Polynomial<int>();
	p1.setElem(0, 1);
	p1.setElem(1, 2);
	p1.setElem(2, 1);

	Polynomial<int> p2 = Polynomial<int>();
	p2.setElem(0, 100);
	p2.setElem(1, 101);
	p2.setElem(2, 100);

	cout << "p1: " << p1 << endl << "p2: " << p2 << endl << endl;

	Polynomial<int> p3 = p1 + p2;
	cout << "p1 + p2: " << p3 << endl;

	Polynomial<int> p4 = p1 - p2;
	cout << "p1 - p2: " << p4 << endl;

	Polynomial<int> p5 = p1 + p2;

	p5.clear();
	cout << "Clear p5!!! p5: "  << p5 << endl;

	p5 = p1;
	cout << "Asign p5 = p1!!! p5 = " << p5 << endl << endl;


	Polynomial<float> pf1 = Polynomial<float>();
	cout << "pf1: " << pf1 << endl << endl;

	Polynomial<char> pc1 = Polynomial<char>();
	pc1.setElem(0, 'A');
	pc1.setElem(1, 'B');
	cout << "pc1: " << pc1 << endl;


	Polynomial<int> pe1 = Polynomial<int>();
	pe1.setElem(0, 1);
	pe1.setElem(1, 2);
	pe1.setElem(2, 1);
	cout << "pe1: " << pe1 << endl;
	cout << "pe1.eval(2): " << pe1.eval(2);

	return 0;
}
