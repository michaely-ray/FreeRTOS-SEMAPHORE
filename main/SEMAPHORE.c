#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

SemaphoreHandle_t binSemaphore;

void handleWifi(void *params)
{
    while (true)
    {
        vTaskDelay(5000/ portTICK_PERIOD_MS);
        printf("GET IP \n\n");
        vTaskDelay(5000/ portTICK_PERIOD_MS);
        xSemaphoreGive(binSemaphore);
    }
}

void initMqtt(void)
{
    printf("MQTT Start\n\n");
}

void initWifi(void)
{
     xTaskCreate(&handleWifi, "handleWIFI", 2048, NULL, configMAX_PRIORITIES-1, NULL);
}

void connections(void)
{
    initWifi();
    xSemaphoreTake(binSemaphore, portMAX_DELAY);
    initMqtt(); 
}

void app_main(void)
{
    binSemaphore = xSemaphoreCreateBinary();
    connections();
}
