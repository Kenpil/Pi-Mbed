#include <bcm2835.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char buf[1];
    char buf2[1];
    char buf3[1];

    if (!bcm2835_init())return 1;
    bcm2835_i2c_begin();                //Start I2C operations.
    bcm2835_i2c_setSlaveAddress(0x05);  //I2C address
    bcm2835_i2c_set_baudrate(10000);    //1M baudrate
    printf("started!\n");

    while(1)
    {
        buf[0] = 0x05;    //LED ON
        bcm2835_i2c_write(buf,1);
        bcm2835_i2c_read(buf2,1);
        bcm2835_delay(100);
        buf[0] = 0x05;     //LED OFF
        bcm2835_i2c_write(buf,1);
        bcm2835_i2c_read(buf2,1);
        bcm2835_delay(100);
    }
    bcm2835_i2c_end();
    bcm2835_close();
    return 0;
}
