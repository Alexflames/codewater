using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;
using technoproglib4;

namespace technoprog4_1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите a, b, c, d. Найдем их минимум: ");
            string[] str = Console.ReadLine().Split(new char[] { ' ', '\n', '\t' },
                        StringSplitOptions.RemoveEmptyEntries);
            int a = Int32.Parse(str[0]), b = Int32.Parse(str[1]), 
                c = Int32.Parse(str[2]), d = Int32.Parse(str[3]);
            Console.WriteLine("Введите 1 для подсчета с использованием динамической библиотеки. " +
                "\n 2 для статической: ");
            string opt = Console.ReadLine();
            switch (opt)
            {
                case "1":
                    {
                        Console.WriteLine("Динамическая библиотека активирована.");
                        Assembly aly = Assembly.Load("technoproglib4");
                        Object o = aly.CreateInstance("technoproglib4.G_Class");
                        Type t = aly.GetType("technoproglib4.G_Class");

                        MethodInfo mi = t.GetMethod("MinDyn");
                        object result = mi.Invoke(o, new object[2] { a, b });
                        result = mi.Invoke(o, new object[2] { result, c });
                        result = mi.Invoke(o, new object[2] { result, d });
                        Console.WriteLine("Ответ: " + result.ToString());
                        break;
                    }                    
                default:
                    {
                        Console.WriteLine("Используем статическую библиотеку.");
                        Console.WriteLine("Ответ: " +
                            G_Class.Min(G_Class.Min(G_Class.Min(a, b), c), d));
                        Console.WriteLine("a меньше b и c? " + a.Min(b, c));
                    }
                    break;
            }

            Console.ReadLine();
        }
    }
}
