namespace technoprog2_1
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
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.buttonCalculate = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.labelZeros = new System.Windows.Forms.Label();
            this.labelOnes = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // listBox1
            // 
            this.listBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 25;
            this.listBox1.Items.AddRange(new object[] {
            "110 10",
            "0000000",
            "1",
            "000100",
            "10 1010 1"});
            this.listBox1.Location = new System.Drawing.Point(12, 12);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(155, 129);
            this.listBox1.TabIndex = 0;
            // 
            // buttonCalculate
            // 
            this.buttonCalculate.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.buttonCalculate.Location = new System.Drawing.Point(173, 12);
            this.buttonCalculate.Name = "buttonCalculate";
            this.buttonCalculate.Size = new System.Drawing.Size(153, 60);
            this.buttonCalculate.TabIndex = 2;
            this.buttonCalculate.Text = "Посчитать кол-во 0 и 1";
            this.buttonCalculate.UseVisualStyleBackColor = true;
            this.buttonCalculate.Click += new System.EventHandler(this.buttonCalculate_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label1.Location = new System.Drawing.Point(184, 92);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(74, 25);
            this.label1.TabIndex = 5;
            this.label1.Text = "Нулей:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label2.Location = new System.Drawing.Point(327, 92);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(93, 25);
            this.label2.TabIndex = 6;
            this.label2.Text = "Единиц: ";
            // 
            // labelZeros
            // 
            this.labelZeros.AutoSize = true;
            this.labelZeros.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.labelZeros.Location = new System.Drawing.Point(264, 92);
            this.labelZeros.Name = "labelZeros";
            this.labelZeros.Size = new System.Drawing.Size(17, 25);
            this.labelZeros.TabIndex = 7;
            this.labelZeros.Text = " ";
            // 
            // labelOnes
            // 
            this.labelOnes.AutoSize = true;
            this.labelOnes.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.labelOnes.Location = new System.Drawing.Point(426, 92);
            this.labelOnes.Name = "labelOnes";
            this.labelOnes.Size = new System.Drawing.Size(17, 25);
            this.labelOnes.TabIndex = 8;
            this.labelOnes.Text = " ";
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.button1.Location = new System.Drawing.Point(332, 12);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(153, 60);
            this.button1.TabIndex = 9;
            this.button1.Text = "Заполнить программно";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(497, 165);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.labelOnes);
            this.Controls.Add(this.labelZeros);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.buttonCalculate);
            this.Controls.Add(this.listBox1);
            this.Name = "Form1";
            this.Text = "Лаб №2 Обработка строк - 351 Григорьев А.А.";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Button buttonCalculate;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label labelZeros;
        private System.Windows.Forms.Label labelOnes;
        private System.Windows.Forms.Button button1;
    }
}

