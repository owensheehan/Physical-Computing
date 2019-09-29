
int sensorValue;
int sensorLow = 0;
int sensorHigh = 1023;
const int LED_PIN = 13;
void setup() {
pinMode(LED_PIN, OUTPUT);
digitalWrite(LED_PIN, HIGH);
// calibrate for the first five seconds after program runs
while (millis() < 5000) {
sensorValue = analogRead(A0);
if (sensorValue > sensorHigh) {
sensorHigh = sensorValue;
}
if (sensorValue < sensorLow) {
sensorLow = sensorValue;
}
}
// turn the LED off, signaling the end of the calibration period
digitalWrite(LED_PIN, LOW);
}
void loop() {
sensorValue = analogRead(A0);
// map the sensor values to a wide range of pitches
int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
// play the tone for 20 ms on pin 8
tone(8, pitch, 20);
// wait for 10 ms to give sound time to play
delay(10);
}

