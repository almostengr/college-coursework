'
'MIS 320
'FEBRUARY 8, 2011
'ASSIGNMENT 3

Imports MIS320Spring11Assignment2.Customer



Public Class frmCustEntry

    Private Sub btnSave_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnSave.Click

        Dim MyCustomer As New Customer(tbxName.Text, tbxAddress.Text, tbxEmail.Text, tbxPhone.Text)
        Dim CheckPhoneNumber As New checkPhoneNumber(tbxPhone.Text)

        CheckPhoneNumber.checkPhoneNumber()

        If CheckPhoneNumber.getValidSubmission() = True Then
            MyCustomer.SaveCustomer()

            tbxName.Clear()
            tbxAddress.Clear()
            tbxEmail.Clear()
            tbxPhone.Clear()
        Else
            MsgBox(CheckPhoneNumber.getErrorMessage(), MsgBoxStyle.Critical, "Error!")
        End If

    End Sub
End Class
