/*
 * DIO.c
 *
 * Created: 9/1/2020 11:46:07 PM
 *  Author: yehia
 */ 
#include "DIO.h"
#define  Fifteen 15
#define  Four  4
# define shift_Left <<
void DIO_WritePinDir(uint8 Port,uint8 PinNo,STD_Direction Dir)
{
	switch(Port)
	{
		case 'A':
		case 'a':
		if (Dir == STD_OUT)
		{
			SET_Bit(DDR_A,PinNo);
		}
		else
		{
			CLEAR_Bit(DDR_A,PinNo);
		}
		break;
		case 'B':
		case 'b':
		if (Dir == STD_OUT)
		{
			SET_Bit(DDR_B,PinNo);
		}
		else
		{
			CLEAR_Bit(DDR_B,PinNo);
		}
		break;
		
		case 'C':
		case 'c':
		if (Dir == STD_OUT)
		{
			SET_Bit(DDR_C,PinNo);
		}
		else
		{
			CLEAR_Bit(DDR_C,PinNo);
		}
		break;
		case 'D':
		case 'd':
		if (Dir == STD_OUT)
		{
			SET_Bit(DDR_D,PinNo);
		}
		else
		{
			CLEAR_Bit(DDR_D,PinNo);
		}
		break;
		
	}
}
void DIO_WritePin(uint8 Port,uint8 PinNo,STD_levelType level)
{
	switch(Port)
	{
		case 'A':
		case 'a':
		if (level == STD_high)
		{
			SET_Bit(PORT_A,PinNo);
		}
		else
		{
			CLEAR_Bit(PORT_A,PinNo);
		}
		break;
		case 'B':
		case 'b':
		if (level == STD_high)
		{
			SET_Bit(PORT_B,PinNo);
		}
		else
		{
			CLEAR_Bit(PORT_B,PinNo);
		}
		break;
		case 'C':
		case 'c':
		if (level == STD_high)
		{
			SET_Bit(PORT_C,PinNo);
		}
		else
		{
			CLEAR_Bit(PORT_C,PinNo);
		}
		break;
		case 'D':
		case 'd':
		if (level == STD_high)
		{
			SET_Bit(PORT_D,PinNo);
		}
		else
		{
			CLEAR_Bit(PORT_D,PinNo);
		}
		break;
		
	}
}
STD_levelType DIO_ReadPin(uint8 Port,uint8 PinNo)
{
	STD_levelType ret = -1;
	switch(Port)
	{
		case 'A':
		case 'a':
		ret = GIT_Bit(PIN_A,PinNo);
		break;
		case 'B':
		case 'b':
		ret = GIT_Bit(PIN_B,PinNo);
		break;
		case 'C':
		case 'c':
		ret = GIT_Bit(PIN_C,PinNo);
		break;
		case 'D':
		case 'd':
		ret = GIT_Bit(PIN_D,PinNo);
		break;
	}
	return ret;
	
}
void Dio_WritePortDir(uint8 PORT,STD_Direction dir)
{
	switch (PORT) 
	{
		/* check if the direction is input 
		put zero in the port bits else
		put one 
		*/
		case 'A':
		case  'a':
		DDR_A = dir == STD_IN ?0:255;
		break;
		case 'B':
		case  'b':
		DDR_B = dir == STD_IN ?0:255;
		break;
		case 'C':
		case  'c':
		DDR_C = dir == STD_IN ?0:255;
		break;
		case 'D':
		case  'd':
		DDR_D = dir == STD_IN ?0:255;
		break;
	}
}
uint8 Dio_ReadPort(uint8 PORT )
{
	
	uint8 sum = 0 ,count=1; //create counter which represent 1,2,4...,128
	switch(PORT)
	{
		case 'A':
		case 'a':
		for (uint8 i = 0; i < 8; i++)
		{
			if (GIT_Bit(PIN_A,i) == 1) // if the bit equals one change the value of sum 
			{
				sum += count;
			}
			else
			{
				
			}
			count *= 2; /// instade of  using pow() function 
		}
		break;
		case 'B':
		case 'b':
		for (uint8 i = 0; i < 8; i++)
		{
			if (GIT_Bit(PIN_B,i) == 1)
			{
				sum += count;
			}
			else
			{
				
			}
			count *= 2;
		}
		break;
		case 'C':
		case 'c':
		for (uint8 i = 0; i < 8; i++)
		{
			if (GIT_Bit(PIN_C,i) == 1)
			{
				sum += count;
			}
			else
			{
				
			}
			count *= 2;
		}
		break;
		case 'D':
		case 'd':
		for (uint8 i = 0; i < 8; i++)
		{
			if (GIT_Bit(PIN_D,i) == 1)
			{
				sum += count;
			}
			else
			{
				
			}
			count *= 2;
		}
		break;
	}
	return sum;
}
void Dio_WritePortVal(uint8 PORT, uint8 data)
{
	switch(PORT )
	{
		case 'A':
		case 'a':
		PORT_A = data;
		break;
		case 'B':
		case 'b':
		PORT_B = data;
		break;
		case 'C':
		case 'c':
		PORT_C = data;
		break;
		case 'D':
		case 'd':
		PORT_D = data;
		break;
	}
}
void Dio_WritePortLevel(uint8 PORT, STD_levelType Level)
{
	switch (PORT) 
	{

		case 'A':
		case  'a':
		PORT_A = Level == STD_low ?0x00:0xFF;
		break;
		case 'B':
		case 'b':
		PORT_B = Level == STD_low ?0x00:0xFF;
		break;
		case 'C':
		case  'c':
		PORT_C = Level == STD_low ?0x00:0xFF;
		break;
		case 'D':
		case  'd':
		PORT_D = Level == STD_low ?0x00:0xFF;
		break;
	}
}
void Dio_WriteHighNibbleVal(uint8 port, uint8 val)
{
	switch(port) 
	{
		case 'A':
		case 'a':
		PORT_A &= ~(Fifteen shift_Left Four); //clear the the last 4 bit in port A 
		PORT_A |= (val<<4);   //set the value of the last 4 bit in port A
		break;
		case 'B':
		case 'b':
		PORT_B &= ~(Fifteen shift_Left Four); //clear the the last 4 bit in port B
		PORT_B |= (val shift_Left Four);   //set the value of the last 4 bit in port B
		break;
		case 'C':
		case 'c':
		PORT_C &= ~(Fifteen shift_Left Four); //clear the the last 4 bit in port c
		PORT_C |= (val shift_Left Four);   //set the value of the last 4 bit in port c
		break;
		case 'D':
		case 'd':
		PORT_D &= ~(Fifteen shift_Left Four); //clear the the last 4 bit in port D
		PORT_D |= (val shift_Left Four);   //set the value of the last 4 bit in port D
		break;
	}
}
void Dio_WriteLowNibbleVal(uint8 port, uint8 val)
{
	switch(port)
	{
		case 'A':
		case 'a':
		PORT_A &= ~(Fifteen); //clear the the first 4 bit in port A
		PORT_A |= val;   //set the value of the first 4 bit in port A
		break;
		case 'B':
		case 'b':
		PORT_B &= ~Fifteen; //clear the the first 4 bit in port B
		PORT_B |= val;   //set the value of the first 4 bit in port B
		break;
		case 'C':
		case 'c':
		PORT_C &= ~(Fifteen); //clear the the first 4 bit in port c
		PORT_C |= val;   //set the value of the first 4 bit in port c
		break;
		case 'D':
		case 'd':
		PORT_D &= ~(Fifteen); //clear the the first 4 bit in port D
		PORT_D |= val;   //set the value of the first 4 bit in port D
		break;
	}
}
void Dio_WriteHighNibbleDir(uint8 port, STD_Direction dir) 
{
	switch(port)
	{
		case 'A':
		case 'a':
		if (dir == STD_IN)
		{
			DDR_A &= ~(Fifteen shift_Left Four); //make the last 4 bit in port A are input 
		}
		else
		{
			DDR_A |= (Fifteen shift_Left Four); //set the direction of the last 4 bit in port A "output"
		}
		break;
		case 'B':
		case 'b':
		if (dir == STD_IN)
		{
			DDR_B &= ~(Fifteen shift_Left Four); //make the last 4 bit in port B are input 
		}
		else
		{
			DDR_B |= (Fifteen shift_Left Four);   //set the direction of the last 4 bit in port B "output"
		}
		
		
		case 'C':
		case 'c':
		if (dir == STD_IN)
		{
			DDR_C &= ~(Fifteen shift_Left Four); //make the last 4 bit in port C are input
		}
		else
		{
			DDR_C |= (Fifteen shift_Left Four); //set the direction of the last 4 bit in port C "output"
		}
		break;
		case 'D':
		case 'd':
		if (dir == STD_IN)
		{
			DDR_D &= ~(Fifteen shift_Left Four); //make the last 4 bit in port D are input
		}
		else
		{
			DDR_D |= (Fifteen shift_Left Four);   //set the direction of the last 4 bit in port D "output"
		}
		
		
		break;
	}
}
void Dio_WriteLowNibbleDir(uint8 port, STD_Direction dir)
{
	switch(port)
	{
		case 'A':
		case 'a':
		if (dir == STD_IN)
		{
			DDR_A &= ~(Fifteen); //make the first 4 bit in port A are input
		}
		else
		{
			DDR_A |= (Fifteen ); //set the direction of the first 4 bit in port A "output"
		}
		break;
		case 'B':
		case 'b':
		if (dir == STD_IN)
		{
			DDR_B &= ~(Fifteen); //make the first 4 bit in port B are input
		}
		else
		{
			DDR_B |= (Fifteen );   //set the direction of the first 4 bit in port B "output"
		}
		
		
		case 'C':
		case 'c':
		if (dir == STD_IN)
		{
			DDR_C &= ~(Fifteen ); //make the first 4 bit in port C are input
		}
		else
		{
			DDR_C |= (Fifteen); //set the direction of the first 4 bit in port C "output"
		}
		break;
		case 'D':
		case 'd':
		if (dir == STD_IN)
		{
			DDR_D &= ~(Fifteen); //make the first 4 bit in port D are input
		}
		else
		{
			DDR_D |= (Fifteen );   //set the direction of the first 4 bit in port D "output"
		}
		
		
		break;
	}
}
