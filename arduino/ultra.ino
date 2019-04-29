/* Arduino Ultrasonic Music Sensor. Sends Serial Commands back to a computer of the notes to turn on.
 *  
 *  
 */

const int TRIG = 2;
const int ECHO = 3;

const long MIN_VAL = 2; //Measured in Inches
const long MAX_VAL = 22; //inches

long duration, inches;

int val = 0; //Byte to send

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(2);
  digitalWrite(TRIG, LOW);
  
  duration = pulseIn(ECHO, HIGH);

  inches = microsecondsToInches(duration);

  if (inches < MIN_VAL) val = 0;
  else if (inches > MAX_VAL) val = 127;
  else {
    val = (int)(((float)(inches - MIN_VAL) / (MAX_VAL - MIN_VAL)) * 127);
    digitalWrite(LED_BUILTIN, HIGH);
  }

  Serial.write(val);

  delay(25);
}

long microsecondsToInches(long microseconds) {
  return microseconds/74/2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds/29/2;
}
