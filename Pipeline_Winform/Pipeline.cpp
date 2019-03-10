/* ������������ ������ 1 �� ���������� ������
	��������� ���������� ������ 721703
	����� ������� �������� ��������
	������� �������� � ���������� ��������� � ���� ������
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "BinaryNumber.cpp"

using namespace std;

class Pipeline {
private:
	const string NO_PAIR_ERR = "No such pair"; // ����� ��������� �� ���������� ����� ���� �����

	unsigned m; // ���������� �������������� ���
	unsigned t; // ���������� ������ �� ������ ��� ���������
	unsigned n; // ������������ ���������� ����� ���������

	unsigned tCounter; // ������� ������

	vector<BinaryNumber> A; // ������ ������ ��������� ���
	vector<BinaryNumber> B; // ������ ������ ��������� ���

	pair<BinaryNumber, BinaryNumber> processingPair; // �������������� ����
	unsigned processingPairCounter; // ������� �������������� ���
	unsigned pCounter; // ������� �������� �� ������ �������� ����

	BinaryNumber partialSum; // ��������� �����
	BinaryNumber shiftedSum; // ��������� �����, ��������� �� 1 ������ �����
	BinaryNumber partialProduct; // ��������� ������������

	vector<BinaryNumber> C; // �������� ������ ����������� ���������
	vector<unsigned> CClocks; // ������ �������� ������ ��������� �������� ����������� ���������

	bool isWorkCompleted; // ���� ���������� ������ ���������

	void setProcessingPair(unsigned _numberOfPair) {
		processingPair = pair<BinaryNumber, BinaryNumber>(A[_numberOfPair], B[_numberOfPair]);
	} // ���������� �������������� ����

public:
	Pipeline(unsigned _m = 1, vector<BinaryNumber> _A = vector<BinaryNumber>(), vector<BinaryNumber> _B = vector<BinaryNumber>(), unsigned _t = 1, unsigned _n = 1) {
		m = _m;
		t = _t;
		n = _n;

		tCounter = 0;

		A = _A;
		B = _B;

		processingPair = pair<BinaryNumber, BinaryNumber>(A[0], B[0]);
		processingPairCounter = 0;
		pCounter = 0;

		partialSum = BinaryNumber(0, BinaryNumber::getExpandP());
		shiftedSum = BinaryNumber(0, BinaryNumber::getExpandP());
		partialProduct = BinaryNumber(0, BinaryNumber::getExpandP());

		C = vector<BinaryNumber>();
		CClocks = vector<unsigned>();

		isWorkCompleted = false;

	} // ����������� ���������

	unsigned getM()const {
		return m;
	}

	unsigned getTCounter()const {
		return tCounter;
	}

	unsigned getN()const {
		return n;
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

	string pairToString(unsigned _numberOfPair) {
		if (_numberOfPair >= m || _numberOfPair < 0) {
			return NO_PAIR_ERR;
		}

		return A[_numberOfPair].toString() + '\n' + B[_numberOfPair].toString();
	} // ��������������� ������������� ���� �������� �����

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

		for (unsigned i = 0; i < C.size(); i++) {
			result += '[' + to_string(i) + "] " + (_isDecimalRepresent ? to_string(C[i].getSourceNumber()) : C[i].toString()) +
				"\t| clock: " + to_string(getCClock(i)) + '\n';
		}

		return result;
	} // ��������������� ������������� ������ �������� ����������� ���������

	unsigned getCClock(unsigned _numberOfProduct)const {
		return _numberOfProduct < CClocks.size() ? CClocks[_numberOfProduct] : 0;
	}

	bool getIsWorkCompleted()const {
		return isWorkCompleted;
	}

	void tempsToZero() {
		partialProduct = BinaryNumber(0, BinaryNumber::getExpandP());
		partialSum = BinaryNumber(0, BinaryNumber::getExpandP());
		shiftedSum = BinaryNumber(0, BinaryNumber::getExpandP());
		pCounter = 0;
	} // ��������� ������������� ����� � ����

	void makeStep() {
		vector<bool> secondBinaryNumber = processingPair.second.getBinaryNumber();

		if (pCounter == secondBinaryNumber.size()) {
			C.push_back(partialSum);
			CClocks.push_back(tCounter);

			if (++processingPairCounter == m) {
				isWorkCompleted = true;
			}
			else {
				setProcessingPair(processingPairCounter);
			}
			tempsToZero();
			tCounter += t;

			return;
		}

		if (pCounter == secondBinaryNumber.size() - 1) {
			partialSum = BinaryNumber::sum(shiftedSum, partialProduct);
			partialProduct = shiftedSum = BinaryNumber(0, BinaryNumber::getExpandP());
			pCounter++;
			tCounter += t;

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

		tCounter += t;
	} // ��� ���������
};