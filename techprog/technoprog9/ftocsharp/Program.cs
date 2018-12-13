using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using fsharpLib;

namespace ftocsharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Building building = new Building("Вольская 10А", 1500, 7, "1 января 1998", 75);
            Building building2 = new Building("Рандомная 100/120", 300, 2, "13 декабря 2018", 1);
            var building1Data = building.getData;
            Console.WriteLine($"Адрес: {building1Data.Item1} \n Площадь: {building1Data.Item2} " +
                $"\n  Кол-во этажей: {building1Data.Item3} \n Дата постройки {building1Data.Item4}\n");
            building2.print();
        }
    }
}
