using System;
using System.Collections.Generic;

namespace Pipeline_Winform
{
    class BinaryNumber
    {
        private const int p = 6; // Разрядность двоичного числа
        private const int expandP = p * 2; // Разрядность двоичного числа при выполнении над ним арифметических операций

        private int sourceNumber; // Исходное десятичное число
        private List<bool> binaryNumber; // Исходное двоичное число в векторном представлении

        
        public BinaryNumber(int _sourceNumber = 0, int _p = p)
        {
            sourceNumber = _sourceNumber;
            binaryNumber = new List<bool>(_p);
            for (int i = 0; i < _p; i++)
            {
                binaryNumber.Add(false);
            }

            if (sourceNumber < Math.Pow(2, _p))
            {
                for (int i = _p - 1; _sourceNumber > 0 && i >= 0; i--)
                {
                    binaryNumber[i] = (_sourceNumber % 2 == 1);
                    _sourceNumber /= 2;
                }
            }
            else
            {
                sourceNumber = 0;
                for (int i = _p - 1; _sourceNumber > 0 && i >= 0; i--)
                {
                    binaryNumber[i] = false;
                }
            }
        } // Конструктор двоичного числа

        public int GetSourceNumber() {
		    return sourceNumber;
	    }

        public List<bool> GetBinaryNumber() {
		    return binaryNumber;
	    }

        public static int GetP()
        {
            return p;
        }

        public static int GetExpandP()
        {
            return expandP;
        }

        public static BinaryNumber ToExpandP(BinaryNumber _binaryNumber, int _expandP = expandP)
        {
            return new BinaryNumber(_binaryNumber.GetSourceNumber(), _expandP);
        } // Получение двоичного числа заданной разрядности из исходного

        public BinaryNumber ShiftToLeft()
        {
            int bnSize = binaryNumber.Count;

            return new BinaryNumber(sourceNumber * 2, bnSize); ;
        } // Создание двоичного числа, полученного сдвигом исходного на один разряд влево

        public static BinaryNumber Sum(BinaryNumber _a, BinaryNumber _b)
        {
            return new BinaryNumber(_a.GetSourceNumber() + _b.GetSourceNumber(), _a.GetBinaryNumber().Count);
        } // Получение суммы двух двоичных чисел

        override public string ToString()
        {
            string result = "";
            int bnSize = binaryNumber.Count;
            bool isP = (bnSize == p);
            bool isExpandP = (bnSize == expandP);
            bool isUnexpectedP = !(isP || isExpandP);

            if (isP)
            {
                for (int i = 0; i < p - 2; i++)
                {
                    result += binaryNumber[i] ? '1' : '0';
                }
                result += ' ';

                for (int i = p - 2; i < p; i++)
                {
                    result += binaryNumber[i] ? '1' : '0';
                }
            }

            if (isExpandP)
            {
                uint whiteSpaceTime = 3;

                for (int i = 0, j = 1; i < expandP; i++, j++)
                {
                    result += binaryNumber[i] ? '1' : '0';

                    if (j == whiteSpaceTime)
                    {
                        result += ' ';
                        j = 0;
                    }
                }
            }

            if (isUnexpectedP)
            {
                for (int i = 0; i < binaryNumber.Count; i++)
                {
                    result += binaryNumber[i] ? '1' : '0';
                }
            }

            return result;
        } // Форматированный вывод двоичного числа
    }
}
