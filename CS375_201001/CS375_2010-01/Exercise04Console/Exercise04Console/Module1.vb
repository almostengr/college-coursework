'CS375 COMPUTER EXERCISE #4
'This program is written in Visual Basic .Net console environment. You are to write a GUI
'version in Visual Basic .Net.
Module Triangle
    Sub Main()
        Dim row As Integer = 1, side, column, a, b As Integer
        Console.Write("Enter side length(must be 20 or less): ")
        side = Console.ReadLine
        a = side
        b = side
        If side <= 20 Then
            While row <= side
                column = 1
                While column <= row
                    Console.Write("*")
                    column += 1
                End While
                Console.WriteLine()
                row += 1
            End While
            Console.WriteLine("--------------------")
            row = 1
            While side >= row
                column = 1
                While column <= side
                    Console.Write("*")
                    column += 1
                End While
                Console.WriteLine()
                side -= 1
            End While
            Console.WriteLine("--------------------")
            side = a
            row = 1
            While row <= side
                column = 1
                While column < row
                    Console.Write(" ")
                    column += 1
                End While
                a = side
                While a >= row
                    Console.Write("*")
                    a -= 1
                End While
                Console.WriteLine()
                row += 1
            End While
            Console.WriteLine("--------------------")
            row = 1
            side = b
            While row <= side
                column = side
                While column > 0
                    Console.Write(" ")
                    column -= 1
                End While
                a = 1
                While a <= row
                    Console.Write("*")
                    a += 1
                End While
                Console.WriteLine()
                row += 1
            End While
        Else
            Console.WriteLine("side too large")
        End If
    End Sub
End Module