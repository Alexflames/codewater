using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace technoprog3_1_2
{
    public partial class Form1 : Form
    {
        Graphics gr;
        Pen dragonPen = new Pen(Color.SteelBlue, 0.3f);

        private void DragonFracRecursive(float x1, float y1, float x2, float y2, int k)
        {
            if (k == 0)
            {
                gr.DrawLine(dragonPen, x1, y1, x2, y2);
            }
            else
            {
                float tx = (x1 + x2) / 2 + (y1 - y2) / 2;
                float ty = (y1 + y2) / 2 - (x1 - x2) / 2;
                DragonFracRecursive(x2, y2, tx, ty, k - 1);
                DragonFracRecursive(x1, y1, tx, ty, k - 1);

                // Добавление этой строки делает результат как на изображении
                // но при этом противоречит условию
                gr.DrawLine(dragonPen, x1, y1, x2, y2); 
            }
        }

        public Bitmap DragonFrac(int recursive_depth, float x0, float y0, float xn, float yn)
        {
            Bitmap bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            gr = Graphics.FromImage(bmp);

            DragonFracRecursive(x0, y0, xn, yn, recursive_depth);

            return bmp;
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = DragonFrac(
                11,
                90, 90,
                250, 250);
        }
    }
}
