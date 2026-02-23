#include <Servo.h>
#include <EEPROM.h>
#include <TimerOne.h>
#include <Adafruit_NeoPixel.h>
#include <AS5045.h>

//Základna
////Servo Servo1;
const int stepPin1 = A0; 
const int dirPin1 = A1; 
const int enPin1 = 38;
int actuatorPosition1 = 0; 

Servo Actuator2;
///Servo Servo3;
const int stepPin3 = A6; 
const int dirPin3 = A7; 
const int enPin3 = A2;
int actuatorPosition3 = 0; 
///Servo Actuator4;
const int stepPin4 = 46; 
const int dirPin4 = 48; 
const int enPin4 = A8;
int actuatorPosition4 = 0; 
Servo Actuator5;
Servo Actuator6;
Servo Actuator7;


#define PIN 6
#define CSpin   3
#define CLKpin  5
#define DOpin   4

Adafruit_NeoPixel strip = Adafruit_NeoPixel(15, PIN, NEO_GRB + NEO_KHZ800);

AS5045 enc (CSpin, CLKpin, DOpin) ;

double uhel1, uhel2, uhel3;


int COMpos,pos2=0,pos3=160,pos4=90,pos5=90,pos6=90,pos7=90;
int Speed=5;
String COM = "";
String SERVO;
int addr = 0;

int Value=0;

int ConnectedFlg=0;

int GoCode = 0;
int EOP = 0;
String Command = "";
int Position = 90;
int Delay = 100;

int StartButton = 0;
int StopButton = 0;
int MenuButton = 0;

int MenuIndex = 0;

int CommandAvailable = 0;

void setup()
{
  
  //Serial.begin(115200);
  Serial.begin(9600);

  if (!enc.begin ())
    Serial.println ("Error setting up AS5045") ;
  else
    Serial.println ("Setting up AS5045 OK") ;

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  //Základna
  ////Actuator1.attach(6,1000,2000);
  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
  pinMode(enPin1,OUTPUT);
  
  //Actuator2.attach(7,1000,2000);
  //Actuator3.attach(8,1000,2000);
  //Actuator4.attach(9,1000,2000);
  //Actuator5.attach(10,1000,2000);
  Actuator6.attach(11,1000,2000);
  Actuator7.attach(12,1000,2000);
  //Actuator8.attach(13,1000,2000);
  /*pinMode(22, OUTPUT);     //LED
  pinMode(24, INPUT);      //menu
  pinMode(2, OUTPUT);     //play LED
  pinMode(3, INPUT);      //stop
  pinMode(4, OUTPUT);     //move LED
  pinMode(5, INPUT);      //start*/


  delay(100);
  
  Actuator2.write(0);
  
  //pinMode(44, OUTPUT);

  
  //pinMode(44, OUTPUT);
  //digitalWrite(44,LOW);
  
  delay(3000);
  
  Serial.println("Init Complete..\n");
  
}



