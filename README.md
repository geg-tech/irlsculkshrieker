# IRL Sculk Shrieker

This is a recreation of the [***sculk shrieker***](https://minecraft.wiki/w/Sculk_Shrieker) from the game Minecraft, made for Highway!

![warden](https://github.com/user-attachments/assets/7622232f-a346-405a-a716-3ee246f41c43)

This block will ~~summon a warden at your exact location~~ shriek whenever it hears a sound nearby through a speaker embedded inside the top of the shrieker. Perfect for alarming anyone sneaking past you and inflicting [*severe ancient city flashbacks*](https://github.com/geg-tech/irlsculkshrieker/blob/main/extras/flashbacks.png) onto friends!


I made this project as my last Highway submission, and wanted to end off with something that *wasn't* another keyboard. I saw the Minecraft submissions by [@aaron huang and his compass](https://hackclub.slack.com/archives/C08S22XRYMU/p1750910065012999) and by [@danieliscrazy and his jukebox](https://github.com/danieliscrazy/Jukebox), and was inspired to make my own Minecraft-related project, which soon grew into this sculk shrieker. <br/>

I aimed to be as *game-accurate* as possible while also putting my own spin on the design, using the textures as reference when detailing and modeling the case and incorporating little features and details into the final result, such as the animated textures on the top of the block. Every pixel on the texture translates to 4mm on the model, making the entire shrieker have a tiny footprint of *64mm x 64mm! wow!* 

## CAD
![render](https://github.com/user-attachments/assets/03bc3b60-870e-49e0-86c0-b32caa13e6a9)
![exploded](https://github.com/user-attachments/assets/f3ac3d42-9f9e-43f1-97a5-91e1ae53b135)
![cad](https://github.com/user-attachments/assets/41ab5e7d-d8e7-4f83-b798-e49194341a6b)
![internals](https://github.com/user-attachments/assets/eeb6a0d8-e6a1-4d16-ad16-5abc13fc2f00)

## PCB + Wiring Diagram
### Wiring Diagram
<img width="1324" alt="image" src="https://github.com/user-attachments/assets/5bc043fc-0dc9-4a16-b020-adb0fd94abf9" /> <br/>
### PCB
<img width="648" alt="image" src="https://github.com/user-attachments/assets/852f5acb-28bc-438d-9208-44b61863ac1c" /> <br/>
<img width="685" alt="image" src="https://github.com/user-attachments/assets/1d0b2ba1-9654-4076-8747-a0aa94b506d0" /> <br/>
<img width="688" alt="image" src="https://github.com/user-attachments/assets/c998b319-6ba1-40f9-bb9d-02456819012e" /> <br/>

## BOM

|Name|Quantity|Price|Source|Purpose|Link|
|---|---|---|---|---|---|
|Adafruit Micro SD SPI/SDIO Breakout Board|1        |$3.50 |Adafruit  |Hosts MP3 files to play via the speaker                |https://www.adafruit.com/product/4682|
|SK6812RGBW LEDs                          |20       |$11.90|Adafruit  |Adds animated lighting to the top                      |https://www.adafruit.com/product/2762                                                                                                                                                                                                                                             |
|4 Ohm 3 Watt Speaker                     |1        |$2.95 |Aliexpress|Outputs amplified data from amp as audio               |https://www.aliexpress.us/item/3256805513376202.html?spm=a2g0o.detail.0.0.e91d8P9I8P9IvQ&mp=1&pdp_npi=5%40dis%21USD%21USD%202.95%21USD%202.81%21%21USD%202.81%21%21%21%402101ef7017517659888774051ebce8%2112000037280015644%21ct%21US%216388337753%21%211%210&gatewayAdapt=glo2usa|
|KY-037 Sound Sensor                      |1        |$1.04 |Aliexpress|Detects whenever a sound is over a threshold           |https://www.aliexpress.us/item/3256807347494500.html?spm=a2g0o.detail.0.0.542aLwRHLwRHNI&mp=1&pdp_npi=5%40dis%21USD%21USD%202.92%21USD%202.92%21%21USD%202.92%21%21%21%402103244617517664615985016e6b67%2112000041188403861%21ct%21US%216388337753%21%211%210&gatewayAdapt=glo2usa|
|ESP32                                    |1        |$3.98 |Aliexpress|Controls all modules/PCB, triggers MP3                 |https://www.aliexpress.us/item/3256807453968983.html?spm=a2g0o.detail.0.0.4443wfd1wfd1Kn&mp=1&pdp_npi=5%40dis%21USD%21USD%203.98%21USD%203.64%21%21USD%203.64%21%21%21%402103246617517664681434438e1056%2112000041608696464%21ct%21US%216388337753%21%211%210&gatewayAdapt=glo2usa|
|MAX98357A Speaker Amp                    |1        |$1.66 |Aliexpress|Amplifies MP3 data to signals usable by speaker        |https://www.aliexpress.us/item/3256806882501015.html?spm=a2g0o.detail.0.0.7a781pAH1pAHw5&mp=1&pdp_npi=5%40dis%21USD%21USD%201.84%21USD%201.80%21%21USD%201.80%21%21%21%402103277f17517664746265268e3da2%2112000039302356100%21ct%21US%216388337753%21%211%210&gatewayAdapt=glo2usa|
|PCB                                      |1        |$2.00 |JLCPCB    |Holds and wires RGBW lights                            |                                                                                                                                                                                                                                                                                  |
|Case (all parts)                         |1        |$0.00 |Owned     |Contains all parts, looks pretty                       |                                                                                                                                                                                                                                                                                  |
|M2 Screws (4x 16mm, 2x 10mm)             |6        |$0.00 |Owned     |Holds together the case shells and attaches speaker    |                                                                                                                                                                                                                                                                                  |
|Paint                                    |1        |$0.00 |Owned     |Makes case look prettier                               |                                                                                                                                                                                                                                                                                  |
|Cable                                    |1        |$0.00 |Owned     |Communicates between ESP32 and comupter, provides power|                                                                                                                                                                                                                                                                                  |
|Soldering Iron + Solder Wire + Flux      |1        |$0.00 |Owned     |Secures wires between modules/components               |                                                                                                                                                                                                                                                                                  |
|Solid Core Wire                          |1        |$0.00 |Owned     |Connects components together                           |                                                                                                                                                                                                                                                                                  |
|Hot Glue                                 |1        |$0.00 |Owned     |Secures loose components to the case                   |                                                                                                                                                                                                                                                                                  |
|                                         |         |      |          |                                                       |                                                                                                                                                                                                                                                                                  |
|                                         |Subtotal:|$27.03|          |Aliexpress: $12.35                                     |                                                                                                                                                                                                                                                                                  |
|                                         |Total:   |$42.66|          |JLCPCB: $8.12                                          |                                                                                                                                                                                                                                                                                  |
|                                         |         |      |          |Adafruit: $21.19                                       |                                                                                                                                                                                                                                                                                  |
