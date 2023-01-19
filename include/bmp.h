#pragma once
#include <stdio.h>

struct BitmapInfoHeader {
  unsigned int headerSize;  // Default is 40; offset 0E
  unsigned int imageWidth;  // offset 12h
  unsigned int imageHeigth; // offset 16h
  unsigned short planes;    // offset 1Ah. Default is 1
  short bitsPerPixel;       // "Color Depth" Default is 1 // offset 1Ch
  unsigned int compression; // offset 1Eh
  // Value	Identified by	Compression method	Comments
  //	0	BI_RGB	none	Most common
  //	1	BI_RLE8	RLE 8 - bit / pixel	Can be used only with 8 - bit /
  // pixel bitmaps 	2	BI_RLE4	RLE 4 - bit / pixel	Can be used only
  // with
  // 4
  //- bit / pixel bitmaps 	3	BI_BITFIELDS	OS22XBITMAPHEADER :
  // Huffman 1D
  // BITMAPV2INFOHEADER : RGB bit field masks, 	BITMAPV3INFOHEADER + : RGBA 4
  // BI_JPEG	OS22XBITMAPHEADER : RLE - 24	BITMAPV4INFOHEADER + : JPEG
  // image for printing[14] 	5	BI_PNG		BITMAPV4INFOHEADER + :
  // PNG image for
  // printing[14] 	6	BI_ALPHABITFIELDS	RGBA bit field masks
  // only Windows CE 5.0 with.NET 4.0 or later 	11	BI_CMYK	none only
  // Windows Metafile CMYK[4] 	12	BI_CMYKRLE8	RLE - 8	only Windows
  // Metafile CMYK 	13 BI_CMYKRLE4	RLE - 4	only Windows Metafile CMYK

  unsigned int imageRawSize;         // maybe 0; offset 22h
  unsigned int horizontalResolution; // Pixel per metre // offset 26h
  unsigned int verticalResolution;   // Pixel per metre // offset 2Ah
  unsigned int
      colorPallete; // number color of pallet // default is 0 // offset 2Eh
  unsigned int importantColors; // ignore // 0 is default // offset 32h
};

struct BitmapFileHeader {
  unsigned char signature[2];   // offset 00
  unsigned int imageSize;       // offset 02
  short reserved1;              // offset 06
  short reserved2;              // offset 08
  unsigned int pixelDataOffset; // offset 0A
  struct BitmapInfoHeader BIHeader;
};

typedef struct BitmapFileHeader BFHeader;
typedef struct BitmapInfoHeader BIHeader;

void fillHeader(BFHeader *bf, FILE *fp);
