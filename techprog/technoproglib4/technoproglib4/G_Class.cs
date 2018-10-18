using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace technoproglib4
{
    public class G_Class
    {
        public static int Min(int x, int y)
        {
            return x < y ? x : y;
        }

        public static double Min(double x, double y)
        {
            return x < y ? x : y;
        }

        public static string Min(string x, string y)
        {
            return Int32.Parse(x) < Int32.Parse(y) ? x : y;
        }

        public static int Min()
        {
            return Int32.MinValue;
        }

        public int MinDyn(int x, int y)
        {
            return x < y ? x : y;
        }
    }

    public static class G_Class_Ext
    {
        public static bool Min(this double x, double y, double z)
        {
            return (x < y && x < z);
        }

        public static bool Min(this int x, int y, int z)
        {
            return (x < y && x < z);
        }
    }
}
