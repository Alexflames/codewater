using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace technoprog5_2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Вариант: 1. Какую подзадачу хотите решить? (1 или 2)");
            char mode = Console.ReadLine()[0];
            switch (mode)
            {
                case '1':
                    {
                        Console.WriteLine("Введите строку, которая будет обработана");
                        StringBuilder inputStr = new StringBuilder(Console.ReadLine());
                        Console.WriteLine("Введите символ x, который будет вставлен после каждого y в строке");
                        char x = Console.ReadLine()[0];
                        Console.WriteLine("Введите символ y");
                        char y = Console.ReadLine()[0];
                        inputStr.Replace(y.ToString(), y.ToString() + x);
                        Console.WriteLine("Измененная строка: " + inputStr);
                        break;
                    }
                default:
                    {
                        char[] separators = { ' ', ',', '.' };
                        Console.WriteLine("Введите сообщение, которое будет обработано");
                        string[] inputStr = Console.ReadLine().Split(separators);
                        Console.WriteLine("Введите подстроку, при наличии которой в слове сообщения будет выведено");
                        string x = Console.ReadLine();
                        foreach (var item in inputStr)
                        {
                            if (item.Contains(x))
                            {
                                Console.Write(item + ' ');
                            }
                        }

                        break;
                    }
            }
            Console.ReadKey();
        }
    }
}
