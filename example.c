/*
Estudante: Thomas Frentzel
Curso: Bacharelado em Ci�ncia da Computa��o
*/

#include <stdio.h>
    #include <stdlib.h>
    #include "FreeRTOS.h"
    #include "task.h"

    // Defini��o das constantes para limites dos dados vitais
    #define MIN_FREQ_CARD 20
    #define MAX_FREQ_CARD 140
    #define MIN_SAT_OXI 80
    #define MAX_SAT_OXI 100
    #define MIN_TEMP 34
    #define MAX_TEMP 41

    // Fun��o para gerar valores aleat�rios dentro de um intervalo
    int generate_random(int min, int max) {
        return (rand() % (max - min + 1)) + min;
    }

    // Tarefa para monitorar os batimentos card�acos
    void batimentos(void* pvParameters) {
        while (1) {
            int freq_card = generate_random(MIN_FREQ_CARD, MAX_FREQ_CARD);
            printf("Batimentos: %d\n", freq_card);

            if (freq_card < 50 || freq_card > 90) {
                printf("Alerta! Batimento cardiaco alterado!\n");
            }

            vTaskDelay(1000); // Aguarda 1 segundo
        }
        vTaskDelete(NULL);
    }

    // Tarefa para monitorar a satura��o de oxig�nio
    void saturacao(void* pvParameters) {
        while (1) {
            int sat_oxigenio = generate_random(MIN_SAT_OXI, MAX_SAT_OXI);
            printf("Saturacao: %d\n", sat_oxigenio);

            if (sat_oxigenio < 90) {
                printf("Alerta! Saturacao de oxigenio baixa!\n");
            }

            vTaskDelay(1000); // Aguarda 1 segundo
        }
        vTaskDelete(NULL);
    }

    // Tarefa para monitorar a temperatura
    void temperatura(void* pvParameters) {
        while (1) {
            int temperatura = generate_random(MIN_TEMP, MAX_TEMP);
            printf("Temperatura: %d\n", temperatura);

            if (temperatura < 35 || temperatura > 37.5) {
                printf("Alerta! Temperatura alterada!\n");
            }

            vTaskDelay(1000);// Aguarda 1 segundo
        }
        vTaskDelete(NULL);
    }

    int main_(void) {
        
        // Inicializa��o do FreeRTOS
        xTaskCreate(batimentos, "Monitor de Batimentos", 1000, NULL, 1, NULL);
    
        xTaskCreate(saturacao, "Monitor Saturacao", 1000, NULL, 1, NULL);
     
        xTaskCreate(temperatura, "Monitor Temperatura", 1000, NULL, 1, NULL);
        
        // Iniciar o escalonador
        vTaskStartScheduler();

        return 0;
    }