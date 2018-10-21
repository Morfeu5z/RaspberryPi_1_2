String bin_to_string(){
  String temp_string   = String(random(0, 255), BIN);
  String zero = "";
  for (int counter=0; counter < (8 - temp_string.length()); counter++){
    zero += "0";
  }
  temp_string = zero + temp_string;
  return temp_string;
}


String summ_two_value(String value1, String value2){
  String final_result = "00000000";
  int ax = 0;
  for (int counter=7; counter >= 0; counter--){
   String s1(value1.charAt(counter));
   String s2(value2.charAt(counter));
   String text = s1+s2;
   switch (strtol(text.c_str(), NULL, 2)){  
    case 0:
      if(ax==0){ final_result.setCharAt(counter,'0'); ax=0; }else {final_result.setCharAt(counter,'1'); ax=0;} break;
    case 1:
      if(ax==0){ final_result.setCharAt(counter,'1'); ax=0; }else {final_result.setCharAt(counter,'0'); ax=1;} break;
    case 2:
      if(ax==0){ final_result.setCharAt(counter,'1'); ax=0; }else {final_result.setCharAt(counter,'0'); ax=1;} break;
    case 3:
      if(ax==0){ final_result.setCharAt(counter,'0'); ax=1; }else {final_result.setCharAt(counter,'1'); ax=1;} break;
    }
  }
  if(ax == 1){
    final_result = "1" + final_result;
  }else
    final_result = "0" + final_result;
  return final_result;
}

void setup(){
  /* bandwidth serial speed */
  Serial.begin(9600);

  /* Using 8-bits on          - pins 2..9
     auxilari(dodatkowy) bit  - pin 13
     button pin               - pin 10 */
  for(int i=2; i<10;i++){
    pinMode(i, OUTPUT);
  }
  pinMode(13, OUTPUT);
  //pinMode(A0, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  /* Random initializer
     reading state fo analog input */
  //randomSeed(analogRead(0));
  
}



void loop(){
  if(digitalRead(10) == LOW){
    String temp_value1; 
    String temp_value2;
    String temp_summ; 
    bin_to_string();
    temp_value1 = bin_to_string();
    temp_value2 = bin_to_string();
    temp_summ   = summ_two_value(temp_value1, temp_value2);
    int pin;
    for(pin=2; pin < 10; pin++){
      if(temp_summ.charAt(pin-1) == '1'){
        digitalWrite(pin, HIGH);
      }  
    }
    if(temp_summ.charAt(0) == '1'){
      digitalWrite(13, HIGH);
    }
    Serial.println("+"+ temp_value1);
    Serial.println(" "+ temp_value2);
    Serial.println(temp_summ);
    Serial.println("_________________");
    delay(3000);
  }
  for(int p=2; p < 10; p++){
    digitalWrite(p, LOW);
  }  
  digitalWrite(13, LOW);
    
}
