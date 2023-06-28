#include "mbed.h"

DigitalOut STO_1 (PB_1);
DigitalOut STO_2 (PF_0);
DigitalOut STO_C (PB_0);

PwmOut PWM1 (PA_8);
PwmOut PWM2 (PA_11);

DigitalIn EN1 (PA_6);
DigitalIn EN2 (PA_5);
DigitalIn CENTER (PA_7);

AnalogIn VOLUME (PA_0);

void config(void);
void read_switches(void);
void set_pwm(void);


int main() {
    config();
    while(1) {
        read_switches();
    }
}

void config(void) {
    EN1.mode(PullUp);
    EN2.mode(PullUp);
    CENTER.mode(PullUp);
    PWM1.period_ms(20);
    PWM2.period_ms(20);
}

void read_switches(void) {
    static bool EN1_status = EN1.read();
    static bool EN2_status = EN2.read();
    static bool CENTER_status = CENTER.read();
}

void set_pwm(void) {
    PWM1.pulsewidth_us(1530);
    PWM2.pulsewidth_us(1530);
}