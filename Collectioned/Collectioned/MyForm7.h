#pragma once

namespace Collectioned {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm7
	/// </summary>
	public ref class MyForm7 : public System::Windows::Forms::Form
	{
	public:
		MyForm7(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm7()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblX;
	private: System::Windows::Forms::Label^  lblY;
	private: System::Windows::Forms::TextBox^  txtX;
	private: System::Windows::Forms::TextBox^  txtY;
	private: System::Windows::Forms::Button^  btnCreate;
	private: System::Windows::Forms::ErrorProvider^  errorProviderX;
	private: System::Windows::Forms::ErrorProvider^  errorProviderY;
	private: System::Windows::Forms::TextBox^  txtSetY;
	private: System::Windows::Forms::TextBox^  txtSetX;
	private: System::Windows::Forms::Label^  lblSetY;
	private: System::Windows::Forms::Label^  lblSetX;
	private: System::Windows::Forms::Button^  btnAddX;
	private: System::Windows::Forms::Button^  btnAddY;
	private: System::Windows::Forms::TextBox^  txtAddY;
	private: System::Windows::Forms::TextBox^  txtAddX;
	private: System::Windows::Forms::Button^  btnRemoveX;
	private: System::Windows::Forms::Button^  btnRemoveY;
	private: System::Windows::Forms::TextBox^  txtRemoveY;
	private: System::Windows::Forms::TextBox^  txtRemoveX;


	private: System::Windows::Forms::Button^  btnIntersect;
	private: System::Windows::Forms::ErrorProvider^  errorProviderFunc;
	private: System::Windows::Forms::Button^  btnUnite;
	private: System::Windows::Forms::TextBox^  txtChanged;
	private: System::Windows::Forms::Button^  btnDifference;
	private: System::Windows::Forms::Button^  btnCheckSub;
	private: System::Windows::Forms::TextBox^  txtCheckRes;
	private: System::Windows::Forms::Button^  btnIsEven;
	private: System::Windows::Forms::TextBox^  txtIsEven;
	private: System::Windows::Forms::Button^  btnRemoveAllY;
	private: System::Windows::Forms::Button^  btnRemoveAllX;











	private: System::ComponentModel::IContainer^  components;
	protected:


	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lblX = (gcnew System::Windows::Forms::Label());
			this->lblY = (gcnew System::Windows::Forms::Label());
			this->txtX = (gcnew System::Windows::Forms::TextBox());
			this->txtY = (gcnew System::Windows::Forms::TextBox());
			this->btnCreate = (gcnew System::Windows::Forms::Button());
			this->errorProviderX = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProviderY = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->txtSetX = (gcnew System::Windows::Forms::TextBox());
			this->txtSetY = (gcnew System::Windows::Forms::TextBox());
			this->lblSetX = (gcnew System::Windows::Forms::Label());
			this->lblSetY = (gcnew System::Windows::Forms::Label());
			this->btnAddX = (gcnew System::Windows::Forms::Button());
			this->btnAddY = (gcnew System::Windows::Forms::Button());
			this->txtAddX = (gcnew System::Windows::Forms::TextBox());
			this->txtAddY = (gcnew System::Windows::Forms::TextBox());
			this->btnRemoveX = (gcnew System::Windows::Forms::Button());
			this->btnRemoveY = (gcnew System::Windows::Forms::Button());
			this->txtRemoveX = (gcnew System::Windows::Forms::TextBox());
			this->txtRemoveY = (gcnew System::Windows::Forms::TextBox());
			this->btnIntersect = (gcnew System::Windows::Forms::Button());
			this->errorProviderFunc = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->btnUnite = (gcnew System::Windows::Forms::Button());
			this->txtChanged = (gcnew System::Windows::Forms::TextBox());
			this->btnDifference = (gcnew System::Windows::Forms::Button());
			this->btnCheckSub = (gcnew System::Windows::Forms::Button());
			this->txtCheckRes = (gcnew System::Windows::Forms::TextBox());
			this->btnIsEven = (gcnew System::Windows::Forms::Button());
			this->txtIsEven = (gcnew System::Windows::Forms::TextBox());
			this->btnRemoveAllX = (gcnew System::Windows::Forms::Button());
			this->btnRemoveAllY = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderFunc))->BeginInit();
			this->SuspendLayout();
			// 
			// lblX
			// 
			this->lblX->AutoSize = true;
			this->lblX->Location = System::Drawing::Point(31, 30);
			this->lblX->Name = L"lblX";
			this->lblX->Size = System::Drawing::Size(220, 17);
			this->lblX->TabIndex = 0;
			this->lblX->Text = L"������� �������� ��������� X\r\n";
			// 
			// lblY
			// 
			this->lblY->AutoSize = true;
			this->lblY->Location = System::Drawing::Point(470, 30);
			this->lblY->Name = L"lblY";
			this->lblY->Size = System::Drawing::Size(220, 34);
			this->lblY->TabIndex = 1;
			this->lblY->Text = L"������� �������� ��������� Y\r\n\r\n";
			// 
			// txtX
			// 
			this->txtX->Location = System::Drawing::Point(34, 68);
			this->txtX->Name = L"txtX";
			this->txtX->Size = System::Drawing::Size(217, 22);
			this->txtX->TabIndex = 2;
			// 
			// txtY
			// 
			this->txtY->Location = System::Drawing::Point(473, 67);
			this->txtY->Name = L"txtY";
			this->txtY->Size = System::Drawing::Size(217, 22);
			this->txtY->TabIndex = 3;
			// 
			// btnCreate
			// 
			this->btnCreate->Location = System::Drawing::Point(302, 67);
			this->btnCreate->Name = L"btnCreate";
			this->btnCreate->Size = System::Drawing::Size(125, 63);
			this->btnCreate->TabIndex = 4;
			this->btnCreate->Text = L"�������\r\n���������";
			this->btnCreate->UseVisualStyleBackColor = true;
			this->btnCreate->Click += gcnew System::EventHandler(this, &MyForm7::btnCreate_Click);
			// 
			// errorProviderX
			// 
			this->errorProviderX->ContainerControl = this;
			// 
			// errorProviderY
			// 
			this->errorProviderY->ContainerControl = this;
			// 
			// txtSetX
			// 
			this->txtSetX->Location = System::Drawing::Point(34, 119);
			this->txtSetX->Name = L"txtSetX";
			this->txtSetX->ReadOnly = true;
			this->txtSetX->Size = System::Drawing::Size(217, 22);
			this->txtSetX->TabIndex = 5;
			// 
			// txtSetY
			// 
			this->txtSetY->Location = System::Drawing::Point(473, 119);
			this->txtSetY->Name = L"txtSetY";
			this->txtSetY->ReadOnly = true;
			this->txtSetY->Size = System::Drawing::Size(217, 22);
			this->txtSetY->TabIndex = 6;
			// 
			// lblSetX
			// 
			this->lblSetX->AutoSize = true;
			this->lblSetX->Location = System::Drawing::Point(98, 99);
			this->lblSetX->Name = L"lblSetX";
			this->lblSetX->Size = System::Drawing::Size(94, 17);
			this->lblSetX->TabIndex = 7;
			this->lblSetX->Text = L"��������� X";
			// 
			// lblSetY
			// 
			this->lblSetY->AutoSize = true;
			this->lblSetY->Location = System::Drawing::Point(534, 99);
			this->lblSetY->Name = L"lblSetY";
			this->lblSetY->Size = System::Drawing::Size(94, 17);
			this->lblSetY->TabIndex = 8;
			this->lblSetY->Text = L"��������� Y";
			// 
			// btnAddX
			// 
			this->btnAddX->Location = System::Drawing::Point(127, 171);
			this->btnAddX->Name = L"btnAddX";
			this->btnAddX->Size = System::Drawing::Size(124, 33);
			this->btnAddX->TabIndex = 9;
			this->btnAddX->Text = L"�������� � X";
			this->btnAddX->UseVisualStyleBackColor = true;
			this->btnAddX->Click += gcnew System::EventHandler(this, &MyForm7::btnAddX_Click);
			// 
			// btnAddY
			// 
			this->btnAddY->Location = System::Drawing::Point(473, 171);
			this->btnAddY->Name = L"btnAddY";
			this->btnAddY->Size = System::Drawing::Size(124, 33);
			this->btnAddY->TabIndex = 10;
			this->btnAddY->Text = L"�������� � Y";
			this->btnAddY->UseVisualStyleBackColor = true;
			this->btnAddY->Click += gcnew System::EventHandler(this, &MyForm7::btnAddY_Click);
			// 
			// txtAddX
			// 
			this->txtAddX->Location = System::Drawing::Point(34, 176);
			this->txtAddX->Name = L"txtAddX";
			this->txtAddX->Size = System::Drawing::Size(87, 22);
			this->txtAddX->TabIndex = 11;
			// 
			// txtAddY
			// 
			this->txtAddY->Location = System::Drawing::Point(603, 176);
			this->txtAddY->Name = L"txtAddY";
			this->txtAddY->Size = System::Drawing::Size(87, 22);
			this->txtAddY->TabIndex = 12;
			// 
			// btnRemoveX
			// 
			this->btnRemoveX->Location = System::Drawing::Point(127, 210);
			this->btnRemoveX->Name = L"btnRemoveX";
			this->btnRemoveX->Size = System::Drawing::Size(124, 33);
			this->btnRemoveX->TabIndex = 13;
			this->btnRemoveX->Text = L"������� �� X";
			this->btnRemoveX->UseVisualStyleBackColor = true;
			this->btnRemoveX->Click += gcnew System::EventHandler(this, &MyForm7::btnRemoveX_Click);
			// 
			// btnRemoveY
			// 
			this->btnRemoveY->Location = System::Drawing::Point(473, 210);
			this->btnRemoveY->Name = L"btnRemoveY";
			this->btnRemoveY->Size = System::Drawing::Size(124, 33);
			this->btnRemoveY->TabIndex = 14;
			this->btnRemoveY->Text = L"������� �� Y";
			this->btnRemoveY->UseVisualStyleBackColor = true;
			this->btnRemoveY->Click += gcnew System::EventHandler(this, &MyForm7::btnRemoveY_Click);
			// 
			// txtRemoveX
			// 
			this->txtRemoveX->Location = System::Drawing::Point(34, 215);
			this->txtRemoveX->Name = L"txtRemoveX";
			this->txtRemoveX->Size = System::Drawing::Size(87, 22);
			this->txtRemoveX->TabIndex = 15;
			// 
			// txtRemoveY
			// 
			this->txtRemoveY->Location = System::Drawing::Point(603, 215);
			this->txtRemoveY->Name = L"txtRemoveY";
			this->txtRemoveY->Size = System::Drawing::Size(87, 22);
			this->txtRemoveY->TabIndex = 16;
			// 
			// btnIntersect
			// 
			this->btnIntersect->Location = System::Drawing::Point(127, 282);
			this->btnIntersect->Name = L"btnIntersect";
			this->btnIntersect->Size = System::Drawing::Size(112, 50);
			this->btnIntersect->TabIndex = 17;
			this->btnIntersect->Text = L"����������� ��������";
			this->btnIntersect->UseVisualStyleBackColor = true;
			this->btnIntersect->Click += gcnew System::EventHandler(this, &MyForm7::btnIntersect_Click);
			// 
			// errorProviderFunc
			// 
			this->errorProviderFunc->ContainerControl = this;
			// 
			// btnUnite
			// 
			this->btnUnite->Location = System::Drawing::Point(245, 282);
			this->btnUnite->Name = L"btnUnite";
			this->btnUnite->Size = System::Drawing::Size(109, 50);
			this->btnUnite->TabIndex = 19;
			this->btnUnite->Text = L"����������� ��������";
			this->btnUnite->UseVisualStyleBackColor = true;
			this->btnUnite->Click += gcnew System::EventHandler(this, &MyForm7::btnUnite_Click);
			// 
			// txtChanged
			// 
			this->txtChanged->Location = System::Drawing::Point(127, 338);
			this->txtChanged->Name = L"txtChanged";
			this->txtChanged->ReadOnly = true;
			this->txtChanged->Size = System::Drawing::Size(340, 22);
			this->txtChanged->TabIndex = 20;
			// 
			// btnDifference
			// 
			this->btnDifference->Location = System::Drawing::Point(360, 282);
			this->btnDifference->Name = L"btnDifference";
			this->btnDifference->Size = System::Drawing::Size(107, 50);
			this->btnDifference->TabIndex = 21;
			this->btnDifference->Text = L"�������� ��������";
			this->btnDifference->UseVisualStyleBackColor = true;
			this->btnDifference->Click += gcnew System::EventHandler(this, &MyForm7::btnDifference_Click);
			// 
			// btnCheckSub
			// 
			this->btnCheckSub->Location = System::Drawing::Point(302, 192);
			this->btnCheckSub->Name = L"btnCheckSub";
			this->btnCheckSub->Size = System::Drawing::Size(125, 45);
			this->btnCheckSub->TabIndex = 22;
			this->btnCheckSub->Text = L"X ������������ Y \?";
			this->btnCheckSub->UseVisualStyleBackColor = true;
			this->btnCheckSub->Click += gcnew System::EventHandler(this, &MyForm7::btnCheckSub_Click);
			// 
			// txtCheckRes
			// 
			this->txtCheckRes->Location = System::Drawing::Point(273, 249);
			this->txtCheckRes->Name = L"txtCheckRes";
			this->txtCheckRes->ReadOnly = true;
			this->txtCheckRes->Size = System::Drawing::Size(179, 22);
			this->txtCheckRes->TabIndex = 23;
			// 
			// btnIsEven
			// 
			this->btnIsEven->Location = System::Drawing::Point(472, 282);
			this->btnIsEven->Name = L"btnIsEven";
			this->btnIsEven->Size = System::Drawing::Size(125, 50);
			this->btnIsEven->TabIndex = 24;
			this->btnIsEven->Text = L"��� ����� ������\?";
			this->btnIsEven->UseVisualStyleBackColor = true;
			this->btnIsEven->Click += gcnew System::EventHandler(this, &MyForm7::btnIsEven_Click);
			// 
			// txtIsEven
			// 
			this->txtIsEven->Location = System::Drawing::Point(473, 338);
			this->txtIsEven->Name = L"txtIsEven";
			this->txtIsEven->ReadOnly = true;
			this->txtIsEven->Size = System::Drawing::Size(124, 22);
			this->txtIsEven->TabIndex = 25;
			// 
			// btnRemoveAllX
			// 
			this->btnRemoveAllX->Location = System::Drawing::Point(34, 249);
			this->btnRemoveAllX->Name = L"btnRemoveAllX";
			this->btnRemoveAllX->Size = System::Drawing::Size(217, 27);
			this->btnRemoveAllX->TabIndex = 26;
			this->btnRemoveAllX->Text = L"������� ��� �� X";
			this->btnRemoveAllX->UseVisualStyleBackColor = true;
			this->btnRemoveAllX->Click += gcnew System::EventHandler(this, &MyForm7::btnRemoveAllX_Click);
			// 
			// btnRemoveAllY
			// 
			this->btnRemoveAllY->Location = System::Drawing::Point(473, 249);
			this->btnRemoveAllY->Name = L"btnRemoveAllY";
			this->btnRemoveAllY->Size = System::Drawing::Size(217, 27);
			this->btnRemoveAllY->TabIndex = 27;
			this->btnRemoveAllY->Text = L"������� ��� �� Y";
			this->btnRemoveAllY->UseVisualStyleBackColor = true;
			this->btnRemoveAllY->Click += gcnew System::EventHandler(this, &MyForm7::btnRemoveAllY_Click);
			// 
			// MyForm7
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(719, 372);
			this->Controls->Add(this->btnRemoveAllY);
			this->Controls->Add(this->btnRemoveAllX);
			this->Controls->Add(this->txtIsEven);
			this->Controls->Add(this->btnIsEven);
			this->Controls->Add(this->txtCheckRes);
			this->Controls->Add(this->btnCheckSub);
			this->Controls->Add(this->btnDifference);
			this->Controls->Add(this->txtChanged);
			this->Controls->Add(this->btnUnite);
			this->Controls->Add(this->btnIntersect);
			this->Controls->Add(this->txtRemoveY);
			this->Controls->Add(this->txtRemoveX);
			this->Controls->Add(this->btnRemoveY);
			this->Controls->Add(this->btnRemoveX);
			this->Controls->Add(this->txtAddY);
			this->Controls->Add(this->txtAddX);
			this->Controls->Add(this->btnAddY);
			this->Controls->Add(this->btnAddX);
			this->Controls->Add(this->lblSetY);
			this->Controls->Add(this->lblSetX);
			this->Controls->Add(this->txtSetY);
			this->Controls->Add(this->txtSetX);
			this->Controls->Add(this->btnCreate);
			this->Controls->Add(this->txtY);
			this->Controls->Add(this->txtX);
			this->Controls->Add(this->lblY);
			this->Controls->Add(this->lblX);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm7";
			this->Text = L"��������� (���.6)";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderFunc))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// �������� ����
	private: System::Collections::Generic::SortedSet<int> setX, setY;
	// ���, �������������� ����� ��������� � ����������� �������
	private: System::Collections::Generic::SortedSet<int> setChanged;

	//-----------������ �������, ����������� �����------//
	// ����� � ���� - ��������� X
	private: void FillTxtX() {
		// �������� ������� - ����� ���� X
		int setXlength = setX.Count;
		array<int>^tempY = gcnew array<int>(setXlength);
		setX.CopyTo(tempY);

		System::String^ SetXdisplay;	// ������ ������
		SetXdisplay = "";
		for (int i = 0; i < tempY->Length; i++) {
			SetXdisplay += tempY[i].ToString() + " ";
		}
		this->txtSetX->Text = SetXdisplay;
	}

	// ����� � ���� - ��������� Y
	private: void FillTxtY() {
		// �������� ������� - ����� ���� Y
		int setYlength = setY.Count;
		array<int>^tempY = gcnew array<int>(setYlength);
		setY.CopyTo(tempY);

		System::String^ SetYdisplay;	// ������ ������
		SetYdisplay = "";
		for (int i = 0; i < tempY->Length; i++) {
			SetYdisplay += tempY[i].ToString() + " ";
		}
		this->txtSetY->Text = SetYdisplay;
	}

	// ����� � ���� - ����� ���������
	private: void FillTxtChanged() {
		// �������� ������� - ����� ���� 
		int setChangedlength = setChanged.Count;
		array<int>^tempY = gcnew array<int>(setChangedlength);
		setChanged.CopyTo(tempY);

		System::String^ SetChangeddisplay; // ����� �� �����
		SetChangeddisplay = "";
		for (int i = 0; i < tempY->Length; i++) {
			SetChangeddisplay += tempY[i].ToString() + " ";
		}
		this->txtChanged->Text = SetChangeddisplay;
	}

	// ������� �������� ������ � ������
	private: void InfoClean() {
		setChanged.Clear();
		this->errorProviderX->Clear(); 
		this->errorProviderY->Clear(); 
		this->errorProviderFunc->Clear(); this->txtChanged->Text = "";
		this->txtCheckRes->Text = ""; this->txtIsEven->Text = "";
	}

	//------------������� - ������----------------//			
	// �������� �������� �� ������
	private: System::Void btnCreate_Click(System::Object^  sender, System::EventArgs^  e) {
		this->txtSetX->Text = "";
		this->txtSetY->Text = "";
		InfoClean(); setX.Clear(); setY.Clear();

		System::String^ InfX = this->txtX->Text;
		System::String^ InfY = this->txtY->Text;

		if (InfX == "" || InfY == "")
			errorProviderFunc->SetError(btnCreate, "���� ��� ��� ��������� ������");

		// ���������� �����, ����������� - ���� �������
		System::String^ delimStr = " ";
		array <wchar_t>^ delimiter = delimStr->ToCharArray();
		array <System::String^>^ InfXsplit, ^InfYsplit;
		InfXsplit = InfX->Split(delimiter);
		InfYsplit = InfY->Split(delimiter);

		// ���������� ���� X
		bool CheckX, CheckY;
		for (int i = 0; i < InfXsplit->Length; i++) {
			if (InfXsplit[i] == "") // ���������� �������
				continue;
			int numX;
			CheckX = Int32::TryParse(InfXsplit[i], numX);
			if (!CheckX) {
				errorProviderX->SetError(this->txtX, "�� ��������� ����� ������� ����� ����");
				break;
			}
			else 
				setX.Add(numX);
			
		}
		// ���������� ���� Y
		for (int i = 0; i < InfYsplit->Length; i++) {
			if (InfYsplit[i] == "") // ���������� �������
				continue;
			int numY;
			CheckY = Int32::TryParse(InfYsplit[i], numY);
			if (!CheckY) {
				errorProviderY->SetError(this->txtY, "�� ��������� ����� ������� ����� ����");
				break;
			}
			else 
				setY.Add(numY);
			
		}
		// �������� ������ � ������ ����� � ������������ � (��)���������� ��������
		if (CheckX) {
			FillTxtX();
		}
		else {
			setX.Clear();
		}
		if (CheckY) {
			FillTxtY();
		}
		else {
			setY.Clear();
		}
		if (CheckX && CheckY) {
			this->txtX->Text = "";
			this->txtY->Text = "";
		}
	}

	// ���������� �������� � X
	private: System::Void btnAddX_Click(System::Object^  sender, System::EventArgs^  e) {
		InfoClean();

		int numX;
		bool CheckX = Int32::TryParse(this->txtAddX->Text, numX);
		if (!CheckX) {
			errorProviderX->SetError(btnAddX, "������ ������ - �� �����");
		}
		else {
			setX.Add(numX);
			FillTxtX();
		}
		txtAddX->Text = "";
	}

	// ���������� �������� � Y
	private: System::Void btnAddY_Click(System::Object^  sender, System::EventArgs^  e) {
		InfoClean();

		int numY;
		bool CheckY = Int32::TryParse(this->txtAddY->Text, numY);
		if (!CheckY) {
			errorProviderY->SetError(txtAddY, "������ ������ - �� �����");
		}
		else {
			setY.Add(numY);
			FillTxtY();
		}
		txtAddY->Text = "";
	}

	// �������� ������� ��������� �������� � X
	private: System::Void btnRemoveX_Click(System::Object^  sender, System::EventArgs^  e) {
		InfoClean();
		int value;
		bool Check = Int32::TryParse(this->txtRemoveX->Text, value);
		if (!Check) {
			errorProviderX->SetError(btnRemoveX, "������� �� �����");
		}
		else {
			if (!setX.Remove(value))
				errorProviderX->SetError(btnRemoveX, "������ �������� � ��������� X ���");
			FillTxtX();
		}
		txtRemoveX->Text = "";
	}

	// �������� ������� ��������� �������� � Y
	private: System::Void btnRemoveY_Click(System::Object^  sender, System::EventArgs^  e) {
		InfoClean();

		int value;
		bool Check = Int32::TryParse(this->txtRemoveY->Text, value);
		if (!Check) {
			errorProviderY->SetError(txtRemoveY, "������� �� �����");
		}
		else {
			if (!setY.Remove(value))
				errorProviderY->SetError(txtRemoveY, "������ �������� � ��������� Y ���");
			FillTxtY();
		}
		txtRemoveY->Text = "";
	}

	// ����������� ��������
	private: System::Void btnIntersect_Click(System::Object^  sender, System::EventArgs^  e) {
		txtChanged->Text = ""; txtIsEven->Text = "";
		errorProviderFunc->Clear(); setChanged.Clear();

		if (setX.Count == 0 || setY.Count == 0) {
			errorProviderFunc->SetError(btnIntersect, "���� �� �������� ������, ���������� ��������� ��������");
			return;
		}
		// �������� ��������� ��������, ���������� ������ �����������
		int setYlength = setY.Count;
		array<int>^tempY = gcnew array<int>(setYlength);
		setY.CopyTo(tempY);

		int setXlength = setX.Count;
		array<int>^tempX = gcnew array<int>(setXlength);
		setX.CopyTo(tempX);

		for (int i = 0; i < tempX->Length; i++) {
			setChanged.Add(tempX[i]);	// ��������� ����� ��� ��� ������ ���� X
		}
		
		setChanged.IntersectWith(tempY);	// ���� ����������� c Y
		
		FillTxtChanged();
	}

	// ����������� ��������
	private: System::Void btnUnite_Click(System::Object^  sender, System::EventArgs^  e) {
		txtChanged->Text = ""; txtIsEven->Text = "";
		errorProviderFunc->Clear(); setChanged.Clear();

		if (setX.Count == 0 || setY.Count == 0) {
			errorProviderFunc->SetError(btnUnite, "���� �� �������� ������, ���������� ��������� ��������");
			return;
		}
		// �������� ��������� ��������, ���������� ������ �����������
		int setYlength = setY.Count;
		array<int>^tempY = gcnew array<int>(setYlength);
		setY.CopyTo(tempY);

		int setXlength = setX.Count;
		array<int>^tempX = gcnew array<int>(setXlength);
		setX.CopyTo(tempX);

		for (int i = 0; i < tempX->Length; i++) {
			setChanged.Add(tempX[i]);	// ��������� ����� ��� ��� ����� ���� X
		}

		setChanged.UnionWith(tempY);	// ���� ����������� � Y

		FillTxtChanged();
	}

	// �������� ��������
	private: System::Void btnDifference_Click(System::Object^  sender, System::EventArgs^  e) {
		txtChanged->Text = ""; txtIsEven->Text = ""; 
		errorProviderFunc->Clear(); setChanged.Clear();

		if (setX.Count == 0 || setY.Count == 0) {
			errorProviderFunc->SetError(btnDifference, "���� �� �������� ������, ���������� ��������� ��������");
			return;
		}
		// �������� ��������� ��������, ���������� ������ �����������
		int setYlength = setY.Count;
		array<int>^tempY = gcnew array<int>(setYlength);
		setY.CopyTo(tempY);

		int setXlength = setX.Count;
		array<int>^tempX = gcnew array<int>(setXlength);
		setX.CopyTo(tempX);

		for (int i = 0; i < tempX->Length; i++) {
			setChanged.Add(tempX[i]); // ��������� ����� ��� ��� ����� ���� X
		}

		setChanged.SymmetricExceptWith(tempY);	// ������� ��������, ������� ��� � �����
		setChanged.ExceptWith(tempY);	// ������� ��������, ������� ���� � Y

		FillTxtChanged();
	}

	// ��������, �������� �� ���� ��������� ������������� �������
	private: System::Void btnCheckSub_Click(System::Object^  sender, System::EventArgs^  e) {
		txtCheckRes->Text = "";
		errorProviderFunc->Clear();

		if (setX.Count == 0 || setY.Count == 0) {
			errorProviderFunc->SetError(btnCheckSub, "���� �� �������� ������, ���������� ��������� ��������");
			return;
		}
		// �������� ���������� ���������, ����������� ������ ������������
		int setYlength = setY.Count;
		array<int>^tempY = gcnew array<int>(setYlength);
		setY.CopyTo(tempY);

		if (setX.IsSubsetOf(tempY)) {
			this->txtCheckRes->Text = "X ������������ Y";
		}
		else if (setX.IsSupersetOf(tempY)) {
			this->txtCheckRes->Text = "Y ������������ X";
		}
		else 
			this->txtCheckRes->Text = "����������� ���";
	}

	// �������� �� �������� ������ ���������			
	private: System::Void btnIsEven_Click(System::Object^  sender, System::EventArgs^  e) {
		txtIsEven->Text = "";
		errorProviderFunc->Clear();

		if (setChanged.Count == 0) {
			errorProviderFunc->SetError(btnIsEven, "���� �� �������� ������, ���������� ��������� ��������");
			return;
		}
		// �������� ������� - ����� ���� Y
		int setYlength = setY.Count;
		array<int>^tempY = gcnew array<int>(setYlength);
		setY.CopyTo(tempY);

		int maxnum = setChanged.Max;
		
		// ������ ������ ����� 
		array<int>^alleven = gcnew array<int>(maxnum / 2 + 1);
		for (int i = 0; i <= maxnum; i += 2) {
			alleven[i / 2] = i;
		}

		// ���� ��� ��� �������� ������������� ��������� ������ �����
		if (setChanged.IsSubsetOf(alleven))
			txtIsEven->Text = "��";
		else
			txtIsEven->Text = "���";
	}

	// �������� ���� ��������� �� X
	private: System::Void btnRemoveAllX_Click(System::Object^  sender, System::EventArgs^  e) {
		InfoClean();
		if (setX.Count == 0)
			errorProviderX->SetError(btnRemoveAllX, "��������� X ��� ������");
		txtSetX->Text = "";
		setX.Clear();
	}

	// �������� ���� ��������� �� Y
	private: System::Void btnRemoveAllY_Click(System::Object^  sender, System::EventArgs^  e) {
		InfoClean();
		if (setY.Count == 0)
			errorProviderY->SetError(btnRemoveAllY, "��������� Y ��� ������");
		txtSetY->Text = "";
		setY.Clear();
	}
};
}
