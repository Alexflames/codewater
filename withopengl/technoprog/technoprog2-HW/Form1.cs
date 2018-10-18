using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.OleDb;

namespace technoprog2_HW
{
    public partial class Form1 : Form
    {
        public static string connectString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source= 593_Database1.mdb;";
        // поле - ссылка на экземпляр класса OleDbConnection для соединения с БД
        private OleDbConnection myConnection;

        public Form1()
        {
            InitializeComponent();
            // создаем экземпляр класса OleDbConnection
            myConnection = new OleDbConnection(connectString);
            // открываем соединение с БД
            myConnection.Open();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            // закрываем соединение с БД
            myConnection.Close();   
        }

        private void buttonSelect_Click(object sender, EventArgs e)
        {
            // считываем ячейки
            string select1 = textBoxSelect1.Text;
            string select2 = textBoxSelect2.Text;
            string select3 = textBoxSelect3.Text;
            string where = textBoxWhere.Text;
            // текст запроса
            string query;
            if (select3 == "")
            {
                query = "SELECT "
                    + select1
                    + " FROM " + select2
                    + " WHERE " + where;
                // создаем объект OleDbCommand для выполнения запроса к БД MS Access
                OleDbCommand command = new OleDbCommand(query, myConnection);
                // выполняем запрос и выводим результат в textBox1
                textBoxAns.Text = command.ExecuteScalar().ToString();
            }
            else
            {
                query = "SELECT "
                    + select1
                    + " FROM " + select2
                    + " ORDER BY " + select3;
                // создаем объект OleDbCommand для выполнения запроса к БД MS Access
                OleDbCommand command = new OleDbCommand(query, myConnection);

                // получаем объект OleDbDataReader для чтения табличного результата запроса SELECT
                OleDbDataReader reader = command.ExecuteReader();

                // очищаем listBox1
                listBox1.Items.Clear();

                // в цикле построчно читаем ответ от БД
                while (reader.Read())
                {
                    string toAdd = "";
                    for (int i = 0; i < reader.VisibleFieldCount; i++)
                    {
                        reader[0].ToString();
                        // выводим данные столбцов текущей строки в listBox1
                        toAdd += reader[i].ToString() + " ";
                    }
                    listBox1.Items.Add(toAdd);
                }

                // закрываем OleDbDataReader
                reader.Close();
            }


        }

        private void buttonInsert_Click(object sender, EventArgs e)
        {
            // считывание данных
            string insert1 = textBoxInsertInto.Text;
            string insert2 = textBoxInsertValues.Text;
            // текст запроса
            string query = "INSERT INTO "
                + insert1
                + " VALUES " + insert2;

            // создаем объект OleDbCommand для выполнения запроса к БД MS Access
            OleDbCommand command = new OleDbCommand(query, myConnection);

            // выполняем запрос к MS Access
            command.ExecuteNonQuery();
        }

        private void buttonUpdate_Click(object sender, EventArgs e)
        {
            // считывание данных
            string update1 = textBoxUpdate1.Text;
            string update2 = textBoxUpdateSet.Text;
            string where = textBoxWhere.Text;

            // текст запроса
            string query = "UPDATE "
                + update1
                + " SET " + update2;
            if (where != "")
            {
                query += " Where " + where;
            }

            // создаем объект OleDbCommand для выполнения запроса к БД MS Access
            OleDbCommand command = new OleDbCommand(query, myConnection);

            // выполняем запрос к MS Access
            command.ExecuteNonQuery();
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            // считывание данных
            string delete1 = textBoxDeleteFrom.Text;
            string where = textBoxWhere.Text;
            // текст запроса
            string query = "DELETE FROM "
                + delete1
                + " WHERE " + where;

            // создаем объект OleDbCommand для выполнения запроса к БД MS Access
            OleDbCommand command = new OleDbCommand(query, myConnection);

            // выполняем запрос к MS Access
            command.ExecuteNonQuery();
        }
    }
}
