#include <qrcode_hub75.h>
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

/*--------------------- MATRIX LILBRARY CONFIG -------------------------*/
#define PANEL_RES_X 64      // Number of pixels wide of each INDIVIDUAL panel module. 
#define PANEL_RES_Y 32     // Number of pixels tall of each INDIVIDUAL panel module.
#define PANEL_CHAIN 1      // Total number of panels chained one to another

MatrixPanel_I2S_DMA *dma_display = nullptr;


void setup() {

    Serial.begin(115200);
    Serial.println("");
    Serial.println("Starting...");

    dma_display = new MatrixPanel_I2S_DMA(mxconfig);
    dma_display->begin();
    QRcode_HUB75 qrcode (dma_display);


    // enable debug qrcode
    // qrcode.debug();

    // Initialize QRcode display using library
    qrcode.init();
    // create qrcode
    qrcode.create("Hello world.");

}

void loop() { }