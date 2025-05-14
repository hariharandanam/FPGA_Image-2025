int pot1 = A0;
int buzzer1=11;
int buzzer2=12;
int buzzer3=13;

int pot2=A1;
int led[5] = {2, 3, 4, 5, 6};

void setup() {
  Serial.begin(9600);
  pinMode(pot1,INPUT);
  pinMode(buzzer1,OUTPUT);
  pinMode(buzzer2,OUTPUT);
  pinMode(buzzer3,OUTPUT);
  
  pinMode(pot2,INPUT);
  for(int i = 0 ; i<5 ; i++){
    pinMode(led[i],OUTPUT);
  }  
}

void loop() {
  int x = analogRead(pot1);
  Serial.println(x);
  
  int y= analogRead(pot2);
  Serial.println(y);
  
  //for pot1
    
  digitalWrite(buzzer1, LOW);
  digitalWrite(buzzer2, LOW);
  digitalWrite(buzzer3, LOW);
  
  
  if(x>=0 && x<=341) digitalWrite(buzzer1,HIGH);
  else if( x>=342 && x<=682) digitalWrite(buzzer2,HIGH);
  else digitalWrite(buzzer3,HIGH);
    
    
  //for pot2
   int delayTime=y/4;
   for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      digitalWrite(led[j], (i == j) ? HIGH : LOW);
    }
    delay(delayTime);
  }
}
//https://www.tinkercad.com/things/9jZr4x6exvz-brave-kieran-sango?sharecode=1-TLkWVHLqgyPF-IpuRhvRPvziUo-RG4i_A35mkctoA