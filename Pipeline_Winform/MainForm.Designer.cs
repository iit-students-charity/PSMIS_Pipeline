using System.Windows.Forms;
using System.Drawing;

namespace Pipeline_Winform
{
    partial class MainForm
    {
        private System.ComponentModel.IContainer components = null;
        
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows
        
        private void InitializeComponent()
        {
            this.A_Label = new System.Windows.Forms.Label();
            this.A_TextBox = new System.Windows.Forms.TextBox();
            this.B_TextBox = new System.Windows.Forms.TextBox();
            this.B_Label = new System.Windows.Forms.Label();
            this.m_TextBox = new System.Windows.Forms.TextBox();
            this.m_Label = new System.Windows.Forms.Label();
            this.n_TextBox = new System.Windows.Forms.TextBox();
            this.n_Label = new System.Windows.Forms.Label();
            this.t_TextBox = new System.Windows.Forms.TextBox();
            this.t_Label = new System.Windows.Forms.Label();
            this.Start_Button = new System.Windows.Forms.Button();
            this.Result_ComboBox = new System.Windows.Forms.ComboBox();
            this.Pipeine_DataGridView = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.Pipeine_DataGridView)).BeginInit();
            this.SuspendLayout();
            // 
            // A_Label
            // 
            this.A_Label.AutoSize = true;
            this.A_Label.Location = new System.Drawing.Point(11, 15);
            this.A_Label.Name = "A_Label";
            this.A_Label.Size = new System.Drawing.Size(14, 13);
            this.A_Label.TabIndex = 0;
            this.A_Label.Text = "A";
            // 
            // A_TextBox
            // 
            this.A_TextBox.Location = new System.Drawing.Point(31, 12);
            this.A_TextBox.Name = "A_TextBox";
            this.A_TextBox.Size = new System.Drawing.Size(100, 20);
            this.A_TextBox.TabIndex = 1;
            // 
            // B_TextBox
            // 
            this.B_TextBox.Location = new System.Drawing.Point(167, 12);
            this.B_TextBox.Name = "B_TextBox";
            this.B_TextBox.Size = new System.Drawing.Size(100, 20);
            this.B_TextBox.TabIndex = 3;
            // 
            // B_Label
            // 
            this.B_Label.AutoSize = true;
            this.B_Label.Location = new System.Drawing.Point(147, 15);
            this.B_Label.Name = "B_Label";
            this.B_Label.Size = new System.Drawing.Size(14, 13);
            this.B_Label.TabIndex = 2;
            this.B_Label.Text = "B";
            // 
            // m_TextBox
            // 
            this.m_TextBox.Location = new System.Drawing.Point(325, 12);
            this.m_TextBox.Name = "m_TextBox";
            this.m_TextBox.Size = new System.Drawing.Size(36, 20);
            this.m_TextBox.TabIndex = 5;
            // 
            // m_Label
            // 
            this.m_Label.AutoSize = true;
            this.m_Label.Location = new System.Drawing.Point(305, 15);
            this.m_Label.Name = "m_Label";
            this.m_Label.Size = new System.Drawing.Size(15, 13);
            this.m_Label.TabIndex = 4;
            this.m_Label.Text = "m";
            // 
            // n_TextBox
            // 
            this.n_TextBox.Location = new System.Drawing.Point(387, 12);
            this.n_TextBox.Name = "n_TextBox";
            this.n_TextBox.Size = new System.Drawing.Size(36, 20);
            this.n_TextBox.TabIndex = 7;
            // 
            // n_Label
            // 
            this.n_Label.AutoSize = true;
            this.n_Label.Location = new System.Drawing.Point(367, 15);
            this.n_Label.Name = "n_Label";
            this.n_Label.Size = new System.Drawing.Size(13, 13);
            this.n_Label.TabIndex = 6;
            this.n_Label.Text = "n";
            // 
            // t_TextBox
            // 
            this.t_TextBox.Location = new System.Drawing.Point(445, 12);
            this.t_TextBox.Name = "t_TextBox";
            this.t_TextBox.Size = new System.Drawing.Size(36, 20);
            this.t_TextBox.TabIndex = 9;
            // 
            // t_Label
            // 
            this.t_Label.AutoSize = true;
            this.t_Label.Location = new System.Drawing.Point(429, 15);
            this.t_Label.Name = "t_Label";
            this.t_Label.Size = new System.Drawing.Size(10, 13);
            this.t_Label.TabIndex = 8;
            this.t_Label.Text = "t";
            // 
            // Start_Button
            // 
            this.Start_Button.Location = new System.Drawing.Point(728, 10);
            this.Start_Button.Name = "Start_Button";
            this.Start_Button.Size = new System.Drawing.Size(168, 23);
            this.Start_Button.TabIndex = 10;
            this.Start_Button.Text = "Запустить конвейер";
            this.Start_Button.UseVisualStyleBackColor = true;
            this.Start_Button.Click += new System.EventHandler(this.Start_Button_Click);
            // 
            // Result_ComboBox
            // 
            this.Result_ComboBox.FormattingEnabled = true;
            this.Result_ComboBox.Location = new System.Drawing.Point(915, 12);
            this.Result_ComboBox.Name = "Result_ComboBox";
            this.Result_ComboBox.Size = new System.Drawing.Size(157, 21);
            this.Result_ComboBox.TabIndex = 11;
            this.Result_ComboBox.Text = "Список результатов";
            // 
            // Pipeine_DataGridView
            // 
            this.Pipeine_DataGridView.AllowUserToAddRows = false;
            this.Pipeine_DataGridView.AllowUserToDeleteRows = false;
            this.Pipeine_DataGridView.BackgroundColor = System.Drawing.Color.White;
            this.Pipeine_DataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.Pipeine_DataGridView.Location = new System.Drawing.Point(12, 51);
            this.Pipeine_DataGridView.Name = "Pipeine_DataGridView";
            this.Pipeine_DataGridView.ReadOnly = true;
            this.Pipeine_DataGridView.Size = new System.Drawing.Size(1060, 498);
            this.Pipeine_DataGridView.TabIndex = 12;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1084, 561);
            this.Controls.Add(this.Pipeine_DataGridView);
            this.Controls.Add(this.Result_ComboBox);
            this.Controls.Add(this.Start_Button);
            this.Controls.Add(this.t_TextBox);
            this.Controls.Add(this.t_Label);
            this.Controls.Add(this.n_TextBox);
            this.Controls.Add(this.n_Label);
            this.Controls.Add(this.m_TextBox);
            this.Controls.Add(this.m_Label);
            this.Controls.Add(this.B_TextBox);
            this.Controls.Add(this.B_Label);
            this.Controls.Add(this.A_TextBox);
            this.Controls.Add(this.A_Label);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.Name = "MainForm";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Pipeline";
            ((System.ComponentModel.ISupportInitialize)(this.Pipeine_DataGridView)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Label A_Label;
        private TextBox A_TextBox;
        private TextBox B_TextBox;
        private Label B_Label;
        private TextBox m_TextBox;
        private Label m_Label;
        private TextBox n_TextBox;
        private Label n_Label;
        private TextBox t_TextBox;
        private Label t_Label;
        private Button Start_Button;
        private ComboBox Result_ComboBox;
        private DataGridView Pipeine_DataGridView;
    }
}

