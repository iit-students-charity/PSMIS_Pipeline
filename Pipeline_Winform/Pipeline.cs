using System.Collections.Generic;

namespace Pipeline_Winform
{
    class Pipeline
    {
        private const string NO_PAIR_ERR = "No such pair"; // Текст сообщения об отсутствии такой пары чисел

        private int m; // Количество обрабатываемых пар
        private int t; // Количество тактов на каждый шаг конвейера
        private int n; // Максимальное количество шагов конвейера

        private int tCounter; // Счетчик тактов

        private List<BinaryNumber> A; // Вектор первых элементов пар
        private List<BinaryNumber> B; // Вектор вторых элементов пар

        private (BinaryNumber, BinaryNumber) processingPair; // Обрабатываемая пара
        private int processingPairCounter; // Счетчик обрабатываемых пар
        private int pCounter; // Счетчик разрядов во втором элементе пары

        private BinaryNumber partialSum; // Частичная сумма
        private BinaryNumber shiftedSum; // Частичная сумма, сдвинутая на 1 разряд влево
        private BinaryNumber partialProduct; // Частичное произведение

        private List<BinaryNumber> C; // Итоговый список результатов умножений
        private List<int> CClocks; // Список тактовых времен получения конечных результатов умножений

        private bool isWorkCompleted; // Флаг завершения работы конвейера

        private void SetProcessingPair(int _numberOfPair)
        {
            processingPair = (A[_numberOfPair], B[_numberOfPair]);
        } // Установить обрабатываемую пару


        public Pipeline(List<BinaryNumber> _A, List<BinaryNumber> _B, int _m = 1, int _n = 1, int _t = 1)
        {
            m = _m;
            t = _t;
            n = _n;

            tCounter = 0;

            A = _A;
            B = _B;

            processingPair = (A[0], B[0]);
            processingPairCounter = 0;
            pCounter = 0;

            partialSum = new BinaryNumber(0, BinaryNumber.GetExpandP());
            shiftedSum = new BinaryNumber(0, BinaryNumber.GetExpandP());
            partialProduct = new BinaryNumber(0, BinaryNumber.GetExpandP());

            C = new List<BinaryNumber>();
            CClocks = new List<int>();

            isWorkCompleted = false;

        } // Конструктор конвейера

        public int GetM() {
		return m;
	    }

        public int GetTCounter() {
		    return tCounter;
	    }

        public int GetN() {
		    return n;
	    }

        public (BinaryNumber, BinaryNumber) GetProcessingPair() {
		    return processingPair;
	    }

        public int GetProcessingPairCounter() {
		    return processingPairCounter;
	    }

        public BinaryNumber GetPartialProduct() {
		    return partialProduct;
	    }

        public BinaryNumber GetPartialSum() {
		    return partialSum;
	    }

        public BinaryNumber GetShiftedSum() {
		    return shiftedSum;
	    }

        public string PairToString(int _numberOfPair)
        {
            if (_numberOfPair >= m || _numberOfPair < 0)
            {
                return NO_PAIR_ERR;
            }

            return A[_numberOfPair].ToString() + '\n' + B[_numberOfPair].ToString();
        } // Форматированное представление пары двоичных чисел

        public string ProcessingPairToString()
        {
            return PairToString(processingPairCounter);
        }

        public string PartialProductToString()
        {
            return partialProduct.ToString();
        }

        public string PartialSumToString()
        {
            return partialSum.ToString();
        }

        public string ShiftedSumToString()
        {
            return shiftedSum.ToString();
        }

        public int GetCClock(int _numberOfProduct) {
		    return _numberOfProduct < CClocks.Count ? CClocks[_numberOfProduct] : 0;
	    }

        public bool GetIsWorkCompleted() {
		    return isWorkCompleted;
	    }

        public void tempsToZero()
        {
            partialProduct = new BinaryNumber(0, BinaryNumber.GetExpandP());
            partialSum = new BinaryNumber(0, BinaryNumber.GetExpandP());
            shiftedSum = new BinaryNumber(0, BinaryNumber.GetExpandP());
            pCounter = 0;
        } // Установка промежуточных полей в ноль

        public void makeStep()
        {
            List<bool> secondBinaryNumber = processingPair.Item2.GetBinaryNumber();

            if (pCounter == secondBinaryNumber.Count)
            {
                C.Add(partialSum);
                CClocks.Add(tCounter);

                if (++processingPairCounter == m)
                {
                    isWorkCompleted = true;
                }
                else
                {
                    SetProcessingPair(processingPairCounter);
                }
                tempsToZero();
                tCounter += t;

                return;
            }

            if (pCounter == secondBinaryNumber.Count - 1)
            {
                partialSum = BinaryNumber.Sum(shiftedSum, partialProduct);
                partialProduct = shiftedSum = new BinaryNumber(0, BinaryNumber.GetExpandP());
                pCounter++;
                tCounter += t;

                return;
            }

            secondBinaryNumber = processingPair.Item2.GetBinaryNumber();

            if (pCounter < secondBinaryNumber.Count - 1)
            {
                partialSum = (pCounter == 0) ? (secondBinaryNumber[pCounter] ? BinaryNumber.ToExpandP(processingPair.Item1) :
                    new BinaryNumber(0, BinaryNumber.GetExpandP())) : BinaryNumber.Sum(shiftedSum, partialProduct);
                partialProduct = secondBinaryNumber[++pCounter] ? BinaryNumber.ToExpandP(processingPair.Item1) :
                    new BinaryNumber(0, BinaryNumber.GetExpandP());
            }

            shiftedSum = partialSum.ShiftToLeft();

            tCounter += t;
        } // Шаг конвейера
    }
}
