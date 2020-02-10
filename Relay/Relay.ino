
int portRelay = 2;

void setup() {

  pinMode(portRelay, OUTPUT);

  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  Serial.println("Nível alto. NO = acionado; NF = oposto de NO.");
  digitalWrite(portRelay, HIGH);
  delay(5000);
  digitalWrite(portRelay, LOW);
  Serial.println("Nível baixo... NO = oposto de NF; NF = acionado.");
  delay(5000);
  
  // put your main code here, to run repeatedly:

}
