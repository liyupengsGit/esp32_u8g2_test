#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include <driver/gpio.h>
#include <driver/spi_master.h>
#include <nvs_flash.h>
#include <u8g2_esp32_hal.h>


void oled(void *pvParameters)
{
    	u8g2_t u8g2;
        u8g2_Setup_ssd1306_i2c_128x64_noname_f(&u8g2,U8G2_R0,u8g2_esp32_i2c_byte_cb,u8g2_esp32_gpio_and_delay_cb);
	u8x8_SetI2CAddress(&u8g2.u8x8, (CONFIG_ADR<<1));// set the display address shifted left (0x3C == 0X78) => ( 0011 1100 = 0111 1000)
	u8g2_InitDisplay(&u8g2);
	u8g2_SetPowerSave(&u8g2, 0);
	while(1) {
		u8g2_ClearBuffer(&u8g2);
		u8g2_SetFont(&u8g2, u8g2_font_timR14_tf);
		u8g2_DrawStr(&u8g2, 2,48,"TESTE!!");
		u8g2_SendBuffer(&u8g2);
		vTaskDelay(1000 / portTICK_RATE_MS);

		u8g2_ClearBuffer(&u8g2);
		u8g2_SetFont(&u8g2, u8g2_font_timR14_tf);
		u8g2_DrawStr(&u8g2, 2,17,"Hello World!");
		u8g2_SendBuffer(&u8g2);
		vTaskDelay(1000 / portTICK_RATE_MS);
	}
}


void app_main() {
    nvs_flash_init();

	u8g2_esp32_hal_t u8g2_esp32_hal = U8G2_ESP32_HAL_DEFAULT;
	u8g2_esp32_hal.sda = CONFIG_SDA;
	u8g2_esp32_hal.scl = CONFIG_SCL;
	u8g2_esp32_hal.reset = CONFIG_RST;
	u8g2_esp32_hal_init(u8g2_esp32_hal);

	xTaskCreate(&oled, "oled", 2048, NULL, 1, NULL);

}
