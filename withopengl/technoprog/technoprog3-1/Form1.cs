using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace technoprog3_1
{
    public partial class Form1 : Form
    {
        Graphics g_graph;
        // Коэффициенты для матриц
        private float x_offset = 0;
        private float y_offset = 0;
        private float xy_mult = 1;
        private float rotate_angle = 0;


        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Matrix matMult = new Matrix();
            matMult.Scale(xy_mult, xy_mult);

            g.MultiplyTransform(matMult);
            g.RotateTransform(rotate_angle);
            g.TranslateTransform(x_offset, y_offset);
            
            g.DrawEllipse(
                new Pen(
                    new HatchBrush(HatchStyle.DashedDownwardDiagonal,
                        Color.DodgerBlue, 
                        Color.DarkGoldenrod),
                        20),
                200, 100, 50, 100);
            
            g.DrawRectangle(new Pen(Brushes.CornflowerBlue, 3), 200, 100, 50, 100);



            /*
            Pen p = new Pen(Color.Green, 2);
            Rectangle rect = new Rectangle(10, 10, 200, 200);
            e.Graphics.DrawEllipse(p, rect);
            p.Dispose();
            */
            Bitmap bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            Graphics gr = Graphics.FromImage(bmp);
            LinearGradientBrush gradientBrush = new LinearGradientBrush(new Point(0, 0), new Point(40, 40), Color.Green, Color.Blue);
            gr.FillEllipse(gradientBrush, 100, 10, 40, 40);
            
            for (int i = 0; i < pictureBox1.Height; i += 5)
            {
                gr.DrawLine(new Pen(Color.Aquamarine, 0.25f), 0, i, pictureBox1.Width, i);
                
            }
            pictureBox1.Image = bmp;
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
 //           this.Invalidate(); // Вызывает событие Redraw

            int amp = 70; //амплитуда
            int h = 40; //отступ для текста
            int x0 = 20; //начала координат
            int y0 = h + amp;
            List<double> f = new List<double>();
            // Начальный, конечный x, шаг
            double x = -3.5;
            float xk = 2.5f;
            double dx = 0.015;

            // Константы в формуле
            double a = -1.25;
            double b = -1.5;
            double c = 0.75;
            while (x <= (xk + dx / 2))
            {

                double y = b * c / x + Math.Cos(Math.Sqrt(a * a * a * x));
                if (y < 3)
                {
                    f.Add(y * 25);
                }
                x = x + dx;
            }
            // Инструменты рисования
            g_graph = Graphics.FromHwnd(this.Handle); // Где рисуем
            Pen pen = Pens.Black; // Чем рисуем
                                  // Текст заголовка
            g_graph.DrawString("График функции", new Font("Arial", 14), Brushes.MediumPurple, 0, 0); //Вывод текста
                                                                                        //textBox1.Text = "График синусоиды";
                                                                                        //Рисуем график
            g_graph.DrawLine(pen, x0, y0, x0 + (xk * 100), y0); //Рисуем ось X
            g_graph.DrawLine(pen, x0, y0 - amp, x0, y0 + amp); //Рисуем ось Y
            for (int i = 0; i < f.Count - 1; i++) //Рисуем график
            {
                float f1 = y0 - (float)f[i]; //Координата Y[i]
                float f2 = y0 - (float)f[i + 1]; //Координата Y[i+1]
                g_graph.DrawLine(pen, x0 + i, f1, x0 + i + 1, f2);
            }

        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.D:
                    x_offset += 5.0f;
                    break;
                case Keys.A:
                    x_offset -= 5.0f;
                    break;
                case Keys.W:
                    y_offset -= 5.0f;
                    break;
                case Keys.S:
                    y_offset += 5.0f;
                    break;
                case Keys.D1:
                    xy_mult += 0.05f;
                    break;
                case Keys.D2:
                    xy_mult -= 0.05f;
                    break;
                case Keys.Q:
                    rotate_angle += 1.0f;
                    break;
                case Keys.E:
                    rotate_angle -= 1.0f;
                    break;
                default:
                    break;
            }
            this.Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Form1_KeyPress(object sender, KeyPressEventArgs e)
        {

        }
    }
}
