<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmCustEntry
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
        Me.lblName = New System.Windows.Forms.Label
        Me.lblAddress = New System.Windows.Forms.Label
        Me.lblEmail = New System.Windows.Forms.Label
        Me.lblPhone = New System.Windows.Forms.Label
        Me.tbxName = New System.Windows.Forms.TextBox
        Me.tbxAddress = New System.Windows.Forms.TextBox
        Me.tbxEmail = New System.Windows.Forms.TextBox
        Me.tbxPhone = New System.Windows.Forms.TextBox
        Me.btnSave = New System.Windows.Forms.Button
        Me.SuspendLayout()
        '
        'lblName
        '
        Me.lblName.AutoSize = True
        Me.lblName.Font = New System.Drawing.Font("Tahoma", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblName.Location = New System.Drawing.Point(32, 25)
        Me.lblName.Name = "lblName"
        Me.lblName.Size = New System.Drawing.Size(56, 19)
        Me.lblName.TabIndex = 0
        Me.lblName.Text = "Name:"
        Me.lblName.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblAddress
        '
        Me.lblAddress.AutoSize = True
        Me.lblAddress.Font = New System.Drawing.Font("Tahoma", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblAddress.Location = New System.Drawing.Point(16, 64)
        Me.lblAddress.Name = "lblAddress"
        Me.lblAddress.Size = New System.Drawing.Size(72, 19)
        Me.lblAddress.TabIndex = 1
        Me.lblAddress.Text = "Address:"
        Me.lblAddress.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblEmail
        '
        Me.lblEmail.AutoSize = True
        Me.lblEmail.Font = New System.Drawing.Font("Tahoma", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblEmail.Location = New System.Drawing.Point(34, 107)
        Me.lblEmail.Name = "lblEmail"
        Me.lblEmail.Size = New System.Drawing.Size(54, 19)
        Me.lblEmail.TabIndex = 2
        Me.lblEmail.Text = "Email:"
        Me.lblEmail.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblPhone
        '
        Me.lblPhone.AutoSize = True
        Me.lblPhone.Font = New System.Drawing.Font("Tahoma", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblPhone.Location = New System.Drawing.Point(29, 145)
        Me.lblPhone.Name = "lblPhone"
        Me.lblPhone.Size = New System.Drawing.Size(59, 19)
        Me.lblPhone.TabIndex = 3
        Me.lblPhone.Text = "Phone:"
        Me.lblPhone.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'tbxName
        '
        Me.tbxName.Location = New System.Drawing.Point(83, 24)
        Me.tbxName.Name = "tbxName"
        Me.tbxName.Size = New System.Drawing.Size(145, 20)
        Me.tbxName.TabIndex = 4
        '
        'tbxAddress
        '
        Me.tbxAddress.Location = New System.Drawing.Point(83, 63)
        Me.tbxAddress.Name = "tbxAddress"
        Me.tbxAddress.Size = New System.Drawing.Size(145, 20)
        Me.tbxAddress.TabIndex = 5
        '
        'tbxEmail
        '
        Me.tbxEmail.Location = New System.Drawing.Point(83, 106)
        Me.tbxEmail.Name = "tbxEmail"
        Me.tbxEmail.Size = New System.Drawing.Size(145, 20)
        Me.tbxEmail.TabIndex = 6
        '
        'tbxPhone
        '
        Me.tbxPhone.Location = New System.Drawing.Point(83, 144)
        Me.tbxPhone.Name = "tbxPhone"
        Me.tbxPhone.Size = New System.Drawing.Size(145, 20)
        Me.tbxPhone.TabIndex = 7
        '
        'btnSave
        '
        Me.btnSave.Location = New System.Drawing.Point(83, 196)
        Me.btnSave.Name = "btnSave"
        Me.btnSave.Size = New System.Drawing.Size(145, 32)
        Me.btnSave.TabIndex = 8
        Me.btnSave.Text = "Save"
        Me.btnSave.UseVisualStyleBackColor = True
        '
        'frmCustEntry
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(277, 281)
        Me.Controls.Add(Me.btnSave)
        Me.Controls.Add(Me.tbxPhone)
        Me.Controls.Add(Me.tbxEmail)
        Me.Controls.Add(Me.tbxAddress)
        Me.Controls.Add(Me.tbxName)
        Me.Controls.Add(Me.lblPhone)
        Me.Controls.Add(Me.lblEmail)
        Me.Controls.Add(Me.lblAddress)
        Me.Controls.Add(Me.lblName)
        Me.Name = "frmCustEntry"
        Me.Text = "Customer Entry"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents lblName As System.Windows.Forms.Label
    Friend WithEvents lblAddress As System.Windows.Forms.Label
    Friend WithEvents lblEmail As System.Windows.Forms.Label
    Friend WithEvents lblPhone As System.Windows.Forms.Label
    Friend WithEvents tbxName As System.Windows.Forms.TextBox
    Friend WithEvents tbxAddress As System.Windows.Forms.TextBox
    Friend WithEvents tbxEmail As System.Windows.Forms.TextBox
    Friend WithEvents tbxPhone As System.Windows.Forms.TextBox
    Friend WithEvents btnSave As System.Windows.Forms.Button

End Class
