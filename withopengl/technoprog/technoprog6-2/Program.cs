using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace technoprog6_2
{
    class Program
    {
        static void BubbleSort(ref int[] Array)
        {
            bool changes = true;
            while (changes)
            {
                changes = false;
                for (int i = 0; i < Array.Length - 1; i++)
                {
                    if (Array[i] > Array[i + 1])
                    {
                        changes = true;
                        var temp = Array[i];
                        Array[i] = Array[i + 1];
                        Array[i + 1] = temp;
                    }
                }
            }
        }

        // Дихотомический поиск элемента в массиве
        static KeyValuePair<int, int> IndexOf(ref int[] Array, int Value, int Left, int Right, int counter)
        {
            // Увеличиваем счетчик итераций
            counter++;
            // Находим середину диапазона
            int x = (Left + Right) / 2;
            // Если нашли значение - возвращаем его индекс
            if (Array[x] == Value)
                return new KeyValuePair<int, int>(x, counter);
            // Если середина совпадает с левой или правой границами - значение не найдено
            if ((x == Left) || (x == Right))
                return new KeyValuePair<int, int>(-1, counter);
            // Продолжаем поиск слева или справа от середины
            if (Array[x] < Value)
                return IndexOf(ref Array, Value, x, Right, counter);
            else
                return IndexOf(ref Array, Value, Left, x, counter);
        }

        static void Main(string[] args)
        {
            Random rand = new Random();
            int[] numbers = new int[100];
            for (int i = 0; i < numbers.Length; i++)
            {
                numbers[i] = rand.Next(0, 100);
            }

            int randI = rand.Next(50, 99);
            Console.WriteLine("Поиск элемента " + numbers[randI]);
            int elementToFind = numbers[randI];

            int cntFind = 0;
            for (int i = 0; i < numbers.Length; i++)
            {
                cntFind++;
                if (numbers[i] == numbers[randI])
                {
                    Console.WriteLine(
                        "Простой поиск: " + cntFind + " итераций, "
                        + " элемент на позиции " + i);
                    break;
                }
            }

            Console.WriteLine("Проведем сортировку...");
            BubbleSort(ref numbers);

            KeyValuePair<int, int> ans = IndexOf(ref numbers, elementToFind, 0, 99, 0);
            Console.WriteLine(
                        "Двоичный поиск: " + ans.Value + " итераций, "
                        + " элемент на позиции " + ans.Key);
            Console.ReadKey();
        }
    }
}
