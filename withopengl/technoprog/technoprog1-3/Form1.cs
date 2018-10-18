using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace technoprog1_3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // Получение данных из TextBox
            double x = Double.Parse(textInputX.Text);
            double y = Double.Parse(textInputY.Text);

            Func<double, double> func = null;
            int n;
            bool rbChecked = true;
            if (radioButton1.Checked)
            {
                func = Fun_sh_x;
            }
            else if (radioButton2.Checked)
            {
                func = Fun_sqr_x;
            }
            else if (radioButton3.Checked)
            {
                func = Fun_exp_x;
            }
            else
            {
                rbChecked = false;
                MessageBox.Show("Выберите функцию для вычисления");
            }
            if (rbChecked)
            {
                textBoxAns.Text = CalculateFuctionWithChosen(func, x, y).ToString();
            }
    }

        private double Fun_sh_x(double x)
        {
            return (Math.Exp(x) - Math.Exp(x)) / 2;
        }

        private double Fun_sqr_x(double x)
        {
            return x * x;
        }

        private double Fun_exp_x(double x)
        {
            return Math.Exp(x);
        }

        private double CalculateFuctionWithChosen(Func<double, double> func, double x, double y)
        {
            double condition = x * y;
            if (condition > 0)
            {
                double f_x = func(x);
                return (f_x + y) * (f_x + y) - Math.Sqrt(f_x * y);
            }
            else if (condition < 0)
            {
                double f_x = func(x);
                return (f_x + y) * (f_x + y) + Math.Sqrt(Math.Abs(f_x * y));
            }
            else
            {
                double f_x = func(x);
                return (f_x + y) * (f_x + y) + 1;
            }
        }
    }
}
