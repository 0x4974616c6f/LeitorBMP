#include "../include/bmp.h"
#include <stdio.h>
#include <stdlib.h>

BFHeader bf;


int main(int argc, char *argv[]) {
	FILE *fp;
  	char arg[] = "C:\\Users\\italo\\Desktop\\1.bmp";
    int larguraTotal = 0;
    int bytesPerRaw = 0;
    int y, x;
    unsigned int byteAtual = 0;
    int count = 0;

    if (argc < 2) {
        fp = fopen(arg, "rb");
    }  
    else {
        fp = fopen(argv[1], "rb");
    } 	
	if (!fp) {
		printf("Not open image");
		return (0);
	}

	fillHeader(&bf, fp);

	// printf("%c%cX\n", bf.signature[0], bf.signature[1]);
	// printf("%dX\n", bf.imageSize);
	// printf("%hdX\n", bf.reserved1);
	// printf("%hdX\n", bf.reserved2);
	// printf("%dX\n", bf.pixelDataOffset);

	if (bf.BIHeader.bitsPerPixel != 1){
        printf("Only image monocromatics\n");
        fclose(fp);
        return(0);
    }

    larguraTotal = bf.BIHeader.imageWidth * bf.BIHeader.bitsPerPixel;
    bytesPerRaw = selling(larguraTotal, 32) * 4;

    fseek(fp, bf.pixelDataOffset, SEEK_SET);

    for (y = 0; y < bf.BIHeader.imageHeigth; y++) {
        for (x = 0; x < bytesPerRaw; x++) {
            fread(&byteAtual, 1, 1, fp);
            for(count = 0; count < 8; count++){
                printf("%d", checkBit(&byteAtual, count));
            }
        }
    }

	return (0);
}
