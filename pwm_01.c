#include <stdio.h> //biblioteca padrão da linguagem C
#include "pico/stdlib.h" //subconjunto central de bibliotecas do SDK Pico
#include "hardware/pwm.h" //biblioteca para controlar o hardware de PWM

#define PWM_LED 12 //pino do LED conectado GPIO como PWM


//rotina principal
int main()
{
    //inicializa o sistema padrão de I/O
    stdio_init_all(); 

    //habilitar o pino GPIO como PWM
    gpio_set_function(PWM_LED, GPIO_FUNC_PWM);

    //obter o canal PWM da GPIO
    uint slice = pwm_gpio_to_slice_num(PWM_LED);

    //define o divisor de clock do PWM
    pwm_set_clkdiv(slice, 2.0);

    //definir o valor de wrap
    pwm_set_wrap(slice, 2000);

    //definir o cico de trabalho (duty cycle) do pwm
    pwm_set_gpio_level(PWM_LED, 1500);

    //habilita o pwm no slice correspondente
    pwm_set_enabled(slice, true);

    //loop principal
    while (true) {

        printf("slice:%d\n",slice);
        sleep_ms(1000);
    }
}
