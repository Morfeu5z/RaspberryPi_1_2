int kp1 = 11, kp2 = 12, kp3 = 10; //number of pin for BUTTON
String k1 = "A", k2 = "D", k3 = " "; //ASCII symbol
int d1 = 5, d2 = 6, d3 = 7; //number of pin for LED
String serialData; //Data from ruspberry
boolean newData;

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
  int ledNum = serialData[0];
  boolean ledStat;
  if(serialData.length()>1){
    Serial.println(serialData);
    if(serialData[1]==0){
      ledStat = 0;
    }else{
      ledStat = 1;
    }
    while(newData == true){
      if(ledNum >=2){
        digitalWrite(ledNum, ledStat);
      }else if(ledNum == 0){
        reset();
      }
    }
  }
}

// Used to read button and send emulated keboard key.
void ReadKeyboard(){
  if(digitalRead(kp1)==0){
    Serial.println(k1); 
    delay(50);
  }else if(digitalRead(kp2)==0){
    Serial.println(k2);
    delay(50);
  }else if(digitalRead(kp3)==0){
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
