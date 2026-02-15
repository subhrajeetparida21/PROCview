/*****************************************************************************************
 * PROGRAM: PROCview — Create a User Command `my_ps`
 *
 * OBJECTIVE:
 * This program creates a user-level command called `my_ps` that merges information from:
 *      1) `ps aux`   → USER, PID, %CPU, %MEM, VSZ, RSS, TTY, STAT, START, TIME, COMMAND
 *      2) `ps -eLf`  → process + thread view (LWP, NLWP, etc.)
 *
 * ASSIGNMENT HINT (as given):
 * - Use system() to execute:
 *      "ps aux  > x1.txt"
 *      "ps -eLf > x2.txt"
 * - Open files, extract info and write combined output into merged.txt
 * - Display merged.txt in terminal
 * - Compile and save executable as `my_ps` so it behaves like a command
 *
 * USAGE:
 *      ./my_ps
 * or (after copying into /usr/local/bin):
 *      my_ps
 *
 * OUTPUT FILES GENERATED:
 *      x1.txt      → output of `ps aux`
 *      x2.txt      → output of `ps -eLf`
 *      merged.txt  → combined output (final)
 *****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /***********************
     * 1) Run ps commands
     ***********************/
    system("ps aux > x1.txt");
    system("ps -eLf > x2.txt");

    /***********************
     * 2) Open files
     ***********************/
    FILE *fp1 = fopen("x1.txt", "r");
    FILE *fp2 = fopen("x2.txt", "r");
    FILE *fp3 = fopen("merged.txt", "w");

    if (fp1 == NULL || fp2 == NULL || fp3 == NULL)
    {
        printf("Error: Could not open one or more files.\n");
        return 1;
    }

    /***********************
     * 3) Merge content
     ***********************/
    char line[2000];

    fprintf(fp3, "===================== PROCview (my_ps) =====================\n\n");

    fprintf(fp3, "--------------------- ps aux OUTPUT -------------------------\n");
    while (fgets(line, sizeof(line), fp1) != NULL)
    {
        fprintf(fp3, "%s", line);
    }

    fprintf(fp3, "\n--------------------- ps -eLf OUTPUT ------------------------\n");
    while (fgets(line, sizeof(line), fp2) != NULL)
    {
        fprintf(fp3, "%s", line);
    }

    /***********************
     * 4) Close files
     ***********************/
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    /***********************
     * 5) Display merged.txt
     ***********************/
    system("cat merged.txt");

    return 0;
}
