namespace Server;

partial class ServerForm
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
            this.ip_label = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.portBox = new System.Windows.Forms.TextBox();
            this.start_button = new System.Windows.Forms.Button();
            this.clear_button = new System.Windows.Forms.Button();
            this.stop_button = new System.Windows.Forms.Button();
            this.serverTextBox = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point);
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(103, 25);
            this.label1.TabIndex = 0;
            this.label1.Text = "Server IP :";
            // 
            // ip_label
            // 
            this.ip_label.AutoSize = true;
            this.ip_label.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.ip_label.Location = new System.Drawing.Point(121, 9);
            this.ip_label.Name = "ip_label";
            this.ip_label.Size = new System.Drawing.Size(144, 25);
            this.ip_label.TabIndex = 1;
            this.ip_label.Text = "255.255.255.255";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point);
            this.label3.Location = new System.Drawing.Point(12, 47);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(61, 25);
            this.label3.TabIndex = 2;
            this.label3.Text = "Port :";
            // 
            // portBox
            // 
            this.portBox.Location = new System.Drawing.Point(79, 49);
            this.portBox.MaxLength = 5;
            this.portBox.Name = "portBox";
            this.portBox.Size = new System.Drawing.Size(100, 23);
            this.portBox.TabIndex = 3;
            this.portBox.Text = "11451";
            this.portBox.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.portBox_KeyPress);
            // 
            // start_button
            // 
            this.start_button.Location = new System.Drawing.Point(358, 9);
            this.start_button.Name = "start_button";
            this.start_button.Size = new System.Drawing.Size(102, 30);
            this.start_button.TabIndex = 4;
            this.start_button.Text = "Start";
            this.start_button.UseVisualStyleBackColor = true;
            this.start_button.Click += new System.EventHandler(this.start_button_Click);
            // 
            // clear_button
            // 
            this.clear_button.Location = new System.Drawing.Point(358, 407);
            this.clear_button.Name = "clear_button";
            this.clear_button.Size = new System.Drawing.Size(102, 30);
            this.clear_button.TabIndex = 6;
            this.clear_button.Text = "Clear";
            this.clear_button.UseVisualStyleBackColor = true;
            this.clear_button.Click += new System.EventHandler(this.clear_button_Click);
            // 
            // stop_button
            // 
            this.stop_button.Enabled = false;
            this.stop_button.Location = new System.Drawing.Point(358, 42);
            this.stop_button.Name = "stop_button";
            this.stop_button.Size = new System.Drawing.Size(102, 30);
            this.stop_button.TabIndex = 8;
            this.stop_button.Text = "Stop";
            this.stop_button.UseVisualStyleBackColor = true;
            this.stop_button.Click += new System.EventHandler(this.stop_button_Click);
            // 
            // serverTextBox
            // 
            this.serverTextBox.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.serverTextBox.Location = new System.Drawing.Point(12, 78);
            this.serverTextBox.Name = "serverTextBox";
            this.serverTextBox.ReadOnly = true;
            this.serverTextBox.Size = new System.Drawing.Size(448, 323);
            this.serverTextBox.TabIndex = 23;
            this.serverTextBox.Text = "";
            // 
            // ServerForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(472, 449);
            this.Controls.Add(this.serverTextBox);
            this.Controls.Add(this.stop_button);
            this.Controls.Add(this.clear_button);
            this.Controls.Add(this.start_button);
            this.Controls.Add(this.portBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.ip_label);
            this.Controls.Add(this.label1);
            this.Name = "ServerForm";
            this.Text = "Server";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.ServerForm_FormClosed);
            this.ResumeLayout(false);
            this.PerformLayout();

    }

    #endregion

    private Label label1;
    private Label ip_label;
    private Label label3;
    private TextBox portBox;
    private Button start_button;
    private Button clear_button;
    private Button stop_button;
    private RichTextBox serverTextBox;
}