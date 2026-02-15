/* 
   PROCview - Group Assignment 3
   This program runs two Linux commands:
   1) ps aux
   2) ps -eLf

   It stores their outputs in files and then merges them
   into one file called merged.txt and prints it.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f1, *f2, *f3;
    char buffer[1000];

    /* Run Linux commands and store output */
    system("ps aux > x1.txt");
    system("ps -eLf > x2.txt");

    /* Open files */
    f1 = fopen("x1.txt", "r");
    f2 = fopen("x2.txt", "r");
    f3 = fopen("merged.txt", "w");

    if (f1 == NULL || f2 == NULL || f3 == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    fprintf(f3, "=========== PROCview Output ===========\n\n");

    fprintf(f3, "----- ps aux -----\n");
    while (fgets(buffer, sizeof(buffer), f1) != NULL)
    {
        fprintf(f3, "%s", buffer);
    }

    fprintf(f3, "\n----- ps -eLf -----\n");
    while (fgets(buffer, sizeof(buffer), f2) != NULL)
    {
        fprintf(f3, "%s", buffer);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);

    /* Display final output */
    system("cat merged.txt");

    return 0;
}
