using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace technoprog1_4._1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Calculate(object sender)
        {
            // Считывание начальных данных
            double x0 = Convert.ToDouble(textBoxX0.Text);
            double xk = Convert.ToDouble(textBoxXk.Text);
            double dx = Convert.ToDouble(textBoxDx.Text);
            double a = Convert.ToDouble(textBoxA.Text);
            double b = Convert.ToDouble(textBoxB.Text);
            double c = Convert.ToDouble(textBoxC.Text);
            // Цикл для табулирования функции
            double x = x0;
            if (sender == buttonCalculateDiv2)
            {
                dx /= 2;
            }
            richTextBox.Text = "";
            while (x <= (xk + dx / 2))
            {
                double y = (1 / 100) * b * c / x + Math.Cos(Math.Sqrt(a * a * a * x));
                richTextBox.Text += "x=" + Convert.ToString(x) +
                                 "; y=" + Convert.ToString(y) + Environment.NewLine;
                x = x + dx;
            }
        }

        private void buttonCalculate_Click(object sender, EventArgs e)
        {
            Calculate(sender);
        }

        private void buttonCalculateDiv2_Click(object sender, EventArgs e)
        {
            Calculate(sender);
        }
    }
}
