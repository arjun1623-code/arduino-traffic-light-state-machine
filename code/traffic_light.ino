int current_state;
int previous_state = HIGH;
unsigned long lastPressTime = 0;
const unsigned long DEBOUNCE_DELAY = 50;

enum TrafficState{
  RED,
  GREEN,
  BLUE
};
TrafficState state=RED;
void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(13, INPUT_PULLUP);
}
void loop() {
  current_state = digitalRead(13);
  if ((current_state !=previous_state) && (millis() - lastPressTime >= DEBOUNCE_DELAY)  ){
    lastPressTime = millis();  // ← Reset ONLY when you call function
    if (current_state==LOW){
      TrafficLightController(); 
    }
  }
  previous_state = current_state;
}
void TrafficLightController() {
  if (state == RED) {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  } else if (state == GREEN) {
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
  } else if (state == BLUE) {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
  }
  state=(state+1)%3;
}
