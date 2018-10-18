using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace technoprog3_2
{
    public partial class Form1 : Form
    {
        //описываем переменные достыпные в любом обработчике событий класса Form1
        private int x1, y1, width, height;
        private float[] sizeMult = { 0.5f, 0.6f, 0.85f, 1.0f, 0.9f, 0.75f };
        private int sizeMultI = 0;
        private SolidBrush brush = new SolidBrush(Color.IndianRed);

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //определяем цент экрана
            x1 = ClientSize.Width / 2;
            y1 = ClientSize.Height / 2;
            //определяем конец часовой стрелки с учетом центра экрана
            width = 200;
            height = 120;
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            g.TranslateTransform(
                (ClientSize.Width + width) / 2,
                (ClientSize.Height + height) / 2);

            g.ScaleTransform(sizeMult[sizeMultI], sizeMult[sizeMultI]);

            g.RotateTransform(-135);

            g.TranslateTransform(
                -1 * (ClientSize.Width + width) / 2,
                -1 * (ClientSize.Height + height) / 2);

            g.FillEllipse(brush, x1 + 110, y1, width, height);
            g.FillEllipse(brush, x1 + 100, y1 + 10, height, width);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            sizeMultI = (sizeMultI + 1) % sizeMult.Length;
            Invalidate(); //вынудительный вызов перерисовки (Paint)
        }
    }
}
