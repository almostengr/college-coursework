Imports MIS320Spring11Assignment2.DAO_Customer


Public Class Customer

    Dim Name As String
    Dim Address As String
    Dim Email As String
    Dim Phone As String
    Dim MyDAO As New DAO_Customer

    Sub New(ByVal InName As String, ByVal InAddress As String, ByVal InEmail As String, ByVal InPhone As String)

        Name = InName
        Address = InAddress
        Email = InEmail
        Phone = InPhone

    End Sub

    Sub SaveCustomer()

        MyDAO.SetName(Name)
        MyDAO.SetAddress(Address)
        MyDAO.SetEmail(Email)
        MyDAO.SetPhone(Phone)
        MyDAO.SaveCustomer()

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

