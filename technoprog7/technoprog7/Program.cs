using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace technoprog7
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("n= ");
            int n = int.Parse(Console.ReadLine());
            //Записываем в файл t.dat степени числа 3
            FileStream f = new FileStream("t.dat", FileMode.Create);
            BinaryWriter fOut = new BinaryWriter(f);
            int mult = 1;
            for (int i = 0; i <= n; i++)
            {
                fOut.Write(mult);
                mult *= 3;
            }
            fOut.Close();
            //Объекты f и fIn связаны с одним и тем же файлом 
            f = new FileStream("t.dat", FileMode.Open);
            BinaryReader fIn = new BinaryReader(f);
            long m = f.Length; //определяем количество байт в потоке
                               //Читаем данные из файла t.dat начиная с элемента с номером 1, т.е с 8 байта,
                               //перемещая внутренний указатель на 16 байт, т.е. на два вещественных числа
            for (long i = 0; i < m; i += 16)
            {
                f.Seek(i, SeekOrigin.Begin);
                n = fIn.ReadInt32();
                Console.Write(n + " ");
            }
            fIn.Close();
            f.Close();
            Console.ReadKey();
        }
    }

}
