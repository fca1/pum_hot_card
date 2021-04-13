/*
 * t_serial.h
 *
 *  Created on: 9 avr. 2021
 *      Author: frant
 */

#ifndef CHAUFFAGE_INCLUDE_T_SERIAL_H_
#define CHAUFFAGE_INCLUDE_T_SERIAL_H_


enum e_opcode
{
E_SET_TEMP,
E_SET_ID,
E_STOP,
E_START,
};

#pragma pack(1)





struct t_comm_frame
{
uint8_t stx;
uint8_t length;
enum e_opcode opcode;
uint8_t tbl[0];

};



#pragma pack()


#endif /* CHAUFFAGE_INCLUDE_T_SERIAL_H_ */
