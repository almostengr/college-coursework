Public Class checkPhoneNumber

    Dim phoneNumber As String
    Dim validSubmission As Boolean = True
    Dim errorMessage As String = ""


    Sub New(ByVal inputPhoneNumber As String)
        phoneNumber = inputPhoneNumber
    End Sub

    Sub checkPhoneNumber()
        Trim(phoneNumber)
        If phoneNumber.Length <> 0 Then
            'IF PHONE IS NOT 0 THEN CONTINUE
            If (phoneNumber.Length <> 10 Or Not (IsNumeric(phoneNumber.Length))) Then
                'IF PHONE IS NOT TEN DIGITS THEN DISPLAY ERROR
                validSubmission = False
                errorMessage = "Phone number must be numeric; " + _
                    "no symbols (dashes, hypens, parentheses, etc)." + vbCrLf
            Else
                'IF PHONE IS TEN DIGITS, NO ERROR
            End If
        Else
            'DO NOTHING
        End If
    End Sub

    Function getValidSubmission()
        Return validSubmission
    End Function

    Function getErrorMessage()
        Return errorMessage
    End Function
End Class
