/* Лабораторная работа 1 по дисциплине МРЗвИС
	Выполнена студенткой группы 721703
	БГУИР Стрижич Анжелика Олеговна
	Описаны свойства и функционал двоичного числа в виде класса
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class BinaryNumber {
private:
	static const unsigned p = 6; // Разрядность двоичного числа
	static const unsigned expandP = p * 2; // Разрядность двоичного числа при выполнении над ним арифметических операций

	int sourceNumber; // Исходное десятичное число
	vector<bool> binaryNumber; // Исходное двоичное число в векторном представлении

public:
	BinaryNumber(int _sourceNumber = 0, unsigned _p = p) {
		sourceNumber = _sourceNumber;
		binaryNumber = vector<bool>(_p);

		if (sourceNumber < pow(2, _p)) {
			for (auto i = _p - 1; _sourceNumber > 0 && i >= 0; i--) {
				binaryNumber[i] = _sourceNumber % 2;
				_sourceNumber /= 2;
			}
		}
		else {
			*this = BinaryNumber(0, _p);
		}
	} // Конструктор двоичного числа

	int getSourceNumber()const {
		return sourceNumber;
	}

	vector<bool> getBinaryNumber()const {
		return binaryNumber;
	}

	static unsigned getP() {
		return p;
	}

	static unsigned getExpandP() {
		return expandP;
	}

	static BinaryNumber toExpandP(BinaryNumber _binaryNumber, unsigned _expandP = expandP) {
		return BinaryNumber(_binaryNumber.getSourceNumber(), _expandP);
	} // Получение двоичного числа заданной разрядности из исходного

	BinaryNumber shiftToLeft() {
		unsigned bnSize = binaryNumber.size();
		BinaryNumber result(sourceNumber * 2, bnSize);

		return result;
	} // Создание двоичного числа, полученного сдвигом исходного на один разряд влево

	static BinaryNumber sum(BinaryNumber _a, BinaryNumber _b) {
		return BinaryNumber(_a.getSourceNumber() + _b.getSourceNumber(), _a.getBinaryNumber().size());
	} // Получение суммы двух двоичных чисел

	string toString() {
		string result = "";
		unsigned bnSize = binaryNumber.size();
		bool isP = (bnSize == p);
		bool isExpandP = (bnSize == expandP);
		bool isUnexpectedP = !(isP || isExpandP);

		if (isP) {
			for (auto i = 0; i < p - 2; i++) {
				result += binaryNumber[i] ? '1' : '0';
			}
			result += ' ';

			for (auto i = p - 2; i < p; i++) {
				result += binaryNumber[i] ? '1' : '0';
			}
		}

		if (isExpandP) {
			unsigned whiteSpaceTime = 3;

			for (auto i = 0, j = 1; i < expandP; i++, j++) {
				result += binaryNumber[i] ? '1' : '0';

				if (j == whiteSpaceTime) {
					result += ' ';
					j = 0;
				}
			}
		}

		if (isUnexpectedP) {
			for (unsigned i = 0; i < binaryNumber.size(); i++) {
				result += binaryNumber[i] ? '1' : '0';
			}
		}

		return result;
	} // Форматированный вывод двоичного числа
};