'
'MIS 320
'MARCH 3, 2011
'ASSIGNMENT 4

Imports System.IO
Imports System.IO.File


Public Class DAO_Customer

    Dim Name As String
    Dim Address As String
    Dim Email As String
    Dim Phone As String

    Sub SaveCustomer()
        Dim outfile As String = "C:\Customer.dat"
        Dim wfs As New FileStream(outfile, FileMode.Append, FileAccess.Write)
        Dim swriter As New StreamWriter(wfs)

        Dim Record As String = Name & "," & Address & "," & Email & "," & Phone

        swriter.WriteLine(Record)
        swriter.Close()

    End Sub

    Sub SetName(ByVal InName As String)

        Name = InName

    End Sub

    Function GetName()

        Return Name

    End Function

    Sub SetAddress(ByVal InAddress As String)

        Address = InAddress

    End Sub

    Function GetAddress()

        Return Address

    End Function

    Sub SetEmail(ByVal InEmail As String)

        Email = InEmail

    End Sub

    Function GetEmail()

        Return Email

    End Function

    Sub SetPhone(ByVal InPhone As String)

        Phone = InPhone

    End Sub

    Function GetPhone()

        Return Phone

    End Function


End Class
