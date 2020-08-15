'           
'       MIS 320 - Assignment 2
'       February 1, 2011

Imports System
Imports System.Text.RegularExpressions
Imports MIS_320_Assignment_2.CustomerInfo

Public Class FormCustomerEntry

    Private Sub btnSubmit_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnSubmit.Click
        Dim CustomerInformation As New CustomerInfo     'CLASS CALL
        Dim successfulCommit As Boolean     'REPORTS OF COMMITTMENT WAS SUCCESSFUL
        Dim errorsExist As Boolean = False  'REPORTS IF ERRORS EXIST
        Dim errorMessage As String = ""     'ERROR MESSAGE 

        'SET FIELD TEXT TO CLASS VARIABLES
        CustomerInformation.CustName() = tbxName.Text
        CustomerInformation.CustAddr() = tbxAddress.Text
        CustomerInformation.CustEmail() = tbxEmail.Text
        CustomerInformation.CustPhone() = tbxPhone.Text

        checkName(errorsExist, errorMessage)        'CHECK NAME FIELD
        checkEmail(errorsExist, errorMessage)       'CHECK EMAIL FIELD
        checkPhone(errorsExist, errorMessage)       'CHECK PHONEFIELD

        If errorsExist = False Then
            CustomerInformation.saveCust()  'SAVE CUSTOMER INFO

            successfulCommit = CustomerInformation.custCommitted    'UPDATE STATUS IF COMMIT WAS SUCCESSFUL

            If successfulCommit = False Then
                updateStatus(CustomerInformation.custErrorInfo.ToString, True)
                'DISPLAY ERROR MESSAGE

            Else
                updateStatus("Customer data saved! Ready.", False)

                'CLEAR TEXT BOXES
                tbxName.Clear()
                tbxAddress.Clear()
                tbxEmail.Clear()
                tbxPhone.Clear()
            End If
        Else
            updateStatus(errorMessage, True)
            'DISPLAY ERROR MESSAGE
        End If

        tbxName.Focus()
    End Sub

    Private Sub ExitToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ExitToolStripMenuItem.Click
        Me.Close()
    End Sub

    Private Sub btnReset_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnReset.Click
        updateStatus("Ready!", False)

        'CLEAR TEXT BOXES
        tbxName.Clear()
        tbxAddress.Clear()
        tbxEmail.Clear()
        tbxPhone.Clear()
    End Sub

    Private Sub tbxPhone_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles tbxPhone.LostFocus
        'CHECK PHONE NUMBER AND IF ERRORS EXIST THEN DISPLAY MESSAGE
        Dim errorstatus As Boolean = False
        Dim errorMessage As String = ""
        checkPhone(errorstatus, errorMessage)
        updateStatus(errorMessage, errorstatus)
    End Sub

    Public Sub updateStatus(ByVal statusMessage As String, ByVal isError As Boolean)
        If isError = True Then
            'DISPLAY STATUS MESSAGE IF ERRORS EXIST
            lblProgramStatus.Text = "ERROR!" + statusMessage
        Else
            'DISPLAY STATUS MESSAGE IF NO ERRORS EXIST
            lblProgramStatus.Text = statusMessage
        End If
    End Sub


    Public Sub checkPhone(ByRef errors As Boolean, ByRef message As String)
        Trim(tbxPhone.Text) 'TRIM SPACES OUT
        If tbxPhone.Text.Length <> 0 Then
            'IF PHONE IS NOT 0 THEN CONTINUE
            If (tbxPhone.Text.Length <> 10 Or Not (IsNumeric(tbxPhone.Text.Length))) Then
                'IF PHONE IS NOT TEN DIGITS THEN DISPLAY ERROR
                errors = True
                message = message + " Invalid phone number."
            Else
                message = "Ready!"
            End If
        End If
    End Sub

    Public Sub checkName(ByRef errors As Boolean, ByRef message As String)
        If tbxName.Text = "" Then
            'IF NAME DOES NOT HAVE A VALUE THEN DISPLAY ERROR
            errors = True
            message = message + " Name is required."
        Else
            message = "Ready!"
        End If
    End Sub

    Public Sub checkEmail(ByRef errors As Boolean, ByRef message As String)
        Dim emailExpression As New System.Text.RegularExpressions.Regex("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}$")
        If tbxEmail.Text.Length > 0 Then
            If emailExpression.IsMatch(tbxEmail.Text) Then
                'errors = False
            Else
                errors = True
                message = message + " Email is not valid."
            End If
        Else
            message = "Ready!"
        End If
    End Sub

    Private Sub tbxName_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles tbxName.LostFocus
        'CHECKS NAME AND IF THERE IS AN ERROR DISPLAY MESSAGE
        Dim errorstatus As Boolean = False
        Dim errorMessage As String = ""
        checkName(errorstatus, errorMessage)
        updateStatus(errorMessage, errorstatus)
    End Sub

    Private Sub tbxEmail_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles tbxEmail.LostFocus
        'CHECKS NAME AND IF THERE IS AN ERROR DISPLAY MESSAGE
        Dim errorstatus As Boolean = False
        Dim errorMessage As String = ""
        checkEmail(errorstatus, errorMessage)
        updateStatus(errorMessage, errorstatus)
    End Sub
End Class
