using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace techprog10_1
{
    public delegate double Geom(double r);           // объявление делегата

    class Program
    {
        public static double GeomD(double r)
        {
            return 2 * Math.PI * r;
        }

        public static double GeomS(double r)
        {
            return Math.PI * r * r;
        }

        public static double GeomV(double r)
        {
            return 4.0 / 3.0 * Math.PI * r * r * r;
        }


        static void Main(string[] args)
        {
            Console.WriteLine("Введите радиус R ");
            double R = Convert.ToDouble(Console.ReadLine());
            Geom geom = new Geom(GeomD);
            Console.WriteLine(" Длина окружности ");
            Console.WriteLine(geom(R));

            Console.WriteLine(" Площадь круга ");
            geom = new Geom(GeomS);
            Console.WriteLine(geom(R));

            Console.WriteLine(" Объем шара ");
            geom = new Geom(GeomV);
            Console.WriteLine(geom(R));
        }
    }
}
