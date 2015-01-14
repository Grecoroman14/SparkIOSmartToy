// name the pins
int led1 = D0;
int led2 = D1;
int led3 = D2;
int led4 = D3;
int ForceSenser = A0;
int Speaker = D4;
int fan = D6;
double analogvalue = 0.0;
double pirvalue = 0.0;
int lastTimeClose;
int now;
TCPvClient client;

// This routine runs only once upon reset
void setup()
{
   // Configure the pins to be outputs
   pinMode(led1, OUTPUT);
   pinMode(fan, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
   pinMode(led4, OUTPUT);
   pinMode(ForceSenser, INPUT);
   pinMode(Speaker, OUTPUT);
   pinMode(A0, INPUT);
   pinMode(A1, INPUT);
   Spark.variable("analogvalue", &analogvalue, DOUBLE);
   Spark.variable("pirvalue", &pirvalue, DOUBLE);

}


// This routine loops forever
void loop()
{
   analogvalue = analogRead(ForceSenser) + 0.0;
   ForceSenserIO(analogvalue);
   pirvalue = analogRead(A1) + 0.0;
   PIRSenserIO(pirvalue);
}

void ForceSenserIO(int forceSenser){

    if(forceSenser < 3000)  // xxx equals the force we decide is enough
        {
        digitalWrite(led1, HIGH);
        }
    else{
        digitalWrite(led1, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
    }

}

void PIRSenserIO(int pirSenser){

    if(pirSenser < 230)  // xxx equals the force we decide is enough
        {
        digitalWrite(led2, HIGH);
        lastTimeClose = millis();
        }
    else{
        digitalWrite(led2, LOW);
        now = millis();
        if(now-lastTimeClose > 3000 && now-lastTimeClose < 8000){
            digitalWrite(fan, HIGH);
            delay(1000);
            digitalWrite(fan, LOW);
        }
    }

}
