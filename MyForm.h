#pragma once
#include"HashTable.h"
#include "Node_2.h"
#include "Dictionaryy.h"
#include "ARY_TREE.h"
#include <vector>
namespace DSGrammarly {

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
		HashTable* helping_verbs = new HashTable(13);
		HashTable* verbs = new HashTable(271);
		HashTable* prepositions = new HashTable(70);
		Dictionaryy *D1 = new Dictionaryy;
		ARY_TREE* N1 = new ARY_TREE;
	private: System::Windows::Forms::TabControl^ Tabs;
	public:



	private: System::Windows::Forms::TabPage^ TensePage;
	public:


	public: System::Windows::Forms::TextBox^ InputBox;
	private:
	private: System::Windows::Forms::Button^ InputButton;
	private: System::Windows::Forms::Button^ SynonymInputButton;

	private: System::Windows::Forms::Button^ DictionaryInputButton;
	private: System::Windows::Forms::TextBox^ SynonymBox;



	private: System::Windows::Forms::TextBox^ DictionaryInputBox;
	private: System::Windows::Forms::TextBox^ MeaningBox;



	private: System::Windows::Forms::TextBox^ OutputBox;
	private: System::Windows::Forms::Button^ FindSynonymButton;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::TabPage^ Dictionary;
	public:

	public:

	public:


	public:



