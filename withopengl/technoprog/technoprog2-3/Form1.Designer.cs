namespace technoprog2_3
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
            this.dataGrid = new System.Windows.Forms.DataGridView();
            this.col1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.col2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.col3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.col4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.minimums = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.buttonFill = new System.Windows.Forms.Button();
            this.buttonDBGetAll = new System.Windows.Forms.Button();
            this.buttonMin = new System.Windows.Forms.Button();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.buttonDBQuery = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGrid)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGrid
            // 
            this.dataGrid.AllowUserToAddRows = false;
            this.dataGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGrid.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.col1,
            this.col2,
            this.col3,
            this.col4,
            this.minimums});
            this.dataGrid.Location = new System.Drawing.Point(29, 24);
            this.dataGrid.Name = "dataGrid";
            this.dataGrid.RowTemplate.Height = 24;
            this.dataGrid.Size = new System.Drawing.Size(542, 182);
            this.dataGrid.TabIndex = 0;
            // 
            // col1
            // 
            this.col1.HeaderText = "";
            this.col1.Name = "col1";
            // 
            // col2
            // 
            this.col2.HeaderText = "";
            this.col2.Name = "col2";
            // 
            // col3
            // 
            this.col3.HeaderText = "";
            this.col3.Name = "col3";
            // 
            // col4
            // 
            this.col4.HeaderText = "";
            this.col4.Name = "col4";
            // 
            // minimums
            // 
            this.minimums.HeaderText = "Минимум";
            this.minimums.Name = "minimums";
            this.minimums.ReadOnly = true;
            // 
            // buttonFill
            // 
            this.buttonFill.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.buttonFill.Location = new System.Drawing.Point(114, 222);
            this.buttonFill.Name = "buttonFill";
            this.buttonFill.Size = new System.Drawing.Size(153, 60);
            this.buttonFill.TabIndex = 9;
            this.buttonFill.Text = "Заполнить программно";
            this.buttonFill.UseVisualStyleBackColor = true;
            this.buttonFill.Click += new System.EventHandler(this.buttonFill_Click);
            // 
            // buttonDBGetAll
            // 
            this.buttonDBGetAll.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.buttonDBGetAll.Location = new System.Drawing.Point(29, 344);
            this.buttonDBGetAll.Name = "buttonDBGetAll";
            this.buttonDBGetAll.Size = new System.Drawing.Size(167, 60);
            this.buttonDBGetAll.TabIndex = 10;
            this.buttonDBGetAll.Text = "Выбрать БД";
            this.buttonDBGetAll.UseVisualStyleBackColor = true;
            this.buttonDBGetAll.Click += new System.EventHandler(this.buttonDBGetAll_Click);
            // 
            // buttonMin
            // 
            this.buttonMin.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.buttonMin.Location = new System.Drawing.Point(301, 222);
            this.buttonMin.Name = "buttonMin";
            this.buttonMin.Size = new System.Drawing.Size(153, 60);
            this.buttonMin.TabIndex = 11;
            this.buttonMin.Text = "Найти минимум";
            this.buttonMin.UseVisualStyleBackColor = true;
            this.buttonMin.Click += new System.EventHandler(this.buttonMin_Click);
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(29, 299);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(542, 24);
            this.comboBox1.TabIndex = 12;
            // 
            // buttonDBQuery
            // 
            this.buttonDBQuery.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.buttonDBQuery.Location = new System.Drawing.Point(404, 344);
            this.buttonDBQuery.Name = "buttonDBQuery";
            this.buttonDBQuery.Size = new System.Drawing.Size(167, 60);
            this.buttonDBQuery.TabIndex = 13;
            this.buttonDBQuery.Text = "Запрос по выбранной";
            this.buttonDBQuery.UseVisualStyleBackColor = true;
            this.buttonDBQuery.Click += new System.EventHandler(this.buttonDBQuery_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(608, 450);
            this.Controls.Add(this.buttonDBQuery);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.buttonMin);
            this.Controls.Add(this.buttonDBGetAll);
            this.Controls.Add(this.buttonFill);
            this.Controls.Add(this.dataGrid);
            this.Name = "Form1";
            this.Text = "Лаб №2 Григорьев А.А. 351 КНиИТ";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGrid)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGrid;
        private System.Windows.Forms.DataGridViewTextBoxColumn col1;
        private System.Windows.Forms.DataGridViewTextBoxColumn col2;
        private System.Windows.Forms.DataGridViewTextBoxColumn col3;
        private System.Windows.Forms.DataGridViewTextBoxColumn col4;
        private System.Windows.Forms.DataGridViewTextBoxColumn minimums;
        private System.Windows.Forms.Button buttonFill;
        private System.Windows.Forms.Button buttonDBGetAll;
        private System.Windows.Forms.Button buttonMin;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Button buttonDBQuery;
    }
}

