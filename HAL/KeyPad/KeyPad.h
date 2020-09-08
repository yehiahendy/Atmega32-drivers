/*
 * KeyPad.h
 *
 * Created: 9/8/2020 3:50:52 AM
 *  Author: yehia
 */ 
#ifndef KEYPAD_H_
#define KEYPAD_H_
#define KP_Port    'c'
#define KP_3          
#include "../../MCAL/DIO/DIO.h"
#include <util/delay.h>
void KP_VidInit(void);
uint8 KP_u8GetKey();





#endif /* KEYPAD_H_ */