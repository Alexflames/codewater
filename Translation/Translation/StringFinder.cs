using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Translation
{
    public struct StrFinderRes
    {
        public bool found;
        public int m;
        public StrFinderRes(bool resultFound, int maxStringLength)
        {
            found = resultFound;
            m = maxStringLength;
        }
    }

    public static class StringFinder
    {
        /// <summary>
        /// Finds the maximum string length to be fit into State Machine
        /// </summary>
        /// <param name="A">State Machine</param>
        /// <param name="str">String to be passed to SM</param>
        /// <param name="l">Pass string from this position</param>
        /// <returns>Pair: boolean, int</returns>
        public static StrFinderRes MaxString(StateMachine A, string str, int l = 0)
        {
            bool flag = false;
            int m = 0, i = l;
            if (A.isFinalState()) {
                flag = true;
            }
            var state = A.GetState();
            while (i < str.Length && A.GetState() != "BROKE")
            {
                state = A[str[i].ToString()]; // если undeterm. то нужно обновить множество, пересечение наверное
                if (A.isFinalState()) {
                    flag = true; // при undeterm. если в множестве хотя б одно есть
                    m = i - l + 1;
                }
                i++;
            }
            
            return new StrFinderRes(flag, m);
        }
    }
}
