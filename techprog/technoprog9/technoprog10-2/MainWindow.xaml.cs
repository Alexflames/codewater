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
                Name = "баклажан с ИИ"
            },

            new UntestedModule {
                DaysInProgress = 65,
                Importance = 10,
                IsExperimental = true,
                Weight = 73485,
                Name = "протокол самоуничтожения"
            },

            new UntestedModule {
                DaysInProgress = 1,
                Importance = 85,
                IsExperimental = false,
                Weight = 200,
                Name = "Лабораторная №10 по ТП"
            }

            };

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            foreach (var obj in Modules) {
                listItems.Items.Add($"{obj.Name} -- {String.Format("{0:f2}", obj.ErrorFullness)}");
            }
        }
    }
}
