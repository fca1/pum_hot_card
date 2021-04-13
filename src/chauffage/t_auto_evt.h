#pragma once


typedef enum e_auto_evt {
EVT_NONE,
EVT_INIT_HARD,
EVT_SET_PWM,
EVT_STOP_ASSER,
EVT_BLINK,
EVT_BAD,
EVT_TIMER_LOCKED,
EVT_ASK_MEAS,
EVT_RESULT_MEAS,
EVT_ASSERV_LOCKED,
EVT_UNLOCKED,
EVT_BLINK_FOUND // Il y a au moins une donnee lue dans le le NFC
} e_auto_evt ;
