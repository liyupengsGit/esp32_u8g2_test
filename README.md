# esp32_u8g2_test
Test using u8g2 by Olikraus and the HAL provided by nKolban using Heltec wifi_kit_32

Just copy the u8g2 folder (download at olikraus gitpage) to your esp-idf/components folder, rename it to "u8g2_esp32_hal" and merge the folder found here to include the hal files and component mk to your u8g2 folder and then include the "u8g2_esp32_hal.h" in the header of your code to use the u8g2 libraby.

# Further instructions

Instructions on how to setup the HAL and use the library could be found at:

https://github.com/nkolban/esp32-snippets/tree/master/hardware/displays/U8G2

https://github.com/olikraus/u8g2/wiki/u8g2setupc

http://www.lucadentella.it/en/2017/10/30/esp32-25-display-oled-con-u8g2/

i did nothing to the original files, just provided an easy way to copy the files and use it right away, because i was facing a lot of problems when trying to run the codes with this library+hal, so maybe it helps someone. 
