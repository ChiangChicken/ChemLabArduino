int ledPin = 13; // LED is attached to digital pin 13
int x = 0; // variable to be updated by the interrupt

//variables to keep track of the timing of recent interrupts
unsigned long button_time = 0;  
unsigned long last_button_time = 0; 

void setup() {                
  //enable interrupt 0 which uses pin 2
  //jump to the increment function on falling edge
  attachInterrupt(0, increment, FALLING);
  Serial.begin(9600);  //turn on serial communication
}

void loop() {
  switch (x) {
    case 1:
      PWM
      break;
    case 2:
      PWM
      break;
    case 3:
      PWM
      break;
    case 4:
      PWM
      break;
    case 5:
       PWM
       break;
  }

}

// Interrupt service routine for interrupt 0
void increment() {
  button_time = millis();
  //check to see if increment() was called in the last 250 milliseconds
  if (button_time - last_button_time > 250)
  {
    x++;
    digitalWrite(ledPin, HIGH);
    last_button_time = button_time;
  }
}
