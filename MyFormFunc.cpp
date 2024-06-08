#include "MyForm.h"
#include "Resource.h"

using namespace lab5_dotnet;

MyForm::MyForm() {
	InitializeComponent();
	this->dm = gcnew Resource();
}

MyForm::~MyForm() {
	if (components) {
		delete components;
	}
	if (IsDataInitialized) {
		this->dm->WriteDataFile();
		delete this->dm;
		dm = nullptr;
		IsDataInitialized = false;
	}
}

Void MyForm::initializationData() {
	try {
		this->dm->ReadDataFile();
		this->IsDataInitialized = true;
	}
	catch (Exception^ e) {
		MessageBox::Show("Ошибка, не найдены файлы данных для чтения. Проверьте, что рядом "
			"с программой находится папка Data с тремя текстовыми файлами данных.", 
			"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		this->Close();
	}
}

Void MyForm::buttonSearchLink_Click(System::Object^ sender, System::EventArgs^ e) {
	IsChangeSearchButtonClicked = true;
	textBoxSearch->Enabled = true;
	buttonSearchStart->Enabled = true;
	buttonAddNode->Enabled = true;
	textBoxInputData1->Enabled = true;
	textBoxInputData2->Enabled = true;
	buttonSearchLink->FlatStyle = FlatStyle::Popup;
	buttonSearchBook->FlatStyle = FlatStyle::Standard;
	buttonSearchSubject->FlatStyle = FlatStyle::Standard;
	searchStatus = S_LINK;
	textBoxSearch->Text = L"";
	labelInputData1->Text = L"ID книги";
	labelInputData2->Text = L"ID дисциплины";
	labelSearch->Text = L"Введите информацию о связи";
	listViewData1->Items->Clear();
	columnHeader1->Text = "ID";
	columnHeader1->Width = 220;
	columnHeader2->Text = "Название книги";
	columnHeader2->Width = 220;
	columnHeader3->Text = "";
	columnHeader3->Width = 0;
}

Void MyForm::buttonSearchBook_Click(Object^ sender, EventArgs^ e) {
	IsChangeSearchButtonClicked = true;
	textBoxSearch->Enabled = true;
	buttonSearchStart->Enabled = true;
	buttonAddNode->Enabled = true;
	textBoxInputData1->Enabled = true;
	textBoxInputData2->Enabled = true;
	buttonSearchLink->FlatStyle = FlatStyle::Standard;
	buttonSearchBook->FlatStyle = FlatStyle::Popup;
	buttonSearchSubject->FlatStyle = FlatStyle::Standard;
	searchStatus = S_BOOK;
	textBoxSearch->Text = L"";
	labelInputData1->Text = L"ID книги";
	labelInputData2->Text = L"Название книги";
	labelSearch->Text = L"Введите информацию о книге";
	listViewData1->Items->Clear();
	columnHeader1->Text = "ID книги";
	columnHeader1->Width = 100;
	columnHeader2->Text = "Название книги";
	columnHeader2->Width = 230;
}

Void MyForm::buttonSearchSubject_Click(Object^ sender, EventArgs^ e) {
	IsChangeSearchButtonClicked = true;
	textBoxSearch->Enabled = true;
	buttonSearchStart->Enabled = true;
	buttonAddNode->Enabled = true;
	textBoxInputData1->Enabled = true;
	textBoxInputData2->Enabled = true;
	buttonSearchLink->FlatStyle = FlatStyle::Standard;
	buttonSearchBook->FlatStyle = FlatStyle::Standard;
	buttonSearchSubject->FlatStyle = FlatStyle::Popup;
	searchStatus = S_SUBJECT;
	textBoxSearch->Text = L"";
	labelInputData1->Text = L"Код дисциплины";
	labelInputData2->Text = L"Название дисциплины";
	labelSearch->Text = L"Введите информацию о дисциплине";
	listViewData1->Items->Clear();
	columnHeader1->Text = "Код";
	columnHeader1->Width = 75;
	columnHeader2->Text = "Название дисциплины";
	columnHeader2->Width = 145;
}

Void MyForm::buttonSearchStart_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!IsDataInitialized) {
		initializationData();
		IsDataInitialized = true;
	}
	listViewData1->Items->Clear();
	List<Object^>^ finded = nullptr;
	String^ text = textBoxSearch->Text->ToLower();

	switch (searchStatus) {
	case S_LINK:
		finded = dm->FindNode(type_Link, text);
		for each (Link^ link in finded) {
			ListViewItem^ item = gcnew ListViewItem();
			item->Text = link->bookid;
			item->SubItems->Add(link->subjid);
			listViewData1->Items->Add(item);
		}
		break;
	case S_BOOK:
		finded = dm->FindNode(type_Book, text);
		for each (Book^ book in finded) {
			ListViewItem^ item = gcnew ListViewItem();
			item->Text = book->bookid;
			item->SubItems->Add(book->nameofbook);
			listViewData1->Items->Add(item);
		}
		break;
	case S_SUBJECT:
		finded = dm->FindNode(type_Subject, text);
		for each (Subject^ subject in finded) {
			ListViewItem^ item = gcnew ListViewItem();
			item->Text = subject->subjid;
			item->SubItems->Add(subject->nameofsubj);
			listViewData1->Items->Add(item);
		}
		break;
	default:
		MessageBox::Show("Ошибка - не выбрана категория поиска", "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		break;
	}
	listViewData1->Scrollable = true;
}

