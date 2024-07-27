#include <stdio.h>

typedef struct _movie
{
   char movie_name[11];
   double box_office;
   short year;
}Movie;

int main(){
    Movie mv1 = {"spiderman",999.79,2017};//ตัวแปร mv1 ประเภท Movie
    printf("%s\n%.2lf\n%d", mv1.movie_name,mv1.box_office,mv1.year);
}
//ศิริสุข ทานธรรม 6610402230