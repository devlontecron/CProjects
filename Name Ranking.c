/*Devin Durham
TCSS 333
Prof Mayer
Spring 2016

Receives an in file of most common names and outputs an .xlc file that organizes and ranks most common names over multiple input files 


*/

#include <stdio.h>
#include <string.h>



void printing(FILE *outfile, char *name, int Rank, int year){




 fprintf(outfile, "%s,", name, Rank);

  for(int y = 0; y<year; y++){
      fprintf(outfile, ",");
   }


    fprintf(outfile, "%d\n", Rank);



}


void Rank(FILE *outfile, char *name, int theYear, int theRankNum, char theFinalArray[][50], int nameCount){

//printf("%d = %s      %d\n", theRankNum, name, nameCount);
/*
int Flag = 0;
int u = 0;



while(*theFinalArray[u] != 1 && Flag ==0){
   if(strcmp( theFinalArray[u], name)){
      Flag=1;
   }else{
      u++;
}
}

if(Flag == 0){
   strcpy(theFinalArray[u], name);
}

*/

printing(outfile, name, theRankNum, theYear);

//printf(*theFinalArray);
//printf(",");
//printf("%d",theRankNum);



}


int reading(FILE *theFile, FILE *outFile, int theYearFile, char theFinalArray[][50], int nameCount){

   char names[100][80];

   int r = 0;
   int c = 0;
   int e = 0;
   char temp[80];

        int i,j;
        for(i = 0; i<1000; i++){
            for(j = 0; j<50; j++){
                     theFinalArray[i][j]=0;
            }
         }



   while (r<100){
        fgets(temp,80,theFile);

        for(e = 0; e<80 && temp[e] != ',' ; e++){
           temp[e];
         }
         temp[e] = '\0';


         int rankNum = r+1;
         Rank(outFile,temp, theYearFile, rankNum, theFinalArray, nameCount);

         r++;
      }
}




void Openfiles(){

   FILE *filesArray[10];

   filesArray[0] =  fopen("yob1920.txt", "rb");
   filesArray[1] =  fopen("yob1930.txt", "rb");
   filesArray[2] =  fopen("yob1940.txt", "rb");
   filesArray[3] =  fopen("yob1950.txt", "rb");
   filesArray[4] =  fopen("yob1960.txt", "rb");
   filesArray[5] =  fopen("yob1970.txt", "rb");
   filesArray[6] =  fopen("yob1980.txt", "rb");
   filesArray[7] =  fopen("yob1990.txt", "rb");
   filesArray[8] =  fopen("yob2000.txt", "rb");
   filesArray[9] =  fopen("yob2010.txt", "rb");
   filesArray[10]=  fopen("summary.csv", "wb");




   fprintf(filesArray[10], "Name,1920,1930,1940,1950,1960,1970,1980,1990,2000,2010,\n");

   char finalArray[1000][50];

   int nameCount = 0;

   for(int y = 0; y<10; y++){





     reading(filesArray[y], filesArray[10],y, finalArray, nameCount);
  }


}

/*

int sort(void){
   //re order the list

   for( int p = 0; p < 100; p++){
      for (int i = 0; i+1 < 100; i++){
         if (strcmp( states[i], states[i+1])>0){
            char temp[30];
            strcpy(temp, states[i]);
            strcpy(states[i+1], states[i]);
            strcpy(states[i+1], temp);
         }
      }
   }
   //printing();

}


*/

int main(void) {

   Openfiles();

   //sort();

}


