int toggle1,toggle2,toggle3,toggle4, initial;
bool spade, heart, club, diamond, full;

void setup() {
  pinMode(2,INPUT);  // put your setup code here, to run once:
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
  start();
}

void loop() {
  toggle1 = digitalRead(2);
  toggle2 = digitalRead(3);
  toggle3 = digitalRead(4);
  toggle4 = digitalRead(5);
  Serial.println(initial);
 
  if(toggle1 == 1){
    toggleSpade();
    delay(1000);
  }
  if(toggle2 == 1){
    toggleHeart();
    delay(1000);
  }
  if(toggle3 == 1){
    toggleClub();
    delay(1000);
  }
  if(toggle4 == 1){
    toggleDiamond();
    delay(1000);
  }
  if(club == spade && club == diamond && club == heart && club == 1){
    complete();
  }   

}

void toggleSpade(){//spade,heart, diamond
  if( spade == false){
    digitalWrite(6,HIGH);
    spade = true;
  }else{
    digitalWrite(6,LOW);
    spade = false;
  }
  if( heart == false){
    digitalWrite(7,HIGH);
    heart = true;
  }else{
    digitalWrite(7,LOW);
    heart = false;
  }  
  if( diamond == false){
    digitalWrite(9,HIGH);
    diamond = true;
  }else{
    digitalWrite(9,LOW);
    diamond = false;
  }  
}
void toggleHeart(){//heart spade club
  if( heart == false){
    digitalWrite(7,HIGH);
    heart = true;
  }else{
    digitalWrite(7,LOW);
    heart = false;
  }
  if( spade == false){
    digitalWrite(6,HIGH);
    spade = true;
  }else{
    digitalWrite(6,LOW);
    spade = false;
  }
  if( club == false){
    digitalWrite(8,HIGH);
    club = true;
  }else{
    digitalWrite(8,LOW);
    club = false;
  }  
}
void toggleClub(){//club heart diamond
  if( club == false){
    digitalWrite(8,HIGH);
    club = true;
  }else{
    digitalWrite(8,LOW);
    club = false;
  }
  if( diamond == false){
    digitalWrite(9,HIGH);
    diamond = true;
  }else{
    digitalWrite(9,LOW);
    diamond = false;
  }  
  if( heart == false){
    digitalWrite(7,HIGH);
    heart = true;
  }else{
    digitalWrite(7,LOW);
    heart = false;
  }
}
void toggleDiamond(){//diamond club spade
  if( diamond == false){
    digitalWrite(9,HIGH);
    diamond = true;
  }else{
    digitalWrite(9,LOW);
    diamond = false;
  }
  if( club == false){
    digitalWrite(8,HIGH);
    club = true;
  }else{
    digitalWrite(8,LOW);
    club = false;
  }
  if( spade == false){
    digitalWrite(6,HIGH);
    spade = true;
  }else{
    digitalWrite(6,LOW);
    spade = false;
  }
}
void complete(){
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  delay(500);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(500);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  delay(500);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(500);
  start();
}
void start(){
  for(int i = 6; i <= 9; i++){
    digitalWrite(i,LOW);
  }
  initial = random(6,9);
  digitalWrite(initial,HIGH);
  if(initial == 6){
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    spade = true;
  }else if(initial == 7){
    digitalWrite(6,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);    
    heart = true;
  }else if(initial == 8){
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);    
    club = true;
  }else if(initial == 9){
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(6,LOW);    
    diamond = true;
  }
}

