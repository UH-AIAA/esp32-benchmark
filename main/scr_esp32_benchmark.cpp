///////////////////////////////////////////////////////////////////////
/*                       SCR ESP-32 Benchmark                        */
///////////////////////////////////////////////////////////////////////
/*                           N. Samuell                              */
/*                      FreeRTOS/ESP-IDF test                        */
/*                          MIT License                              */
///////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <utility/imumaths.h>

#include "esp_system.h"
#include "driver/gpio.h"

// SPI imports, I^2C, and UART Imports
#include "SPI.h"
#include "Arduino.h"
#include "Adafruit_BMP3XX.h"
#include "Adafruit_ADXL375.h"
#include "Adafruit_LSM6DSO32.h"
#include "Adafruit_BNO055.h"
#include "Adafruit_GPS.h"
#include "LoRa.h"

// SRAD Imports
#include "SRAD_PHX.h"

// Sensor SPI init
#define SPI_SCLK_PIN 12
#define SPI_MISO_PIN 13
#define SPI_MOSI_PIN 11
#define SPI_MAX_TRSZ 4096

// SD+LoRa SPI Init
#define VSPI_SCLK_PIN 18
#define VSPI_MISO_PIN 17
#define VSPI_MOSI_PIN 16
// #define VSPI_MAX_TRSZ 4092

// I^2C Init
#define I2C_SDA 8
#define I2C_SCL 9

// CS definitions
#define BMP390_CS 10
#define ADXL375_CS 5
#define LSM6DSO32_CS 4

#define LORA_CS 7

// Lo-Ra Control Pins
#define LORA_RST 21
#define LORA_IRQ 19
#define LORA_FREQ 915E6

// Chip Object Instantiation
Adafruit_BMP3XX BMP;
Adafruit_ADXL375 ADXL(SPI_SCLK_PIN, SPI_MISO_PIN, SPI_MOSI_PIN, ADXL375_CS);
Adafruit_LSM6DSO32 LSM;
Adafruit_BNO055 BNO(55, BNO055_ADDRESS_A, &Wire);
Adafruit_GPS GPS(&Wire);

void init_spi() {
    // set outputs/inputs for software spi
    gpio_set_direction(GPIO_NUM_12, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_13, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_11, GPIO_MODE_INPUT);

    // start SPI bus
    BMP.begin_SPI(BMP390_CS, SPI_SCLK_PIN, SPI_MISO_PIN, SPI_MOSI_PIN);
    ADXL.begin();
    LSM.begin_SPI(LSM6DSO32_CS, SPI_SCLK_PIN, SPI_MISO_PIN, SPI_MOSI_PIN);
}

void init_I2C() {
    Wire.begin(I2C_SDA, I2C_SCL);
}

// TODO: example tasks
// void hello_task(void *pvParameter)
// {
// 	while(1)
// 	{
// 	    printf("Hello world!\n");
// 	    vTaskDelay(100 / portTICK_PERIOD_MS);
// 	}
// }
// void blinky(void *pvParameter)
// {
//     esp_rom_gpio_pad_select_gpio(BLINK_GPIO);
//     /* Set the GPIO as a push/pull output */
//     gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
//     while(1) {
//         /* Blink off (output low) */
//         gpio_set_level(BLINK_GPIO, 0);
//         vTaskDelay(1000 / portTICK_PERIOD_MS);
//         /* Blink on (output high) */
//         gpio_set_level(BLINK_GPIO, 1);
//         vTaskDelay(1000 / portTICK_PERIOD_MS);
//     }
// }

void read_SPI_sensors(void *pvParamter) {
    while(1) {
        /* ripped from SRAD_PHX */

    }
}

extern "C" void app_main()
{
    // init Arduino Framework from ESP HAL
    initArduino();

    // init SPI buses
    init_spi();

    // init I^2C bus
    init_I2C();

    // dump GPIO config
    gpio_dump_io_configuration(stdout, SOC_GPIO_VALID_GPIO_MASK);


    // xTaskCreate(&hello_task, "hello_task", 2048, NULL, 5, NULL);
    // xTaskCreate(&blinky, "blinky", 512,NULL,5,NULL );
}
