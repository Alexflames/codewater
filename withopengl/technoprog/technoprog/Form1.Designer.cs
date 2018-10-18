namespace technoprog
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
            this.buttonWOW = new System.Windows.Forms.Button();
            this.buttonRed = new System.Windows.Forms.Button();
            this.buttonGreen = new System.Windows.Forms.Button();
            this.buttonBlue = new System.Windows.Forms.Button();
            this.buttonYellow = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonWOW
            // 
            this.buttonWOW.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.buttonWOW.Location = new System.Drawing.Point(473, 403);
            this.buttonWOW.Name = "buttonWOW";
            this.buttonWOW.Size = new System.Drawing.Size(315, 35);
            this.buttonWOW.TabIndex = 8;
            this.buttonWOW.Text = "Серо-бур-малиновый в крапинку";
            this.buttonWOW.UseVisualStyleBackColor = true;
            this.buttonWOW.Click += new System.EventHandler(this.buttonWOW_Click);
            // 
            // buttonRed
            // 
            this.buttonRed.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.buttonRed.Location = new System.Drawing.Point(104, 69);
            this.buttonRed.Name = "buttonRed";
            this.buttonRed.Size = new System.Drawing.Size(133, 52);
            this.buttonRed.TabIndex = 9;
            this.buttonRed.Text = "Красный";
            this.buttonRed.UseVisualStyleBackColor = true;
            this.buttonRed.Click += new System.EventHandler(this.buttonRed_Click);
            // 
            // buttonGreen
            // 
            this.buttonGreen.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.buttonGreen.Location = new System.Drawing.Point(544, 69);
            this.buttonGreen.Name = "buttonGreen";
            this.buttonGreen.Size = new System.Drawing.Size(133, 52);
            this.buttonGreen.TabIndex = 10;
            this.buttonGreen.Text = "Зеленый";
            this.buttonGreen.UseVisualStyleBackColor = true;
            this.buttonGreen.Click += new System.EventHandler(this.buttonGreen_Click);
            // 
            // buttonBlue
            // 
            this.buttonBlue.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.buttonBlue.Location = new System.Drawing.Point(104, 279);
            this.buttonBlue.Name = "buttonBlue";
            this.buttonBlue.Size = new System.Drawing.Size(133, 52);
            this.buttonBlue.TabIndex = 11;
            this.buttonBlue.Text = "Синий";
            this.buttonBlue.UseVisualStyleBackColor = true;
            this.buttonBlue.Click += new System.EventHandler(this.buttonBlue_Click);
            // 
            // buttonYellow
            // 
            this.buttonYellow.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.buttonYellow.Location = new System.Drawing.Point(544, 279);
            this.buttonYellow.Name = "buttonYellow";
            this.buttonYellow.Size = new System.Drawing.Size(133, 52);
            this.buttonYellow.TabIndex = 12;
            this.buttonYellow.Text = "Желтый";
            this.buttonYellow.UseVisualStyleBackColor = true;
            this.buttonYellow.Click += new System.EventHandler(this.buttonYellow_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.buttonYellow);
            this.Controls.Add(this.buttonBlue);
            this.Controls.Add(this.buttonGreen);
            this.Controls.Add(this.buttonRed);
            this.Controls.Add(this.buttonWOW);
            this.Name = "Form1";
            this.Text = "Лаб. Раб. N1. Ст. гр. 351 Григорьев Алексей Александрович";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Button buttonWOW;
        private System.Windows.Forms.Button buttonRed;
        private System.Windows.Forms.Button buttonGreen;
        private System.Windows.Forms.Button buttonBlue;
        private System.Windows.Forms.Button buttonYellow;
    }
}

