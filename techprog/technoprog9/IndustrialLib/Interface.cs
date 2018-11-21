using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IndustrialLib
{
    interface IRepairable
    {
        float Wear { get; set; }

        int RepairCost();

        void Repair(int MoneyToPay);
    }

    interface IFuelRunning
    {
        float FuelMeter { get; set; }

        float MaxFuel { get; }

        void FillUpFuel(float volume);
    }
}
