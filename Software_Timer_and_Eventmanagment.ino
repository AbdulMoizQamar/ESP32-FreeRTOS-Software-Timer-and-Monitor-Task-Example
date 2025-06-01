#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
#include "freertos/task.h"

int Counter = 0;
TimerHandle_t xTimer;

// Timer callback function
void vTimerCallback(TimerHandle_t xTimer) {
  Counter++;  
  Serial.println("Timer callback executed. Counter incremented.");
}

// Task to monitor the shared variable
void monitorTask(void *parameter) {
  int lastCounter = -1;
  while (1) {
    if (lastCounter != Counter) {
      Serial.printf("Monitor Task: Counter changed to %d\n", Counter);
      lastCounter = Counter;
    }
    vTaskDelay(pdMS_TO_TICKS(500));  
}
}
void setup() {
  Serial.begin(115200);
  delay(1000);

  // Create the software timer (1s period, auto-reload)
  xTimer = xTimerCreate("MyTimer", pdMS_TO_TICKS(1000), pdTRUE, NULL, vTimerCallback);

  if (xTimer != NULL) {
    xTimerStart(xTimer, 0);  
  } else {
    Serial.println("Failed to create timer.");
  }

  // Create the task to monitor the counter
  xTaskCreate(
    monitorTask,    // Task function
    "MonitorTask",  // Task name
    2048,           // Stack size
    NULL,           // Parameter
    1,              // Priority
    NULL           // Task handle
  );
}

void loop() {
}
