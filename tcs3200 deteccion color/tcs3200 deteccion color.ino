//variables
const int r = 2;
const int g = 4;
const int b = 3;
const int w = 5;
const int altavoz = 13;
const int s0 = 8;
const int s1 = 9;
const int s2 = 12;
const int s3 = 11;
const int out = 10;
byte countRed = 0;
byte countGreen = 0;
byte countBlue = 0;

//setup
void setup() {
   Serial.begin(9600);
   pinMode(s0, OUTPUT);
   pinMode(s1, OUTPUT);
   pinMode(s2, OUTPUT);
   pinMode(s3, OUTPUT);
   pinMode(out, INPUT);
   digitalWrite(s0, HIGH);
   digitalWrite(s1, HIGH);
}//endsetup

//loop
void loop() {
   getColor(); //inicializamos la busqueda de colores
   Serial.print("Red: ");
   Serial.print(countRed, DEC);
   Serial.print("Green: ");
   Serial.print(countGreen, DEC);
   Serial.print("Blue: ");
   Serial.print(countBlue, DEC);
   if (countRed < countBlue && countGreen > 100 && countRed < 220) //si es rojo
   {
      Serial.println(" - Red");
      digitalWrite(r,HIGH);
      digitalWrite(b,LOW);
      digitalWrite(g,LOW);
      digitalWrite(w,LOW);
      delay(2000);
      tone(altavoz, 440);
      delay(500);
      noTone(altavoz);
   }
   else if (countBlue < 50 && countBlue < 60) //si es azul 
   {
      Serial.println(" - Blue");
      digitalWrite(b,HIGH);
      digitalWrite(r,LOW);
      digitalWrite(g,LOW);
      digitalWrite(w,LOW);
      delay(2000);
      tone(altavoz, 600);
      delay(500);
      noTone(altavoz);
   }
   else if (countGreen < 140 && countGreen < 150) // si es verde
   {
      Serial.println(" - Green");
      digitalWrite(g,HIGH);
      digitalWrite(r,LOW);
      digitalWrite(b,LOW);
      digitalWrite(w,LOW);
      delay(2000);
      tone(altavoz, 1000);
      delay(500);
      noTone(altavoz);
   }
   else { // si no es ningun color de los anteriores
      Serial.println("-");
      digitalWrite(w,HIGH);
      digitalWrite(r,LOW);
      digitalWrite(g,LOW);
      digitalWrite(b,LOW);
   }
   delay(1000);
}//endloop

//getcolor
void getColor()
{
   digitalWrite(s2, LOW);
   digitalWrite(s3, LOW);
   countRed = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
   digitalWrite(s3, HIGH);
   countBlue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
   digitalWrite(s2, HIGH);
   countGreen = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}//endgetColor
