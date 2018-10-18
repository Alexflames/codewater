using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace technoprog
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void buttonWOW_Click(object sender, EventArgs e)
        {
            BackColor = Color.White;
            MessageBox.Show("Великолепная краска закончилась");
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            BackColor = Color.AntiqueWhite;
        }

        private void buttonRed_Click(object sender, EventArgs e)
        {
            BackColor = Color.PaleVioletRed;
        }

        private void buttonGreen_Click(object sender, EventArgs e)
        {
            BackColor = Color.ForestGreen;
        }

        private void buttonBlue_Click(object sender, EventArgs e)
        {
            BackColor = Color.CadetBlue;
        }

        private void buttonYellow_Click(object sender, EventArgs e)
        {
            BackColor = Color.LightGoldenrodYellow;
        }
    }
}
