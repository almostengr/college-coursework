Imports System.Text.RegularExpressions


Public Class ErrorHandler

    Const strPhoneNumError As String = "Phone number must be entered as a 10 digit number with no other characters"
    Const strPhoneNumInstructions As String = "(Ex. 5556667890)"
    Const strEmailEntryError As String = "You did not enter a properly formatted email address (with @ and .)"
    Const strEmailMissingError As String = "Email address is required"
    Const strNameMissingError As String = "Name is required"

    Public Function ValidatePhone(ByVal PhoneNum As String)


        Dim phoneEnumerator As IEnumerator = PhoneNum.GetEnumerator()
        Dim Count As Integer = 0

        While phoneEnumerator.MoveNext()
            Count = Count + 1
            If Count > 10 Or Not (phoneEnumerator.Current > Chr(47) And phoneEnumerator.Current < Chr(58)) Then
                MsgBox(strPhoneNumError, MsgBoxStyle.OkOnly, "Phone Number Entry Error")
                Return False
            End If
        End While

        Return True

    End Function
    Public Function ValidateEmail(ByVal Email As String)

        Dim emailExpression As New System.Text.RegularExpressions.Regex("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}$")
        If Email.Length > 0 Then
            If emailExpression.IsMatch(Email) Then
                Return True
            Else
                MsgBox(strEmailEntryError, MsgBoxStyle.OkOnly, "Email Entry Error")
                Return False
            End If
        Else
            MsgBox(strEmailMissingError, MsgBoxStyle.OkOnly, "Email Entry Error")
            Return False
        End If

    End Function
    Public Function ValidateName(ByVal Name As String)

        If Name.Length <= 0 Then
            MsgBox(strNameMissingError, MsgBoxStyle.OkOnly, "Name Entry Error")
            Return False
        Else
            Return True
        End If

    End Function

    Public Function GetPhoneInstructions()

        Return strPhoneNumInstructions

    End Function

End Class
