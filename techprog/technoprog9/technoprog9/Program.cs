using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using IndustrialLib;

namespace technoprog9
{
    class Program
    {
        static void Main(string[] args)
        {
            var building = new Building("Вольская 3", 345, 7, 15);
            Console.WriteLine(building);

            Console.WriteLine("* Выделено 30000 руб. на починку");
            building.Repair(30000);

            Console.WriteLine(building);

            Console.WriteLine();

            var car = new Car("34ОСО5", "Dodge Viper", 27092017, 67, 100);
            Console.WriteLine(car);

            Console.WriteLine("* Добавим 50л. топлива");
            car.FillUpFuel(50.0f);
            Console.Write(car);

            Console.WriteLine();
            Console.WriteLine();

            var flats = new Flat[]
            {
                new Flat(310, 3, 30, 1),
                new Flat(303, 3, 50, 3),
                new Flat(210, 2, 50, 1)
            };

            var threeFlatBuilding = new MultipleFlatBuilding("Volskaya", 3, flats);
            foreach (Flat flat in threeFlatBuilding)
            {
                Console.WriteLine(flat);
            }

            Console.WriteLine();

            foreach (Flat flat in threeFlatBuilding.FlatsIterarot())
            {
                Console.WriteLine(flat);
            }
        }
    }
}
