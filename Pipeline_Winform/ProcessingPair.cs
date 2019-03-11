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

        private enum ProcType { Shift, SumAndProduct }
        private ProcType procType;
        private int rowPosition;
        private int index;

        public ProcessingPair(BinaryNumber _first, BinaryNumber _second, int _index)
        {
            first = _first;
            second = _second;
            procType = ProcType.SumAndProduct;
            index = _index;

            partialSum = new BinaryNumber(0, BinaryNumber.GetExpandP());
            shiftedSum = new BinaryNumber(0, BinaryNumber.GetExpandP());
            partialProduct = new BinaryNumber(0, BinaryNumber.GetExpandP());
            result = null;

            pCounter = resultClock = 0;
        } // Конструктор обрабатываемой пары

        public ProcessingPair()
        {
            partialSum = new BinaryNumber(0, BinaryNumber.GetExpandP());
            shiftedSum = new BinaryNumber(0, BinaryNumber.GetExpandP());
            partialProduct = new BinaryNumber(0, BinaryNumber.GetExpandP());
            result = null;

            first = new BinaryNumber();
            second = new BinaryNumber();

            procType = ProcType.SumAndProduct;
            pCounter = resultClock = 0;
        }

        public BinaryNumber GetResult() {
		    return result;
	    }

        public int GetResultClock() {
		    return resultClock;
	    }

        public void SetResultClock(int _resultClock)
        {
            resultClock = _resultClock;
        }

        public int GetRowPosition()
        {
            return rowPosition;
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
        
        // Первая операция - сдвиг влево на один разряд
        public void Shift()
        {
            shiftedSum = partialSum.ShiftToLeft();
        }

        // Вторая операция - получение частичных суммы и произведения
        public void SumProd()
        {
            List<bool> secondBinaryNumber = second.GetBinaryNumber();
            
            if (pCounter == secondBinaryNumber.Count)
            {
                result = partialSum;

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

            partialSum = (pCounter == 0) ? (secondBinaryNumber[pCounter] ? BinaryNumber.ToExpandP(first) :
                new BinaryNumber(0, BinaryNumber.GetExpandP())) : BinaryNumber.Sum(shiftedSum, partialProduct);

            pCounter++;
            
            partialProduct = secondBinaryNumber[pCounter] ? BinaryNumber.ToExpandP(first) :
                new BinaryNumber(0, BinaryNumber.GetExpandP());
        }

        public void MakeStep(int _clockCounter)
        {
            if (result != null)
            {
                return;
            }

            if (procType == ProcType.Shift)
            {
                Shift();

                procType = ProcType.SumAndProduct;
            }
            else
            {
                SumProd();

                procType = ProcType.Shift;
            }

            rowPosition++;

            if (rowPosition == Pipeline.countOfSubTasks)
            {
                result = partialSum;
                resultClock = _clockCounter;
            }
        }

        public string TempsToString()
        {
            string result = "Index: " + index + "\n";

            if (procType == ProcType.Shift)
            {
                result += "S: " + ShiftedSumToString();
            }
            else
            {
                result += "S: " + PartialSumToString() +
                    "\nP: " + PartialProductToString();
            }

            return result;
        }

        public override string ToString()
        {
            return result == null ? "" : result.GetSourceNumber().ToString() + ", t = " + resultClock;
        }
    }
}
