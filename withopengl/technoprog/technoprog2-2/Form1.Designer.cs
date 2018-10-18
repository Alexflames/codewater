namespace technoprog2_2
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
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.buttonFill = new System.Windows.Forms.Button();
            this.listBoxData = new System.Windows.Forms.ListBox();
            this.listBoxAns = new System.Windows.Forms.ListBox();
            this.buttonSwitch = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label2.Location = new System.Drawing.Point(225, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(206, 25);
            this.label2.TabIndex = 10;
            this.label2.Text = "Полученный массив:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label1.Location = new System.Drawing.Point(7, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(178, 25);
            this.label1.TabIndex = 9;
            this.label1.Text = "Исходный массив";
            // 
            // buttonFill
            // 
            this.buttonFill.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.buttonFill.Location = new System.Drawing.Point(12, 477);
            this.buttonFill.Name = "buttonFill";
            this.buttonFill.Size = new System.Drawing.Size(153, 60);
            this.buttonFill.TabIndex = 8;
            this.buttonFill.Text = "Заполнить массив";
            this.buttonFill.UseVisualStyleBackColor = true;
            this.buttonFill.Click += new System.EventHandler(this.buttonFill_Click);
            // 
            // listBoxData
            // 
            this.listBoxData.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F);
            this.listBoxData.FormattingEnabled = true;
            this.listBoxData.ItemHeight = 18;
            this.listBoxData.Location = new System.Drawing.Point(12, 45);
            this.listBoxData.Name = "listBoxData";
            this.listBoxData.Size = new System.Drawing.Size(155, 418);
            this.listBoxData.TabIndex = 7;
            // 
            // listBoxAns
            // 
            this.listBoxAns.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F);
            this.listBoxAns.FormattingEnabled = true;
            this.listBoxAns.ItemHeight = 18;
            this.listBoxAns.Location = new System.Drawing.Point(249, 45);
            this.listBoxAns.Name = "listBoxAns";
            this.listBoxAns.Size = new System.Drawing.Size(155, 418);
            this.listBoxAns.TabIndex = 11;
            // 
            // buttonSwitch
            // 
            this.buttonSwitch.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.buttonSwitch.Location = new System.Drawing.Point(249, 477);
            this.buttonSwitch.Name = "buttonSwitch";
            this.buttonSwitch.Size = new System.Drawing.Size(153, 60);
            this.buttonSwitch.TabIndex = 12;
            this.buttonSwitch.Text = "Поменять min и max";
            this.buttonSwitch.UseVisualStyleBackColor = true;
            this.buttonSwitch.Click += new System.EventHandler(this.buttonSwitch_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(445, 549);
            this.Controls.Add(this.buttonSwitch);
            this.Controls.Add(this.listBoxAns);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.buttonFill);
            this.Controls.Add(this.listBoxData);
            this.Name = "Form1";
            this.Text = "Лаб №2-2. Вар №1, 351 Григорьев А.А.";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonFill;
        private System.Windows.Forms.ListBox listBoxData;
        private System.Windows.Forms.ListBox listBoxAns;
        private System.Windows.Forms.Button buttonSwitch;
    }
}

