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

        static void OutClosestPaths(Dictionary<Node, Node> preds, Node fromNode)
        {
            Console.WriteLine("Ищем кратчайший путь до каждой вершины от: " + fromNode.GetName());
            foreach (Node node in preds.Keys)
            {
                // Не считаем текущую вершину если она есть
                if (node == fromNode)
                {
                    continue;
                }

                Console.Write("Путь до вершины " + node.GetName() + ": ");

                Node currentNode = node;
                Stack<Node> pathToNode = new Stack<Node>();
                while (preds[currentNode] != fromNode)
                {
                    pathToNode.Push(preds[currentNode]);
                    currentNode = preds[currentNode];
                }

                Console.Write(fromNode.GetName() + " ");
                while (pathToNode.Count != 0)
                {
                    Console.Write(pathToNode.Pop().GetName() + " ");
                }
                Console.WriteLine(node.GetName() + " ");
            }
        }

        static void Main(string[] args)
        {
            string filename = "input_graph_Grigoriev2.txt";
            G_Graph mainGraph = new G_Graph(filename);
            Console.WriteLine("Открываю файл " + filename);
            mainGraph.WriteToConsole();

           

            //Console.WriteLine("Построение каркаса. Граф должен быть связным, неориентированным и взвешенным");
            //if (mainGraph.IsWeighted() && !mainGraph.IsOriented())
            //{
            //    G_Graph minTree = G_Graph.Boruv(mainGraph);
            //    minTree.WriteToConsole();

            //    Node from = mainGraph.GetGraph().Keys.First();

            //    Dictionary<Node, Node> predVertices =
            //        G_Graph.BFS_Prev(mainGraph, from);

            //    OutClosestPaths(predVertices, from);
            //}
            //else
            //{
            //    Console.WriteLine("Ошибка, нельзя построить каркас" +
            //        ". Граф не взвешенный или ориентированный");
            //}

            //if (mainGraph.IsOriented())
            //{
            //    Console.WriteLine("Данный ациклический орграф имеет корень? - "
            //        + G_Graph.DFS_HasAcycleRoot(mainGraph));
            //}

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
