Imports System.IO
Imports System.Globalization

Public Class project4

    '
    'CS 375 Project 4
    'April 23, 2010

    Dim totalPurchasePrice As Decimal       'TOTAL PRICE THAT INCLUDE
    Dim taxRate As Decimal = 0.09           'TAX RATE / PERCENTAGES TAX
    Dim subtotalPurchasePrice As Decimal    'SUBTOTAL PRICE


    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        dateLabel.Text = DateAndTime.Now.ToLongDateString()
        timeLabel.Text = DateAndTime.Now.ToLongTimeString()
    End Sub

    Private Sub plantComboBox_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles plantComboBox.SelectedIndexChanged
        quantityTextbox.Focus()         'CHANGE FOCUS TO QUANTITY TEXTBOX
    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'ADD ITEMS TO COMBO BOX
        plantComboBox.Items.Add("Flower-Iris")
        plantComboBox.Items.Add("Flower-Lilac")
        plantComboBox.Items.Add("Flower-Marigold")
        plantComboBox.Items.Add("Herb-Basil")
        plantComboBox.Items.Add("Herb-Mint")
        plantComboBox.Items.Add("Shrub-Juniper")
        plantComboBox.Items.Add("Shrub-Boxwood")
        plantComboBox.Items.Add("Tree-Adler")
        plantComboBox.Items.Add("Tree-Ash")
        plantComboBox.Items.Add("Tree-Pine")
        plantComboBox.Items.Add("Tree-Oak")
        plantComboBox.Items.Add("Tree-Olive")

        totalPurchasePrice = 0.0        'SET TOTAL PRICE TO $0.00
        purchaseTotalLabel.Text = totalPurchasePrice.ToString("C", CultureInfo.GetCultureInfo("en-us"))
        'FORMAT AND OUTPUT DOLLAR FORMAT
    End Sub

    Private Sub addItemButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles addItemButton.Click
        Dim pricePerItem As Decimal             'PRICE PER ITEM
        Dim plantQuantity As Integer = 0        'QUANTITY OF PLANTS ENTERED


        If CInt(quantityTextbox.Text) > 0 Then      'IF NUMBER IS NOT 
            plantQuantity = CInt(quantityTextbox.Text)  'GET NUMBER FROM TEXTBXOX, CONVERT, PLACE IN VARIABLE
        Else
            plantQuantity = 0
        End If

        If plantComboBox.SelectedIndex <> -1 And plantQuantity > -1 Then
            'IF NO COMBOBOX VALUE SELECT AND PLANT QUANTITY IS GREATER THAN -1 

            plantsListbox.Items.Add(plantComboBox.SelectedItem) 'ADD ITEM NAME TO LISTBOX

            If plantComboBox.SelectedIndex = 0 Then     'FLOWER-IRIS
                If discountCheckBox.Checked = True Then
                    pricePerItem = 3.84       'APPLY DISCOUNTED PRICE
                Else
                    pricePerItem = 4.37       'APPLY STANDARD PRICE
                End If
            ElseIf plantComboBox.SelectedIndex = 1 Then     'FLOWER-LILAC
                If discountCheckBox.Checked = True Then
                    pricePerItem = 4.49       'APPLY DISCOUNTED PRICE
                Else
                    pricePerItem = 5.22       'APPLY STANDARD PRICE
                End If
            ElseIf plantComboBox.SelectedIndex = 2 Then     'FLOWER-MARIGOLD
                If discountCheckBox.Checked = True Then
                    pricePerItem = 1.6        'APPLY DISCOUNTED PRICE
                Else
                    pricePerItem = 1.73       'APPLY STANDARD PRICE
                End If
            ElseIf plantComboBox.SelectedIndex = 3 Then     'HERB-BASIL
                If discountCheckBox.Checked = True Then
                    pricePerItem = 1.26      'APPLY DISCOUNTED PRICE
                Else
                    pricePerItem = 1.88       'APPLY STANDARD PRICE
                End If
            ElseIf plantComboBox.SelectedIndex = 4 Then     'HERB-MINT
                If discountCheckBox.Checked = True Then
                    pricePerItem = 2.26       'APPLY DISCOUNTED PRICE
                Else
                    pricePerItem = 2.88       'APPLY STANDARD PRICE
                End If
            ElseIf plantComboBox.SelectedIndex = 5 Then     'SHRUB-JUNIPER
                If discountCheckBox.Checked = True Then
                    pricePerItem = 3.72       'APPLY DISCOUNTED PRICE
                Else
                    pricePerItem = 4.18       'APPLY STANDARD PRICE
                End If
            ElseIf plantComboBox.SelectedIndex = 6 Then     'SHRUB-BOXWOOD
                If discountCheckBox.Checked = True Then
                    pricePerItem = 8.7        'APPLY DISCOUNTED PRICE
                Else
                    pricePerItem = 9.22       'APPLY STANDARD PRICE
                End If
            ElseIf plantComboBox.SelectedIndex = 7 Then     'TREE-ADLER
                If discountCheckBox.Checked = True Then
                    pricePerItem = 34.6       'APPLY DISCOUNTED PRICE
                Else
                    pricePerItem = 39.88      'APPLY STANDARD PRICE
                End If
            ElseIf plantComboBox.SelectedIndex = 8 Then     'TREE-ASH
                If discountCheckBox.Checked = True Then
                    pricePerItem = 38.6      'APPLY DISCOUNTED PRICE
                Else
                    pricePerItem = 43.8      'APPLY STANDARD PRICE
                End If
            ElseIf plantComboBox.SelectedIndex = 9 Then     'TREE-PINE
                If discountCheckBox.Checked = True Then
                    pricePerItem = 26.94      'APPLY DISCOUNTED PRICE
                Else
                    pricePerItem = 28.6      'APPLY STANDARD PRICE
                End If
            ElseIf plantComboBox.SelectedIndex = 10 Then    'TREE-OAK
                If discountCheckBox.Checked = True Then
                    pricePerItem = 29.32      'APPLY DISCOUNTED PRICE
                Else
                    pricePerItem = 33.84      'APPLY STANDARD PRICE
                End If
            ElseIf plantComboBox.SelectedIndex = 11 Then    'TREE-OLIVE
                If discountCheckBox.Checked = True Then
                    pricePerItem = 17.24      'APPLY DISCOUNTED PRICE
                Else
                    pricePerItem = 19.2      'APPLY STANDARD PRICE
                End If
            End If

            quantityListbox.Items.Add(plantQuantity)    'ADD TO QUANTITY LIST

            priceListbox.Items.Add(pricePerItem.ToString("C", CultureInfo.GetCultureInfo("en-us")))
            'ADD TO PRICE LIST



            totalListbox.Items.Add((pricePerItem * plantQuantity).ToString("C", CultureInfo.GetCultureInfo("en-us")))
            'ADD TO TOTAL LIST

            totalPurchasePrice = totalPurchasePrice + (pricePerItem * plantQuantity)
            'TOTAL LIST BOX 

            purchaseTotalLabel.Text = ((totalPurchasePrice * taxRate) + totalPurchasePrice).ToString("C", CultureInfo.GetCultureInfo("en-us"))
            'UPDATE QUOTATED
        End If
    End Sub

    Private Sub newQuotationButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles newQuotationButton.Click
        quantityTextbox.Clear()             'CLEAR QUANTITY TEXTBOX
        plantsListbox.Items.Clear()         'CLEAR PLANTS LISTBOX
        quantityListbox.Items.Clear()       'CLEAR QUANTITY LISTBOX
        priceListbox.Items.Clear()          'CLEAR PRICE LISTBOX
        totalListbox.Items.Clear()          'CLEAR PRICE TOTAL LISTBOX
        totalPurchasePrice = 0.0            'CHANGE TOTAL PRICE TO $0.00
        plantComboBox.Focus()               'CHANGE FOCUS TO PLANT COMBO BOX
        purchaseTotalLabel.Text = totalPurchasePrice.ToString("C", CultureInfo.GetCultureInfo("en-us"))
    End Sub


    Public Function writeToCSVFile(ByVal strData As String, ByVal FullPath As String, Optional ByVal ErrInfo As String = "") As Boolean
        Dim bAns As Boolean = False
        Dim fileWriter As StreamWriter
        Try
            fileWriter = New StreamWriter(FullPath)     'CREATE NEW (IF IT DOESN'T ALREADY EXIST) AND OPEN FILE
            fileWriter.Write(strData)       'WRITE DATA TO FILE
            fileWriter.Close()              'CLOSE FILE
            bAns = True
        Catch Ex As Exception
            ErrInfo = Ex.Message    'SHOW ERROR MESSAGE
        End Try
        Return bAns
    End Function


    Private Sub writeQuotationCSVButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles writeQuotationButton.Click

        Dim writeToCSVFileString As String = ""
        Dim iCounter As Integer

        writeToCSVFileString = "Plant, Quantity, Price Per Item, Item Total, Final Price (including Tax)" + vbNewLine
        For iCounter = 0 To (plantsListbox.Items.Count - 1)
            writeToCSVFileString += CStr(plantsListbox.Items.Item(iCounter)) + ", "
            'WRITE ITEMS IN PLANT LIST BOX TO FILE 

            writeToCSVFileString += CStr(quantityListbox.Items.Item(iCounter)) + ", "
            'WRITE ITEMS IN QUANTITY LIST BOX TO FILE 

            writeToCSVFileString += CStr(priceListbox.Items.Item(iCounter)) + ", "
            'WRITE ITEMS IN PRICE PER ITEM LIST BOX TO FILE 

            writeToCSVFileString += CStr(totalListbox.Items.Item(iCounter)) + ", "
            'WRITE ITEMS IN TOTAL LIST BOX TO FILE 

            writeToCSVFileString += vbNewLine
            'WRITE CARRIAGE RETURN TO FILE

        Next

        writeToCSVFileString += ",,,," + CStr(purchaseTotalLabel.Text)

        writeToCSVFile(writeToCSVFileString, "price_quotation.txt")
    End Sub

    Private Sub removeItemButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles removeItemButton.Click
        Dim priceVoid As Decimal        'PRICE OF ITEM VOIDED 
        Dim voidableItem As Integer     'INDEX OF ITEM TO VOID 


        If (plantsListbox.SelectedIndex <> -1) Then
            voidableItem = plantsListbox.SelectedIndex
            'IF ITEM IS SELECTED IN PLANTS LISTBOX, THEN USE ITS INDEX
        ElseIf totalListbox.SelectedIndex <> -1 Then
            voidableItem = totalListbox.SelectedIndex
            'IF ITEM IS SELECTED IN TOTAL LISTBOX, THEN USE ITS INDEX
        ElseIf quantityListbox.SelectedIndex <> -1 Then
            voidableItem = quantityListbox.SelectedIndex
            'IF ITEM IS SELECTED IN QUANTITY LISTBOX, THEN USE ITS INDEX
        ElseIf priceListbox.SelectedIndex <> -1 Then
            voidableItem = priceListbox.SelectedIndex
            'IF ITEM IS SELECTED IN QUANTITY LISTBOX, THEN USE ITS INDEX
        End If


        priceVoid = CDec(totalListbox.Items.IndexOf(voidableItem))        'GET PRICE OF ITEM TO BE VOIDED

        priceListbox.Items.RemoveAt(voidableItem)           'REMOVE ITEM FROM PRICE LIST BOX 

        totalListbox.Items.RemoveAt(voidableItem)           'REMOVE ITEM FROM TOTAL LIST BOX

        quantityListbox.Items.RemoveAt(voidableItem)        'REMOVE ITEM FROM QUANTITY LIST BOX

        plantsListbox.Items.RemoveAt(voidableItem)          'REMOVE ITEM FROM PLANTS LIST BOX

        totalPurchasePrice = totalPurchasePrice - priceVoid   'SUBTRACT ITEM PRICE FROM TOTAL

        purchaseTotalLabel.Text = (totalPurchasePrice * taxRate).ToString("C", CultureInfo.GetCultureInfo("en-us"))
        'UPDATE QUOTATED
    End Sub

    Private Sub exitButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles exitButton.Click
        Me.Close()      'EXIT PROGRAM
    End Sub
End Class
