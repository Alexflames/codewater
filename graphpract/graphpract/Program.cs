using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace graphpract
{
    class Program
    {
        static bool ReadFile(G_Graph workGraph)
        {
            Console.WriteLine("Введите имя файла, работающего с графом. END чтобы закончить");

            try
            {

                string[] data = Console.ReadLine().Split(new char[] { ' ', '\n', '\t' },
                                    StringSplitOptions.RemoveEmptyEntries);
                if (data[0].ToLower() == "end") return false;
                
                workGraph.GraphActions(data[0]);
                

            }
            catch (Exception e)
            {
                Console.WriteLine("%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
                Console.WriteLine("ОШИБКА: " + e.Message);
                Console.WriteLine("%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
            }

            return true;
        }

        static void Main(string[] args)
        {
            string filename = "input_graph_orient_acycle.txt";
            G_Graph mainGraph = new G_Graph(filename);
            Console.WriteLine("Открываю файл " + filename);
            mainGraph.WriteToConsole();

            if (mainGraph.IsOriented())
            {
                Console.WriteLine("Данный ациклический орграф имеет корень? - "
                    + G_Graph.DFS_HasAcycleRoot(mainGraph));
            }
            //G_Graph copyGraph = new G_Graph(mainGraph, G_Graph.GraphCopyMode.STANDARD);
            //copyGraph.WriteToConsole();

            //Console.WriteLine("Дополнение графа:");
            //G_Graph inverseGraph = new G_Graph(mainGraph, G_Graph.GraphCopyMode.INVERSE);
            //inverseGraph.WriteToConsole();

            bool shouldRead = true;
            while (shouldRead)
            {
                shouldRead = ReadFile(mainGraph);
                mainGraph.WriteToConsole();
            }
        }
    }
}
