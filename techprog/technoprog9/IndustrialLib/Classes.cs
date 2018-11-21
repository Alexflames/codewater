using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IndustrialLib
{
    public class Building : IRepairable
    {
        public float Wear { get; set; }
        string Address;
        float SquareSize;
        int FloorCount;

        public Building(string address, float squareSize, int floorCount, float wear)
        {
            Address = address;
            SquareSize = squareSize;
            FloorCount = floorCount;
            Wear = wear;
        }

        public static implicit operator string(Building building)
        {
            return String.Format("Адрес: {0}, {1} кв.м. {2} этажей. Здание изношено на {3} ед.",
                building.Address, building.SquareSize, building.FloorCount, building.Wear);
        }

        public int RepairCost()
        {
            return (int)(Wear * 10 * SquareSize);
        }

        public void Repair(int money)
        {
            int repairCost = RepairCost();
            Wear -= money / (10 * SquareSize); 
        } 
    }

    public class Car : IFuelRunning
    {
        string RegNum;

        string CarMake; // Марка

        long CreationDate;

        public float FuelMeter { get; set; }
        public float MaxFuel { get; set; }

        public Car(string regNum, string carMake, long creationDate, float fuelMeter, float maxFuel)
        {
            RegNum = regNum;
            CarMake = carMake;
            CreationDate = creationDate;
            FuelMeter = fuelMeter;
            MaxFuel = maxFuel;
        }

        public void FillUpFuel(float fuel)
        {
            FuelMeter = FuelMeter + fuel > MaxFuel ? MaxFuel : FuelMeter;
        }

        public static implicit operator string(Car car)
        {
            return String.Format("Рег. номер: {0}, {1} {2}. Бак заполнен на {3:f3} / {4:f3} ",
                car.RegNum, car.CarMake, car.CreationDate.ToString("##-##-####"), car.FuelMeter, car.MaxFuel);
        }
    }

    public class Flat : IComparable
    {
        int Number;
        int Floor;
        float SquareSize;
        int RoomCount;

        public static implicit operator string(Flat flat)
        {
            return String.Format("Квартира номер: {0}, {1} этаж. {2} кв.м. - {3} комнаты",
                flat.Number, flat.Floor, flat.SquareSize, flat.RoomCount);
        }

        public Flat(int number, int floor, float squareSize, int roomCount)
        {
            Number = number;
            Floor = floor;
            SquareSize = squareSize;
            RoomCount = roomCount;
        }

        public int CompareTo(object obj)
        {
            return SquareSize.CompareTo(obj) == 0 ? RoomCount.CompareTo(obj) : SquareSize.CompareTo(obj);
        }

    }

    public class MultipleFlatBuilding : IEnumerable
    {
        string StreetName;
        int BuildingNumber;

        Flat[] Flats;

        public MultipleFlatBuilding(string streetName, int buildingNumber, Flat[] flats)
        {
            StreetName = streetName;
            BuildingNumber = buildingNumber;
            Flats = flats;
        }

        public IEnumerator GetEnumerator()
        {
            return Flats.GetEnumerator();
        }

        public IEnumerable FlatsIterarot()
        {
            for (int i = Flats.Length; i != 0; i--)
            {
                yield return Flats[i - 1];
            }
        }
    }
}
