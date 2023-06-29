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
void set_led(void);

bool EN1_OUT = false;
bool EN2_OUT = false;
bool CENTER_OUT = true;

int VOLUME_OUT = 1500;

int main() {
    config();
    while(1) {
        read_switches();
        set_pwm();
        set_led();
        wait_ms(5);
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
    bool EN1_status = EN1.read();
    bool EN2_status = EN2.read();
    bool CENTER_status = CENTER.read();
    static bool EN1_status_old = EN1_status;
    static bool EN2_status_old = EN2_status;
    static bool CENTER_status_old = CENTER_status;
    double VOLUME_voltage = VOLUME.read();

    if(EN1_status_old == 0 && EN1_status == 1)
        EN1_OUT = !EN1_OUT;
    if(EN2_status_old == 0 && EN2_status == 1)
        EN2_OUT = !EN2_OUT;
    if(CENTER_status_old == 0 && CENTER_status == 1)
        CENTER_OUT = !CENTER_OUT;

    VOLUME_OUT = 500 + (int)(VOLUME_voltage * 2000.0);
}

void set_pwm(void) {
    PWM1.pulsewidth_us(VOLUME_OUT);
    PWM2.pulsewidth_us(VOLUME_OUT);
}

void set_led(void) {
    STO_1 = EN1_OUT;
    STO_2 = EN2_OUT;
    STO_C = CENTER_OUT;
}