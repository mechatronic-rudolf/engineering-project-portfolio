///////////////////////// GLOBAL PIN DECLARATIONS
  // Traffic LED pins setup
  int redLight = 5;
  int amberLight = 6;
  int greenLight = 7;

  // Input Pin for Pedestrian Button
  int pedestrianPin = 12;
///////////////////////// END OF GLOBAL PIN DECLARATIONS

/////////////////// SETUP
void setup() {
  // Traffic LED pins setup
  pinMode(redLight, OUTPUT);
  pinMode(amberLight, OUTPUT);
  pinMode(greenLight, OUTPUT);

  // Set pedestrian pin to input
  pinMode(pedestrianPin, INPUT_PULLUP);

  //Start the Serial Monitor
  Serial.begin(9600);
}

/////// Pedestrian Crossing Function
void pedestrianCrossing(){
  delay(100);
  digitalWrite(greenLight, LOW);
  digitalWrite(amberLight, HIGH);
  delay(5000);
  digitalWrite(amberLight, LOW);
  digitalWrite(redLight, HIGH);
  delay(10000);
  digitalWrite(redLight, LOW);
  int i = 0;
  for (i = 0; i<= 10; i++){
    digitalWrite(amberLight, HIGH);
    delay(250);
    digitalWrite(amberLight, LOW);
    delay(250);
  }
}

/////// LOOP
void loop() {
  // Condition
  int pedestrianButton = digitalRead(pedestrianPin);
  digitalWrite(greenLight, HIGH);

  // Pedestrian Button Check
  if (pedestrianButton == HIGH) {
    Serial.println("Button Pressed");
    delay(1000);
    pedestrianCrossing();
  } 
}