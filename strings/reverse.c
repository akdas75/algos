



#include <stdio.h>
#include <string.h>




int main (void) {

    char str[] = "Hello World";
    printf ("%lu \n",strlen (str));
    printf ("%lu \n",sizeof (str));
     printf ("%s \n",str);
    int i;
    char tmp;

    for (i=0; i<strlen(str)/2; i++){

        printf ("Swapping %c and %c\n",str[i],str [strlen(str)-1 - i]);

        tmp = str[i];

        str[i] = str [strlen(str)-1 - i];

        str [strlen(str)-1 - i] = tmp;
         
    }

    printf ("%s \n",str);
    
}