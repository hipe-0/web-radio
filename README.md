# web-radio
A practical standalone DIY open-source web radio with 200+ channels. Hours of music with (usually almost) no ads. Very kids friendly (kids love it).

https://github.com/user-attachments/assets/d1213b52-7903-45f3-94ce-77da26fb0ff1

# Features
* ESP32 powered (that microcontroller has an insane price/power ratio with low consumption)
* Connects to internet radio via your Wifi Box.
* Dead simple to use (Kids friendly)
* 200+ channels are preset
* Easy selection of channel with a big rotary button you can press to launch the radio.
* Useful 1.54" color LCD screen that displays song titles.
* Memorize the last channel after switch off.
* 3D Enclosure you can download (for free) and 3D print yourself (Mine is in PETG with 2 colored layers, but PLA should be fine too)
* Volume push buttons +/-
* On/Off switch
* Uses a single USB rechargeable Li/ion battery in 18650 form factor.
* Audio output: 3mm Audio jack, stereo, hifi 16 bit
* If a channel produces a rebooting, long press on encoder while rebooting will move to channel+1
* WPS: Easy wifi connexion in one click on your box 🛜
* Cheap (about 20 € of material, but in practice should be more around ~30-40 € as you need to buy some components in bulks of 5 or 10 and also add some delivery costs)
![20250423_133256](https://github.com/user-attachments/assets/5e40bebb-8538-4dca-8c5f-6f9722b295dc)
![20250423_142001](https://github.com/user-attachments/assets/7efc7cea-f6ce-4179-a4fb-7e65e717b717)
![20250423_142011](https://github.com/user-attachments/assets/dc3fa3d4-ba49-4a1a-8cfe-1480b464abc7)
![20250423_135808](https://github.com/user-attachments/assets/cccccfa2-b6de-47f9-b9ed-506dbe80634e)
![20250423_171448](https://github.com/user-attachments/assets/6f15123d-d04f-4b92-b701-cdd8711e52c7)

# Parts
* 1x ESP32 WROOM microcontroler Development Board ESP WROOM32 Module WIFI+Bluetooth IO (https://de.aliexpress.com/item/1005006449303342.html) ~4€
* 1x 'Audio kit' DAC PT8211 from PRJC I2S 16 bit 3.3v (https://www.pjrc.com/store/pt8211_kit.html) ~3$
* 1x Full color TFT Display module 240x240 LCD screen 3.3v RGB 1.54"x1.54" SDI-ST7789 (https://de.aliexpress.com/item/1005007465243480.html) ~3€
* 2x push button switches
* 1x on/off switch
* 1x Li-Ion Battery shield ESP32 18650 Battery Charge Shield Board V3 Micro USB Port Type-A USB 0.5A (https://de.aliexpress.com/item/1005001621882169.html?spm=a2g0o.order_list.order_list_main.308.1d491802ooXU1Q&gatewayAdapt=glo2deu) ~2€
* 1x Li-Ion Battery 3.7V 18650 12000mAh Rechargeable (https://de.aliexpress.com/item/1005001659406681.html?spm=a2g0o.order_list.order_list_main.61.1d491802ooXU1Q&gatewayAdapt=glo2deu) ~0.5€
* Wires
* 2x Solder board
* 1x Soldering iron
* 1x 360° Rotary encoder with press switch (https://de.aliexpress.com/item/1005004907970664.html?spm=a2g0o.order_list.order_list_main.438.1d491802ooXU1Q&gatewayAdapt=glo2deu) ~0.5€
* 2x 10K resistors (for signal pull-up)
* 1x 3D printed enclosure in PETG with it's cover (https://www.thingiverse.com/thing:7199885) <2€ in material cost

# Code
Upload the code with VS Code with the platformio add-in.

# 3D Models
Download my own design here on thigiverse:
* https://www.thingiverse.com/thing:7199885
<img width="465" height="530" alt="2025-11-13 22_55_09-_Untitled - PrusaSlicer-2 9 2 based on Slic3r" src="https://github.com/user-attachments/assets/ad068ad3-7e61-4550-8be6-9671afff4945" />


# Shematics - Prototype board
Here is the fritzing view of how I suggest to assemble and weld with prototype board.
<img width="1115" height="697" alt="2025-11-15 17_00_17-2025-11-15 Internet Radio fzz - Fritzing -  Vue de la platine d&#39;essai" src="https://github.com/user-attachments/assets/5dce1f41-d035-40fb-b343-235fa4009cdc" />

# Notes and Shematics
You may find useful the added details and shematics in my original notes: Hoping you can read my scribbles below. Is quite straightforward once you get into it. 😊
<img width="1352" height="1803" alt="image" src="https://github.com/user-attachments/assets/3b130be8-d138-4187-9676-78544ee04c63" />

# Ideas for the future
Desiging a printed Circuit board would make the assembly so much easier. --> I'll maybe do this later.
