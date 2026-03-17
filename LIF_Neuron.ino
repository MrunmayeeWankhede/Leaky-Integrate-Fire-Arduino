int buttonPin = 2;
int ledPin = 13;

float membranePotential = 0.0;
float decayRate = 0.5;
int threshold = 2;

unsigned long lastDecayTime = 0;
int decayInterval = 500;

unsigned long refractoryStart = 0;
int refractoryPeriod = 1000;
bool inRefractory = false;

bool buttonWasPressed = false;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  unsigned long currentTime = millis();

  // Refractory Check
  if (inRefractory) {
    if (currentTime - refractoryStart >= refractoryPeriod) {
      inRefractory = false;
    } else {
      return;
    }
  }

  // Decay
  if (currentTime - lastDecayTime >= decayInterval) {
    lastDecayTime = currentTime;
    membranePotential -= decayRate;
    if (membranePotential < 0) membranePotential = 0;
  }

  // Button Input
  int buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && !buttonWasPressed) {   
    membranePotential++;
    buttonWasPressed = true;
  }
  if (buttonState == LOW) {
    buttonWasPressed = false;
  }

  // Fire
  if (membranePotential >= threshold) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);

    membranePotential = 0;
    inRefractory = true;
    refractoryStart = millis();

    while(digitalRead(buttonPin) == LOW) {}   // wait for release
    delay(50);
  }

  //Serial.println(membranePotential);
}
