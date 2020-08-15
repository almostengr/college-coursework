Imports MIS320Spring11Assignment2.Customer
Imports ErrorHandler.ErrorHandler




Public Class frmCustEntry

    Dim ehEntryError As New ErrorHandler.ErrorHandler


    Private Sub btnSave_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnSave.Click

        Dim MyCustomer As New Customer(tbxName.Text, tbxAddress.Text, tbxEmail.Text, tbxPhone.Text)
        Dim IsError As Boolean = False

        If Not ehEntryError.ValidateName(tbxName.Text) Then
            IsError = True
        End If

        If Not ehEntryError.ValidateEmail(tbxEmail.Text) Then
            tbxEmail.Clear()
            IsError = True
        End If

        If Not ehEntryError.ValidatePhone(tbxPhone.Text) Then
            tbxPhone.Clear()
            IsError = True
        End If

        If Not IsError Then
            MyCustomer.SaveCustomer()

            tbxName.Clear()
            tbxAddress.Clear()
            tbxEmail.Clear()
            tbxPhone.Clear()
        End If

    End Sub

    Private Sub frmCustEntry_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load

        lblPhoneInstruction.Text = ehEntryError.GetPhoneInstructions

    End Sub

 
End Class
