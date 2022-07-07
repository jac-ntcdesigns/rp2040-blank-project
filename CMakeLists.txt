cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(blank C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_BOARD seeed_xiao_rp2040)

pico_sdk_init()

# Set Debug build compiler arguments
set(CMAKE_CXX_FLAGS_DEBUG "-pipe -g -O0 -Wfatal-errors -Wpedantic -Wall -Wextra -Wconversion -Wshadow=local -Wdouble-promotion -Wformat=2 -Wformat-overflow=2 -Wformat-nonliteral -Wformat-security -Wformat-truncation=2 -Wnull-dereference -Wimplicit-fallthrough=3 -Wshift-overflow=2 -Wswitch-default -Wunused-parameter -Wunused-const-variable=2 -Wstrict-overflow=4 -Wstringop-overflow=3 -Wsuggest-attribute=pure -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wmissing-noreturn -Wsuggest-attribute=malloc -Wsuggest-attribute=format -Wmissing-format-attribute -Wsuggest-attribute=cold -Walloc-zero -Walloca -Wattribute-alias=2 -Wduplicated-branches -Wcast-qual")
set(CMAKE_C_FLAGS_DEBUG "-pipe -g -O0 -Wfatal-errors -Wpedantic -Wall -Wextra -Wconversion -Wshadow=local -Wdouble-promotion -Wformat=2 -Wformat-overflow=2 -Wformat-nonliteral -Wformat-security -Wformat-truncation=2 -Wnull-dereference -Wimplicit-fallthrough=3 -Wshift-overflow=2 -Wswitch-default -Wunused-parameter -Wunused-const-variable=2 -Wstrict-overflow=4 -Wstringop-overflow=3 -Wsuggest-attribute=pure -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wmissing-noreturn -Wsuggest-attribute=malloc -Wsuggest-attribute=format -Wmissing-format-attribute -Wsuggest-attribute=cold -Walloc-zero -Walloca -Wattribute-alias=2 -Wduplicated-branches -Wcast-qual")

# Set Release build compiler arguments
set(CMAKE_CXX_FLAGS_RELEASE "-pipe -Os -fno-builtin")
set(CMAKE_C_FLAGS_RELEASE "-pipe -Os -fno-builtin")

add_executable(${PROJECT_NAME}
	${PROJECT_NAME}.c
	)

target_link_libraries(
	${PROJECT_NAME} 
	pico_stdlib
	pico_multicore
   	hardware_pio
	hardware_pwm
	)

pico_enable_stdio_usb(${PROJECT_NAME} 0)
pico_enable_stdio_uart(${PROJECT_NAME} 1)

pico_add_extra_outputs(${PROJECT_NAME})
