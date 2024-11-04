#ifndef ESPQRCODEHUB75_H
#define ESPQRCODEHUB75_H

#define HUB75

#include "qrcodedisplay.h"
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

#define HUB75

class QRcode_HUB75 : public QRcodeDisplay
{
	private:
        MatrixPanel_I2S_DMA *display;
        void drawPixel(int x, int y, int color);
	public:
		QRcode_HUB75(MatrixPanel_I2S_DMA *display);

		void init();
        void init(int width, int height);
		void screenwhite();
		void screenupdate();
};

#endif