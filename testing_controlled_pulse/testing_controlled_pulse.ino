const byte interruptPin = 2;
float delaytime3 = 0.010;
float delaytime4 = 0.015;
float delaytime5 = 0.002;
float delaytime6 = 0.002;
float delaytime7 = 0.002;
unsigned long previousTime = 0;
unsigned long previousTime1 = 0;
//unsigned long previousTime2 = 0;
//unsigned long previousTime3 = 0;
//unsigned long previousTime4 = 0;
float parameter = 0.020;
float increase = 0.003;
bool casePressed;
void setup ()
{
  Serial.begin(9600);

///**Each Pin represents a different channel (remember low output = higher-going pulses)**///

  pinMode (3, OUTPUT) ;
  digitalWrite (3, LOW) ;  // or set to HIGH for low-going pulses.

  pinMode (4, OUTPUT) ;
  digitalWrite (4, LOW) ;  // or set to HIGH for low-going pulses.

  pinMode (5, OUTPUT) ;
  digitalWrite (5, LOW) ;  // or set to HIGH for low-going pulses.

  pinMode (6, OUTPUT) ;
  digitalWrite (6, LOW) ;  // or set to HIGH for low-going pulses.

  pinMode(7, OUTPUT);
  digitalWrite (7, LOW) ;  // or set to HIGH for low-going pulses.

 attachInterrupt(digitalPinToInterrupt(2), Runtime, RISING);
}

// The GUI will call serialport.write("s30.0001")
// or serialport.write("t3")
// or .write("r3") and then will do a serialport.readline();
void loop ()
{
  static byte c1;
  static byte c2;
  
  while (Serial.available()) {
    c1 = c2;
    c2 = Serial.read();
    uint16_t combined = (c1 << 8) | c2;
    switch (combined) {
      case 's3':
        delaytime3 = Serial.parseFloat();
        break;
      case 't3':
        PIND = 0x08;
        break;
      case 'r3':
        Serial.println((PORTD & 0x08) != 0);
        break;
    }
  }
}



void Runtime(){
  unsigned long currentTime = micros();
  unsigned long currentTime1 = micros();
  unsigned long currentTime2 = micros();
  unsigned long currentTime3 = micros();
  unsigned long currentTime4 = micros();
  PIND = 0x08;
//  PIND = 0x20;
//  PIND = 0x40;
//  PIND = 0x80;
  if(currentTime - previousTime > delaytime3) {
    PIND = 0x08;
  }
  
  PIND = 0X10;
  if(currentTime1 - previousTime1 > delaytime4) {
    PIND = 0x10;
  }

//  if(currentTime2 - previousTime2 > delaytime5) {
//    PIND = 0x20;
//  }
//  if(currentTime3 - previousTime3 > delaytime6) {
//    PIND = 0x40;
//  }
//  if(currentTime4 - previousTime4 > delaytime7) {
//    PIND = 0x80;
//  }
}



