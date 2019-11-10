using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Translation
{
    public class FileStateMachine : StateMachine
    {
        protected Dictionary<string, string> ItoE = new Dictionary<string, string>();

        protected virtual void ProceedQ(string Q)
        {
            foreach (string state in Q.Split(' '))
            {
                this.Q.Add(state.ToUpper());
            }
        }

        protected virtual void ProceedE(string E)
        {
            foreach (string signal in E.Split(' '))
            {
                this.E.Add(signal);
            }
        }

        protected virtual void ProceedS(string S)
        {
            foreach (string state in S.Split(' '))
            {
                this.S.Add(state.ToUpper());
            }
        }

        protected virtual void ProceedF(string F)
        {
            foreach (string state in F.Split(' '))
            {
                this.F.Add(state.ToUpper());
            }
        }

        protected virtual void ProceedD(System.IO.StreamReader sr)
        {
            while (sr.Peek() != -1)
            {
                var Dline = sr.ReadLine().Split(' ');
                if (Dline.Length != 3) continue;
                D.Add(new PairS(Dline[0].ToUpper(),
                    Dline[1]), Dline[2].ToUpper());
            }
            sr.Close();
        }

        protected virtual void ProceedBefore(System.IO.StreamReader sr) { }

        public FileStateMachine(string filename)
        {
            var sr = new System.IO.StreamReader(filename);
            ProceedBefore(sr);

            var Q = sr.ReadLine();
            
            ProceedQ(Q);

            var E = sr.ReadLine();
            ProceedE(E);

            var S = sr.ReadLine();
            ProceedS(S);

            var F = sr.ReadLine();
            ProceedF(F);

            ProceedD(sr);

            ResetState();
        }
    }
}
