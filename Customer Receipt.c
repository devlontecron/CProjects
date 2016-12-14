/*Devin Durham
prof. Mayer
TCSS 333
Spring Quarter

reads in a file which collects and organizes data of customers order and outputs to another file.  
*/

#include <stdio.h>
#include <string.h>


struct item_tag {
   char itemName[30];
   int quant;
   float cost;
};
typedef struct item_tag Item;

struct customer_tag {
   char name[30];
   Item purch[10];
   int sizeOfPurch;
   float orderTotal;
};
typedef struct customer_tag Customer;


sortTotalOrder(Customer *CustArray, int NumbsOfCust){

      int r,g;
      Customer temp;

      for (r = 0; r < NumbsOfCust; r++) {
         for (g = 0; g < NumbsOfCust-1; g++) {
               if(CustArray[r].orderTotal > CustArray[g].orderTotal){
                  temp = CustArray[r];
                  CustArray[r] = CustArray[g];
                  CustArray[g] = temp;
               }
            }
      }
}

void sortItems(Customer *CustArray, int NumbsOfCust){

   int r,w,g;
   Customer temp;

   for (r = 0; r < NumbsOfCust; r++) {
         for(w =0; w< CustArray[r].sizeOfPurch; w++){
            for (g = 0; g < CustArray[r].sizeOfPurch-1; g++) {
            if((CustArray[r].purch[w].cost*CustArray[r].purch[w].quant) > (CustArray[r].purch[g].cost*CustArray[r].purch[g].quant)){
               temp.purch[0] = CustArray[r].purch[w];
               CustArray[r].purch[w] = CustArray[r].purch[g];
               CustArray[r].purch[g] = temp.purch[0];
            }
          }
          }
   }
}


void readInFile(Customer *CustArray){

   Customer c;
   Item i;

   c.sizeOfPurch = 0;
   char inName[30];
   char inProduct[50];
   float inCost;
   int r,w,s,foundFlag, inQuant;
   int NumbsOfCust = 0;

   FILE *inFile = fopen("hw4input.txt", "rb");
   if (inFile == NULL) {
      printf("File did not open.");
   }

   while (fscanf(inFile, "%s %d %s $%f", inName, &inQuant, inProduct, &inCost) != EOF) {
      foundFlag = 0;

      for (s = 0; s < NumbsOfCust && foundFlag ==0; s++) {

         if(strcmp( CustArray[s].name, inName)==0){

            i.quant = inQuant;
            strcpy(i.itemName, inProduct);
             i.cost = inCost;

            CustArray[s].purch[CustArray[s].sizeOfPurch] = i;
            CustArray[s].sizeOfPurch++;
            CustArray[s].orderTotal = CustArray[s].orderTotal + (inCost*inQuant);

            foundFlag = 1;
         }
      }

   if(foundFlag == 0){
      strcpy(c.name, inName);
      i.quant = inQuant;
      strcpy(i.itemName, inProduct);
      i.cost = inCost;

      c.sizeOfPurch = 0;
      c.purch[0] = i;
      c.sizeOfPurch++;
      c.orderTotal = inCost*inQuant;

      CustArray[NumbsOfCust] = c;
      NumbsOfCust++;
   }
 }

 outFileTime(CustArray, NumbsOfCust);
 sortItems(CustArray, NumbsOfCust);
 sortTotalOrder(CustArray, NumbsOfCust);
 outFileMoney(CustArray, NumbsOfCust);

}


outFileMoney(Customer *CustArray, int NumbsOfCust){

  FILE *outMoney = fopen("hw4money.txt", "wb");
   int r,w;
      for (r = 0; r < NumbsOfCust; r++) {
         fprintf(outMoney, "%s, Total Order = %.2f \n", CustArray[r].name, CustArray[r].orderTotal);

         for(w =0; w< CustArray[r].sizeOfPurch; w++){
            fprintf(outMoney,"%s %d $%.2f, Item Value = $%.2f \n",  CustArray[r].purch[w].itemName, CustArray[r].purch[w].quant, CustArray[r].purch[w].cost, (CustArray[r].purch[w].cost*CustArray[r].purch[w].quant));
         }
         fprintf(outMoney,"\n");
   }
}

outFileTime(Customer *CustArray, int NumbsOfCust){

FILE *outTime = fopen("hw4time.txt", "wb");

   int r,w;
   for (r = 0; r < NumbsOfCust; r++) {
      fprintf(outTime, "%s\n", CustArray[r].name);

      for(w =0; w< CustArray[r].sizeOfPurch; w++){
         fprintf(outTime,"%s %d $%.2f \n",  CustArray[r].purch[w].itemName, CustArray[r].purch[w].quant, CustArray[r].purch[w].cost);
      }
      fprintf(outTime,"\n");
   }
}

int main(void){

   Customer arrayCustomers [20];

   readInFile(arrayCustomers);

}



