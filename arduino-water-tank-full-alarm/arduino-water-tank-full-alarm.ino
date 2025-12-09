#define water_pump_motor 0
#define water_level_sensor 0
#define buzzer 0
#define led 0
#define button 0

void setup() {
  /* 핀 모드 설정 */
  pinMode(water_pump_motor, OUTPUT);
  pinMode(water_level_sensor, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  Serial.begin(115200); // 모니터링용 시리얼 통신 시작
}

void loop() {
  /* 수위 센서 인식 안 되면 (수위 센서가 위치한 수위까지 물이 안 차오르면) */
  if (digitalRead(water_level_sensor) == 1) Serial.println("물 탱크 가득 차지 않음");

  /* 수위 센서 인식되면 (수위 센서가 위치한 수위까지 물이 차오르면) */
  else {
    Serial.println("물 탱크 가득 참");

    /* 0.5초 간격으로 LED, 부저 껐다 켜기 */
    digitalWrite(led, HIGH); tone(buzzer, 784, 500);
    delay(500);
    digitalWrite(led, LOW); noTone(buzzer);
    delay(500);
  }

  /* 버튼이 눌린 상태라면 */
  while (digitalRead(button) == 0) {
    digitalWrite(water_pump_motor, HIGH); // 워터 펌프 모터 켜기
  } digitalWrite(water_pump_motor, LOW); // 버튼 떼지면 워터 펌프 모터 끄기
}
