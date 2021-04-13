/*
 * temperature.h
 *
 *  Created on: 19 mars 2021
 *      Author: rapha
 */

#ifndef chauffage_HARD_G_SI7053_H_
#define chauffage_HARD_G_SI7053_H_

extern int16_t sensorSI7053_read_decideg(void);
extern void sensorSI7053_reset(void);
extern uint8_t * sensorSI7053_read_serial(uint64_t *ptr);


#endif /* chauffage_HARD_G_SI7053_H_ */
