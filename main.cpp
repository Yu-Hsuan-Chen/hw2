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
// LocalFileSystem local("local");  // Create the local filesystem under the name "local"
BufferedSerial pc(USBTX, USBRX);
void LCD();
void generate_wave(int y);
void write_file();
int sample = 100;
float ADCdata[100];
             


int main()
{
    printf("START! \n\r");  

    // FILE *fp = fopen("out.txt", "w"); 
    // fprintf(fp, "Hello World!");
    // fclose(fp);
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
    uLCD.printf("  200HZ \n");
    uLCD.printf("  400HZ \n");
    uLCD.printf("  500HZ \n");
    uLCD.printf("  1000HZ \n");
    int x1 = 20; int y1 = 50;
    uLCD.rectangle(x1, y1, x1+85, y1+15, RED);

    //50 65 80 95 
    while(1) {
        if(Up.read() > 0.9f) {
            printf("Up botton PRESSED \n\r");
            uLCD.rectangle(x1, y1, x1+85, y1+15, BLACK);
            if(y1 > 50) {
                y1 -= 15;
                uLCD.rectangle(x1, y1, x1+85, y1+15, RED);                
            }else{
                y1 = 95;
                uLCD.rectangle(x1, y1, x1+85, y1+15, RED);                 
            }

        }
            
        if(Down.read() > 0.9f) {
            printf("Down botton PRESSED \n\r");
            uLCD.rectangle(x1, y1, x1+85, y1+15, BLACK);
            if(y1 < 95) {
                y1 += 15;
                uLCD.rectangle(x1, y1, x1+85, y1+15, RED);
            }else {
                y1 = 50;
                uLCD.rectangle(x1, y1, x1+85, y1+15, RED);
            }

        }
        //50 65 80 95 
        if(Choose.read() > 0.9f) {
            generate_wave(y1);
            
        }
           
        ThisThread::sleep_for(250ms);
    }

}

void generate_wave(int y) {
    int period = 0;
    printf("Choose botton PRESSED \n\r"); 
    switch (y)
    {
    case 50:
        period = 5000;
        break;
    case 65:
        period = 2500;
        break;
    case 80:
        period = 2000;
        break;
    case 95:
        period = 1000;
        break;
    default:
        break;
    }
    printf("y = %d, Period(us) = %d\n\r", y, period);
    printf("Start generate wave form!! \n\r");
    ThisThread::sleep_for(1s);
    while (Down.read() < 0.9f && Up.read() < 0.9f && Choose.read() < 0.9f && Sample == 1) {
        //0.1 period
        int idx = 0;
        for (float i = 0.0f; i <= 0.9f; i += 0.09f) {
            Aout = i;
            ADCdata[idx++] = Ain;
            ADCdata[idx++] = Ain;
            ADCdata[idx++] = Ain;
            ADCdata[idx++] = Ain;
            ADCdata[idx++] = Ain;
            wait_us(0.1*period/10);
        }
        //0.9 period
        for (float i = 0.9f; i >= 0.0f; i -= 0.09f) {
            Aout = i;
            ADCdata[idx++] = Ain;
            ADCdata[idx++] = Ain;
            ADCdata[idx++] = Ain;
            ADCdata[idx++] = Ain;
            ADCdata[idx++] = Ain;
            wait_us(0.9*period/10);
        }
    }  
    printf("Stop generate wave form! \n\r");
    if(Sample == 0) {
        // write_file();
        // printf("Writing over! \n\r");
        printf("Start catching data\n\r");
        ThisThread::sleep_for(200ms);
        for(int i=0; i<sample; i++) {
            printf("%f\n\r", ADCdata[i]);
            ThisThread::sleep_for(200ms);
        }
    }

}


