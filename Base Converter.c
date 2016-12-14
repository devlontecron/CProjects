/*Devin Durham
TCSS 333
Prof Mayer
Spring 2016

An interactive program that reads and writes integers in decimal, binary, and hex.
The user is asked for what type of input or what type of output by key commands. The program runs till the user types “q” 
*/

#include <stdio.h>

int main(void){

char reading;
char inOrOut;
char type;
int oldValue = 0;
int readingValue = 0;
int typeFlag = 0;
int commaCount = 0;

printf("Commands: id, ib, ix, od, ob, ox\n>");

//reading the input

while (1){

  scanf("%c", &reading);

  if (reading == 'q'){
     printf("Good bye!\n");
     return 0;
  } else if(reading == 'i'){
     inOrOut = reading;
     typeFlag = 1;
     oldValue = 0;
  } else if(reading == 'o'){
       inOrOut = reading;
       typeFlag = 1;
       int commaCount = 3;

  } else if(typeFlag == 1 && reading == 'd' ||typeFlag == 1 && reading == 'b' || typeFlag == 1 && reading == 'x'){
     type = reading;
     typeFlag = 0;

  } else if(inOrOut == 'o'){
     if(type == 'x'){
        int Xpow = 1;
        int XValue = oldValue;
        int hex;
        int XpowNum = 0;
        int commaFlag = 0;

         while (XValue >= Xpow){
             Xpow = (Xpow*16);
             XpowNum++;
          }

          while (Xpow != 1){

             Xpow = Xpow /16 ;
             hex = XValue / Xpow;
             if (commaFlag == 1 && XpowNum%2 == 0){

                printf(",");
             }

             commaFlag = 1;
             XpowNum--;
             printf("%x", hex);
             XValue = XValue%Xpow;
          }
       } else if(type == 'd'){


          int Tpow = 1;
          int DValue = oldValue;
          int dec;
          int TpowNum = 0;

          while (DValue >= Tpow){
             Tpow = (Tpow*10);
             TpowNum++;
          }

          while (Tpow != 1){
             Tpow = Tpow /10 ;
             // printf("%d ", pow);
             dec = DValue / Tpow;
             if (TpowNum%3 == 0){
                printf(",");
             }
             TpowNum--;
             printf("%d", dec);
             DValue = DValue%Tpow;
             //printf("t");
          }
       } else if(type == 'b'){

          int pow = 1;
          int BValue = oldValue;
          int bin;
          int powNum = 0;
          int commaFlag = 0;

          while (BValue >= pow){
             pow = (pow*2);
             powNum++;
             // printf("%d", pow);
             // printf("%d", BValue);
          }

          while (pow != 1){

             pow = pow /2 ;
             // printf("%d ", pow);
             bin = BValue / pow;

             if (commaFlag == 1 && powNum%4 == 0){
                printf(",");
             }

             commaFlag = 1;
             powNum--;
             printf("%d", bin);
             BValue = BValue%pow;
             //printf("t");
          }
       }

       printf("\n>");

    } else if (reading == ' ' || reading == ',' ){
          //do nothing
       } else if( reading == '\n'){
          printf(">");

       } else if(inOrOut == 'i'){

           readingValue = reading - 48;
            if(type == 'x'){
               if (reading == 'a' || reading == 'b' || reading == 'c' || reading == 'd' || reading == 'e' || reading == 'f'){
                  readingValue = reading - 87;
               }
                oldValue = oldValue*16;
                oldValue = oldValue + readingValue;

                //oldValue = oldValue + readingValue;
             } else if(type == 'b'){
                 oldValue = oldValue*2;
                 oldValue = oldValue + readingValue;
                 // printf("%d", readingValue);
                 // printf ("%d", oldValue);
              } else if(type == 'd'){
                  oldValue = oldValue*10;
                  oldValue = oldValue + readingValue;
               }
            }
         }
      }
