using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Translation
{
    class TestSM : StateMachine
    {
        public TestSM()
        {
            Q = new HashSet<string>()
            {
                "alpha",
                "numeric",
                "none"
            };
            E = new HashSet<string>()
            {
                "a", "b",
                "1", "2"
            };
            D = new Dictionary<PairS, string>()
            {
                { new PairS("alpha", "a") , "alpha" },
                { new PairS("alpha", "b") , "alpha" },
                { new PairS("alpha", "1") , "numeric" },
                { new PairS("alpha", "2") , "numeric" },
                { new PairS("numeric", "a") , "alpha" },
                { new PairS("numeric", "b") , "alpha" },
                { new PairS("numeric", "1") , "numeric" },
                { new PairS("numeric", "2") , "numeric" },
            };
            S = new HashSet<string>()
            {
                "alpha"
            };
            F = new HashSet<string>()
            {
                "alpha",
                "numeric"
            };
        }
    }
}
