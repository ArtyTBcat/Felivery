int number_pins = 8;
int motor_pins[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
float motor_percent_active[8] = {1, 0, 0, 1, 0, 0, 0, 0};// duty cycle

int frequency;

void setup() {
  Serial.begin(57600);
  for (int i = 0; i < number_pins; i++) {
    pinMode(motor_pins[i], OUTPUT);
  }
}

int previous_milli;
int loop_frequency_counter;
int count_time_period;
void loop() {

  //update loop frequency every second
  int milliseconds = millis();
  if (milliseconds - previous_milli >= 1000) {
    // Serial.print("milliseconds: "); Serial.print(milliseconds - previous_milli);
    previous_milli = milliseconds;
    frequency = loop_frequency_counter;
    loop_frequency_counter = 0;    
    // Serial.print(" frequency: "); Serial.print(frequency); Serial.println(" hz");
  }
  loop_frequency_counter++;

  // calculated_pwm_freq_milliseconds & turn off
  float time_period;
  for(int i = 0; i < number_pins; i++) {
    time_period = 1 / frequency;
    float duty_cycle = motor_percent_active[i];
    float Ton = time_period * duty_cycle;
    if (count_time_period >= Ton){
      digitalWrite(motor_pins[i], LOW); // turn off
    }
  }

  // turn on the motor
  if (count_time_period >= time_period) { //turn on motor every time period
    for (int i = 0; i < number_pins; i++) {
      if (motor_percent_active[i] > 0) { // turn on only active value > 0
        digitalWrite(motor_pins[i], HIGH);
      }
    }
    count_time_period = 0;
  }
  count_time_period++;

}
