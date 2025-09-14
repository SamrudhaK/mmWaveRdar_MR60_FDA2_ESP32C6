#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

static const char *TAG = "LightRGB";

// Use the built-in LED pin for ESP32-C6
#define LED_PIN GPIO_NUM_2  // Built-in LED on most ESP32 boards

void app_main(void)
{
    ESP_LOGI(TAG, "Starting LightRGB application");
    
    // Initialize the built-in LED
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(LED_PIN, 0);
    
    ESP_LOGI(TAG, "LED initialized on GPIO %d", LED_PIN);
    
    while (1) {
        // Blink the built-in LED 10 times
        ESP_LOGI(TAG, "Starting blink sequence");
        for (int i = 0; i < 10; i++) {
            gpio_set_level(LED_PIN, 1);  // Turn on LED
            vTaskDelay(pdMS_TO_TICKS(100));
            gpio_set_level(LED_PIN, 0);   // Turn off LED
            vTaskDelay(pdMS_TO_TICKS(100));
        }
        
        // Fade effect using PWM-like approach
        ESP_LOGI(TAG, "Starting fade sequence");
        for (int brightness = 255; brightness >= 0; brightness--) {
            // Simple PWM simulation - on/off with varying duty cycle
            for (int cycle = 0; cycle < 10; cycle++) {
                if (cycle < (brightness / 25)) {
                    gpio_set_level(LED_PIN, 1);
                } else {
                    gpio_set_level(LED_PIN, 0);
                }
                vTaskDelay(pdMS_TO_TICKS(1));
            }
        }
        
        ESP_LOGI(TAG, "Cycle complete, restarting...");
        vTaskDelay(pdMS_TO_TICKS(1000));  // Wait 1 second before next cycle
    }
} 