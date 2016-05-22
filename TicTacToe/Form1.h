#pragma once
#include "gameField.h"

namespace TicTacToe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button2;

	private:
		gameField game;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

			 /// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(187, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(109, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Generate Field";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Enabled = false;
			this->numericUpDown1->Location = System::Drawing::Point(88, 15);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->ReadOnly = true;
			this->numericUpDown1->Size = System::Drawing::Size(73, 20);
			this->numericUpDown1->TabIndex = 1;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(15, 45);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(105, 17);
			this->checkBox1->TabIndex = 2;
			this->checkBox1->Text = L"Computer begins";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Size of Field: ";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(187, 41);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(109, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Start";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(313, 17);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(39, 36);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(375, 262);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
		{
			int a = (int)numericUpDown1->Value;
			game.init(a, a);
			for (int y = 0; y < a; y++)
				for (int x = 0; x < a; x++)
				{
					System::Windows::Forms::PictureBox^  pic;
					pic = gcnew System::Windows::Forms::PictureBox();
					pic->BackColor = System::Drawing::Color::White;
					pic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
					pic->Location = System::Drawing::Point(15 + 60 * x, 80 + 60 * y);
					pic->Name = L"";
					pic->Size = System::Drawing::Size(50, 50);
					pic->TabIndex = 500 + 10*x + y;
					pic->TabStop = false;
					pic->Click += gcnew System::EventHandler(this, &Form1::pic_Click);
					this->Controls->Add(pic);
					
				}
		}
			 void tabIndexToXY(int tabIndex, int *x, int *y)
			 {
				 if (tabIndex < 500)
				 {
					 *x = -1;
					 *y = -1;
				 }
				 else
				 {
					 *x = (tabIndex - 500) / 10;
					 *y = (tabIndex - 500) % 10;
				 }
			 }
	private: System::Void pic_Click(System::Object^  sender, System::EventArgs^  e)
		{
			System::Windows::Forms::PictureBox^  pic = (System::Windows::Forms::PictureBox^)sender;
			int x;
			int y;
			tabIndexToXY(pic->TabIndex, &x, &y);

			cellValue_t res = game.setCellAs(x, y, cv_X);
			switch (res)
			{
			case cv_X:
			case cv_O:
				game.doNextStep(x, y);
				break;
			case cv_none:
			case cv_err:
				break;
			}

			// redraw all cells
			this->Controls->Count;
			for each(Control ^pC in this->Controls)
			{
				if (pC->GetType() == System::Windows::Forms::PictureBox::typeid)
				{
					//System::Windows::Forms::PictureBox ^pic = (System::Windows::Forms::PictureBox) pC;
					int x;
					int y;
					tabIndexToXY(pC->TabIndex, &x, &y);
					if (0 <= x && 0 <= y)
					{
						System::Drawing::Color color = System::Drawing::Color::DarkGray;
						cellValue_t cv = game.getValueFrom(x, y);
						switch (cv)
						{
						case cv_X:
							color = System::Drawing::Color::Red;
							break;
						case cv_O:
							color = System::Drawing::Color::Blue;
							break;
						case cv_none:
							color = System::Drawing::Color::White;
							break;
						}
						pC->BackColor = color;
					}
				}
			}
		}
};
}

