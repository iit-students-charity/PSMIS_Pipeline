#pragma once

namespace PipelineWinform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::Label^  A_Label;
	private: System::Windows::Forms::Label^  B_Label;





	private: System::Windows::Forms::Label^  m_Label;
	private: System::Windows::Forms::Label^  n_Label;
	private: System::Windows::Forms::Label^  t_Label;
	private: System::Windows::Forms::Button^  Start_Button;

	private: System::Windows::Forms::ComboBox^  C_ComboBox;
	private: System::Windows::Forms::MaskedTextBox^  m_MaskedTextBox;
	private: System::Windows::Forms::MaskedTextBox^  n_MaskedTextBox;
	private: System::Windows::Forms::MaskedTextBox^  t_MaskedTextBox;
	private: System::Windows::Forms::TextBox^  B_TextBox;
	private: System::Windows::Forms::TextBox^  A_TextBox;
	private: System::Windows::Forms::DataGridView^  Pipeline_DataGridView;





	protected:

	protected:

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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->A_Label = (gcnew System::Windows::Forms::Label());
			this->B_Label = (gcnew System::Windows::Forms::Label());
			this->m_Label = (gcnew System::Windows::Forms::Label());
			this->n_Label = (gcnew System::Windows::Forms::Label());
			this->t_Label = (gcnew System::Windows::Forms::Label());
			this->Start_Button = (gcnew System::Windows::Forms::Button());
			this->C_ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->m_MaskedTextBox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->n_MaskedTextBox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->t_MaskedTextBox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->B_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->A_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Pipeline_DataGridView = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Pipeline_DataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// A_Label
			// 
			this->A_Label->AutoSize = true;
			this->A_Label->BackColor = System::Drawing::Color::Transparent;
			this->A_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->A_Label->Location = System::Drawing::Point(13, 15);
			this->A_Label->Name = L"A_Label";
			this->A_Label->Size = System::Drawing::Size(14, 15);
			this->A_Label->TabIndex = 0;
			this->A_Label->Text = L"A";
			// 
			// B_Label
			// 
			this->B_Label->AutoSize = true;
			this->B_Label->BackColor = System::Drawing::Color::Transparent;
			this->B_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->B_Label->Location = System::Drawing::Point(253, 15);
			this->B_Label->Name = L"B_Label";
			this->B_Label->Size = System::Drawing::Size(15, 15);
			this->B_Label->TabIndex = 1;
			this->B_Label->Text = L"B";
			// 
			// m_Label
			// 
			this->m_Label->AutoSize = true;
			this->m_Label->BackColor = System::Drawing::Color::Transparent;
			this->m_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->m_Label->Location = System::Drawing::Point(494, 15);
			this->m_Label->Name = L"m_Label";
			this->m_Label->Size = System::Drawing::Size(18, 15);
			this->m_Label->TabIndex = 7;
			this->m_Label->Text = L"m";
			// 
			// n_Label
			// 
			this->n_Label->AutoSize = true;
			this->n_Label->BackColor = System::Drawing::Color::Transparent;
			this->n_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->n_Label->Location = System::Drawing::Point(567, 15);
			this->n_Label->Name = L"n_Label";
			this->n_Label->Size = System::Drawing::Size(14, 15);
			this->n_Label->TabIndex = 8;
			this->n_Label->Text = L"n";
			// 
			// t_Label
			// 
			this->t_Label->AutoSize = true;
			this->t_Label->BackColor = System::Drawing::Color::Transparent;
			this->t_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->t_Label->Location = System::Drawing::Point(636, 15);
			this->t_Label->Name = L"t_Label";
			this->t_Label->Size = System::Drawing::Size(10, 15);
			this->t_Label->TabIndex = 9;
			this->t_Label->Text = L"t";
			// 
			// Start_Button
			// 
			this->Start_Button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Start_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->Start_Button->Location = System::Drawing::Point(756, 10);
			this->Start_Button->Name = L"Start_Button";
			this->Start_Button->Size = System::Drawing::Size(150, 26);
			this->Start_Button->TabIndex = 10;
			this->Start_Button->Text = L"Запустить конвейер";
			this->Start_Button->UseVisualStyleBackColor = true;
			this->Start_Button->Click += gcnew System::EventHandler(this, &MyForm::Start_Button_Click);
			// 
			// C_ComboBox
			// 
			this->C_ComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->C_ComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->C_ComboBox->FormattingEnabled = true;
			this->C_ComboBox->Location = System::Drawing::Point(922, 12);
			this->C_ComboBox->Name = L"C_ComboBox";
			this->C_ComboBox->Size = System::Drawing::Size(150, 23);
			this->C_ComboBox->TabIndex = 12;
			this->C_ComboBox->Text = L"Список результатов";
			// 
			// m_MaskedTextBox
			// 
			this->m_MaskedTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->m_MaskedTextBox->Location = System::Drawing::Point(518, 12);
			this->m_MaskedTextBox->Mask = L"000";
			this->m_MaskedTextBox->Name = L"m_MaskedTextBox";
			this->m_MaskedTextBox->Size = System::Drawing::Size(43, 21);
			this->m_MaskedTextBox->TabIndex = 13;
			this->m_MaskedTextBox->ValidatingType = System::Int32::typeid;
			// 
			// n_MaskedTextBox
			// 
			this->n_MaskedTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->n_MaskedTextBox->Location = System::Drawing::Point(587, 12);
			this->n_MaskedTextBox->Mask = L"0000";
			this->n_MaskedTextBox->Name = L"n_MaskedTextBox";
			this->n_MaskedTextBox->Size = System::Drawing::Size(43, 21);
			this->n_MaskedTextBox->TabIndex = 14;
			this->n_MaskedTextBox->ValidatingType = System::Int32::typeid;
			// 
			// t_MaskedTextBox
			// 
			this->t_MaskedTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->t_MaskedTextBox->Location = System::Drawing::Point(652, 12);
			this->t_MaskedTextBox->Mask = L"000";
			this->t_MaskedTextBox->Name = L"t_MaskedTextBox";
			this->t_MaskedTextBox->Size = System::Drawing::Size(43, 21);
			this->t_MaskedTextBox->TabIndex = 15;
			this->t_MaskedTextBox->ValidatingType = System::Int32::typeid;
			// 
			// B_TextBox
			// 
			this->B_TextBox->BackColor = System::Drawing::Color::White;
			this->B_TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->B_TextBox->Location = System::Drawing::Point(277, 12);
			this->B_TextBox->Name = L"B_TextBox";
			this->B_TextBox->Size = System::Drawing::Size(200, 21);
			this->B_TextBox->TabIndex = 3;
			// 
			// A_TextBox
			// 
			this->A_TextBox->BackColor = System::Drawing::Color::White;
			this->A_TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->A_TextBox->Location = System::Drawing::Point(36, 12);
			this->A_TextBox->Name = L"A_TextBox";
			this->A_TextBox->Size = System::Drawing::Size(200, 21);
			this->A_TextBox->TabIndex = 2;
			// 
			// Pipeline_DataGridView
			// 
			this->Pipeline_DataGridView->AllowUserToAddRows = false;
			this->Pipeline_DataGridView->AllowUserToDeleteRows = false;
			this->Pipeline_DataGridView->AllowUserToResizeColumns = false;
			this->Pipeline_DataGridView->AllowUserToResizeRows = false;
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::Color::Gainsboro;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::Color::Black;
			this->Pipeline_DataGridView->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle6;
			this->Pipeline_DataGridView->BackgroundColor = System::Drawing::Color::White;
			this->Pipeline_DataGridView->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Pipeline_DataGridView->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			this->Pipeline_DataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Pipeline_DataGridView->Location = System::Drawing::Point(16, 50);
			this->Pipeline_DataGridView->Name = L"Pipeline_DataGridView";
			this->Pipeline_DataGridView->ReadOnly = true;
			this->Pipeline_DataGridView->Size = System::Drawing::Size(1056, 499);
			this->Pipeline_DataGridView->TabIndex = 16;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1084, 561);
			this->Controls->Add(this->Pipeline_DataGridView);
			this->Controls->Add(this->t_MaskedTextBox);
			this->Controls->Add(this->n_MaskedTextBox);
			this->Controls->Add(this->m_MaskedTextBox);
			this->Controls->Add(this->C_ComboBox);
			this->Controls->Add(this->Start_Button);
			this->Controls->Add(this->t_Label);
			this->Controls->Add(this->n_Label);
			this->Controls->Add(this->m_Label);
			this->Controls->Add(this->B_TextBox);
			this->Controls->Add(this->A_TextBox);
			this->Controls->Add(this->B_Label);
			this->Controls->Add(this->A_Label);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1100, 600);
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pipeline";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Pipeline_DataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void Start_Button_Click(System::Object^  sender, System::EventArgs^  e) {
			
		}
	};
}