using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Linq;

namespace technoprog4_HW
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());

            int[] a = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = int.Parse(Console.ReadLine());
            }

            var a2 = from item in a where Convert.ToString(item).StartsWith("2") select item;

            Console.WriteLine("Сумма чисел: " +
                a2.Sum() + "\n Количество чисел: " + a2.Count());

            Console.WriteLine("Способ №2: ");

            var a2_2 = (from item in a orderby item.ToString()[0] select item )
                .SkipWhile(it => !Convert.ToString(it).StartsWith("2"))
                .OrderByDescending(it => it.ToString()[0])
                .SkipWhile(it => !Convert.ToString(it).StartsWith("2"));

            Console.WriteLine("Сумма чисел: " +
                a2_2.Sum() + "\n Количество чисел: " + a2_2.Count());

            Console.ReadKey();
        }
    }
}
