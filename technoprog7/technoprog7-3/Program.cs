using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using System.IO;

namespace technoprog7_3
{
    class Program
    {

        enum Query
        {
            GETTEXT,
            COUNTMATRIX
        }

        static string ReadMessage(NetworkStream stream)
        {
            // Через сокет передается массив байт, который после получения нужно преобразовать в строку. 
            String data = String.Empty;
            Byte[] bytes = System.Text.Encoding.UTF8.GetBytes(data);
            int i = stream.Read(bytes, 0, bytes.Length);
            return System.Text.Encoding.ASCII.GetString(bytes, 0, i);
        }

        static void SendMessage(string msg, NetworkStream stream)
        {
            // Перед отправкой через сокет строку необходимо преобразовать в массив байт. 
            Byte[] bytes = new Byte[256];
            String data = "text";
            bytes = System.Text.Encoding.UTF8.GetBytes(data);
            stream.Write(bytes, 0, bytes.Length);
        }

        static double[][] CalcMatrix(double [][] m1, double[][] m2)
        {
            double[][] ans = new double[100][]; //TODO: fix размера

            return ans;
        }

        static void Main(string[] args)
        {
            WebClient myClient = new WebClient();
            Console.WriteLine("Введите адрес, с которого надо считать страницу");
            string url = Console.ReadLine();
            Stream response = myClient.OpenRead(url);// http://www.binarytable.tk/
            // The stream data is used here.
            StreamReader sr = new StreamReader(response);
            string responseStr = sr.ReadToEnd() + "\n";
            byte[] info = new UTF8Encoding(true).GetBytes(responseStr);

            FileStream sw = new FileStream("response.txt", FileMode.Create);
            sw.Write(info, 0, info.Length);

            // Второе задание
            string hostInfo = "";
            IPHostEntry host1 = Dns.GetHostEntry("www.mail.ru");
            hostInfo += host1.HostName + "\n";
            foreach (IPAddress ip in host1.AddressList)
                hostInfo += ip.ToString() + "\n";
            hostInfo += "\n";
            info = new UTF8Encoding(true).GetBytes(hostInfo);
            sw.Write(info, 0, info.Length);

            response.Close();

            // Третье задание
            Int32 port = 13000;
            IPAddress localAddr = IPAddress.Parse("127.0.0.1");
            TcpListener server = new TcpListener(localAddr, port);
            server.Start();

            TcpClient client = server.AcceptTcpClient();
            // После подключения создается поток входных / выходных сообщений
            NetworkStream stream = client.GetStream();

            string msg = ReadMessage(stream);
            SendMessage(msg, stream);
        }
    }
}
