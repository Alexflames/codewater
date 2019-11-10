using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Translation
{
    public class File2StateMachine : FileStateMachine
    {
        public string Lex = "";
        public int Pr = 0;

        protected override void ProceedE(string E)
        {
            foreach (string input in E.Split(';'))
            {
                var inputSplitted = input.Split(' ');
                var signalName = inputSplitted[0];
                for (int i = 0; i < inputSplitted.Length; i++)
                {
                    if (i == 0) continue;
                    ItoE.Add(inputSplitted[i], signalName);
                }
                this.E.Add(signalName);
            }
        }

        public override string NextState(string input)
        {
            if (!ItoE.ContainsKey(input))
            {
                State = "BROKE";
                return State;
            }
            var signal = ItoE[input];
            return base.NextState(signal);
        }

        protected override void ProceedBefore(StreamReader sr)
        {
            var info = sr.ReadLine().Split(' ');
            Lex = info[0];
            Pr = int.Parse(info[1]);
        }

        public File2StateMachine(string filename) : base(filename) {

        }

    }
}
