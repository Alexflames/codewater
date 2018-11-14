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
            Byte[] bytes = new Byte[256];
            String data = null;
            int i = stream.Read(bytes, 0, bytes.Length);
            return System.Text.Encoding.UTF8.GetString(bytes, 0, i);
        }

        static void SendMessage(string msg, NetworkStream stream)
        {
            string[] convertedMsg = msg.Split(' ', '\n');
            // Преобразуем string-ввод в матрицы
            int matSize = Convert.ToInt32(convertedMsg[0]);
            double[][] m1 = new double[matSize][];
            double[][] m2 = new double[matSize][];

            int msgIt = 1;
            for (int i = 0; i < matSize; i++)
            {
                m1[i] = new double[matSize];
                for (int j = 0; j < matSize; j++)
                {
                    m1[i][j] = Convert.ToDouble(convertedMsg[msgIt]);
                    msgIt++;
                }
            }

            for (int i = 0; i < matSize; i++)
            {
                m2[i] = new double[matSize];
                for (int j = 0; j < matSize; j++)
                {
                    m2[i][j] = Convert.ToDouble(convertedMsg[msgIt]);
                    msgIt++;
                }
            }
            // Производим умножение матриц
            double[][] matAns = CalcMatrix(m1, m2);

            string retMsg = matSize.ToString();
            for (int i = 0; i < matSize; i++)
            {
                for (int j = 0; j < matSize; j++)
                {
                    retMsg += " " + matAns[i][j];
                }
            }
            // Перед отправкой через сокет строку необходимо преобразовать в массив байт. 
            byte[] bytes = new byte[256];
            bytes = Encoding.UTF8.GetBytes(retMsg);
            stream.Write(bytes, 0, bytes.Length);
        }

        static double[][] CalcMatrix(double [][] m1, double[][] m2)
        {
            double[][] ans = new double[m1.Count()][]; 
            
            for (int i = 0; i < ans.Count(); i++)
            {
                ans[i] = new double[m2.Count()];
                for (int j = 0; j < ans[i].Count(); j++)
                {
                    ans[i][j] = 0;
                    for (int k = 0; k < m2.Count(); k++)
                    {
                        ans[i][j] += m1[i][k] * m2[k][j];
                    }
                }
            }

            return ans;
        }

        static void Main(string[] args)
        {
            WebClient myClient = new WebClient();
            //Console.WriteLine("Введите адрес, с которого надо считать страницу");
            //string url = Console.ReadLine();
            Stream response = myClient.OpenRead("http://www.binarytable.tk/");//  https://github.com/Alexflames/
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

            Console.ReadKey();

            stream.Close();
        }
    }
}
