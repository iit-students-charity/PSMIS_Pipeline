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
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle2 = new System.Windows.Forms.DataGridViewCellStyle();
            this.A_Label = new System.Windows.Forms.Label();
            this.A_TextBox = new System.Windows.Forms.TextBox();
            this.B_TextBox = new System.Windows.Forms.TextBox();
            this.B_Label = new System.Windows.Forms.Label();
            this.m_TextBox = new System.Windows.Forms.TextBox();
            this.m_Label = new System.Windows.Forms.Label();
            this.t_TextBox = new System.Windows.Forms.TextBox();
            this.t_Label = new System.Windows.Forms.Label();
            this.Start_Button = new System.Windows.Forms.Button();
            this.Result_ComboBox = new System.Windows.Forms.ComboBox();
            this.Pipeine_DataGridView = new System.Windows.Forms.DataGridView();
            this.Column1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.s1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.p1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.s2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.p2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.s3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.p3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.s4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.p4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.s5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.p5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.s6 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.p6 = new System.Windows.Forms.DataGridViewTextBoxColumn();
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
            // t_TextBox
            // 
            this.t_TextBox.Location = new System.Drawing.Point(386, 12);
            this.t_TextBox.Name = "t_TextBox";
            this.t_TextBox.Size = new System.Drawing.Size(36, 20);
            this.t_TextBox.TabIndex = 9;
            // 
            // t_Label
            // 
            this.t_Label.AutoSize = true;
            this.t_Label.Location = new System.Drawing.Point(370, 15);
            this.t_Label.Name = "t_Label";
            this.t_Label.Size = new System.Drawing.Size(10, 13);
            this.t_Label.TabIndex = 8;
            this.t_Label.Text = "t";
            // 
            // Start_Button
            // 
            this.Start_Button.Location = new System.Drawing.Point(1084, 13);
            this.Start_Button.Name = "Start_Button";
            this.Start_Button.Size = new System.Drawing.Size(168, 23);
            this.Start_Button.TabIndex = 10;
            this.Start_Button.Text = "Start pipeline";
            this.Start_Button.UseVisualStyleBackColor = true;
            this.Start_Button.Click += new System.EventHandler(this.Start_Button_Click);
            // 
            // Result_ComboBox
            // 
            this.Result_ComboBox.FormattingEnabled = true;
            this.Result_ComboBox.Location = new System.Drawing.Point(1268, 15);
            this.Result_ComboBox.Name = "Result_ComboBox";
            this.Result_ComboBox.Size = new System.Drawing.Size(157, 21);
            this.Result_ComboBox.TabIndex = 11;
            this.Result_ComboBox.Text = "Product list";
            // 
            // Pipeine_DataGridView
            // 
            this.Pipeine_DataGridView.AllowUserToAddRows = false;
            this.Pipeine_DataGridView.AllowUserToDeleteRows = false;
            this.Pipeine_DataGridView.AllowUserToResizeColumns = false;
            this.Pipeine_DataGridView.AllowUserToResizeRows = false;
            this.Pipeine_DataGridView.BackgroundColor = System.Drawing.Color.White;
            dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            dataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Desktop;
            dataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.Pipeine_DataGridView.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
            this.Pipeine_DataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.Pipeine_DataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Column1,
            this.s1,
            this.p1,
            this.s2,
            this.p2,
            this.s3,
            this.p3,
            this.s4,
            this.p4,
            this.s5,
            this.p5,
            this.s6,
            this.p6});
            dataGridViewCellStyle2.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle2.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            dataGridViewCellStyle2.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle2.SelectionBackColor = System.Drawing.SystemColors.ActiveCaption;
            dataGridViewCellStyle2.SelectionForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle2.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.Pipeine_DataGridView.DefaultCellStyle = dataGridViewCellStyle2;
            this.Pipeine_DataGridView.Location = new System.Drawing.Point(12, 51);
            this.Pipeine_DataGridView.Name = "Pipeine_DataGridView";
            this.Pipeine_DataGridView.ReadOnly = true;
            this.Pipeine_DataGridView.RowTemplate.Height = 100;
            this.Pipeine_DataGridView.RowTemplate.ReadOnly = true;
            this.Pipeine_DataGridView.RowTemplate.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.Pipeine_DataGridView.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.Pipeine_DataGridView.Size = new System.Drawing.Size(1413, 498);
            this.Pipeine_DataGridView.TabIndex = 12;
            // 
            // Column1
            // 
            this.Column1.Frozen = true;
            this.Column1.HeaderText = "Clock";
            this.Column1.Name = "Column1";
            this.Column1.ReadOnly = true;
            this.Column1.Width = 50;
            // 
            // s1
            // 
            this.s1.Frozen = true;
            this.s1.HeaderText = "Shift";
            this.s1.Name = "s1";
            this.s1.ReadOnly = true;
            this.s1.Width = 110;
            // 
            // p1
            // 
            this.p1.Frozen = true;
            this.p1.HeaderText = "Sum&Prod";
            this.p1.Name = "p1";
            this.p1.ReadOnly = true;
            this.p1.Width = 110;
            // 
            // s2
            // 
            this.s2.Frozen = true;
            this.s2.HeaderText = "Shift";
            this.s2.Name = "s2";
            this.s2.ReadOnly = true;
            this.s2.Width = 110;
            // 
            // p2
            // 
            this.p2.Frozen = true;
            this.p2.HeaderText = "Sum&Prod";
            this.p2.Name = "p2";
            this.p2.ReadOnly = true;
            this.p2.Width = 110;
            // 
            // s3
            // 
            this.s3.Frozen = true;
            this.s3.HeaderText = "Shift";
            this.s3.Name = "s3";
            this.s3.ReadOnly = true;
            this.s3.Width = 110;
            // 
            // p3
            // 
            this.p3.Frozen = true;
            this.p3.HeaderText = "Sum&Prod";
            this.p3.Name = "p3";
            this.p3.ReadOnly = true;
            this.p3.Width = 110;
            // 
            // s4
            // 
            this.s4.Frozen = true;
            this.s4.HeaderText = "Shift";
            this.s4.Name = "s4";
            this.s4.ReadOnly = true;
            this.s4.Width = 110;
            // 
            // p4
            // 
            this.p4.Frozen = true;
            this.p4.HeaderText = "Sum&Prod";
            this.p4.Name = "p4";
            this.p4.ReadOnly = true;
            this.p4.Width = 110;
            // 
            // s5
            // 
            this.s5.Frozen = true;
            this.s5.HeaderText = "Shift";
            this.s5.Name = "s5";
            this.s5.ReadOnly = true;
            this.s5.Width = 110;
            // 
            // p5
            // 
            this.p5.Frozen = true;
            this.p5.HeaderText = "Sum&Prod";
            this.p5.Name = "p5";
            this.p5.ReadOnly = true;
            this.p5.Width = 110;
            // 
            // s6
            // 
            this.s6.Frozen = true;
            this.s6.HeaderText = "Shift";
            this.s6.Name = "s6";
            this.s6.ReadOnly = true;
            this.s6.Width = 110;
            // 
            // p6
            // 
            this.p6.Frozen = true;
            this.p6.HeaderText = "Sum&Prod";
            this.p6.Name = "p6";
            this.p6.ReadOnly = true;
            this.p6.Width = 110;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1440, 561);
            this.Controls.Add(this.Pipeine_DataGridView);
            this.Controls.Add(this.Result_ComboBox);
            this.Controls.Add(this.Start_Button);
            this.Controls.Add(this.t_TextBox);
            this.Controls.Add(this.t_Label);
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
        private TextBox t_TextBox;
        private Label t_Label;
        private Button Start_Button;
        private ComboBox Result_ComboBox;
        private DataGridView Pipeine_DataGridView;
        private DataGridViewTextBoxColumn Column1;
        private DataGridViewTextBoxColumn s1;
        private DataGridViewTextBoxColumn p1;
        private DataGridViewTextBoxColumn s2;
        private DataGridViewTextBoxColumn p2;
        private DataGridViewTextBoxColumn s3;
        private DataGridViewTextBoxColumn p3;
        private DataGridViewTextBoxColumn s4;
        private DataGridViewTextBoxColumn p4;
        private DataGridViewTextBoxColumn s5;
        private DataGridViewTextBoxColumn p5;
        private DataGridViewTextBoxColumn s6;
        private DataGridViewTextBoxColumn p6;
    }
}

