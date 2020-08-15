Public Class Form1

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        ListBox1.Items.Add("Enter side length (must be 20 or less)")
    End Sub

    Private Sub startButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles startButton.Click

        Dim row As Integer = 1
        Dim side, column, a, b As Integer

        a = sideText.Text
        b = sideText.Text
        side = CInt(sideText.Text)

        If (side <= 20) Then
            Dim row_buffer As String = ""
            Dim row_buffer2 As String = ""
            While (row <= CInt(sideText.Text))
                column = 1
                While (column <= row)
                    row_buffer = row_buffer + "*"
                    column = column + 1
                End While
                ListBox1.Items.Add(row_buffer)
                'ListBox1.Items.Add("")
                row = row + 1
            End While
            row_buffer = Nothing

            ListBox1.Items.Add("---------------")
            row = 1
            While (side >= row)
                column = 1
                While (column <= side)
                    row_buffer2 = row_buffer2 + "*"
                    column = column + 1
                End While
                ListBox1.Items.Add(row_buffer2)
                side = side - 1
                'ListBox1.Items.Add("")
            End While
            ListBox1.Items.Add("---------------")
        End If

    End Sub
End Class
