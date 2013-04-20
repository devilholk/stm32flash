#ifndef _RPI_GPIO_H
#define _RPI_GPIO_H


#define RPI_GPIO_BCM2708_PERI_BASE        0x20000000
#define RPI_GPIO_BASE                (RPI_GPIO_BCM2708_PERI_BASE + 0x200000) /* GPIO controller */


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define RPI_GPIO_PAGE_SIZE (4*1024)
#define RPI_GPIO_BLOCK_SIZE (4*1024)

int  rpi_gpio_mem_fd;
void *rpi_gpio_map;

// I/O access
volatile unsigned *rpi_gpio;

// GPIO setup macros. Always use INP_GPIO(x) before using OUT_GPIO(x) or SET_GPIO_ALT(x,y)
#define RPI_INP_GPIO(g) *(rpi_gpio+((g)/10)) &= ~(7<<(((g)%10)*3))
#define RPI_OUT_GPIO(g) *(rpi_gpio+((g)/10)) |=  (1<<(((g)%10)*3))
#define RPI_SET_GPIO_ALT(g,a) *(rpi_gpio+(((g)/10))) |= (((a)<=3?(a)+4:(a)==4?3:2)<<(((g)%10)*3))

#define RPI_GPIO_SET *(rpi_gpio+7)  // sets   bits which are 1 ignores bits which are 0
#define RPI_GPIO_CLR *(rpi_gpio+10) // clears bits which are 1 ignores bits which are 0

void rpi_gpio_setup_io();


#endif