void loop()
{
  
   uhel1 = enc.read_first () * 0.08789;
if(enc.status () == 0b10011)
  {
      Serial.print ("Uhel 1 : ");
      Serial.println(uhel1);
  }
  
uhel2 = enc.read_middle () * 0.08789;
if(enc.status () == 0b10011)
  {
      Serial.print ("Uhel 2 : ");
      Serial.println(uhel2);
  }
  
uhel3 = enc.read_last () * 0.08789;
if(enc.status () == 0b10011)
  {
      Serial.print ("Uhel 3 : ");
      Serial.println(uhel3);
  }
  
    
  if(COM == "scan")
  {
    Serial.print("Arduino Mega\n");
    COM="";
  }

  //Navázání spojení s PC rozhraním, poslání informací o firmware
  if(COM == "connect")
  {
    Serial.print("CONNECTED.. CHECKING FIRMWARE..\n");
    Serial.print("Arduino Mega 2560 - Robot Control App Driver\n");
    Serial.print("2.0.0 /Alpha\n");
    //1.0.0revB
    ConnectedFlg=1;
    COM="";
  }  

  if(COM == "rev")
  {
    Serial.print("revision Alpha\n");
    COM="";
  }
  
  if(COM == "disconnect")
  {
    ConnectedFlg=0;
    COM="";
  }
  
  if(COM == "reconnect")
  {
    ConnectedFlg=1;
    COM="";
  }  
  
  

  //Nastavení rychlosti z Online režimu
  if(COM.substring(0,6) == "SPEED_")
  {
    Speed = COM.substring(6,9).toInt();
    delay(1);
    
    COM="";
  }

  StartButton = digitalRead(5);
  MenuButton = digitalRead(24);

  if(digitalRead(24) == HIGH)
  {
    digitalWrite(22,HIGH);
  }
  else
  {
    digitalWrite(22,LOW);
  }
  
  if(MenuButton == 1)
  {
    while(digitalRead(24) == HIGH)
      delay(100);
    MenuButton = digitalRead(24);
    MenuIndex++;
    if(MenuIndex > 1)
      MenuIndex = 0;
  }

  //Nastavení aktuátoru z Online režimu
  if (COM.substring(0,11) == "ACTUATOR_1") {                   //Zjistí který aktuátor
    COMpos = COM.substring(11,14).toInt();                      //Zjistí požadovanou polohu
      if(actuatorPosition1<COMpos)
        digitalWrite(dirPin1,HIGH);                          //Pohyb vpravo
      else if(actuatorPosition1>COMpos)
        digitalWrite(dirPin1,LOW);                           //Pohyb vlevo
      
      for (actuatorPosition1; actuatorPosition1 <= COMpos; actuatorPosition1 += 1)
      {          
        digitalWrite(enPin1,LOW); 
        for(int x = 0; x < (44); x++)
        {
          //sixteenth step
          digitalWrite(stepPin1,HIGH); 
          delayMicroseconds(500); 
          digitalWrite(stepPin1,LOW); 
          delayMicroseconds(500); 

        }                       //Nastaví polohu serva (navýšenou o 1 st.)
      delay(Speed);                             //Prodleva mezi jednotlivými kroku posunu (udává rychlost otáčení)
      if(actuatorPosition1!=uhel1)
         break;
      }
    

    Serial.println(String(COMpos)+"st"); 
    COM="";
    
  }
  if (COM.substring(0,6) == "ACTUATOR_2") {
    COMpos = COM.substring(6,9).toInt();
    if(pos2<COMpos)
    {
      for (pos2; pos2 <= COMpos; pos2 += 1){ 
      Actuator2.write(pos2);              
      delay(Speed);    
                        
      }
      
    }
    else if(pos2>COMpos)
    {
      for (pos2; pos2 >= COMpos; pos2 -= 1){ 
      Actuator2.write(pos2);             
      delay(Speed);      
                          
      }
      
    }
    Serial.println(String(COMpos)+"st");
    COM="";
        
  }
  if (COM.substring(0,6) == "ACTUATOR_3") {
    COMpos = COM.substring(6,9).toInt();
    if(actuatorPosition3<COMpos)
        digitalWrite(dirPin3,HIGH);                          //Pohyb vpravo
      else if(actuatorPosition3>COMpos)
        digitalWrite(dirPin3,LOW);                           //Pohyb vlevo
      
      for (actuatorPosition3; actuatorPosition3 <= COMpos; actuatorPosition3 += 1)
      {          
        digitalWrite(enPin3,LOW); 
        for(int x = 0; x < (44); x++)
        {
          //sixteenth step
          digitalWrite(stepPin3,HIGH); 
          delayMicroseconds(500); 
          digitalWrite(stepPin3,LOW); 
          delayMicroseconds(500); 
        }             
      delay(Speed);  
      if(actuatorPosition1!=uhel2)
         break;                        
      }
      
    Serial.println(String(COMpos)+"st");
    COM="";
        
  }
  if (COM.substring(0,6) == "ACTUATOR_4") {
    COMpos = COM.substring(6,9).toInt();
    if(actuatorPosition4<COMpos)
        digitalWrite(dirPin4,HIGH);                          //Pohyb vpravo
      else if(actuatorPosition4>COMpos)
        digitalWrite(dirPin4,LOW);                           //Pohyb vlevo
      
      for (actuatorPosition4; actuatorPosition4 <= COMpos; actuatorPosition4 += 1)
      {          
        digitalWrite(enPin4,LOW); 
        for(int x = 0; x < (44); x++)
        {
          //sixteenth step
          digitalWrite(stepPin4,HIGH); 
          delayMicroseconds(500); 
          digitalWrite(stepPin4,LOW); 
          delayMicroseconds(500); 
        }             
      delay(Speed);  
      if(actuatorPosition4!=uhel3)
         break;                        
      }
    Serial.println(String(COMpos)+"st");
    COM="";
        
  }
  if (COM.substring(0,6) == "ACTUATOR_5") {
    COMpos = COM.substring(6,9).toInt();
    if(pos5<COMpos)
    {
      for (pos5; pos5 <= COMpos; pos5 += 1){ 
      Actuator5.write(pos5);             
      delay(Speed);   
                           
      }
      
    }
    else if(pos5>COMpos)
    {
      for (pos5; pos5 >= COMpos; pos5 -= 1){
      Actuator5.write(pos5);              
      delay(Speed);     
                         
      }
      
    }
    Serial.println(String(COMpos)+"st");
    COM="";
        
  }
  if (COM.substring(0,6) == "ACTUATOR_6") {
    COMpos = COM.substring(6,9).toInt();
    if(pos6<COMpos)
    {
      for (pos6; pos6 <= COMpos; pos6 += 1){
      Actuator6.write(pos6);              
      delay(Speed);         
                     
      }
      
    }
    else if(pos6>COMpos)
    {
      for (pos6; pos6 >= COMpos; pos6 -= 1){
      Actuator6.write(pos6);             
      delay(Speed);        
                     
      }
      
    }
    Serial.println(String(COMpos)+"st");
    COM="";
        
  }
  if (COM.substring(0,6) == "ACTUATOR_7") {
    COMpos = COM.substring(6,9).toInt();
    if(pos7<COMpos)
    {
      for (pos7; pos7 <= COMpos; pos7 += 1){
      Actuator7.write(pos7);             
      delay(Speed);          
                    
      }
      
    }
    else if(pos7>COMpos)
    {
      for (pos7; pos7 >= COMpos; pos7 -= 1){
      Actuator7.write(pos7);              
      delay(Speed);          
                     
      }
      
    }
    Serial.println(String(COMpos)+"st");
    COM="";
        
  }

  //Zápis sekvence do eeprom
  if (COM.substring(0,1)  == "<") {                   //Zjistí zda obsahuje unikátní symbol pro zápis
    int x = COM.length()-1;                           //Zjistí délku řetězce s kódem
    EEPROM.write(0, x);                               //Zapíše délku na první polohu v eeprom
    for(addr=1; addr < COM.length(); addr++)          //Cyklus pro postupný zápis řetezce
    {
      char StreamString[COM.length()] ;               //Vytvoření char[] s počtem prvký rovným délce řetězce
      COM.toCharArray(StreamString, COM.length());    //Převod ze String na char[]
      int val = StreamString[addr];                   //Převod písmen na čísla ASCII kódu
      EEPROM.write(addr, val);                        //Uložení do eeprom
    }
    COM="";
  }

  if(digitalRead(5) == HIGH)
  {
    digitalWrite(2,HIGH);
  }
  else
  {
    digitalWrite(2,LOW);
  }
  
  if((COM == "start")||(StartButton == 1))                                   //Zjistí, zda je start sekvence
  {
    GoCode = 1;                                        //Nastaví příznak sekvence
    EOP = EEPROM.read(0);                              //Zjistí uloženou délku ekvence
    StartButton = 0;
    COM = "";
    MenuIndex=0;
    Serial.println("Start..");
    delay(1000);
  }

  while(GoCode)                                        //Cyklus nekonečné sekvence
  {
    digitalWrite(2,HIGH);    
    CommandAvailable = 0;                              //Nulování příznaku PříznakDostupný
    for(addr=1; addr < EOP; addr++)                    //Cyklus čtení z eeprom
    {
      char EEchar = EEPROM.read(addr);                 //Čtení z EEPROM
      int EEint = (int)EEchar;                         //Převod char na int
      
      if(CommandAvailable)                             //Zjistí zda je příkaz
      {
        if(Command.substring(0,5) == "ACTUATOR_")          //Zjistí zda je ACTUATOR_
        {
          Timer1.detachInterrupt();
          GetValueActuator(EEchar);                        //Získá zakódovanou hodnotu příkazu
          if(Command == "ACTUATOR_1")                       //Zjistí, zda je ACTUATOR_1
            MoveActuator1();
          if(Command == "ACTUATOR_2")
            MoveActuator2();
          if(Command == "ACTUATOR_3")
            MoveActuator3();
          if(Command == "ACTUATOR_4")
            MoveActuator4();
          if(Command == "ACTUATOR_5")
            MoveActuator5();
          if(Command == "ACTUATOR_6")
            MoveActuator6();
          if(Command == "ACTUATOR_7")
            MoveActuator7();
          //callbackFunction();
        }
        if(Command.substring(0,5) == "SPEED")
        {
          GetValueSpeed(EEchar);                          //Záská hodnotu rychlosti
        }
        if(Command.substring(0,5) == "DELAY")
        {
          GetValueDelay(EEchar);                          //Získá hodnotu prodlevy
          delay(Delay);
          Serial.println("DELAY_ on "+String(Delay)+"ms");
        }
        CommandAvailable = 0;

          delay(5);
    
    
      }
      
      if((EEint >= 65)&&(EEint <= 90)&&(!CommandAvailable)) //Zjistí, zda je kód velké písmeno (zakodovaný příkaz)
      {
        GetCommand(EEchar);
        CommandAvailable = 1;
      }
    serialEvent(); 
    StopButton = digitalRead(3);
    if((COM == "stop")||(StopButton == 1))                                       //Zjistí zda je stop a vyskočí z cyklu
      break;
    }
    //COM = Serial.readString();
    Serial.println("Opakuji..");
    if((COM == "stop")||(StopButton == 1))                                       //Zjistí zda je stop a přeruší sekvenci
    {
      GoCode = 0;
      digitalWrite(2,LOW);  
      StopButton = 0; 
      delay(100);
      Serial.println("Stop..");
      
    }
  }
  
  if (COM.substring(0,2)  == "read_ee") {                   //funkce pro čtení z eeprom a výpis do aplikace (pomůcka troubleshootingu)
    EOP = EEPROM.read(0);
    for(addr=1; addr < EOP; addr++)
    {
      int val = EEPROM.read(addr);
      String str = String(val);
      Serial.println(val);
    }
    COM="";
  }
}

