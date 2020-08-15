'
'CS 375     Project 3
'April 5, 2010

Public Class Form1
    Dim isSimRunning As Boolean = False

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        timeLabel.Text = DateTime.Now.ToLongTimeString()    'UPDATES TIME WITH CURRENT TIME
        dateLabel.Text = DateTime.Now.ToLongDateString()    'UPDATES DATE WITH CURRENT TIME 
    End Sub

    Private Sub exitButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles exitButton.Click
        Me.Close()      'EXITS PROGRAM 
    End Sub

    Private Sub clearButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles clearButton.Click
        simulationTextbox.Clear()   'CLEARS SIMULATION TEXT BOX
        gallonsTextbox.Clear()      'CLEARS GALLONS TEXT BOX
        priceTextbox.Clear()        'CLEARS PRICE TEXT BOX
        statusListBox.Items.Clear() 'CLEARS STATUS LIST BOX
        isSimRunning = False        'SETS SIMULATION RUNNING STATUS TO FALSE
    End Sub

    Private Sub simButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles simButton.Click

        If (simulationTextbox.TextLength > 0) Then
            'PREVENTS FROM SIMULATING WITH NO SIMULATION TIME ENTERED

            Dim enteredSimTime As Integer = CInt(simulationTextbox.Text)
            'CONVERTS SIMULATION TIME TO INTEGER


            If ((enteredSimTime >= 100) And (isSimRunning = False)) Then
                'IF SIMULATION TIME IS LESS THAN 100 AND IS NOT RUNNING, THEN DISPLAY ERROR MESSAGE

                isSimRunning = True     'TO PREVENT MULTIPLE INSTANCES OF SIMULATION

                Dim pumpClass As New Pump()     'CREATES NEW PUMP OBJECT

                gallonsTextbox.Text = pumpClass.galProp()     'OUTPUTS INITIAL GALLONS IN TANK
                priceTextbox.Text = pumpClass.priceProp().ToString("c", New Globalization.CultureInfo("en-US", False))
                'OUTPUTS PRICE OF GALLON OF GAS


                Dim totalElapsedTime As Integer = 0     'SETS ELAPSED TIME TO ZERO

                statusListBox.Items.Add("Starting a new simulation...")
                statusListBox.Items.Add("Simulation Time is " + CStr(enteredSimTime) + " minutes.")


                While (enteredSimTime >= totalElapsedTime)

                    Dim customerClass As New Customer() 'CREATES NEW CUSTOMER OBJECT
                    Dim randIdle As Integer = customerClass.randomIdleTimeProp()
                    'PUTS RANDOM IDLE TIME INTO VARIABLE

                    Dim randGas As Integer = customerClass.randomGasPumpedProp()
                    'PUTS RANDOM GALLONS PUMPED INTO VARIABLE


                    statusListBox.Items.Add(pumpClass.displayPumpTankStats())
                    'DISPLAY NUMBER OF GALLONS OF GAS IN TANK 

                    statusListBox.Items.Add(pumpClass.displayPumpPriceStats())
                    'DISPLAY PRICE OF GAS PER GALLON


                    totalElapsedTime = randIdle + totalElapsedTime
                    'ADD RANDOM ELAPSED TIME TO TOTAL ELAPSED TIME


                    statusListBox.Items.Add("The idle time is " + CStr(randIdle) + _
                        " minutes and we are " + CStr(totalElapsedTime) + " minutes into the simulation.")
                    'DIPSLAY IDLE TIME AND TOTAL TIME

                    statusListBox.Items.Add(pumpClass.pumpTransaction(randGas))
                    'DISPLAY GAS PUMP TRANSACTION

                End While

                isSimRunning = False    'END OF SIMULATION, CHANGE STATUS TO REFLECT
                statusListBox.Items.Add("Time is up. The simluation has ended.")    'NOTICE OF END OF SIMULATION
            Else

                'OUTPUTS ERROR MESSAGE IF SIMULATION TIME IS NOT GREAT ENOUGH
                statusListBox.Items.Add("Simulation Time needs to be equal or greater than 100 minutes")
                isSimRunning = False

            End If
        Else

            statusListBox.Items.Add("Simulation Time was not entered. Please enter a time.")
            'ERROR MESSAGE

        End If


    End Sub


    Public Class Pump

        Public gal As Integer           'GALLONS AVAILABLE OF GAS
        Private price As Decimal         'PRICE OF GAS
        Private tankLevel As Integer    'TANK LEVEL OF GAS 



        Dim gasPumped As Integer        'AMOUNT OF GAS PUMPED
        Dim pricePumped As Double       'PRICE OF THE AMOUNT OF GAS PUMPED 

        Public Sub New()        'DEFAULT CONSTRUCTOR
            gal = 500           'INITIALIZE GALLONS TO 500
            price = 2.9         'INITIALIZE PRICE TO 2.90
        End Sub


        Public Property priceProp() As Decimal
            'GETTER AND SETTER FOR PRICE
            Get
                Return price
            End Get
            Set(ByVal value As Decimal)
                If value >= 0 Then
                    price = value
                End If
            End Set
        End Property

        Public Property galProp() As Integer
            'GETTER AND SETTER FOR GALLONS
            Get
                Return gal
            End Get
            Set(ByVal value As Integer)
                If gal >= 0 Then
                    gal = value
                End If
            End Set
        End Property

        Public Property tankLevelProp() As Integer
            'GETTER AND SETTER FOR TANK LEVEL
            Get
                Return tankLevel
            End Get
            Set(ByVal value As Integer)
                If value >= 0 Then
                    tankLevel = value
                End If
            End Set
        End Property

        Public Function displayPumpTankStats() As String

            Return "The gas tank has " + CStr(galProp()) + " gallons of gas."
            'DISPLAYS THE AMOUNT OF GAS IN THE TANK

        End Function    'END OF DISPLAYPUMPSTATS FUNCTION

        Public Function displayPumpPriceStats() As String

            Return "The price per gallon of gas is " + CStr(priceProp().ToString("c", New Globalization.CultureInfo("en-US", False)))
            'DISPLAYS THE PRICE PER GALLON OF GAS

        End Function

        Public Function pumpTransaction(ByVal gasRequested As Integer) As String
            Dim finalOutputString As String

            If gasRequested > gal Then
                'IF THERE IS MORE GAS REQUESTED THAN WHAT IS AVAILABLE
                gasPumped = gal
            Else
                gasPumped = gasRequested
            End If

            gal = gal - gasPumped   'CALCULATE THE AMOUNT OF GAS LEFT IN TANK
            pricePumped = gasPumped * price 'CALCULATE PRICE OF GAS THAT WAS PUMPED


            'DISPLAY OUTPUT
            finalOutputString = "Gallons requested: " + CStr(gasRequested) + ", Gallons pumped: " + CStr(gasPumped) + _
                ", Gallons remaining: " + CStr(gal) + ", Price: " + CStr(pricePumped.ToString("c", New Globalization.CultureInfo("en-US", False)))

            Return finalOutputString
        End Function    'END OF PUMPTRANSACTION FUNCTION
    End Class   'END OF PUMP CLASS


    Public Class Customer
        Private randomIdleTime As Integer
        Private randomGasPumped As Integer

        Public Sub New()
            randomIdleTime = randNumber(1, 16)    'RANDOM AMOUNT OF IDLE TIME
            randomGasPumped = randNumber(3, 20)    'RANDOM AMOUNT OF GAS PUMPED
        End Sub

        Public Property randomIdleTimeProp() As Integer
            'GETTER AND SETTER FOR RANDOM IDLE TIME
            Get
                Return randomIdleTime
            End Get
            Set(ByVal value As Integer)
                value = randNumber(1, 16)
                If value >= 0 Then
                    randomIdleTime = value
                End If
            End Set
        End Property

        Public Property randomGasPumpedProp() As Integer
            'GETTER AND SETTER FOR RANDOM AMOUNT OF GAS PUMPED
            Get
                Return randomGasPumped
            End Get
            Set(ByVal value As Integer)
                value = randNumber(3, 20)
                If value >= 0 Then
                    randomGasPumped = value
                End If
            End Set
        End Property

        Public Function randNumber(ByVal maxOfRange As Integer, ByVal minOfRange As Integer) As Integer
            'START RANDOM NUMBER GENERATOR
            Dim r As New Random(System.DateTime.Now.Millisecond)

            If minOfRange > maxOfRange Then 'IF THE MIN NUMBER IS OUTSIDE OF THE RANGE 
                Dim t As Integer = minOfRange   'COPY NUMBER TO TEMP VARIABLE
                minOfRange = maxOfRange     'SET MAX AS MIN
                maxOfRange = t  'SET TEMP TO MAX 
            End If

            Return r.Next(minOfRange, maxOfRange)   'RETURNS RANDOM VALUE

        End Function    'END OF RANDNUMBER FUNCTION

        Protected Overrides Sub Finalize()  'DESTRUCTOR

        End Sub
    End Class   'END OF CUSTOMER CLASS

End Class   'END OF FORM1 CLASS
