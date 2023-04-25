#include "main.h"

void print_buffer(char *buffer, int size)
{
    int written = 0;

    while (written < size)
    {
        int res = write(STDOUT_FILENO, buffer + written, size - written);
        if (res == -1)
        {
            // Handle write error
            break;
        }
        written += res;
    }
}
