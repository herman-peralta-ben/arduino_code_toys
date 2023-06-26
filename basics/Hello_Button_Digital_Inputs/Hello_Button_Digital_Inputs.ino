//www.elegoo.com
//2016.12.08

int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;

#define DEBUG_ENABLED false 

void setup() {
  pinMode(ledPin, OUTPUT);
  // INPUT_PULLUP - the default value for the input is HIGH, unless it is pulled LOW by the action of pressing the button
  // INPUT - not working with buttons
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
  
  #if DEBUG_ENABLED 
    Serial.begin(9600);
  #endif
}

void loop() {
  // Since the input is normally HIGH and only goes LOW when the button is pressed
  if (digitalRead(buttonApin) == LOW) {
    #if DEBUG_ENABLED
      Serial.println("A off, turning led on");
    #endif
    digitalWrite(ledPin, HIGH);
  } else {
    #if DEBUG_ENABLED
      Serial.println("A on");
    #endif
  }
  if (digitalRead(buttonBpin) == LOW) {
    #if DEBUG_ENABLED
      Serial.println("B off, turning led off");
    #endif
    digitalWrite(ledPin, LOW);
  } else {
    #if DEBUG_ENABLED
      Serial.println("B on");
    #endif
  }
}
