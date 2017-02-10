
void setup() {
  Serial.begin(9600);
  randomSeed(2);

}
int head(){
  int ran;
  ran=random(1,21);
  Serial.print("Numero random --> ");
  Serial.println(ran);
  delay(2000);
}
void loop() {
  head();

}
