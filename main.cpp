#include "mbed.h"
#include "uLCD_4DGL.h"
// #include "FATDirHandle.h"
// #include "FATFileHandle.h"
// #include "FATFileSystem.h"
// #include "MemFileSystem.h"
// #include "SDFileSystem.h"
#include <cstdio>

AnalogIn Up(A0);
AnalogIn Down(A1);
AnalogIn Choose(A2);
AnalogOut Aout(D7);
AnalogIn Ain(A3);
uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;

DigitalIn Sample(USER_BUTTON);
BufferedSerial pc(USBTX, USBRX);

void LCD();
void generate_wave(int y);
void write_file();
float ADCdata[3672];
             
Timer t;

int main()
{
    printf("START! \n\r");  
    LCD();

}

void LCD() {
    uLCD.media_init(); // initialize uSD card
    uLCD.locate(0, 0);
    uLCD.text_width(2); //4X size text
    uLCD.text_height(2);
    uLCD.color(RED);
    uLCD.printf("\n   MENU \n\n");

    uLCD.color(WHITE);
    uLCD.printf("  10HZ \n");
    uLCD.printf("  100HZ \n");
    uLCD.printf("  500HZ \n");
    int x1 = 20; int y1 = 50;
    uLCD.rectangle(x1, y1, x1+85, y1+15, RED);

    //50 65 80 
    while(1) {
        if(Up.read() > 0.9f) {
            printf("Up botton PRESSED \n\r");
            uLCD.rectangle(x1, y1, x1+85, y1+15, BLACK);
            if(y1 > 50) {
                y1 -= 15;
                uLCD.rectangle(x1, y1, x1+85, y1+15, RED);                
            }else{
                y1 = 80;
                uLCD.rectangle(x1, y1, x1+85, y1+15, RED);                 
            }

        }
            
        if(Down.read() > 0.9f) {
            printf("Down botton PRESSED \n\r");
            uLCD.rectangle(x1, y1, x1+85, y1+15, BLACK);
            if(y1 < 80) {
                y1 += 15;
                uLCD.rectangle(x1, y1, x1+85, y1+15, RED);
            }else {
                y1 = 50;
                uLCD.rectangle(x1, y1, x1+85, y1+15, RED);
            }

        }
        //50 65 80 95 
        if(Choose.read() > 0.9f) {
            printf("Choose botton PRESSED \n\r"); 
            generate_wave(y1);
        }
           
        ThisThread::sleep_for(250ms);
    }

}

void generate_wave(int y) {
    int period = 0;
    int samples = 0;
    switch (y)
    {
    case 50:
    //10hz
        period = 100000;
        samples = 3672;
        break;
    //100
    case 65:
        period = 10000;
        samples = 362;        
        break;
    //500
    case 80:
        period = 2000;
        samples = 72;        
        break;
    default:
        break;
    }
    float tmp = 0.1f/(period/272);
    printf("Start generate wave form!! \n\r");
    printf("%d\n\r", samples);
    ThisThread::sleep_for(1s);
    
    while (Down.read() < 0.9f && Up.read() < 0.9f && Choose.read() < 0.9f && Sample == 1) {
        int idx = 0;
        for (float i = 0.0f; i <= 0.9f; i += (tmp*9)) {
            Aout = i;
            ADCdata[idx++] = Ain;
        }
        for (float i = 0.9f; i >= 0.0f; i -= tmp) {
            Aout = i;
            ADCdata[idx++] = Ain;
        }
    }  
    

    printf("Stop generate wave form! \n\r");
    if(Sample == 0) {
        printf("Start catching data\n\r");
        ThisThread::sleep_for(200ms);
        for(int i=0; i<samples; i++) {
            printf("%f\n\r", ADCdata[i]);
            ThisThread::sleep_for(200ms);
        }
    }

}
     
