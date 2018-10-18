#pragma once

namespace fileworks {

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

	private: System::Windows::Forms::Button^  btnOpen;
	private: System::Windows::Forms::Button^  btnSave;
	private: System::Windows::Forms::DataGridView^  grdInput;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog;

	private: System::Windows::Forms::Button^  btnAdd;
	private: System::Windows::Forms::Button^  btnRemove;

	private: System::Windows::Forms::Label^  lblRate;
	private: System::Windows::Forms::TextBox^  txtRate;
	private: System::Windows::Forms::ErrorProvider^  errorProvider;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Surname;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  pplName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  MiddleName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  PhoneNumber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Rate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Adress;
	private: System::Windows::Forms::Button^  btnWrite;

	private: System::Windows::Forms::DataGridView^  grdOutput;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::Label^  lblInput;
	private: System::Windows::Forms::Label^  lblOutput;

	private: System::ComponentModel::IContainer^  components;


	protected:

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
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->grdInput = (gcnew System::Windows::Forms::DataGridView());
			this->Surname = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pplName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MiddleName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PhoneNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Rate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Adress = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnRemove = (gcnew System::Windows::Forms::Button());
			this->lblRate = (gcnew System::Windows::Forms::Label());
			this->txtRate = (gcnew System::Windows::Forms::TextBox());
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->grdOutput = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnWrite = (gcnew System::Windows::Forms::Button());
			this->lblOutput = (gcnew System::Windows::Forms::Label());
			this->lblInput = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdOutput))->BeginInit();
			this->SuspendLayout();
			// 
			// btnOpen
			// 
			this->btnOpen->Location = System::Drawing::Point(1050, 33);
			this->btnOpen->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(117, 44);
			this->btnOpen->TabIndex = 1;
			this->btnOpen->Text = L"Открыть из файла";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &MyForm::btnOpen_Click);
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(1196, 33);
			this->btnSave->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(192, 44);
			this->btnSave->TabIndex = 2;
			this->btnSave->Text = L"Сохранить, учитывая тариф";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &MyForm::btnSave_Click);
			// 
			// grdInput
			// 
			this->grdInput->AllowUserToAddRows = false;
			this->grdInput->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grdInput->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Surname, this->pplName,
					this->MiddleName, this->PhoneNumber, this->Rate, this->Adress
			});
			this->grdInput->Location = System::Drawing::Point(43, 33);
			this->grdInput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grdInput->Name = L"grdInput";
			this->grdInput->RowTemplate->Height = 28;
			this->grdInput->Size = System::Drawing::Size(989, 220);
			this->grdInput->TabIndex = 3;
			// 
			// Surname
			// 
			this->Surname->HeaderText = L"Фамилия";
			this->Surname->Name = L"Surname";
			// 
			// pplName
			// 
			this->pplName->HeaderText = L"Имя";
			this->pplName->Name = L"pplName";
			// 
			// MiddleName
			// 
			this->MiddleName->HeaderText = L"Отчество абонента";
			this->MiddleName->Name = L"MiddleName";
			// 
			// PhoneNumber
			// 
			this->PhoneNumber->HeaderText = L"Номер телефона";
			this->PhoneNumber->Name = L"PhoneNumber";
			// 
			// Rate
			// 
			this->Rate->HeaderText = L"Тариф";
			this->Rate->Name = L"Rate";
			// 
			// Adress
			// 
			this->Adress->HeaderText = L"Адрес (улица, дом, квартира)";
			this->Adress->Name = L"Adress";
			this->Adress->Width = 200;
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"txt";
			this->openFileDialog->FileName = L"input";
			this->openFileDialog->Filter = L"Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";
			this->openFileDialog->Title = L"Открыть файл";
			// 
			// saveFileDialog
			// 
			this->saveFileDialog->DefaultExt = L"txt";
			this->saveFileDialog->FileName = L"output";
			this->saveFileDialog->Filter = L"Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";
			this->saveFileDialog->Title = L"Сохранить файл";
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(1050, 106);
			this->btnAdd->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(117, 49);
			this->btnAdd->TabIndex = 6;
			this->btnAdd->Text = L"Добавление строк";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &MyForm::btnAdd_Click);
			// 
			// btnRemove
			// 
			this->btnRemove->Location = System::Drawing::Point(1051, 171);
			this->btnRemove->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnRemove->Name = L"btnRemove";
			this->btnRemove->Size = System::Drawing::Size(116, 49);
			this->btnRemove->TabIndex = 7;
			this->btnRemove->Text = L"Удаление строк";
			this->btnRemove->UseVisualStyleBackColor = true;
			this->btnRemove->Click += gcnew System::EventHandler(this, &MyForm::btnRemove_Click);
			// 
			// lblRate
			// 
			this->lblRate->AutoSize = true;
			this->lblRate->Location = System::Drawing::Point(1192, 185);
			this->lblRate->Name = L"lblRate";
			this->lblRate->Size = System::Drawing::Size(56, 17);
			this->lblRate->TabIndex = 8;
			this->lblRate->Text = L"Тариф:";
			// 
			// txtRate
			// 
			this->txtRate->Location = System::Drawing::Point(1254, 182);
			this->txtRate->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtRate->Name = L"txtRate";
			this->txtRate->Size = System::Drawing::Size(111, 22);
			this->txtRate->TabIndex = 9;
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// grdOutput
			// 
			this->grdOutput->AllowUserToAddRows = false;
			this->grdOutput->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grdOutput->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5,
					this->dataGridViewTextBoxColumn6
			});
			this->grdOutput->Location = System::Drawing::Point(43, 289);
			this->grdOutput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grdOutput->Name = L"grdOutput";
			this->grdOutput->RowTemplate->Height = 28;
			this->grdOutput->Size = System::Drawing::Size(989, 220);
			this->grdOutput->TabIndex = 10;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Фамилия";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Имя";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Отчество абонента";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Номер телефона";
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"Тариф";
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->HeaderText = L"Адрес (улица, дом, квартира)";
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			this->dataGridViewTextBoxColumn6->Width = 200;
			// 
			// btnWrite
			// 
			this->btnWrite->Location = System::Drawing::Point(1196, 106);
			this->btnWrite->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnWrite->Name = L"btnWrite";
			this->btnWrite->Size = System::Drawing::Size(192, 44);
			this->btnWrite->TabIndex = 11;
			this->btnWrite->Text = L"Запись в таблицу с условием";
			this->btnWrite->UseVisualStyleBackColor = true;
			this->btnWrite->Click += gcnew System::EventHandler(this, &MyForm::btnWrite_Click);
			// 
			// lblOutput
			// 
			this->lblOutput->AutoSize = true;
			this->lblOutput->Location = System::Drawing::Point(48, 270);
			this->lblOutput->Name = L"lblOutput";
			this->lblOutput->Size = System::Drawing::Size(117, 17);
			this->lblOutput->TabIndex = 12;
			this->lblOutput->Text = L"Таблица вывода";
			// 
			// lblInput
			// 
			this->lblInput->AutoSize = true;
			this->lblInput->Location = System::Drawing::Point(48, 14);
			this->lblInput->Name = L"lblInput";
			this->lblInput->Size = System::Drawing::Size(107, 17);
			this->lblInput->TabIndex = 13;
			this->lblInput->Text = L"Таблица ввода";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1417, 518);
			this->Controls->Add(this->lblInput);
			this->Controls->Add(this->lblOutput);
			this->Controls->Add(this->btnWrite);
			this->Controls->Add(this->grdOutput);
			this->Controls->Add(this->txtRate);
			this->Controls->Add(this->lblRate);
			this->Controls->Add(this->btnRemove);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->grdInput);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->btnOpen);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximumSize = System::Drawing::Size(2224, 2009);
			this->Name = L"MyForm";
			this->Text = L"Работа с файлами (Вар. 8)";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdOutput))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Функция удаления всех строк таблицы
	private: void DeleteRows() {
		while (this->grdInput->RowCount > 0)
			this->grdInput->Rows->Remove(this->grdInput->Rows[this->grdInput->RowCount - 1]);
	}
			 // Функция удаления всех строк вывода
	private: void DeleteRowsOutput() {
		while (this->grdOutput->RowCount > 0)
			this->grdOutput->Rows->Remove(this->grdOutput->Rows[this->grdOutput->RowCount - 1]);
	}
			 // Проверка корректности ввода номера телефона
	private: bool CheckPhone(System::String^ PhoneNum) {
		for (int i = 0; i < PhoneNum->Length; i++) {
			if ((PhoneNum[i] - '0' < 0 || PhoneNum[i] - '0' > 9) && PhoneNum[i] != '-') {
				errorProvider->SetError(grdInput, "Номер телефона не должен содержать других символов кроме цифр и '-' ");
				return false;
			}
		}
		return true;
	}

			 // Кнопка открытия .txt документа
	private: System::Void btnOpen_Click(System::Object^  sender, System::EventArgs^  e) {
		errorProvider->Clear();

		// Считывание данных, результат кладется в strData
		System::IO::Stream^ myStream;
		if (this->openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			if ((myStream = openFileDialog->OpenFile()) != nullptr) {
				System::IO::StreamReader^ sw =
					gcnew System::IO::StreamReader(myStream,
						System::Text::Encoding::GetEncoding(1251));
				System::String ^strData = sw->ReadToEnd(); 
				sw->Close();

				// Удаление предыдущей информации в таблице
				DeleteRows();

				// Разделение ввода, разделитель - знак табуляции и перевода строки
				System::String^ delimStr = "\t,\n,\r";
				array <wchar_t>^ delimiter = delimStr->ToCharArray();
				array <System::String^>^ words;
				words = strData->Split(delimiter);

				int passed = 0;		// Если в вводе оказался знак пробела, пропускаем его и считаем их количество
				// Ввод данных в таблицу
				for (int i = 0; i < words->Length; i++) {
					if (words[i] == "") {
						passed++;
						continue;
					}
					else {
						// Для сохранения порядка ввода в таблицу не считаем пропущенные пробелы
						if ((i - passed) % 6 == 0)
							this->grdInput->Rows->Add(1);
						int rowN = i - passed;
						this->grdInput[rowN % 6, rowN / 6]->Value = words[i];
					}

				}
			}

	}

			 // Кнопка сохранения в .txt документ
	private: System::Void btnSave_Click(System::Object^  sender, System::EventArgs^  e) {
		errorProvider->Clear();

		bool IsAreaWrong = false; // Если эта переменная true, то появится ошибка и выполнение прервется
								  // Проверка на наличие пустых ячеек

		for (int i = 0; i < this->grdInput->RowCount; i++) {
			for (int j = 0; j < this->grdInput->ColumnCount; j++) {
				if (!((System::String^)this->grdInput[j, i]->Value)) {
					IsAreaWrong = true;		// Ошибка найдена
					errorProvider->SetError(this->grdInput,
						"Пустые ячейки таблицы недопустимы");
					break;
				}
			}
		}
		// Выбранный тариф для сохранения элементов с ним
		System::String^ ChosenRate = this->txtRate->Text->ToString();
		if (!IsAreaWrong) {
			if (ChosenRate != "")
				ChosenRate->ToLower(); // Случайные заглавные буквы не сломают программу
			else {
				IsAreaWrong = true;
				errorProvider->SetError(this->txtRate, "Необходимо заполнить поле тарифа");
			}
		}
		// Была ли найдена до этого ошибка
		if (IsAreaWrong)
			return;

		System::IO::Stream^ myStream;
		if (this->saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			if ((myStream = saveFileDialog->OpenFile()) != nullptr) {
				System::IO::StreamWriter^ sw =
					gcnew System::IO::StreamWriter(myStream,
						System::Text::Encoding::GetEncoding(1251));

				bool AnyGoodRateFound = false;	// Найден ли хоть 1 пользователь с нужным тарифом
				for (int i = 0; i < grdInput->RowCount; i++) {
					// Правильно ли введён номер телефона
					if (!CheckPhone(this->grdInput[3, i]->Value->ToString())) {
						sw->Close();
						return;
					}
					// Совпадает ли ячейка тарифа с заданным для сохранения
					if (this->grdInput[4, i]->Value->ToString()->ToLower() != ChosenRate)
						continue;
					AnyGoodRateFound = true;
					if (i != 0)
						sw->WriteLine("");	// Перевод на новую строку
					for (int j = 0; j < grdInput->ColumnCount; j++) {
						sw->Write(this->grdInput[j, i]->Value);
						sw->Write("\t");
					}
				}
				if (AnyGoodRateFound == 0)
					errorProvider->SetError(this->grdInput,
						"Не найдены люди с таким тарифом / тариф указан неверно");
				sw->Close();
			}

	}

			 // Кнопка добавления строк
	private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e) {
		this->grdInput->Rows->Add(1);
		DeleteRowsOutput();
	}
			 // Кнопка удаления строк
	private: System::Void btnRemove_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->grdInput->RowCount > 0) {
			this->grdInput->Rows->Remove(this->grdInput->Rows[this->grdInput->RowCount - 1]);
		}
		DeleteRowsOutput();
	}

			 // Кнопка записи во вторую таблицу
	private: System::Void btnWrite_Click(System::Object^  sender, System::EventArgs^  e) {
		errorProvider->Clear();
		DeleteRowsOutput();

		// Проверка на наличие пустых ячеек
		for (int i = 0; i < this->grdInput->RowCount; i++) {
			for (int j = 0; j < this->grdInput->ColumnCount; j++) {
				if (!((System::String^)this->grdInput[j, i]->Value)) {
					errorProvider->SetError(this->grdInput,
						"Пустые ячейки таблицы недопустимы");
					DeleteRowsOutput();
					return;
				}
			}
		}
		// Выбранный тариф для сохранения элементов с ним
		System::String^ ChosenRate = this->txtRate->Text->ToString();
		if (ChosenRate != "")
			ChosenRate->ToLower(); // Случайные заглавные буквы не сломают программу
		else {
			DeleteRowsOutput();
			errorProvider->SetError(this->txtRate, "Необходимо заполнить поле тарифа");
			return;
		}

		int badStr = 0; // Кол-во строк с несовпадающими тарифами
		int i = 0;
		for (i = 0; i < grdInput->RowCount; i++) {
			// Проверка корректности номера телефона
			if (!CheckPhone(this->grdInput[3, i]->Value->ToString())) {
				DeleteRowsOutput();
				return;
			}
			// Проверка совпадения тарифа
			if (this->grdInput[4, i]->Value->ToString()->ToLower() != ChosenRate) {
				badStr++;
				continue;
			}
			grdOutput->Rows->Add(1);
			for (int j = 0; j < grdInput->ColumnCount; j++) {
				this->grdOutput[j, i - badStr]->Value = this->grdInput[j, i]->Value;
			}
		}
		if (badStr == i)
			errorProvider->SetError(this->txtRate,
				"Не найдены люди с таким тарифом / тариф указан неверно");
	}
};
}
