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

	static BinaryNumber toExpandP(BinaryNumber _binaryNumber, unsigned _expandP = expandP) {
		return BinaryNumber(_binaryNumber.getSourceNumber(), _expandP);
	}

	BinaryNumber shiftToLeft() {
		unsigned bnSize = binaryNumber.size();
		BinaryNumber result(sourceNumber * 2, bnSize);

		return result;
	}

	static BinaryNumber sum(BinaryNumber _a, BinaryNumber _b) {
		return BinaryNumber(_a.getSourceNumber() + _b.getSourceNumber(), _a.getBinaryNumber().size());
	}

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

class Pipeline {
private:
	const string NO_PAIR_ERR = "No such pair"; // Текст сообщения об отсутствии такой пары чисел

	unsigned m; // Количество обрабатываемых пар
	unsigned clock = 0; // Счетчик тактов
	vector<BinaryNumber> A; // Вектор первых элементов пар
	vector<BinaryNumber> B; // Вектор вторых элементов пар

	pair<BinaryNumber, BinaryNumber> processingPair; // Обрабатываемая пара
	unsigned processingPairCounter = 0; // Счетчик обрабатываемых пар
	unsigned pCounter = 0; // Счетчик разрядов во втором элементе пары

	BinaryNumber partialSum; // Частичная сумма
	BinaryNumber shiftedSum; // Частичная сумма, сдвинутая на 1 разряд влево
	BinaryNumber partialProduct; // Частичное произведение

	vector<BinaryNumber> prodList; // Итоговый список результатов умножений
	 
	bool isWorkCompleted = false; // Флаг завершения работы конвеера

	void setProcessingPair(unsigned _numberOfPair) {
		processingPair = pair<BinaryNumber, BinaryNumber>(A[_numberOfPair], B[_numberOfPair]);
	}

public:
	Pipeline(unsigned _m = 1, vector<BinaryNumber> _A = vector<BinaryNumber>(), vector<BinaryNumber> _B = vector<BinaryNumber>()) {
		m = _m;
		A = _A;
		B = _B;

		processingPair = pair<BinaryNumber, BinaryNumber>(A[0], B[0]);

		partialProduct = BinaryNumber(0, BinaryNumber::getExpandP());
		partialSum = BinaryNumber(0, BinaryNumber::getExpandP());
		shiftedSum = BinaryNumber(0, BinaryNumber::getExpandP());

		prodList = vector<BinaryNumber>();
	}

	unsigned getClock()const {
		return clock;
	}

	unsigned getM()const {
		return m;
	}

	pair<BinaryNumber, BinaryNumber> getProcessingPair()const {
		return processingPair;
	}

	unsigned getProcessingPairCounter()const {
		return processingPairCounter;
	}

	BinaryNumber getPartialProduct()const {
		return partialProduct;
	}

	BinaryNumber getPartialSum()const {
		return partialSum;
	}

	BinaryNumber getShiftedSum()const {
		return shiftedSum;
	}

	bool getIsWorkCompleted()const {
		return isWorkCompleted;
	}

	string pairToString(unsigned _numberOfPair) {
		if (_numberOfPair >= m || _numberOfPair < 0) {
			return NO_PAIR_ERR;
		}

		return A[_numberOfPair].toString() + '\n' + B[_numberOfPair].toString();
	}

	string processingPairToString() {
		return pairToString(processingPairCounter);
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

	string productListToString(bool _isDecimalRepresent = false) {
		string result = "";

		for (unsigned i = 0; i < m; i++) {
			result += (_isDecimalRepresent ? to_string(prodList[i].getSourceNumber()) : prodList[i].toString()) + '\n';
		}

		return result;
	}

	void tempsToZero() {
		partialProduct = BinaryNumber(0, BinaryNumber::getExpandP());
		partialSum = BinaryNumber(0, BinaryNumber::getExpandP());
		shiftedSum = BinaryNumber(0, BinaryNumber::getExpandP());
		pCounter = 0;
	}

	void makeStep() {
		clock++;

		vector<bool> secondBinaryNumber = processingPair.second.getBinaryNumber();		

		if (pCounter == secondBinaryNumber.size()) {
			prodList.push_back(partialSum);

			if (++processingPairCounter == m) {
				isWorkCompleted = true;
			}
			else {
				setProcessingPair(processingPairCounter);
			}
			tempsToZero();

			return;
		}
		
		if (pCounter == secondBinaryNumber.size() - 1) {
			partialSum = BinaryNumber::sum(shiftedSum, partialProduct);
			partialProduct = shiftedSum = BinaryNumber(0, BinaryNumber::getExpandP());
			pCounter++;

			return;
		}

		secondBinaryNumber = processingPair.second.getBinaryNumber();

		if (pCounter < secondBinaryNumber.size() - 1) {
			partialSum = (pCounter == 0) ? (secondBinaryNumber[pCounter] ? BinaryNumber::toExpandP(processingPair.first) :
				BinaryNumber(0, BinaryNumber::getExpandP())) : BinaryNumber::sum(shiftedSum, partialProduct);
			partialProduct = secondBinaryNumber[++pCounter] ? BinaryNumber::toExpandP(processingPair.first) :
				BinaryNumber(0, BinaryNumber::getExpandP());
		}

		shiftedSum = partialSum.shiftToLeft();
	}
};

int main()
{
	int m = 0;
	cout << "Enter 'm' parameter: ";
	cin >> m;

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

	Pipeline pipeline(m, A, B);

	//char toWorkContinue = ' ';

	while (true) {
		pipeline.makeStep();

		cout << "\n\n...STEP " << pipeline.getClock() << "...";

		cout << "\n\n----------Processing pair of numbers";
		cout << '\n' << pipeline.processingPairToString();

		cout << "\n\n----------Partial sum---------------";
		cout << '\n' << pipeline.partialSumToString();

		cout << "\n\n----------Shifted sum---------------";
		cout << '\n' << pipeline.shiftedSumToString();

		cout << "\n\n----------Partial product-----------";
		cout << '\n' << pipeline.partialProductToString();

		//cout << "\n\nEnter any key to continue the pipeline work...";
		//cin >> toWorkContinue;

		if (pipeline.getIsWorkCompleted()) {
			cout << "\nList of products:\n";
			cout << pipeline.productListToString(1);
			break;
		}
	}

	return 0;
}