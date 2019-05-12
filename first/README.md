# Pi-Mbed

なんか sudo vi /etc/modules に
i2c-bcm2835
i2c-dev
を書くと機能。i2cdetectすると、アドレス表示
masterの、bufferにそのアドレスを書き込むと通信できた
seti2cslave()みたいな方でないから、注意！
