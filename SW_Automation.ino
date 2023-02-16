const int IN3 = 9;
const int IN4 = 8;
const int IN2 = 10;
const int IN1 = 11;
const int F2 = 6;
const int F1 = 7;
const int F3 = 5;
const int F4 = 4;
const int bot = 3;
int FimDeCurso1;
int FimDeCurso2;
int FimDeCurso3;
int FimDeCurso4;
int BotEstado;
int LED1 = 2;
int LED2 = 12;



// HIGH VIROU LOW
// LOW VIROU HIGH



void setup()
{
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(F1, INPUT);
    pinMode(F2, INPUT);
    pinMode(F3, INPUT);
    pinMode(F4, INPUT);
    pinMode(bot, INPUT);
    pinMode(LED1,OUTPUT);
    pinMode(LED2, INPUT);
}



void loop()
{
    FimDeCurso1 = digitalRead(F1);
    FimDeCurso2 = digitalRead(F2);
    FimDeCurso3 = digitalRead(F3);
    FimDeCurso4 = digitalRead(F4);
    BotEstado = digitalRead(bot);



   if (BotEstado == HIGH)
    {



       //VAI
        if((FimDeCurso1 == HIGH)&& (FimDeCurso2 == LOW ))
        {

     
            //Movimenta para a esquerda
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);
        }

        



       // DESCE
        else if ((FimDeCurso2 == HIGH) && (FimDeCurso3 == HIGH))
        {

          digitalWrite(IN3, LOW);
          digitalWrite(IN4, LOW);
          delay(100);
             //Movimenta para descer
           digitalWrite(IN1, HIGH);
           digitalWrite(IN2, LOW);
        }
        //SOBE
        else if((FimDeCurso2 == HIGH) && (FimDeCurso4 == HIGH))
        {
            //Movimenta para subir
            delay(3000);
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH);
            
            delay(17000);
            
            digitalWrite(LED1, HIGH);
        }

        

       else if((FimDeCurso2 == HIGH) && (digitalRead(LED2)==HIGH))
        {
            //Movimenta para direita
            delay(100);
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, LOW);
            delay(100);
            digitalWrite(LED1, LOW);
            delay(2000);
            
            
            
        }

        

      
    }
    
    else
    {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
    }
}
