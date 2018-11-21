using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace technoprog9_3
{
    class Program
    {
        static void Main(string[] args)
        {
            // Создаем пустой поток в памяти  
            MemoryStream ms = new MemoryStream();
            byte[] memData = Encoding.ASCII.GetBytes
                  ("This will go in Memory!");
            // Записываем данные в память
            ms.Write(memData, 0, memData.Length);
            // Устанавливаем указатель на начало 
            ms.Position = 0;
            byte[] inData = new byte[100];
            // Читаем из памяти и выводим на экран
            ms.Read(inData, 0, 100);
            Console.WriteLine(Encoding.ASCII.GetString(inData));
            
            inData = new byte[100];
            Console.WriteLine(ms.Length);
            var length = ms.Length;
            for (int i = 0; i < length; i+=2)
            {
                ms.Write(memData, i, 1);
            }

            ms.Read(inData, 0, 100);

            inData = new byte[100];
            for (int i = (int)length - 1; i >= 0; i--)
            {
                ms.Write(memData, i, 1);
            }

            ms.Read(inData, 0, 100);

            // А также переписываем содержимое памяти в файл
            Stream strm = new FileStream("Memoutput.txt",
            FileMode.OpenOrCreate, FileAccess.Write);
            ms.WriteTo(strm);
        }
    }
}
