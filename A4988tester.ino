// A4988 driver test routine
#define ENABLE 6
#define STEP 4
#define DIR 2

#define STEPS_PER_ROTATION 400



void setup() {
  Serial.begin(57600);

  pinMode(ENABLE,OUTPUT);
  pinMode(STEP,OUTPUT);
  pinMode(DIR,OUTPUT);
}


void stepNow(int totalSteps) {
  Serial.print(totalSteps);
  Serial.println(F(" steps."));

  int i;
  for(i=0;i<totalSteps;++i) {
    digitalWrite(STEP,HIGH);
    delayMicroseconds(700);
    digitalWrite(STEP,LOW);
    delayMicroseconds(700);
  }
}


void walkBothDirections() {
  Serial.println(F("dir LOW"));
  digitalWrite(DIR,LOW);
  stepNow(STEPS_PER_ROTATION);
  
  Serial.println(F("dir HIGH"));
  digitalWrite(DIR,HIGH);
  stepNow(STEPS_PER_ROTATION);
}


void loop() {
  Serial.println(F("Enable HIGH"));
  digitalWrite(ENABLE,HIGH);
  walkBothDirections();
  Serial.println(F("Enable LOW"));
  digitalWrite(ENABLE,LOW);
  walkBothDirections();
}
