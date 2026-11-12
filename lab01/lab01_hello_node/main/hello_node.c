#include <stdio.h>
#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include "esp_heap_caps.h"
#include "esp_log.h"
#include "driver/gpio.h"

static const char *TAG = "lab01";

#define LED_GPIO 2

void app_main(void)
{
    gpio_config_t led = {
        .pin_bit_mask = 1ULL << LED_GPIO,
        .mode = GPIO_MODE_OUTPUT,
    };
    gpio_config(&led);

    unsigned i = 0;
    bool level = false;

    while (1) {
        level = !level;
        gpio_set_level(LED_GPIO, level);
        ESP_LOGI(TAG, "iteration %u, time %lld ms, free heap %u B",
                 i++,
                 (long long)(esp_timer_get_time() / 1000),
                 (unsigned)heap_caps_get_free_size(MALLOC_CAP_8BIT));
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}