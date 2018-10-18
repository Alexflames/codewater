#pragma once

namespace Graphics1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	float lines[] = {
		// ������
		0.5f,3.f,1.f,4.5f, // �� ����� ���� ����� �� ���
		1.f,4.5f,0.5f,6.f, // ����� ��� ����� ����� �����
		0.5f,6.f,0.5f, 7.5f, // ����� ��� �����
		0.5f, 7.5f,1.f,8.f, // ����� ��� ���� �����
		1.f,8.f,1.5f,8.f, // ����� ��� ���� ��������
		1.5f,8.f,2.f,7.5f, // ����� ��� ���� ������
		2.f,7.5f,1.5f, 6.f, // ����� ��� ������ ������ ����
		1.5f, 6.f,1.5f,4.5f, // ����� ��� ������ �� �������
		1.5f,4.5f,3.f,4.5f, // �������
		3.f,4.5f,3.f,6.f, // ������ ��� ����� ����� �����
		3.f,6.f,2.5f,7.5f, // ������ ��� �����
		2.5f,7.5f,3.f,8.f, // ������ ��� ���� �����
		3.f,8.f,3.5f,8.f, // ������ ��� ���� ��������
		3.5f,8.f,4.f,7.5f, // ������ ��� ���� ������
		4.f,7.5f,4.f,6.f, // ������ ��� ������ ����
		4.f,6.f,3.5f,4.5f, // ������ ��� ������
		3.5f,4.5f,4.f,3.f, // �� ������� ��� ���� �� ����
		4.f,3.f,3.5f,1.5f, // ������ �����
		3.5f,1.5f,2.5f,1.f, // ���������� ������
		2.5f,1.f,2.f,1.f, // ���������� �����
		2.f,1.f,1.f,1.5f, // ���������� �����
		1.f,1.5f,0.5f,3.f, // ����� �����
		// ��������
		4.f,3.f,5.5f,3.5f, // ����� �� ������ ������
		5.5f,3.5f,7.f,3.5f, // ����� ����
		7.f,3.5f,7.5f,2.5f, // ����� ������ �� ������
		7.5f,2.5f,8.f,2.5f, // ����� ������
		8.f,2.5f,8.f,2.f, // ����� ������
		8.f,2.f,7.5f,2.f, // ����� ��� ������ ������
		7.5f,2.f,7.5f,0.5f, // ������ ���� ������ ������ ����
		7.5f,0.5f,6.5f,0.5f, // ������ ���� ���
		6.5f,0.5f,6.5f,1.f, // ������ ���� �����
		6.5f,1.f,6.f,1.f, // ����� ������ ���
		6.f,1.f,6.f,0.5f, // ����� ������ ���� ������
		6.f,0.5f,5.f,0.5f, // ����� ������ ���� ���
		5.f,0.5f,5.f,1.f, // ����� ������ ���� �����
		5.f,1.f,4.f,1.f, // ����� ������� � ��������� ������
		4.f,1.f,4.f,0.5f, // ������ �������� ���� ������
		4.f,0.5f,3.f,0.5f, // ������ �������� ���� ���
		3.f,0.5f,3.f,1.f, // ������ �������� ���� �����
		3.f,1.f,2.5f,1.f, // ����� �������� ���
		2.5f,1.f,2.5f,0.5f, // �������� ���� ������
		2.5f,0.5f,1.5f,0.5f, // �������� ���� ���
		1.5f,0.5f,1.5f,1.25f, // �������� ���� �����
		// ����� ����
		1.5f,3.5f,1.5f,3.f, // ����� ���� ����� ������ ����
		1.5f,3.f,2.f,3.f, // ����� ���� ���
		2.f, 3.f,2.f,3.5f, // ����� ���� ������
		2.f,3.5f,1.5f,3.5f, // ����� ���� ����
		// ������ ����
		2.5f,3.5f,2.5f,3.f, // ������ ���� �����
		2.5f,3.f,3.f, 3.f, // ������ ���� �����
		3.f,3.f,3.f,3.5f, // ������ ���� ������
		3.f,3.5f,2.5f,3.5f, // ������ ���� ������
		// ����� ��������
		1.f,5.5f,1.f,7.f, // ����� ����� ��������
		3.5f,5.5f,3.5f,7.f, // ������ ����� ��������
		// ���
		2.f,2.5f,2.5f,2.5f, // ��� ������
		2.5f,2.5f,2.25f,2.f, // ��� ������
		2.25f,2.f,2.f,2.5f // ��� �����
	};

	// ��� ����������� � ������ ������� � ����� �������
	// ����� ���� ��� ��� �� ����� ���� ������ ��� ������
	// ����������, ��� 3d �� ����������
	float linesSnail[] = {	// .f, .f, .f, .f,
#pragma region ������	
		1.5f, 0.5f, 0.5f, 1.5f, // �� ����� � ����� �����
		0.5f, 1.5f, 0.5f, 2.f,	// ����� �����
		0.5f, 2.f, 1.f, 3.f,	// �� ����� ����� �� ��� �����
		1.f, 3.f, 1.5f, 5.5f,   // �� ��� ����� �� ������ ��������
		1.5f, 5.5f, 1.f, 6.f,	// ����� ������ ����� ������ ��������
		1.f, 6.f, 1.5f, 7.f,	// ����� ������� ����� ������ ��������
		1.5f, 7.f, 2.f, 7.f,	// ������� ����� ������ ��������
		2.f, 7.f, 2.5f, 6.f,	// ������� ������ ����� ������ ��������
		2.5f, 6.f, 2.f, 5.5f,	// ������ ������ ����� ������ ��������
		2.f, 5.5f, 1.5f, 4.f,	// �� �������� ������ �� ���
		1.5f, 4.f, 2.f, 4.f,	// ���
		2.f, 4.f, 2.5f, 3.5f,	// ����� �� ���
		2.5f, 3.5f, 3.f, 5.5f,	// �� ��� ����� �� ������� ��������
		3.f, 5.5f, 2.5f, 6.f,	// ������ ����� ����� ������� ��������
		2.5f, 6.f, 3.f, 7.f,	// ������� ����� ����� ������� ��������
		3.f, 7.f, 3.5f, 7.f,	// ������� ����� ������� ��������
		3.5f, 7.f, 4.f, 6.f,	// ������� ������ ����� ������� ��������
		4.f, 6.f, 3.5f, 5.5f,	// ������ ������ ����� ������� ��������
		3.5f, 5.5f, 3.f, 3.f,	// �� ������� �������� ���� �� ���
		3.f, 3.f, 3.5f, 2.5f,	// ��� � ������� �������� �������
#pragma endregion
		
#pragma region ������ �����
		0.5f, 2.f, 1.f, 2.5f,	// ����� ����� ������ �����
		1.f, 2.5f, 1.5f, 2.f,	// ������ ����� ������ �����
		1.5f, 2.f, 0.5f, 2.f,	// ������ ����� ������ �����
		1.f, 2.5f, 0.75f, 2.f,  // ����� ����� ������ ������
		1.f, 2.5f, 1.25f, 2.f,  // ������ ����� ������ ������

		2.0f, 2.f, 2.5f, 2.5f,	// ����� ����� ������� �����
		2.5f, 2.5f, 3.0f, 2.f,	// ������ ����� ������� �����
		3.0f, 2.f, 2.0f, 2.f,	// ������ ����� ������� �����
		2.5f, 2.5f, 2.25f, 2.f,	// ����� ����� ������� ������
		2.5f, 2.5f, 2.75f, 2.f,	// ������ ����� ������� ������

		1.f, 1.5f, 2.5f, 1.5f,	// ���� ���������� ������
		2.5f, 1.5f, 2.f, 1.f,	// ������ ����� ���������� ������
		2.f, 1.f, 1.5f, 1.f,	// ��� ���������� ������
		1.5f, 1.f, 1.f, 1.5f,	// ����� ����� ��������� ������
		0.9f, 1.4f, 1.1f, 1.6f, // ����� ������
		2.4f, 1.6f, 2.6f, 1.4f, // ������ ������
#pragma endregion

#pragma region �������� (�����, �������� �������)
		3.5f, 2.5f, 4.f, 3.f,	// ���� � ������ �������
		4.f, 3.f, 7.f, 1.5f,	// ���� ����� � ������
		7.f, 1.5f, 9.f, 2.5f,	// ���� ������ �����

#pragma endregion
		 
#pragma region ��������

#pragma endregion
		
#pragma region ������� - 1 (�����������)

#pragma endregion 
		
#pragma region ������� - 2

#pragma endregion

#pragma region ������� - 3 (�������)

#pragma endregion
		
#pragma region ������� �������

#pragma endregion
	};

	unsigned int arrayLength = sizeof(lines) / sizeof(float);
	unsigned int arraySnailLength = sizeof(linesSnail) / sizeof(float);

	float Vx = 8.5f;			// ������ ������� �� �����������
	float Vy = 8.5f;			// ������ ������� �� ���������
	float snailVx = 15.f;		// ������ ������ �� �����������
	float snailVy = 8.5;		// ������ ������ �� ���������
	float aspectFig = Vx / Vy;  // ����������� ������ �������
	float snailAspectFig = snailVx / snailVy;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(436, 449);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: bool keepAspectRatio; // ��������� ����������� ������?
	private: bool isStandardPainting; // ����������� ��� ���� �������?

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		keepAspectRatio = true;
		isStandardPainting = true;
	}

	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine);

		Pen^ blackPen = gcnew Pen(Color::Black, 2);
		
		float Wx = ClientRectangle.Width;   // ������ ���� �� �����������
		float Wy = ClientRectangle.Height;  // ������ ���� �� ���������
		float aspectForm = Wx / Wy;			// ����������� ������ ���� ���������

		float Sx, Sy;
		float Ty;	  // �������� � ������������� ������� �� ��� Oy ����� ����� �����
		if (keepAspectRatio) {
			// �����������s ���������� ��� ���������� ��������� ����������� ������
			if (isStandardPainting) {
				Sx = Sy = aspectFig < aspectForm ? Wy / Vy : Wx / Vx;
				Ty = Sy * Vy;
			}
			else {
				Sx = Sy = snailAspectFig < aspectForm ? Wy / Vy : Wx / Vx;
				Ty = Sy * snailVy;
			}
		}
		else {
			if (isStandardPainting) {
				Sx = Wx / Vx; // ����������� ���������� �� ��� Ox
				Sy = Wy / Vy; // ����������� ���������� �� ��� Oy
				Ty = Sy * Vy;
			}
			else {
				Sx = Wx / snailVx;
				Sy = Wy / snailVy;
				Ty = Sy * snailVy; 
			}
		}

		if (isStandardPainting) {
			for (int i = 0; i < arrayLength; i += 4) {
				g->DrawLine(blackPen, Sx * lines[i], Ty - Sy * lines[i + 1],
					Sx * lines[i + 2], Ty - Sy * lines[i + 3]);
			}
		}
		else {
			for (int i = 0; i < arraySnailLength; i += 4) {
				g->DrawLine(blackPen, Sx * linesSnail[i], Ty - Sy * linesSnail[i + 1],
					Sx * linesSnail[i + 2], Ty - Sy * linesSnail[i + 3]);
			}
		}
	}
	private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e) {
		Refresh();
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode) {
		case Keys::M :
			keepAspectRatio = !keepAspectRatio;
			break;
		case Keys::N :
			isStandardPainting = !isStandardPainting;
			break;
		default:
			break;
		}
		Refresh();
	}
	};
}
