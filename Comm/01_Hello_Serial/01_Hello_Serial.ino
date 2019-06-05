int cnt;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  cnt=0;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(cnt);
  delay(1000);
  cnt=cnt+1;
}
