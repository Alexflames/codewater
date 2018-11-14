using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace technoprog7_thread
{

    class Program
    {
        private const int mSize = 100000;
        private const short threadN = 4;
        static void Main(string[] args)
        {
            int[] mas = new int[mSize];
            Random rand = new Random();
            for (int i = 0; i < mSize; i++)
            {
                mas[i] = rand.Next();
            }

            var watch = new System.Diagnostics.Stopwatch();
            var min = int.MaxValue;
            watch.Start();
            for (int i = 0; i < mSize; i++)
            {
                min = mas[i] < min ? mas[i] : min;
            }
            watch.Stop();
            Console.WriteLine("Время поиска минимума в массиве из " + mSize + " элементов: " + watch.ElapsedTicks + "(тиков)" 
                + " минимум: " + min);

            Thread[] threads = new Thread[threadN]; 
            int[] thrMins = new int[threadN]; // Минимумы для каждого из потоков

            int thrMin = int.MaxValue;


            for (int i = 0; i < threadN; i++)
            {
                threads[i] = new Thread((obj) =>
                {
                    for (int j = i; j < (mSize / (threadN + 1) * (i + 1)); j++)
                    {
                        thrMin = mas[j] < thrMin ? mas[j] : thrMin;
                    }
                });
                threads[i].Start();
            }

            // Принудительный запуск
            watch.Reset();
            watch.Start();
            for (int i = 0; i < threadN; i++)
            {
                threads[i].Join();
            }
            watch.Stop();

            Console.WriteLine("С использованием " + threadN + " потоков: " + watch.ElapsedTicks + " минимум: " + thrMin);
            Console.ReadKey();
        }
    }
}