		MyForm(void)
		{
			InitializeComponent();
			contentloader();
			D1->WriteIntoTree();
			D1->WriteSynAnt();
			consolestatus(1);
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

	protected:

	public:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Tabs = (gcnew System::Windows::Forms::TabControl());
			this->TensePage = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->FindSynonymButton = (gcnew System::Windows::Forms::Button());
			this->OutputBox = (gcnew System::Windows::Forms::TextBox());
			this->InputBox = (gcnew System::Windows::Forms::TextBox());
			this->InputButton = (gcnew System::Windows::Forms::Button());
			this->Dictionary = (gcnew System::Windows::Forms::TabPage());
			this->SynonymInputButton = (gcnew System::Windows::Forms::Button());
			this->DictionaryInputButton = (gcnew System::Windows::Forms::Button());
			this->SynonymBox = (gcnew System::Windows::Forms::TextBox());
			this->DictionaryInputBox = (gcnew System::Windows::Forms::TextBox());
			this->MeaningBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Tabs->SuspendLayout();
			this->TensePage->SuspendLayout();
			this->Dictionary->SuspendLayout();
			this->SuspendLayout();
			// 
			// Tabs
			// 
			this->Tabs->Controls->Add(this->TensePage);
			this->Tabs->Controls->Add(this->Dictionary);
			this->Tabs->Location = System::Drawing::Point(0, 0);
			this->Tabs->Name = L"Tabs";
			this->Tabs->SelectedIndex = 0;
			this->Tabs->Size = System::Drawing::Size(777, 460);
			this->Tabs->TabIndex = 3;
			// 
			// TensePage
			// 
			this->TensePage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TensePage.BackgroundImage")));
			this->TensePage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->TensePage->Controls->Add(this->label2);
			this->TensePage->Controls->Add(this->label1);
			this->TensePage->Controls->Add(this->FindSynonymButton);
			this->TensePage->Controls->Add(this->OutputBox);
			this->TensePage->Controls->Add(this->InputBox);
			this->TensePage->Controls->Add(this->InputButton);
			this->TensePage->Location = System::Drawing::Point(4, 22);
			this->TensePage->Name = L"TensePage";
			this->TensePage->Padding = System::Windows::Forms::Padding(3);
			this->TensePage->Size = System::Drawing::Size(769, 434);
			this->TensePage->TabIndex = 0;
			this->TensePage->Text = L"Tenses";
			this->TensePage->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(18, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(736, 41);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Grammarly: Tense Corrector and Dictionary";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// FindSynonymButton
			// 
			this->FindSynonymButton->Location = System::Drawing::Point(599, 176);
			this->FindSynonymButton->Name = L"FindSynonymButton";
			this->FindSynonymButton->Size = System::Drawing::Size(126, 38);
			this->FindSynonymButton->TabIndex = 7;
			this->FindSynonymButton->Text = L"Find Possible Synonyms";
			this->FindSynonymButton->UseVisualStyleBackColor = true;
			this->FindSynonymButton->Click += gcnew System::EventHandler(this, &MyForm::FindSynonymButton_Click);
			// 
			// OutputBox
			// 
			this->OutputBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->OutputBox->Location = System::Drawing::Point(32, 231);
			this->OutputBox->Multiline = true;
			this->OutputBox->Name = L"OutputBox";
			this->OutputBox->ReadOnly = true;
			this->OutputBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->OutputBox->Size = System::Drawing::Size(693, 181);
			this->OutputBox->TabIndex = 6;
			// 
			// InputBox
			// 
			this->InputBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InputBox->Location = System::Drawing::Point(32, 104);
			this->InputBox->Multiline = true;
			this->InputBox->Name = L"InputBox";
			this->InputBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->InputBox->Size = System::Drawing::Size(544, 110);
			this->InputBox->TabIndex = 4;
			this->InputBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// InputButton
			// 
			this->InputButton->Location = System::Drawing::Point(599, 88);
			this->InputButton->Name = L"InputButton";
			this->InputButton->Size = System::Drawing::Size(126, 77);
			this->InputButton->TabIndex = 3;
			this->InputButton->Text = L"Test the sentence";
			this->InputButton->UseVisualStyleBackColor = true;
			this->InputButton->Click += gcnew System::EventHandler(this, &MyForm::InputButton_Click);
			// 
			// Dictionary
			// 
			this->Dictionary->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Dictionary.BackgroundImage")));
			this->Dictionary->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Dictionary->Controls->Add(this->label3);
			this->Dictionary->Controls->Add(this->SynonymInputButton);
			this->Dictionary->Controls->Add(this->DictionaryInputButton);
			this->Dictionary->Controls->Add(this->SynonymBox);
			this->Dictionary->Controls->Add(this->DictionaryInputBox);
			this->Dictionary->Controls->Add(this->MeaningBox);
			this->Dictionary->Location = System::Drawing::Point(4, 22);
			this->Dictionary->Name = L"Dictionary";
			this->Dictionary->Padding = System::Windows::Forms::Padding(3);
			this->Dictionary->Size = System::Drawing::Size(769, 434);
			this->Dictionary->TabIndex = 1;
			this->Dictionary->Text = L"Dictionary";
			this->Dictionary->UseVisualStyleBackColor = true;
			// 
			// SynonymInputButton
			// 
			this->SynonymInputButton->Location = System::Drawing::Point(646, 58);
			this->SynonymInputButton->Name = L"SynonymInputButton";
			this->SynonymInputButton->Size = System::Drawing::Size(98, 52);
			this->SynonymInputButton->TabIndex = 5;
			this->SynonymInputButton->Text = L"Find Synonyms";
			this->SynonymInputButton->UseVisualStyleBackColor = true;
			this->SynonymInputButton->Click += gcnew System::EventHandler(this, &MyForm::SynonymInputButton_Click);
			// 
			// DictionaryInputButton
			// 
			this->DictionaryInputButton->Location = System::Drawing::Point(524, 58);
			this->DictionaryInputButton->Name = L"DictionaryInputButton";
			this->DictionaryInputButton->Size = System::Drawing::Size(99, 52);
			this->DictionaryInputButton->TabIndex = 4;
			this->DictionaryInputButton->Text = L"Search For Meaning";
			this->DictionaryInputButton->UseVisualStyleBackColor = true;
			this->DictionaryInputButton->Click += gcnew System::EventHandler(this, &MyForm::DictionaryInputButton_Click);
			// 
			// SynonymBox
			// 
			this->SynonymBox->Location = System::Drawing::Point(24, 337);
			this->SynonymBox->Multiline = true;
			this->SynonymBox->Name = L"SynonymBox";
			this->SynonymBox->ReadOnly = true;
			this->SynonymBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->SynonymBox->Size = System::Drawing::Size(704, 88);
			this->SynonymBox->TabIndex = 3;
			// 
			// DictionaryInputBox
			// 
			this->DictionaryInputBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DictionaryInputBox->Location = System::Drawing::Point(24, 48);
			this->DictionaryInputBox->Multiline = true;
			this->DictionaryInputBox->Name = L"DictionaryInputBox";
			this->DictionaryInputBox->Size = System::Drawing::Size(480, 79);
			this->DictionaryInputBox->TabIndex = 2;
			// 
			// MeaningBox
			// 
			this->MeaningBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MeaningBox->Location = System::Drawing::Point(24, 147);
			this->MeaningBox->Multiline = true;
			this->MeaningBox->Name = L"MeaningBox";
			this->MeaningBox->ReadOnly = true;
			this->MeaningBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->MeaningBox->Size = System::Drawing::Size(704, 170);
			this->MeaningBox->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Yellow;
			this->label2->Location = System::Drawing::Point(32, 75);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(526, 24);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Write a Sentence in the following to get corrected suggestions";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Blue;
			this->label3->Location = System::Drawing::Point(20, 21);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(520, 24);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Write a word or sentence in the following to find its meanings:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(779, 459);
			this->Controls->Add(this->Tabs);
			this->Name = L"MyForm";
			this->Text = L"Grammarly";
			this->Tabs->ResumeLayout(false);
			this->TensePage->ResumeLayout(false);
			this->TensePage->PerformLayout();
			this->Dictionary->ResumeLayout(false);
			this->Dictionary->PerformLayout();
			this->ResumeLayout(false);

		}
		int tenseteller(Node* verbform);
		void contentloader();
		vector<string> algorithm(string sentence);
		void consolestatus(int which);
#pragma endregion


private: System::Void InputButton_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void DictionaryInputButton_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void SynonymInputButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void FindSynonymButton_Click(System::Object^ sender, System::EventArgs^ e);

};
}
