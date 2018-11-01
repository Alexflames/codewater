using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Text.RegularExpressions;

namespace technoprog7_2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Введите заданную букву: ");
            StreamReader fileIn = new StreamReader("text.txt");
            string text = fileIn.ReadToEnd(); //считываем из файла весь текст
            fileIn.Close();
            int k = 0;
            //разбиваем текст на слова используя регулярные выражения
            string[] newText = Regex.Split(text, "[ ,.:;]+");
            //подсчитываем количество слов, начинающихся на заданную букву 
            foreach (string b in newText)
                if (b[0] == b[b.Length - 1]) ++k;
            Console.WriteLine("Количество слов, начинающих и оканчивающихся на одну букву = " + k);
            Console.ReadKey();
        }
    }
}