//Funkce pro čtení seriového portu
void serialEvent()
{
  
  while (Serial.available())
  {
    COM = Serial.readString();
  }
  
}



//Funkce posunu serva při sekvenci
void MoveActuator1()
{
    if(actuatorPosition1<Position)
    {
      digitalWrite(dirPin1,HIGH);
    }
    else if(actuatorPosition1>Position)
    {
      digitalWrite(dirPin1,LOW);  
    } 

      
      for (actuatorPosition1; actuatorPosition1 <= Position; actuatorPosition1 += 1)
      { 
      digitalWrite(enPin1,LOW); 
        for(int x = 0; x < (44); x++)
        {
          //sixteenth step
          digitalWrite(stepPin1,HIGH); 
          delayMicroseconds(500); 
          digitalWrite(stepPin1,LOW); 
          delayMicroseconds(500); 
        }             
      delay(Speed);   
                          
      }
      
    Serial.println("ACTUATOR_1 on "+String(Position)+"st");
     
}

void MoveActuator2()
{
    if(pos2<Position)
    {
      for (pos2; pos2 <= Position; pos2 += 1){
      Actuator2.write(pos2);              
      delay(Speed);        
                    
      }
      
    }
    else if(pos2>Position)
    {
      for (pos2; pos2 >= Position; pos2 -= 1){
      Actuator2.write(pos2);             
      delay(Speed);       
                     
      }
      
    }
    Serial.println("ACTUATOR_2 on "+String(Position)+"st");
     
}

