String cor = "";
float tempo = -999.;
int pin = -999.;
void setup () {
  Serial.begin(9600);
 
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop () {
  Serial.println("Dime a cor do LED que queres encender");
  while(Serial.available() == 0) {}//Espera até que haxa algo no buffer
  cor = Serial.readString ();
  Serial.println("Dime cantos segundos queres que este ON ou OFF");
  while(Serial.available() == 0){} //Espera até que haxa algo no buffer
  tempo = 1000 * Serial.parseFloat();
 
if(cor == "vermello")   {
  pin = 13;
 
}
else if (cor== "naranja")  {
         pin = 12;
}
       
 else if(cor== "amarillo")   {
  pin = 11;
 
  }
         
 else if(cor== "verde")   {
  pin = 10;
 
  }
         
 else if (cor== "azul")   {
  pin = 9;
 
  }
 
         
 else if(cor== "blanco")   {
  pin = 8;
 
  }
         
  switch(pin) {
    case 13 :
    digitalWrite(13, HIGH);
    delay(tempo);
    digitalWrite(13, LOW);
    delay (tempo);
    break;
 
    case 12 :
    digitalWrite(12, HIGH);
    delay(tempo);
    digitalWrite(12, LOW);
    delay (tempo);
    break;
   

    case 11 :  
    for (int i=0 ; i < 256; i++) {
      analogWrite(11, i);
      delay(tempo/256);
    }
    for(int i = 255; i>=0; i--) {
      analogWrite(11, i);
      delay(tempo/256);
      break;
     
    }
     
    case 10 :  
    for (int i=0 ; i < 256; i++) {
      analogWrite(10, i);
      delay(tempo/256);
    }
    for(int i = 255; i>=0; i--) {
      analogWrite(10, i);
      delay(tempo/256);
      break;
     
    }
     
    case 9 :  
    for (int i=0 ; i < 256; i++) {
      analogWrite(9, i);
      delay(tempo/256);
    }
    for(int i = 255; i>=0; i--) {
      analogWrite(9, i);
      delay(tempo/256);
      break;
    }
 
    case 8 :
    digitalWrite(8, HIGH);
    delay(tempo);
    digitalWrite(8, LOW);
    delay (tempo);
    break;
   
    default:
   
      Serial.println("Erro");
 
    break;
 }
}
