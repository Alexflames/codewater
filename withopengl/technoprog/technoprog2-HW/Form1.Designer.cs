namespace technoprog2_HW
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
            this.buttonSelect = new System.Windows.Forms.Button();
            this.buttonInsert = new System.Windows.Forms.Button();
            this.buttonUpdate = new System.Windows.Forms.Button();
            this.buttonDelete = new System.Windows.Forms.Button();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.textBoxWhere = new System.Windows.Forms.TextBox();
            this.textBoxInsertInto = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxInsertValues = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textBoxUpdate1 = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.textBoxUpdateSet = new System.Windows.Forms.TextBox();
            this.textBoxSelect1 = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.textBoxSelect2 = new System.Windows.Forms.TextBox();
            this.textBoxSelect3 = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.textBoxAns = new System.Windows.Forms.TextBox();
            this.textBoxDeleteFrom = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // buttonSelect
            // 
            this.buttonSelect.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.buttonSelect.Location = new System.Drawing.Point(402, 74);
            this.buttonSelect.Name = "buttonSelect";
            this.buttonSelect.Size = new System.Drawing.Size(142, 31);
            this.buttonSelect.TabIndex = 19;
            this.buttonSelect.Text = "SELECT";
            this.buttonSelect.UseVisualStyleBackColor = true;
            this.buttonSelect.Click += new System.EventHandler(this.buttonSelect_Click);
            // 
            // buttonInsert
            // 
            this.buttonInsert.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.buttonInsert.Location = new System.Drawing.Point(402, 206);
            this.buttonInsert.Name = "buttonInsert";
            this.buttonInsert.Size = new System.Drawing.Size(142, 31);
            this.buttonInsert.TabIndex = 21;
            this.buttonInsert.Text = "INSERT";
            this.buttonInsert.UseVisualStyleBackColor = true;
            this.buttonInsert.Click += new System.EventHandler(this.buttonInsert_Click);
            // 
            // buttonUpdate
            // 
            this.buttonUpdate.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.buttonUpdate.Location = new System.Drawing.Point(402, 293);
            this.buttonUpdate.Name = "buttonUpdate";
            this.buttonUpdate.Size = new System.Drawing.Size(142, 31);
            this.buttonUpdate.TabIndex = 22;
            this.buttonUpdate.Text = "UPDATE";
            this.buttonUpdate.UseVisualStyleBackColor = true;
            this.buttonUpdate.Click += new System.EventHandler(this.buttonUpdate_Click);
            // 
            // buttonDelete
            // 
            this.buttonDelete.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.buttonDelete.Location = new System.Drawing.Point(402, 330);
            this.buttonDelete.Name = "buttonDelete";
            this.buttonDelete.Size = new System.Drawing.Size(142, 31);
            this.buttonDelete.TabIndex = 23;
            this.buttonDelete.Text = "DELETE";
            this.buttonDelete.UseVisualStyleBackColor = true;
            this.buttonDelete.Click += new System.EventHandler(this.buttonDelete_Click);
            // 
            // listBox1
            // 
            this.listBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 25;
            this.listBox1.Location = new System.Drawing.Point(32, 74);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(346, 329);
            this.listBox1.TabIndex = 25;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label1.Location = new System.Drawing.Point(583, 378);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(77, 25);
            this.label1.TabIndex = 26;
            this.label1.Text = "Where:";
            // 
            // textBoxWhere
            // 
            this.textBoxWhere.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textBoxWhere.Location = new System.Drawing.Point(666, 375);
            this.textBoxWhere.Name = "textBoxWhere";
            this.textBoxWhere.Size = new System.Drawing.Size(130, 30);
            this.textBoxWhere.TabIndex = 27;
            // 
            // textBoxInsertInto
            // 
            this.textBoxInsertInto.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textBoxInsertInto.Location = new System.Drawing.Point(648, 209);
            this.textBoxInsertInto.Name = "textBoxInsertInto";
            this.textBoxInsertInto.Size = new System.Drawing.Size(307, 30);
            this.textBoxInsertInto.TabIndex = 29;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label2.Location = new System.Drawing.Point(550, 209);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(60, 25);
            this.label2.TabIndex = 28;
            this.label2.Text = "INTO";
            // 
            // textBoxInsertValues
            // 
            this.textBoxInsertValues.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textBoxInsertValues.Location = new System.Drawing.Point(648, 250);
            this.textBoxInsertValues.Name = "textBoxInsertValues";
            this.textBoxInsertValues.Size = new System.Drawing.Size(307, 30);
            this.textBoxInsertValues.TabIndex = 31;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label3.Location = new System.Drawing.Point(550, 253);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(92, 25);
            this.label3.TabIndex = 30;
            this.label3.Text = "VALUES";
            // 
            // textBoxUpdate1
            // 
            this.textBoxUpdate1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textBoxUpdate1.Location = new System.Drawing.Point(550, 294);
            this.textBoxUpdate1.Name = "textBoxUpdate1";
            this.textBoxUpdate1.Size = new System.Drawing.Size(130, 30);
            this.textBoxUpdate1.TabIndex = 32;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label4.Location = new System.Drawing.Point(686, 293);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(52, 25);
            this.label4.TabIndex = 33;
            this.label4.Text = "SET";
            // 
            // textBoxUpdateSet
            // 
            this.textBoxUpdateSet.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textBoxUpdateSet.Location = new System.Drawing.Point(744, 294);
            this.textBoxUpdateSet.Name = "textBoxUpdateSet";
            this.textBoxUpdateSet.Size = new System.Drawing.Size(211, 30);
            this.textBoxUpdateSet.TabIndex = 34;
            // 
            // textBoxSelect1
            // 
            this.textBoxSelect1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textBoxSelect1.Location = new System.Drawing.Point(648, 75);
            this.textBoxSelect1.Name = "textBoxSelect1";
            this.textBoxSelect1.Size = new System.Drawing.Size(307, 30);
            this.textBoxSelect1.TabIndex = 36;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label5.Location = new System.Drawing.Point(551, 115);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(70, 25);
            this.label5.TabIndex = 35;
            this.label5.Text = "FROM";
            // 
            // textBoxSelect2
            // 
            this.textBoxSelect2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textBoxSelect2.Location = new System.Drawing.Point(648, 110);
            this.textBoxSelect2.Name = "textBoxSelect2";
            this.textBoxSelect2.Size = new System.Drawing.Size(307, 30);
            this.textBoxSelect2.TabIndex = 37;
            // 
            // textBoxSelect3
            // 
            this.textBoxSelect3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textBoxSelect3.Location = new System.Drawing.Point(648, 146);
            this.textBoxSelect3.Name = "textBoxSelect3";
            this.textBoxSelect3.Size = new System.Drawing.Size(307, 30);
            this.textBoxSelect3.TabIndex = 39;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label6.Location = new System.Drawing.Point(509, 149);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(112, 25);
            this.label6.TabIndex = 38;
            this.label6.Text = "ORDER BY";
            // 
            // textBoxAns
            // 
            this.textBoxAns.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textBoxAns.Location = new System.Drawing.Point(32, 27);
            this.textBoxAns.Name = "textBoxAns";
            this.textBoxAns.Size = new System.Drawing.Size(346, 30);
            this.textBoxAns.TabIndex = 40;
            // 
            // textBoxDeleteFrom
            // 
            this.textBoxDeleteFrom.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textBoxDeleteFrom.Location = new System.Drawing.Point(648, 330);
            this.textBoxDeleteFrom.Name = "textBoxDeleteFrom";
            this.textBoxDeleteFrom.Size = new System.Drawing.Size(307, 30);
            this.textBoxDeleteFrom.TabIndex = 42;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label7.Location = new System.Drawing.Point(551, 335);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(70, 25);
            this.label7.TabIndex = 41;
            this.label7.Text = "FROM";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(192)))), ((int)(((byte)(255)))));
            this.ClientSize = new System.Drawing.Size(1010, 450);
            this.Controls.Add(this.textBoxDeleteFrom);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.textBoxAns);
            this.Controls.Add(this.textBoxSelect3);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.textBoxSelect2);
            this.Controls.Add(this.textBoxSelect1);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.textBoxUpdateSet);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.textBoxUpdate1);
            this.Controls.Add(this.textBoxInsertValues);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textBoxInsertInto);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBoxWhere);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.buttonDelete);
            this.Controls.Add(this.buttonUpdate);
            this.Controls.Add(this.buttonInsert);
            this.Controls.Add(this.buttonSelect);
            this.Name = "Form1";
            this.Text = "Лаб №2 Григорьев А.А. 351 - Построение универсальных запросов";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonSelect;
        private System.Windows.Forms.Button buttonInsert;
        private System.Windows.Forms.Button buttonUpdate;
        private System.Windows.Forms.Button buttonDelete;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxWhere;
        private System.Windows.Forms.TextBox textBoxInsertInto;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxInsertValues;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBoxUpdate1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textBoxUpdateSet;
        private System.Windows.Forms.TextBox textBoxSelect1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textBoxSelect2;
        private System.Windows.Forms.TextBox textBoxSelect3;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox textBoxAns;
        private System.Windows.Forms.TextBox textBoxDeleteFrom;
        private System.Windows.Forms.Label label7;
    }
}

