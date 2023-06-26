/* HelloRGB.ino
 * Simple circuit using RGB Led (R, Cathode, G, B), being Cathode the longest pin (and GND).  
 * 
 * Herman. June 25, 2023
 */
//region Board config
#define RED 6
#define GREEN 5
#define BLUE 3
//endregion Board config

#define DELAY 10

#define DEBUG_ENABLED false

void setup() {  
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  // digitalWrite(RED, HIGH); // LOW  

  #if DEBUG_ENABLED
    Serial.begin(9600);
  #endif
}

void loop() {
  // put your main code here, to run repeatedly:
  fade(RED, GREEN);
  fade(GREEN, BLUE);
  fade(BLUE, RED);  
}

void fade(int led1, int led2) {
  int v1 = 255;  
  for(int i = 0; i < 255 ; i++) {    
    v1--;
    
    #if DEBUG_ENABLED
      debug(led1, v1, led2, i);
    #endif
    
    analogWrite(led1, v1);
    analogWrite(led2, i);    
    delay(DELAY);
  }
}

#if DEBUG_ENABLED
void debug(int led1, int value1, int led2, int value2) {
  debug(led1, v1);
  debug(led2, i);
  Serial.println("");
}

void debug(int led, int value) {
  switch(led) {
    case RED:
      Serial.print("R ");
      break;
    case GREEN:
      Serial.print("G ");
      break;
    case BLUE:
      Serial.print("B ");
      break;

  }
  Serial.print(value);
  Serial.print(" ");
}
#endif