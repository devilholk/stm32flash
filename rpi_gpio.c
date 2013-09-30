#include "rpi_gpio.h"

//
// Set up a memory regions to access GPIO
//
void rpi_gpio_setup_io()
{
   /* open /dev/mem */
   if ((rpi_gpio_mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0) {
      printf("can't open /dev/mem \n");
      exit(-1);
   }

   /* mmap GPIO */
   rpi_gpio_map = mmap(
      NULL,             //Any adddress in our space will do
      RPI_GPIO_BLOCK_SIZE,       //Map length
      PROT_READ|PROT_WRITE,// Enable reading & writting to mapped memory
      MAP_SHARED,       //Shared with other processes
      rpi_gpio_mem_fd,           //File to map
      RPI_GPIO_BASE         //Offset to GPIO peripheral
   );

   close(rpi_gpio_mem_fd); //No need to keep mem_fd open after mmap

   if (rpi_gpio_map == MAP_FAILED) {
      printf("mmap error %p\n", rpi_gpio_map);//errno also set!
      exit(-1);
   }

   // Always use volatile pointer!
   rpi_gpio = (volatile unsigned *)rpi_gpio_map;


} // setup_io


