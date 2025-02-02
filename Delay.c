#include <stdio.h>
#include "pico/stdlib.h"

#define LED_VERDE_PIN 13
#define LED_AMARELO_PIN 12
#define LED_VERMELHO_PIN 11
#define BUTTON_PIN 5

bool ciclo_ativo = false;

void iniciar_ciclo(){
    while (ciclo_ativo)
    {
        /* led verde aceso por 5 segundos */
        gpio_put(LED_VERDE_PIN, 1);
        sleep_ms(5000);
        gpio_put(LED_VERDE_PIN, 0);

         /* led Amarelo aceso por 2 segundos */
        gpio_put(LED_AMARELO_PIN, 1);
        sleep_ms(5000);
        gpio_put(LED_AMARELO_PIN, 0);

         /* led vermelho aceso por 5 segundos */
        gpio_put(LED_VERMELHO_PIN, 1);
        sleep_ms(5000);
        gpio_put(LED_VERMELHO_PIN, 0);

    }
    



}

int main()
{
    stdio_init_all();

    //inicia os leds dos pinos como saida
    gpio_init(LED_VERDE_PIN);
    gpio_set_dir(LED_VERDE_PIN,GPIO_OUT);

    gpio_init(LED_AMARELO_PIN);
    gpio_set_dir(LED_AMARELO_PIN,GPIO_OUT);
    
    gpio_init(LED_VERMELHO_PIN);
    gpio_set_dir(LED_VERMELHO_PIN,GPIO_OUT);

    //INICIALIZA E CONFIGURA O PINO DO PUSH-BUTTON COMO ENTRADA COM O PUSH_DOWN

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN,GPIO_IN);
    gpio_pull_down(BUTTON_PIN);

    while (true){
        //verifica se o botão foi pressionado
        if(gpio_get(BUTTON_PIN)){

            //Altera o estado do ciclo do semáforo
            ciclo_ativo= !ciclo_ativo;

            // Se o ciclo estiver ativo, inicia o ciclo do semáforo
            if (ciclo_ativo)
            {
                iniciar_ciclo();
            }
            
            //adiciona um pequeno delay para evitar múltiplas leituras do botão
            sleep_ms(200);

        }




    }
    
    
    
 
    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }

    return 0;
}
