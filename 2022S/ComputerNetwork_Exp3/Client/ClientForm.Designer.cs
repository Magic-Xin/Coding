namespace Client;

partial class ClientForm
{
    /// <summary>
    ///  Required designer variable.
    /// </summary>
    private System.ComponentModel.IContainer components = null;

    /// <summary>
    ///  Clean up any resources being used.
    /// </summary>
    /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
    protected override void Dispose(bool disposing)
    {
        if (disposing && (components != null))
        {
            components.Dispose();
        }

        base.Dispose(disposing);
    }

    #region Windows Form Designer generated code

    /// <summary>
    ///  Required method for Designer support - do not modify
    ///  the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent()
    {
            this.label1 = new System.Windows.Forms.Label();
            this.stop_button = new System.Windows.Forms.Button();
            this.start_button = new System.Windows.Forms.Button();
            this.portBox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.ipBox = new System.Windows.Forms.TextBox();
            this.listBox = new System.Windows.Forms.ListBox();
            this.label2 = new System.Windows.Forms.Label();
            this.msgBox = new System.Windows.Forms.TextBox();
            this.send_button = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.nameBox = new System.Windows.Forms.TextBox();
            this.clientTextBox = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point);
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(103, 25);
            this.label1.TabIndex = 1;
            this.label1.Text = "Server IP :";
            // 
            // stop_button
            // 
            this.stop_button.Enabled = false;
            this.stop_button.Location = new System.Drawing.Point(358, 42);
            this.stop_button.Name = "stop_button";
            this.stop_button.Size = new System.Drawing.Size(102, 30);
            this.stop_button.TabIndex = 10;
            this.stop_button.Text = "Stop";
            this.stop_button.UseVisualStyleBackColor = true;
            this.stop_button.Click += new System.EventHandler(this.stop_button_Click);
            // 
            // start_button
            // 
            this.start_button.Location = new System.Drawing.Point(358, 9);
            this.start_button.Name = "start_button";
            this.start_button.Size = new System.Drawing.Size(102, 30);
            this.start_button.TabIndex = 9;
            this.start_button.Text = "Start";
            this.start_button.UseVisualStyleBackColor = true;
            this.start_button.Click += new System.EventHandler(this.start_button_Click);
            // 
            // portBox
            // 
            this.portBox.Location = new System.Drawing.Point(79, 44);
            this.portBox.MaxLength = 5;
            this.portBox.Name = "portBox";
            this.portBox.Size = new System.Drawing.Size(100, 23);
            this.portBox.TabIndex = 12;
            this.portBox.Text = "11451";
            this.portBox.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.portBox_KeyPress);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point);
            this.label3.Location = new System.Drawing.Point(12, 42);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(61, 25);
            this.label3.TabIndex = 11;
            this.label3.Text = "Port :";
            // 
            // ipBox
            // 
            this.ipBox.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.ipBox.Location = new System.Drawing.Point(121, 14);
            this.ipBox.MaxLength = 5;
            this.ipBox.Name = "ipBox";
            this.ipBox.Size = new System.Drawing.Size(130, 23);
            this.ipBox.TabIndex = 13;
            this.ipBox.Text = "127.0.0.1";
            // 
            // listBox
            // 
            this.listBox.Enabled = false;
            this.listBox.FormattingEnabled = true;
            this.listBox.ItemHeight = 15;
            this.listBox.Items.AddRange(new object[] {
            "ALL"});
            this.listBox.Location = new System.Drawing.Point(358, 108);
            this.listBox.Name = "listBox";
            this.listBox.Size = new System.Drawing.Size(102, 289);
            this.listBox.TabIndex = 15;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point);
            this.label2.Location = new System.Drawing.Point(355, 76);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(106, 21);
            this.label2.TabIndex = 16;
            this.label2.Text = "Online Users";
            // 
            // msgBox
            // 
            this.msgBox.Location = new System.Drawing.Point(12, 414);
            this.msgBox.Name = "msgBox";
            this.msgBox.Size = new System.Drawing.Size(340, 23);
            this.msgBox.TabIndex = 17;
            this.msgBox.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.msgBox_KeyPress);
            // 
            // send_button
            // 
            this.send_button.Enabled = false;
            this.send_button.Location = new System.Drawing.Point(358, 409);
            this.send_button.Name = "send_button";
            this.send_button.Size = new System.Drawing.Size(102, 30);
            this.send_button.TabIndex = 18;
            this.send_button.Text = "Send";
            this.send_button.UseVisualStyleBackColor = true;
            this.send_button.Click += new System.EventHandler(this.send_button_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point);
            this.label4.Location = new System.Drawing.Point(12, 72);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(111, 25);
            this.label4.TabIndex = 19;
            this.label4.Text = "Nickname :";
            // 
            // nameBox
            // 
            this.nameBox.Location = new System.Drawing.Point(129, 74);
            this.nameBox.MaxLength = 20;
            this.nameBox.Name = "nameBox";
            this.nameBox.Size = new System.Drawing.Size(100, 23);
            this.nameBox.TabIndex = 20;
            this.nameBox.Text = "Anonymouse";
            // 
            // clientTextBox
            // 
            this.clientTextBox.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.clientTextBox.Location = new System.Drawing.Point(15, 108);
            this.clientTextBox.Name = "clientTextBox";
            this.clientTextBox.ReadOnly = true;
            this.clientTextBox.Size = new System.Drawing.Size(334, 289);
            this.clientTextBox.TabIndex = 22;
            this.clientTextBox.Text = "";
            // 
            // ClientForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(472, 449);
            this.Controls.Add(this.clientTextBox);
            this.Controls.Add(this.nameBox);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.send_button);
            this.Controls.Add(this.msgBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.listBox);
            this.Controls.Add(this.ipBox);
            this.Controls.Add(this.portBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.stop_button);
            this.Controls.Add(this.start_button);
            this.Controls.Add(this.label1);
            this.Name = "ClientForm";
            this.Text = "Client";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.ClientForm_FormClosed);
            this.ResumeLayout(false);
            this.PerformLayout();

    }

    #endregion

    private Label label1;
    private Button stop_button;
    private Button start_button;
    private TextBox portBox;
    private Label label3;
    private TextBox ipBox;
    private ListBox listBox;
    private Label label2;
    private TextBox msgBox;
    private Button send_button;
    private Label label4;
    private TextBox nameBox;
    private RichTextBox clientTextBox;
}