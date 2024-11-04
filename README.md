# QRcodeHUB75

Subclass that you can use jointly with https://github.com/yoprogramo/QRcodeDisplay to generate QRcodes in HUB75 panels.

To use it:

## In platform.io: 

add as dependencies:

```
yoprogramo/QRcodeDisplay
yoprogramo/QRcode-hub75
adafruit/Adafruit GFX Library
mrfaptastic/ESP32 HUB75 LED MATRIX PANEL DMA Display
```

## In arduino ide:
open Library Manager (menu Sketch > Include Library > Manage Libraries…) then install the following libraries:

```
 QRcodeDisplay
 yoprogramo/QRcode-hub75
 Adafruit GFX Library
 ESP32 HUB75 LED MATRIX PANEL DMA Display
```

 Creating a QRcode is just as simple as:

 ```
#include <qrcode_hub75.h>
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

#define PANEL_RES_X 64      // Number of pixels wide of each INDIVIDUAL panel module. 
#define PANEL_RES_Y 32     // Number of pixels tall of each INDIVIDUAL panel module.
#define PANEL_CHAIN 1      // Total number of panels chained one to another

MatrixPanel_I2S_DMA *dma_display = nullptr;

void setup() {

    HUB75_I2S_CFG mxconfig(
    PANEL_RES_X,   // module width
    PANEL_RES_Y,   // module height
    PANEL_CHAIN    // Chain length
    );

    dma_display = new MatrixPanel_I2S_DMA(mxconfig);
    dma_display->begin();
    QRcode_HUB75 qrcode (dma_display);

    qrcode.init();
    qrcode.create("Hello world.");

}

 ```

 For other displays, please refer the main repository: https://github.com/yoprogramo/QRcodeDisplay
