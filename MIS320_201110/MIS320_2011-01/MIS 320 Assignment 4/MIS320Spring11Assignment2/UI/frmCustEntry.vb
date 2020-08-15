'
'MIS 320
'MARCH 3, 2011
'ASSIGNMENT 4

Imports MIS320Spring11Assignment2.Customer
Imports ErrorHandler    'IMPORTS ERRORHANDLER.DLL CLASS FILE

Public Class frmCustEntry

    Private Sub btnSave_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnSave.Click

        Dim MyCustomer As New Customer(tbxName.Text, tbxAddress.Text, tbxEmail.Text, tbxPhone.Text)
        'Dim CheckPhoneNumber As New checkPhoneNumber(tbxPhone.Text)
        Dim ErrorChecker As New ErrorHandler.ErrorHandler

        'CheckPhoneNumber.checkPhoneNumber()

        'If CheckPhoneNumber.getValidSubmission() = True Then

        'CALLS FUNCTIONS AND IF ANY RETURN FALSE, DOES NOT SUBMIT INFO ENTERED
        If (ErrorChecker.ValidateName(tbxName.Text) And ErrorChecker.ValidateEmail(tbxEmail.Text) _
                And ErrorChecker.ValidatePhone(tbxPhone.Text)) Then

            MyCustomer.SaveCustomer()

            tbxName.Clear()
            tbxAddress.Clear()
            tbxEmail.Clear()
            tbxPhone.Clear()
        Else
            'MsgBox(CheckPhoneNumber.getErrorMessage(), MsgBoxStyle.Critical, "Error!")
        End If

    End Sub
End Class
