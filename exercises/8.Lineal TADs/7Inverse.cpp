#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#include "LinkedListStack.h"

template <class T>
void Invierte(LinkedListStack <T> stack, const int &positions){ //tengo que poner el type aqui ya????? Se puede hacer con listas??

	T *intermedia = new T[positions];
	int i = 0;
	while (!stack.empty() && i<positions){
		intermedia[i] = stack.top();
		stack.pop();
		i++;
	}
	for (int j = 0 ; j <i; j++){
		stack.push(intermedia[j]);
	}
	delete[] intermedia;
}

int main(){
	LinkedListStack<int> stack = LinkedListStack<int>();
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(6);
	stack.push(7);
	Invierte(stack, 3);

	return 0;
}
