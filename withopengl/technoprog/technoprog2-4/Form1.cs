using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace technoprog2_4
{
    public partial class Form1 : Form
    {
        /// <summary>
        /// Левая граница графика
        /// </summary>
        private double x0 = -3;

        /// <summary>
        /// Правая граница графика
        /// </summary>
        private double xk = 3;

        /// <summary>
        /// Шаг графика
        /// </summary>
        private double dx = 1;

        // Массив значений X - общий для обоих графиков
        private double[] x1;
        private double[] x2;

        // Два массива Y - по одному для каждого графика
        private double[] y1;
        private double[] y2;

        Chart chart = new Chart();

        private void Calculate()
        {
            x1 = new double[100]; x2 = new double[100];
            y1 = new double[100]; y2 = new double[100];

            double a = -1.25;
            double b = -1.5;
            double c = 0.75;

            double x = x0;

            int i = 0;
            while (x <= (xk + dx / 2))
            {

                double y = b * c / x + Math.Cos(Math.Sqrt(a * a * a * x));
                if (y < 1000)
                {
                    x1[i] = x;
                    y1[i] = y;
                }
                x = x + dx;
                i++;
            }

            x = x0;
            i = 0;
            dx /= 2;
            while (x <= (xk + dx / 2))
            {

                double y = b * c / x + Math.Cos(Math.Sqrt(a * a * a * x));
                if (y < 1000)
                {
                    y2[i] = y;
                    x2[i] = x;
                }
                x = x + dx;
                i++;
            }
        }

        /// <summary>
        /// Создаём элемент управления Chart и настраиваем его
        /// </summary>
        private void CreateChart()
        {
            // Считывание начальных данных
            x0 = Convert.ToDouble(textBoxX0.Text); // -1.5
            xk = Convert.ToDouble(textBoxXk.Text); // 3.5
            dx = Convert.ToDouble(textBoxDx.Text); // 0.5

            // Помещаем Chart на форму
            chart.Parent = this;
            // Задаём размеры элемента
            chart.SetBounds(40, 40, ClientSize.Width - 50,
                            ClientSize.Height - 50);

            // Создаём новую область для построения графика
            ChartArea area = new ChartArea();
            // Даём ей имя (чтобы потом добавлять графики)
            area.Name = "myGraph";
            // Задаём левую и правую границы оси X
            area.AxisX.Minimum = x0;
            area.AxisX.Maximum = xk;
            // Определяем шаг сетки
            area.AxisX.MajorGrid.Interval = dx;
            // Добавляем область в диаграмму
            chart.ChartAreas.Add(area);

            // Создаём объект для первого графика
            Series series1 = new Series();
            // Ссылаемся на область для построения графика
            series1.ChartArea = "myGraph";
            // Задаём тип графика - сплайны
            series1.ChartType = SeriesChartType.Spline;
            // Указываем ширину линии графика
            series1.BorderWidth = 2;
            // Название графика для отображения в легенде
            series1.LegendText = "bc/x + cos(sqrt(a^3x))";
            // Добавляем в список графиков диаграммы
            chart.Series.Add(series1);
            // Аналогичные действия для второго графика
            Series series2 = new Series();
            series2.ChartArea = "myGraph";
            series2.ChartType = SeriesChartType.Spline;
            series2.BorderWidth = 2;
            series2.LegendText = "f(dx/2)";
            chart.Series.Add(series2);

            // Создаём легенду, которая будет показывать названия
            Legend legend = new Legend();
            chart.Legends.Add(legend);
        }


        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load_1(object sender, EventArgs e)
        {
            // Создаём элемент управления
            CreateChart();

            // Расчитываем значения точек графиков функций
            Calculate();

            // Добавляем вычисленные значения в графики
            chart.Series[0].Points.DataBindXY(x1, y1);
            chart.Series[1].Points.DataBindXY(x2, y2);
        }

        private void buttonCalculate_Click(object sender, EventArgs e)
        {
            // Создаём элемент управления
            chart.Series.Clear();
            chart.ChartAreas.Clear();
            CreateChart();

            // Расчитываем значения точек графиков функций
            Calculate();

            // Добавляем вычисленные значения в 
            chart.Series[0].Points.DataBindXY(x1, y1);
            chart.Series[1].Points.DataBindXY(x2, y2);
            chart.Update();
        }
    }
}