void MoveActuator3()
{
    if(actuatorPosition3<Position)
    {
      digitalWrite(dirPin3,HIGH);
    }
    else if(actuatorPosition3>Position)
    {
      digitalWrite(dirPin3,LOW);  
    } 

      
      for (actuatorPosition3; actuatorPosition3 <= Position; actuatorPosition3 += 1)
      { 
      digitalWrite(enPin3,LOW); 
        for(int x = 0; x < (44); x++)
        {
          //sixteenth step
          digitalWrite(stepPin3,HIGH); 
          delayMicroseconds(500); 
          digitalWrite(stepPin3,LOW); 
          delayMicroseconds(500); 
        } 
      
    }
    Serial.println("ACTUATOR_3 on "+String(Position)+"st");
     
}

void MoveActuator4()
{
   if(actuatorPosition4<Position)
    {
      digitalWrite(dirPin4,HIGH);
    }
    else if(actuatorPosition4>Position)
    {
      digitalWrite(dirPin4,LOW);  
    } 

      
      for (actuatorPosition4; actuatorPosition4 <= Position; actuatorPosition4 += 1)
      { 
      digitalWrite(enPin4,LOW); 
        for(int x = 0; x < (44); x++)
        {
          //sixteenth step
          digitalWrite(stepPin4,HIGH); 
          delayMicroseconds(500); 
          digitalWrite(stepPin4,LOW); 
          delayMicroseconds(500); 
        } 
      
    }
    Serial.println("ACTUATOR_4 on "+String(Position)+"st");
     
}

