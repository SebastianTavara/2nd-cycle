#pragma once

#include "MyForm1.h"
#include "MyForm2.h"

namespace GAMEJAM2024II {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Button^ btnGenCarros;
	protected:

	private: System::Windows::Forms::Label^ lblMenu;
    private: System::Windows::Forms::Button^ button1;




	private:
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
			this->btnGenCarros = (gcnew System::Windows::Forms::Button());
			this->lblMenu = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnGenCarros
			// 
			this->btnGenCarros->Location = System::Drawing::Point(460, 149);
			this->btnGenCarros->Name = L"btnGenCarros";
			this->btnGenCarros->Size = System::Drawing::Size(235, 104);
			this->btnGenCarros->TabIndex = 2;
			this->btnGenCarros->Text = L"Generacion Automatica de Carros";
			this->btnGenCarros->UseVisualStyleBackColor = true;
			this->btnGenCarros->Click += gcnew System::EventHandler(this, &MyForm::btnGenCarros_Click);
			// 
			// lblMenu
			// 
			this->lblMenu->AutoSize = true;
			this->lblMenu->Location = System::Drawing::Point(349, 73);
			this->lblMenu->Name = L"lblMenu";
			this->lblMenu->Size = System::Drawing::Size(47, 16);
			this->lblMenu->TabIndex = 3;
			this->lblMenu->Text = L"MENU";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(71, 146);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(251, 107);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Carrera";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(770, 394);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->lblMenu);
			this->Controls->Add(this->btnGenCarros);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
private: System::Void btnGenCarros_Click(System::Object^ sender, System::EventArgs^ e) {
    MyForm2^ rebote = gcnew MyForm2();
    rebote->Show();
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
    MyForm1^ carrera = gcnew MyForm1();
    carrera->Show();
}
};
}
