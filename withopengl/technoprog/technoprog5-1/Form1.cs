using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;

namespace technoprog5_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.ShowDialog();
            string filename = openFileDialog.FileName;
            if (filename != "")
                richTextBox1.LoadFile(filename, RichTextBoxStreamType.PlainText);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //сохранение файла
            SaveFileDialog savedialog = new SaveFileDialog();//описываем и порождаем объект savedialog 
            //задаем свойства для savedialog
            savedialog.Title = "Сохранить картинку как ...";
            savedialog.OverwritePrompt = true;
            savedialog.CheckPathExists = true;
            savedialog.Filter =
                "Text Files(*.txt)|*.txt|Response files(*.rsp)|*.rsp|CSharp Files(*.cs)|*.cs|All files(*.*)|*.*";
            savedialog.ShowHelp = true;
            // If selected, save
            if (savedialog.ShowDialog() == DialogResult.OK)//вызываем диалоговое окно и проверяем задано ли имя файла
            {
                // в строку fileName записываем указанный в savedialog полный путь к файлу
                string fileName = savedialog.FileName;
                richTextBox1.SaveFile(fileName, RichTextBoxStreamType.PlainText);
            }
        }

        /// <summary>
        ///  Building it ok?
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void buttonBuild_Click(object sender, EventArgs e)
        {
            string cscPath = richTextBoxBuild.Text;
            string command = richTextBox1.Text;
            string csCodePath = richTextBoxPrj.Text;

            var startInfo = new ProcessStartInfo(cscPath, command);
            startInfo.StandardOutputEncoding = Encoding.GetEncoding(866);
            // указываем папку из которой производится запуск команд
            startInfo.WorkingDirectory = csCodePath;
            startInfo.UseShellExecute = false;
            startInfo.CreateNoWindow = true;
            startInfo.RedirectStandardOutput = true;
            var proc = new Process();
            proc.StartInfo = startInfo;
            proc.Start();
            var result = proc.StandardOutput.ReadToEnd();
            proc.WaitForExit();
            // вывод сообщений командной строки
            richTextBox4.Text = result;

            // генерация XML - документации
            if (checkBoxGenXML.Checked) {
                string XMLcommand = "/doc:" + "Progdoc.xml " + textBox1.Text;
                startInfo = new ProcessStartInfo(cscPath, XMLcommand);
                startInfo.StandardOutputEncoding = Encoding.GetEncoding(866);
                // указываем папку из которой производится запуск команд
                startInfo.WorkingDirectory = csCodePath;
                startInfo.UseShellExecute = false;
                startInfo.CreateNoWindow = true;
                startInfo.RedirectStandardOutput = true;
                proc = new Process();
                proc.StartInfo = startInfo;
                proc.Start();
                result = proc.StandardOutput.ReadToEnd();
                proc.WaitForExit();
                // вывод сообщений командной строки
                richTextBox4.Text += "\n" + result;
            }
        }

        private void buttonPathcsc_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.ShowDialog();

            string filename = openFileDialog.FileName;
            richTextBoxBuild.Text = filename;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog folderDialog = new FolderBrowserDialog();
            folderDialog.ShowDialog();

            richTextBoxPrj.Text = folderDialog.SelectedPath;
        }
    }
}
