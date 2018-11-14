using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;

namespace technoprog7_3_client
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите размерность квадратной матрицы:");
            string n = Console.ReadLine().Split(' ')[0];
            string message = n;
            Console.WriteLine("Введите первую матрицу, построчно");
            for (int i = 0; i < System.Convert.ToInt32(n); i++)
            {
                string[] row = Console.ReadLine().Split(' ');
                for (int j = 0; j < System.Convert.ToInt32(n); j++)
                {
                    message += " " + row[j];
                }
            }
            Console.WriteLine("Введите вторую матрицу, построчно");
            for (int i = 0; i < System.Convert.ToInt32(n); i++)
            {
                string[] row = Console.ReadLine().Split(' ');
                for (int j = 0; j < System.Convert.ToInt32(n); j++)
                {
                    message += " " + row[j];
                }
            }

            TcpClient client = new TcpClient("localhost", 13000);
            // Затем после подключения к серверу аналогично серверной программе создается поток входных / выходных сообщений
            NetworkStream stream = client.GetStream();
            // Можно отправить сообщение серверу, предварительно преобразовав строку в массив байт:
            Byte[] bytes = System.Text.Encoding.UTF8.GetBytes(message);
            stream.Write(bytes, 0, bytes.Length);
            // Или получить сообщение от сервера, преобразовав массив байт в строку:
            bytes = new Byte[256];
            Int32 ind = stream.Read(bytes, 0, bytes.Length);

            string[] responseData = System.Text.Encoding.ASCII.GetString(bytes, 0, ind).Split(' ');
            int it = 1;
            for (int i = 0; i < Convert.ToInt32(responseData[0]); i++)
            {
                for (int j = 0; j < Convert.ToInt32(responseData[0]); j++)
                {
                    Console.Write(responseData[it] + " ");
                    it++;
                }
                Console.WriteLine();
            }
            Console.ReadKey();
        }
    }
}
