'CS375 COMPUTER EXERCISE #3
'This program is written in Visual Basic 6.0 code. You are to create a console version and a
'GUI version in Visual Basic .Net.
Public Class frmBackpack
    Inherits System.Windows.Forms.Form
    Private Sub btnCompute_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles btnCompute.Click
        Dim bounces As Integer, height As Integer, bouncefactor As Double, _
        distance As Double, btype As String
        height = txtHeight.Text
        If (txtType.Text > 0) And (txtType.Text < 5) Or Not (txtType.Text = "") Then
            bouncefactor = Microsoft.VisualBasic.Switch(txtType.Text = 1, 0.7, _
            txtType.Text = 2, 0.75, _
            txtType.Text = 3, 0.9, _
            txtType.Text = 4, 0.3)
            btype = Microsoft.VisualBasic.Switch(txtType.Text = 1, " Tennis Ball ", _
            txtType.Text = 2, " Basketball ", _
            txtType.Text = 3, " Super Ball ", _
            txtType.Text = 4, " Softball ")
            height = height * 100
            bounces = 1
            While height * bouncefactor >= 10
                bounces = bounces + 1
                height = height * bouncefactor
                distance = distance + 2 * height
            End While
            lstOut.Items.Add("The " & btype & " bounced " & bounces & " times.")
            lstOut.Items.Add("The " & btype & " traveled about " & distance / 100 & "meters.")
        Else
            MsgBox("You must enter one of the following values: 1,2,3,4", , "Data Entry")
            txtType.Clear()
            lstOut.Items.Clear()
            txtType.Focus()
        End If
    End Sub
    Private Sub btnClear_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles btnClear.Click
        lstOut.Items.Clear()
        txtHeight.Clear()
        txtType.Clear()
        txtHeight.Focus()
    End Sub
    Private Sub btnExit_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles btnExit.Click
        Me.Close()
    End Sub
    Private Sub frmBackpack_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        With lstInput.Items()
            .Clear()
            .Add("1. Tennis Ball")
            .Add("2. Basketball")
            .Add("3. Super Ball")
            .Add("4. Softball")
        End With
    End Sub
    Private Sub tmr1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles tmr1.Tick
        lblTimer.Text = Now
    End Sub
End Class