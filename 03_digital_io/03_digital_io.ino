
void setup() {
  // put your setup code here, to run once:
  pinMode(D0, OUTPUT);
  pinMode(D3, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(D3)) digitalWrite(D0, 0);  
  else digitalWrite(D0, 1); 
}
