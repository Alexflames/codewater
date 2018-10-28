using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace technoprog6_3
{

    class NamedObject
    {
        public string Name { get; }
        public NamedObject(string name)
        {
            this.Name = name;
        }

    }

    class Student : NamedObject
    {
        protected int[] _marks;

        public Student(int[] marks, string name) : base(name)
        {
            _marks = marks;
        }

        public double getAverageMark()
        {
            int sum = 0;
            foreach (var mark in _marks)
            {
                sum += mark;
            }
            return Math.Round((sum * 1.0) / _marks.Length, 3);
        }

        public static bool operator >(Student st1, Student st2)
        {
            return st1.getAverageMark() > st2.getAverageMark();
        }

        public static bool operator <(Student st1, Student st2)
        {
            return st1.getAverageMark() < st2.getAverageMark();
        }

        public override string ToString()
        {
            string toReturn = "";
            foreach (var mark in _marks)
            {
                toReturn += " " + mark;
            }
            return "[" + toReturn + " ]";
        }
    }

    class HighSchoolStudent <T> : Student {
        public T Info; // Любая информация об ученике
        
        int AutoFiveCount { get; set; } = 0;

        /// <summary>
        /// Студент, помимо обычных оценок имеются автоматы
        /// </summary>
        /// <param name="marks"> Массив целых чисел, оценки </param>
        /// <param name="name"> Имя студента </param>
        /// <param name="autoFiveCnt"> Количество автоматов </param>
        public HighSchoolStudent(int[] marks, string name, int autoFiveCnt) : base(marks, name) {
            AutoFiveCount = autoFiveCnt;
        }


        public new double getAverageMark()
        {
            int sum = 0;
            foreach (var mark in _marks)
            {
                sum += mark;
            }

            sum += AutoFiveCount * 5;
            return Math.Round((sum * 1.0) / (_marks.Length + AutoFiveCount), 3);
        }
    }

    class Program
    {
        static List<int> inputStudentMarks(char name)
        {
            Console.WriteLine("Введите оценки, полученные учащимся " + name);
            char[] delimiters = { ' ', ',' };
            List<int> studentAMarks = new List<int>();
            foreach (var mark in Console.ReadLine().Split(delimiters))
            {
                studentAMarks.Add(Convert.ToInt32(mark));
            }
            return studentAMarks;
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Пусть первый учащийся - студент, имеющий две пятерки автоматом");
            HighSchoolStudent<int> studentA =
                new HighSchoolStudent<int>(inputStudentMarks('A').ToArray(), "A (студент)", 2);
            Console.WriteLine("Средняя оценка: " + studentA.getAverageMark()); 
            Student studentB =
                new Student(inputStudentMarks('B').ToArray(), "B");
            Console.WriteLine("Средняя оценка: " + studentB.getAverageMark());
            Student studentC =
                new Student(inputStudentMarks('C').ToArray(), "C");
            Console.WriteLine("Средняя оценка: " + studentC.getAverageMark());

            Console.WriteLine("Средняя оценка учащегося " + studentA.Name 
                + " выше учащегося " + studentB.Name + " ? " + (studentA > studentB));
            Console.WriteLine("Средняя оценка учащегося " + studentA.Name
                + " выше учащегося " + studentC.Name + " ? " + (studentA > studentC));
            Console.WriteLine("Средняя оценка учащегося " + studentB.Name
                + " выше учащегося " + studentC.Name + " ? " + (studentB > studentC));

            Console.ReadKey();
        }
    }
}
