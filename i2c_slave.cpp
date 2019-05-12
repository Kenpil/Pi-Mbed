#include "mbed.h"
 
I2CSlave slave(D14, D15);
//I2CSlave slave(I2C1_SDA, I2C1_SCL);
 
unsigned char my_i2c_slave_address = 0x0a;
 
int main()
{
    char buf[10];
    char msg[] = "Slave!"; // 53 = S; 6C = l; 61 = a; 76 = v; 65 = e; 21 = !; 00 = end of string marker => read of 7 bytes by I2C master
    int counter=0;
 
    slave.address(my_i2c_slave_address);
    printf("Hello from I2CSlaveTest program for mbed.\r\n");
 
    while (1) {
        int i = slave.receive();
        switch (i) {
            case I2CSlave::ReadAddressed:
                printf("\r\nRead from I2C slave & sending local %02d byte string to I2C master %s",strlen(msg) + 1, msg);
                slave.write(msg, strlen(msg) + 1); // Includes null char
                break;
            case I2CSlave::WriteGeneral:
                slave.read(buf, 10);
                printf("\r\nRead from inside WRITE I2C routine... G: %s", buf);
                break;
            case I2CSlave::WriteAddressed:
                slave.read(buf, 10);
                printf("\r\n[%02d] Read A: %s", counter++,buf);
                break;
        }
        for(int i = 0; i < 10; i++) buf[i] = 0;    // Clear buffer
    } 
}
