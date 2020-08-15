Imports System.IO
Imports System.Globalization

Public Class project5

    '
    'CS 375  - Spring 2010
    'April 30, 2010

    Private productPriceArray() As Double = New Double(10) {}
    'ARRAY THAT HOLDS PRICES OF PRODUCTS

    Private Sub calculateTotal()
        Dim purchaseTotal As Decimal = 0.0      'INITIALIZE PURCHASE PRICE TO $0.00
        Dim currentItem As Integer              'CURRENT ITEM NUMBER IN LIST BOX

        For currentItem = 0 To (extPrice_Listbox.Items.Count - 1)
            'GO THROUGH EXTENDED PRICE AND TAX LIST BOXES AND ADD VALUES
            purchaseTotal = purchaseTotal + CDec(extPrice_Listbox.Items(currentItem)) + _
                CDec(tax_ListBox.Items(currentItem))
        Next

        totalCost_Label.Text = (purchaseTotal).ToString("C", CultureInfo.GetCultureInfo("en-us"))
        'AFTER ADDING ALL VALUES, DISPLAY TOTAL
    End Sub

    Private Sub project5_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

        Dim inputLineFromFile As String
        Dim currentItem As Integer = 0      'DECLARE AND SET CURRENT ITEM TO 0
        Dim position, length, first, last As Integer


        Dim inputFile As System.IO.StreamReader = System.IO.File.OpenText("office.txt")
        'OPEN INPUT FILE

        Try     'TRY TO OPEN FILE AND IF UNABLE, THROW EXCEPTION MESSAGE
            While (inputFile.Peek <> -1)    'READ UNTIL THEN END OF FILE
                inputLineFromFile = inputFile.ReadLine  'READ 1 LINE OF FILE
                position = inputLineFromFile.IndexOf(",")   'GET POSITION NUMBER WHERE COMMA IS
                length = inputLineFromFile.Length   'TOTAL LENGTH OF LINE
                first = position + 1
                last = length - first

                'itemName = inputLineFromFile.Substring(0, position)
                'PUT ITEM NAME INTO VARIABLE 

                availProducts_ListBox.Items.Add(inputLineFromFile.Substring(0, position))   'ADD ITEM NAME TO PRODUCTS AVAILABLE

                'itemPrice = CDec(inputLineFromFile.Substring(first, last))
                'GET THE PRICE FROM FILE AND STORE IN VARIABLE

                productPriceArray(currentItem) = CDec(inputLineFromFile.Substring(first, last))
                'PUT VALUE IN PRICE VARIABLE INTO ARRAY

                currentItem += 1    'INCREMENT TO GET THE NEXT ITEM
            End While
            inputFile.Close()   'CLOSE INPUT FILE
        Catch ex As Exception
            Throw New Exception(ex.Message) 'THROWS EXCEPTION ERROR MESSAGE
        End Try
    End Sub

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        dateDisplay_Label.Text = DateTime.Now.ToLongDateString()    'UDPATES WITH CURRENT DATE
        timeDisplay_Label.Text = DateTime.Now.ToLongTimeString()    'UDPATES WITH CURRENT TIME
    End Sub

    Private Sub availProducts_ListBox_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles availProducts_ListBox.SelectedIndexChanged

        quantity_Textbox.Focus()    'CHANGE FOCUS TO QUANTITY TEXT BOX AFTER SELECTING ITEM

    End Sub

    Private Sub addPurchase_Button_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles addPurchase_Button.Click

        Dim extendedPrice, salesPrice As Decimal

        If ((availProducts_ListBox.SelectedIndex <> -1) And (CStr(quantity_Textbox.Text)) > -1) Then
            product_ListBox.Items.Add(availProducts_ListBox.Text)   'ADD NAME OF PRODUCT TO PRODUCT LISTBOX

            quantity_ListBox.Items.Add(quantity_Textbox.Text)   'GETS QUANTITY FROM TEXTBOX 
            price_ListBox.Items.Add((productPriceArray(availProducts_ListBox.SelectedIndex)).ToString("C", CultureInfo.GetCultureInfo("en-us")))
            'ADD QUANTITY TO QUANTITY LISTBOX 

            extendedPrice = (CDec(quantity_Textbox.Text)) * productPriceArray(availProducts_ListBox.SelectedIndex)
            'CALCULATE THE EXTENDED PRICE 
            extPrice_Listbox.Items.Add((extendedPrice).ToString("C", CultureInfo.GetCultureInfo("en-us")))
            'ADD EXTENDED PRICE TO EXTENDED PRICE LISTBOX

            salesPrice = CDec(extendedPrice * 0.05) 'CALCULATES SALES TAX
            tax_ListBox.Items.Add((salesPrice).ToString("C", CultureInfo.GetCultureInfo("en-us")))
            'ADDS SALES TAX AS TAX LISTBOX 

            calculateTotal()    'CALLS FUNCTIONS TO CALCULATE THE TOTAL

            quantity_Textbox.Clear()        'CLEAR THE QUANTITY LIST BOX
            availProducts_ListBox.SelectedIndex = -1    'UNSELECT THE ITEM IN THE AVAILABLE PRODUCTS LISTBOX
            availProducts_ListBox.Focus()   'CHANGE THE FOCUS BACK TO THE AVAILABLE PRODUCTS LISTBOX
        End If
    End Sub

    Private Sub exit_Button_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles exit_Button.Click
        Me.Close()      'EXITS PROGRAM
    End Sub

    Private Sub removeItem_Button_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles removeItem_Button.Click

        Dim indexNumber As Integer = product_ListBox.SelectedIndex     'GET INDEX NUMBER OF ITEM SELECTED

        If indexNumber > -1 Then
            product_ListBox.Items.RemoveAt(indexNumber)     'REMOVE PRODUCT IN PRODCUT IN LISTBOX
            quantity_ListBox.Items.RemoveAt(indexNumber)    'REMOVE QUANTITY IN QUANTITY LISTBOX
            price_ListBox.Items.RemoveAt(indexNumber)       'REMOVE PRICE ITEM IN PRICE LISTBOX 
            extPrice_Listbox.Items.RemoveAt(indexNumber)    'REMOVE EXTENDED PRICE ITEM IN EXTENDED PRICE LISTBOX 
            tax_ListBox.Items.RemoveAt(indexNumber)     'REMOVE TAX ITEM IN TAX LISTBOX
            calculateTotal()    'CALCULATES TOTAL AND DISPLAYS IT
        End If
    End Sub

    Private Sub reset_Button_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles reset_Button.Click

        availProducts_ListBox.SelectedIndex = -1    'RESET AVAILABLE PRODCUTS LISTBOX
        product_ListBox.Items.Clear()       'CLEAR PRODUCT LISTBOX
        quantity_ListBox.Items.Clear()      'CLEAR QUANTITY LISTBOX
        price_ListBox.Items.Clear()         'CLEAR PRICE LISTBOX
        extPrice_Listbox.Items.Clear()      'CLEAR EXTENDED PRICE LISTBOX
        tax_ListBox.Items.Clear()           'CLEAR TAX LISTBOX
        quantity_Textbox.Clear()            'CLEAR QUANTITY TEXTBOX

        totalCost_Label.Text = (0.0).ToString("c", CultureInfo.GetCultureInfo("en-us"))
        'CHANGE TOTAL COST LABEL TO $0.00
    End Sub
End Class
