# ESP32-FreeRTOS-Software-Timer-and-Monitor-Task-Example
This project demonstrates how to use FreeRTOS software timers with the ESP32 using the Arduino framework. 
📝 Description:
This project demonstrates how to use FreeRTOS software timers with the ESP32 using the Arduino framework. A timer is created that increments a shared counter every 1 second. A separate task monitors changes in this counter and logs them via serial output.
This is an ideal example to learn how timers and tasks can work together in a non-blocking and synchronized way using FreeRTOS.

✅ Features:
Uses xTimerCreate() to configure a periodic software timer
A counter is incremented inside the timer callback function
A separate FreeRTOS task continuously monitors changes to the counter
Efficient task-delay logic using vTaskDelay()

📦 Requirements:
ESP32 development board
Arduino IDE or PlatformIO
FreeRTOS (included with ESP32 Arduino core)

