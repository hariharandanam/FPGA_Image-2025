// C++ code
unsigned long block = millis();
int i = 9;
void setup()
{
  Serial.begin(9000);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  //digitalWrite(13,HIGH);
  //digitalWrite(9,HIGH);
  //digitalWrite(10,HIGH);
  //digitalWrite(11,HIGH);
  //digitalWrite(12,HIGH);
  pinMode(A5,INPUT);
  block = millis();
}
void loop()
{ 
  int a = analogRead(A5);
  float b = analogRead(A4);
  float wait = 1000 - (b/1023)*1000 + 100;
  //for(int i = 9;i<=13;i++){
  //  if((b != analogRead(A4)) || (a != analogRead(A5)) ){
  //  	break;
  //  }
  //	digitalWrite(i,HIGH);
  //  delay(wait);
  //  digitalWrite(i,LOW);
  //}
  if(i >=9 && i<= 13){
    if(millis() - block >= wait){
      digitalWrite(i,HIGH);
      block = millis();
      i+=1;
    }
    else{
      if(i != 9){
      for(int j = 9;j<=13;j++)	
        if(j != i-1)
        	digitalWrite(j,LOW);
      }
      else{
      	digitalWrite(9,LOW);
        digitalWrite(10,LOW);
        digitalWrite(11,LOW);
        digitalWrite(12,LOW);
      }  
    }
  }
  else{
  	i = 9;
  }
  if(a <= 341){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  }
  else if(a <= 642){
  	digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(2,LOW);
  }
  else{
  	digitalWrite(4,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);
  }
}

//https://www.tinkercad.com/things/jhhMD43LygU-week0project241177?sharecode=Z1lZSh6Zlb4gKEwJ4BPf_PFd1SCj0d-fCyczfuj5enE