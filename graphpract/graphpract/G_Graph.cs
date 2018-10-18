using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace graphpract
{
    class Node
    {
        public enum Color
        {
            WHITE,
            GREY,
            BLACK
        }

        public Node(string id)
        {
            m_id = id;
        }

        public Node(Node node)
        {
            m_id = node.GetName();
        }

        private string m_id;
        public string GetName()
        {
            return m_id;
        }

        private Color m_color = Color.WHITE;
        public Color GetColor()
        {
            return m_color;
        }
        public void SetColor(Color color)
        {
            m_color = color;
        }
    }

    class EdgeTo
    {
        public EdgeTo(Node to)
        {
            m_nodeTo = to;
            m_weight = 0;
        }

        public EdgeTo(Node to, int weight)
        {
            m_nodeTo = to;
            m_weight = weight;
        }

        public EdgeTo(EdgeTo edgeTo, Node nodeTo)
        {
            m_nodeTo = nodeTo;
            m_weight = edgeTo.GetWeight();
        }

        public void SetWeight(int weight)
        {
            m_weight = weight;
        }

        public int GetWeight()
        {
            return m_weight;
        }

        public EdgeTo Copy()
        {
            EdgeTo copy = new EdgeTo(m_nodeTo);
            copy.SetWeight(m_weight);
            return copy;
        }

        public Node GetNodeTo()
        {
            return m_nodeTo;
        }

        private Node m_nodeTo;
        private int m_weight;
    }

    class G_Graph
    {
        public enum InputMode
        {
            NONE,
            OPTION,
            VERTEX,
            EDGE,
            ACTION,
            END
        };

        private Dictionary<Node, List<EdgeTo>> m_graph;
        private bool m_oriented = false;
        private bool m_weighted = false;

        // Поля для взаимодействия с несколькими графами
        private string m_graphName;
        private G_Graph m_secondGraph;
        private Dictionary<string, G_Graph> otherGraphs = new Dictionary<string, G_Graph>();

        private InputMode m_inputMode = InputMode.NONE;

        #region Методы для работы с графом

        private static void DFS_Visit(Node visitNode, G_Graph dfsGraph)
        {
            visitNode.SetColor(Node.Color.GREY);

            var graph = dfsGraph.GetGraph();
            foreach(EdgeTo edge in graph[visitNode])
            {
                if (edge.GetNodeTo().GetColor() == Node.Color.WHITE)
                {
                    DFS_Visit(edge.GetNodeTo(), dfsGraph);
                }
            }
            visitNode.SetColor(Node.Color.BLACK);
        }

        private static void DFS_Init(Dictionary<Node, List<EdgeTo>>.KeyCollection graph)
        {
            foreach (Node node in graph)
            {
                node.SetColor(Node.Color.WHITE);
            }
        }

        public static bool DFS_HasAcycleRoot(G_Graph DFSgraph)
        {
            var graph = DFSgraph.GetGraph();
            DFS_Init(graph.Keys);

            List<Node> badNodesList = new List<Node>();

            foreach (Node node in graph.Keys)
            {
                if (node.GetColor() == Node.Color.WHITE)
                {
                    DFS_Visit(node, DFSgraph);
                    int blackNodes = 0;
                    foreach (Node nodeToMark in graph.Keys)
                    {
                        if (nodeToMark.GetColor() == Node.Color.BLACK)
                        {
                            blackNodes++;
                            badNodesList.Add(nodeToMark);
                            nodeToMark.SetColor(Node.Color.WHITE);
                        }

                        if (blackNodes == graph.Keys.Count)
                        {
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        #region отлаженные
        public bool IsOriented()
        {
            return m_oriented;
        }

        public void SetOriented(bool oriented)
        {
            m_oriented = oriented;
        }
        
        public bool IsWeighted()
        {
            return m_weighted;
        }

        public void SetWeighted(bool weighted)
        {
            m_weighted = weighted;
        }

        public Dictionary<Node, List<EdgeTo>> GetGraph()
        {
            return m_graph;
        }

        public InputMode GetState()
        {
            return m_inputMode;
        }

        private void InsertNode(Node node)
        {
            m_graph.Add(node, new List<EdgeTo>());
        }

        private void AddEdge(Node node, EdgeTo edge)
        {
            m_graph[node].Add(edge);

            if (!m_oriented)
            {
                EdgeTo back = new EdgeTo(node);
                if (IsWeighted())
                    back.SetWeight(edge.GetWeight());
                m_graph[edge.GetNodeTo()].Add(new EdgeTo(node));
            }
        }

        public bool SearchNodeByName(string name, out Node toReturn)
        {
            toReturn = null;
            bool success = false;

            foreach (var key in m_graph.Keys)
            {
                if (key.GetName() == name)
                {
                    toReturn = key;
                    success = true;
                }
            }
            return success;
        }
        
        private static bool NodeToNameSame(EdgeTo edgeTo, string name)
        {
            return (edgeTo.GetNodeTo().GetName() == name);
        }

        public void DeleteEdgeFromTo(Node nodeFrom, Node nodeTo)
        {
            m_graph[nodeFrom]
                .Remove(m_graph[nodeFrom]
                .Find(x => NodeToNameSame(x, nodeTo.GetName())));
                
            if (!m_oriented)
            {
                m_graph[nodeTo]
                    .Remove(m_graph[nodeTo]
                    .Find(x => NodeToNameSame(x, nodeFrom.GetName())));
            }
            
        }

        public void DeleteNode(Node nodeToDelete)
        {
            List<EdgeTo> edgesToDelete = new List<EdgeTo>();
            if (!m_oriented) {
                foreach (EdgeTo edgeToDelete in m_graph[nodeToDelete])
                {
                    Node nodeTo = edgeToDelete.GetNodeTo();
                    m_graph[nodeTo]
                        .Remove(m_graph[nodeTo]
                        .Find(x => NodeToNameSame(x, nodeToDelete.GetName())));
                }
            }

            m_graph.Remove(nodeToDelete);
        }

        public void WriteToConsole()
        {
            Console.WriteLine("Вывод графа в консоль");
            
            Console.Write("Особенности графа: ");
            if (m_oriented)
            {
                Console.Write("ориентированный ");
            }
            else
            {
                Console.Write("неориентированный ");
            }
            if (m_weighted)
            {
                Console.Write("взвешенный ");
            }
            Console.WriteLine();

            foreach (var item in m_graph)
            {
                Console.Write(item.Key.GetName() + ": ");
                foreach (var edge in item.Value)
                {
                    Console.Write(edge.GetNodeTo().GetName() + " ");
                    if (IsWeighted())
                    {
                        Console.Write("(вес: " + edge.GetWeight() + ") ");
                    }
                }
                Console.WriteLine();
            }

            Console.WriteLine();
        }

        #endregion

        public string GetName()
        {
            return m_graphName;
        }

        public void SetName(string name)
        {
            m_graphName = name;
        }

        public enum NodeSearchCondition
        {
            NOTADJACENT,
            HASLOOP
        }

        public List<Node> NodesByCondition(NodeSearchCondition nodeCondition)
        {
            List<Node> nodesToReturn = new List<Node>();
            foreach (var item in GetGraph())
            {
                switch (nodeCondition)
                {
                    case NodeSearchCondition.NOTADJACENT:
                        throw new Exception("wrong condition for 0 argument");
                    case NodeSearchCondition.HASLOOP:
                        if (item.Value.Find(x => NodeToNameSame(x, item.Key.GetName())) != null)
                        {
                            nodesToReturn.Add(item.Key);
                        }
                        break;
                    default:
                        throw new Exception("condition not found");
                }
            }
            return nodesToReturn;
        }

        public List<Node> NodesByCondition(NodeSearchCondition nodeCondition, string conditionString)
        {
            List<Node> nodesToReturn = new List<Node>();
            foreach (var item in GetGraph())
            {
                switch (nodeCondition)
                {
                    case NodeSearchCondition.NOTADJACENT:
                        if (item.Key.GetName() != conditionString &&
                            !item.Value.Exists(x => NodeToNameSame(x, conditionString)))
                        {
                            nodesToReturn.Add(item.Key);
                        }
                        break;
                    case NodeSearchCondition.HASLOOP:
                        throw new Exception("wrong condition for 1 argument");
                    default:
                        throw new Exception("condition not found");
                }
            }
            return nodesToReturn;
        }

        #endregion

        #region Конструкторы

        // Создание графа с помощью ввода в консоль
        // ТОЛЬКО ДЛЯ ТЕСТИРОВАНИЯ
        public G_Graph()
        {
            m_graph = new Dictionary<Node, List<EdgeTo>>();
            Console.WriteLine("Создан пустой граф");
        }

        public G_Graph(bool test)
        {
            m_graph = new Dictionary<Node, List<EdgeTo>>();
            Console.WriteLine("Введите настройки графа через пробел: orient = ориентир., weight = взвешенный");
            string[] data =
            Console.ReadLine().Split(new char[] { ' ', '\n', '\t' },
                                        StringSplitOptions.RemoveEmptyEntries);
            foreach (string item in data)
            {
                switch (item.ToLower())
                {
                    case "orient":
                        m_oriented = true;
                        break;
                    case "weight":
                        m_weighted = true;
                        break;
                    default:
                        Console.WriteLine("Настройка " + item + " не найдена");
                        break;
                }

                
            }

            Console.WriteLine("Введите вершины графа");
            data =
                Console.ReadLine().Split(new char[] { ' ', '\n', '\t' },
                                            StringSplitOptions.RemoveEmptyEntries);

            foreach (string nodeInf in data)
            {
                Node node = new Node(nodeInf);
                InsertNode(node);
            }

            if (m_weighted)
            {
                Console.WriteLine("Введите построчно вершину и смежную с ней, вес. end - конец");
            }
            else
            {
                Console.WriteLine("Введите построчно вершину и смежную с ней, end - конец");
            }
            
            while (true)
            {
                data = 
                    Console.ReadLine().Split(new char[] { ' ', '\n', '\t' },
                                             StringSplitOptions.RemoveEmptyEntries);
                if (data[0].ToLower() == "end")
                {
                    break;
                }
                else
                {
                    Node nodeFrom, nodeTo;
                    SearchNodeByName(data[0], out nodeFrom);
                    SearchNodeByName(data[1], out nodeTo);

                    EdgeTo edge;
                    edge = new EdgeTo(nodeTo);

                    if (m_weighted)
                    {
                        edge.SetWeight(Int32.Parse(data[2]));
                    }

                    // Добавить ребро
                    AddEdge(nodeFrom, edge);

                    if (!m_oriented)
                    {
                        EdgeTo edgeBack = new EdgeTo(nodeFrom);
                        AddEdge(nodeTo, edgeBack);
                        // создать обратно ребро
                    }
                }

            }
        }
        
        public enum GraphCopyMode
        {
            STANDARD,
            INVERSE
        }

        public G_Graph(G_Graph graph, GraphCopyMode graphCopyMode)
        {
            m_graph = new Dictionary<Node, List<EdgeTo>>();
            // Копирование графа
            var inputGraph = graph.GetGraph();
            if (graphCopyMode == GraphCopyMode.STANDARD)
            {
                foreach (var node in inputGraph)
                {
                    Node nodeCopy = new Node(node.Key);
                    InsertNode(nodeCopy);
                    m_oriented = true; // Важно для полного копирования ребер

                }

                m_oriented = true; // Важно для полного копирования ребер
                foreach (var node in inputGraph)
                {
                    foreach (var edge in node.Value)
                    {
                        SearchNodeByName(edge.GetNodeTo().GetName(), out Node nodeToCopy);
                        SearchNodeByName(node.Key.GetName(), out Node nodeFrom);
                        EdgeTo edgeCopy = new EdgeTo(edge, nodeToCopy);
                        AddEdge(nodeFrom, edgeCopy);
                    }

                }
                
                SetOriented(graph.IsOriented());
                SetWeighted(graph.IsWeighted());
                Console.WriteLine("Создана копия графа");
            }

            // Дополнение графа
            else if (graphCopyMode == GraphCopyMode.INVERSE)
            {
                // копирование графа
                foreach (var node in inputGraph)
                {
                    Node nodeCopy = new Node(node.Key);
                    InsertNode(nodeCopy);
                    m_oriented = true; // Важно для полного копирования ребер

                }

                m_oriented = true; // Важно для полного копирования ребер
                foreach (var node in inputGraph)
                {
                    foreach (var edge in node.Value)
                    {
                        SearchNodeByName(edge.GetNodeTo().GetName(), out Node nodeToCopy);
                        SearchNodeByName(node.Key.GetName(), out Node nodeFrom);
                        EdgeTo edgeCopy = new EdgeTo(edge, nodeToCopy);
                        AddEdge(nodeFrom, edgeCopy);
                    }

                }

                var thisGraph = GetGraph();
                // для каждого узла в графе
                foreach (var node in thisGraph)
                {
                    // Ключ - все узлы, значение - наличие грани? true, false
                    Dictionary<Node, bool> nodeNamesWithEdges = new Dictionary<Node, bool>();
                    // добавляем все узлы
                    foreach (Node eachNode in thisGraph.Keys)
                    {
                        nodeNamesWithEdges.Add(eachNode, false);
                    }

                    // для каждого ребра, исходящего из данной вершины
                    // меняем значение узлов с ребрами в списке на true
                    foreach (EdgeTo edge in thisGraph[node.Key])
                    {
                        nodeNamesWithEdges[edge.GetNodeTo()] = true;
                    }

                    // очищаем список ребер, исходящих из данной вершины
                    thisGraph[node.Key].Clear();

                    // для каждого узла, в которые (возможно) идут ребра
                    foreach (var item in nodeNamesWithEdges)
                    {
                        // петли в неориентированном графе не нужны
                        if (node.Key != item.Key)
                        {
                            // если такого ребра не существовало
                            if (nodeNamesWithEdges[item.Key] == false)
                            {
                                AddEdge(node.Key, new EdgeTo(item.Key));
                            }
                        }
                    }
                }
                m_oriented = false;
            }
        }
             
        // вспомогательная функция выбора опций при считывании из файла
        private void proceedInput (string[] input, int line)
        {
            try
            {
                if (input.Length == 0 || input[0] == "//") return;
                else if (input[0].ToUpper() == "SET")
                {
                    switch (input[1].ToUpper())
                    {
                        case ("OPTION"):
                            m_inputMode = InputMode.OPTION;
                            break;
                        case ("VERTEX"):
                            m_inputMode = InputMode.VERTEX;
                            break;
                        case ("EDGE"):
                            m_inputMode = InputMode.EDGE;
                            break;
                        case ("ACTION"):
                            m_inputMode = InputMode.ACTION;
                            break;
                        case ("END"):
                            m_inputMode = InputMode.END;
                            break;
                        default:
                            break;
                    }
                }
                else if (m_inputMode == InputMode.OPTION)
                {
                    foreach (var item in input)
                    {
                        switch (item.ToLower())
                        {
                            case ("orient"):
                                m_oriented = true;
                                break;
                            case ("weight"):
                                m_weighted = true;
                                break;
                            case ("name"):
                                SetName(input[1]);
                                break;
                            default:
                                Console.WriteLine("ERROR: NO SUCH OPTION " + item + " FOUND");
                                break;
                        }
                    }
                }
                else if (m_inputMode == InputMode.VERTEX)
                {
                    foreach (var item in input)
                    {
                        Node toAdd = new Node(item);
                        InsertNode(toAdd);
                    }
                }
                else if (m_inputMode == InputMode.EDGE)
                {
                    SearchNodeByName(input[0], out Node nodeToAddEdges);

                    SearchNodeByName(input[1], out Node nodeConnectTo);

                    // Переделать, проходя по подпоследовательности определяя свойства
                    if (input.Length == 3 && input[2][0] == 'w')
                        AddEdge(nodeToAddEdges, new EdgeTo(nodeConnectTo, Int32.Parse(input[2].Substring(1))));
                    else
                        AddEdge(nodeToAddEdges, new EdgeTo(nodeConnectTo));

                }
                else if (m_inputMode == InputMode.ACTION)
                {
                    switch (input[0].ToUpper())
                    {
                        case "ADDV":
                            InsertNode(new Node(input[1]));
                            break;
                        case "ADDE":
                            {
                                SearchNodeByName(input[1], out Node from);
                                SearchNodeByName(input[2], out Node to);
                                if (input.Length == 4 && input[3][0] == 'w')
                                    AddEdge(from, new EdgeTo(to, Int32.Parse(input[3].Substring(1))));
                                else
                                    AddEdge(from, new EdgeTo(to));
                                break;
                            }
                        case "DELV":
                            {
                                SearchNodeByName(input[1], out Node toDelete);
                                DeleteNode(toDelete);
                                break;
                            }
                        case "DELE":
                            {
                                SearchNodeByName(input[1], out Node from);
                                SearchNodeByName(input[2], out Node to);
                                DeleteEdgeFromTo(from, to);
                                break;
                            }
                        case "NOTADJACENT":
                            {
                                Console.WriteLine("---------------------------------------------------");
                                Console.WriteLine("Поиск вершин, не смежных с " + input[1]);
                                foreach (Node node in NodesByCondition(NodeSearchCondition.NOTADJACENT, input[1]))
                                {
                                    Console.Write(node.GetName() + " ");
                                }
                                Console.WriteLine();
                                Console.WriteLine("---------------------------------------------------");
                                break;
                            }
                        case "HASLOOP":
                            {
                                Console.WriteLine("---------------------------------------------------");
                                Console.WriteLine("Поиск вершин, имеющих петли");
                                foreach (Node node in NodesByCondition(NodeSearchCondition.HASLOOP))
                                {
                                    Console.Write(node.GetName() + " ");
                                }
                                Console.WriteLine();
                                Console.WriteLine("---------------------------------------------------");
                                break;
                            }
                        default:
                            Console.WriteLine("Action " + input[0] + " not found");
                            break;
                    }
                }
            }
            catch
            {
                throw new Exception("Количество аргументов функции " + input[0] +
                    "\n не соответствует ожиданиям" +
                    "\n Ошибка в строке: " + line);
            }
        }

        // считывает из файла действия над графом
        public void GraphActions(string filename)
        {
            StreamReader sr = new StreamReader(filename);

            m_inputMode = InputMode.NONE;
            int line = 0;
            while (m_inputMode != InputMode.END)
            {
                line++;
                string[] data =
                    sr.ReadLine().Split(new char[] { ' ', '\n', '\t' },
                                                StringSplitOptions.RemoveEmptyEntries);
                proceedInput(data, line);
            }

            sr.Close();
        }

        // считывание графа из файла filename
        public G_Graph(string filename)
        {
            
            m_graph = new Dictionary<Node, List<EdgeTo>>();

            GraphActions(filename);
        }

        #endregion
    }
}