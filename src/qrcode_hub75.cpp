#include <Arduino.h>
#include "qrencode.h"
#include "qrcode_hub75.h"

// Implements functions for HUB75 panels

QRcode_HUB75::QRcode_HUB75(MatrixPanel_I2S_DMA *display) {
    
    this->display = display;
}

void QRcode_HUB75::init(int width, int height) {
    this->screenwidth = width;
    this->screenheight = height;
    display->fillScreen(display->color565(255, 255, 255));
    int min = screenwidth;
    if (screenheight<screenwidth)
        min = screenheight;
    multiply = min/WD;
    offsetsX = (screenwidth-(WD*multiply))/2;
    offsetsY = (screenheight-(WD*multiply))/2;
}

void QRcode_HUB75::init() {
    this->init(display->width(), display->height());
}

void QRcode_HUB75::screenwhite() {
    display->fillScreen(display->color565(255, 255, 255));
}

void QRcode_HUB75::screenupdate() {
    //No update for HUB75
}

void QRcode_HUB75::drawPixel(int x, int y, int color) {
    if(color==1) {
        color = display->color565(0, 0, 0);//BLACK
    } else {
        color = display->color565(255, 255, 255);//WHITE
    }
    display->drawPixel(x, y, color);
}