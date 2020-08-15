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
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.timeLabel = New System.Windows.Forms.Label
        Me.dateLabel = New System.Windows.Forms.Label
        Me.statusListBox = New System.Windows.Forms.ListBox
        Me.gallonsLabel = New System.Windows.Forms.Label
        Me.gallonsTextbox = New System.Windows.Forms.TextBox
        Me.priceTextbox = New System.Windows.Forms.TextBox
        Me.priceLabel = New System.Windows.Forms.Label
        Me.simTimeLabel = New System.Windows.Forms.Label
        Me.simulationTextbox = New System.Windows.Forms.TextBox
        Me.simButton = New System.Windows.Forms.Button
        Me.clearButton = New System.Windows.Forms.Button
        Me.exitButton = New System.Windows.Forms.Button
        Me.Label1 = New System.Windows.Forms.Label
        Me.SuspendLayout()
        '
        'Timer1
        '
        Me.Timer1.Enabled = True
        Me.Timer1.Interval = 1000
        '
        'timeLabel
        '
        Me.timeLabel.AutoSize = True
        Me.timeLabel.BackColor = System.Drawing.Color.Black
        Me.timeLabel.ForeColor = System.Drawing.Color.Yellow
        Me.timeLabel.Location = New System.Drawing.Point(13, 13)
        Me.timeLabel.Name = "timeLabel"
        Me.timeLabel.Size = New System.Drawing.Size(39, 13)
        Me.timeLabel.TabIndex = 0
        Me.timeLabel.Text = "Label1"
        '
        'dateLabel
        '
        Me.dateLabel.AutoSize = True
        Me.dateLabel.BackColor = System.Drawing.Color.Black
        Me.dateLabel.ForeColor = System.Drawing.Color.Yellow
        Me.dateLabel.Location = New System.Drawing.Point(124, 13)
        Me.dateLabel.Name = "dateLabel"
        Me.dateLabel.Size = New System.Drawing.Size(39, 13)
        Me.dateLabel.TabIndex = 1
        Me.dateLabel.Text = "Label2"
        '
        'statusListBox
        '
        Me.statusListBox.FormattingEnabled = True
        Me.statusListBox.Location = New System.Drawing.Point(12, 36)
        Me.statusListBox.Name = "statusListBox"
        Me.statusListBox.Size = New System.Drawing.Size(412, 433)
        Me.statusListBox.TabIndex = 2
        '
        'gallonsLabel
        '
        Me.gallonsLabel.AutoSize = True
        Me.gallonsLabel.BackColor = System.Drawing.Color.Black
        Me.gallonsLabel.ForeColor = System.Drawing.Color.White
        Me.gallonsLabel.Location = New System.Drawing.Point(441, 36)
        Me.gallonsLabel.Name = "gallonsLabel"
        Me.gallonsLabel.Size = New System.Drawing.Size(147, 13)
        Me.gallonsLabel.TabIndex = 3
        Me.gallonsLabel.Text = "Enter initial gallons in the tank"
        '
        'gallonsTextbox
        '
        Me.gallonsTextbox.Location = New System.Drawing.Point(444, 59)
        Me.gallonsTextbox.Name = "gallonsTextbox"
        Me.gallonsTextbox.Size = New System.Drawing.Size(144, 20)
        Me.gallonsTextbox.TabIndex = 4
        '
        'priceTextbox
        '
        Me.priceTextbox.Location = New System.Drawing.Point(444, 123)
        Me.priceTextbox.Name = "priceTextbox"
        Me.priceTextbox.Size = New System.Drawing.Size(144, 20)
        Me.priceTextbox.TabIndex = 5
        '
        'priceLabel
        '
        Me.priceLabel.AutoSize = True
        Me.priceLabel.BackColor = System.Drawing.Color.Black
        Me.priceLabel.ForeColor = System.Drawing.Color.White
        Me.priceLabel.Location = New System.Drawing.Point(444, 104)
        Me.priceLabel.Name = "priceLabel"
        Me.priceLabel.Size = New System.Drawing.Size(141, 13)
        Me.priceLabel.TabIndex = 6
        Me.priceLabel.Text = "Enter todays price-per-gallon"
        '
        'simTimeLabel
        '
        Me.simTimeLabel.AutoSize = True
        Me.simTimeLabel.BackColor = System.Drawing.Color.Black
        Me.simTimeLabel.ForeColor = System.Drawing.Color.White
        Me.simTimeLabel.Location = New System.Drawing.Point(444, 169)
        Me.simTimeLabel.Name = "simTimeLabel"
        Me.simTimeLabel.Size = New System.Drawing.Size(135, 13)
        Me.simTimeLabel.TabIndex = 7
        Me.simTimeLabel.Text = "Enter the simulation time in "
        '
        'simulationTextbox
        '
        Me.simulationTextbox.Location = New System.Drawing.Point(444, 202)
        Me.simulationTextbox.Name = "simulationTextbox"
        Me.simulationTextbox.Size = New System.Drawing.Size(144, 20)
        Me.simulationTextbox.TabIndex = 8
        '
        'simButton
        '
        Me.simButton.BackColor = System.Drawing.Color.Yellow
        Me.simButton.Location = New System.Drawing.Point(466, 252)
        Me.simButton.Name = "simButton"
        Me.simButton.Size = New System.Drawing.Size(75, 23)
        Me.simButton.TabIndex = 9
        Me.simButton.Text = "Simulation"
        Me.simButton.UseVisualStyleBackColor = False
        '
        'clearButton
        '
        Me.clearButton.BackColor = System.Drawing.Color.Yellow
        Me.clearButton.Location = New System.Drawing.Point(467, 281)
        Me.clearButton.Name = "clearButton"
        Me.clearButton.Size = New System.Drawing.Size(75, 23)
        Me.clearButton.TabIndex = 10
        Me.clearButton.Text = "Clear"
        Me.clearButton.UseVisualStyleBackColor = False
        '
        'exitButton
        '
        Me.exitButton.BackColor = System.Drawing.Color.Yellow
        Me.exitButton.Location = New System.Drawing.Point(467, 310)
        Me.exitButton.Name = "exitButton"
        Me.exitButton.Size = New System.Drawing.Size(75, 23)
        Me.exitButton.TabIndex = 11
        Me.exitButton.Text = "Exit"
        Me.exitButton.UseVisualStyleBackColor = False
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.BackColor = System.Drawing.Color.Black
        Me.Label1.ForeColor = System.Drawing.Color.White
        Me.Label1.Location = New System.Drawing.Point(462, 186)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(79, 13)
        Me.Label1.TabIndex = 12
        Me.Label1.Text = "minutes >= 100"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.Color.Black
        Me.ClientSize = New System.Drawing.Size(609, 481)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.exitButton)
        Me.Controls.Add(Me.clearButton)
        Me.Controls.Add(Me.simButton)
        Me.Controls.Add(Me.simulationTextbox)
        Me.Controls.Add(Me.simTimeLabel)
        Me.Controls.Add(Me.priceLabel)
        Me.Controls.Add(Me.priceTextbox)
        Me.Controls.Add(Me.gallonsTextbox)
        Me.Controls.Add(Me.gallonsLabel)
        Me.Controls.Add(Me.statusListBox)
        Me.Controls.Add(Me.dateLabel)
        Me.Controls.Add(Me.timeLabel)
        Me.Name = "Form1"
        Me.Text = "Project 3 - Spring 2010"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents timeLabel As System.Windows.Forms.Label
    Friend WithEvents dateLabel As System.Windows.Forms.Label
    Friend WithEvents statusListBox As System.Windows.Forms.ListBox
    Friend WithEvents gallonsLabel As System.Windows.Forms.Label
    Friend WithEvents gallonsTextbox As System.Windows.Forms.TextBox
    Friend WithEvents priceTextbox As System.Windows.Forms.TextBox
    Friend WithEvents priceLabel As System.Windows.Forms.Label
    Friend WithEvents simTimeLabel As System.Windows.Forms.Label
    Friend WithEvents simulationTextbox As System.Windows.Forms.TextBox
    Friend WithEvents simButton As System.Windows.Forms.Button
    Friend WithEvents clearButton As System.Windows.Forms.Button
    Friend WithEvents exitButton As System.Windows.Forms.Button
    Friend WithEvents Label1 As System.Windows.Forms.Label

End Class
