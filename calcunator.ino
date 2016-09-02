
#include <LiquidCrystal.h>

LiquidCrystal lcd(5, 4, 3, 2, 1, 0);

//io
const int A=0;
const int B=1;
const int P=7;
const int BUZZER=11;
boolean Pp = false;
//calculator
 //values
  long i=0;
  long j=0;
 //doings
  int d=0;
 //switchers
 boolean iin=false;
 boolean jin=false;
 boolean din=false;
//random
int r=0;
//strings
const String start = "CALCUNATOR";
const char* menuprints[]={"calculator", "trigonometry", "countconv", "randomiser", "music", "visitcard"};
//bytes
byte tg1[8] = {//teg
  B11111,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B11000,
  B10100,
};
byte tg2[8] = { 
  B11100,
  B00100,
  B00100,
  B00100,
  B00000,
  B00000,
  B00000,
  B00000,
};
byte tg3[8] = { 
  B00000,
  B00100,
  B01010,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
};
byte tg4[8] = { 
  B10010,
  B10001,
  B10000,
  B10001,
  B10010,
  B10100,
  B11000,
  B10000,
};  
byte tg5[8] = { 
  B00100,
  B01010,
  B10001,
  B00000,
  B00000,
  B00001,
  B00010,
  B00100,
};
byte tg6[8] = { 
  B00001,
  B00011,
  B00101,
  B11001,
  B11111,
  B00001,
  B00001,
  B00001,
};              //end of teg

//music
 //notes
 const int DO=261;
 const int RE=293;
 const int MI=329;
 const int FA=349;
 const int SO=392;
 const int LA=440;
 const int SI=493;
 const char* noteprints[]={"a", "b", "c", "d", "e", "f","g"};
 //delays
 int play=0;
 int wait=0;
 //melody
 int melody[15]={0};
 char melodyprint[15]={0};
//switcers
int menu=0;
const int mainmenulong = 6;
boolean choise = false;

void setup() {
  pinMode(6, OUTPUT);
  analogWrite(6,55);
  lcd.begin(16, 2);
  lcd.createChar(1, tg1);
  lcd.createChar(2, tg2);
  lcd.createChar(3, tg3);
  lcd.createChar(4, tg4);
  lcd.createChar(5, tg5);
  lcd.createChar(6, tg6);
}

void loop() {
mainmenu();
//delay(100);
//lcd.clear();
}

void mainmenu(){
  do{
    int value=readSensor(A);
    lcd.setCursor(2, 0);
    lcd.print(value);
 menu=(((value-4)/170));
 lcd.setCursor(2, 1);
 lcd.print(menuprints[menu]);
 if(mainbut()==true){
   choise=true;
 }
 delay(100);
 lcd.clear();
  }while(choise == false);
  choise = false;
  delay(200);//задержка для гашения воздеёствия кнопки выбора на вызываемую функцию
  switch(menu){
    case 0: calculator();
    break;
    case 1: trigonometry();
    break;
    case 2: calculator();
    break;
    case 3: randomiser();
    break;
    case 4: music();
    break;
    case 5: visitcard();
    break;
    default:calculator();
}
}

void calculator(){
  
  do{//ввод первого числа
lcd.clear();
lcd.setCursor(2, 0);
lcd.print(i);
lcd.setCursor(5, 1);
lcd.print(getnumber());
lcd.setCursor(2, 1);
switch(calcinputmetod()){//печать значения выбранного действия
  case 0: lcd.print("_");break;
  case 1: lcd.print("<");break;
  case 2: lcd.print(".");break;
  case 3: lcd.print(">");break;
}
if(mainbut()==true){//выполнение действия

  switch(calcinputmetod()){
  case 0: i=((i*10)+getnumber());break;
  case 1: i=((i-i%10)/10);break;
  case 2: i=(i+(getnumber()/10));break;
  case 3:  iin=true;break;
  }

}
delay (100);
}while (iin==false);
delay(200);
 do{//ввод второрго числа
lcd.clear();
lcd.setCursor(2, 0);
lcd.print(j);
lcd.setCursor(5, 1);
lcd.print(getnumber());
lcd.setCursor(2, 1);
switch(calcinputmetod()){//печать значения выбранного действия
  case 0: lcd.print("_");break;
  case 1: lcd.print("<");break;
  case 2: lcd.print(".");break;
  case 3: lcd.print(">");break;
}
if(mainbut()==true){//выполнение действия
  switch(calcinputmetod()){
  case 0: j=((j*10)+getnumber());break;
  case 1: j=((j-j%10)/10);break;
  case 2: j=(j+(getnumber()/10));break;
  case 3:  jin=true;break;
}
}
delay (100);
}while (jin==false);
delay(200);
do{
  lcd.clear();
lcd.setCursor(2, 0);
lcd.print(i);
lcd.setCursor(2, 1);
lcd.print(j);
lcd.setCursor(13, 1);
switch(calcinputmetod()){//печать значения выбранного действия
  case 0: lcd.print("=");break;
  case 1: lcd.print("=");break;
  case 2: lcd.print("<<");break;
  case 3: lcd.print("<<");break;
}
lcd.setCursor(13, 0);
switch(getdoing()){//печать значения выбранного действия
  case 0: lcd.print("+");break;
  case 1: lcd.print("-");break;
  case 2: lcd.print("*");break;
  case 3: lcd.print("/");break;
}
if(mainbut()==true){//выполнение действия
lcd.clear();
lcd.setCursor(2, 0);
  switch(getdoing()){
  case 0: lcd.print(i+j);;break;
  case 1: lcd.print(i-j);break;
  case 2: lcd.print(i*j);break;
  case 3: lcd.print(i/j);break;
}
din=true;
}
delay(100);
}while(din==false);
delay(200);
do{
delay(100);
}while(mainbut()==false);
iin=false;
jin=false;
din=false;
 i=0;
 j=0;
 delay(200);
}//конец калькулятора

