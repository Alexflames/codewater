#pragma once
#include "table.h"

namespace table {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  grdNumbers;
	protected:

	protected:

	private: System::Windows::Forms::Label^  lblTask1;
	private: System::Windows::Forms::Label^  lblColumnX;
	private: System::Windows::Forms::Button^  btnAddRow;
	private: System::Windows::Forms::Button^  btnRemoveRow;
	private: System::Windows::Forms::ErrorProvider^  errorProvider;
	private: System::Windows::Forms::Button^  btnChange;
	private: System::Windows::Forms::Button^  btnRemoveColumn;
	private: System::Windows::Forms::Button^  btnAddColumn;
	private: System::Windows::Forms::DataGridView^  grdOutput;

	private: System::Windows::Forms::Label^  lblArrow2;
	private: System::Windows::Forms::Label^  lblArrow1;
	private: System::Windows::Forms::DataGridView^  grdX;


	private: System::Windows::Forms::Label^  lblRes;
	private: System::Windows::Forms::Label^  lblInput;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Numbers;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;






	protected:
	protected:

	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->grdNumbers = (gcnew System::Windows::Forms::DataGridView());
			this->Numbers = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lblTask1 = (gcnew System::Windows::Forms::Label());
			this->lblColumnX = (gcnew System::Windows::Forms::Label());
			this->btnAddRow = (gcnew System::Windows::Forms::Button());
			this->btnRemoveRow = (gcnew System::Windows::Forms::Button());
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->grdOutput = (gcnew System::Windows::Forms::DataGridView());
			this->btnAddColumn = (gcnew System::Windows::Forms::Button());
			this->btnRemoveColumn = (gcnew System::Windows::Forms::Button());
			this->btnChange = (gcnew System::Windows::Forms::Button());
			this->grdX = (gcnew System::Windows::Forms::DataGridView());
			this->lblArrow1 = (gcnew System::Windows::Forms::Label());
			this->lblArrow2 = (gcnew System::Windows::Forms::Label());
			this->lblInput = (gcnew System::Windows::Forms::Label());
			this->lblRes = (gcnew System::Windows::Forms::Label());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdNumbers))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdOutput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdX))->BeginInit();
			this->SuspendLayout();
			// 
			// grdNumbers
			// 
			this->grdNumbers->AllowUserToAddRows = false;
			this->grdNumbers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grdNumbers->ColumnHeadersVisible = false;
			this->grdNumbers->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Numbers });
			this->grdNumbers->Location = System::Drawing::Point(11, 116);
			this->grdNumbers->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grdNumbers->Name = L"grdNumbers";
			this->grdNumbers->RowHeadersVisible = false;
			this->grdNumbers->RowTemplate->Height = 28;
			this->grdNumbers->Size = System::Drawing::Size(324, 318);
			this->grdNumbers->TabIndex = 0;
			// 
			// Numbers
			// 
			this->Numbers->FillWeight = 70;
			this->Numbers->HeaderText = L"Массив";
			this->Numbers->Name = L"Numbers";
			this->Numbers->Width = 50;
			// 
			// lblTask1
			// 
			this->lblTask1->AutoSize = true;
			this->lblTask1->Location = System::Drawing::Point(11, 20);
			this->lblTask1->Name = L"lblTask1";
			this->lblTask1->Size = System::Drawing::Size(474, 17);
			this->lblTask1->TabIndex = 1;
			this->lblTask1->Text = L"Заменить столбцы, содержащие только чётные элементы столбцом X";
			// 
			// lblColumnX
			// 
			this->lblColumnX->AutoSize = true;
			this->lblColumnX->Location = System::Drawing::Point(410, 90);
			this->lblColumnX->Name = L"lblColumnX";
			this->lblColumnX->Size = System::Drawing::Size(77, 17);
			this->lblColumnX->TabIndex = 2;
			this->lblColumnX->Text = L"Столбец X";
			// 
			// btnAddRow
			// 
			this->btnAddRow->Location = System::Drawing::Point(573, 7);
			this->btnAddRow->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnAddRow->Name = L"btnAddRow";
			this->btnAddRow->Size = System::Drawing::Size(93, 42);
			this->btnAddRow->TabIndex = 3;
			this->btnAddRow->Text = L"Добавить строки";
			this->btnAddRow->UseVisualStyleBackColor = true;
			this->btnAddRow->Click += gcnew System::EventHandler(this, &MyForm::btnAdd_Click);
			// 
			// btnRemoveRow
			// 
			this->btnRemoveRow->Location = System::Drawing::Point(573, 54);
			this->btnRemoveRow->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnRemoveRow->Name = L"btnRemoveRow";
			this->btnRemoveRow->Size = System::Drawing::Size(93, 44);
			this->btnRemoveRow->TabIndex = 4;
			this->btnRemoveRow->Text = L"Удалить строки";
			this->btnRemoveRow->UseVisualStyleBackColor = true;
			this->btnRemoveRow->Click += gcnew System::EventHandler(this, &MyForm::btnRemove_Click);
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// grdOutput
			// 
			this->grdOutput->AllowUserToAddRows = false;
			this->grdOutput->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grdOutput->ColumnHeadersVisible = false;
			this->grdOutput->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->dataGridViewTextBoxColumn1 });
			this->grdOutput->Location = System::Drawing::Point(573, 116);
			this->grdOutput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grdOutput->Name = L"grdOutput";
			this->grdOutput->ReadOnly = true;
			this->grdOutput->RowHeadersVisible = false;
			this->grdOutput->RowTemplate->Height = 28;
			this->grdOutput->Size = System::Drawing::Size(324, 318);
			this->grdOutput->TabIndex = 5;
			// 
			// btnAddColumn
			// 
			this->btnAddColumn->Location = System::Drawing::Point(804, 7);
			this->btnAddColumn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnAddColumn->Name = L"btnAddColumn";
			this->btnAddColumn->Size = System::Drawing::Size(93, 42);
			this->btnAddColumn->TabIndex = 6;
			this->btnAddColumn->Text = L"Добавить столбец";
			this->btnAddColumn->UseVisualStyleBackColor = true;
			this->btnAddColumn->Click += gcnew System::EventHandler(this, &MyForm::btnAddColumn_Click);
			// 
			// btnRemoveColumn
			// 
			this->btnRemoveColumn->Location = System::Drawing::Point(804, 54);
			this->btnRemoveColumn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnRemoveColumn->Name = L"btnRemoveColumn";
			this->btnRemoveColumn->Size = System::Drawing::Size(93, 44);
			this->btnRemoveColumn->TabIndex = 7;
			this->btnRemoveColumn->Text = L"Удалить столбец";
			this->btnRemoveColumn->UseVisualStyleBackColor = true;
			this->btnRemoveColumn->Click += gcnew System::EventHandler(this, &MyForm::btnRemoveColumn_Click);
			// 
			// btnChange
			// 
			this->btnChange->Location = System::Drawing::Point(684, 28);
			this->btnChange->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnChange->Name = L"btnChange";
			this->btnChange->Size = System::Drawing::Size(101, 51);
			this->btnChange->TabIndex = 8;
			this->btnChange->Text = L"Изменить столбцы";
			this->btnChange->UseVisualStyleBackColor = true;
			this->btnChange->Click += gcnew System::EventHandler(this, &MyForm::btnChange_Click);
			// 
			// grdX
			// 
			this->grdX->AllowUserToAddRows = false;
			this->grdX->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grdX->ColumnHeadersVisible = false;
			this->grdX->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->dataGridViewTextBoxColumn2 });
			this->grdX->Location = System::Drawing::Point(396, 116);
			this->grdX->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grdX->Name = L"grdX";
			this->grdX->RowHeadersVisible = false;
			this->grdX->RowTemplate->Height = 28;
			this->grdX->Size = System::Drawing::Size(119, 318);
			this->grdX->TabIndex = 9;
			// 
			// lblArrow1
			// 
			this->lblArrow1->AutoSize = true;
			this->lblArrow1->Location = System::Drawing::Point(343, 244);
			this->lblArrow1->Name = L"lblArrow1";
			this->lblArrow1->Size = System::Drawing::Size(51, 17);
			this->lblArrow1->TabIndex = 10;
			this->lblArrow1->Text = L"------->";
			// 
			// lblArrow2
			// 
			this->lblArrow2->AutoSize = true;
			this->lblArrow2->Location = System::Drawing::Point(521, 244);
			this->lblArrow2->Name = L"lblArrow2";
			this->lblArrow2->Size = System::Drawing::Size(51, 17);
			this->lblArrow2->TabIndex = 11;
			this->lblArrow2->Text = L"------->";
			// 
			// lblInput
			// 
			this->lblInput->AutoSize = true;
			this->lblInput->Location = System::Drawing::Point(57, 90);
			this->lblInput->Name = L"lblInput";
			this->lblInput->Size = System::Drawing::Size(107, 17);
			this->lblInput->TabIndex = 12;
			this->lblInput->Text = L"Таблица ввода";
			// 
			// lblRes
			// 
			this->lblRes->AutoSize = true;
			this->lblRes->Location = System::Drawing::Point(681, 90);
			this->lblRes->Name = L"lblRes";
			this->lblRes->Size = System::Drawing::Size(76, 17);
			this->lblRes->TabIndex = 13;
			this->lblRes->Text = L"Результат";
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Массив";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Width = 50;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Массив";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->Width = 115;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(908, 444);
			this->Controls->Add(this->lblRes);
			this->Controls->Add(this->lblInput);
			this->Controls->Add(this->lblArrow2);
			this->Controls->Add(this->lblArrow1);
			this->Controls->Add(this->grdX);
			this->Controls->Add(this->btnChange);
			this->Controls->Add(this->btnRemoveColumn);
			this->Controls->Add(this->btnAddColumn);
			this->Controls->Add(this->grdOutput);
			this->Controls->Add(this->btnRemoveRow);
			this->Controls->Add(this->btnAddRow);
			this->Controls->Add(this->lblColumnX);
			this->Controls->Add(this->lblTask1);
			this->Controls->Add(this->grdNumbers);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Обработка табличных данных, часть 2 (Вар.18)";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdNumbers))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdOutput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdX))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	// Добавление строк
	private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->grdNumbers->Rows->Add(1);
		this->grdX->Rows->Add(1);
		this->grdOutput->Rows->Add(1);
	}

	// Удаление строк
	private: System::Void btnRemove_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (this->grdNumbers->RowCount > 0) {
			this->grdNumbers->Rows->Remove(this->grdNumbers->Rows[this->grdNumbers->RowCount - 1]);
			this->grdOutput->Rows->Remove(this->grdOutput->Rows[this->grdOutput->RowCount - 1]);
			this->grdX->Rows->Remove(this->grdX->Rows[this->grdX->RowCount - 1]);
		}
		
	}
	
	// Добавление столбцов
	private: System::Void btnAddColumn_Click(System::Object^  sender, System::EventArgs^  e) {
		this->grdNumbers->Columns->Add("inputColumn" + this->grdNumbers->ColumnCount.ToString(), "");
		this->grdOutput->Columns->Add("outputColumn" + this->grdOutput->ColumnCount.ToString(), "");
		this->grdNumbers->Columns[this->grdNumbers->ColumnCount - 1]->Width = 50;
		this->grdOutput->Columns[this->grdOutput->ColumnCount - 1]->Width = 50;

	}

	// Удаление столбцов
	private: System::Void btnRemoveColumn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->grdNumbers->ColumnCount > 1) {
			this->grdNumbers->Columns->Remove(this->grdNumbers->Columns[this->grdNumbers->ColumnCount - 1]);
			this->grdOutput->Columns->Remove(this->grdOutput->Columns[this->grdOutput->ColumnCount - 1]);
		}
	}

	private: System::Void btnChange_Click(System::Object^  sender, System::EventArgs^  e) {
		// Очищаем предыдущие результаты
		errorProvider->Clear();
		
		//--------------------Проверка столбца X------------------//
		bool IsXWrong = false;
		for (int i = 0; i < this->grdX->RowCount; i++) {
			if (!((System::String^)this->grdX[0, i]->Value)) {
				IsXWrong = true;
				errorProvider->SetError(this->lblColumnX,
					"Пустые строки таблицы X недопустимы");
				break;
			}
		}
		bool CheckCell;
		if (!IsXWrong) {
			for (int i = 0; i < this->grdX->RowCount; i++) {
				int TempVal;
				CheckCell = Int32::TryParse(this->grdX[0, i]->Value->ToString(), TempVal);
				if (!CheckCell) {
					IsXWrong = true;
					errorProvider->SetError(this->lblColumnX,
						"В столбце X есть не числа");
					break;
				}
				if (TempVal > 100000) {
					IsXWrong = true;
					errorProvider->SetError(this->lblColumnX,
						"Ввод слишком больших чисел в таблице ввода недопустим");
					break;
				}
			}
		}

		//-------- Проверка матрицы ввода------------//
		bool IsAreaWrong = false; // Если эта переменная true, то появится ошибка и выполнение прервется
								  
		for (int i = 0; i < this->grdNumbers->RowCount; i++) {
			for (int j = 0; j < this->grdNumbers->ColumnCount; j++) {
				if (!((System::String^)this->grdNumbers[j, i]->Value)) {
					IsAreaWrong = true;
					errorProvider->SetError(this->lblInput,
						"Пустые ячейки исходной таблицы недопустимы");
					break;
				}
			}
		}
		if (!IsAreaWrong) {
			bool CheckCell;	// Проверка правильности ячеек

			for (int i = 0; i < this->grdNumbers->ColumnCount; i++) {
				int evenColumnCount = 0;
				for (int j = 0; j < this->grdNumbers->RowCount; j++) {
					int TempVal;
					CheckCell = Int32::TryParse(this->grdNumbers[i, j]->Value->ToString(), TempVal);
					if (!CheckCell) {
						IsAreaWrong = true;
						errorProvider->SetError(this->lblInput,
							"В таблице ввода есть не числа");
						break;
					}
					if (TempVal > 100000) {
						IsAreaWrong = true;
						errorProvider->SetError(this->lblInput,
							"Ввод слишком больших чисел в таблице ввода недопустим");
						break;
					}

					if (TempVal % 2 == 0)
						evenColumnCount++;
				}
				// При выполнении условия замена столбца
				if (evenColumnCount == this->grdNumbers->RowCount && !IsXWrong) {
					for (int j = 0; j < this->grdOutput->RowCount; j++) {
						this->grdOutput[i, j]->Value = this->grdX[0, j]->Value;
					}
				}
				else if(!IsXWrong) // Если не найдена ошибка в столбце X
					for (int j = 0; j < this->grdOutput->RowCount; j++) {
						this->grdOutput[i, j]->Value = this->grdNumbers[i, j]->Value;
					}
			}
		}
		// Очищение вывода при нахождении ошибки
		if (IsXWrong || IsAreaWrong) {
			for (int i = 0; i < this->grdOutput->RowCount; i++) {
				for (int j = 0; j < this->grdOutput->ColumnCount; j++) {
					this->grdOutput[j, i]->Value = "";
				}
			}
		}
	}
};
}