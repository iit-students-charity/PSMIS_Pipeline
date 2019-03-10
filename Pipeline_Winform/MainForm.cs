using System;
using System.Text.RegularExpressions;
using System.Drawing;
using System.Windows.Forms;
using System.Collections.Generic;

namespace Pipeline_Winform
{
    public partial class MainForm : Form
    {
        private class InvalidValuesErrorDialog
        {
            private const int DLG_WIDTH = 250;
            private const int DLG_HEIGHT = 100;

            private string dlg_text = "Error";
            private string ertxt_text = "Unable to parse input values";

            private Label errorText;
            private Form dialog;

            public InvalidValuesErrorDialog(string _dlg_text, string _ertxt_text)
            {
                dlg_text = _dlg_text;
                ertxt_text = _ertxt_text;

                dialog = new Form
                {
                    Width = DLG_WIDTH,
                    Height = DLG_HEIGHT,
                    FormBorderStyle = FormBorderStyle.FixedToolWindow,
                    StartPosition = FormStartPosition.CenterScreen,
                    Text = dlg_text
                };

                errorText = new Label
                {
                    Width = dialog.Width - 40,
                    Height = dialog.Height / 2,
                    Location = new Point(15, 1),
                    Text = ertxt_text,
                    TextAlign = ContentAlignment.MiddleCenter
                };

                dialog.Controls.Add(errorText);
            }

            public void Show()
            {
                dialog.Show();
            }
        }

        public MainForm()
        {
            InitializeComponent();
        }

        private void Start_Button_Click(object sender, EventArgs e)
        {
            int m = 0;
            int n = 0;
            int t = 0;
            List<BinaryNumber> A = new List<BinaryNumber>();
            List<BinaryNumber> B = new List<BinaryNumber>();

            try
            {
                m = int.Parse(m_TextBox.Text);
                n = int.Parse(n_TextBox.Text);
                t = int.Parse(t_TextBox.Text);

                string regexPattern = @"\d{1,}";
                Regex rgx = new Regex(regexPattern);

                foreach (Match match in rgx.Matches(A_TextBox.Text))
                {
                    A.Add(new BinaryNumber(int.Parse(match.Value)));
                }
                foreach (Match match in rgx.Matches(B_TextBox.Text))
                {
                    B.Add(new BinaryNumber(int.Parse(match.Value)));
                }
            }
            catch (FormatException)
            {
                new InvalidValuesErrorDialog("Error", "Unable to parse input values").Show();
                return;
            }

            if ((m != A.Count) || (m != B.Count) || (A.Count != B.Count))
            {
                new InvalidValuesErrorDialog("Warning", "'m' parameter is not equal to A or B counts, " +
                    "or A and B counts arent equal").Show();
            }

            Pipeline pipeline = new Pipeline(A, B, m, n, t);


        }
    }
}
