#pragma once
#include "calculations.h"

namespace calculations {

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
	private: System::Windows::Forms::Label^  labelX;
	protected:
	private: System::Windows::Forms::Label^  labelY;
	private: System::Windows::Forms::Label^  labelAns;
	private: System::Windows::Forms::Button^  buttonAns;
	private: System::Windows::Forms::TextBox^  textInputX;

	private: System::Windows::Forms::TextBox^  textInputY;


	private: System::Windows::Forms::TextBox^  textOutput;

	private: System::Windows::Forms::ErrorProvider^  errorProviderX;
	private: System::Windows::Forms::ErrorProvider^  errorProviderY;
	private: System::Windows::Forms::Label^  labelODZ1;





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
			this->labelX = (gcnew System::Windows::Forms::Label());
			this->labelY = (gcnew System::Windows::Forms::Label());
			this->labelAns = (gcnew System::Windows::Forms::Label());
			this->buttonAns = (gcnew System::Windows::Forms::Button());
			this->textInputX = (gcnew System::Windows::Forms::TextBox());
			this->textInputY = (gcnew System::Windows::Forms::TextBox());
			this->textOutput = (gcnew System::Windows::Forms::TextBox());
			this->errorProviderX = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProviderY = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->labelODZ1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderY))->BeginInit();
			this->SuspendLayout();
			// 
			// labelX
			// 
			this->labelX->AutoSize = true;
			this->labelX->Location = System::Drawing::Point(12, 44);
			this->labelX->Name = L"labelX";
			this->labelX->Size = System::Drawing::Size(20, 20);
			this->labelX->TabIndex = 0;
			this->labelX->Text = L"X";
			// 
			// labelY
			// 
			this->labelY->AutoSize = true;
			this->labelY->Location = System::Drawing::Point(12, 98);
			this->labelY->Name = L"labelY";
			this->labelY->Size = System::Drawing::Size(20, 20);
			this->labelY->TabIndex = 1;
			this->labelY->Text = L"Y";
			// 
			// labelAns
			// 
			this->labelAns->AutoSize = true;
			this->labelAns->Location = System::Drawing::Point(12, 158);
			this->labelAns->Name = L"labelAns";
			this->labelAns->Size = System::Drawing::Size(89, 20);
			this->labelAns->TabIndex = 2;
			this->labelAns->Text = L"Результат";
			// 
			// buttonAns
			// 
			this->buttonAns->Location = System::Drawing::Point(208, 247);
			this->buttonAns->Name = L"buttonAns";
			this->buttonAns->Size = System::Drawing::Size(117, 30);
			this->buttonAns->TabIndex = 3;
			this->buttonAns->Text = L"Посчитать";
			this->buttonAns->UseVisualStyleBackColor = true;
			this->buttonAns->Click += gcnew System::EventHandler(this, &MyForm::buttonAns_Click);
			// 
			// textInputX
			// 
			this->textInputX->Location = System::Drawing::Point(136, 41);
			this->textInputX->Name = L"textInputX";
			this->textInputX->Size = System::Drawing::Size(258, 26);
			this->textInputX->TabIndex = 4;
			// 
			// textInputY
			// 
			this->textInputY->Location = System::Drawing::Point(136, 92);
			this->textInputY->Name = L"textInputY";
			this->textInputY->Size = System::Drawing::Size(258, 26);
			this->textInputY->TabIndex = 5;
			// 
			// textOutput
			// 
			this->textOutput->Location = System::Drawing::Point(136, 152);
			this->textOutput->Name = L"textOutput";
			this->textOutput->ReadOnly = true;
			this->textOutput->Size = System::Drawing::Size(258, 26);
			this->textOutput->TabIndex = 6;
			// 
			// errorProviderX
			// 
			this->errorProviderX->ContainerControl = this;
			// 
			// errorProviderY
			// 
			this->errorProviderY->ContainerControl = this;
			// 
			// labelODZ1
			// 
			this->labelODZ1->AutoSize = true;
			this->labelODZ1->Location = System::Drawing::Point(12, 198);
			this->labelODZ1->Name = L"labelODZ1";
			this->labelODZ1->Size = System::Drawing::Size(240, 20);
			this->labelODZ1->TabIndex = 7;
			this->labelODZ1->Text = L"ОДЗ: ( (y + 2)^2 - (x + 3)^2 ) =/= 0\r\n";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(552, 289);
			this->Controls->Add(this->labelODZ1);
			this->Controls->Add(this->textOutput);
			this->Controls->Add(this->textInputY);
			this->Controls->Add(this->textInputX);
			this->Controls->Add(this->buttonAns);
			this->Controls->Add(this->labelAns);
			this->Controls->Add(this->labelY);
			this->Controls->Add(this->labelX);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Вычисление функции (Вариант 5)";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderY))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void buttonAns_Click(System::Object^  sender, System::EventArgs^  e) {
		int InputNumberX, InputNumberY;

		bool resultX = Int32::TryParse(this->textInputX->Text, InputNumberX);
		bool resultY = Int32::TryParse(this->textInputY->Text, InputNumberY);

		errorProviderX->Clear();  // Убираем старые ошибки
		errorProviderY->Clear();
		this->textOutput->Text = ""; // Убираем старый вывод

		if (!resultX && !resultY) {
			errorProviderX->SetError(this->textInputX,
				"x - не целое число");
			errorProviderY->SetError(this->textInputY,
				"y - не целое число");
		}
		else if (!resultX) {
			errorProviderX->SetError(this->textInputX,
				"x - не целое число");
		}
		else if (!resultY) {
			errorProviderY->SetError(this->textInputY,
				"y - не целое число");
		}
		else if (InputNumberX == 1 && InputNumberY == -6 || InputNumberX == 1 && InputNumberY == 2) // Проверка деления на 0
		{
			errorProviderX->SetError(this->textInputX,
				"деление на 0");
			errorProviderY->SetError(this->textInputY,
				"деление на 0");
		}
		else { // Вывод
			double OutputNumber = func(InputNumberX, InputNumberY);
			this->textOutput->Text = System::Convert::ToString(OutputNumber);
		}
	}
};
}
