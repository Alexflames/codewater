using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Translation
{
    class FileStateMachine : StateMachine
    {
        public FileStateMachine(string filename)
        {
            var sr = new System.IO.StreamReader(filename);
            var Q = sr.ReadLine();
            foreach (string state in Q.Split(' '))
            {
                this.Q.Add(state.ToUpper());
            }
            var E = sr.ReadLine();
            foreach (string signal in E.Split(' '))
            {
                this.E.Add(signal);
            }
            var S = sr.ReadLine();
            foreach (string state in S.Split(' '))
            {
                this.S.Add(state.ToUpper());
            }
            var F = sr.ReadLine();
            foreach (string state in F.Split(' '))
            {
                this.F.Add(state.ToUpper());
            }

            while (sr.Peek() != -1)
            {
                var Dline = sr.ReadLine().Split(' ');
                if (Dline.Length != 3) continue; 
                D.Add(new PairS(Dline[0].ToUpper(),
                    Dline[1]), Dline[2].ToUpper());
            }
            sr.Close();

            ResetState();
        }
    }
}
