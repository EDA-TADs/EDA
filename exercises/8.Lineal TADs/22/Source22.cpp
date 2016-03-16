/*
 * Source22.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: DevPGSV
 */

#include <iostream>
#include <string>
#include "DequeP.h"

const char KEY_FIN = '+';
const char KEY_INICIO = '-';
const char KEY_DERECHA = '*';
const char KEY_IZQUIERDA = 'c1';
const char KEY_SUPR = '3';
const char KEY_DELETE = 'c2';

int main() {
	std::string line;
	while (std::getline(std::cin, line)) {
		DequeP<char> chars = DequeP<char>('|');
		for (int i = 0; i < line.length(); i++) {
			// std::cout << line[i] << std::endl;
			switch(line[i]) {
			case KEY_FIN:
				chars.sendPointerToBack();
				break;
			case KEY_INICIO:
				chars.sendPointerToFront();
				break;
			case KEY_DERECHA:
				chars.movePointerTowardsBack();
				break;
			case KEY_IZQUIERDA:
				chars.movePointerTowardsFront();
				break;
			case KEY_SUPR:
				chars.pop_afterPointer();
				break;
			case KEY_DELETE:
				chars.pop_beforePointer();
				break;
			default:
				chars.push_beforePointer(line[i]);
				break;
			}
		}
		chars.deletePointer();
		while (!chars.empty()) {
			std::cout << chars.front();
			chars.pop_front();
		}
		std::cout << std::endl;
	}
}



