using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Pipeline_Winform
{
    class PipelineGridProcessingElement
    {
        private enum ProcType { Shift, SumAndProduct}

        private ProcessingPair procPair;
        private ProcType procType;
        private int rowPosition;
        private int index;

        public PipelineGridProcessingElement(ProcessingPair _procPair, int _index)
        {
            procPair = _procPair;
            procType = ProcType.Shift;
            rowPosition = 0;
            index = _index;
        }

        public void MakeStep()
        {
            if (procType == ProcType.Shift)
            {
                procPair.Shift();

                procType = ProcType.SumAndProduct;
            } else
            {
                procPair.SumProd();
                procType = ProcType.Shift;
            }
            
            rowPosition++;
        }

        public override string ToString()
        {
            string result = "Index: " + index + '\n';

            if (procType == ProcType.SumAndProduct)
            {
                result += "ShSum = " + procPair.ShiftedSumToString();
            } else
            {
                result += "Sum = " + procPair.PartialSumToString() +
                    "\nProd = " + procPair.PartialProductToString();
            }

            return result;
        }
    }
}