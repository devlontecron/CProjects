#include "mallok.h"
#include <stdlib.h>
#include <stdio.h>

struct node{
   void *location;
   int size;
   int isAvail;
   struct node *next;
};
typedef struct node Node;

void *front = NULL;


void create_pool(int Psize){
  void *privateheap = malloc(Psize);
   Node *b = (Node *)malloc( sizeof(Node) );

   b->size = Psize;
   b->location = privateheap;
   b->isAvail = 1;
   b->next = NULL;

   front = b;

}


void *my_malloc(int Msize){

      Node * curr = (Node *)malloc( sizeof(Node) );
      curr = front;
      while (curr != NULL && (curr->isAvail ==0 || curr->size < Msize)) {

          curr = curr->next;
      }
      if (curr != NULL) {

          Node *newNode = (Node *)malloc( sizeof(Node) );

          newNode->size = curr->size - Msize;
          newNode->location = curr->location+Msize;


          newNode->isAvail = 1;
          newNode->next = curr->next;

          curr->size = Msize;
          curr->isAvail = 0;
          curr->next = newNode;

         return curr->location;

      } else if(curr == NULL){
         printf("ERROR: my_malloc FAILED; Could not allocate requested size of %d\n", Msize);
         return NULL;
      }

}


//detailed printing function for the heap
void printMyHeap(){

   Node *curr = front;
   int i;
   printf("Location  Size Available(1=yes)\n");
   while(curr != NULL){
      printf("%d %d %d \n", curr->location, curr->size, curr->isAvail);
      curr = curr->next;
   }
   printf("------------------------------\n");
}



void my_free(void *block){
      Node * curre = (Node *)malloc( sizeof(Node));
      Node * prev = (Node *)malloc( sizeof(Node));
      curre = front;

       while (curre != NULL && curre->location != block) {
           prev = curre;
           curre = curre->next;
        }
        if(curre != NULL){
           curre->isAvail = 1;

           if(curre->next->isAvail == 1){
             curre->size = curre->size + curre->next->size;

              curre->next->location = curre->location;
              if(curre->next->next == NULL){
                 curre->next = NULL;
              }else{
              curre->next = curre->next->next;
              }
           }

            if(prev->isAvail == 1){
               prev->size = prev->size + curre->size;
               curre->location = prev->location;
               prev->next = curre->next;

           }

        }else{
           printf("ERROR: my_free FAILED; Could not free requested memory\n");
        }
}




