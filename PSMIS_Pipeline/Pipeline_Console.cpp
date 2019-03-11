/* Лабораторная работа 1 по дисциплине МРЗвИС
	Выполнена студенткой группы 721703
	БГУИР Стрижич Анжелика Олеговна
	Разработано консольное приложение с имитацией конвейерной архитектуры для умножения заданного множества пар двоичных чисел 
*/

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
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
	}

	int getSourceNumber()const  {
		return sourceNumber;
	} 

	vector<bool> getBinaryNumber()const  {
		return binaryNumber;
	}

	static unsigned getP() {
		return p;
	}

	static unsigned getExpandP() {
		return expandP;
	}

	// Получение двоичного числа заданной разрядности из исходного
	static BinaryNumber toExpandP(BinaryNumber _binaryNumber, unsigned _expandP = expandP) {
		return BinaryNumber(_binaryNumber.getSourceNumber(), _expandP);
	} 

	// Создание двоичного числа, полученного сдвигом исходного на один разряд влево
	BinaryNumber shiftToLeft() {
		unsigned bnSize = binaryNumber.size();
		BinaryNumber result(sourceNumber * 2, bnSize);

		return result;
	} 

	// Получение суммы двух двоичных чисел
	static BinaryNumber sum(BinaryNumber _a, BinaryNumber _b) {
		return BinaryNumber(_a.getSourceNumber() + _b.getSourceNumber(), _a.getBinaryNumber().size());
	} 

	// Форматированный вывод двоичного числа
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
	} 
};

class ProcessingPair {
private:
	BinaryNumber first; // Первое число пары
	BinaryNumber second; // Второе число пары

	BinaryNumber partialSum; // Частичная сумма
	BinaryNumber shiftedSum; // Частичная сумма, сдвинутая на 1 разряд влево
	BinaryNumber partialProduct; // Частичное произведение
	unsigned pCounter; // Счетчик разрядов во втором элементе пары

	BinaryNumber result; // Результат операции
	unsigned resultClock; // Время получения результата операции

	bool isResultNull; // Не получен ли результат операции
public:
	ProcessingPair(BinaryNumber _first, BinaryNumber _second) {
		first = _first;
		second = _second;

		partialSum = shiftedSum = partialProduct = result = BinaryNumber(0, BinaryNumber::getExpandP());
		pCounter = resultClock = 0;
		isResultNull = true;
	} // Конструктор обрабатываемой пары

	BinaryNumber getResult()const {
		return result;
	}

	unsigned getResultClock()const {
		return resultClock;
	}

	bool getIsResultNull()const {
		return isResultNull;
	}

	string partialProductToString() {
		return partialProduct.toString();
	}

	string partialSumToString() {
		return partialSum.toString();
	}

	string shiftedSumToString() {
		return shiftedSum.toString();
	}

	string resultToString() {
		return result.toString();
	}

	// Первая операция - получение частичной суммы и частичного произведения
	void sumAndMultiply(unsigned _clock) {
		if (!isResultNull) {
			return;
		}

		vector<bool> secondBinaryNumber = second.getBinaryNumber();

		if (pCounter == secondBinaryNumber.size()) {
			result = partialSum;
			resultClock = _clock;
			isResultNull = false;

			return;
		}

		if (pCounter == secondBinaryNumber.size() - 1) {
			partialSum = BinaryNumber::sum(shiftedSum, partialProduct);

			pCounter++;

			partialProduct = BinaryNumber(0, BinaryNumber::getExpandP());
			shiftedSum = BinaryNumber(0, BinaryNumber::getExpandP());

			return;
		}

		secondBinaryNumber = second.getBinaryNumber();

		partialSum = (pCounter == 0) ? (secondBinaryNumber[pCounter] ? BinaryNumber::toExpandP(first) :
			BinaryNumber(0, BinaryNumber::getExpandP())) : BinaryNumber::sum(shiftedSum, partialProduct);

		pCounter++;

		partialProduct = secondBinaryNumber[pCounter] ? BinaryNumber::toExpandP(first) :
			BinaryNumber(0, BinaryNumber::getExpandP());
	}

	// Вторая операция - сдвиг влево на один разряд
	void shiftLeft() {
		shiftedSum = partialSum.shiftToLeft();
	}
};

class Pipeline {
private:
	const string NO_PAIR_ERR = "No such pair"; // Текст сообщения об отсутствии такой пары чисел

	unsigned m; // Количество обрабатываемых пар
	unsigned t; // Количество тактов на каждый шаг конвейера

	unsigned clockCounter; // Счетчик тактов

