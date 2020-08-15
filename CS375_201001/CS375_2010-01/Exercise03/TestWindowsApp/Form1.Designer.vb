<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmBackpack
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
        Me.components = New System.ComponentModel.Container
        Me.txtType = New System.Windows.Forms.TextBox
        Me.txtHeight = New System.Windows.Forms.TextBox
        Me.lstOut = New System.Windows.Forms.ListBox
        Me.tmr1 = New System.Windows.Forms.Timer(Me.components)
        Me.btnCompute = New System.Windows.Forms.Button
        Me.btnExit = New System.Windows.Forms.Button
        Me.btnClear = New System.Windows.Forms.Button
        Me.lblTimer = New System.Windows.Forms.TextBox
        Me.lstInput = New System.Windows.Forms.ListBox
        Me.Label1 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label3 = New System.Windows.Forms.Label
        Me.SuspendLayout()
        '
        'txtType
        '
        Me.txtType.Location = New System.Drawing.Point(29, 87)
        Me.txtType.Name = "txtType"
        Me.txtType.Size = New System.Drawing.Size(100, 20)
        Me.txtType.TabIndex = 0
        Me.txtType.Text = "txtType"
        '
        'txtHeight
        '
        Me.txtHeight.Location = New System.Drawing.Point(135, 86)
        Me.txtHeight.Name = "txtHeight"
        Me.txtHeight.Size = New System.Drawing.Size(100, 20)
        Me.txtHeight.TabIndex = 1
        Me.txtHeight.Text = "txtHeight"
        '
        'lstOut
        '
        Me.lstOut.FormattingEnabled = True
        Me.lstOut.Location = New System.Drawing.Point(12, 188)
        Me.lstOut.Name = "lstOut"
        Me.lstOut.Size = New System.Drawing.Size(470, 277)
        Me.lstOut.TabIndex = 2
        '
        'tmr1
        '
        Me.tmr1.Enabled = True
        Me.tmr1.Interval = 1000
        '
        'btnCompute
        '
        Me.btnCompute.Location = New System.Drawing.Point(389, 48)
        Me.btnCompute.Name = "btnCompute"
        Me.btnCompute.Size = New System.Drawing.Size(75, 23)
        Me.btnCompute.TabIndex = 3
        Me.btnCompute.Text = "Compute"
        Me.btnCompute.UseVisualStyleBackColor = True
        '
        'btnExit
        '
        Me.btnExit.Location = New System.Drawing.Point(389, 115)
        Me.btnExit.Name = "btnExit"
        Me.btnExit.Size = New System.Drawing.Size(75, 23)
        Me.btnExit.TabIndex = 4
        Me.btnExit.Text = "Exit"
        Me.btnExit.UseVisualStyleBackColor = True
        '
        'btnClear
        '
        Me.btnClear.Location = New System.Drawing.Point(389, 83)
        Me.btnClear.Name = "btnClear"
        Me.btnClear.Size = New System.Drawing.Size(75, 23)
        Me.btnClear.TabIndex = 5
        Me.btnClear.Text = "Clear"
        Me.btnClear.UseVisualStyleBackColor = True
        '
        'lblTimer
        '
        Me.lblTimer.Location = New System.Drawing.Point(29, 12)
        Me.lblTimer.Name = "lblTimer"
        Me.lblTimer.Size = New System.Drawing.Size(100, 20)
        Me.lblTimer.TabIndex = 6
        Me.lblTimer.Text = "lblTimer"
        '
        'lstInput
        '
        Me.lstInput.FormattingEnabled = True
        Me.lstInput.Location = New System.Drawing.Point(242, 87)
        Me.lstInput.Name = "lstInput"
        Me.lstInput.Size = New System.Drawing.Size(120, 95)
        Me.lstInput.TabIndex = 7
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(29, 68)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(51, 13)
        Me.Label1.TabIndex = 8
        Me.Label1.Text = "Ball Type"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(132, 68)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(38, 13)
        Me.Label2.TabIndex = 9
        Me.Label2.Text = "Height"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(239, 68)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(66, 13)
        Me.Label3.TabIndex = 10
        Me.Label3.Text = "Ball Selector"
        '
        'frmBackpack
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(493, 477)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.lstInput)
        Me.Controls.Add(Me.lblTimer)
        Me.Controls.Add(Me.btnClear)
        Me.Controls.Add(Me.btnExit)
        Me.Controls.Add(Me.btnCompute)
        Me.Controls.Add(Me.lstOut)
        Me.Controls.Add(Me.txtHeight)
        Me.Controls.Add(Me.txtType)
        Me.Name = "frmBackpack"
        Me.Text = "Example #3"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents txtType As System.Windows.Forms.TextBox
    Friend WithEvents txtHeight As System.Windows.Forms.TextBox
    Friend WithEvents lstOut As System.Windows.Forms.ListBox
    Friend WithEvents tmr1 As System.Windows.Forms.Timer
    Friend WithEvents btnCompute As System.Windows.Forms.Button
    Friend WithEvents btnExit As System.Windows.Forms.Button
    Friend WithEvents btnClear As System.Windows.Forms.Button
    Friend WithEvents lblTimer As System.Windows.Forms.TextBox
    Friend WithEvents lstInput As System.Windows.Forms.ListBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label

End Class
