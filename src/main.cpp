#include <kinetis.h>
#include <stdlib.h>
#include <Arduino.h>
#include <FreeRTOS.h>
#include <task.h>
#include <usb_dev.h>

#define LED 13
#define LED_BLINK_TIME 200
#define SERIAL_TIME 1000

void blink_task(void *args)
{
    pinMode(LED, OUTPUT);

    while (1) {
        digitalWrite(LED, LOW);
        vTaskDelay(LED_BLINK_TIME / portTICK_PERIOD_MS);
        digitalWrite(LED, HIGH);
        vTaskDelay(LED_BLINK_TIME / portTICK_PERIOD_MS);
    }
}

void serial_task(void *args)
{
    Serial.begin(115200);

    while (1) {
        Serial.println("Hello World !");
        vTaskDelay(SERIAL_TIME);
    }
}

void setup() {
  // create the tasks
  xTaskCreate(blink_task, "blink", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
  xTaskCreate(serial_task, "serial", configMINIMAL_STACK_SIZE, NULL, 2, NULL);

  // start scheduler, main should stop functioning here
  vTaskStartScheduler();

  for(;;);
}

void loop() {

}
