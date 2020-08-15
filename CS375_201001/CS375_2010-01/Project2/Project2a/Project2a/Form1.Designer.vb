<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
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
        Me.ListBox1 = New System.Windows.Forms.ListBox
        Me.ListBox2 = New System.Windows.Forms.ListBox
        Me.btnResults = New System.Windows.Forms.Button
        Me.btnClear = New System.Windows.Forms.Button
        Me.btnWrite = New System.Windows.Forms.Button
        Me.btnExit = New System.Windows.Forms.Button
        Me.labelDate = New System.Windows.Forms.Label
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.labelTime = New System.Windows.Forms.Label
        Me.SuspendLayout()
        '
        'ListBox1
        '
        Me.ListBox1.FormattingEnabled = True
        Me.ListBox1.Location = New System.Drawing.Point(12, 12)
        Me.ListBox1.Name = "ListBox1"
        Me.ListBox1.Size = New System.Drawing.Size(347, 485)
        Me.ListBox1.TabIndex = 0
        '
        'ListBox2
        '
        Me.ListBox2.FormattingEnabled = True
        Me.ListBox2.Location = New System.Drawing.Point(365, 233)
        Me.ListBox2.Name = "ListBox2"
        Me.ListBox2.Size = New System.Drawing.Size(360, 264)
        Me.ListBox2.TabIndex = 1
        '
        'btnResults
        '
        Me.btnResults.BackColor = System.Drawing.Color.Green
        Me.btnResults.ForeColor = System.Drawing.Color.White
        Me.btnResults.Location = New System.Drawing.Point(382, 12)
        Me.btnResults.Name = "btnResults"
        Me.btnResults.Size = New System.Drawing.Size(75, 23)
        Me.btnResults.TabIndex = 2
        Me.btnResults.Text = "Results"
        Me.btnResults.UseVisualStyleBackColor = False
        '
        'btnClear
        '
        Me.btnClear.BackColor = System.Drawing.Color.Green
        Me.btnClear.ForeColor = System.Drawing.Color.White
        Me.btnClear.Location = New System.Drawing.Point(544, 12)
        Me.btnClear.Name = "btnClear"
        Me.btnClear.Size = New System.Drawing.Size(75, 23)
        Me.btnClear.TabIndex = 3
        Me.btnClear.Text = "Clear"
        Me.btnClear.UseVisualStyleBackColor = False
        '
        'btnWrite
        '
        Me.btnWrite.BackColor = System.Drawing.Color.Green
        Me.btnWrite.ForeColor = System.Drawing.Color.White
        Me.btnWrite.Location = New System.Drawing.Point(463, 12)
        Me.btnWrite.Name = "btnWrite"
        Me.btnWrite.Size = New System.Drawing.Size(75, 23)
        Me.btnWrite.TabIndex = 4
        Me.btnWrite.Text = "Write"
        Me.btnWrite.UseVisualStyleBackColor = False
        '
        'btnExit
        '
        Me.btnExit.BackColor = System.Drawing.Color.Green
        Me.btnExit.ForeColor = System.Drawing.Color.White
        Me.btnExit.Location = New System.Drawing.Point(625, 12)
        Me.btnExit.Name = "btnExit"
        Me.btnExit.Size = New System.Drawing.Size(75, 23)
        Me.btnExit.TabIndex = 5
        Me.btnExit.Text = "Exit"
        Me.btnExit.UseVisualStyleBackColor = False
        '
        'labelDate
        '
        Me.labelDate.AutoSize = True
        Me.labelDate.BackColor = System.Drawing.Color.White
        Me.labelDate.Location = New System.Drawing.Point(379, 75)
        Me.labelDate.Name = "labelDate"
        Me.labelDate.Size = New System.Drawing.Size(52, 13)
        Me.labelDate.TabIndex = 8
        Me.labelDate.Text = "labelDate"
        '
        'Timer1
        '
        Me.Timer1.Enabled = True
        Me.Timer1.Interval = 1000
        '
        'labelTime
        '
        Me.labelTime.AutoSize = True
        Me.labelTime.BackColor = System.Drawing.Color.White
        Me.labelTime.Location = New System.Drawing.Point(379, 105)
        Me.labelTime.Name = "labelTime"
        Me.labelTime.Size = New System.Drawing.Size(52, 13)
        Me.labelTime.TabIndex = 9
        Me.labelTime.Text = "labelTime"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.Color.Black
        Me.ClientSize = New System.Drawing.Size(741, 506)
        Me.Controls.Add(Me.labelTime)
        Me.Controls.Add(Me.labelDate)
        Me.Controls.Add(Me.btnExit)
        Me.Controls.Add(Me.btnWrite)
        Me.Controls.Add(Me.btnClear)
        Me.Controls.Add(Me.btnResults)
        Me.Controls.Add(Me.ListBox2)
        Me.Controls.Add(Me.ListBox1)
        Me.Name = "Form1"
        Me.Text = "Project 2 - Spring 2010"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents ListBox1 As System.Windows.Forms.ListBox
    Friend WithEvents ListBox2 As System.Windows.Forms.ListBox
    Friend WithEvents btnResults As System.Windows.Forms.Button
    Friend WithEvents btnClear As System.Windows.Forms.Button
    Friend WithEvents btnWrite As System.Windows.Forms.Button
    Friend WithEvents btnExit As System.Windows.Forms.Button
    Friend WithEvents labelDate As System.Windows.Forms.Label
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents labelTime As System.Windows.Forms.Label

End Class
