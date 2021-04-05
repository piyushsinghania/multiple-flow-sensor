int Pulses1 = 2;         //Arduino digital pin 2 is declared as Pulses1
int Pulses2 = 3;         //Arduino digital pin 3 is declared as Pulses2
int Pulses3 = 18;         //Arduino digital pin 18 is declared as Pulses3
int Pulses4 = 19;         //Arduino digital pin 19 is declared as Pulses4

int led1   = 7; //Led pin for led 1
int led2   = 8; //Led pin for led 2
int led3   = 9; //Led pin for led 3
int led4   = 10;//Led pin for led 4


volatile int pulsecount1; //Variable to count number of pulses1
volatile int pulsecount2; //Variable to count number of pulses2
volatile int pulsecount3; //Variable to count number of pulses3
volatile int pulsecount4; //Variable to count number of pulses4

  
volatile int i=0;                 //Variable for led1 status 
volatile int j=0;                 //Variable for led2 status
volatile int k=0;                 //Variable for led3 status
volatile int l=0;                 //Variable for led4 status

void setup() {
  //Interrupt pin 2 declared as input and pull up resitor is enabled
  pinMode(Pulses1, INPUT_PULLUP); 

  //Interrupt pin 3 declared as input and pull up resistor is enabled
  pinMode(Pulses2, INPUT_PULLUP);

  //Interrupt pin 18 declared as input and pull up resistor is enabled
  pinMode(Pulses3, INPUT_PULLUP);

  //Interrupt pin 19 declared as input and pull up resistor is enabled
  pinMode(Pulses4, INPUT_PULLUP);

  //Led1 as output
  pinMode(led1, OUTPUT);

  //Led2 as output
  pinMode(led2, OUTPUT);

  //Led3 as output
  pinMode(led3, OUTPUT);

  //Led4 as output
  pinMode(led4, OUTPUT);
  
  
  //Interrupt is attached to pin 3
  //ISR(interuupt service routine) of interrupt is CountPulses
  //Interrupt is activated on HIGH to LOW transition 
  attachInterrupt(digitalPinToInterrupt(Pulses1), CountPulsesOne, FALLING);    

  attachInterrupt(digitalPinToInterrupt(Pulses2), CountPulsesTwo, FALLING);

  attachInterrupt(digitalPinToInterrupt(Pulses3), CountPulsesThree, FALLING);

  attachInterrupt(digitalPinToInterrupt(Pulses4), CountPulsesFour, FALLING);
  
  Serial.begin(9600);  //Starting serial monitor
}
void loop() { 
  pulsecount1 = 0;  //Start counting from 0 again
  pulsecount2 = 0;  //start counting from 0 again
  pulsecount3 = 0;  //start counting from 0 again
  pulsecount4 = 0;  //start counting from 0 again
  
  i=0;             //Reset led1 toggling variable
  j=0;             //Reset led2 loggling variable
  k=0;             //Reset led3 loggling variable
  l=0;             //Reset led4 loggling variable
    
  interrupts();    //Enables interrupt on arduino pin 3
  delay (2000);    //Wait 1 second 
  noInterrupts();  //Disable the interrupt

 //One second is over now and we have the number of pulses in variable 
 //'pulsecount1'

  //Calculating the water flow rate in Milli Liters per minute for sensor 1
  double flowRate1;
  flowRate1 = (pulsecount1 * 2.22 * 60); 
  Serial.print("Flow rate F1=");       
  Serial.print(flowRate1);   //Print milli liters per minute on serial monitor for 
  Serial.println("mL/minute");     

  //Calculating the water flow rate in Milli Litres per minute for sensor 2
  double flowRate2;
  flowRate2 = (pulsecount2 * 2.22 * 60); 
  Serial.print("Flow rate F2=");       
  Serial.print(flowRate2);   //Print milli liters per minute on serial monitor for 
  Serial.println("mL/minute");  

  //Calculating the water flow rate in Milli Litres per minute for sensor 3
  double flowRate3;
  flowRate3 = (pulsecount3 * 2.22 * 60); 
  Serial.print("Flow rate F3=");       
  Serial.print(flowRate3);   //Print milli liters per minute on serial monitor for 
  Serial.println("mL/minute");  

  //Calculating the water flow rate in Milli Litres per minute for sensor 4
  double flowRate4;
  flowRate4 = (pulsecount4 * 2.22 * 60); 
  Serial.print("Flow rate F4=");       
  Serial.print(flowRate4);   //Print milli liters per minute on serial monitor for 
  Serial.println("mL/minute");  

  Serial.println("");
  
}
 
void CountPulsesOne()
{
    pulsecount1++; //Increment the variable on every pulse1
    //On every pulse1 toggle the state of led1.
    if(i%2==0)
    digitalWrite(led1,HIGH);
    else
    digitalWrite(led1,LOW);
    i++;
}
void CountPulsesTwo()
{
    pulsecount2++; //Increment the variable on every pulse2
    //On every pulse2 toggle the state of led2.
    if(j%2==0)
    digitalWrite(led2,HIGH);
    else
    digitalWrite(led2,LOW);
    j++;
}
void CountPulsesThree()
{
    pulsecount3++; //Increment the variable on every pulse3
    //On every pulse3 toggle the state of led3.
    if(k%2==0)
    digitalWrite(led3,HIGH);
    else
    digitalWrite(led3,LOW);
    k++;
}
void CountPulsesFour()
{
    pulsecount4++; //Increment the variable on every pulse4
    //On every pulse4 toggle the state of led2.
    if(l%2==0)
    digitalWrite(led4,HIGH);
    else
    digitalWrite(led4,LOW);
    l++;
}
