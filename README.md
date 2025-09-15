# ESP32 Benchmark

The point of this code is to run a minial CFE (Core Flight Environment) that does the following things:

- collect data from essential sensors
- save data somewhere on disk
- transmit data over LoRa antenna

in the following ways:

- run within FreeRTOS
- utilize the SMP multi-core model (Symmetric Multiprocessing)

The goal of this project is to see whether or not the ESP32 is in the ballpark of our hardware performance needs given our current design requirements.
