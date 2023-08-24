// C++ code
//
int color[4];

void setup()
{
  //Red button
  pinMode(22, INPUT_PULLUP); //switch
  pinMode(23, OUTPUT); // LED
  
  //Yellow
  pinMode(19, INPUT_PULLUP); //switch
  pinMode(21, OUTPUT); // LED
  
  //green
  pinMode(5, INPUT_PULLUP); //switch
  pinMode(18, OUTPUT); // LED
  
  //blue
  pinMode(15, INPUT_PULLUP); //switch
  pinMode(4, OUTPUT); //LED

  Serial.begin(115200);
}

// void switchLED(int num){
//   switch(num){
//     case 0:
//       digitalWrite(23, HIGH);
//      delay(1000); // Wait for 1000 millisecond(s)
//      digitalWrite(23, LOW);      
//      break;
//     case 1:
//      digitalWrite(21, HIGH);
//      delay(1000); // Wait for 1000 millisecond(s)
//      digitalWrite(21, LOW);      
//      break;
//     case 2:
//      digitalWrite(18, HIGH);
//      delay(1000); // Wait for 1000 millisecond(s)
//      digitalWrite(18, LOW);      
//      break;
//     case 3:
//      digitalWrite(4, HIGH);
//      delay(1000); // Wait for 1000 millisecond(s)
//      digitalWrite(4, LOW);     
//      break;
//     default:
//      break;
//   } 
// }

void loop()
{  
 for(int i = 0; i<4; i++) {
   color[i] = random(1,5);
 }

 Serial.println("game");
 delay(500);

 for(int i = 0; i<4; i++){
   if(color[i]==1){
     digitalWrite(23, HIGH);
     delay(1000);
     digitalWrite(23, LOW);
   }
   if(color[i]==2){
     digitalWrite(21, HIGH);
     delay(1000);
     digitalWrite(21, LOW);
   }
   if(color[i]==3){
     digitalWrite(18, HIGH);
     delay(1000);
     digitalWrite(18, LOW);
   }
   if(color[i]==4){
     digitalWrite(4, HIGH);
     delay(1000);
     digitalWrite(4, LOW);
   }
   delay(50);
 }
  int click[4] = {0};
   Serial.println("game start!");

  for(int i = 0; i<4; i++){
    while(true) {
      if(digitalRead(22) == LOW){
        digitalWrite(23, HIGH);
        click[i] = 1;
        break;
      }
      if(digitalRead(19) == LOW){
        digitalWrite(21, HIGH);
        click[i] = 1;
        break;
      }
      if(digitalRead(5) == LOW){
        digitalWrite(18, HIGH);
        click[i] = 1;
        break;
      }
      if(digitalRead(15) == LOW){
        digitalWrite(4, HIGH);
        click[i] = 1;
        break;
      }
      delay(500);
      light_off();
    }

    if(!check(click, i+1)){
      light_on();
      delay(100);
      light_off();
      delay(100);
      light_on();
      delay(100);
      light_off();
      delay(100);
      break;
    }
  }
}

bool check(int click[], int count) {
    for(int i = 0; i<count; i++){
      if(click[i] != color[i]) {
        Serial.println("over");
        return false;
      } else {
        Serial.print(i);
        Serial.println("Success");
      }

      if(i == 3) {
        Serial.println("win!");
      light_on();
      delay(100);
      light_off();
      delay(100);
      light_on();
      delay(100);
      light_off();
      delay(100);
      }
    }
    return true;
  }

void light_on(){
  digitalWrite(23, HIGH);
  digitalWrite(21, HIGH);
  digitalWrite(18, HIGH);
  digitalWrite(4, HIGH);
}

void light_off(){
  digitalWrite(23, LOW);
  digitalWrite(21, LOW);
  digitalWrite(18, LOW);
  digitalWrite(4, LOW);
  }
