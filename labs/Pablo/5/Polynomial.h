
#include <string>
#include <iostream>
#include <math.h>


const int MAX = 20;

class DegreeTooBigExc {};

template <class Type>
class Polynomial {
private:
	Type _pol[MAX];
	//int _lenght;
public:

	Polynomial() {
		for (int i = 0; i < MAX; i++) {
			_pol[i] = 0;
		}
	}

	~Polynomial() {
		// Nothing to do. Static memory does not need to be freed.
	}

	// Friend << operator
	template <class T> friend ostream& operator<<(ostream& os, const Polynomial<T>& pol);


	// Observers
	Type getElem(int elem) const;
	int getMaxGr() const;
	Polynomial<Type> operator+ (const Polynomial<Type> &pol) const;
	Polynomial<Type> operator- (const Polynomial<Type> &pol) const;
	bool operator== (const Polynomial<Type> &pol) const;
	void print() const;
	Type eval (Type val) const;

	// Mutators
	Polynomial<Type> operator= (const Polynomial<Type> &pol);
	void clear();
	void setElem(int elem, const Type &element);
};

template <class T>
ostream& operator<<(ostream& os, const Polynomial<T>& pol) {

	cout << pol.getElem(0);

	for (int i = 1; i < MAX; i++) {
		if (pol.getElem(i) != 0)
			cout << " + " << pol.getElem(i) << "*x^" << i;
	}

    return os;
}

template <class Type>
Type Polynomial<Type>::eval(Type val) const {
	Type total = 0;
	for (int i = 1; i < MAX; i++) {
		total += _pol[i] * pow(val, i);
	}
	return total;
}

template <class Type>
Type Polynomial<Type>::getElem(int elem) const {
	if (elem >= MAX) throw DegreeTooBigExc();
	return _pol[elem];
}

template <class Type>
int Polynomial<Type>::getMaxGr() const {
	for (int i = MAX; i > 0; i--) {
		if (_pol[i] != 0)
			return i;
	}
	return -1;
}

template <class Type>
void Polynomial<Type>::print() const {
	cout << _pol[0];

	for (int i = 1; i < MAX; i++) {
		if (_pol[i] != 0)
			cout << " + " << _pol[i] << "*x^" << i;
	}
	cout << endl;
}


template <class Type>
Polynomial<Type> Polynomial<Type>::operator+ (const Polynomial<Type> &pol) const {
	Polynomial<Type> sum = Polynomial<Type>();
	for (int i = 0; i < MAX; i++) {
		sum.setElem(i, _pol[i] + pol.getElem(i));
	}

	return sum;
}

template <class Type>
bool Polynomial<Type>::operator== (const Polynomial<Type> &pol) const {

	for (int i = 0; i < MAX; i++) {
		if (_pol[i] != pol.getElem(i)) {
			return false;
		}
	}
	return true;
}

template <class Type>
Polynomial<Type> Polynomial<Type>::operator- (const Polynomial<Type> &pol) const {
	Polynomial<Type> diff = Polynomial<Type>();
	for (int i = 0; i < MAX; i++) {
		diff.setElem(i, _pol[i] - pol.getElem(i));
	}

	return diff;
}

template <class Type>
Polynomial<Type> Polynomial<Type>::operator= (const Polynomial<Type> &pol) {
	Polynomial<Type> diff = Polynomial<Type>();
	for (int i = 0; i < MAX; i++) {
		_pol[i] = pol.getElem(i);
	}

	return diff;
}


template <class Type>
void Polynomial<Type>::clear() {
	for (int i = 0; i < MAX; i++) {
		_pol[i] = 0;
	}
}

template <class Type>
void Polynomial<Type>::setElem(int elem, const Type &element) {
	_pol[elem] = element;
}

