/*
 * ---=== Brainfunky ===---
 *
 * My tiny experimental Brainfuck interpreter written in pure C
 *
 * Copyright (c) Ivan Movchan (NobootRecord), 2022
 * [https://nobootrecord.github.io]
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Include all the stuff we need

int main(int argc, char*argv[]) // Here we go
{
    FILE *f; char m[30000];
    int p = 0, l = 0, fp = 0;
    char x = 0; // Some variables...

    for (int i = 0; i < 30000; i++) m[i] = 0; // Initialize buffer

    // Check arguments and show help message if need
    if (argc != 2)
    {
            printf("Brainfunky 1.0 (%s %s)\nUsage: brainfunky $filename$\n", __DATE__, __TIME__);
            return 0;
    };

    // Open file
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Failed to open '%s' file\n", argv[1]);
        return 1;
    };

    while (!feof(f)) // Run Brainfuck code :)
    {
        x = fgetc(f); fp++; // Read one char
        if (x == '>') p++;
        if (x == '<') p--;
        if (x == '+') m[p]++;
        if (x == '-') m[p]--;
        if (x == '.') printf("%c", m[p]);
        if (x == ',') m[p] = getchar();
        if (x == '[' && m[p] == 0)
        {
            l = fp;
            while (x != ']')
            {
                fp++;
                fseek(f, fp, SEEK_SET);
                x = fgetc(f);
                if (feof(f)) return 0;
            };
        };
        if (x == ']' && m[p] != 0)
        {
            fseek(f, l, SEEK_SET);
            fp -= l;
        };
    };

    // Close file and exit
    fclose(f);
    return 0;
}
