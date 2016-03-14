/*Alberto Rodríguez - Rabadán Manzanares DNI: 71229492-X*/
const int MAX = 6;

template <class T>
class Polynomial {
private:
	T poly[MAX];
public:
	// Simple Constructor
	Polynomial() {
		for (int i = 0; i < MAX; i++) {
			poly[i] = 0;
		}
	}

	// Mutators
	Polynomial<T> operator+(const Polynomial<T> &poly);
	void operator=(const Polynomial &poly);
	bool operator==(const Polynomial &poly) const;
	int solution(const int &x) const;
	void setElement(int pos, const T &elem);
	void Polynomial<T>::print() const;
	
	// Destructor
	void destroy();

	// Observers
	const T& getElement(int index) const;

};

template <class T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial<T> &poly) {
	Polynomial<T> new_poly;

	for (int i = 0; i < MAX; i++) {
		new_poly.setElement(i, Polynomial<T>::getElement(i) + poly.getElement(i));
	}

	return new_poly;
}

template <class T>
void Polynomial<T>::operator=(const Polynomial &poly) {

	for (int i = 0; i < MAX; i++) {
		Polynomial<T>::setElement(i, poly.getElement(i));
	}

}

template <class T>
bool Polynomial<T>::operator==(const Polynomial &poly) const {
	bool equals = true;

	for (int i = 0; i < MAX; i++) {
		if (Polynomial<T>::getElement(i) != poly.getElement(i))
			equals = false;
	}

	return equals;
}

template <class T>
int Polynomial<T>::solution(const int &x) const {
	int pol = 0;

	for (int i = 0; i < MAX; i++) {
		pol = pol + (poly[i] * pow(x, i));
	}

	return pol;
}

template <class T>
void Polynomial<T>::setElement(int pos, const T &elem) {
	poly[pos] = elem;
}

template <class T>
void Polynomial<T>::print() const {
	cout << poly[0];
	for (int i = 1; i < MAX; i++) {
		cout << " + " << poly[i] << "*x^" << i;
	}
	cout << endl;
}

template <class T>
const T& Polynomial<T>::getElement(int index) const {
	return poly[index];
}

template <class T>
void Polynomial<T>::destroy() {
	for (int i = 0; i < MAX; i++)
	{
		Polynomial<T>::setElement(i, 0);
	}
}