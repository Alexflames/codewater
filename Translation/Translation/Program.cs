using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Translation
{
    class Program
    {
        public static string ReadFile(string filename)
        {
            string text = "";

            if (System.IO.File.Exists(filename))
            {
                System.IO.StreamReader objReader = new System.IO.StreamReader(filename);
                do
                {
                    text = text + objReader.ReadLine() + " ";
                } while (objReader.Peek() != -1);
            }
            else
            {
                throw new Exception("Файл не существует");
            }

            return text;
        }

        static void Main(string[] args)
        {
            var SM = new File2StateMachine("TestSM2.txt");
            var SMint = new File2StateMachine("intSM.txt");
            var A = new File2StateMachine[2];
            A[0] = SM; A[1] = SMint;

            List<string> numbers = new List<string>();
            string input = ReadFile("input1.txt");
            string output = "";
            int i = 0;
            //while (i < input.Length)
            //{
            //    var res = StringFinder.MaxString(SM, input, i);
            //    if (res.found)
            //    {
            //        numbers.Add(input.Substring(i, res.m));
            //        i = i + Math.Max(res.m, 1);
            //    }
            //    else i++;
            //    SM.ResetState();
            //}
            var answers = StringFinder.MaxToken(A, input);
            foreach (var token in answers)
            {
                output = output + token.token + " " + token.strLeft + "\n";
            }
            Console.Write(output);
            var objWriter = new System.IO.StreamWriter("output1.txt");
            objWriter.WriteLine(output);
            objWriter.Close();
            return;
        }
    }
}
