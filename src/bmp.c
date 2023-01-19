#include "../include/bmp.h"

void fillHeader(BFHeader *bf, FILE *fp) {
    // BitmapFileHeader
    fread(&bf->signature, 2, 1, fp);
    fread(&bf->imageSize, 4, 1, fp);
    fread(&bf->reserved1, 2, 1, fp);
    fread(&bf->reserved2, 2, 1, fp);
    fread(&bf->pixelDataOffset, 4, 1, fp);

    // BitmapInfoHeader
    fread(&bf->BIHeader.headerSize, 4, 1, fp);
    fread(&bf->BIHeader.imageWidth, 4, 1, fp);
    fread(&bf->BIHeader.imageHeigth, 4, 1, fp);
    fread(&bf->BIHeader.planes, 2, 1, fp);
    fread(&bf->BIHeader.bitsPerPixel, 2, 1, fp);
    fread(&bf->BIHeader.compression, 4, 1, fp);
    fread(&bf->BIHeader.imageRawSize, 4, 1, fp);
    fread(&bf->BIHeader.horizontalResolution, 4, 1, fp);
    fread(&bf->BIHeader.verticalResolution, 4, 1, fp);
    fread(&bf->BIHeader.colorPallete, 4, 1, fp);
    fread(&bf->BIHeader.importantColors, 4, 1, fp); 
}

int selling(int x, int y) {
    return (x%y ? x/y + 1 : x/y);
}

int checkBit(unsigned char *ch, int posicao){
    __asm__("mov ebx,");
}