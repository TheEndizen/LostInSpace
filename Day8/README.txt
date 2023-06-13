Depending on the RGB LED:

1. the order of the red, blue, and green leads may be switched
2. longest lead may be an anode instead of a cathode

The 1st issue is resolved by mapping the software to the corresponding pins/leads.
The 2nd issue requires modification of the hardware so that 5V goes through the anode.

................................................................................

RGB Pinout (physical)
-	Red
--	Cathode
-	Green
-	Blue

RGB Pinout (tinkerCAD)
-	Red
--	Cathode
-	Blue
-	Green