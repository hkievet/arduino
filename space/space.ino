int switchState = 0;

int i = 0;

void setup(){
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

}

void loop(){
  if (digitalRead(2)){
    //Red -> Yellow -> Green -> Yellow (repeat when pressed)
    if (i == 0){
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);  
    }
    else if (i == 1 || i == 3){
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);    
    }
    else if (i == 2){    
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);  
    } 
    i++;
    if (i == 4){
      i = 0;
    }
    delay(300);
  }
  else {
    delay(50);
  }

}
