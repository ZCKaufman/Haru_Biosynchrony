const int GSR = A0;
const int PPG = A1;
int GSRVal;
int PPGVal;

void setup() {
  Serial.Begin(9600);
  pinMode(GSR, OUTPUT);
  pinMode(PPG, OUTPUT);
  delay(1000);

}

void loop() {
  GSRVal = analogRead(GSR);
  PPGVal = analogRead(PPG);
  Serial.print("PPG Val");
  Serial.println(PPGVal);
  Serial.print("GSR Val");
  Serial.println(GSR);

}
