using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace technoprog2_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void buttonCalculate_Click(object sender, EventArgs e)
        {
            try
            {
                // Номер выделенной строки
                int index = listBox1.SelectedIndex;
                // Считываем строку в перменную str
                string str = (string)listBox1.Items[index];
                // Узнаем количество символов в строке
                int len = str.Length;
                // Считаем, что количество нулей равно 0
                int countZeros = 0;
                int countOnes = 0;
                // Устанавливаем счетчик символов в 0
                int i = 0;
                //Организуем цикл перебора всех символов в строке
                while (i < len)
                {
                    // Если нашли пробел, то увеличиваем
                    // счетчик пробелов на 1
                    if (str[i] == '0')
                        countZeros++;
                    else if (str[i] == '1')
                        countOnes++;
                    i++;
                }
                labelZeros.Text = countZeros.ToString();
                labelOnes.Text = countOnes.ToString();
            }
            catch (Exception)
            {
                MessageBox.Show("Выделите строку для подсчета нулей и единиц");
            }
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            Random rand = new Random();
            int len = rand.Next(4, 7);
            for (int i = 0; i < len; i++)
            {
                string stringToIns = "";
                for (int j = 0; j < 10; j++) {
                    int chooseRand = rand.Next(0, 3);
                    switch (chooseRand)
                    {
                        case 0:
                            stringToIns += "0";
                            break;
                        case 1:
                            stringToIns += "1";
                            break;
                        case 2:
                            stringToIns += " ";
                            break;
                        default:
                            break;
                    }
                }
                listBox1.Items.Insert(i, stringToIns);
            }
        }
    }
}
