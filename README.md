# web-radio
A practical standalone open-source web radio with 200+ channels, hours of music with (usually almost) no ads. Kids friendly. Working on a simple ESP32 with a DAC and connecting to your Wifi box in one push on the WPS button.

https://github.com/user-attachments/assets/d1213b52-7903-45f3-94ce-77da26fb0ff1

# Features
* ESP32 powered
* Connects to Wifi for internet radio
* Kids friendly
* 200+ channels are preset
* Easy selection of channel with infinite rotation rotary encoder
* Useful 1.54" color LCD screen
* Memorize the last channel
* 3D printed enclosure
* +/- volume button
* On/Off switch
* Uses rechargeable Li/ion battery 3.7v
* Audio output: 3mm Audio jack, stereo, hifi 16 bit
* If a channel produces a rebooting, long press on encoder while rebooting will move to channel+1
* WPS: easy connexion in one click on most wifi box
![20250423_133256](https://github.com/user-attachments/assets/5e40bebb-8538-4dca-8c5f-6f9722b295dc)
![20250423_142001](https://github.com/user-attachments/assets/7efc7cea-f6ce-4179-a4fb-7e65e717b717)
![20250423_142011](https://github.com/user-attachments/assets/dc3fa3d4-ba49-4a1a-8cfe-1480b464abc7)
![20250423_135808](https://github.com/user-attachments/assets/cccccfa2-b6de-47f9-b9ed-506dbe80634e)
![20250423_171448](https://github.com/user-attachments/assets/6f15123d-d04f-4b92-b701-cdd8711e52c7)

# Parts
* 1x ESP32 WROOM microcontroler (Development Board ESP WROOM32 Module WIFI+Bluetooth IO)
* 1x 'Audio kit' DAC PT8211 from PRJC I2S 16 bit 3.3v (https://www.pjrc.com/store/pt8211_kit.html)
* 1x Full color TFT Display module 240x240 LCD screen 3.3v RGB 1.54"x1.54" SDI-ST7789 ()
* 2x push button switches
* 1x on/off switch
* 1x Li-Ion Battery shield ESP32 18650 Battery Charge Shield Board V3 Micro USB Port Type-A USB 0.5A (https://de.aliexpress.com/item/1005001621882169.html?spm=a2g0o.order_list.order_list_main.308.1d491802ooXU1Q&gatewayAdapt=glo2deu)
* 1x Li-Ion Battery 3.7V 18650 12000mAh Rechargeable (https://de.aliexpress.com/item/1005001659406681.html?spm=a2g0o.order_list.order_list_main.61.1d491802ooXU1Q&gatewayAdapt=glo2deu)
* Wires
* 2x Solder board
* 1x Soldering iron
* 1x 360° Rotary encoder with press switch (https://de.aliexpress.com/item/1005004907970664.html?spm=a2g0o.order_list.order_list_main.438.1d491802ooXU1Q&gatewayAdapt=glo2deu)
* 2x 10K resistors (for signal pull-up)
* 1x 3D printed enclosure in PETG with it's cover (https://www.thingiverse.com/thing:7199885)

# Code
Upload the code with VS Code with the platformio add-in.

# 3D Models
Download my own design here on thigiverse:
* https://www.thingiverse.com/thing:7199885

# Shematics
Here is the fritzing view of how I suggest to assemble and weld with prototype board.
<img width="1115" height="697" alt="2025-11-15 17_00_17-2025-11-15 Internet Radio fzz - Fritzing -  Vue de la platine d&#39;essai" src="https://github.com/user-attachments/assets/5dce1f41-d035-40fb-b343-235fa4009cdc" />

More detail here: Hoping you can read my original scribbles below. Is quite straightforward once you get into it. 😊
<img width="1352" height="1803" alt="image" src="https://github.com/user-attachments/assets/3b130be8-d138-4187-9676-78544ee04c63" />