	vector<BinaryNumber> A; // Вектор первых элементов пар
	vector<BinaryNumber> B; // Вектор вторых элементов пар
	vector<ProcessingPair> C; // Итоговый список результатов умножений

	unsigned processingPairCounter; // Счетчик обрабатываемых пар
	vector<ProcessingPair> processingPairs; // Текущие обрабатываемые пары
	 
	bool isWorkCompleted; // Флаг завершения работы конвейера

public:
	Pipeline(vector<BinaryNumber> _A, vector<BinaryNumber> _B, unsigned _m = 1, unsigned _t = 1) {
		m = _m;
		t = _t;
		//n = _n;

		clockCounter = 0;

		A = _A;
		B = _B;
		C = vector<ProcessingPair>();

		processingPairCounter = 0;
		processingPairs = vector<ProcessingPair>();

		isWorkCompleted = false;

	}

	unsigned getM()const {
		return m;
	}

	unsigned getClockCounter()const {
		return clockCounter;
	}
	
	/*unsigned getN()const {
		return n;
	}*/

	unsigned getProcessingPairCounter()const {
		return processingPairCounter;
	}

	vector<ProcessingPair> getProcessingPairs()const {
		return processingPairs;
	}

	string pairToString(unsigned _numberOfPair) {
		if (_numberOfPair >= m || _numberOfPair < 0) {
			return NO_PAIR_ERR;
		}

		return A[_numberOfPair].toString() + '\n' + B[_numberOfPair].toString();
	} // Форматированное представление пары двоичных чисел

	// Форматированное представление списка конечных результатов умножения
	string productListToString(bool _isDecimalRepresent = false) {
		string result = "";

		for (unsigned i = 0; i < C.size(); i++) {
			result += '[' + to_string(i) + "] " + (_isDecimalRepresent ? to_string(C[i].getResult().getSourceNumber()) : C[i].resultToString()) +
				"\t\t| clock: " + to_string(C[i].getResultClock()) + '\n';
		}

		return result;
	} 

	bool getIsWorkCompleted()const {
		return isWorkCompleted;
	}

	// Шаг конвейера
	void makeStep() {	
		for (auto i = 0; i < processingPairs.size(); i++) {
			processingPairs[i].shiftLeft();
		}

		if (processingPairCounter < m) {
			processingPairs.push_back(ProcessingPair(A[processingPairCounter], B[processingPairCounter]));
			processingPairCounter++;
		}		

		for (auto i = 0; i < processingPairs.size(); i++) {
			processingPairs[i].sumAndMultiply(clockCounter);
		}

		clockCounter += t;

		checkResults();
	}

	void checkResults() {
		if (!processingPairs[processingPairs.size() - 1].getIsResultNull()) {
			isWorkCompleted = true;
			for (auto i = 0; i < m; i++) {
				C.push_back(processingPairs[i]);
			}
		}
	}
};

int main()
{
	int m = 0;
	cout << "Enter 'm' parameter: ";
	cin >> m;
	int t = 0;
	cout << "Enter 't' parameter: ";
	cin >> t;

	fflush(stdin);

	int a = 0;
	int b = 0;

	vector<BinaryNumber> A;
	vector<BinaryNumber> B;

	for (auto i = 0; i < m; i++) {
		cout << "\nEnter a pair of decimal numbers: ";
		
		cin >> a >> b;
		A.push_back(BinaryNumber(a));
		B.push_back(BinaryNumber(b));
	}

	fflush(stdin);
	system("cls");

	Pipeline pipeline(A, B, m, t);

	for (auto i = 0; i < m; i++) {
		cout << "\n[" << i << "] pair:\n" << pipeline.pairToString(i);
	}

	unsigned stepCounter = 0;

	string stage = "Partial sum\t\tShift & product\t\t";
	cout << "\n\n\tClock\tIndex\t" << stage << stage << stage << stage << stage << stage;

	while (stepCounter < BinaryNumber::getExpandP()) {
		pipeline.makeStep();

		if (pipeline.getIsWorkCompleted()) {
			cout << "\n\nList of products:";
			cout << '\n' << pipeline.productListToString(1);

			break;
		}

		cout << "\n\t" << pipeline.getClockCounter();

		vector<ProcessingPair> procPairs = pipeline.getProcessingPairs();

		for (auto i = 0; i < procPairs.size(); i++) {
			if (!procPairs[i].getIsResultNull()) {
				continue;
			}

			cout << "\n\t\t" << i;

			cout << "\t" << procPairs[i].partialSumToString();

			cout << "\t" << procPairs[i].shiftedSumToString();

			cout << "\t" << procPairs[i].partialProductToString();
		}

		stepCounter++;
	}

	return 0;
}