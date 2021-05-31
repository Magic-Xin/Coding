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
        private DataBase db = new DataBase();
        private bool login = false;
        private string database_now = "";
        public Form1()
        {
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            if(!login && db.loginDB())
            {
                label1.Text = "数据库已登录";
                login = true;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (login && db.logoutDB())
            {
                label1.Text = "数据库已登出";
                login = false;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            _ = new DataSet();

            if (login)
            {
                try
                {
                    DataSet ds = db.DataSelect("use DBExperiment " + textBox1.Text.ToString());
                    dataGridView1.DataSource = ds.Tables[0];
                }
                catch (Exception ecp)
                {
                    MessageBox.Show(ecp.ToString());
                }
            }
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (login)
            {
                if (e.ColumnIndex == 0)
                {
                    DialogResult dr = MessageBox.Show("确认删除：" + dataGridView1.Rows[e.RowIndex].Cells[2].Value.ToString(), "确认修改", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning, MessageBoxDefaultButton.Button1);
                }
                else if (e.ColumnIndex == 1)
                {
                    DialogResult dr = MessageBox.Show("确认删除：" + dataGridView1.Rows[e.RowIndex].Cells[2].Value.ToString(), "确认删除", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning, MessageBoxDefaultButton.Button1);
                    if (dr == DialogResult.OK)
                    {
                        MessageBox.Show("完成！修改行数："+db.DataDelete("use DBExperiment delete from " + database_now + " where " + dataGridView1.Columns[2].HeaderText + "='" + dataGridView1.Rows[e.RowIndex].Cells[2].Value.ToString() + "'"));
                    }
                }
                try
                {
                    DataSet ds = db.DataSelect("use DBExperiment select * from " + database_now);
                    dataGridView1.DataSource = ds.Tables[0];
                }
                catch (Exception ecp)
                {
                    MessageBox.Show(ecp.ToString());
                }
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            _ = new DataSet();

            if (login)
            {
                try
                {
                    DataSet ds = db.DataSelect("use DBExperiment select * from " + comboBox1.Text);
                    dataGridView1.DataSource = ds.Tables[0];
                    database_now = comboBox1.Text;
                }
                catch (Exception ecp)
                {
                    MessageBox.Show(ecp.ToString());
                }
            }
        }
    }
}
