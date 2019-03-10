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
	} // Конструктор двоичного числа

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

	void makeStep(unsigned _clock) {
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
			partialProduct = shiftedSum = BinaryNumber(0, BinaryNumber::getExpandP());
			pCounter++;

			return;
		}

		secondBinaryNumber = second.getBinaryNumber();

		if (pCounter < secondBinaryNumber.size() - 1) {
			partialSum = (pCounter == 0) ? (secondBinaryNumber[pCounter] ? BinaryNumber::toExpandP(first) :
				BinaryNumber(0, BinaryNumber::getExpandP())) : BinaryNumber::sum(shiftedSum, partialProduct);
			partialProduct = secondBinaryNumber[++pCounter] ? BinaryNumber::toExpandP(first) :
				BinaryNumber(0, BinaryNumber::getExpandP());
		}

		shiftedSum = partialSum.shiftToLeft();
	} // Шаг арифметичской операции
};

class Pipeline {
private:
	const string NO_PAIR_ERR = "No such pair"; // Текст сообщения об отсутствии такой пары чисел

	unsigned m; // Количество обрабатываемых пар
	unsigned t; // Количество тактов на каждый шаг конвейера
	unsigned n; // Максимальное количество шагов конвейера

	unsigned clockCounter; // Счетчик тактов

	vector<BinaryNumber> A; // Вектор первых элементов пар
	vector<BinaryNumber> B; // Вектор вторых элементов пар
	vector<ProcessingPair> C; // Итоговый список результатов умножений

	unsigned processingPairCounter; // Счетчик обрабатываемых пар
	vector<ProcessingPair> processingPairs;
	 
	bool isWorkCompleted; // Флаг завершения работы конвейера

public:
	Pipeline(vector<BinaryNumber> _A, vector<BinaryNumber> _B, unsigned _m = 1, unsigned _t = 1, unsigned _n = 1) {
		m = _m;
		t = _t;
		n = _n;

		clockCounter = 0;

		A = _A;
		B = _B;
		C = vector<ProcessingPair>();

		processingPairCounter = 0;
		processingPairs = vector<ProcessingPair>();

		isWorkCompleted = false;

	} // Конструктор конвейера

	unsigned getM()const {
		return m;
	}

	unsigned getClockCounter()const {
		return clockCounter;
	}
	
	unsigned getN()const {
		return n;
	}

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

	string processingPairToString() {
		return pairToString(processingPairCounter);
	}

	string productListToString(bool _isDecimalRepresent = false) {
		string result = "";

		for (unsigned i = 0; i < C.size(); i++) {
			result += '[' + to_string(i) + "] " + (_isDecimalRepresent ? to_string(C[i].getResult().getSourceNumber()) : C[i].resultToString()) +
				"\t\t| clock: " + to_string(C[i].getResultClock()) + '\n';
		}

		return result;
	} // Форматированное представление списка конечных результатов умножения

	bool getIsWorkCompleted()const {
		return isWorkCompleted;
	}

	void makeStep() {		
		if (processingPairCounter < m) {
			processingPairs.push_back(ProcessingPair(A[processingPairCounter], B[processingPairCounter]));
			processingPairCounter++;
		}

		if (!processingPairs[processingPairs.size() - 1].getIsResultNull()) {
			isWorkCompleted = true;
			for (auto i = 0; i < m; i++) {
				C.push_back(processingPairs[i]);
			}
			clockCounter += t;

			return;
		}

		for (auto i = 0; i < processingPairs.size(); i++) {
			processingPairs[i].makeStep(clockCounter);
		}

		clockCounter += t;
	} // Шаг конвейера
};

int main()
{
	int m = 0;
	cout << "Enter 'm' parameter: ";
	cin >> m;
	int t = 0;
	cout << "Enter 't' parameter: ";
	cin >> t;
	int n = 0;
	cout << "Enter 'n' parameter: ";
	cin >> n;

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

	Pipeline pipeline(A, B, m, t, n);

	for (auto i = 0; i < m; i++) {
		cout << "\n[" << i << "] pair:\n" << pipeline.pairToString(i);
	}

	unsigned stepCounter = 0;

	while (true) {
		pipeline.makeStep();

		if (pipeline.getIsWorkCompleted()) {
			cout << "\n\nList of products:";
			cout << '\n' << pipeline.productListToString(1);

			break;
		}

		cout << "\n\n\t\tSTEP " << ++stepCounter;
		cout << "\nClock: " << pipeline.getClockCounter();

		vector<ProcessingPair> procPairs = pipeline.getProcessingPairs();

		for (auto i = 0; i < procPairs.size(); i++) {
			cout << "\n\n----------Processing pair index: " << i;

			cout << "\n\n--------------------Partial sum:";
			cout << '\n' << procPairs[i].partialSumToString();

			cout << "\n\n--------------------Shifted sum:";
			cout << '\n' << procPairs[i].shiftedSumToString();

			cout << "\n\n----------------Partial product:";
			cout << '\n' << procPairs[i].partialProductToString();
		}

		if (stepCounter >= pipeline.getN()) {
			cout << "\n\nThe 'n' parameter is less than count of steps needed, C list is not completely full";
			cout << '\n' << pipeline.productListToString(1);

			break;
		}
	}

	return 0;
}