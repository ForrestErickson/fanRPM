//fanRMP.ino
// From: https://fdossena.com/?p=ArduinoFanControl/i.md



#define PIN_SENSE 2 //where we connected the fan sense pin. Must be an interrupt capable pin (2 or 3 on Arduino Uno)
#define DEBOUNCE 0 //0 is fine for most fans, crappy fans may require 10 or 20 to filter out noise
#define FANSTUCK_THRESHOLD 500 //if no interrupts were received for 500ms, consider the fan as stuck and report 0 RPM
//Interrupt handler. Stores the timestamps of the last 2 interrupts and handles debouncing
unsigned long volatile ts1 = 0, ts2 = 0;
void tachISR() {
  unsigned long m = millis();
  if ((m - ts2) > DEBOUNCE) {
    ts1 = ts2;
    ts2 = m;
  }
}
//Calculates the RPM based on the timestamps of the last 2 interrupts. Can be called at any time.
unsigned long calcRPM() {
  if (millis() - ts2 < FANSTUCK_THRESHOLD && ts2 != 0) {
    return (60000 / (ts2 - ts1)) / 2;
  } else return 0;
}
void setup() {
  pinMode(PIN_SENSE, INPUT_PULLUP); //set the sense pin as input with pullup resistor
  attachInterrupt(digitalPinToInterrupt(PIN_SENSE), tachISR, FALLING); //set tachISR to be triggered when the signal on the sense pin goes low
  Serial.begin(115200); //enable serial so we can see the RPM in the serial monitor
  delay(100);
  Serial.println("****** fanRMP.ino ******");
  Serial.println("Version: 0.1");
}
void loop() {
  delay(100);
  Serial.print("RPM:");
  Serial.println(calcRPM());
}
