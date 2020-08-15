Imports System.IO


Public Class Form1

    Private Sub Label1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles labelDate.Click

    End Sub

    Private Sub btnExit_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnExit.Click
        Me.Close()
    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

        Dim gs1_avg, gs2_avg, gs3_avg, gs4_avg, gs5_avg, gs6_ave As Double
        Dim gs1_sum, gs2_sum, gs3_sum, gs4_sum, gs5_sum, gs6_sum As Double

        Dim emp_array As Double(,) = New Double(,) {}
        Dim gov_array As Double(,) = New Double(,) {}

        'Dim empInput As System.IO.StreamReader = System.IO.File.OpenText("employee.txt")

        'Dim i As Integer = 0
        'Dim j As Integer = 0
        'While (empInput.Peek <> -1)
        '    'For i = 0 To emp_array.GetUpperBound(0)
        '    '    For j = 0 To emp_array.GetUpperBound(1)
        '    '        ' emp_array(i, j) = empInput.ReadLine
        '    '    Next
        '    'Next
        'End While


        'Dim govInput As System.IO.StreamReader = System.IO.File.OpenText("government.txt")

        'i = 0   'RESETS VALUES TO 0 
        'j = 0   'RESETS VALUES TO 0
        'While (govInput.Peek <> -1)
        '    'For i = 0 To gov_array.GetUpperBound(0)
        '    '    For j = 0 To gov_array.GetUpperBound(1)
        '    '        'gov_array(i, j) = govInput.ReadLine
        '    '    Next
        '    'Next
        'End While
        'empInput.Close()
        'govInput.Close()


        Dim strfilename As String
        Dim num_rows As Long
        Dim num_cols As Long
        Dim x As Integer
        Dim y As Integer
        Dim strarray(1, 1) As String

        ' Load the file.
        strfilename = "employees.txt"

        'Check if file exist
        If File.Exists(strfilename) Then
            Dim tmpstream As StreamReader = File.OpenText(strfilename)
            Dim strlines() As String
            Dim strline() As String

            'Load content of file to strLines array
            strlines = tmpstream.ReadToEnd().Split(Environment.NewLine)

            ' Redimension the array.
            num_rows = UBound(strlines)
            strline = strlines(0).Split(",")
            num_cols = UBound(strline)
            ReDim strarray(num_rows, num_cols)

            ' Copy the data into the array.
            For x = 0 To num_rows
                strline = strlines(x).Split(",")
                For y = 0 To num_cols
                    strarray(x, y) = strline(y)
                Next
            Next


            ' Display the data in textbox
            For x = 0 To num_rows
                For y = 0 To num_cols
                    'TextBox1.Text = TextBox1.Text & strarray(x, y) & ","
                    ListBox1.Items.Add(strarray(x, y))
                Next
                'TextBox1.Text = TextBox1.Text & Environment.NewLine
            Next
        End If

    End Sub

    Private Sub ListBox1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ListBox1.SelectedIndexChanged
        ListBox1.Focus()
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnResults.Click

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnClear.Click

    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnWrite.Click

    End Sub

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        labelDate.Text = DateTime.Now.ToLongTimeString()
        labelTime.Text = DateTime.Now.ToLongDateString()

    End Sub

    Private Sub labelTime_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles labelTime.Click

    End Sub

    Private Sub ListBox2_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ListBox2.SelectedIndexChanged

    End Sub
End Class
