#ifndef LIB_H_
#define LIB_H_

// Port define
#define IN1 0
#define IN2 1
#define IN3 2
#define IN4 3
#define chuky 1200
#define dutyc 800

// Timer1_PWM Function
void PWM_Init(uint16_t);
void PWM_Start(void);

// DC_Motor Controller Function
void Tien(uint16_t);
void Lui(uint16_t);
void Trai(uint16_t);
void Phai(uint16_t);
void Dung(uint16_t);

#endif