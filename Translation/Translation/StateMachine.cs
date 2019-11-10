using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Translation
{
    //class MyEnum
    //{
    //    public static readonly MyEnum UNDEFINED = new MyEnum("undefined"); 

    //    public override string ToString()
    //    {
    //        return Value;
    //    }

    //    protected MyEnum(string value)
    //    {
    //        this.Value = value;
    //    }

    //    public string Value { get; private set; }
    //}

    public abstract class StateMachine
    {
        protected string State;

        // <state, input> : state
        protected struct PairS
        {
            string a;
            string b;
            public PairS(string first, string second)
            {
                a = first;
                b = second;
            }
        }
        protected HashSet<string> Q = new HashSet<string>();
        protected HashSet<string> E = new HashSet<string>();
        protected Dictionary<PairS, string> D = new Dictionary<PairS, string>();
        protected HashSet<string> S = new HashSet<string>();
        protected HashSet<string> F = new HashSet<string>();

        //--------------------------------------
        // Чистые геттеры
        public string GetState()
        {
            return State;
        }

        public override string ToString()
        {
            return "Автомат: " + this.GetType().Name + '\n' +
                "Текущее состояние: " + State + '\n';
        }

        public bool isFinalState()
        {
            return F.Contains(State);
        }

        //--------------------------------------
        // Акторы

        public string this[string i]
        {
            get { return NextState(i); }
            set { NextState(i); }
        }

        public virtual string NextState(string input)
        {
            if (D.ContainsKey(new PairS(State, input)))
            {
                PairS StateInput = new PairS(State, input);
                State = D[StateInput];
            }
            else
            {
                State = "BROKE";
            }

            return State;
        }

        public void ResetState()
        {
            State = S.First();
        }
    }
}
