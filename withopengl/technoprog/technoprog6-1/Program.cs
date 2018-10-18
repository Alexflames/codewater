using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace technoprog6_1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите логин: ");
            string login = Console.ReadLine();
            Regex regex = new Regex(@"^([a-z]|[A-Z])\w{1,9}");
            if (regex.IsMatch(login))
            {
                Console.WriteLine("Верный логин");
            }
            else
            {
                Console.WriteLine("Неправильный логин");
            }
            Console.ReadKey();
        }
    }
}
