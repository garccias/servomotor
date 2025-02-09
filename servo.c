#include "pico/stdlib.h"
#include "hardware/pwm.h"

 #define PWM_PIN 12    // Pino GPIO do LEDS para teste na placa BitDogLab
 // #define PWM_PIN 22       // Pino GPIO do servo

#define WRAP_VALUE 25000 // Período de 20ms (50Hz)

// pulsos de controle do servo
#define PULSE_MAX 2400 //  180 graus (2400us)
#define PULSE_90 1470  // 90 graus (1470us)
#define PULSE_MIN 500  // 0 graus (500us)

#define SWEEP_STEP 5   // 
#define SWEEP_DELAY 10 // 

// Função para configurar o PWM corretamente
void set_pwm_pulse(uint gpio, uint16_t pulse_width)
{
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    uint16_t level = (pulse_width * WRAP_VALUE) / 20000; 
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(gpio), level);
}

int main()
{
    stdio_init_all();

    // Configuração do GPIO para PWM
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(PWM_PIN);

    pwm_set_wrap(slice_num, WRAP_VALUE);
    pwm_set_clkdiv(slice_num, 100.0f); 
    pwm_set_enabled(slice_num, true);

    // 180 graus e aguardar 5s
    set_pwm_pulse(PWM_PIN, PULSE_MAX);
    sleep_ms(5000);

    // 90 graus e aguardar 5s
    set_pwm_pulse(PWM_PIN, PULSE_90);
    sleep_ms(5000);

    // 0 graus e aguardar 5s
    set_pwm_pulse(PWM_PIN, PULSE_MIN);
    sleep_ms(5000);

    // contínuo entre 0 e 180 graus
    while (true)
    {
        // 0° para 180°
        for (uint16_t pulse = PULSE_MIN; pulse <= PULSE_MAX; pulse += SWEEP_STEP)
        {
            set_pwm_pulse(PWM_PIN, pulse);
            sleep_ms(SWEEP_DELAY);
        }
        //  180° para 0°
        for (uint16_t pulse = PULSE_MAX; pulse >= PULSE_MIN; pulse -= SWEEP_STEP)
        {
            set_pwm_pulse(PWM_PIN, pulse);
            sleep_ms(SWEEP_DELAY);
        }
    }
}