#include <LiquidCrystal.h>  
#include <Keypad.h>

LiquidCrystal lcd(A0,A1,13,12,11,10);

int chk_init = 0; 
int val, val2 = 0;  
int zero_val = 0; 
int zero_val2 = 0;  
int key_val = 0;  
int set_cal = 0;  
int cal_end = 0;  
unsigned int digit4_sum_1 = 0; 
unsigned int digit4_sum_2 = 0; 
unsigned long digit4_total = 0;

int reset_val = 0; 

const byte numRows = 4;
const byte numCols = 4;

char Keymap[numRows][numCols]=
{
  {'1','2','3','A'},  
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

byte rowPins[numRows] = {9,8,7,6};
byte colPins[numCols] = {5,4,3,2};

Keypad myKeypad = Keypad(makeKeymap(Keymap), rowPins, colPins, numRows, numCols);

void Reset()
{
    asm volatile ("jmp 0");  
} 

void cal_init_reset()
{
    lcd.clear();
  val = 0;  
    val2 = 0;
  digit4_sum_1 = 0;
  digit4_sum_2 = 0;
  digit4_total = 0;
  set_cal = 0;
    zero_val = 0;
}  

void setup()
{
  Serial.begin(9600);
    lcd.begin(16,2);
    lcd.print("***CALCULADORA***");
  lcd.setCursor(0,1);
    lcd.print("Presiona un boton.");
    lcd.setCursor(0,0);
}

void loop()
{
  char Keypressed = myKeypad.getKey();
    
    if(Keypressed != NO_KEY)
    { 
        if(!chk_init){ 
          lcd.clear();
            chk_init = 1;}
      
        if(cal_end){
            cal_init_reset();
            cal_end=0;}

        Serial.print(Keypressed); 
      
        if(Keypressed != 'A' && Keypressed != 'B' && Keypressed != 'C' && Keypressed != 'D' && Keypressed != '#' && Keypressed != '*')
    {
                 if(Keypressed == '1') key_val = 1;
            else if(Keypressed == '2') key_val = 2;
            else if(Keypressed == '3') key_val = 3;
            else if(Keypressed == '4') key_val = 4;
            else if(Keypressed == '5') key_val = 5;
            else if(Keypressed == '6') key_val = 6;
            else if(Keypressed == '7') key_val = 7;
            else if(Keypressed == '8') key_val = 8;
            else if(Keypressed == '9') key_val = 9;
            else if(Keypressed == '0') key_val = 0;
            
      if(!set_cal){
        val++;
        if(Keypressed != '0') 
          zero_val = 0;

        if(!zero_val && val <= 4)
          lcd.write(Keypressed);
                                
        if(val == 1 && Keypressed == '0'){
          val=0;
          zero_val = 1;
          lcd.setCursor(0,0);}
              
        switch(val){  
          case 1:
            digit4_sum_1 = key_val * 1; 
            break;
          case 2:
            digit4_sum_1 = (digit4_sum_1 * 10) + key_val; 
            break;
          case 3:
            digit4_sum_1 = (digit4_sum_1 * 10) + key_val; 
            break;
          case 4:
            digit4_sum_1 = (digit4_sum_1 * 10) + key_val; 
                      if(digit4_sum_1 == 8800)
                          reset_val = 1;
            break;
        }
            }
            else if(set_cal){ 
        val2++;
        if(Keypressed != '0') 
          zero_val2 = 0;

        if(!zero_val2 && val2 <= 4)
          lcd.write(Keypressed);
                  
        if(val2 == 1 && Keypressed == '0'){
          val2=0;
          zero_val2 = 1;
          lcd.setCursor(5,0);}
          
        switch(val2){
          case 1:
            digit4_sum_2 = key_val * 1;
            break;
          case 2:
            digit4_sum_2 = (digit4_sum_2 * 10) + key_val;
            break;
          case 3:
            digit4_sum_2 = (digit4_sum_2 * 10) + key_val;
            break;
          case 4:
            digit4_sum_2 = (digit4_sum_2 * 10) + key_val;
            break;
        }
            }
        }
        else if(Keypressed == '*')
        {
            cal_init_reset();
        }
        
        else if(Keypressed == '#')
        {
            if(reset_val)
        Reset();
          
            if(val != 0 && val2 != 0){
                lcd.setCursor(0,1);
                lcd.write("=");
                cal_end=1;

                switch(set_cal){
                    case 1: 
                        digit4_total = digit4_sum_1 + digit4_sum_2;
                        lcd.print(digit4_total);
                        break;

                    case 2: 
                        if(digit4_sum_1 >= digit4_sum_2)
                            digit4_total = digit4_sum_1 - digit4_sum_2;
                        else{
                            lcd.write("-");
                            digit4_total = digit4_sum_2 - digit4_sum_1;}

                        lcd.print(digit4_total);
                        break;

                    case 3: 
                        digit4_total = (unsigned long)digit4_sum_1 * digit4_sum_2;
                        lcd.print(digit4_total);
                        break;

                    case 4:
                        digit4_total = digit4_sum_1 / digit4_sum_2;
                        lcd.print(digit4_total);
                        break;

                    default:
                        break;
                }
            }
        }
      
        else
        {
            reset_val = 0; 
          
            if(val != 0 && set_cal == 0){
        if(Keypressed == 'A'){
          lcd.write("+");
          set_cal=1;}
        
        else if(Keypressed == 'B'){
          lcd.write("-");
          set_cal=2;}

        else if(Keypressed == 'C'){
          lcd.write("*");
          set_cal=3;}

        else if(Keypressed == 'D'){
          lcd.write("/");
          set_cal=4;}
            }
        }
    }
}
