namespace technoprog2_4
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
            this.label6 = new System.Windows.Forms.Label();
            this.textBoxDx = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxXk = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.textBoxX0 = new System.Windows.Forms.TextBox();
            this.buttonCalculate = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label6.Location = new System.Drawing.Point(339, 15);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(33, 25);
            this.label6.TabIndex = 17;
            this.label6.Text = "dx";
            // 
            // textBoxDx
            // 
            this.textBoxDx.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textBoxDx.Location = new System.Drawing.Point(393, 12);
            this.textBoxDx.Name = "textBoxDx";
            this.textBoxDx.Size = new System.Drawing.Size(53, 30);
            this.textBoxDx.TabIndex = 16;
            this.textBoxDx.Text = "0,5";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label2.Location = new System.Drawing.Point(185, 15);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(32, 25);
            this.label2.TabIndex = 15;
            this.label2.Text = "xk";
            // 
            // textBoxXk
            // 
            this.textBoxXk.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textBoxXk.Location = new System.Drawing.Point(223, 15);
            this.textBoxXk.Name = "textBoxXk";
            this.textBoxXk.Size = new System.Drawing.Size(85, 30);
            this.textBoxXk.TabIndex = 14;
            this.textBoxXk.Text = "3,4999";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label1.Location = new System.Drawing.Point(17, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(33, 25);
            this.label1.TabIndex = 13;
            this.label1.Text = "x0";
            // 
            // textBoxX0
            // 
            this.textBoxX0.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textBoxX0.Location = new System.Drawing.Point(72, 14);
            this.textBoxX0.Name = "textBoxX0";
            this.textBoxX0.Size = new System.Drawing.Size(85, 30);
            this.textBoxX0.TabIndex = 12;
            this.textBoxX0.Text = "-3,5001";
            // 
            // buttonCalculate
            // 
            this.buttonCalculate.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.buttonCalculate.Location = new System.Drawing.Point(484, 15);
            this.buttonCalculate.Name = "buttonCalculate";
            this.buttonCalculate.Size = new System.Drawing.Size(142, 31);
            this.buttonCalculate.TabIndex = 18;
            this.buttonCalculate.Text = "Вычислить";
            this.buttonCalculate.UseVisualStyleBackColor = true;
            this.buttonCalculate.Click += new System.EventHandler(this.buttonCalculate_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.buttonCalculate);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.textBoxDx);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBoxXk);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBoxX0);
            this.Name = "Form1";
            this.Text = "Лаб №2 Григорьев А.А. 351";
            this.Load += new System.EventHandler(this.Form1_Load_1);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox textBoxDx;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxXk;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxX0;
        private System.Windows.Forms.Button buttonCalculate;
    }
}

