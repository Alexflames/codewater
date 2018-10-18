using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.OleDb;

namespace technoprog2_3
{
    public partial class Form1 : Form
    {
        private string fileName;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            dataGrid.Rows.Add(3);
        }

        private void buttonFill_Click(object sender, EventArgs e)
        {
            Random random = new Random();
            for (int i = 0; i < dataGrid.RowCount; i++)
            {
                for (int j = 0; j < dataGrid.ColumnCount - 1; j++)
                {
                    dataGrid[j, i].Value = random.Next(-100, 100);
                }
            }
        }

        private void buttonMin_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < dataGrid.RowCount; i++)
            {
                int minVal = Convert.ToInt32(dataGrid[0, i].Value);
                for (int j = 1; j < dataGrid.ColumnCount - 1; j++)
                {
                    int value = Convert.ToInt32(dataGrid[j, i].Value);
                    if (minVal > value)
                    {
                        minVal = value;
                    }
                }
                dataGrid[dataGrid.ColumnCount - 1, i].Value = minVal;
            }
        }

        private void buttonDBGetAll_Click(object sender, EventArgs e)
        {
            OpenFileDialog openfiledialog1 = new OpenFileDialog();
            openfiledialog1.Filter = "Access 2003 (*.mdb)|*.mdb|Access 2007|*.accdb";
            if (openfiledialog1.ShowDialog() == DialogResult.OK)
            {
                fileName = openfiledialog1.FileName;
                using (OleDbConnection con = new OleDbConnection(@"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + openfiledialog1.FileName))
                {
                    comboBox1.Items.Clear();
                    con.Open();
                    DataTable tbls = con.GetSchema("Tables", new string[] { null, null, null, "TABLE" }); //список всех таблиц
                    foreach (DataRow row in tbls.Rows)
                    {
                        string TableName = row["TABLE_NAME"].ToString();
                        comboBox1.Items.Add(TableName);
                    }
                }
            }
        }

        private void buttonDBQuery_Click(object sender, EventArgs e)
        {
            using (OleDbConnection con = new OleDbConnection(@"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + fileName))
            {
                con.Open();
                OleDbDataAdapter dbAdapter1 = new OleDbDataAdapter(@"SELECT " + comboBox1.SelectedItem + @".* FROM " + comboBox1.SelectedItem, con);
                DataTable dataTable = new DataTable();
                dbAdapter1.Fill(dataTable);
                dataGrid.DataSource = dataTable;
            }
            
        }
    }
}
