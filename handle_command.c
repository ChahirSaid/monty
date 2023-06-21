#include "monty.h"

/**
 * handle_cmd - Handles Monty commands
 * @line: The command line to be processed
 * @l: The line number of the command
 * @head: Double pointer to the head of the stack
 *
 * Description: This function handles Monty commands by tokenizing the command line,
 *              comparing the tokens to a list of known instructions, and executing
 *              the corresponding functions. It also handles special cases like the
 *              "push" instruction where a value needs to be extracted from the line.
 *
 * Return: 0 on success, 1 if there's an error with the command format, 2 if the instruction is unknown.
 */
int handle_cmd(char *line, unsigned int l, stack_t **head)
{
    int i = 0;
    char *first;
    instruction_t op[] = {
		{"push", _push},
        {"pall", _pall},
        {"pint", _pint},
        {"pop", _pop},
        {"swap", _swap},
        {"add", _add},
        {"nop", _nop},
		{NULL, NULL}
	};

    first = strtok(line, " \n\t\r\a\v");

    if (first == NULL || first[0] == '#')
        return (0);

    while (op[i].opcode != NULL)
    {
        if (strcmp(op[i].opcode, first) == 0)
        {
            if (strcmp(first, "push") == 0)
            {
                first = strtok(NULL, " \n\t\r\a\v");
                if (_isdigit(first) == 1)
                    value = atoi(first);
                else
                {
                    fprintf(stderr, "L%u: usage: push integer\n", l);
                    fclose(gv.file);
                    free(gv.line);
                    free_stack(head);
                    exit(EXIT_FAILURE);
                }
            }
            op[i].f(head, l);
            return (0);
        }
        else
        {
            if (op[i+1].opcode == NULL)
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", l, first);
                fclose(gv.file);
                free(gv.line);
                free_stack(head);
                exit(EXIT_FAILURE);
            }
        }
        i++;
    }
    return (0);
}
