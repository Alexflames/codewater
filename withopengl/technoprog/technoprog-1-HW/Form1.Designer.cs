namespace technoprog_1_HW
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
            this.components = new System.ComponentModel.Container();
            this.pictureBox1 = new Emgu.CV.UI.ImageBox();
            this.button1 = new System.Windows.Forms.Button();
            this.imageBoxTransform = new Emgu.CV.UI.ImageBox();
            this.buttonKanny = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxCT = new System.Windows.Forms.TextBox();
            this.textBoxCTL = new System.Windows.Forms.TextBox();
            this.buttonClrFilter = new System.Windows.Forms.Button();
            this.buttonLines = new System.Windows.Forms.Button();
            this.textBoxLimit = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.imageBoxTransform)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.FunctionalMode = Emgu.CV.UI.ImageBox.FunctionalModeOption.Minimum;
            this.pictureBox1.Location = new System.Drawing.Point(32, 120);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(465, 446);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.button1.Location = new System.Drawing.Point(12, 12);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(150, 38);
            this.button1.TabIndex = 1;
            this.button1.Text = "Изображение";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // imageBoxTransform
            // 
            this.imageBoxTransform.FunctionalMode = Emgu.CV.UI.ImageBox.FunctionalModeOption.Minimum;
            this.imageBoxTransform.Location = new System.Drawing.Point(626, 120);
            this.imageBoxTransform.Name = "imageBoxTransform";
            this.imageBoxTransform.Size = new System.Drawing.Size(465, 446);
            this.imageBoxTransform.TabIndex = 2;
            this.imageBoxTransform.TabStop = false;
            // 
            // buttonKanny
            // 
            this.buttonKanny.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.buttonKanny.Location = new System.Drawing.Point(331, 12);
            this.buttonKanny.Name = "buttonKanny";
            this.buttonKanny.Size = new System.Drawing.Size(133, 38);
            this.buttonKanny.TabIndex = 3;
            this.buttonKanny.Text = "Kanny";
            this.buttonKanny.UseVisualStyleBackColor = true;
            this.buttonKanny.Click += new System.EventHandler(this.buttonKanny_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label1.Location = new System.Drawing.Point(155, 63);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(153, 25);
            this.label1.TabIndex = 4;
            this.label1.Text = "cannyThreshold";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label2.Location = new System.Drawing.Point(420, 63);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(67, 25);
            this.label2.TabIndex = 5;
            this.label2.Text = "linking";
            // 
            // textBoxCT
            // 
            this.textBoxCT.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textBoxCT.Location = new System.Drawing.Point(314, 61);
            this.textBoxCT.Name = "textBoxCT";
            this.textBoxCT.Size = new System.Drawing.Size(100, 30);
            this.textBoxCT.TabIndex = 6;
            // 
            // textBoxCTL
            // 
            this.textBoxCTL.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textBoxCTL.Location = new System.Drawing.Point(493, 59);
            this.textBoxCTL.Name = "textBoxCTL";
            this.textBoxCTL.Size = new System.Drawing.Size(100, 30);
            this.textBoxCTL.TabIndex = 7;
            // 
            // buttonClrFilter
            // 
            this.buttonClrFilter.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.buttonClrFilter.Location = new System.Drawing.Point(950, 12);
            this.buttonClrFilter.Name = "buttonClrFilter";
            this.buttonClrFilter.Size = new System.Drawing.Size(154, 38);
            this.buttonClrFilter.TabIndex = 8;
            this.buttonClrFilter.Text = "Цвет-фильтр";
            this.buttonClrFilter.UseVisualStyleBackColor = true;
            this.buttonClrFilter.Click += new System.EventHandler(this.buttonClrFilter_Click);
            // 
            // buttonLines
            // 
            this.buttonLines.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.buttonLines.Location = new System.Drawing.Point(708, 12);
            this.buttonLines.Name = "buttonLines";
            this.buttonLines.Size = new System.Drawing.Size(154, 38);
            this.buttonLines.TabIndex = 9;
            this.buttonLines.Text = "Из линий";
            this.buttonLines.UseVisualStyleBackColor = true;
            this.buttonLines.Click += new System.EventHandler(this.buttonLines_Click);
            // 
            // textBoxLimit
            // 
            this.textBoxLimit.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textBoxLimit.Location = new System.Drawing.Point(839, 63);
            this.textBoxLimit.Name = "textBoxLimit";
            this.textBoxLimit.Size = new System.Drawing.Size(100, 30);
            this.textBoxLimit.TabIndex = 11;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label3.Location = new System.Drawing.Point(631, 64);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(202, 25);
            this.label3.TabIndex = 10;
            this.label3.Text = "Пороговое значение";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1116, 578);
            this.Controls.Add(this.textBoxLimit);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.buttonLines);
            this.Controls.Add(this.buttonClrFilter);
            this.Controls.Add(this.textBoxCTL);
            this.Controls.Add(this.textBoxCT);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.buttonKanny);
            this.Controls.Add(this.imageBoxTransform);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.pictureBox1);
            this.Name = "Form1";
            this.Text = "Лаб. Раб. N1. Ст. гр. 351 Григорьев Алексей Александрович";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.imageBoxTransform)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Emgu.CV.UI.ImageBox pictureBox1;
        private System.Windows.Forms.Button button1;
        private Emgu.CV.UI.ImageBox imageBoxTransform;
        private System.Windows.Forms.Button buttonKanny;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxCT;
        private System.Windows.Forms.TextBox textBoxCTL;
        private System.Windows.Forms.Button buttonClrFilter;
        private System.Windows.Forms.Button buttonLines;
        private System.Windows.Forms.TextBox textBoxLimit;
        private System.Windows.Forms.Label label3;
    }
}

