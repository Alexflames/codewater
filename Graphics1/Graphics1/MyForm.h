#pragma once

namespace Graphics1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	float lines[] = {
		// голова
		0.5f,3.f,1.f,4.5f, // от левой щеки вверх до уха
		1.f,4.5f,0.5f,6.f, // левое ухо слева снизу вверх
		0.5f,6.f,0.5f, 7.5f, // левое ухо слева
		0.5f, 7.5f,1.f,8.f, // левое ухо верх слева
		1.f,8.f,1.5f,8.f, // левое ухо верх середина
		1.5f,8.f,2.f,7.5f, // левое ухо верх справа
		2.f,7.5f,1.5f, 6.f, // левое ухо справа сверху вниз
		1.5f, 6.f,1.5f,4.5f, // левое ухо справа до макушки
		1.5f,4.5f,3.f,4.5f, // макушка
		3.f,4.5f,3.f,6.f, // правое ухо слева снизу вверх
		3.f,6.f,2.5f,7.5f, // правое ухо слева
		2.5f,7.5f,3.f,8.f, // правое ухо верх слева
		3.f,8.f,3.5f,8.f, // правое ухо верх середина
		3.5f,8.f,4.f,7.5f, // правое ухо верх справа
		4.f,7.5f,4.f,6.f, // правое ухо сверху вниз
		4.f,6.f,3.5f,4.5f, // правое ухо справа
		3.5f,4.5f,4.f,3.f, // от правого уха вниз до щеки
		4.f,3.f,3.5f,1.5f, // правая скула
		3.5f,1.5f,2.5f,1.f, // подбородок справа
		2.5f,1.f,2.f,1.f, // подбородок снизу
		2.f,1.f,1.f,1.5f, // подбородок слева
		1.f,1.5f,0.5f,3.f, // левая скула
		// туловище
		4.f,3.f,5.5f,3.5f, // спина от головы вправо
		5.5f,3.5f,7.f,3.5f, // спина верх
		7.f,3.5f,7.5f,2.5f, // спина сверху до хвоста
		7.5f,2.5f,8.f,2.5f, // хвост сверху
		8.f,2.5f,8.f,2.f, // хвост справа
		8.f,2.f,7.5f,2.f, // хвост низ справа налево
		7.5f,2.f,7.5f,0.5f, // задняя нога справа сверху вниз
		7.5f,0.5f,6.5f,0.5f, // задняя нога низ
		6.5f,0.5f,6.5f,1.f, // задняя нога слева
		6.5f,1.f,6.f,1.f, // между задних ног
		6.f,1.f,6.f,0.5f, // левая задняя нога справа
		6.f,0.5f,5.f,0.5f, // левая задняя нога низ
		5.f,0.5f,5.f,1.f, // левая задняя нога слева
		5.f,1.f,4.f,1.f, // между задними и передними ногами
		4.f,1.f,4.f,0.5f, // правая передняя нога справа
		4.f,0.5f,3.f,0.5f, // правая передняя нога низ
		3.f,0.5f,3.f,1.f, // правая передняя нога слева
		3.f,1.f,2.5f,1.f, // между передних ног
		2.5f,1.f,2.5f,0.5f, // передняя нога справа
		2.5f,0.5f,1.5f,0.5f, // передняя нога низ
		1.5f,0.5f,1.5f,1.25f, // передняя нога слева
		// левый глаз
		1.5f,3.5f,1.5f,3.f, // левый глаз слева сверху вниз
		1.5f,3.f,2.f,3.f, // левый глаз низ
		2.f, 3.f,2.f,3.5f, // левый глаз справа
		2.f,3.5f,1.5f,3.5f, // левый глаз верх
		// правый глаз
		2.5f,3.5f,2.5f,3.f, // правый глаз слева
		2.5f,3.f,3.f, 3.f, // правый глаз снизу
		3.f,3.f,3.f,3.5f, // правый глаз справа
		3.f,3.5f,2.5f,3.5f, // правый глаз сверху
		// ушные раковины
		1.f,5.5f,1.f,7.f, // левая ушная раковина
		3.5f,5.5f,3.5f,7.f, // правая ушная раковина
		// нос
		2.f,2.5f,2.5f,2.5f, // нос сверху
		2.5f,2.5f,2.25f,2.f, // нос справа
		2.25f,2.f,2.f,2.5f // нос слева
	};

	// Все направления у улитки указаны с нашей стороны
	// левый глаз для нас на самом деле правый для улитки
	// Представим, что 3d не существует
	float linesSnail[] = {	// .f, .f, .f, .f,
#pragma region голова	
		1.5f, 0.5f, 0.5f, 1.5f, // от земли к левой щёчке
		0.5f, 1.5f, 0.5f, 2.f,	// левая щёчка
		0.5f, 2.f, 1.f, 3.f,	// от левой щёчки ко лбу слева
		1.f, 3.f, 1.5f, 5.5f,   // от лба слева до левого отростка
		1.5f, 5.5f, 1.f, 6.f,	// левая нижняя часть левого отростка
		1.f, 6.f, 1.5f, 7.f,	// левая верхняя часть левого отростка
		1.5f, 7.f, 2.f, 7.f,	// верхняя часть левого отростка
		2.f, 7.f, 2.5f, 6.f,	// верхняя правая часть левого отростка
		2.5f, 6.f, 2.f, 5.5f,	// нижняя правая часть левого отростка
		2.f, 5.5f, 1.5f, 4.f,	// от отростка справа до лба
		1.5f, 4.f, 2.f, 4.f,	// лоб
		2.f, 4.f, 2.5f, 3.5f,	// изгиб на лбу
		2.5f, 3.5f, 3.f, 5.5f,	// от лба слева до правого отростка
		3.f, 5.5f, 2.5f, 6.f,	// нижняя левая часть правого отростка
		2.5f, 6.f, 3.f, 7.f,	// верхняя левая часть правого отростка
		3.f, 7.f, 3.5f, 7.f,	// верхняя часть правого отростка
		3.5f, 7.f, 4.f, 6.f,	// верхняя правая часть правого отростка
		4.f, 6.f, 3.5f, 5.5f,	// нижняя правая часть правого отростка
		3.5f, 5.5f, 3.f, 3.f,	// от правого отростка вниз ко лбу
		3.f, 3.f, 3.5f, 2.5f,	// шея у правого отростка направо
#pragma endregion
		
#pragma region хитрая морда
		0.5f, 2.f, 1.f, 2.5f,	// левая часть левого глаза
		1.f, 2.5f, 1.5f, 2.f,	// правая часть левого глаза
		1.5f, 2.f, 0.5f, 2.f,	// нижняя часть левого глаза
		1.f, 2.5f, 0.75f, 2.f,  // левая часть левого зрачка
		1.f, 2.5f, 1.25f, 2.f,  // правая часть левого зрачка

		2.0f, 2.f, 2.5f, 2.5f,	// левая часть правого глаза
		2.5f, 2.5f, 3.0f, 2.f,	// правая часть правого глаза
		3.0f, 2.f, 2.0f, 2.f,	// нижняя часть правого глаза
		2.5f, 2.5f, 2.25f, 2.f,	// левая часть правого зрачка
		2.5f, 2.5f, 2.75f, 2.f,	// правая часть правого зрачка

		1.f, 1.5f, 2.5f, 1.5f,	// верх прекрасной улыбки
		2.5f, 1.5f, 2.f, 1.f,	// правая часть прекрасной улыбки
		2.f, 1.f, 1.5f, 1.f,	// низ прекрасной улыбки
		1.5f, 1.f, 1.f, 1.5f,	// левая часть прекрсной улыбки
		0.9f, 1.4f, 1.1f, 1.6f, // левая ямочка
		2.4f, 1.6f, 2.6f, 1.4f, // правая ямочка
#pragma endregion

#pragma region туловище (нечто, держащее ракушку)
		3.5f, 2.5f, 4.f, 3.f,	// тело у начала панциря
		4.f, 3.f, 7.f, 1.5f,	// тело слева к центру
		7.f, 1.5f, 9.f, 2.5f,	// тело справа внизу

#pragma endregion
		 
#pragma region раковина

#pragma endregion
		
#pragma region спираль - 1 (центральная)

#pragma endregion 
		
#pragma region спираль - 2

#pragma endregion

#pragma region спираль - 3 (остатки)

#pragma endregion
		
#pragma region внешние границы

#pragma endregion
	};

	unsigned int arrayLength = sizeof(lines) / sizeof(float);
	unsigned int arraySnailLength = sizeof(linesSnail) / sizeof(float);

	float Vx = 8.5f;			// размер рисунка по горизонтали
	float Vy = 8.5f;			// размер рисунка по вертикали
	float snailVx = 15.f;		// размер улитки по горизонтали
	float snailVy = 8.5;		// размер улитки по вертикали
	float aspectFig = Vx / Vy;  // соотношение сторон рисунка
	float snailAspectFig = snailVx / snailVy;

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

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
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
	private: bool keepAspectRatio; // сохранять соотношение сторон?
	private: bool isStandardPainting; // стандартный или свой рисунок?

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		keepAspectRatio = true;
		isStandardPainting = true;
	}

	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine);

		Pen^ blackPen = gcnew Pen(Color::Black, 2);
		
		float Wx = ClientRectangle.Width;   // размер окна по горизонтали
		float Wy = ClientRectangle.Height;  // размер окна по вертикали
		float aspectForm = Wx / Wy;			// соотношение сторон окна рисования

		float Sx, Sy;
		float Ty;	  // смещение в положительную сторону по оси Oy после смены знака
		if (keepAspectRatio) {
			// коэффициентs увеличения при сохранении исходного соотношения сторон
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
				Sx = Wx / Vx; // коэффициент увеличения по оси Ox
				Sy = Wy / Vy; // коэффициент увеличения по оси Oy
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
