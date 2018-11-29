using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO;
using System.Xml.Serialization;
using System.Runtime.Serialization.Json;

namespace technoprog10_2
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private UntestedModule[] Modules = new[] {
            new UntestedModule {
                DaysInProgress = 15,
                Importance = 40,
                IsExperimental = true,
                Weight = 273,
                Name = "Баклажан с ИИ"
            },

            new UntestedModule {
                DaysInProgress = 65,
                Importance = 10,
                IsExperimental = true,
                Weight = 73485,
                Name = "Экстренное самоуничтожение"
            },

            new UntestedModule {
                DaysInProgress = 3,
                Importance = 85,
                IsExperimental = false,
                Weight = 400,
                Name = "Лабораторная №10 по ТП"
            },

            new UntestedModule {
                DaysInProgress = 1,
                Importance = 55,
                IsExperimental = false,
                Weight = 500,
                Name = "Разогрев пищи"
            }

            };

        public MainWindow()
        {
            InitializeComponent();
        }

        void UpdateModulesList()
        {
            listItems.Items.Clear();
            foreach (var obj in Modules)
            {
                listItems.Items.Add($"{obj.Name} -- {String.Format("{0:f2}", obj.ErrorFullness)}");
            }
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            UpdateModulesList();
        }

        private void listItems_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (listItems.Items.Count != 0)
            {
                txtModuleDesc.Text = Modules[listItems.SelectedIndex].ToString();
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            var x = double.Parse(txtErrorFullness.Text);
            var result = from m in Modules where m.ErrorFullness > x select m.Name;
            string s = "";
            foreach (var item in result) s += item.ToString() + "\n";
            MessageBox.Show(s, $"Все модули с уровнем ошибок больше чем {x}");
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            var isExperimental = (bool)checkExperimental.IsChecked;
            var result = from m in Modules where m.IsExperimental == isExperimental select m.Name;
            string s = "";
            foreach (var item in result) s += item.ToString() + "\n";
            string sExperimental = isExperimental ? "" : "не";
            MessageBox.Show(s, $"Все ${sExperimental}эксперементальные модули");
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            var x = SlImportance.Value;
            var result = from m in Modules where m.Importance > x select m.Name;
            string s = "";
            foreach (var item in result) s += item.ToString() + "\n";
            MessageBox.Show(s, $"Все модули с уровнем важности больше чем {x}");
        }

        private void SlImportance_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            lblSlImportance.Content = String.Format("{0:f2}:", SlImportance.Value);
        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            string s = "";
            switch (CmbFindOption.Text)
            {
                case "Уровнем ошибок":
                    s = Modules.OrderByDescending(item => item.ErrorFullness).First().Name;
                    break;
                case "Кол-вом дней в разработке":
                    s = Modules.OrderByDescending(item => item.DaysInProgress).First().Name;
                    break;
                case "Уровнем важности":
                    s = Modules.OrderByDescending(item => item.Importance).First().Name;
                    break;
                default:
                    s = Modules.OrderByDescending(item => item.Importance).First().Name;
                    break;
            }
            MessageBox.Show(s, "Найденный по критерию модуль");
        }

        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            // создаем поток для записи
            StreamWriter writer = new StreamWriter("Modules.xml");
            // создаем сериализатор
            XmlSerializer serializer = new XmlSerializer(typeof(UntestedModule[]));
            // и сериализуем объект
            serializer.Serialize(writer, Modules);
            writer.Close();
        }

        private void Button_Click_5(object sender, RoutedEventArgs e)
        {
            FileStream reader = new FileStream("Modules.xml", FileMode.Open,
                     FileAccess.Read);
            // создаем десериализатор
            XmlSerializer deserializer = new XmlSerializer(typeof(UntestedModule[]));
            // и десериализуем объект
            Modules = (UntestedModule[])deserializer.Deserialize(reader);
            reader.Close();

            UpdateModulesList();
        }

        private void Button_Click_6(object sender, RoutedEventArgs e)
        {
            DataContractJsonSerializer jsonFormatter = new DataContractJsonSerializer(typeof(UntestedModule[]));

            using (FileStream fs = new FileStream("people.json", FileMode.OpenOrCreate))
            {
                jsonFormatter.WriteObject(fs, Modules);
            }

            Console.ReadLine();
        }

        private void Button_Click_7(object sender, RoutedEventArgs e)
        {
            DataContractJsonSerializer jsonFormatter = new DataContractJsonSerializer(typeof(UntestedModule[]));

            using (FileStream fs = new FileStream("people.json", FileMode.OpenOrCreate))
            {
                Modules = (UntestedModule[])jsonFormatter.ReadObject(fs);

                UpdateModulesList();
            }
        }
    }
}
