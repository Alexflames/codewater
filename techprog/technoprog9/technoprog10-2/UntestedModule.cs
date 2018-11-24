using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace technoprog10_2
{
    /// <summary>
    /// Программный модуль, к которому будет применено, возможно, тестирование
    /// </summary>
    class UntestedModule
    {
        public string Name { get; set; }

        /// <summary>
        /// Дней в разработке
        /// </summary>
        public int DaysInProgress { get; set; }
        
        /// <summary>
        /// Уровень возможных ошибок, чем больше тем более вероятны
        /// </summary>
        public double ErrorFullness {
            get {
                return (Weight * 0.01) * (1.0 + DaysInProgress / 0.01) * (1.0 + Importance * 0.01);
            }
        }

        /// <summary>
        /// Насколько объемный модуль, строки кода
        /// </summary>
        public double Weight { get; set; }

        /// <summary>
        /// Важность модуля, от 0 до 100
        /// </summary>
        public double Importance { get; set; }

        /// <summary>
        /// Эксперементальный модуль? Не запущен в производство?
        /// </summary>
        public bool IsExperimental { get; set; }

        public override string ToString()
        {
            string isExperimentalString = IsExperimental ? "V" : "X";
            return string.Format(
                "Название модуля: {0}\n" +
                "о Уровень возможных ошибок: {1}\n" +
                "о Количество строк кода: {2}\n" +
                "о Важность модуля (0 - 100): {3}\n" +
                "о Дней в разработке: {4}\n" +
                $"o {isExperimentalString}"
                );
        }
    }
}
