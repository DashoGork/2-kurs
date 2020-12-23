#pragma once
#include <stdlib.h>
#include<msclr/marshal_cppstd.h>
#include <string>
#include <ctime>
namespace LVB42 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
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
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ hintToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label6;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hintToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->label1->Location = System::Drawing::Point(12, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(360, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Word Jamble!";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Transparent;
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->newToolStripMenuItem,
					this->hintToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(384, 26);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(53, 22);
			this->newToolStripMenuItem->Text = L"New";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::newToolStripMenuItem_Click);
			// 
			// hintToolStripMenuItem
			// 
			this->hintToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->hintToolStripMenuItem->Name = L"hintToolStripMenuItem";
			this->hintToolStripMenuItem->Size = System::Drawing::Size(50, 22);
			this->hintToolStripMenuItem->Text = L"Hint";
			this->hintToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::hintToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(48, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->label2->Location = System::Drawing::Point(-3, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 23);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Word:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->label3->Location = System::Drawing::Point(-3, 118);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 23);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Guess:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->label4->Location = System::Drawing::Point(16, 215);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(356, 75);
			this->label4->TabIndex = 4;
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->label5->Location = System::Drawing::Point(86, 78);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 18);
			this->label5->TabIndex = 5;
			this->label5->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->ForeColor = System::Drawing::SystemColors::MenuText;
			this->richTextBox1->Location = System::Drawing::Point(89, 118);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(100, 23);
			this->richTextBox1->TabIndex = 6;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			this->richTextBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::richTextBox1_KeyPress);
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->label6->Location = System::Drawing::Point(16, 162);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(356, 42);
			this->label6->TabIndex = 7;
			this->label6->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(384, 299);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(400, 338);
			this->MinimumSize = System::Drawing::Size(400, 338);
			this->Name = L"MyForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"1";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//private:  array <String^,1>^  word =    gcnew array <String^>{"wall", "glasses","labored","persistent","jumble"};
		int i = 0;

private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

private: System::Void newToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	srand(static_cast<unsigned int>(time(0)));
	richTextBox1 -> Text = "";
	label6->Text = "";
	label4->Text = "";
	array <String^, 1>^ word = gcnew array <String^>{"wall", "glasses", "labored", "persistent", "jumble"};
	i = (rand() % 5);
	String^ n1 = word[i];
	std::string the_word = msclr::interop::marshal_as<std::string>(n1);
	std::string jumble = msclr::interop::marshal_as<std::string>(n1);
	int length = jumble.size();
	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}
	String^ n2 = gcnew String(jumble.c_str());
	label5->Text = n2;

}
private: System::Void hintToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	array <String^, 1>^ hint = gcnew array <String^>{"Do you feel you're banging your head against something?", "These might help you see the answer.", "Going slowly, is it?", "Keep at it.", "It's what the game is all about."};
	label6->Text = hint[i];
}

private: System::Void richTextBox1_KeyPress(System::Object^ sender,
		System::Windows::Forms::KeyPressEventArgs^ e) {
			if ((e->KeyChar >= 'a') && (e->KeyChar <= 'z'))
		// цифра
				return;
			e->Handled = true;
			if (Char::IsControl(e->KeyChar))
			{
				if (e->KeyChar == (char)Keys::Enter)
				{

					array <String^, 1>^ word = gcnew array <String^>{"wall", "glasses", "labored", "persistent", "jumble"};
					String^ n1 = word[i];
					std::string the_guess = msclr::interop::marshal_as<std::string>(richTextBox1->Text);
					std::string the_word = msclr::interop::marshal_as<std::string>(n1);
					//String^ n2 = gcnew String(the_guess.c_str());
					if (strcmp(the_guess.c_str(), the_word.c_str()) == 1) {
						richTextBox1->Text = "";
						label4->Text = "\nThat's it!  You guessed it!\n";

					}
					else if (strcmp(the_guess.c_str(), the_word.c_str()) != 0) {
						richTextBox1->Text = "";
						label4->Text = "Wrong!";
						richTextBox1->Focus();
					}

				}


			}
		
	}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
