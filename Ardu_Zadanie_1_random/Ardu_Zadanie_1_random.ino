int btn_on, l_str;
String string, zero;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  btn_on = 0;
  pinMode(13, OUTPUT);
  for (int i=2; i<10; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(10, INPUT_PULLUP);
  for (int i=2; i<10; i++){
    digitalWrite(i, LOW);
  }
}

void loop() {
  if(digitalRead(10) == LOW){
    if(btn_on == 0){
      int s = random(0, 255);
      string = String(s, BIN);
      l_str = string.length();
      zero = "";
      for(int i = 0; i<8-l_str; i++){
        zero = zero + "0";
      }
      string = zero + string;
      Serial.println("Liczba - " + String(s) + " - " + string);
    }
    btn_on = 1;
    digitalWrite(13, HIGH);
    for (int i=0; i<8; i++){
      if (string[i] == '0'){
        digitalWrite(i+2, LOW); 
      }else{
        digitalWrite(i+2, HIGH);
      }
    } 
    delay(3000);
  }
  if(digitalRead(10) == HIGH){
    btn_on = 0;
    digitalWrite(13,LOW);
    for (int i=2; i<10; i++){
      digitalWrite(i, LOW);
    }
  }
}