void MoveActuator5()
{
    if(pos5<Position)
    {
      for (pos5; pos5 <= Position; pos5 += 1){
      Actuator5.write(pos5);            
      delay(Speed);         
                    
      }
      
    }
    else if(pos5>Position)
    {
      for (pos5; pos5 >= Position; pos5 -= 1){
      Actuator5.write(pos5);             
      delay(Speed);           
                  
      }
      
    }
    Serial.println("ACTUATOR_5 on "+String(Position)+"st");
     
}

void MoveActuator6()
{
    if(pos6<Position)
    {
      for (pos6; pos6 <= Position; pos6 += 1){ 
      Actuator6.write(pos6);             
      delay(Speed);             
              
      }
      
    }
    else if(pos6>Position)
    {
      for (pos6; pos6 >= Position; pos6 -= 1){ 
      Actuator6.write(pos6);             
      delay(Speed);          
                   
      }
      
    }
    Serial.println("ACTUATOR_6 on "+String(Position)+"st");
     
}

void MoveActuator7()
{
    if(pos7<Position)
    {
      for (pos7; pos7 <= Position; pos7 += 1){ 
      Actuator7.write(pos7);            
      delay(Speed);              
               
      }
      
    }
    else if(pos7>Position)
    {
      for (pos7; pos7 >= Position; pos7 -= 1){
      Actuator7.write(pos7);            
      delay(Speed);              
              
      }
      
    }
    Serial.println("ACTUATOR_7 on "+String(Position)+"st");
     
}

//Funkce pro převod kódu na příkazy
void GetCommand(char input)
{
  if(input == 'A')
    Command = "ACTUATOR_1";
  else if(input == 'B')
    Command = "ACTUATOR_2";
  else if(input == 'C')
    Command = "ACTUATOR_3";
  else if(input == 'D')
    Command = "ACTUATOR_4";
  else if(input == 'E')
    Command = "ACTUATOR_5";
  else if(input == 'F')
    Command = "ACTUATOR_6";
  else if(input == 'G')
    Command = "ACTUATOR_7";
  else if(input == 'Z')
    Command = "SPEED_";
  else if(input == 'Y')
    Command = "DELAY_";
  else
    Command = "";
}

