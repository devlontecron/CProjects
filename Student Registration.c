
#include <stdio.h>
#include <string.h>
#include "aidb.h"

int main(void){

   char reading[100];

   printf("Enter file name: ");

   scanf("%s", &reading);

   FILE *infile = fopen(reading, "rb");
   char Harr[16];
   Course *course;
   Student *stud;
   Enroll *enr;
   char *str;
   int x,z,numOfStuds, numOfCourses, numOfEnrol;
   int hasCourses = 0;
   int hasEnrollment = 0;

   fread(Harr, sizeof(char) ,16 , infile);

   AIDB_FileHeader *MainHeader = (AIDB_FileHeader *)&Harr[0];

//sectionHeader

   char arr[MainHeader[0].file_size+1];

   fread(arr , sizeof(char), (MainHeader[0].file_size),infile);

   SectionHeader *headers = (SectionHeader *)&arr[MainHeader[0].section_table_offset-16];

//Making pointers to each section;


   for(x=0; x<MainHeader[0].section_count; x++){

      if(headers[x].type == 0){
        stud = (Student *)&arr[headers[x].offset-16];
         numOfStuds = headers[x].num_entries;

     }else if (headers[x].type == 1){
        course = (Course *)&arr[headers[x].offset-16];
        numOfCourses = headers[x].num_entries;
        hasCourses = 1;

     }else if (headers[x].type == 2){
        enr = (Enroll *)&arr[headers[x].offset-16];
        numOfEnrol = headers[x].num_entries;
        hasEnrollment = 1;

     } else if (headers[x].type == 3){
        str = (char *)&arr[headers[x].offset-16];
     }
  }

   printf("\nAIDB Tables\n\nStudents\n");

   char tempName[80];
//Printing out names and majors
   for(z = 0; z<numOfStuds; z++){
    printf("%.4d   ", stud[z].id_num);

      x=0;
      while(str[stud[z].name + x] != '\0'){
         tempName[x] = str[stud[z].name + x];
         x++;
      }
      tempName[x] = str[stud[z].name + x];

      printf("%-30s", tempName);

      if(stud[z].major == 0){
         printf("CS");
      }else if(stud[z].major == 1){
         printf("CE");
      }else if(stud[z].major == 2){
         printf("MATH");
      }else if(stud[z].major == 3){
         printf("SOC WORK");
      }else if(stud[z].major == 4){
         printf("NURSING");
      }
    printf("\n");
   }

   printf("\n");

//print courses
char tempCourse[100];
   if(hasCourses == 1){
      printf("Courses\n");


   for(z = 0; z<numOfCourses; z++){

      x=0;
      while(str[course[z].name + x] != '\0'){
         tempCourse[x] = str[course[z].name + x];
         x++;
      }

   tempCourse[x] = str[course[z].name + x];
   printf("%-30s", tempCourse);
   printf("%d", course[z].max_enroll);
   printf("\n");

   }

    printf("\n");
}

//printing Enrollments

   if(hasEnrollment ==1){
      printf("Enrollments\n");


   for(z = 0; z<numOfEnrol; z++){

       x=0;
       while(str[stud[enr[z].student].name + x] != '\0'){
          tempName[x] = str[stud[enr[z].student].name + x];
          x++;
       }
       tempName[x] = str[stud[enr[z].student].name + x];

       printf("%-30s", tempName);

       x=0;
       while(str[course[enr[z].course].name + x] != '\0'){
         tempCourse[x] = str[course[enr[z].course].name + x];
         x++;
       }

       tempCourse[x] = str[course[enr[z].course].name + x];

       printf("%s\n", tempCourse);
    }


}

return 0;
}





