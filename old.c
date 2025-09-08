// old shit worth hanging on to

void init_spi(void) {
    // TODO: complete off ESP-IDF docs

    // TODO: init Sensor SPI
    
    // host configuration struct
    const spi_bus_config_t spi_sensor_config = {
        .mosi_io_num = SPI_MOSI_PIN,    // MOSI Pin select,
        .miso_io_num = SPI_MISO_PIN,    // MISO Pin select,
        .sclk_io_num = SPI_SCLK_PIN,    // SCLK Pin select,
        .max_transfer_sz = 0,           // use default
        .intr_flags = 0,                // interrupt flags, set to zero if unused
    };

    // device configuration structs:
    const spi_device_interface_config_t BMP390_CFG = {
        .dummy_bits = 8,                            // dummy bits, BMP390 uses 1 dummy byte (8 bits)
        .mode = 0,                                  // SPI Mode, BMP390 is 0 mode compatible
        SPI_CLK_SRC_DEFAULT,                        // SPI clock source, this is default
        .duty_cycle_pos = 128,                      // default
        .clock_speed_hz = 5000000,                  // ADXL375 clock speed
        .input_delay_ns = 0,                        // default, check docs if we need to tune for HF
        .sample_point = SPI_SAMPLING_POINT_PHASE_0, // default
        .spics_io_num = BMP390_CS,                  // CS Pin for BMP390
        .flags = 0,                                 // no flags needed (i think)
        .queue_size = 16,                           // SPI transaction buffer size
        .pre_cb = NULL,                             // callbacks unused generally
        .post_cb = NULL,                            //
    };

    const spi_device_interface_config_t ADXL375_CFG = {
        .dummy_bits = 8,                            // dummy bits, BMP390 uses 1 dummy byte (8 bits)
        .mode = 3,                                  // SPI Mode, ADXL375 is not 0 mode compatible
        SPI_CLK_SRC_DEFAULT,                        // SPI clock source, this is default
        .duty_cycle_pos = 128,                      // default
        .clock_speed_hz = 5000000,                  // ADXL375 SPI Clock speed
        .input_delay_ns = 0,                        // default, check docs if we need to tune for HF
        .sample_point = SPI_SAMPLING_POINT_PHASE_0, // default
        .spics_io_num = ADXL375_CS,                 // CS Pin for ADXL375
        .flags = 0,                                 // no flags needed (i think)
        .queue_size = 16,                           // SPI transaction buffer size
        .pre_cb = NULL,                             // callbacks unused generally
        .post_cb = NULL,                            //
    };

    // initialize bus
    spi_bus_initialize(SPI2_HOST, &spi_sensor_config, SPI_DMA_CH_AUTO); // TODO: ADD ERROR HANDLING

    // TODO: init SD/LoRa SPI (spi_alt)
    spi_bus_config_t spi_alt_config = {
        .mosi_io_num = VSPI_MOSI_PIN,   // MOSI Pin select,
        .miso_io_num = VSPI_MISO_PIN,   // MISO Pin select,
        .sclk_io_num = VSPI_SCLK_PIN,   // SCLK Pin select,
        .max_transfer_sz = 0,           // use default
        .intr_flags = 0,                // interrupt flags, set to zero if unused
    };
}
