using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DB_Exp3
{
    public partial class Form1 : Form
    {
        private readonly DataBase _db = new DataBase();
        private bool _login;
        private string _databaseNow = "";

        public Form1()
        {
            InitializeComponent();
            _login = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (_login || !_db.LoginDb()) return;

            label1.Text = "数据库已登录";
            _login = true;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (!_login || _db.LogoutDb()) return;

            label1.Text = "数据库已登出";
            _login = false;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (!_login) return;

            _ = new DataSet();
            try
            {
                var ds = _db.DataSelect("use DBExperiment " + textBox1.Text.ToString());
                dataGridView1.DataSource = ds.Tables[0];
            }
            catch (Exception ecp)
            {
                MessageBox.Show(ecp.ToString());
            }
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (!_login) return;

            switch (e.ColumnIndex)
            {
                case 0:
                {
                    var dr =
                        MessageBox.Show("确认修改：" + dataGridView1.Rows[e.RowIndex].Cells[2].Value.ToString(), "确认修改",
                            MessageBoxButtons.OKCancel, MessageBoxIcon.Warning, MessageBoxDefaultButton.Button1);
                    break;
                }
                case 1:
                {
                    var dr =
                        MessageBox.Show("确认删除：" + dataGridView1.Rows[e.RowIndex].Cells[2].Value.ToString(), "确认删除",
                            MessageBoxButtons.OKCancel, MessageBoxIcon.Warning, MessageBoxDefaultButton.Button1);
                    if (dr == DialogResult.OK)
                    {
                        MessageBox.Show("完成！修改行数：" + _db.DataDelete("use DBExperiment delete from " + _databaseNow +
                                                                    " where " + dataGridView1.Columns[2].HeaderText +
                                                                    "='" + dataGridView1.Rows[e.RowIndex].Cells[2].Value
                                                                        .ToString() + "'"));
                    }
                    break;
                }
            }
            try
            {
                var ds = _db.DataSelect("use DBExperiment select * from " + _databaseNow);
                dataGridView1.DataSource = ds.Tables[0];
            }
            catch (Exception ecp)
            {
                MessageBox.Show(ecp.ToString());
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (!_login) return;
            
            _ = new DataSet();
            try
            {
                var ds = _db.DataSelect("use DBExperiment select * from " + comboBox1.Text);
                dataGridView1.DataSource = ds.Tables[0];
                _databaseNow = comboBox1.Text;
            }
            catch (Exception ecp)
            {
                MessageBox.Show(ecp.ToString());
            }
        }
    }
}