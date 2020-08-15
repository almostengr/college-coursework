'           
'       MIS 320 - Assignment 2
'       February 1, 2011

Imports System
Imports System.Text.RegularExpressions
Imports MIS_320_Assignment_2.CustomerDataAccess

Public Class CustomerInfo
    Dim CustomerName As String
    Dim CustomerAddress As String
    Dim CustomerEmail As String
    Dim CustomerPhone As String
    Dim Committed As Boolean
    Dim errorInfo As String



    Public Property CustName() As String
        Get
            Return CustomerName
        End Get
        Set(ByVal value As String)
            CustomerName = value
        End Set
    End Property

    Property CustAddr() As String
        Get
            Return CustomerAddress
        End Get
        Set(ByVal value As String)
            CustomerAddress = value
        End Set
    End Property

    Property CustEmail() As String
        Get
            Return CustomerEmail
        End Get
        Set(ByVal value As String)
            CustomerEmail = value
        End Set
    End Property

    Property CustPhone() As String
        Get
            Return CustomerPhone
        End Get
        Set(ByVal value As String)
            CustomerPhone = value
        End Set
    End Property

    Property custCommitted() As Boolean
        Get
            Return Committed
        End Get
        Set(ByVal value As Boolean)
            Committed = value
        End Set
    End Property

    Property custErrorInfo() As String
        Get
            Return errorInfo
        End Get
        Set(ByVal value As String)
            errorInfo = value
        End Set
    End Property

    Dim CustomerDAO As New CustomerDataAccess
    Dim errorsExist As Boolean = False

    Public Sub saveCust()

        'SET VARIABLES FOR VARIABLES
        CustomerDAO.custNameDAO() = CustomerName
        CustomerDAO.custAddrDAO() = CustomerAddress
        CustomerDAO.custEmailDAO() = CustomerEmail
        CustomerDAO.custPhoneDAO() = CustomerPhone

            CustomerDAO.saveCustDAO()  'SAVE CUSTOMER INFO

        custCommitted = CustomerDAO.custCommittedDAO()
        'RETURNS BACK WHETHER THE COMMITMENT WAS SUCCESSFUL

    End Sub

End Class