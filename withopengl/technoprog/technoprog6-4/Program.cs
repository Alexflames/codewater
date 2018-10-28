using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace technoprog6_4
{
    class Program
    {
        class CharSet
        {
            Dictionary<char, bool> CharExists { get; } = new Dictionary<char, bool>();

            public CharSet(string inputStr)
            {
                foreach (char ch in inputStr)
                {
                    if (ch != ' ' && !CharExists.ContainsKey(ch))
                    {
                        CharExists.Add(ch, true);
                    }
                }
            }

            /// <summary>
            /// Копирует в новое множество элементы другого множества, не превышающие заданное значение
            /// </summary>
            /// <param name="charSetToCopy"> Копируемое множество </param>
            /// <param name="charCopyUpTo"> Символ, который не будут превышать </param>
            public CharSet(CharSet charSetToCopy, char charCopyUpTo)
            {
                foreach (var ch in charSetToCopy.CharExists)
                {
                    if (ch.Value && ch.Key < charCopyUpTo)
                    {
                        CharExists.Add(ch.Key, ch.Value);
                    }
                }
            }

            /// <summary>
            /// Находит символ - среднее значение среди всех в множестве
            /// </summary>
            /// <returns> Символ - среднее значение </returns>
            private char MiddleChar()
            {
                int sum = 0;
                int cnt = 0;
                foreach (var ch in CharExists)
                {
                    sum += ch.Key;
                    cnt++;
                }

                return Convert.ToChar(sum / cnt);
            }

            public static implicit operator char(CharSet charSet)
            {
                return charSet.MiddleChar();
            }

            public static explicit operator CharSet(char ch)
            {
                return new CharSet(ch.ToString());
            }

            public static implicit operator string(CharSet charSet)
            {
                string toReturn = "";
                foreach (var ch in charSet.CharExists)
                {
                    if (ch.Value)
                    {
                        toReturn += ch.Key + " ";
                    }
                }
                return toReturn;
            }

            ~CharSet()
            {
                Console.WriteLine("Множество уничтожено");
            }
        }

        class ComplexNum {
            public double Re { get; set; } = 0;
            public double Im { get; set; } = 0;

            public ComplexNum(double a, double b)
            {
                Re = a;
                Im = b;
            }

            public static ComplexNum operator + (ComplexNum complex1, ComplexNum complex2)
            {
                return new ComplexNum(complex1.Re + complex2.Re, complex1.Im + complex2.Im);
            }

            public static ComplexNum operator * (ComplexNum complex1, ComplexNum complex2)
            {
                return new ComplexNum(
                    complex1.Re * complex2.Re - complex1.Im * complex2.Im,
                    complex1.Re * complex2.Im + complex2.Re * complex1.Im);
            }

            public static bool operator ==(ComplexNum complex1, ComplexNum complex2)
            {
                return complex1.Re == complex2.Re && complex1.Im == complex2.Im;
            }

            public static bool operator !=(ComplexNum complex1, ComplexNum complex2)
            {
                return !(complex1.Re == complex2.Re && complex1.Im == complex2.Im);
            }

            public static implicit operator string(ComplexNum complexNum)
            {
                if (complexNum.Im > 0)
                {
                    return Convert.ToString(Math.Floor(complexNum.Re)) + " + "
                        + Convert.ToString(Math.Floor(complexNum.Im)) + "i";
                }
                else if (complexNum.Im < 0)
                {
                    return Convert.ToString(Math.Floor(complexNum.Re)) + " "
                        + Convert.ToString(Math.Floor(complexNum.Im)) + "i";
                }
                else
                {
                    return Convert.ToString(Math.Floor(complexNum.Re));
                }
            }

        }

        static void Main(string[] args)
        {
            Console.WriteLine("Введите строку - множество символов");
            CharSet charSet = new CharSet(Console.ReadLine());
            Console.WriteLine("Множество: " + charSet);
            
            if (true)
            {
                CharSet charSetCopy = new CharSet(charSet);
                Console.WriteLine("Множество-копия: " + charSetCopy);
            }
            
            char middleChar = charSet;
            Console.WriteLine("Средний элемент: " + middleChar);

            Console.WriteLine();
            Console.WriteLine("Введите первое комплексное число - действительная и мнимая часть через пробел");
            string[] input = Console.ReadLine().Split(' ');
            ComplexNum cnum1 = new ComplexNum(Convert.ToDouble(input[0]), Convert.ToDouble(input[1]));
            Console.WriteLine("Введите второе комплексное число");
            input = Console.ReadLine().Split(' ');
            ComplexNum cnum2 = new ComplexNum(Convert.ToDouble(input[0]), Convert.ToDouble(input[1]));
            Console.WriteLine("Их сложение: " + (cnum1 + cnum2));
            Console.WriteLine("Их произведение: " + (cnum1 * cnum2));
            Console.WriteLine("Они равны? " + (cnum1 == cnum2));

            Console.ReadKey();
        }
    }
}