void trigonometry(){          //тригонометрический калькулятор

do{
 lcd.clear(); 
 lcd.setCursor(2, 0);
 lcd.print(getungle());
 delay(100);
 }while(mainbut()!=HIGH);
    delay(500);
    lcd.setCursor(13, 1);
    lcd.print(getungle());
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" sin ");
    lcd.setCursor(0, 1);
    lcd.print(sin((getungle()*3.14)/180));
    lcd.setCursor(5, 0);
    lcd.print(" cos ");
    lcd.setCursor(6, 1);
    lcd.print(cos((getungle()*3.14)/180));
    lcd.setCursor(9, 0);
    lcd.print("  tan ");
    lcd.setCursor(11, 1);
    lcd.print(tan((getungle()*3.14)/180));
    do{
    delay(100);
  }while(mainbut()!=HIGH);
delay(200);
}

void randomiser(){ //случайных чисел генератор
boolean f=false;  
do{
lcd.clear();

lcd.setCursor(2, 0);
 lcd.print("   randomiser   ");
 lcd.setCursor(2, 1);
 lcd.print(r);
 lcd.setCursor(13, 1);
switch(calcinputmetod()){//печать значения выбранного действия
  case 0: lcd.print("<>");break;
  case 1: lcd.print("=");break;
  case 2: lcd.print("<<");break;
  case 3: lcd.print("<<");break;
}
if((mainbut()==true)&(calcinputmetod()==1)){
 r=random(0,1000);
 delay(200);
}
if((mainbut()==true)&(calcinputmetod()==0)){
 randomSeed(analogRead(0));
 delay(200);
}
if((mainbut()==true)&(calcinputmetod()>=2)){
f=true;
 delay(200);
}
delay(100);
}while(f==false);
f=false;
}

void visitcard(){
  lcd.clear();
 lcd.setCursor(13, 0);//начало печати тега
lcd.write(byte(1));
lcd.write(byte(2));
lcd.write(byte(3));
 lcd.setCursor(13, 1);
lcd.write(byte(4));
lcd.write(byte(5));
lcd.write(byte(6));//конец печати тега

lcd.setCursor(0, 0);
lcd.print("Mark Bogdanov");
lcd.setCursor(0,1);
lcd.print("999 210 69 83");

do{delay(100);}while(mainbut()==false);
delay (200);
}

void music(){
 boolean stoper=false;
 int pos=0;
 int notenow=0;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("_______________");

 do{
   pos=getpos();
   lcd.clear();
 lcd.setCursor(15,0);
 lcd.print(play);
 lcd.setCursor(15,1);
 lcd.print(wait);
 lcd.setCursor(pos,1);
 if((0<=pos)&(pos<=14)){
 lcd.print("^");
 }
 else{
 lcd.print(" ");
 }
 if(mainbut()==true){
   boolean notechoise =false;
   int choisennote=0;
  lcd.setCursor(pos,1);
 lcd.print("*");
 delay(500);
do{
  lcd.setCursor(pos,0);
 choisennote=getnote();
 lcd.print(noteprints[choisennote]);
 if (mainbut()==true){
 notechoise =true;
 melody[pos]=choisennote;
 choisennote=0;
 }
 delay(5);
}while(notechoise==false);

 delay(100);
 }
 }while(stoper!=true);
}
int getnumber(){
  int a=readSensor(A)/102.3;
  return a;
}

int getungle(){
  int a=readSensor(A)/2.8416;

  return a;
}

int getdoing(){
  int a=readSensor(A)/341;
  return a;
}

int getnote(){//взять ноту
  int a=readSensor(A)/146.1;
  return a;
}

int getpos(){//взять позицию нотного пера
  int a=readSensor(A)/68.2;
  return a;
}

boolean mainbut(){  //стабилизация кнопок
  boolean valueButton = digitalRead(P);
  if (Pp != valueButton){
    delay(20);
    valueButton = digitalRead(P);
  }
  return valueButton;
  
}

int calcinputmetod(){
  int a=readSensor(B)/341;
  return a;
}

int readSensor(int analogInPin){ 
   unsigned int avg_sum=0;
   for(byte i=0;i<2;i++){
       avg_sum+=analogRead(analogInPin);
       delay(4); // небольшая пауза между замерами
}
   return avg_sum/2;
}