Void MyForm::buttonAddNode_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ text1 = textBoxInputData1->Text;
	String^ text2 = textBoxInputData2->Text;

	if (String::IsNullOrWhiteSpace(text1) || String::IsNullOrWhiteSpace(text2)) {
		MessageBox::Show("Ошибка. Вы ввели не все данные, необходимые для записи в список.",
						 "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	else {
		ListViewItem^ item = gcnew ListViewItem();
		item->Text = text1;
		item->SubItems->Add(text2);
		Link^ link = gcnew Link();
		Book^ book = gcnew Book();
		Subject^ subject = gcnew Subject();
		Object^ node = nullptr;
		switch (searchStatus) {
		case S_LINK:
			link->bookid = text1;
			link->subjid = text2;
			node = link;
			dm->AddNode(type_Link, node);
			break;
		case S_BOOK:
			
				book->bookid = text1;
				book->nameofbook = text2;
				node = book;
				dm->AddNode(type_Book, node);
			break;
		case S_SUBJECT:
				subject->subjid = text1;
				subject->nameofsubj = text2;
				node = subject;
				dm->AddNode(type_Subject, node);
			break;
		default:
			MessageBox::Show("Ошибка - не выбрана категория записи", "Ошибка", 
							 MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (node) {
			listViewData1->Items->Add(item);
			textBoxInputData1->Text = "";
			textBoxInputData2->Text = "";
		}
	}
}

Void MyForm::listViewData1_ItemSelectionChanged(Object^ sender, ListViewItemSelectionChangedEventArgs^ e) {
	buttonRemoveNode->Enabled = listViewData1->SelectedItems->Count > 0;
}

Void MyForm::buttonRemoveNode_Click(System::Object^ sender, System::EventArgs^ e) {
	if (listViewData1->SelectedItems->Count > 0) {
		Link^ link = gcnew Link();
		Book^ book = gcnew Book();
		Subject^ subject = gcnew Subject();
		Object^ node = nullptr;
		List<ListViewItem^>^ itemsToRemove = gcnew List<ListViewItem^>();

		for each (ListViewItem^ item in listViewData1->SelectedItems) {
			itemsToRemove->Add(item);
		}
		for each (ListViewItem^ item in itemsToRemove) {
			listViewData1->Items->Remove(item);
			switch (searchStatus) {
			case S_LINK:
				link->bookid = item->Text;
				link->subjid = item->SubItems[0]->Text;
				node = link;
				dm->DeleteNode(type_Link, node);
				break;
			case S_BOOK:
				book->bookid = item->Text;
				node = book;
				dm->DeleteNode(type_Book, node);
				break;
			case S_SUBJECT:
				subject->subjid = item->Text;
				node = book;
				dm->DeleteNode(type_Book, node);
				break;
			default:
				MessageBox::Show("Ошибка - не выбрана категория удаления", "Ошибка",
								 MessageBoxButtons::OK, MessageBoxIcon::Error);
				break;
			}
		}
	}
	buttonRemoveNode->Enabled = false;
}