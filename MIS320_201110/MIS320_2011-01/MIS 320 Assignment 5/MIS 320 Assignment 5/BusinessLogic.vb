'
'MIS 320 
'FEBRUARY 22, 2011
'ASSIGNMENT 5

Public Class POS
    Public Function calcSubTotal(ByVal cups As Integer, ByVal price As Double)
        'MULTIPLIES NUMBER CUPS BY PRICE
        Return (cups * price)
    End Function

    Public Function calcSalesTax(ByVal subTotal As Double)
        'CALCULATES THE SALES TAX BASED ON THE SUBTOTAL
        Return (subTotal * 0.09)
    End Function

    Public Function calcTotal(ByVal subTotal As Double, ByVal salesTax As Double)
        'CALCULATES THE TOTAL BASED ON SUBTOTAL AND SALES TAX
        Return (subTotal + salesTax)
    End Function
End Class
