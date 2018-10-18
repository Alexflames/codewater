using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace technoprog4_3
{
    class Program
    {
        /// <summary>
        /// Ввод двумерного массива с консоли
        /// </summary>
        /// <returns> Двумерный массив </returns>
        static int[][] Input()
        {
            Console.WriteLine("введите размерность массива");
            Console.Write("n = ");
            int n = int.Parse(Console.ReadLine());
            int[][] a = new int[n][];
            for (int i = 0; i < n; ++i)
            {
                a[i] = new int[n];
                for (int j = 0; j < n; ++j)
                {
                    Console.Write("a[{0},{1}]= ", i, j);
                    a[i][j] = int.Parse(Console.ReadLine());
                }
            }
            return a;
        }

        static void Print1(int[] a)
        {
            for (int i = 0; i < a.Length; ++i)
                Console.Write("{0,5} ", a[i]);
        }

        static void Print2(int[][] a)
        {
            for (int i = 0; i < a.Length; ++i, Console.WriteLine())
                for (int j = 0; j < a[i].Length; ++j)
                    Console.Write("{0,5} ", a[i][j]);
        }

        /// <summary>
        /// Поиск максимума в массиве
        /// </summary>
        /// <param name="a"> Массив чисел </param>
        /// <returns> Число - максимум </returns>
        static int Max(int[] a)
        {
            int max = a[0];
            for (int i = 1; i < a.Length; ++i)

                if (a[i] > max) { max = a[i]; }
            return max;
        }

        /// <summary>
        /// Создание массива минимумов,
        /// состоящего из минимумов в каждой строке исходного
        /// </summary>
        /// <param name="a"> Исходный двумерный массив </param>
        /// <returns> Массив минимумов в каждой строке </returns>
        static int[] arrMin(int[][] a)
        {
            int[] aOut = new int[a.Length];
            for (int i = 0; i < a.Length; i++)
            {
                int min = Int32.MaxValue;
                for (int j = 0; j < a[i].Length; j++)
                {
                    min = Math.Min(min, a[i][j]);
                }
                aOut[i] = min;
            }
            return aOut;
        }

        static void Main()
        {
            int[][] myArray = Input();
            Console.WriteLine("Исходный массив:");
            Print2(myArray);
            int[] rez = arrMin(myArray);

            Console.WriteLine("Новый массив:");
            Print1(rez);
            Console.ReadKey();
        }
    }
}
