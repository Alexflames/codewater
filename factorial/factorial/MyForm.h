#pragma once
#include "fact.h"

namespace factorial {

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
	private: System::Windows::Forms::TextBox^  txtInput;
	private: System::Windows::Forms::TextBox^  txtOutput;
	protected:

	protected:

	private: System::Windows::Forms::Label^  lblInput;
	private: System::Windows::Forms::Label^  lblOutput;
	private: System::Windows::Forms::Button^  btnCalculate;
	private: System::Windows::Forms::ErrorProvider^  errorProvider;
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
			this->txtInput = (gcnew System::Windows::Forms::TextBox());
			this->txtOutput = (gcnew System::Windows::Forms::TextBox());
			this->lblInput = (gcnew System::Windows::Forms::Label());
			this->lblOutput = (gcnew System::Windows::Forms::Label());
			this->btnCalculate = (gcnew System::Windows::Forms::Button());
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->BeginInit();
			this->SuspendLayout();
			// 
			// txtInput
			// 
			this->txtInput->Location = System::Drawing::Point(193, 58);
			this->txtInput->Name = L"txtInput";
			this->txtInput->Size = System::Drawing::Size(213, 26);
			this->txtInput->TabIndex = 0;
			// 
			// txtOutput
			// 
			this->txtOutput->Location = System::Drawing::Point(193, 151);
			this->txtOutput->Name = L"txtOutput";
			this->txtOutput->ReadOnly = true;
			this->txtOutput->Size = System::Drawing::Size(213, 26);
			this->txtOutput->TabIndex = 1;
			// 
			// lblInput
			// 
			this->lblInput->AutoSize = true;
			this->lblInput->Location = System::Drawing::Point(12, 58);
			this->lblInput->Name = L"lblInput";
			this->lblInput->Size = System::Drawing::Size(175, 20);
			this->lblInput->TabIndex = 2;
			this->lblInput->Text = L"Введите целое число";
			// 
			// lblOutput
			// 
			this->lblOutput->AutoSize = true;
			this->lblOutput->Location = System::Drawing::Point(12, 157);
			this->lblOutput->Name = L"lblOutput";
			this->lblOutput->Size = System::Drawing::Size(89, 20);
			this->lblOutput->TabIndex = 3;
			this->lblOutput->Text = L"Результат";
			// 
			// btnCalculate
			// 
			this->btnCalculate->Location = System::Drawing::Point(193, 222);
			this->btnCalculate->Name = L"btnCalculate";
			this->btnCalculate->Size = System::Drawing::Size(125, 30);
			this->btnCalculate->TabIndex = 4;
			this->btnCalculate->Text = L"Вычислить";
			this->btnCalculate->UseVisualStyleBackColor = true;
			this->btnCalculate->Click += gcnew System::EventHandler(this, &MyForm::btnCalculate_Click);
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(517, 281);
			this->Controls->Add(this->btnCalculate);
			this->Controls->Add(this->lblOutput);
			this->Controls->Add(this->lblInput);
			this->Controls->Add(this->txtOutput);
			this->Controls->Add(this->txtInput);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Факториал";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnCalculate_Click(System::Object^  sender, System::EventArgs^  e) {
		int InputNumber;
		this->txtOutput->Text = "";
		bool result = Int32::TryParse(this->txtInput->Text, InputNumber);
		if (InputNumber > 20) // Проверка на выход за границы типа
			errorProvider->SetError(this->txtInput,
				"выход за границы диапазона типа");
		else if (InputNumber < 0) // Проверка на отрицательность
			errorProvider->SetError(this->txtInput,
				"отрицательное число");
		else if (result) {

			errorProvider->Clear();  // В случае успешной проверки убираем ошибку при ее наличии
			long long OutputNumber = fact(InputNumber);
			this->txtOutput->Text = System::Convert::ToString(OutputNumber);
		}
		else {
			this->txtOutput->Text = "";
			errorProvider->SetError(this->txtInput,
				"Введенная последовательноть символов не является целым числом");
		}
	}
};
}
