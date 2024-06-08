#pragma once

#include "Resource.h"

enum SearchStatus {
	S_LINK = 0,
	S_BOOK = 1,
	S_SUBJECT = 2
};

namespace lab5_dotnet {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class MyForm : public System::Windows::Forms::Form {
	
	public: MyForm(void);
	protected: ~MyForm();

	private: Resource^ dm;

	private: System::Windows::Forms::Button^ buttonSearchBook;
	private: System::Windows::Forms::Button^ buttonSearchSubject;
	private: System::Windows::Forms::TextBox^ textBoxSearch;
	private: System::Windows::Forms::Button^ buttonSearchStart;
	private: System::Windows::Forms::ListView^ listViewData1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::Label^ labelSearch;
	private: System::Windows::Forms::TextBox^ textBoxInputData1;
	private: System::Windows::Forms::Label^ labelInputData1;
	private: System::Windows::Forms::TextBox^ textBoxInputData2;
	private: System::Windows::Forms::Label^ labelInputData2;


	private: System::Windows::Forms::Button^ buttonRemoveNode;
	private: System::Windows::Forms::Button^ buttonAddNode;
	private: System::Windows::Forms::Button^ buttonSearchLink;
	private: System::Windows::Forms::Button^ button1;



	/// <summary>
	/// Обязательная переменная конструктора.
	/// </summary>
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void) {
			this->buttonSearchLink = (gcnew System::Windows::Forms::Button());
			this->buttonSearchBook = (gcnew System::Windows::Forms::Button());
			this->buttonSearchSubject = (gcnew System::Windows::Forms::Button());
			this->textBoxSearch = (gcnew System::Windows::Forms::TextBox());
			this->buttonSearchStart = (gcnew System::Windows::Forms::Button());
			this->listViewData1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->labelSearch = (gcnew System::Windows::Forms::Label());
			this->textBoxInputData1 = (gcnew System::Windows::Forms::TextBox());
			this->labelInputData1 = (gcnew System::Windows::Forms::Label());
			this->textBoxInputData2 = (gcnew System::Windows::Forms::TextBox());
			this->labelInputData2 = (gcnew System::Windows::Forms::Label());
			this->buttonRemoveNode = (gcnew System::Windows::Forms::Button());
			this->buttonAddNode = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonSearchLink
			// 
			this->buttonSearchLink->BackColor = System::Drawing::Color::LightGray;
			this->buttonSearchLink->Location = System::Drawing::Point(260, 20);
			this->buttonSearchLink->Name = L"buttonSearchLink";
			this->buttonSearchLink->Size = System::Drawing::Size(100, 45);
			this->buttonSearchLink->TabIndex = 2;
			this->buttonSearchLink->Text = L"Связи";
			this->buttonSearchLink->UseVisualStyleBackColor = false;
			this->buttonSearchLink->Click += gcnew System::EventHandler(this, &MyForm::buttonSearchLink_Click);
			// 
			// buttonSearchBook
			// 
			this->buttonSearchBook->BackColor = System::Drawing::Color::LightGray;
			this->buttonSearchBook->Location = System::Drawing::Point(40, 20);
			this->buttonSearchBook->Name = L"buttonSearchBook";
			this->buttonSearchBook->Size = System::Drawing::Size(100, 45);
			this->buttonSearchBook->TabIndex = 0;
			this->buttonSearchBook->Text = L"Книги";
			this->buttonSearchBook->UseVisualStyleBackColor = false;
			this->buttonSearchBook->Click += gcnew System::EventHandler(this, &MyForm::buttonSearchBook_Click);
			// 
			// buttonSearchSubject
			// 
			this->buttonSearchSubject->BackColor = System::Drawing::Color::LightGray;
			this->buttonSearchSubject->Location = System::Drawing::Point(150, 20);
			this->buttonSearchSubject->Name = L"buttonSearchSubject";
			this->buttonSearchSubject->Size = System::Drawing::Size(100, 45);
			this->buttonSearchSubject->TabIndex = 1;
			this->buttonSearchSubject->Text = L"Дисциплины";
			this->buttonSearchSubject->UseVisualStyleBackColor = false;
			this->buttonSearchSubject->Click += gcnew System::EventHandler(this, &MyForm::buttonSearchSubject_Click);
			// 
			// textBoxSearch
			// 
			this->textBoxSearch->BackColor = System::Drawing::Color::LightGray;
			this->textBoxSearch->Enabled = false;
			this->textBoxSearch->Location = System::Drawing::Point(40, 80);
			this->textBoxSearch->Name = L"textBoxSearch";
			this->textBoxSearch->Size = System::Drawing::Size(450, 20);
			this->textBoxSearch->TabIndex = 3;
			// 
			// buttonSearchStart
			// 
			this->buttonSearchStart->BackColor = System::Drawing::Color::LightGray;
			this->buttonSearchStart->Enabled = false;
			this->buttonSearchStart->Location = System::Drawing::Point(370, 20);
			this->buttonSearchStart->Name = L"buttonSearchStart";
			this->buttonSearchStart->Size = System::Drawing::Size(120, 45);
			this->buttonSearchStart->TabIndex = 4;
			this->buttonSearchStart->Text = L"Поиск";
			this->buttonSearchStart->UseVisualStyleBackColor = false;
			this->buttonSearchStart->Click += gcnew System::EventHandler(this, &MyForm::buttonSearchStart_Click);
			// 
			// listViewData1
			// 
			this->listViewData1->BackColor = System::Drawing::Color::LightGray;
			this->listViewData1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader1,
					this->columnHeader2, this->columnHeader3
			});
			this->listViewData1->HideSelection = false;
			this->listViewData1->Location = System::Drawing::Point(40, 135);
			this->listViewData1->Name = L"listViewData1";
			this->listViewData1->Size = System::Drawing::Size(450, 250);
			this->listViewData1->TabIndex = 5;
			this->listViewData1->UseCompatibleStateImageBehavior = false;
			this->listViewData1->View = System::Windows::Forms::View::Details;
			this->listViewData1->ItemSelectionChanged += gcnew System::Windows::Forms::ListViewItemSelectionChangedEventHandler(this, &MyForm::listViewData1_ItemSelectionChanged);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Поле 1";
			this->columnHeader1->Width = 148;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Поле 2";
			this->columnHeader2->Width = 148;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Поле 3";
			this->columnHeader3->Width = 148;
			// 
			// labelSearch
			// 
			this->labelSearch->AutoSize = true;
			this->labelSearch->Location = System::Drawing::Point(40, 104);
			this->labelSearch->Name = L"labelSearch";
			this->labelSearch->Size = System::Drawing::Size(39, 13);
			this->labelSearch->TabIndex = 6;
			this->labelSearch->Text = L"Поиск";
			// 
			// textBoxInputData1
			// 
			this->textBoxInputData1->BackColor = System::Drawing::Color::LightGray;
			this->textBoxInputData1->Enabled = false;
			this->textBoxInputData1->Location = System::Drawing::Point(520, 135);
			this->textBoxInputData1->Name = L"textBoxInputData1";
			this->textBoxInputData1->Size = System::Drawing::Size(200, 20);
			this->textBoxInputData1->TabIndex = 7;
			// 
			// labelInputData1
			// 
			this->labelInputData1->AutoSize = true;
			this->labelInputData1->Location = System::Drawing::Point(520, 160);
			this->labelInputData1->Name = L"labelInputData1";
			this->labelInputData1->Size = System::Drawing::Size(75, 13);
			this->labelInputData1->TabIndex = 8;
			this->labelInputData1->Text = L"Поле ввода 1";
			// 
			// textBoxInputData2
			// 
			this->textBoxInputData2->BackColor = System::Drawing::Color::LightGray;
			this->textBoxInputData2->Enabled = false;
			this->textBoxInputData2->Location = System::Drawing::Point(520, 190);
			this->textBoxInputData2->Name = L"textBoxInputData2";
			this->textBoxInputData2->Size = System::Drawing::Size(200, 20);
			this->textBoxInputData2->TabIndex = 9;
			// 
			// labelInputData2
			// 
			this->labelInputData2->AutoSize = true;
			this->labelInputData2->Location = System::Drawing::Point(520, 215);
			this->labelInputData2->Name = L"labelInputData2";
			this->labelInputData2->Size = System::Drawing::Size(75, 13);
			this->labelInputData2->TabIndex = 10;
			this->labelInputData2->Text = L"Поле ввода 2";
			// 
			// buttonRemoveNode
			// 
			this->buttonRemoveNode->BackColor = System::Drawing::Color::LightGray;
			this->buttonRemoveNode->Enabled = false;
			this->buttonRemoveNode->Location = System::Drawing::Point(520, 325);
			this->buttonRemoveNode->Name = L"buttonRemoveNode";
			this->buttonRemoveNode->Size = System::Drawing::Size(90, 40);
			this->buttonRemoveNode->TabIndex = 13;
			this->buttonRemoveNode->Text = L"Удалить";
			this->buttonRemoveNode->UseVisualStyleBackColor = false;
			this->buttonRemoveNode->Click += gcnew System::EventHandler(this, &MyForm::buttonRemoveNode_Click);
			// 
			// buttonAddNode
			// 
			this->buttonAddNode->BackColor = System::Drawing::Color::LightGray;
			this->buttonAddNode->Enabled = false;
			this->buttonAddNode->Location = System::Drawing::Point(630, 325);
			this->buttonAddNode->Name = L"buttonAddNode";
			this->buttonAddNode->Size = System::Drawing::Size(90, 40);
			this->buttonAddNode->TabIndex = 14;
			this->buttonAddNode->Text = L"Записать";
			this->buttonAddNode->UseVisualStyleBackColor = false;
			this->buttonAddNode->Click += gcnew System::EventHandler(this, &MyForm::buttonAddNode_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(534, 41);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(143, 44);
			this->button1->TabIndex = 15;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->BackColor = System::Drawing::Color::LavenderBlush;
			this->ClientSize = System::Drawing::Size(750, 400);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->buttonAddNode);
			this->Controls->Add(this->buttonRemoveNode);
			this->Controls->Add(this->labelInputData2);
			this->Controls->Add(this->textBoxInputData2);
			this->Controls->Add(this->labelInputData1);
			this->Controls->Add(this->textBoxInputData1);
			this->Controls->Add(this->labelSearch);
			this->Controls->Add(this->listViewData1);
			this->Controls->Add(this->buttonSearchStart);
			this->Controls->Add(this->textBoxSearch);
			this->Controls->Add(this->buttonSearchSubject);
			this->Controls->Add(this->buttonSearchBook);
			this->Controls->Add(this->buttonSearchLink);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"MyForm";
			this->Text = L"Библиотечная картотека";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: bool IsChangeSearchButtonClicked = false;
		     bool IsDataInitialized = false;
		     SearchStatus searchStatus = S_BOOK;

	private: Void initializationData();
	private: Void buttonSearchLink_Click(System::Object^ sender, System::EventArgs^ e);
	private: Void buttonSearchBook_Click(Object^ sender, EventArgs^ e);
	private: Void buttonSearchSubject_Click(Object^ sender, EventArgs^ e);
	private: Void buttonSearchStart_Click(Object^ sender, EventArgs^ e);
	private: Void buttonRemoveNode_Click(Object^ sender, EventArgs^ e);
	private: Void buttonAddNode_Click(Object^ sender, EventArgs^ e);
	private: Void listViewData1_ItemSelectionChanged(Object^ sender, ListViewItemSelectionChangedEventArgs^ e);

};
}