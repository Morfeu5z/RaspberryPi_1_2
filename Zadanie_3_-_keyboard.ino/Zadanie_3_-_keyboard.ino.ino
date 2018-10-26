int kp1 = 2, kp2 = 3, kp3 = 4; //number of pin for BUTTON
String k1 = "A", k2 = "D", k3 = " "; //ASCII symbol
int d1 = 5, d2 = 6, d3 = 7; //number of pin for LED
char serialData; //Data from ruspberry
boolean newData, mess1=0, mess2=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(kp1, INPUT_PULLUP);
  pinMode(kp2, INPUT_PULLUP);
  pinMode(kp3, INPUT_PULLUP);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  Serial.println("Start program.");
  for(int i = d1; i<=d3; i++){
    digitalWrite(i, HIGH);
    delay(200);
  }
  delay(1000);
  for(int i = d1; i<=d3; i++){
    digitalWrite(i, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  GetSerialData();
  ChangeLED();
  ReadKeyboard();
}

//Waiting for data from ruspberry
void GetSerialData(){
  if (Serial.available()>0){
    newData = true;
    serialData = Serial.read();
  }
}

//Check how many player have lives.
void ChangeLED(){
  int ledNum = int((serialData - '0'));
  boolean ledStat;
  if(newData == true){
    Serial.println("Get signal: " + String(ledNum));
    if(digitalRead(ledNum)==LOW){
      digitalWrite(ledNum, HIGH);
      Serial.println("Pin " + String(ledNum) + " is HIGH");
    }else{  
      digitalWrite(ledNum, LOW);
      Serial.println("Pin " + String(ledNum) + " is LOW");
    }
    newData = false;
  }
}

void BtnPressTest(int x){
    digitalWrite(x, HIGH);
    delay(500);
    digitalWrite(x, LOW);
  }

// Used to read button and send emulated keboard key.
void ReadKeyboard(){
  if(digitalRead(kp1)==0){
    BtnPressTest(d1);
    Serial.println(k1); 
    delay(50);
  }else if(digitalRead(kp2)==0){
    BtnPressTest(d2);
    Serial.println(k2);
    delay(50);
  }else if(digitalRead(kp3)==0){
    BtnPressTest(d3);
    Serial.println(k3);
    delay(50);
  }
}

//Reset to default set
void reset(){
    k1 = "A";
    k2 = "D";
    k3 = " ";
    for(int i=5;i<=7;i++)digitalWrite(i,LOW);
  }
