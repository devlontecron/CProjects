#include <stdio.h>
int j, signBool;
unsigned int i, masky;
unsigned long isoBit;
float myTotal;

void toBits(int i){
   printf("Your float in 32 bits: ");
   for (j = 0; j < 32; j++) {
      isoBit = i & masky;
      isoBit = isoBit >> 31;
      printf("%c", '0' +  isoBit );
      i = i << 1;
   }
   printf("\n");
}

void bitInfo(int z){
   printf("Sign: ");
   isoBit = z & masky;
   isoBit = isoBit >> 31;
   printf("%c", '0' +  isoBit );
   if(isoBit == 1){
      signBool = 1;
   }
   z = z<<1;

   printf("\nExponent: ");
   for (j = 0; j < 8; j++) {
      isoBit = z & masky;
      isoBit = isoBit >> 31;
      printf("%c", '0' +  isoBit );
      z = z<<1;
   }

   printf("\nFraction: ");
   for (j = 0; j < 23; j++) {
      isoBit = z & masky;
      isoBit = isoBit >> 31;
      printf("%c", '0' +  isoBit );
      z = z<<1;
   }
   printf("\n");
}

float fraction(int k){
   float total = 1.000000;
   float frac = 1.00000;
   printf("\nCreating the Fraction: \nfraction = %f (the implicit 1)\n", total);
   k = k<<9;
   for (j = 0; j < 23; j++) {
      frac = frac/2;
      isoBit = k & masky;
      isoBit = isoBit >> 31;
      if(isoBit == 1){
         total = total+frac;
         printf("fraction = %f, after adding %f\n", total, frac);
      } else{
         printf("fraction = %f, after skipping %f\n", total, frac);
      }
      k = k<<1;
   }
   printf("\n");
   return total;
}

float exponent(int e, float totall){
   e=e<<1;
   int binMath = 128;
   int expo = 0;
   for (j = 0; j < 8; j++) {
      isoBit = e & masky;
      isoBit = isoBit >> 31;
      if(isoBit == 1){
         expo = expo+binMath;
      }
      binMath = binMath/2;
      e = e<<1;
   }
   expo = expo-127;
   printf("Applying the exponent: \nunbiased exponent = %d\n", expo);
   if(expo>0){
      for (j = 0; j < expo; j++) {
         totall = totall*2;
         printf("times 2 = %f\n", totall);
      }
   }else{
      for (j = 0; j > expo; j--) {
         totall = totall/2;
         printf("divided by 2 = %f\n", totall);
      }}
   return totall;
}

int main (void){
   float reading;
   printf("\nEnter a float: ");
   scanf("%f", &reading);
   printf("Your float was read as: %f\n", reading);

   int *ptr = (int*)&reading;
   i=*ptr;
   long var = 0x80000000;
   int *maskPtr = (int*)&var;
   masky = *maskPtr;

   toBits(i);
   bitInfo(i);
   myTotal = fraction(i);
   myTotal = exponent(i, myTotal);

   if(signBool == 1){
      printf("\nFinal Answer: -%f\n", myTotal);
   } else{
      printf("\nFinal Answer: %f\n", myTotal);
   }
}


