#pragma once
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include <string>
#include <set>
#using <System.dll>
#include "funciones.h"
#include "Controlador.h"
#include "helpers.h"

using namespace System::Runtime::InteropServices;
using namespace System;
using namespace std;
using namespace Funciones;
namespace UPCalcula {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		
		MyForm(void)
		{
			InitializeComponent();
			
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
	
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ inicio;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ upch;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ RandomA;
	private: System::Windows::Forms::Button^ UPCalcular;
	private: System::Windows::Forms::Panel^ panel1;




	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Conjunto* relacion=new Conjunto();
		System::Collections::Generic::List<Control^>^ controlList = gcnew System::Collections::Generic::List<Control^>();

	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Button^ clasifica;
		   int cont;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->inicio = (gcnew System::Windows::Forms::Button());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->upch = (gcnew System::Windows::Forms::Label());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->RandomA = (gcnew System::Windows::Forms::Button());
			   this->UPCalcular = (gcnew System::Windows::Forms::Button());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->clasifica = (gcnew System::Windows::Forms::Button());
			   this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // inicio
			   // 
			   this->inicio->BackColor = System::Drawing::Color::Red;
			   this->inicio->Font = (gcnew System::Drawing::Font(L"Impact", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->inicio->ForeColor = System::Drawing::Color::White;
			   this->inicio->Location = System::Drawing::Point(370, 347);
			   this->inicio->Name = L"inicio";
			   this->inicio->Size = System::Drawing::Size(173, 59);
			   this->inicio->TabIndex = 1;
			   this->inicio->Text = L"Inicio";
			   this->inicio->UseVisualStyleBackColor = false;
			   this->inicio->Click += gcnew System::EventHandler(this, &MyForm::inicio_Click);
			   // 
			   // textBox1
			   // 
			   this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox1->Location = System::Drawing::Point(193, 183);
			   this->textBox1->Multiline = true;
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(45, 45);
			   this->textBox1->TabIndex = 2;
			   this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			   this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			   this->textBox1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox1_KeyUp);
			   // 
			   // textBox2
			   // 
			   this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox2->Location = System::Drawing::Point(281, 183);
			   this->textBox2->Multiline = true;
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(45, 45);
			   this->textBox2->TabIndex = 3;
			   this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox2_KeyPress);
			   this->textBox2->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox2_KeyUp);
			   // 
			   // textBox3
			   // 
			   this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox3->Location = System::Drawing::Point(370, 183);
			   this->textBox3->Multiline = true;
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->Size = System::Drawing::Size(45, 45);
			   this->textBox3->TabIndex = 4;
			   this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox3_KeyPress);
			   this->textBox3->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox3_KeyUp);
			   // 
			   // textBox4
			   // 
			   this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox4->Location = System::Drawing::Point(631, 183);
			   this->textBox4->Multiline = true;
			   this->textBox4->Name = L"textBox4";
			   this->textBox4->Size = System::Drawing::Size(45, 45);
			   this->textBox4->TabIndex = 7;
			   this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			   this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox4_KeyPress);
			   // 
			   // textBox5
			   // 
			   this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox5->Location = System::Drawing::Point(542, 183);
			   this->textBox5->Multiline = true;
			   this->textBox5->Name = L"textBox5";
			   this->textBox5->Size = System::Drawing::Size(45, 45);
			   this->textBox5->TabIndex = 6;
			   this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			   this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox5_KeyPress);
			   // 
			   // textBox6
			   // 
			   this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox6->Location = System::Drawing::Point(454, 183);
			   this->textBox6->Multiline = true;
			   this->textBox6->Name = L"textBox6";
			   this->textBox6->Size = System::Drawing::Size(45, 45);
			   this->textBox6->TabIndex = 5;
			   this->textBox6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox6_KeyPress);
			   this->textBox6->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox6_KeyUp);
			   // 
			   // textBox7
			   // 
			   this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox7->Location = System::Drawing::Point(721, 183);
			   this->textBox7->Multiline = true;
			   this->textBox7->Name = L"textBox7";
			   this->textBox7->Size = System::Drawing::Size(45, 45);
			   this->textBox7->TabIndex = 8;
			   this->textBox7->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox7_KeyPress);
			   this->textBox7->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox7_KeyUp);
			   // 
			   // timer1
			   // 
			   this->timer1->Interval = 50;
			   this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			   // 
			   // upch
			   // 
			   this->upch->AutoSize = true;
			   this->upch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->upch->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->upch->Location = System::Drawing::Point(-4, 0);
			   this->upch->Name = L"upch";
			   this->upch->Size = System::Drawing::Size(105, 20);
			   this->upch->TabIndex = 9;
			   this->upch->Text = L"UPCALCULA";
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox1->Location = System::Drawing::Point(134, 124);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(667, 203);
			   this->pictureBox1->TabIndex = 10;
			   this->pictureBox1->TabStop = false;
			   // 
			   // RandomA
			   // 
			   this->RandomA->BackColor = System::Drawing::Color::Red;
			   this->RandomA->Font = (gcnew System::Drawing::Font(L"Impact", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->RandomA->ForeColor = System::Drawing::Color::White;
			   this->RandomA->Location = System::Drawing::Point(526, 347);
			   this->RandomA->Name = L"RandomA";
			   this->RandomA->Size = System::Drawing::Size(150, 59);
			   this->RandomA->TabIndex = 11;
			   this->RandomA->Text = L"Random";
			   this->RandomA->UseVisualStyleBackColor = false;
			   this->RandomA->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			   // 
			   // UPCalcular
			   // 
			   this->UPCalcular->BackColor = System::Drawing::Color::Red;
			   this->UPCalcular->Font = (gcnew System::Drawing::Font(L"Impact", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->UPCalcular->ForeColor = System::Drawing::Color::White;
			   this->UPCalcular->Location = System::Drawing::Point(198, 347);
			   this->UPCalcular->Name = L"UPCalcular";
			   this->UPCalcular->Size = System::Drawing::Size(166, 59);
			   this->UPCalcular->TabIndex = 12;
			   this->UPCalcular->Text = L"UPCalcular";
			   this->UPCalcular->UseVisualStyleBackColor = false;
			   this->UPCalcular->Click += gcnew System::EventHandler(this, &MyForm::UPCalcular_Click);
			   // 
			   // panel1
			   // 
			   this->panel1->BackColor = System::Drawing::Color::Transparent;
			   this->panel1->Controls->Add(this->clasifica);
			   this->panel1->Controls->Add(this->UPCalcular);
			   this->panel1->Controls->Add(this->RandomA);
			   this->panel1->Controls->Add(this->pictureBox1);
			   this->panel1->Controls->Add(this->upch);
			   this->panel1->Controls->Add(this->textBox7);
			   this->panel1->Controls->Add(this->textBox4);
			   this->panel1->Controls->Add(this->textBox5);
			   this->panel1->Controls->Add(this->textBox6);
			   this->panel1->Controls->Add(this->textBox3);
			   this->panel1->Controls->Add(this->textBox2);
			   this->panel1->Controls->Add(this->textBox1);
			   this->panel1->Controls->Add(this->inicio);
			   this->panel1->Location = System::Drawing::Point(3, 5);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(968, 532);
			   this->panel1->TabIndex = 13;
			   this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			   // 
			   // clasifica
			   // 
			   this->clasifica->BackColor = System::Drawing::Color::Red;
			   this->clasifica->Font = (gcnew System::Drawing::Font(L"Impact", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->clasifica->ForeColor = System::Drawing::Color::White;
			   this->clasifica->Location = System::Drawing::Point(350, 460);
			   this->clasifica->Name = L"clasifica";
			   this->clasifica->Size = System::Drawing::Size(205, 59);
			   this->clasifica->TabIndex = 13;
			   this->clasifica->Text = L"CLASIFICAR";
			   this->clasifica->UseVisualStyleBackColor = false;
			   this->clasifica->Visible = false;
			   this->clasifica->Click += gcnew System::EventHandler(this, &MyForm::clasifica_Click);
			   // 
			   // timer2
			   // 
			   this->timer2->Enabled = true;
			   this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(973, 549);
			   this->Controls->Add(this->panel1);
			   this->Name = L"MyForm";
			   this->Text = L"MyForm";
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		controlList->Add(textBox1);
		controlList->Add(textBox2);
		controlList->Add(textBox3);
		controlList->Add(textBox4);
		controlList->Add(textBox5);
		controlList->Add(textBox6);
		controlList->Add(textBox7);
		UPCalcular->Visible = false;
		for each (auto txt in controlList)//recorre cada elemento
		{
			txt->Visible = false;
		}
		upch->Visible = false;
		RandomA->Visible = false;
		System::Drawing::Bitmap^ image = gcnew System::Drawing::Bitmap("imagen/upcalcula.png");
		pictureBox1->Image = image;

	}
	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {	}
	private: System::Void UPCalcula_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void inicio_Click(System::Object^ sender, System::EventArgs^ e) {
		inicio->Visible = false;
		textBox1->Visible = true;
		upch->Visible = true;
		pictureBox1->Visible = false;
		RandomA->Visible = true;

	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if ((textBox1->Text != textBox1->Text->Empty)) {//si tienne contenido entonces muestra la siguiente casilla
			textBox2->Visible = true; textBox2->Focus();
		}
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void textBox2_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if ((textBox2->Text != textBox2->Text->Empty)) {
			textBox3->Visible = true; textBox3->Focus();
		}
	}
	private: System::Void textBox3_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if ((textBox3->Text != textBox3->Text->Empty)) {
			textBox6->Visible = true; textBox6->Focus();
		}
	}
	private: System::Void textBox6_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if ((textBox6->Text != textBox6->Text->Empty)) {
			textBox5->Visible = true; textBox5->Focus(); UPCalcular->Visible = true;
		}
	}
	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if ((textBox5->Text != textBox5->Text->Empty)) {
			textBox4->Visible = true; textBox4->Focus();
		}
	}
	private: System::Void textBox7_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if ((textBox4->Text != textBox4->Text->Empty)) {
			textBox7->Visible = true; textBox7->Focus();
		}
	}
	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsLetterOrDigit(e->KeyChar)) { e->Handled = true; }
		if (textBox1->Text->Length >= 1 && e->KeyChar != 8) { e->Handled = true; }
		if (textBox1->Text->Length == 1 && e->KeyChar == 8) { textBox1->Clear(); }
	}
	private: System::Void textBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsLetterOrDigit(e->KeyChar)) { e->Handled = true; }
		if (textBox2->Text->Length >= 1 && e->KeyChar != 8) { e->Handled = true; }
		if (textBox2->Text->Length == 1 && e->KeyChar == 8) { textBox2->Clear(); }
	}
	private: System::Void textBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsLetterOrDigit(e->KeyChar)) { e->Handled = true; }
		if (textBox3->Text->Length >= 1 && e->KeyChar != 8) { e->Handled = true; }
		if (textBox3->Text->Length == 1 && e->KeyChar == 8) { textBox3->Clear(); }
	}
	private: System::Void textBox6_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsLetterOrDigit(e->KeyChar)) { e->Handled = true; }
		if (textBox6->Text->Length >= 1 && e->KeyChar != 8) { e->Handled = true; }
		if (textBox6->Text->Length == 1 && e->KeyChar == 8) { textBox6->Clear(); }
	}
	private: System::Void textBox5_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsLetterOrDigit(e->KeyChar)) { e->Handled = true; }
		if (textBox5->Text->Length >= 1 && e->KeyChar != 8) { e->Handled = true; }
		if (textBox5->Text->Length == 1 && e->KeyChar == 8) { textBox5->Clear(); }
	}

	private: System::Void textBox4_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsLetterOrDigit(e->KeyChar)) { e->Handled = true; }
		if (textBox4->Text->Length >= 1 && e->KeyChar != 8) { e->Handled = true; }
		if (textBox4->Text->Length == 1 && e->KeyChar == 8) { textBox4->Clear(); }
	}

	private: System::Void textBox7_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsLetterOrDigit(e->KeyChar)) { e->Handled = true; }
		if (textBox7->Text->Length >= 1 && e->KeyChar != 8) { e->Handled = true; }
		if (textBox7->Text->Length == 1 && e->KeyChar == 8) { textBox7->Clear(); }
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		set<int> Numerosusads;
		set<char> Charsusados;

		for each (auto txt in controlList)
		{
			txt->Visible = true;
			int x = RandomN(2, 1);
			if (x == 2)
			{
				int randomNumber;
				do {
					randomNumber = RandomN(9, 1);
				} while (Numerosusads.count(randomNumber) > 0);//si el valor de retorno de count es mayor a 0 significa que el numero ya ha sido usado y se genera dnvo
				Numerosusads.insert(randomNumber);//inserta el numero para luego comprobar si esta repetido
				txt->Text = gcnew String(to_string(randomNumber).c_str());//imprime en char la textbox
			}
			else
			{
				char randomchar;
				do {
					randomchar = RandomC();
				} while (Charsusados.count(randomchar) > 0);

				Charsusados.insert(randomchar);
				txt->Text = gcnew String(randomchar, 1);
			}
		}

		UPCalcular->Visible = true;
	}

	private: System::Void UPCalcular_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ a = textBox1->Text->ToString() + textBox2->Text->ToString() + textBox3->Text->ToString() + textBox6->Text->ToString()
			+ textBox5->Text->ToString() + textBox4->Text->ToString() + textBox7->Text->ToString();
		string convierteString = msclr::interop::marshal_as<string>(a);
		set<char> no_repetido;
		vector<vector<string>> elementos;
		for (auto elemento : convierteString) {
			string s(1, elemento);
			no_repetido.insert(elemento);
			elementos.push_back({ s });
		}
		//validar si hay valores repetidos
		if (no_repetido.size() != convierteString.size())
		{
			Beep(440, 200);
			MessageBox::Show("Haz ingresado elementos repetidos!, por favor revise el conjunto");
			return;
		}
		UPCalcular->Visible = false;
		inicio->Visible = false;
		for each (auto txt in controlList)//recorre cada elemento
		{
			txt->Visible = false;
		}
		RandomA->Visible = false;

		auto resultado = Funciones::calcularProdCartesiano(elementos);

		int x = 260; int y = 50;  int i = 0; int dx = 60;
		if (convierteString.size() <= 5)
		{
			x = 280;
			dx = 80;
		}
		else
		{
			x = 260;
			dx = 60;
		}

		for (auto elemento = resultado.begin(); elemento != resultado.end(); ++elemento, ++i) {
			Button^ nuevoBoton = gcnew Button();
			String^ txtbtn = "(" + gcnew String(elemento->first.c_str()) + "," + gcnew String(elemento->second.c_str()) + ")";
			nuevoBoton->Click += gcnew EventHandler(this, &MyForm::clickBoton);
			nuevoBoton->Text = txtbtn;
			nuevoBoton->Name = txtbtn;
			nuevoBoton->Location = Point(x + dx * i, y);//posicionando los botones
			if (elemento + 1 != resultado.end() && (elemento + 1)->first != elemento->first) {//ordenando los botones
				if (convierteString.size() <= 5)y += 60;
				else y += 50;
				i = 0;
				x = 200;
			}
			panel1->Controls->Add(nuevoBoton);//poniendolos en el panel
		}


	}
	private:
		System::Void clickBoton(System::Object^ sender, System::EventArgs^ e) {
			Button^ Boton = safe_cast<Button^>(sender);
			clasifica->Visible = true;
			if (Boton->BackColor == Color::Gray)
				Boton->BackColor = Color::Transparent;
			else {
				Boton->BackColor = Color::Blue;
				Boton->ForeColor = Color::White;
				String^ c = Boton->Text->ToString();
				string convierteString = msclr::interop::marshal_as<string>(c);
				string ptmrConvierteString = string(convierteString);
				relacion->push_back(ptmrConvierteString);
			}
			
		}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void clasifica_Click(System::Object^ sender, System::EventArgs^ e) {
		Conjunto Bar = { {'1','1'}/*,{"2","2"},{"3","3"}*/ };
		auto r=(*relacion).clasificarR(Bar);
	
	/*	cout << r.size();*/
		/*for (auto re : r) cout << tipos[re] << endl;*/
	}
};
}