//Dále už jen funkce pro převod kódu na hodnoty (servo, speed, delay)
void GetValueActuator(char input)
{
  if(input == 'a')
    Position = 0;
  else if(input == 'b')
   Position = 5;
  else if(input == 'c')
   Position = 10;
  else if(input == 'd')
   Position = 15;
  else if(input == 'e')
   Position = 20;
  else if(input == 'f')
   Position = 25;
  else if(input == 'g')
   Position = 30;
  else if(input == 'h')
   Position = 35;
  else if(input == 'i')
   Position = 40;
  else if(input == 'j')
   Position = 45;
  else if(input == 'k')
   Position = 50;
  else if(input == 'l')
   Position = 55;
  else if(input == 'm')
   Position = 60;
  else if(input == 'n')
   Position = 65;
  else if(input == 'o')
   Position = 70;
  else if(input == 'p')
   Position = 75;
  else if(input == 'q')
   Position = 80;
  else if(input == 'r')
   Position = 85;
  else if(input == 's')
   Position = 90;
  else if(input == 't')
   Position = 95;
  else if(input == 'u')
   Position = 100;
  else if(input == 'v')
   Position = 105;
  else if(input == 'w')
   Position = 110;
  else if(input == 'x')
   Position = 115;
  else if(input == 'y')
   Position = 120;
  else if(input == 'z')
   Position = 125;
  else if(input == '0')
   Position = 130;
  else if(input == '1')
   Position = 135;
  else if(input == '2')
   Position = 140;
  else if(input == '3')
   Position = 145;
  else if(input == '4')
   Position = 150;
  else if(input == '5')
   Position = 155;
  else if(input == '6')
   Position = 160;
  else if(input == '7')
   Position = 165;
  else if(input == '8')
   Position = 170;
  else if(input == '9')
   Position = 175;
  else if(input == '@')
   Position = 180;
  else
   Position = 90;
}

void GetValueSpeed(char input)
{
  if(input == 'a')
    Speed = 20;
  else if(input == 'b')
   Speed = 19;
  else if(input == 'c')
   Speed = 18;
  else if(input == 'd')
   Speed = 17;
  else if(input == 'e')
   Speed = 16;
  else if(input == 'f')
   Speed = 15;
  else if(input == 'g')
   Speed = 14;
  else if(input == 'h')
   Speed = 13;
  else if(input == 'i')
   Speed = 12;
  else if(input == 'j')
   Speed = 11;
  else if(input == 'k')
   Speed = 10;
  else if(input == 'l')
   Speed = 9;
  else if(input == 'm')
   Speed = 8;
  else if(input == 'n')
   Speed = 7;
  else if(input == 'o')
   Speed = 6;
  else if(input == 'p')
   Speed = 5;
  else if(input == 'q')
   Speed = 4;
  else if(input == 'r')
   Speed = 3;
  else if(input == 's')
   Speed = 2;
  else if(input == 't')
   Speed = 1;
  else if(input == 'u')
   Speed = 0;
  else
   Speed = 5;
}

void GetValueDelay(char input)
{
  if(input == 'a')
    Delay = 0;
  else if(input == 'b')
   Delay = 50;
  else if(input == 'c')
   Delay = 100;
  else if(input == 'd')
   Delay = 150;
  else if(input == 'e')
   Delay = 200;
  else if(input == 'f')
   Delay = 250;
  else if(input == 'g')
   Delay = 300;
  else if(input == 'h')
   Delay = 350;
  else if(input == 'i')
   Delay = 400;
  else if(input == 'j')
   Delay = 450;
  else if(input == 'k')
   Delay = 500;
  else if(input == 'l')
   Delay = 550;
  else if(input == 'm')
   Delay = 600;
  else if(input == 'n')
   Delay = 650;
  else if(input == 'o')
   Delay = 700;
  else if(input == 'p')
   Delay = 750;
  else if(input == 'q')
   Delay = 800;
  else if(input == 'r')
   Delay = 850;
  else if(input == 's')
   Delay = 900;
  else if(input == 't')
   Delay = 950;
  else if(input == 'u')
   Delay = 1000;
  else
   Delay = 100;
}
