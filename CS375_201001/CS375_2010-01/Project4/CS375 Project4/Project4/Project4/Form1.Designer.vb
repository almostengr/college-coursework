<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class project4
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(project4))
        Me.dateLabel = New System.Windows.Forms.Label
        Me.timeLabel = New System.Windows.Forms.Label
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.addItemButton = New System.Windows.Forms.Button
        Me.newQuotationButton = New System.Windows.Forms.Button
        Me.removeItemButton = New System.Windows.Forms.Button
        Me.exitButton = New System.Windows.Forms.Button
        Me.choiceLabel = New System.Windows.Forms.Label
        Me.plantComboBox = New System.Windows.Forms.ComboBox
        Me.purchaseTotalLabel = New System.Windows.Forms.Label
        Me.plantsListbox = New System.Windows.Forms.ListBox
        Me.quantityListbox = New System.Windows.Forms.ListBox
        Me.priceListbox = New System.Windows.Forms.ListBox
        Me.totalListbox = New System.Windows.Forms.ListBox
        Me.quantityTextbox = New System.Windows.Forms.TextBox
        Me.quantityLabel = New System.Windows.Forms.Label
        Me.itemListLabel = New System.Windows.Forms.Label
        Me.quantityListLabel = New System.Windows.Forms.Label
        Me.priceListLabel = New System.Windows.Forms.Label
        Me.itemTotalListLabel = New System.Windows.Forms.Label
        Me.discountCheckBox = New System.Windows.Forms.CheckBox
        Me.writeQuotationButton = New System.Windows.Forms.Button
        Me.quoteResultsLabel = New System.Windows.Forms.Label
        Me.inputLabel = New System.Windows.Forms.Label
        Me.Label1 = New System.Windows.Forms.Label
        Me.lilacPictureBox = New System.Windows.Forms.PictureBox
        Me.pictureLabel = New System.Windows.Forms.Label
        Me.Panel1 = New System.Windows.Forms.Panel
        Me.Panel2 = New System.Windows.Forms.Panel
        CType(Me.lilacPictureBox, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.Panel1.SuspendLayout()
        Me.Panel2.SuspendLayout()
        Me.SuspendLayout()
        '
        'dateLabel
        '
        Me.dateLabel.AutoSize = True
        Me.dateLabel.BackColor = System.Drawing.Color.Black
        Me.dateLabel.ForeColor = System.Drawing.Color.White
        Me.dateLabel.Location = New System.Drawing.Point(13, 13)
        Me.dateLabel.Name = "dateLabel"
        Me.dateLabel.Size = New System.Drawing.Size(54, 13)
        Me.dateLabel.TabIndex = 0
        Me.dateLabel.Text = "dateLabel"
        '
        'timeLabel
        '
        Me.timeLabel.AutoSize = True
        Me.timeLabel.BackColor = System.Drawing.Color.Black
        Me.timeLabel.ForeColor = System.Drawing.Color.White
        Me.timeLabel.Location = New System.Drawing.Point(245, 13)
        Me.timeLabel.Name = "timeLabel"
        Me.timeLabel.Size = New System.Drawing.Size(52, 13)
        Me.timeLabel.TabIndex = 1
        Me.timeLabel.Text = "timeLabel"
        '
        'Timer1
        '
        Me.Timer1.Enabled = True
        Me.Timer1.Interval = 1000
        '
        'addItemButton
        '
        Me.addItemButton.Location = New System.Drawing.Point(397, 16)
        Me.addItemButton.Name = "addItemButton"
        Me.addItemButton.Size = New System.Drawing.Size(75, 42)
        Me.addItemButton.TabIndex = 2
        Me.addItemButton.Text = "Add Item"
        Me.addItemButton.UseVisualStyleBackColor = True
        '
        'newQuotationButton
        '
        Me.newQuotationButton.Location = New System.Drawing.Point(397, 64)
        Me.newQuotationButton.Name = "newQuotationButton"
        Me.newQuotationButton.Size = New System.Drawing.Size(75, 42)
        Me.newQuotationButton.TabIndex = 3
        Me.newQuotationButton.Text = "New Quotation"
        Me.newQuotationButton.UseVisualStyleBackColor = True
        '
        'removeItemButton
        '
        Me.removeItemButton.Location = New System.Drawing.Point(397, 160)
        Me.removeItemButton.Name = "removeItemButton"
        Me.removeItemButton.Size = New System.Drawing.Size(75, 42)
        Me.removeItemButton.TabIndex = 4
        Me.removeItemButton.Text = "Remove Item"
        Me.removeItemButton.UseVisualStyleBackColor = True
        '
        'exitButton
        '
        Me.exitButton.Location = New System.Drawing.Point(397, 208)
        Me.exitButton.Name = "exitButton"
        Me.exitButton.Size = New System.Drawing.Size(75, 42)
        Me.exitButton.TabIndex = 5
        Me.exitButton.Text = "Exit"
        Me.exitButton.UseVisualStyleBackColor = True
        '
        'choiceLabel
        '
        Me.choiceLabel.AutoSize = True
        Me.choiceLabel.BackColor = System.Drawing.Color.Black
        Me.choiceLabel.ForeColor = System.Drawing.Color.White
        Me.choiceLabel.Location = New System.Drawing.Point(39, 72)
        Me.choiceLabel.Name = "choiceLabel"
        Me.choiceLabel.Size = New System.Drawing.Size(147, 13)
        Me.choiceLabel.TabIndex = 6
        Me.choiceLabel.Text = "Please Choose A Plant Below"
        '
        'plantComboBox
        '
        Me.plantComboBox.FormattingEnabled = True
        Me.plantComboBox.Location = New System.Drawing.Point(42, 94)
        Me.plantComboBox.Name = "plantComboBox"
        Me.plantComboBox.Size = New System.Drawing.Size(155, 21)
        Me.plantComboBox.TabIndex = 8
        '
        'purchaseTotalLabel
        '
        Me.purchaseTotalLabel.AutoSize = True
        Me.purchaseTotalLabel.BackColor = System.Drawing.Color.Black
        Me.purchaseTotalLabel.ForeColor = System.Drawing.Color.White
        Me.purchaseTotalLabel.Location = New System.Drawing.Point(371, 212)
        Me.purchaseTotalLabel.Name = "purchaseTotalLabel"
        Me.purchaseTotalLabel.Size = New System.Drawing.Size(101, 13)
        Me.purchaseTotalLabel.TabIndex = 9
        Me.purchaseTotalLabel.Text = "purchaseTotalLabel"
        '
        'plantsListbox
        '
        Me.plantsListbox.FormattingEnabled = True
        Me.plantsListbox.Location = New System.Drawing.Point(27, 331)
        Me.plantsListbox.Name = "plantsListbox"
        Me.plantsListbox.Size = New System.Drawing.Size(172, 147)
        Me.plantsListbox.TabIndex = 10
        '
        'quantityListbox
        '
        Me.quantityListbox.FormattingEnabled = True
        Me.quantityListbox.Location = New System.Drawing.Point(205, 331)
        Me.quantityListbox.Name = "quantityListbox"
        Me.quantityListbox.Size = New System.Drawing.Size(68, 147)
        Me.quantityListbox.TabIndex = 11
        '
        'priceListbox
        '
        Me.priceListbox.FormattingEnabled = True
        Me.priceListbox.Location = New System.Drawing.Point(279, 331)
        Me.priceListbox.Name = "priceListbox"
        Me.priceListbox.Size = New System.Drawing.Size(97, 147)
        Me.priceListbox.TabIndex = 12
        '
        'totalListbox
        '
        Me.totalListbox.FormattingEnabled = True
        Me.totalListbox.Location = New System.Drawing.Point(382, 331)
        Me.totalListbox.Name = "totalListbox"
        Me.totalListbox.Size = New System.Drawing.Size(90, 147)
        Me.totalListbox.TabIndex = 13
        '
        'quantityTextbox
        '
        Me.quantityTextbox.Location = New System.Drawing.Point(220, 94)
        Me.quantityTextbox.Name = "quantityTextbox"
        Me.quantityTextbox.Size = New System.Drawing.Size(100, 20)
        Me.quantityTextbox.TabIndex = 16
        '
        'quantityLabel
        '
        Me.quantityLabel.AutoSize = True
        Me.quantityLabel.BackColor = System.Drawing.Color.Black
        Me.quantityLabel.ForeColor = System.Drawing.Color.White
        Me.quantityLabel.Location = New System.Drawing.Point(217, 72)
        Me.quantityLabel.Name = "quantityLabel"
        Me.quantityLabel.Size = New System.Drawing.Size(85, 13)
        Me.quantityLabel.TabIndex = 17
        Me.quantityLabel.Text = "Quantity of Plant"
        '
        'itemListLabel
        '
        Me.itemListLabel.AutoSize = True
        Me.itemListLabel.BackColor = System.Drawing.Color.Black
        Me.itemListLabel.ForeColor = System.Drawing.Color.White
        Me.itemListLabel.Location = New System.Drawing.Point(69, 315)
        Me.itemListLabel.Name = "itemListLabel"
        Me.itemListLabel.Size = New System.Drawing.Size(87, 13)
        Me.itemListLabel.TabIndex = 18
        Me.itemListLabel.Text = "Selected Plant(s)"
        '
        'quantityListLabel
        '
        Me.quantityListLabel.AutoSize = True
        Me.quantityListLabel.BackColor = System.Drawing.Color.Black
        Me.quantityListLabel.ForeColor = System.Drawing.Color.White
        Me.quantityListLabel.Location = New System.Drawing.Point(216, 315)
        Me.quantityListLabel.Name = "quantityListLabel"
        Me.quantityListLabel.Size = New System.Drawing.Size(46, 13)
        Me.quantityListLabel.TabIndex = 19
        Me.quantityListLabel.Text = "Quantity"
        '
        'priceListLabel
        '
        Me.priceListLabel.AutoSize = True
        Me.priceListLabel.BackColor = System.Drawing.Color.Black
        Me.priceListLabel.ForeColor = System.Drawing.Color.White
        Me.priceListLabel.Location = New System.Drawing.Point(292, 315)
        Me.priceListLabel.Name = "priceListLabel"
        Me.priceListLabel.Size = New System.Drawing.Size(73, 13)
        Me.priceListLabel.TabIndex = 20
        Me.priceListLabel.Text = "Price Per Item"
        '
        'itemTotalListLabel
        '
        Me.itemTotalListLabel.AutoSize = True
        Me.itemTotalListLabel.BackColor = System.Drawing.Color.Black
        Me.itemTotalListLabel.ForeColor = System.Drawing.Color.White
        Me.itemTotalListLabel.Location = New System.Drawing.Point(399, 315)
        Me.itemTotalListLabel.Name = "itemTotalListLabel"
        Me.itemTotalListLabel.Size = New System.Drawing.Size(54, 13)
        Me.itemTotalListLabel.TabIndex = 21
        Me.itemTotalListLabel.Text = "Item Total"
        '
        'discountCheckBox
        '
        Me.discountCheckBox.AutoSize = True
        Me.discountCheckBox.BackColor = System.Drawing.Color.Black
        Me.discountCheckBox.ForeColor = System.Drawing.Color.White
        Me.discountCheckBox.Location = New System.Drawing.Point(220, 120)
        Me.discountCheckBox.Name = "discountCheckBox"
        Me.discountCheckBox.Size = New System.Drawing.Size(107, 17)
        Me.discountCheckBox.TabIndex = 22
        Me.discountCheckBox.Text = "Discounted Price"
        Me.discountCheckBox.UseVisualStyleBackColor = False
        '
        'writeQuotationButton
        '
        Me.writeQuotationButton.Location = New System.Drawing.Point(397, 112)
        Me.writeQuotationButton.Name = "writeQuotationButton"
        Me.writeQuotationButton.Size = New System.Drawing.Size(75, 42)
        Me.writeQuotationButton.TabIndex = 23
        Me.writeQuotationButton.Text = "Write Quotation"
        Me.writeQuotationButton.UseVisualStyleBackColor = True
        '
        'quoteResultsLabel
        '
        Me.quoteResultsLabel.AutoSize = True
        Me.quoteResultsLabel.BackColor = System.Drawing.Color.Black
        Me.quoteResultsLabel.ForeColor = System.Drawing.Color.White
        Me.quoteResultsLabel.Location = New System.Drawing.Point(194, 10)
        Me.quoteResultsLabel.Name = "quoteResultsLabel"
        Me.quoteResultsLabel.Size = New System.Drawing.Size(91, 13)
        Me.quoteResultsLabel.TabIndex = 24
        Me.quoteResultsLabel.Text = "Quotation Results"
        '
        'inputLabel
        '
        Me.inputLabel.AutoSize = True
        Me.inputLabel.BackColor = System.Drawing.Color.Black
        Me.inputLabel.ForeColor = System.Drawing.Color.White
        Me.inputLabel.Location = New System.Drawing.Point(168, 46)
        Me.inputLabel.Name = "inputLabel"
        Me.inputLabel.Size = New System.Drawing.Size(70, 13)
        Me.inputLabel.TabIndex = 25
        Me.inputLabel.Text = "Input Section"
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.BackColor = System.Drawing.Color.Black
        Me.Label1.ForeColor = System.Drawing.Color.White
        Me.Label1.Location = New System.Drawing.Point(219, 212)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(149, 13)
        Me.Label1.TabIndex = 26
        Me.Label1.Text = "Quotation Total (includes Tax)"
        '
        'lilacPictureBox
        '
        Me.lilacPictureBox.Image = CType(resources.GetObject("lilacPictureBox.Image"), System.Drawing.Image)
        Me.lilacPictureBox.Location = New System.Drawing.Point(91, 140)
        Me.lilacPictureBox.Name = "lilacPictureBox"
        Me.lilacPictureBox.Size = New System.Drawing.Size(100, 81)
        Me.lilacPictureBox.TabIndex = 27
        Me.lilacPictureBox.TabStop = False
        '
        'pictureLabel
        '
        Me.pictureLabel.AutoSize = True
        Me.pictureLabel.Location = New System.Drawing.Point(121, 124)
        Me.pictureLabel.Name = "pictureLabel"
        Me.pictureLabel.Size = New System.Drawing.Size(40, 13)
        Me.pictureLabel.TabIndex = 28
        Me.pictureLabel.Text = "Picture"
        '
        'Panel1
        '
        Me.Panel1.BackColor = System.Drawing.Color.DarkRed
        Me.Panel1.Controls.Add(Me.pictureLabel)
        Me.Panel1.Controls.Add(Me.lilacPictureBox)
        Me.Panel1.Location = New System.Drawing.Point(8, 6)
        Me.Panel1.Name = "Panel1"
        Me.Panel1.Size = New System.Drawing.Size(481, 254)
        Me.Panel1.TabIndex = 29
        '
        'Panel2
        '
        Me.Panel2.BackColor = System.Drawing.Color.DarkRed
        Me.Panel2.Controls.Add(Me.Label1)
        Me.Panel2.Controls.Add(Me.quoteResultsLabel)
        Me.Panel2.Controls.Add(Me.purchaseTotalLabel)
        Me.Panel2.Location = New System.Drawing.Point(8, 273)
        Me.Panel2.Name = "Panel2"
        Me.Panel2.Size = New System.Drawing.Size(481, 238)
        Me.Panel2.TabIndex = 30
        '
        'project4
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(498, 523)
        Me.Controls.Add(Me.inputLabel)
        Me.Controls.Add(Me.writeQuotationButton)
        Me.Controls.Add(Me.discountCheckBox)
        Me.Controls.Add(Me.itemTotalListLabel)
        Me.Controls.Add(Me.priceListLabel)
        Me.Controls.Add(Me.quantityListLabel)
        Me.Controls.Add(Me.itemListLabel)
        Me.Controls.Add(Me.quantityLabel)
        Me.Controls.Add(Me.quantityTextbox)
        Me.Controls.Add(Me.totalListbox)
        Me.Controls.Add(Me.priceListbox)
        Me.Controls.Add(Me.quantityListbox)
        Me.Controls.Add(Me.plantsListbox)
        Me.Controls.Add(Me.plantComboBox)
        Me.Controls.Add(Me.choiceLabel)
        Me.Controls.Add(Me.exitButton)
        Me.Controls.Add(Me.removeItemButton)
        Me.Controls.Add(Me.newQuotationButton)
        Me.Controls.Add(Me.addItemButton)
        Me.Controls.Add(Me.timeLabel)
        Me.Controls.Add(Me.dateLabel)
        Me.Controls.Add(Me.Panel1)
        Me.Controls.Add(Me.Panel2)
        Me.Name = "project4"
        Me.Text = "Project 4 - Spring 2010 - "
        CType(Me.lilacPictureBox, System.ComponentModel.ISupportInitialize).EndInit()
        Me.Panel1.ResumeLayout(False)
        Me.Panel1.PerformLayout()
        Me.Panel2.ResumeLayout(False)
        Me.Panel2.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents dateLabel As System.Windows.Forms.Label
    Friend WithEvents timeLabel As System.Windows.Forms.Label
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents addItemButton As System.Windows.Forms.Button
    Friend WithEvents newQuotationButton As System.Windows.Forms.Button
    Friend WithEvents removeItemButton As System.Windows.Forms.Button
    Friend WithEvents exitButton As System.Windows.Forms.Button
    Friend WithEvents choiceLabel As System.Windows.Forms.Label
    Friend WithEvents plantComboBox As System.Windows.Forms.ComboBox
    Friend WithEvents purchaseTotalLabel As System.Windows.Forms.Label
    Friend WithEvents plantsListbox As System.Windows.Forms.ListBox
    Friend WithEvents quantityListbox As System.Windows.Forms.ListBox
    Friend WithEvents priceListbox As System.Windows.Forms.ListBox
    Friend WithEvents totalListbox As System.Windows.Forms.ListBox
    Friend WithEvents quantityTextbox As System.Windows.Forms.TextBox
    Friend WithEvents quantityLabel As System.Windows.Forms.Label
    Friend WithEvents itemListLabel As System.Windows.Forms.Label
    Friend WithEvents quantityListLabel As System.Windows.Forms.Label
    Friend WithEvents priceListLabel As System.Windows.Forms.Label
    Friend WithEvents itemTotalListLabel As System.Windows.Forms.Label
    Friend WithEvents discountCheckBox As System.Windows.Forms.CheckBox
    Friend WithEvents writeQuotationButton As System.Windows.Forms.Button
    Friend WithEvents quoteResultsLabel As System.Windows.Forms.Label
    Friend WithEvents inputLabel As System.Windows.Forms.Label
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents lilacPictureBox As System.Windows.Forms.PictureBox
    Friend WithEvents pictureLabel As System.Windows.Forms.Label
    Friend WithEvents Panel1 As System.Windows.Forms.Panel
    Friend WithEvents Panel2 As System.Windows.Forms.Panel

End Class
