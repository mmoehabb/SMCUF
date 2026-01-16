cmake_minimum_required(VERSION 3.10)

project(SMCUF C)

set(CMAKE_C_COMPILER avr-gcc)
set(MCU "atmega328p")
set(F_CPU "16000000UL")
set(BAUD "115200")
set(PROGRAMMER "arduino")
set(PORT "/dev/ttyUSB0")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mmcu=${MCU} -DF_CPU=${F_CPU} -Os -Wall")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME}.elf main.c)

target_include_directories(${PROJECT_NAME}.elf
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_custom_command(
    TARGET ${PROJECT_NAME}.elf
    POST_BUILD
    COMMAND avr-objcopy -O ihex -R .eeprom ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
    COMMENT "Generating ${PROJECT_NAME}.hex for flashing"
)

# Run 'make upload' to flash the MCU using avrdude
add_custom_target(upload
    COMMAND avrdude -F -V -c ${PROGRAMMER} -p ${MCU} -P ${PORT} -b ${BAUD} -U flash:w:${PROJECT_NAME}.hex
    DEPENDS ${PROJECT_NAME}.elf
    COMMENT "Uploading to ${MCU}..."
)
