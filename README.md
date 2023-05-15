# fanRPM
A Controller for a Four Wire Brushless DC Fan

The fan under test was a GDSTIME model 1238 120mm 12V PWM Fan, 120mm x 38mm 213CFM DC Brushless Cooling Fan

Circuit Description:
A 10K pot with wiper to A0,
A 300 OHm resistor from D9 out to the PWM in on the fan.
A 10K pull up on the FG (Frequency Generator) pin of the fan.

Screen capture of PWM and FG signals.
![CH1_PWM_CH2_FG.png](CH1_PWM_CH2_FG.png)

## Notes on Fan Test
With in the fan, the PWM equivilant circuit is a 5K resistor pull up to 5V Vcc.
The PWM short curcuit current was 1mA

The FG (Frequency Generator) required a pull up resistor to Vcc. I used a 10K and got good waveform.

Limits of testing: 
My fan speed was limited by the 1Ammp current limit of my 12V supply.  I got maxium fan speed with he A0 adjusted to about the mid point.

Program serial monitor output when adjusting for maximum fan RPM.
![image](https://github.com/ForrestErickson/fanRPM/assets/5836181/a9d557da-bb3a-45a3-9584-eb1630191ea1)



