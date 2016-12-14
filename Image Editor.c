/*Devin Durham
TCSS 333
Prof Mayer
Spring 2016

Reads in an image from file and manipulates each pixel to output a mirror image and an image repeated four times. 
*/

#include <stdio.h>

int main(void) {

    FILE *infile = fopen("test3.bmp", "rb");
    FILE *outfileQ = fopen("quad.bmp", "wb");
    FILE *outfileR = fopen("reflect.bmp", "wb");

    char headerJunk[2];
    int fileSize;
    int w;
    int h;
    char moreJunk[28];
    char junk[12];
    int newfileSize;


    fread(headerJunk, sizeof(char), 2, infile);
    fread(&fileSize, sizeof(char), 4 , infile);
    fread(junk, sizeof(char), 12 , infile);
    fread(&w , sizeof(char), 4,infile);
    fread(&h, sizeof(char),4,infile);
    fread(moreJunk, sizeof(char), 28, infile);



   unsigned char data[h][w][3];

   unsigned char newQImage[h*2][w*2][3];

   unsigned char newRImage[h][(w*2)][3];



       fread(data,sizeof(char) ,fileSize-54,infile);

         int r;
         int col;
       for (r = 0 ; r < h; r++) {
          int c;
          for (c = 0; c < (w); c++) {
             if(col<3){
                col = 0;
             }

             for(col = 0; col < 3; col++){



             char temp = data[r][c][col];


             newQImage[r][c][col] = temp;
             newQImage[h+r][c][col] = temp;
             newQImage[h+r][(w)+c][col] = temp;
             newQImage[r][c-1+w][col] = temp;



             newRImage[r][c][col] = temp;
             newRImage[r][(w*2-1)-c][col] =temp;

         }
    }
 }


       int newQuadFileSize = (fileSize-54)*4;
       int Qw= w*2;
       int Qh = h*2;

       int newRefFileSize = (fileSize-54)*2;
       int Rw = w*2;
       int Rh = h;



    fwrite(headerJunk, sizeof(char), 2, outfileQ);
    fwrite(&newQuadFileSize, sizeof(char), 4 , outfileQ);
    fwrite(junk, sizeof(char), 12 , outfileQ);
    fwrite(&Qw , sizeof(char), 4,outfileQ);
    fwrite(&Qh, sizeof(char),4,outfileQ);
    fwrite(moreJunk, sizeof(char), 28, outfileQ);

    fwrite(newQImage,sizeof(char) , newQuadFileSize,outfileQ);


    fwrite(headerJunk, sizeof(char), 2, outfileR);
    fwrite(&newRefFileSize, sizeof(char), 4 , outfileR);
    fwrite(junk, sizeof(char), 12 , outfileR);
    fwrite(&Rw , sizeof(char), 4, outfileR);
    fwrite(&Rh, sizeof(char),4, outfileR);
    fwrite(moreJunk, sizeof(char), 28, outfileR);

    fwrite(newRImage,sizeof(char) , newRefFileSize,outfileR);

    return 0;

}
