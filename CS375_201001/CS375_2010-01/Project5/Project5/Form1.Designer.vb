<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class project5
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(project5))
        Me.dateDisplay_Label = New System.Windows.Forms.Label
        Me.timeDisplay_Label = New System.Windows.Forms.Label
        Me.addPurchase_Button = New System.Windows.Forms.Button
        Me.reset_Button = New System.Windows.Forms.Button
        Me.removeItem_Button = New System.Windows.Forms.Button
        Me.exit_Button = New System.Windows.Forms.Button
        Me.choice_DisplayLabel = New System.Windows.Forms.Label
        Me.quantity_DisplayLabel = New System.Windows.Forms.Label
        Me.quantity_Textbox = New System.Windows.Forms.TextBox
        Me.availProducts_ListBox = New System.Windows.Forms.ListBox
        Me.product_ListBox = New System.Windows.Forms.ListBox
        Me.quantity_ListBox = New System.Windows.Forms.ListBox
        Me.price_ListBox = New System.Windows.Forms.ListBox
        Me.extPrice_Listbox = New System.Windows.Forms.ListBox
        Me.product_DisplayLabel = New System.Windows.Forms.Label
        Me.quantity2_DisplayLabel = New System.Windows.Forms.Label
        Me.price_DisplayLabel = New System.Windows.Forms.Label
        Me.extPrice_DisplayLabel = New System.Windows.Forms.Label
        Me.tax_ListBox = New System.Windows.Forms.ListBox
        Me.tax_DisplayLabel = New System.Windows.Forms.Label
        Me.totalCost_DisplayLabel = New System.Windows.Forms.Label
        Me.totalCost_Label = New System.Windows.Forms.Label
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.PictureBox1 = New System.Windows.Forms.PictureBox
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'dateDisplay_Label
        '
        Me.dateDisplay_Label.AutoSize = True
        Me.dateDisplay_Label.Location = New System.Drawing.Point(13, 13)
        Me.dateDisplay_Label.Name = "dateDisplay_Label"
        Me.dateDisplay_Label.Size = New System.Drawing.Size(67, 13)
        Me.dateDisplay_Label.TabIndex = 0
        Me.dateDisplay_Label.Text = "Date Display"
        '
        'timeDisplay_Label
        '
        Me.timeDisplay_Label.AutoSize = True
        Me.timeDisplay_Label.Location = New System.Drawing.Point(180, 12)
        Me.timeDisplay_Label.Name = "timeDisplay_Label"
        Me.timeDisplay_Label.Size = New System.Drawing.Size(67, 13)
        Me.timeDisplay_Label.TabIndex = 1
        Me.timeDisplay_Label.Text = "Time Display"
        '
        'addPurchase_Button
        '
        Me.addPurchase_Button.BackColor = System.Drawing.Color.YellowGreen
        Me.addPurchase_Button.Location = New System.Drawing.Point(396, 13)
        Me.addPurchase_Button.Name = "addPurchase_Button"
        Me.addPurchase_Button.Size = New System.Drawing.Size(75, 38)
        Me.addPurchase_Button.TabIndex = 2
        Me.addPurchase_Button.Text = "Add Purchase"
        Me.addPurchase_Button.UseVisualStyleBackColor = False
        '
        'reset_Button
        '
        Me.reset_Button.BackColor = System.Drawing.Color.YellowGreen
        Me.reset_Button.Location = New System.Drawing.Point(396, 57)
        Me.reset_Button.Name = "reset_Button"
        Me.reset_Button.Size = New System.Drawing.Size(75, 38)
        Me.reset_Button.TabIndex = 3
        Me.reset_Button.Text = "Reset"
        Me.reset_Button.UseVisualStyleBackColor = False
        '
        'removeItem_Button
        '
        Me.removeItem_Button.BackColor = System.Drawing.Color.YellowGreen
        Me.removeItem_Button.Location = New System.Drawing.Point(396, 101)
        Me.removeItem_Button.Name = "removeItem_Button"
        Me.removeItem_Button.Size = New System.Drawing.Size(75, 38)
        Me.removeItem_Button.TabIndex = 4
        Me.removeItem_Button.Text = "Remove Item"
        Me.removeItem_Button.UseVisualStyleBackColor = False
        '
        'exit_Button
        '
        Me.exit_Button.BackColor = System.Drawing.Color.YellowGreen
        Me.exit_Button.Location = New System.Drawing.Point(396, 145)
        Me.exit_Button.Name = "exit_Button"
        Me.exit_Button.Size = New System.Drawing.Size(75, 38)
        Me.exit_Button.TabIndex = 5
        Me.exit_Button.Text = "Exit"
        Me.exit_Button.UseVisualStyleBackColor = False
        '
        'choice_DisplayLabel
        '
        Me.choice_DisplayLabel.AutoSize = True
        Me.choice_DisplayLabel.Location = New System.Drawing.Point(24, 45)
        Me.choice_DisplayLabel.Name = "choice_DisplayLabel"
        Me.choice_DisplayLabel.Size = New System.Drawing.Size(158, 13)
        Me.choice_DisplayLabel.TabIndex = 6
        Me.choice_DisplayLabel.Text = "Please Click Your Choice Below"
        '
        'quantity_DisplayLabel
        '
        Me.quantity_DisplayLabel.AutoSize = True
        Me.quantity_DisplayLabel.Location = New System.Drawing.Point(247, 45)
        Me.quantity_DisplayLabel.Name = "quantity_DisplayLabel"
        Me.quantity_DisplayLabel.Size = New System.Drawing.Size(46, 13)
        Me.quantity_DisplayLabel.TabIndex = 7
        Me.quantity_DisplayLabel.Text = "Quantity"
        '
        'quantity_Textbox
        '
        Me.quantity_Textbox.BackColor = System.Drawing.Color.Orange
        Me.quantity_Textbox.Location = New System.Drawing.Point(238, 62)
        Me.quantity_Textbox.Name = "quantity_Textbox"
        Me.quantity_Textbox.Size = New System.Drawing.Size(65, 20)
        Me.quantity_Textbox.TabIndex = 8
        '
        'availProducts_ListBox
        '
        Me.availProducts_ListBox.BackColor = System.Drawing.Color.Orange
        Me.availProducts_ListBox.FormattingEnabled = True
        Me.availProducts_ListBox.Location = New System.Drawing.Point(16, 62)
        Me.availProducts_ListBox.Name = "availProducts_ListBox"
        Me.availProducts_ListBox.Size = New System.Drawing.Size(176, 95)
        Me.availProducts_ListBox.TabIndex = 9
        '
        'product_ListBox
        '
        Me.product_ListBox.BackColor = System.Drawing.Color.Orange
        Me.product_ListBox.FormattingEnabled = True
        Me.product_ListBox.Location = New System.Drawing.Point(11, 216)
        Me.product_ListBox.Name = "product_ListBox"
        Me.product_ListBox.Size = New System.Drawing.Size(120, 95)
        Me.product_ListBox.TabIndex = 10
        '
        'quantity_ListBox
        '
        Me.quantity_ListBox.BackColor = System.Drawing.Color.Orange
        Me.quantity_ListBox.FormattingEnabled = True
        Me.quantity_ListBox.Location = New System.Drawing.Point(137, 216)
        Me.quantity_ListBox.Name = "quantity_ListBox"
        Me.quantity_ListBox.Size = New System.Drawing.Size(50, 95)
        Me.quantity_ListBox.TabIndex = 11
        '
        'price_ListBox
        '
        Me.price_ListBox.BackColor = System.Drawing.Color.Orange
        Me.price_ListBox.FormattingEnabled = True
        Me.price_ListBox.Location = New System.Drawing.Point(193, 216)
        Me.price_ListBox.Name = "price_ListBox"
        Me.price_ListBox.Size = New System.Drawing.Size(73, 95)
        Me.price_ListBox.TabIndex = 12
        '
        'extPrice_Listbox
        '
        Me.extPrice_Listbox.BackColor = System.Drawing.Color.Orange
        Me.extPrice_Listbox.FormattingEnabled = True
        Me.extPrice_Listbox.Location = New System.Drawing.Point(272, 216)
        Me.extPrice_Listbox.Name = "extPrice_Listbox"
        Me.extPrice_Listbox.Size = New System.Drawing.Size(64, 95)
        Me.extPrice_Listbox.TabIndex = 13
        '
        'product_DisplayLabel
        '
        Me.product_DisplayLabel.AutoSize = True
        Me.product_DisplayLabel.Location = New System.Drawing.Point(44, 200)
        Me.product_DisplayLabel.Name = "product_DisplayLabel"
        Me.product_DisplayLabel.Size = New System.Drawing.Size(44, 13)
        Me.product_DisplayLabel.TabIndex = 14
        Me.product_DisplayLabel.Text = "Product"
        '
        'quantity2_DisplayLabel
        '
        Me.quantity2_DisplayLabel.AutoSize = True
        Me.quantity2_DisplayLabel.Location = New System.Drawing.Point(141, 200)
        Me.quantity2_DisplayLabel.Name = "quantity2_DisplayLabel"
        Me.quantity2_DisplayLabel.Size = New System.Drawing.Size(46, 13)
        Me.quantity2_DisplayLabel.TabIndex = 15
        Me.quantity2_DisplayLabel.Text = "Quantity"
        '
        'price_DisplayLabel
        '
        Me.price_DisplayLabel.AutoSize = True
        Me.price_DisplayLabel.Location = New System.Drawing.Point(215, 200)
        Me.price_DisplayLabel.Name = "price_DisplayLabel"
        Me.price_DisplayLabel.Size = New System.Drawing.Size(31, 13)
        Me.price_DisplayLabel.TabIndex = 16
        Me.price_DisplayLabel.Text = "Price"
        '
        'extPrice_DisplayLabel
        '
        Me.extPrice_DisplayLabel.AutoSize = True
        Me.extPrice_DisplayLabel.Location = New System.Drawing.Point(281, 200)
        Me.extPrice_DisplayLabel.Name = "extPrice_DisplayLabel"
        Me.extPrice_DisplayLabel.Size = New System.Drawing.Size(52, 13)
        Me.extPrice_DisplayLabel.TabIndex = 17
        Me.extPrice_DisplayLabel.Text = "Ext. Price"
        '
        'tax_ListBox
        '
        Me.tax_ListBox.BackColor = System.Drawing.Color.Orange
        Me.tax_ListBox.FormattingEnabled = True
        Me.tax_ListBox.Location = New System.Drawing.Point(342, 216)
        Me.tax_ListBox.Name = "tax_ListBox"
        Me.tax_ListBox.Size = New System.Drawing.Size(64, 95)
        Me.tax_ListBox.TabIndex = 18
        '
        'tax_DisplayLabel
        '
        Me.tax_DisplayLabel.AutoSize = True
        Me.tax_DisplayLabel.Location = New System.Drawing.Point(351, 200)
        Me.tax_DisplayLabel.Name = "tax_DisplayLabel"
        Me.tax_DisplayLabel.Size = New System.Drawing.Size(25, 13)
        Me.tax_DisplayLabel.TabIndex = 19
        Me.tax_DisplayLabel.Text = "Tax"
        '
        'totalCost_DisplayLabel
        '
        Me.totalCost_DisplayLabel.AutoSize = True
        Me.totalCost_DisplayLabel.Location = New System.Drawing.Point(430, 232)
        Me.totalCost_DisplayLabel.Name = "totalCost_DisplayLabel"
        Me.totalCost_DisplayLabel.Size = New System.Drawing.Size(55, 13)
        Me.totalCost_DisplayLabel.TabIndex = 20
        Me.totalCost_DisplayLabel.Text = "Total Cost"
        '
        'totalCost_Label
        '
        Me.totalCost_Label.AutoSize = True
        Me.totalCost_Label.Location = New System.Drawing.Point(430, 257)
        Me.totalCost_Label.Name = "totalCost_Label"
        Me.totalCost_Label.Size = New System.Drawing.Size(34, 13)
        Me.totalCost_Label.TabIndex = 21
        Me.totalCost_Label.Text = "$0.00"
        '
        'Timer1
        '
        Me.Timer1.Enabled = True
        Me.Timer1.Interval = 1000
        '
        'PictureBox1
        '
        Me.PictureBox1.Image = CType(resources.GetObject("PictureBox1.Image"), System.Drawing.Image)
        Me.PictureBox1.Location = New System.Drawing.Point(238, 92)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(104, 91)
        Me.PictureBox1.TabIndex = 22
        Me.PictureBox1.TabStop = False
        '
        'project5
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.Color.Yellow
        Me.ClientSize = New System.Drawing.Size(519, 335)
        Me.Controls.Add(Me.PictureBox1)
        Me.Controls.Add(Me.totalCost_Label)
        Me.Controls.Add(Me.totalCost_DisplayLabel)
        Me.Controls.Add(Me.tax_DisplayLabel)
        Me.Controls.Add(Me.tax_ListBox)
        Me.Controls.Add(Me.extPrice_DisplayLabel)
        Me.Controls.Add(Me.price_DisplayLabel)
        Me.Controls.Add(Me.quantity2_DisplayLabel)
        Me.Controls.Add(Me.product_DisplayLabel)
        Me.Controls.Add(Me.extPrice_Listbox)
        Me.Controls.Add(Me.price_ListBox)
        Me.Controls.Add(Me.quantity_ListBox)
        Me.Controls.Add(Me.product_ListBox)
        Me.Controls.Add(Me.availProducts_ListBox)
        Me.Controls.Add(Me.quantity_Textbox)
        Me.Controls.Add(Me.quantity_DisplayLabel)
        Me.Controls.Add(Me.choice_DisplayLabel)
        Me.Controls.Add(Me.exit_Button)
        Me.Controls.Add(Me.removeItem_Button)
        Me.Controls.Add(Me.reset_Button)
        Me.Controls.Add(Me.addPurchase_Button)
        Me.Controls.Add(Me.timeDisplay_Label)
        Me.Controls.Add(Me.dateDisplay_Label)
        Me.Name = "project5"
        Me.Text = "Project 5 - CS 375 - "
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents dateDisplay_Label As System.Windows.Forms.Label
    Friend WithEvents timeDisplay_Label As System.Windows.Forms.Label
    Friend WithEvents addPurchase_Button As System.Windows.Forms.Button
    Friend WithEvents reset_Button As System.Windows.Forms.Button
    Friend WithEvents removeItem_Button As System.Windows.Forms.Button
    Friend WithEvents exit_Button As System.Windows.Forms.Button
    Friend WithEvents choice_DisplayLabel As System.Windows.Forms.Label
    Friend WithEvents quantity_DisplayLabel As System.Windows.Forms.Label
    Friend WithEvents quantity_Textbox As System.Windows.Forms.TextBox
    Friend WithEvents availProducts_ListBox As System.Windows.Forms.ListBox
    Friend WithEvents product_ListBox As System.Windows.Forms.ListBox
    Friend WithEvents quantity_ListBox As System.Windows.Forms.ListBox
    Friend WithEvents price_ListBox As System.Windows.Forms.ListBox
    Friend WithEvents extPrice_Listbox As System.Windows.Forms.ListBox
    Friend WithEvents product_DisplayLabel As System.Windows.Forms.Label
    Friend WithEvents quantity2_DisplayLabel As System.Windows.Forms.Label
    Friend WithEvents price_DisplayLabel As System.Windows.Forms.Label
    Friend WithEvents extPrice_DisplayLabel As System.Windows.Forms.Label
    Friend WithEvents tax_ListBox As System.Windows.Forms.ListBox
    Friend WithEvents tax_DisplayLabel As System.Windows.Forms.Label
    Friend WithEvents totalCost_DisplayLabel As System.Windows.Forms.Label
    Friend WithEvents totalCost_Label As System.Windows.Forms.Label
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents PictureBox1 As System.Windows.Forms.PictureBox

End Class
