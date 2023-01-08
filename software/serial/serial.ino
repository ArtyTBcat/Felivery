int motor_pins[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
void setup() {
  pinMode(LED_BUILTIN, HIGH);
  Serial.begin(115200);
  for (int i = 0; i < 8; i++) {
    pinMode(motor_pins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(2, HIGH);
  // digitalWrite(4, HIGH);
  // digitalWrite(6, HIGH);
  // digitalWrite(8, HIGH);
  String data;
  if (Serial.available()) {
    data = Serial.read();
    Serial.println(data);
    if (data == "49"){
      float motor[8] = { 1, 0, 0, 1, 1, 0, 0, 1 };
      for(int i = 0; i<8; i++){
        digitalWrite(motor_pins[i], motor[i]);
      }
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.print("w");
    }
    if (data == "50"){
      float motor[8] = { 0, 1, 0, 1, 0, 1, 0, 1 };
      for(int i = 0; i<8; i++){
        digitalWrite(motor_pins[i], motor[i]);
      }
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.print("a");
    }
    if (data == "51"){
      float motor[8] = { 0, 1, 1, 0, 0, 1, 1, 0 };
      for(int i = 0; i<8; i++){
        digitalWrite(motor_pins[i], motor[i]);
      }
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.print("s");
    }
    if (data == "52"){
      float motor[8] = { 1, 0, 1, 0, 1, 0, 1, 0 };
      for(int i = 0; i<8; i++){
        digitalWrite(motor_pins[i], motor[i]);
      }
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.print("d");
    }
    // digitalWrite(8, HIGH);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
    float motor[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
      for(int i = 0; i<8; i++){
        digitalWrite(motor_pins[i], motor[i]);
      }
  }
  
  Serial.println("hheeeallo");
  // serial();
  // digitalWrite(LED_BUILTIN, LOW);
  // digitalWrite(8, LOW);
}

byte data;
void serial() {
  if (Serial.available()) {
    data = Serial.read();
    Serial.println(data);
    if (data == "49") {
      float motor[8] = { 1, 0, 0, 1, 1, 0, 0, 1 };
      for(int i = 0; i<8; i++){
        digitalWrite(motor_pins[i], motor[i]);
      }
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.print("w");
    }

    else if (data == "50") {

      Serial.print("a");
    } else if (data == "51") {

      Serial.print("s");
    } else if (data == "52") {

      Serial.print("d");
    }
  }
}
