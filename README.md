A simple game developed for Arduino Nano and a TFT LCD screen.

## Build and Flash

> Make sure to install avr-gcc and avrdude: [https://github.com/m3y54m/start-avr](https://github.com/m3y54m/start-avr).

1. Take a look into the env variables set in the CMakeLists.txt file, and modify them for your needs:
```cmake
set(CMAKE_C_COMPILER avr-gcc)
set(MCU "atmega328p")
set(F_CPU "16000000UL")
set(BAUD "115200")
set(PROGRAMMER "arduino")
set(PORT "/dev/ttyUSB0")
```

2. Build the main file with cmake:
```shell
mkdir build
cd build
cmake ..  
```

3. Flash the hex file into your MCU:
```shell
cd build
make upload
```
