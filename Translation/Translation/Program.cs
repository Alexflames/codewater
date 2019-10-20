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
            var SM = new FileStateMachine("TestSM.txt");
            List<string> numbers = new List<string>();
            string input = ReadFile("input1.txt");
            string output = "";
            int i = 0;
            while (i < input.Length)
            {
                var res = StringFinder.MaxString(SM, input, i);
                if (res.found)
                {
                    numbers.Add(input.Substring(i, res.m));
                    i = i + res.m;
                }
                else i++;
                SM.ResetState();
            }
            foreach (var num in numbers)
            {
                output = output + num + " ";
            }
            Console.Write(output);
            return;
        }
    }
}
