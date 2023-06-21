#include "monty.h"

glob_vars gv = {NULL, NULL, NULL};

/**
 * main - Entry point of the program
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * This function reads a file specified as a command line argument and
 * Description: executes commands based on the contents of the file.
 */
int main(int argc, char *argv[])
{
    size_t size = 0;
    ssize_t lines = 1;
    unsigned int l = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    gv.file = fopen(argv[1], "r");

    if (gv.file == NULL)
    {
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
    }

    while (lines > 0)
    {
        gv.line = NULL;
        lines = getline(&(gv.line), &size, gv.file);
        l++;

        if (lines > 0)
            handle_cmd(gv.line, l, &gv.head);

        free(gv.line);
    }

    free_stack(&gv.head);
    fclose(gv.file);
    return (0);
}
