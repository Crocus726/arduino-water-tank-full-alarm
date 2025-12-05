#define water_pump_motor 0
#define water_level_sensor 0
#define buzzer 0
#define led 0
#define button 0

void setup() {
  pinMode(water_pump_motor, OUTPUT);
  pinMode(water_level_sensor, INPUT_PULLUP);
  pinMode(led, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  /*  */
  if (digitalRead(water_level_sensor) == 1) Serial.println("물 탱크 가득 차지 않음");

  /*  */
  else {
    Serial.println("물 탱크 가득 참");

    digitalWrite(led, HIGH); tone(buzzer, 784, 500);
    delay(500);
    digitalWrite(led, LOW); noTone(buzzer);
    delay(500);
  }

  /*  */
  while (digitalRead(button) == 0) {
    digitalWrite(water_pump_motor, HIGH);
  } digitalWrite(water_pump_motor, LOW);
}
