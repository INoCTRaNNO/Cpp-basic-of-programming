#pragma once

namespace ProjectName {
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
        }

    protected:
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::Button^ button1;

    protected:

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(150, 107);
            this->textBox1->Multiline = true;
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(291, 94);
            this->textBox1->TabIndex = 0;
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(150, 270);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(291, 53);
            this->button1->TabIndex = 1;
            this->button1->Text = L"Find";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(581, 397);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->textBox1);
            this->Name = L"Form1";
            this->Text = L"Palindrome Substring";
            this->ResumeLayout(false);
            this->PerformLayout();

        }

#pragma endregion

        // Функция для проверки, является ли строка палиндромом
        bool IsPalindrome(String^ s)
        {
            int n = s->Length;
            for (int i = 0; i < n / 2; i++)
            {
                if (s[i] != s[n - i - 1])
                {
                    return false;
                }
            }
            return true;
        }

        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ s = textBox1->Text->Trim();
            int n = s->Length;
            String^ result = "NO SOLUTION";

            // Перебираем все подстроки
            for (int i = 0; i < n; i++)
            {
                for (int j = 1; j <= n - i; j++)
                {
                    String^ substring = s->Substring(i, j);
                    if (!IsPalindrome(substring))
                    {
                        if (result == "NO SOLUTION" || substring->Length > result->Length)
                        {
                            result = substring;
                        }
                    }
                }
            }

            MessageBox::Show(result);
        }
    };
}