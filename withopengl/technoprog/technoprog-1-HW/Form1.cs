using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using Emgu.CV;
using Emgu.CV.UI;
using Emgu.CV.Structure;
using Emgu.CV.CvEnum;
using System.Diagnostics;

using Emgu.CV.Util;

namespace technoprog_1_HW
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string fileName;
            OpenFileDialog op = new OpenFileDialog();
            op.ShowDialog();
            fileName = op.FileName;
            Image<Bgr, Byte> image =
                new Image<Bgr, byte>(fileName).Resize(400, 400, Emgu.CV.CvEnum.Inter.Linear, true);
            pictureBox1.Image = image;
        }

        private void buttonClrFilter_Click(object sender, EventArgs e)
        {
            Mat cannyEdges = CannyFilter();

            Image<Bgr, Byte> i1 = new Image<Bgr, Byte>(pictureBox1.Image.Size);
            Mat ccanny = new Mat();
            CvInvoke.CvtColor(cannyEdges, ccanny, ColorConversion.Gray2Bgr);
            CvInvoke.Subtract(pictureBox1.Image, ccanny, i1);
            for (int i = 0; i < i1.Width; i++)
                for (int j = 0; j < i1.Height; j++)
                {
                    if (i1.Data[j, i, 0] <= 50) i1.Data[j, i, 0] = 0;
                    else if (i1.Data[j, i, 0] <= 100) i1.Data[j, i, 0] = 25;
                    else if (i1.Data[j, i, 0] <= 150) i1.Data[j, i, 0] = 180;
                    else if (i1.Data[j, i, 0] <= 200) i1.Data[j, i, 0] = 210;
                    else i1.Data[j, i, 0] = 255; if (i1.Data[j, i, 1] <= 50) i1.Data[j, i, 1] = 0;
                    else if (i1.Data[j, i, 1] <= 100) i1.Data[j, i, 1] = 25;
                    else if (i1.Data[j, i, 1] <= 150) i1.Data[j, i, 1] = 180;
                    else if (i1.Data[j, i, 1] <= 200) i1.Data[j, i, 1] = 210;
                    else i1.Data[j, i, 1] = 255;
                    if (i1.Data[j, i, 2] <= 50) i1.Data[j, i, 2] = 0;
                    else if (i1.Data[j, i, 2] <= 100) i1.Data[j, i, 2] = 25;
                    else if (i1.Data[j, i, 2] <= 150) i1.Data[j, i, 2] = 180;
                    else if (i1.Data[j, i, 2] <= 200) i1.Data[j, i, 2] = 210;
                    else i1.Data[j, i, 2] = 255;
                }

            imageBoxTransform.Image = i1;
        }

        private Mat CannyFilter()
        {
            var uimage = pictureBox1.Image;
            double cannyThreshold = textBoxCT.Text == "" ? 80.0 : Double.Parse(textBoxCT.Text);
            double cannyThresholdLinking = textBoxCTL.Text == "" ? 40.0 : Double.Parse(textBoxCTL.Text);
            Mat cannyEdges = new Mat();
            CvInvoke.Canny(uimage, cannyEdges, cannyThreshold, cannyThresholdLinking);
            return cannyEdges;
        }

        private void buttonKanny_Click(object sender, EventArgs e)
        {
            Mat cannyEdges = CannyFilter();
            imageBoxTransform.Image = cannyEdges;
        }

        private void buttonLines_Click(object sender, EventArgs e)
        {
            Mat cannyEdges = CannyFilter();

            LineSegment2D[] lines = CvInvoke.HoughLinesP(cannyEdges,
                1, //разрешающая способность в пикселях 
                Math.PI / 45.0, //шаг поворота в радианах. 
                textBoxLimit.Text == "" ? 20 : Int16.Parse(textBoxLimit.Text), //пороговое значение 
                30, //минимальная ширина линии 
                10); //разрыв между линиями
            Mat lineImage = new Mat(pictureBox1.Image.Size, DepthType.Cv8U, 3);
            lineImage.SetTo(new MCvScalar(0));
            foreach (LineSegment2D line in lines) CvInvoke.Line(lineImage, line.P1, line.P2, new Bgr(Color.Green).MCvScalar, 2);
            imageBoxTransform.Image = lineImage;
        }
    }
}
