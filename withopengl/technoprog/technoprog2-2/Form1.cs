using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace technoprog2_2
{
    public partial class Form1 : Form
    {
        int[] Mas = new int[20];

        public Form1()
        {
            InitializeComponent();
        }

        private void buttonFill_Click(object sender, EventArgs e)
        {
            Random rand = new Random();

            listBoxData.Items.Clear();

            for (int i = 0; i < Mas.Length; i++)
            {
                Mas[i] = rand.Next(-50, 50);
                listBoxData.Items.Add("Mas[" + Convert.ToString(i) + "] = "
                                      + Convert.ToString(Mas[i]));
            }

            listBoxAns.Items.Clear();
        }

        private void buttonSwitch_Click(object sender, EventArgs e)
        {
            listBoxAns.Items.Clear();
            int maxI = 0;
            for (int i = 0; i < Mas.Length; i++)
            {
                if (Mas[i] > Mas[maxI]) maxI = i;
                listBoxAns.Items.Add("Mas[" + Convert.ToString(i) + "] = "
                                     + Convert.ToString(Mas[i]));
            }
            int temp = Mas[0];
            Mas[0] = Mas[maxI];
            listBoxAns.Items[0] = "Mas[0] = " + Convert.ToString(Mas[0]);
            Mas[maxI] = temp;
            listBoxAns.Items[maxI] = "Mas[" + maxI + "] = " + Convert.ToString(Mas[maxI]);
        }
    }
}
