<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class FormCustomerEntry
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.tbxName = New System.Windows.Forms.TextBox
        Me.tbxAddress = New System.Windows.Forms.TextBox
        Me.lblName = New System.Windows.Forms.Label
        Me.lblAddress = New System.Windows.Forms.Label
        Me.btnSubmit = New System.Windows.Forms.Button
        Me.lblEmail = New System.Windows.Forms.Label
        Me.tbxEmail = New System.Windows.Forms.TextBox
        Me.lblPhone = New System.Windows.Forms.Label
        Me.tbxPhone = New System.Windows.Forms.TextBox
        Me.sbStatus = New System.Windows.Forms.StatusStrip
        Me.lblProgramStatus = New System.Windows.Forms.ToolStripStatusLabel
        Me.MenuBar = New System.Windows.Forms.MenuStrip
        Me.FIleToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
        Me.ExitToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
        Me.btnReset = New System.Windows.Forms.Button
        Me.sbStatus.SuspendLayout()
        Me.MenuBar.SuspendLayout()
        Me.SuspendLayout()
        '
        'tbxName
        '
        Me.tbxName.Location = New System.Drawing.Point(113, 52)
        Me.tbxName.Name = "tbxName"
        Me.tbxName.Size = New System.Drawing.Size(175, 20)
        Me.tbxName.TabIndex = 0
        '
        'tbxAddress
        '
        Me.tbxAddress.Location = New System.Drawing.Point(113, 91)
        Me.tbxAddress.Name = "tbxAddress"
        Me.tbxAddress.Size = New System.Drawing.Size(175, 20)
        Me.tbxAddress.TabIndex = 1
        '
        'lblName
        '
        Me.lblName.AutoSize = True
        Me.lblName.Location = New System.Drawing.Point(110, 36)
        Me.lblName.Name = "lblName"
        Me.lblName.Size = New System.Drawing.Size(35, 13)
        Me.lblName.TabIndex = 2
        Me.lblName.Text = "Name"
        '
        'lblAddress
        '
        Me.lblAddress.AutoSize = True
        Me.lblAddress.Location = New System.Drawing.Point(110, 75)
        Me.lblAddress.Name = "lblAddress"
        Me.lblAddress.Size = New System.Drawing.Size(45, 13)
        Me.lblAddress.TabIndex = 3
        Me.lblAddress.Text = "Address"
        '
        'btnSubmit
        '
        Me.btnSubmit.Location = New System.Drawing.Point(113, 195)
        Me.btnSubmit.Name = "btnSubmit"
        Me.btnSubmit.Size = New System.Drawing.Size(75, 23)
        Me.btnSubmit.TabIndex = 4
        Me.btnSubmit.Text = "Submit"
        Me.btnSubmit.UseVisualStyleBackColor = True
        '
        'lblEmail
        '
        Me.lblEmail.AutoSize = True
        Me.lblEmail.Location = New System.Drawing.Point(110, 114)
        Me.lblEmail.Name = "lblEmail"
        Me.lblEmail.Size = New System.Drawing.Size(32, 13)
        Me.lblEmail.TabIndex = 6
        Me.lblEmail.Text = "Email"
        '
        'tbxEmail
        '
        Me.tbxEmail.Location = New System.Drawing.Point(113, 130)
        Me.tbxEmail.Name = "tbxEmail"
        Me.tbxEmail.Size = New System.Drawing.Size(175, 20)
        Me.tbxEmail.TabIndex = 2
        '
        'lblPhone
        '
        Me.lblPhone.AutoSize = True
        Me.lblPhone.Location = New System.Drawing.Point(110, 153)
        Me.lblPhone.Name = "lblPhone"
        Me.lblPhone.Size = New System.Drawing.Size(38, 13)
        Me.lblPhone.TabIndex = 8
        Me.lblPhone.Text = "Phone"
        '
        'tbxPhone
        '
        Me.tbxPhone.Location = New System.Drawing.Point(113, 169)
        Me.tbxPhone.MaxLength = 10
        Me.tbxPhone.Name = "tbxPhone"
        Me.tbxPhone.Size = New System.Drawing.Size(175, 20)
        Me.tbxPhone.TabIndex = 3
        '
        'sbStatus
        '
        Me.sbStatus.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.lblProgramStatus})
        Me.sbStatus.Location = New System.Drawing.Point(0, 256)
        Me.sbStatus.Name = "sbStatus"
        Me.sbStatus.Size = New System.Drawing.Size(401, 22)
        Me.sbStatus.TabIndex = 9
        Me.sbStatus.Text = "StatusStrip1"
        '
        'lblProgramStatus
        '
        Me.lblProgramStatus.Name = "lblProgramStatus"
        Me.lblProgramStatus.Size = New System.Drawing.Size(42, 17)
        Me.lblProgramStatus.Text = "Ready."
        '
        'MenuBar
        '
        Me.MenuBar.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.FIleToolStripMenuItem})
        Me.MenuBar.Location = New System.Drawing.Point(0, 0)
        Me.MenuBar.Name = "MenuBar"
        Me.MenuBar.Size = New System.Drawing.Size(401, 24)
        Me.MenuBar.TabIndex = 10
        Me.MenuBar.Text = "MenuBar"
        '
        'FIleToolStripMenuItem
        '
        Me.FIleToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.ExitToolStripMenuItem})
        Me.FIleToolStripMenuItem.Name = "FIleToolStripMenuItem"
        Me.FIleToolStripMenuItem.Size = New System.Drawing.Size(35, 20)
        Me.FIleToolStripMenuItem.Text = "File"
        '
        'ExitToolStripMenuItem
        '
        Me.ExitToolStripMenuItem.Name = "ExitToolStripMenuItem"
        Me.ExitToolStripMenuItem.Size = New System.Drawing.Size(103, 22)
        Me.ExitToolStripMenuItem.Text = "Exit"
        '
        'btnReset
        '
        Me.btnReset.Location = New System.Drawing.Point(213, 195)
        Me.btnReset.Name = "btnReset"
        Me.btnReset.Size = New System.Drawing.Size(75, 23)
        Me.btnReset.TabIndex = 5
        Me.btnReset.Text = "Reset"
        Me.btnReset.UseVisualStyleBackColor = True
        '
        'FormCustomerEntry
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(401, 278)
        Me.Controls.Add(Me.btnReset)
        Me.Controls.Add(Me.sbStatus)
        Me.Controls.Add(Me.MenuBar)
        Me.Controls.Add(Me.lblPhone)
        Me.Controls.Add(Me.tbxPhone)
        Me.Controls.Add(Me.lblEmail)
        Me.Controls.Add(Me.tbxEmail)
        Me.Controls.Add(Me.btnSubmit)
        Me.Controls.Add(Me.lblAddress)
        Me.Controls.Add(Me.lblName)
        Me.Controls.Add(Me.tbxAddress)
        Me.Controls.Add(Me.tbxName)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle
        Me.MainMenuStrip = Me.MenuBar
        Me.MaximizeBox = False
        Me.Name = "FormCustomerEntry"
        Me.Text = "Customer Entry"
        Me.sbStatus.ResumeLayout(False)
        Me.sbStatus.PerformLayout()
        Me.MenuBar.ResumeLayout(False)
        Me.MenuBar.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents tbxName As System.Windows.Forms.TextBox
    Friend WithEvents tbxAddress As System.Windows.Forms.TextBox
    Friend WithEvents lblName As System.Windows.Forms.Label
    Friend WithEvents lblAddress As System.Windows.Forms.Label
    Friend WithEvents btnSubmit As System.Windows.Forms.Button
    Friend WithEvents lblEmail As System.Windows.Forms.Label
    Friend WithEvents tbxEmail As System.Windows.Forms.TextBox
    Friend WithEvents lblPhone As System.Windows.Forms.Label
    Friend WithEvents tbxPhone As System.Windows.Forms.TextBox
    Friend WithEvents sbStatus As System.Windows.Forms.StatusStrip
    Friend WithEvents lblProgramStatus As System.Windows.Forms.ToolStripStatusLabel
    Friend WithEvents MenuBar As System.Windows.Forms.MenuStrip
    Friend WithEvents FIleToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents ExitToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents btnReset As System.Windows.Forms.Button

End Class
