'           
'       MIS 320 - Assignment 2
'       February 1, 2011

Imports System
Imports System.IO

Public Class CustomerDataAccess

    Dim filePath As String = "customer_info.txt"
    Dim customerNameDAO As String
    Dim customerAddressDAO As String
    Dim customerEmailDAO As String
    Dim customerPhoneDAO As String
    Dim Committed As Boolean

    'GETS AND SETS
    Property custNameDAO() As String
        Get
            Return customerNameDAO
        End Get
        Set(ByVal value As String)
            customerNameDAO = value
        End Set
    End Property

    Property custAddrDAO() As String
        Get
            Return customerAddressDAO
        End Get
        Set(ByVal value As String)
            customerAddressDAO = value
        End Set
    End Property

    Property custEmailDAO() As String
        Get
            Return customerEmailDAO
        End Get
        Set(ByVal value As String)
            customerEmailDAO = value
        End Set
    End Property

    Property custPhoneDAO() As String
        Get
            Return customerPhoneDAO
        End Get
        Set(ByVal value As String)
            customerPhoneDAO = value
        End Set
    End Property

    Property custCommittedDAO() As Boolean
        Get
            Return Committed
        End Get
        Set(ByVal value As Boolean)
            Committed = value
        End Set
    End Property

    Public Sub saveCustDAO(Optional ByVal errInfo As String = "")
        Dim fileWriter As StreamWriter
        Dim fileExists As Boolean = False

        If Dir(filePath) <> "" Then
            'CHECK FOR EXISTING FILE
            fileExists = True
        End If

        Try
            fileWriter = New StreamWriter(filePath, True)     'CREATE NEW (IF IT DOESN'T ALREADY EXIST) AND OPEN FILE

            If fileExists = False Then
                'IF FILE DOES NOT EXIST THEN WRITE HEADER LINE
                fileWriter.WriteLine("Name,Address,Email,Phone")
            End If

            fileWriter.WriteLine(customerNameDAO + "," + customerAddressDAO + "," + customerEmailDAO + "," + customerPhoneDAO)
            'WRITES FORM DATA TO FILE
            Committed = True    'UPDATES COMMITTED STATUS
            fileWriter.Close()              'CLOSE FILE

        Catch Ex As Exception
            errInfo = Ex.Message    'SHOW ERROR MESSAGE
            Committed = False       'UPDATES COMMITTED STATUS
        End Try
    End Sub
End Class
