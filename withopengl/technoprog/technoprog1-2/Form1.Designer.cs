namespace technoprog1_2
{
    partial class lab1task2
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(lab1task2));
            this.label1 = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.textInputX = new System.Windows.Forms.TextBox();
            this.textInputY = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.textInputZ = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textAnswer = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.buttonCalculate = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label1.Location = new System.Drawing.Point(12, 168);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(116, 25);
            this.label1.TabIndex = 0;
            this.label1.Text = "Введите X:";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.InitialImage = null;
            this.pictureBox1.Location = new System.Drawing.Point(12, 12);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(470, 146);
            this.pictureBox1.TabIndex = 1;
            this.pictureBox1.TabStop = false;
            // 
            // textInputX
            // 
            this.textInputX.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textInputX.Location = new System.Drawing.Point(134, 168);
            this.textInputX.Name = "textInputX";
            this.textInputX.Size = new System.Drawing.Size(158, 30);
            this.textInputX.TabIndex = 2;
            // 
            // textInputY
            // 
            this.textInputY.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textInputY.Location = new System.Drawing.Point(134, 214);
            this.textInputY.Name = "textInputY";
            this.textInputY.Size = new System.Drawing.Size(158, 30);
            this.textInputY.TabIndex = 4;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label2.Location = new System.Drawing.Point(12, 214);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(115, 25);
            this.label2.TabIndex = 3;
            this.label2.Text = "Введите Y:";
            // 
            // textInputZ
            // 
            this.textInputZ.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textInputZ.Location = new System.Drawing.Point(134, 261);
            this.textInputZ.Name = "textInputZ";
            this.textInputZ.Size = new System.Drawing.Size(158, 30);
            this.textInputZ.TabIndex = 6;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label3.Location = new System.Drawing.Point(12, 261);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(114, 25);
            this.label3.TabIndex = 5;
            this.label3.Text = "Введите Z:";
            // 
            // textAnswer
            // 
            this.textAnswer.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textAnswer.Location = new System.Drawing.Point(134, 308);
            this.textAnswer.Name = "textAnswer";
            this.textAnswer.ReadOnly = true;
            this.textAnswer.Size = new System.Drawing.Size(158, 30);
            this.textAnswer.TabIndex = 8;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label4.Location = new System.Drawing.Point(12, 308);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(117, 25);
            this.label4.TabIndex = 7;
            this.label4.Text = "Результат:";
            // 
            // buttonCalculate
            // 
            this.buttonCalculate.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.buttonCalculate.Location = new System.Drawing.Point(333, 225);
            this.buttonCalculate.Name = "buttonCalculate";
            this.buttonCalculate.Size = new System.Drawing.Size(134, 49);
            this.buttonCalculate.TabIndex = 9;
            this.buttonCalculate.Text = "Вычислить";
            this.buttonCalculate.UseVisualStyleBackColor = true;
            this.buttonCalculate.Click += new System.EventHandler(this.buttonCalculate_Click);
            // 
            // lab1task2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.ClientSize = new System.Drawing.Size(492, 355);
            this.Controls.Add(this.buttonCalculate);
            this.Controls.Add(this.textAnswer);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.textInputZ);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textInputY);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textInputX);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.label1);
            this.Name = "lab1task2";
            this.Text = "Лаб. Раб. N1. Ст. гр. 351 Григорьев Алексей Александрович";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.TextBox textInputX;
        private System.Windows.Forms.TextBox textInputY;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textInputZ;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textAnswer;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button buttonCalculate;
    }
}

