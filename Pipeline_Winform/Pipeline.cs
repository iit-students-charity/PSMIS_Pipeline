using System.Collections.Generic;

namespace Pipeline_Winform
{
    class Pipeline
    {
        private const string NO_PAIR_ERR = "No such pair"; // Текст сообщения об отсутствии такой пары чисел

        private int m; // Количество обрабатываемых пар
        private int t; // Количество тактов на каждый шаг конвейера
        private int n; // Максимальное количество шагов конвейера

        private int clockCounter; // Счетчик тактов

        private List<BinaryNumber> A; // Вектор первых элементов пар
        private List<BinaryNumber> B; // Вектор вторых элементов пар
        private List<ProcessingPair> C; // Итоговый список результатов умножений

        private int processingPairCounter; // Счетчик обрабатываемых пар
        private List<ProcessingPair> processingPairs;

        private bool isWorkCompleted; // Флаг завершения работы конвейера

        public Pipeline(List<BinaryNumber> _A, List<BinaryNumber> _B, int _m = 1, int _n = 1, int _t = 1)
        {
            m = _m;
            t = _t;
            n = _n;

            clockCounter = 0;

            A = _A;
            B = _B;
            C = new List<ProcessingPair>();

            processingPairCounter = 0;
            processingPairs = new List<ProcessingPair>();

            isWorkCompleted = false;

        } // Конструктор конвейера

        public int GetM() {
		return m;
	    }

        public int GetClockCounter() {
		    return clockCounter;
	    }

        public int GetN() {
		    return n;
	    }

        public int GetProcessingPairCounter() {
		    return processingPairCounter;
	    }

        List<ProcessingPair> GetProcessingPairs() {
		    return processingPairs;
	    }

        public string PairToString(int _numberOfPair)
        {
            if (_numberOfPair >= m || _numberOfPair < 0)
            {
                return NO_PAIR_ERR;
            }

            return A[_numberOfPair].ToString() + '\n' + B[_numberOfPair].ToString();
        } // Форматированное представление пары двоичных чисел

        public bool GetIsWorkCompleted() {
		    return isWorkCompleted;
	    }

        public void makeStep()
        {
            if (processingPairCounter < m)
            {
                processingPairs.Add(new ProcessingPair(A[processingPairCounter], B[processingPairCounter]));
                processingPairCounter++;
            }

            if (!processingPairs[processingPairs.Count - 1].GetIsResultNull())
            {
                isWorkCompleted = true;
                for (int i = 0; i < m; i++)
                {
                    C.Add(processingPairs[i]);
                }
                clockCounter += t;

                return;
            }

            for (int i = 0; i < processingPairs.Count; i++)
            {
                processingPairs[i].makeStep(clockCounter);
            }

            clockCounter += t;
        } // Шаг конвейера
    }
}
