using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace technoprog9_2
{
    class Program
    {
        static void printFile(FileInfo file)
        {
            Console.WriteLine("***** " + file.Name + " *****");
            Console.WriteLine("File size: {0}", file.Length);
            Console.WriteLine("Creation: {0}", file.CreationTime);
            Console.WriteLine("Attributes: {0}", file.Attributes.ToString());
        }

        static void Main(string[] args)
        {
            Directory.CreateDirectory(@"c:\temp\K1");
            Directory.SetCurrentDirectory(@"c:\temp\K1");

            var sw = File.CreateText("t1.txt");
            sw.Write("Иванов Иван Иванович, 1965 года рождения, место жительства г. Саратов");
            sw.Close();

            sw = File.CreateText("t2.txt");
            sw.Write("Петров Сергей Федорович, 1966 года рождения, место жительства г.Энгельс");
            sw.Close();

            Directory.CreateDirectory(@"c:\temp\K2");
            //Directory.SetCurrentDirectory(@"c:\temp\K2");

            sw = File.CreateText(@"c:\temp\K2\t3.txt");

            var sr = new StreamReader(@"c:\temp\K1\t1.txt");
            sw.WriteLine(sr.ReadLine());
            sr.Close();

            sr = new StreamReader(@"c:\temp\K1\t2.txt");
            sw.WriteLine(sr.ReadLine());
            sr.Close();

            sw.Close();

            FileInfo f = new FileInfo(@"c:\temp\K1\t1.txt");
            printFile(f);
            f = new FileInfo(@"c:\temp\K1\t2.txt");
            printFile(f);
            f = new FileInfo(@"c:\temp\K2\t3.txt");
            printFile(f);
            
            // Пункт 5
            File.Move(@"c:\temp\K1\t2.txt", @"c:\temp\K2\t2.txt");
            File.Copy(@"c:\temp\K1\t1.txt", @"c:\temp\K2\t1.txt");

            Directory.Move(@"c:\temp\K2", @"c:\temp\ALL");
            var dif = new DirectoryInfo(@"c:\temp\ALL").GetFiles();
            foreach (var file in dif)
            {
                printFile(file);
            }
        }
    }
}
