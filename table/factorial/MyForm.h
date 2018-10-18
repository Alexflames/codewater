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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Numbers;
	private: System::Windows::Forms::Label^  lblTask1;
	private: System::Windows::Forms::Label^  lblTask2;


	private: System::Windows::Forms::Button^  btnAdd;
	private: System::Windows::Forms::Button^  btnRemove;

	private: System::Windows::Forms::Label^  lblArea;




	private: System::Windows::Forms::Button^  btnSum;
	private: System::Windows::Forms::Label^  lblSum;
	private: System::Windows::Forms::TextBox^  txtSum;
	private: System::Windows::Forms::Button^  btnMin;
	private: System::Windows::Forms::Label^  lblMin;


	private: System::Windows::Forms::TextBox^  txtMin;
	private: System::Windows::Forms::TextBox^  txtAreaA;
	private: System::Windows::Forms::TextBox^  txtAreaB;


	private: System::Windows::Forms::Label^  lblAreaCloseBrackets;
	private: System::Windows::Forms::ErrorProvider^  errorProvider;



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
			this->lblTask2 = (gcnew System::Windows::Forms::Label());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnRemove = (gcnew System::Windows::Forms::Button());
			this->lblArea = (gcnew System::Windows::Forms::Label());
			this->btnSum = (gcnew System::Windows::Forms::Button());
			this->lblSum = (gcnew System::Windows::Forms::Label());
			this->txtSum = (gcnew System::Windows::Forms::TextBox());
			this->btnMin = (gcnew System::Windows::Forms::Button());
			this->lblMin = (gcnew System::Windows::Forms::Label());
			this->txtMin = (gcnew System::Windows::Forms::TextBox());
			this->txtAreaA = (gcnew System::Windows::Forms::TextBox());
			this->txtAreaB = (gcnew System::Windows::Forms::TextBox());
			this->lblAreaCloseBrackets = (gcnew System::Windows::Forms::Label());
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdNumbers))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->BeginInit();
			this->SuspendLayout();
			// 
			// grdNumbers
			// 
			this->grdNumbers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grdNumbers->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Numbers });
			this->grdNumbers->Location = System::Drawing::Point(16, 89);
			this->grdNumbers->Name = L"grdNumbers";
			this->grdNumbers->RowTemplate->Height = 28;
			this->grdNumbers->Size = System::Drawing::Size(143, 398);
			this->grdNumbers->TabIndex = 0;
			// 
			// Numbers
			// 
			this->Numbers->HeaderText = L"Массив";
			this->Numbers->Name = L"Numbers";
			// 
			// lblTask1
			// 
			this->lblTask1->AutoSize = true;
			this->lblTask1->Location = System::Drawing::Point(12, 23);
			this->lblTask1->Name = L"lblTask1";
			this->lblTask1->Size = System::Drawing::Size(559, 20);
			this->lblTask1->TabIndex = 1;
			this->lblTask1->Text = L"Найти сумму четных элементов, попадающих в заданный интервал [a,b]";
			// 
			// lblTask2
			// 
			this->lblTask2->AutoSize = true;
			this->lblTask2->Location = System::Drawing::Point(12, 55);
			this->lblTask2->Name = L"lblTask2";
			this->lblTask2->Size = System::Drawing::Size(400, 20);
			this->lblTask2->TabIndex = 2;
			this->lblTask2->Text = L"Вывести минимальный нечетный элемент массива";
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(188, 89);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(105, 38);
			this->btnAdd->TabIndex = 3;
			this->btnAdd->Text = L"Добавить";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &MyForm::btnAdd_Click);
			// 
			// btnRemove
			// 
			this->btnRemove->Location = System::Drawing::Point(188, 152);
			this->btnRemove->Name = L"btnRemove";
			this->btnRemove->Size = System::Drawing::Size(105, 43);
			this->btnRemove->TabIndex = 4;
			this->btnRemove->Text = L"Удалить";
			this->btnRemove->UseVisualStyleBackColor = true;
			this->btnRemove->Click += gcnew System::EventHandler(this, &MyForm::btnRemove_Click);
			// 
			// lblArea
			// 
			this->lblArea->AutoSize = true;
			this->lblArea->Location = System::Drawing::Point(300, 101);
			this->lblArea->Name = L"lblArea";
			this->lblArea->Size = System::Drawing::Size(92, 20);
			this->lblArea->TabIndex = 5;
			this->lblArea->Text = L"Интервал [";
			// 
			// btnSum
			// 
			this->btnSum->Location = System::Drawing::Point(324, 152);
			this->btnSum->Name = L"btnSum";
			this->btnSum->Size = System::Drawing::Size(177, 43);
			this->btnSum->TabIndex = 6;
			this->btnSum->Text = L"Сумма";
			this->btnSum->UseVisualStyleBackColor = true;
			this->btnSum->Click += gcnew System::EventHandler(this, &MyForm::btnSum_Click);
			// 
			// lblSum
			// 
			this->lblSum->AutoSize = true;
			this->lblSum->Location = System::Drawing::Point(313, 228);
			this->lblSum->Name = L"lblSum";
			this->lblSum->Size = System::Drawing::Size(66, 20);
			this->lblSum->TabIndex = 7;
			this->lblSum->Text = L"Сумма :";
			// 
			// txtSum
			// 
			this->txtSum->Location = System::Drawing::Point(408, 228);
			this->txtSum->Name = L"txtSum";
			this->txtSum->ReadOnly = true;
			this->txtSum->Size = System::Drawing::Size(93, 26);
			this->txtSum->TabIndex = 8;
			// 
			// btnMin
			// 
			this->btnMin->Location = System::Drawing::Point(324, 286);
			this->btnMin->Name = L"btnMin";
			this->btnMin->Size = System::Drawing::Size(177, 43);
			this->btnMin->TabIndex = 9;
			this->btnMin->Text = L"Минимум";
			this->btnMin->UseVisualStyleBackColor = true;
			this->btnMin->Click += gcnew System::EventHandler(this, &MyForm::btnMin_Click);
			// 
			// lblMin
			// 
			this->lblMin->AutoSize = true;
			this->lblMin->Location = System::Drawing::Point(313, 364);
			this->lblMin->Name = L"lblMin";
			this->lblMin->Size = System::Drawing::Size(89, 20);
			this->lblMin->TabIndex = 10;
			this->lblMin->Text = L"Результат";
			// 
			// txtMin
			// 
			this->txtMin->Location = System::Drawing::Point(408, 364);
			this->txtMin->Name = L"txtMin";
			this->txtMin->ReadOnly = true;
			this->txtMin->Size = System::Drawing::Size(93, 26);
			this->txtMin->TabIndex = 11;
			// 
			// txtAreaA
			// 
			this->txtAreaA->Location = System::Drawing::Point(398, 101);
			this->txtAreaA->Name = L"txtAreaA";
			this->txtAreaA->Size = System::Drawing::Size(36, 26);
			this->txtAreaA->TabIndex = 12;
			// 
			// txtAreaB
			// 
			this->txtAreaB->Location = System::Drawing::Point(440, 101);
			this->txtAreaB->Name = L"txtAreaB";
			this->txtAreaB->Size = System::Drawing::Size(36, 26);
			this->txtAreaB->TabIndex = 13;
			// 
			// lblAreaCloseBrackets
			// 
			this->lblAreaCloseBrackets->AutoSize = true;
			this->lblAreaCloseBrackets->Location = System::Drawing::Point(488, 101);
			this->lblAreaCloseBrackets->Name = L"lblAreaCloseBrackets";
			this->lblAreaCloseBrackets->Size = System::Drawing::Size(13, 20);
			this->lblAreaCloseBrackets->TabIndex = 14;
			this->lblAreaCloseBrackets->Text = L"]";
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(581, 527);
			this->Controls->Add(this->lblAreaCloseBrackets);
			this->Controls->Add(this->txtAreaB);
			this->Controls->Add(this->txtAreaA);
			this->Controls->Add(this->txtMin);
			this->Controls->Add(this->lblMin);
			this->Controls->Add(this->btnMin);
			this->Controls->Add(this->txtSum);
			this->Controls->Add(this->lblSum);
			this->Controls->Add(this->btnSum);
			this->Controls->Add(this->lblArea);
			this->Controls->Add(this->btnRemove);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->lblTask2);
			this->Controls->Add(this->lblTask1);
			this->Controls->Add(this->grdNumbers);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Обработка табличных данных (Вар.1)";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdNumbers))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	// Добавление строк
	private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->grdNumbers->Rows->Add(1);
	}

	// Удаление строк
	private: System::Void btnRemove_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (!this->grdNumbers->CurrentRow->IsNewRow) {
			int i = this->grdNumbers->CurrentRow->Index;
			this->grdNumbers->Rows->Remove(this->grdNumbers->Rows[i]);
		}
	}

	// Нажатие на кнопку суммирования
	private: System::Void btnSum_Click(System::Object^  sender, System::EventArgs^  e) {
		// Очищаем предыдущие результаты
		errorProvider->Clear();
		this->txtSum->Text = "";

		int InputAreaA, InputAreaB;
		// Получаем и проверяем входные данные
		bool resultA = Int32::TryParse(this->txtAreaA->Text, InputAreaA);
		bool resultB = Int32::TryParse(this->txtAreaB->Text, InputAreaB);

		// Проверка ввода
		bool IsAreaWrong = false; // Если эта переменная true, то появится ошибка и выполнение прервется
		if (!resultA) {
			IsAreaWrong = true;
			errorProvider->SetError(this->lblAreaCloseBrackets,
				"a - не число");
		}
		if (!resultB) {
			if (IsAreaWrong)
				errorProvider->SetError(this->lblAreaCloseBrackets,
					"a - не число, b - не число");
			else {
				errorProvider->SetError(this->lblAreaCloseBrackets,
					"b - не число");
				IsAreaWrong = true;
			}
		}
		if (InputAreaA > InputAreaB && !IsAreaWrong) {
			IsAreaWrong = true;
			errorProvider->SetError(this->lblAreaCloseBrackets,
				"a > b");
		}
		// Если проверка успешна, считываем исходный массив
		if (!IsAreaWrong) {
			for (int i = 0; i < this->grdNumbers->RowCount - 1; i++) {
				if (!((System::String^)this->grdNumbers[0, i]->Value)) {
					IsAreaWrong = true;
					errorProvider->SetError(this->grdNumbers,
						"Пустые строки недопустимы");
				}
			}
		}
		if (!IsAreaWrong) {
			int sum = 0; // Сумма четных элементов
			bool IsAnyEven = false; // Наличие четных элементов
			bool CheckCell;	// Проверка правильности ячеек

			for (int i = 0; i < this->grdNumbers->RowCount - 1; i++) {
				int TempVal;
				CheckCell = Int32::TryParse(this->grdNumbers[0, i]->Value->ToString(), TempVal);
				if (!CheckCell) {
					IsAreaWrong = true;
					errorProvider->SetError(this->grdNumbers,
						"В таблице есть не числа");
					break;
				}
				if (TempVal % 2 == 0 && TempVal >= InputAreaA && TempVal <= InputAreaB) {
					IsAnyEven = true;
					sum += TempVal;
				}
			}

			if (IsAnyEven && !IsAreaWrong)
				this->txtSum->Text = System::Convert::ToString(sum);
			else if (CheckCell)	// Если не нашлись элементы и не было ошибки до этого
				errorProvider->SetError(this->grdNumbers,
					"Таких элементов нет");
		}
	}

	// Нажатие кнопки поиска минимума
	private: System::Void btnMin_Click(System::Object^  sender, System::EventArgs^  e) {
		this->txtMin->Text = "";
		errorProvider->Clear();

		bool IsArrayBad = false;	// Если эта переменная true, то появится ошибка, и выполнение прервется
		for (int i = 0; i < this->grdNumbers->RowCount - 1; i++) {
			if (!((System::String^)this->grdNumbers[0, i]->Value)) {
				errorProvider->SetError(this->grdNumbers,
					"Пустые строки недопустимы");
				IsArrayBad = true;
			}
		}
		if (!IsArrayBad) {
			int MinOdd = 0;	// Минимальное нечетное число
			bool CheckCell;

			for (int i = 0; i < this->grdNumbers->RowCount - 1; i++) {
				int TempVal;
				CheckCell = Int32::TryParse(this->grdNumbers[0, i]->Value->ToString(), TempVal);
				if (!CheckCell) {
					IsArrayBad = true;
					errorProvider->SetError(this->grdNumbers,
						"В таблице есть не числа");
					break;
				}
				if (TempVal % 2 != 0) {
					if (MinOdd == 0)
						MinOdd = TempVal;
					else if (TempVal < MinOdd)
						MinOdd = TempVal;
				}
			}
			if (!IsArrayBad) {
				if (MinOdd != 0)
					this->txtMin->Text = System::Convert::ToString(MinOdd);
				else if (CheckCell) // Если не нашлись элементы и не было ошибки до этого
					errorProvider->SetError(this->grdNumbers,
						"Таких элементов нет");
			}
		}
	}
};
}