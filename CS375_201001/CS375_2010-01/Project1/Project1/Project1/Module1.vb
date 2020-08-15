'
'CS 375     Project1
'January 29, 2010
'USED VISUAL STUDIO 2005 TO WRITE THIS PROGRAM

Module Module1

    Sub Main()
        Dim loanDecimal, loanAmount, loanPercent, monthlyPayment, interestAmount, principal, balance As Double
        Dim numOfYears, period As Integer

        'THE DECIMAL 
        Console.Write("Enter rate of loan in decimal form: ")
        loanDecimal = CDbl(Console.ReadLine)

        'THE NUMBER OF YEARS 
        Console.Write("Enter the number of years: ")
        numOfYears = CInt(Console.ReadLine)

        'OUTPUT THE AMOUNT OF THE LOAN
        Console.Write("Enter the amount of loan: ")
        loanAmount = CDbl(Console.ReadLine)

        loanPercent = loanDecimal * 100


        Console.WriteLine("")
        Console.WriteLine("")
        Console.WriteLine("Rate of Loan= {0}%", loanPercent)
        Console.WriteLine("Number of Years= {0}", numOfYears)
        Console.WriteLine("Amount Borrowed= {0:C}", loanAmount)

        monthlyPayment = Pmt((loanDecimal / 12), (numOfYears * 12), (-loanAmount))

        Console.WriteLine("Amount of Monthly Payment= {0:C}", monthlyPayment)

        Console.WriteLine("")
        Console.WriteLine("")
        Console.WriteLine("Amorization Table")
        Console.WriteLine("Period{0}Payment{0}Interest{0}{0}Principal{0}{0}Balance", Constants.vbTab)

        balance = loanAmount
        period = 1

        'RUN LOOP FOR EACH PERIOD
        While period <= (numOfYears * 12)

            principal = PPmt((loanDecimal / 12), period, (numOfYears * 12), (-loanAmount))
            interestAmount = IPmt((loanDecimal / 12), period, (numOfYears * 12), (-loanAmount))

            'REMAINING BALANCE - MONTHLY PAYMENT AMOUNT + INTEREST AMOUNT
            balance = balance - monthlyPayment + interestAmount

            'OUTPUT TABLE INFORMATION
            Console.WriteLine("  {1}{0}{2:C}{0}{3:C}{0}{0}{4:C}{0}{0}{5:C}", Constants.vbTab, period, monthlyPayment, interestAmount, principal, balance)
            period = period + 1
        End While


    End Sub

End Module
