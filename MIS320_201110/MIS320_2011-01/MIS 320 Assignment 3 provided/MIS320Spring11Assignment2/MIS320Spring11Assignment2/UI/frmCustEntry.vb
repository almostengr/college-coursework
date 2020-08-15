Imports MIS320Spring11Assignment2.Customer



Public Class frmCustEntry

    Private Sub btnSave_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnSave.Click

        Dim MyCustomer As New Customer(tbxName.Text, tbxAddress.Text, tbxEmail.Text, tbxPhone.Text)

        MyCustomer.SaveCustomer()

        tbxName.Clear()
        tbxAddress.Clear()
        tbxEmail.Clear()
        tbxPhone.Clear()


    End Sub
End Class
