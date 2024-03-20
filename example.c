/*
Estudante: Thomas Frentzel
Curso: Bacharelado em Ciência da Computação
*/

#include <stdio.h>
    #include <stdlib.h>
    #include "FreeRTOS.h"
    #include "task.h"
    #include <basic_io.h>

    // Definição das constantes para limites dos dados vitais
    #define MIN_FREQ_CARD 20
    #define MAX_FREQ_CARD 140
    #define MIN_SAT_OXI 80
    #define MAX_SAT_OXI 100
    #define MIN_TEMP 34
    #define MAX_TEMP 41

    // Função para gerar valores aleatórios dentro de um intervalo
    int generate_random(int min, int max) {
        return (rand() % (max - min + 1)) + min;
    }

    // Tarefa para monitorar os batimentos cardíacos
    void batimentos(void* pvParameters) {
        while (1) {
            int freq_card = generate_random(MIN_FREQ_CARD, MAX_FREQ_CARD);
            vPrintStringAndNumber("Batimentos:\n", freq_card);

            if (freq_card < 50 || freq_card > 90) {
               vPrintStringAndNumber("Alerta! Batimento cardiaco alterado!\n", freq_card);
            }

            vTaskDelay(1000); // Aguarda 1 segundo
        }
        vTaskDelete(NULL);
    }

    // Tarefa para monitorar a saturação de oxigênio
    void saturacao(void* pvParameters) {
        while (1) {
            int sat_oxigenio = generate_random(MIN_SAT_OXI, MAX_SAT_OXI);
            vPrintStringAndNumber("Saturacao:\n", sat_oxigenio);

            if (sat_oxigenio < 90) {
                vPrintStringAndNumber("Alerta! Saturacao de oxigenio baixa!\n", sat_oxigenio);
            }

            vTaskDelay(1000); // Aguarda 1 segundo
        }
        vTaskDelete(NULL);
    }

    // Tarefa para monitorar a temperatura
    void temperatura(void* pvParameters) {
        while (1) {
            int temperatura = generate_random(MIN_TEMP, MAX_TEMP);
            vPrintStringAndNumber("Temperatura:\n", temperatura);

            if (temperatura < 35 || temperatura > 37.5) {
                vPrintStringAndNumber("Alerta! Temperatura alterada!\n",temperatura);
            }

            vTaskDelay(1000);
        }
        vTaskDelete(NULL);
    }

    int main_(void) {
        
        // Inicialização do FreeRTOS
        xTaskCreate(batimentos, "Monitor de Batimentos", 1000, NULL, 1, NULL);
    
        xTaskCreate(saturacao, "Monitor Saturacao", 1000, NULL, 1, NULL);
     
        xTaskCreate(temperatura, "Monitor Temperatura", 1000, NULL, 1, NULL);
        
        // Iniciar o escalonador
        vTaskStartScheduler();

        return 0;
    }
