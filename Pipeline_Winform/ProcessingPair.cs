using System.Collections.Generic;

namespace Pipeline_Winform
{
    class ProcessingPair
    {
        private BinaryNumber first; // Первое число пары
        private BinaryNumber second; // Второе число пары

        private BinaryNumber partialSum; // Частичная сумма
        private BinaryNumber shiftedSum; // Частичная сумма, сдвинутая на 1 разряд влево
        private BinaryNumber partialProduct; // Частичное произведение
        private int pCounter; // Счетчик разрядов во втором элементе пары

        private BinaryNumber result; // Результат операции
        private int resultClock; // Время получения результата операции

        private bool isResultNull; // Не получен ли результат операции


        public ProcessingPair(BinaryNumber _first, BinaryNumber _second)
        {
            first = _first;
            second = _second;

            partialSum = new BinaryNumber(0, BinaryNumber.GetExpandP());
            shiftedSum = new BinaryNumber(0, BinaryNumber.GetExpandP());
            partialProduct = new BinaryNumber(0, BinaryNumber.GetExpandP());
            result = new BinaryNumber(0, BinaryNumber.GetExpandP());

            pCounter = resultClock = 0;
            isResultNull = true;
        } // Конструктор обрабатываемой пары

        public BinaryNumber GetResult() {
		    return result;
	    }

        public int GetResultClock() {
		    return resultClock;
	    }

        public bool GetIsResultNull() {
		        return isResultNull;
	    }

        public string partialProductToString()
        {
            return partialProduct.ToString();
        }

        public string partialSumToString()
        {
            return partialSum.ToString();
        }

        public string shiftedSumToString()
        {
            return shiftedSum.ToString();
        }

        public string resultToString()
        {
            return result.ToString();
        }

        // Шаг арифметичской операции
        public void makeStep(int _clock)
        {
            if (!isResultNull)
            {
                return;
            }

            List<bool> secondBinaryNumber = second.GetBinaryNumber();

            if (pCounter == secondBinaryNumber.Count)
            {
                result = partialSum;
                resultClock = _clock;
                isResultNull = false;

                return;
            }

            if (pCounter == secondBinaryNumber.Count - 1)
            {
                partialSum = BinaryNumber.Sum(shiftedSum, partialProduct);

                pCounter++;

                partialProduct = new BinaryNumber(0, BinaryNumber.GetExpandP());
                shiftedSum = new BinaryNumber(0, BinaryNumber.GetExpandP());

                return;
            }

            secondBinaryNumber = second.GetBinaryNumber();

            // Первая операция - суммирование предыдущих сдвинутой суммы и частичного произведения
            partialSum = (pCounter == 0) ? (secondBinaryNumber[pCounter] ? BinaryNumber.ToExpandP(first) :
                new BinaryNumber(0, BinaryNumber.GetExpandP())) : BinaryNumber.Sum(shiftedSum, partialProduct);

            pCounter++;

            // Вторая операция - умножение pCounter-го разряда второго элемента пары на первый элемент пары
            partialProduct = secondBinaryNumber[pCounter] ? BinaryNumber.ToExpandP(first) :
                new BinaryNumber(0, BinaryNumber.GetExpandP());

            // Третья операция - сдвиг влево на один разряд
            shiftedSum = partialSum.ShiftToLeft();
        } 
    }
}
