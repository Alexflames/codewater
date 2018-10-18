using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace technoprog1_2
{
    public partial class lab1task2 : Form
    {
        public lab1task2()
        {
            InitializeComponent();
        }

        private void buttonCalculate_Click(object sender, EventArgs e)
        {
            double x, y, z;
            try
            {
                x = Double.Parse(textInputX.Text);
                y = Double.Parse(textInputY.Text);
                z = Double.Parse(textInputZ.Text); // Exp - format
                double ans = 2 * Math.Cos(x - Math.PI / 6) /
                    (0.5 + Math.Sin(y) * Math.Sin(y)) *
                    (1 + (z * z) / (3 - z * z / 5));
                textAnswer.Text = Math.Round(ans, 6).ToString();
            }
            catch (DivideByZeroException)
            {
                MessageBox.Show("Произошло деление на 0");
            }
            catch (Exception)
            {
                MessageBox.Show("В каждом текстовом поле должно быть число");
            }

        }
    }
}
