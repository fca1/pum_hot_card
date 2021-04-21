#pragma once

#include <stdint.h>

#pragma pack(1)


enum e_cmd
	{
	GET_STATUS = 0x30,  // Donne la temperature, la consigne, et le fan
    ENABLE_HEAT = 0x31, //   # Met en route le chauffage ou non.
    SET_PARAMS = 0x32, //   # Parametre de puissance max, fan , pid et Temp de consigne
	ASK_IDENTITY=0x33,
	};

struct t_header
{
uint8_t 	stx;
uint8_t 	adddr;
enum e_cmd 	cmd;
};

struct t_footer
{
	uint8_t etx;
	uint8_t chk;
};

enum e_report_led
{
E_LED_OFF,
E_LED_LOW,
E_LED_ON,

};


struct t_enable
{
uint8_t actif;
};

struct t_set_params
{
uint8_t enabled;
int16_t deciTemp;
uint8_t fan_min;
uint8_t fan_max;
uint8_t pwm_min;
uint8_t pwm_max;
enum e_report_led leds_report;

uint32_t pid_p;
uint32_t pid_i;
uint32_t pid_d;
};



struct t_status
{
uint8_t	   enabled;// si False, le systeme n'a pas le droit de chauffer.
uint8_t     actif;// True si le systeme est en asservissement de t°
int16_t 	deciTemp;// Temperature en dixieme de degre
uint8_t	    locked;// True si le systeme est asservi
uint8_t	    power_pwm;//Entre 0 et 100
uint8_t	    power_fan;// Entre 0 et 100
};

struct t_identity
{
uint64_t		identity;
};



struct t_comm_rcve
{
struct t_header header;
union
	{
	uint8_t				buffer[0];
	struct t_set_params	params;
	struct t_enable		enable;
	struct t_identity	identity;
	} u;
struct t_footer footer;
};

struct t_comm_emit
{
struct t_header header;
union
	{
	uint8_t				buffer[0];
	struct t_status		status;
	struct t_identity	identity;
	} u;
struct t_footer footer;
};



#pragma pack()

