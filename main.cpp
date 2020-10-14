#include "mbed.h"
#include <iostream>
#include <cstdlib>
//#include "BDDv3.h"
#include "CanCube.h"


DigitalOut led(LED1);

CanCube cube;

/* 
#define CAN_ADDR    0x0000
#define CAN_devType 0x0011
#define CAN_Idmask  0x3FF800

#define DEAD_TIME   300 //s

#define HBR_ADDR    0xC0

#define relays      2

//PinName relayPin[relays] = {A6, A0};

//can id macros//
#define pumpStateId     0x00
#define relayStateId    0x08
#define relay1mask      0x02
#define relay2mask      0x04
#define vipId           0x10
#define shtcId          0x11
#define RW              0x01

#define pumpStateMask   0x06
#define pumpDirMask     0x02
*/

static char counter = 0;
char buffer[4];
char buffer2[4];
char buffer3[64];
float f = 1.0;
float ff = 9.81;

float lf = 1.0;
float lff = 5.0;

Thread ct;
EventQueue cq;

/*
int main(void){
    cout << "start" << endl;

    ThisThread::sleep_for(5000);
    led = 0;

    while(true){
        led = !led;
        cout << cube.pump(0, 1) << endl;
        ThisThread::sleep_for(5000);
        led = !led;
        cout << cube.pump(0, 0) << endl;
        ThisThread::sleep_for(5000);
        led = !led;
        cout << cube.pump(1, 1) << endl;
        ThisThread::sleep_for(5000);
        led = !led;
        cout << cube.pump(0, 0) << endl;
        ThisThread::sleep_for(5000);
    }
}*/

/* 
CAN can(PA_11, PA_12);
CANMessage msg;


void blink(void){
    if(can.read(msg)){
        cout << "polTime : " << *(float*)&msg.data[0] << endl;
    }
}*/

///* GLobal CAN TEST
int main(void){
    cout << "start" << endl;

    can.frequency(250000);

    memcpy(&buffer[0], &f, 4);
    memcpy(&buffer2[0], &ff, 4);

    while(true){
        uint32_t canId = (CAN_devType << 17)|(0x0000)|(pumpStateId)|(0b110);
        if(!(can.write(CANMessage(canId, &buffer[0], 1, CANData, CANExtended)))){
            cout << "error" << endl;
            can.mode(CAN::Reset);
            can.mode(CAN::Normal);
        }else{
            cout << "sent 1" << endl;
        }

        led1 = !led1; 
        ThisThread::sleep_for(5000);

        canId = (CAN_devType << 17)|(0x0000)|(pumpStateId);
        cout << canId + 0 << endl;
        if(!(can.write(CANMessage(canId, &buffer[0], 1, CANData, CANExtended)))){
            cout << "error" << endl;
            can.mode(CAN::Reset);
            can.mode(CAN::Normal);
        }else{
            cout << "sent 2" << endl;
        }

        led1 = !led1;
        ThisThread::sleep_for(1000);
    }
}//*/

/* cube test
int main(void){

    can.frequency(250000);

    while(true){
        uint32_t canId = (CAN_devType << 17)|(CAN_ADDR << 11)|(pumpStateId)|(0x02);
        if(!(can.write(CANMessage(0x11, &buffer[0], 4, CANData, CANStandard)))){
            cout << "TX error" << endl;
            can.mode(CAN::Reset);
            can.mode(CAN::Normal);
        }else{
            cout << "message sent" << endl;
        }
        ThisThread::sleep_for(2000);
        canId = (CAN_devType << 17)|(CAN_ADDR << 11)|(pumpStateId)|(0x00);
        if(!(can.write(CANMessage(0x11, &buffer[0], 4, CANData, CANStandard)))){
            cout << "TX error" << endl;
            can.mode(CAN::Reset);
            can.mode(CAN::Normal);
        }else{
            cout << "message sent" << endl;
        }
        ThisThread::sleep_for(2000);
    }
    
}*/

