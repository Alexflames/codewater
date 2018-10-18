namespace technoprog5_1
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.buttonSave = new System.Windows.Forms.Button();
            this.buttonBuild = new System.Windows.Forms.Button();
            this.checkBoxGenXML = new System.Windows.Forms.CheckBox();
            this.buttonPathcsc = new System.Windows.Forms.Button();
            this.richTextBoxBuild = new System.Windows.Forms.RichTextBox();
            this.richTextBoxPrj = new System.Windows.Forms.RichTextBox();
            this.button5 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.richTextBox4 = new System.Windows.Forms.RichTextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(42, 32);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.Size = new System.Drawing.Size(351, 415);
            this.richTextBox1.TabIndex = 0;
            this.richTextBox1.Text = "";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(468, 32);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(128, 34);
            this.button1.TabIndex = 1;
            this.button1.Text = "Открыть";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // buttonSave
            // 
            this.buttonSave.Location = new System.Drawing.Point(468, 95);
            this.buttonSave.Name = "buttonSave";
            this.buttonSave.Size = new System.Drawing.Size(128, 31);
            this.buttonSave.TabIndex = 2;
            this.buttonSave.Text = "Сохранить";
            this.buttonSave.UseVisualStyleBackColor = true;
            this.buttonSave.Click += new System.EventHandler(this.button2_Click);
            // 
            // buttonBuild
            // 
            this.buttonBuild.Location = new System.Drawing.Point(468, 156);
            this.buttonBuild.Name = "buttonBuild";
            this.buttonBuild.Size = new System.Drawing.Size(128, 30);
            this.buttonBuild.TabIndex = 3;
            this.buttonBuild.Text = "Сборка";
            this.buttonBuild.UseVisualStyleBackColor = true;
            this.buttonBuild.Click += new System.EventHandler(this.buttonBuild_Click);
            // 
            // checkBoxGenXML
            // 
            this.checkBoxGenXML.AutoSize = true;
            this.checkBoxGenXML.Location = new System.Drawing.Point(453, 219);
            this.checkBoxGenXML.Name = "checkBoxGenXML";
            this.checkBoxGenXML.Size = new System.Drawing.Size(264, 21);
            this.checkBoxGenXML.TabIndex = 4;
            this.checkBoxGenXML.Text = "Создать XML-документацию файла";
            this.checkBoxGenXML.UseVisualStyleBackColor = true;
            // 
            // buttonPathcsc
            // 
            this.buttonPathcsc.Location = new System.Drawing.Point(468, 297);
            this.buttonPathcsc.Name = "buttonPathcsc";
            this.buttonPathcsc.Size = new System.Drawing.Size(156, 23);
            this.buttonPathcsc.TabIndex = 5;
            this.buttonPathcsc.Text = "Путь к файлу сборки";
            this.buttonPathcsc.UseVisualStyleBackColor = true;
            this.buttonPathcsc.Click += new System.EventHandler(this.buttonPathcsc_Click);
            // 
            // richTextBoxBuild
            // 
            this.richTextBoxBuild.Location = new System.Drawing.Point(468, 337);
            this.richTextBoxBuild.Name = "richTextBoxBuild";
            this.richTextBoxBuild.Size = new System.Drawing.Size(156, 51);
            this.richTextBoxBuild.TabIndex = 6;
            this.richTextBoxBuild.Text = "";
            // 
            // richTextBoxPrj
            // 
            this.richTextBoxPrj.Location = new System.Drawing.Point(468, 434);
            this.richTextBoxPrj.Name = "richTextBoxPrj";
            this.richTextBoxPrj.Size = new System.Drawing.Size(156, 51);
            this.richTextBoxPrj.TabIndex = 8;
            this.richTextBoxPrj.Text = "";
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(468, 394);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(178, 34);
            this.button5.TabIndex = 7;
            this.button5.Text = "Путь к файлам проекта";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(776, 37);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(209, 17);
            this.label1.TabIndex = 9;
            this.label1.Text = "Сообщение командной строки";
            // 
            // richTextBox4
            // 
            this.richTextBox4.Location = new System.Drawing.Point(754, 61);
            this.richTextBox4.Name = "richTextBox4";
            this.richTextBox4.Size = new System.Drawing.Size(259, 403);
            this.richTextBox4.TabIndex = 10;
            this.richTextBox4.Text = "";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(453, 246);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(264, 22);
            this.textBox1.TabIndex = 11;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1035, 551);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.richTextBox4);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.richTextBoxPrj);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.richTextBoxBuild);
            this.Controls.Add(this.buttonPathcsc);
            this.Controls.Add(this.checkBoxGenXML);
            this.Controls.Add(this.buttonBuild);
            this.Controls.Add(this.buttonSave);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.richTextBox1);
            this.Name = "Form1";
            this.Text = "Лаб №5 Григорьев А.А. 351 КНиИТ";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

							 /// Very rich textBox1
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button buttonSave;
        private System.Windows.Forms.Button buttonBuild;
        private System.Windows.Forms.CheckBox checkBoxGenXML;
        private System.Windows.Forms.Button buttonPathcsc;
        private System.Windows.Forms.RichTextBox richTextBoxBuild;
        private System.Windows.Forms.RichTextBox richTextBoxPrj;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.RichTextBox richTextBox4;
        private System.Windows.Forms.TextBox textBox1;
    }
}

