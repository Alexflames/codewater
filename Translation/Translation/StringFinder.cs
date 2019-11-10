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

    public struct TokenFoundRes
    {
        public string token;
        public string strLeft;
        public TokenFoundRes(string tokenResult, string subString)
        {
            token = tokenResult;
            strLeft = subString;
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


        public static List<TokenFoundRes> MaxToken(File2StateMachine[] A, string str)
        {
            List<TokenFoundRes> results = new List<TokenFoundRes>();
            int k = 0;                         // берем длину макс. токена с k-ой позиции, текущей
            while (k < str.Length) {
                var curLex = "";        // текущая лексема
                int curPr = 0;                   // текущий приоритет
                int m = 0;                       // максимальная длина токена с позиции k
                foreach (var M in A) {
                    StrFinderRes res = MaxString(M, str, k);
                    if (res.found && m < res.m) {
                        curLex = M.Lex;          // класс лексем определенный автоматом M
                        curPr = M.Pr;           // приоритет класса токенов
                        m = res.m;
                    }
                    else if (m == res.m && curPr < M.Pr)
                    {
                        curLex = M.Lex;
                        curPr = M.Pr;
                        m = res.m;
                    }
                    M.ResetState();
                }
                if (m > 0) {
                    results.Add(new TokenFoundRes(curLex, str.Substring(k, m)));
                    k = k + m;
                }
                else if (m == 0)
                {
                    //results.Add(new TokenFoundRes("error", str.Substring(k, 1)));  // ошибка, символ на котором ошибка
                    k = k + 1;
                }

            }
            return results;
        }
    }
}
