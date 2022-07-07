#include <stdio.h>
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/timer.h"
#include "hardware/sync.h"
#include "hardware/pwm.h"

#define LED_RED 17
#define LED_GREEN 16
#define LED_BLUE 25

int main()
{
	stdio_init_all();
	int count = 0;
	gpio_init(LED_RED);
	gpio_set_dir(LED_RED, GPIO_OUT);
	gpio_init(LED_GREEN);
	gpio_set_dir(LED_GREEN, GPIO_OUT);
	gpio_init(LED_BLUE);
	gpio_set_dir(LED_BLUE, GPIO_OUT);
	gpio_init(26);
	gpio_set_dir(26, GPIO_OUT);

	while (1)
	{
		count++;
		gpio_put(LED_RED, 1);
		gpio_put(LED_GREEN, 1);
		gpio_put(LED_BLUE, 1);
		gpio_put(26, 1);
		sleep_ms(25);
		gpio_put(LED_RED, 0);
		gpio_put(LED_GREEN, 0);
		gpio_put(LED_BLUE, 0);
		gpio_put(26, 0);
		sleep_ms(25);
		printf("hi there\n");
	}
}
