#include <stdio.h>
#include <string.h>

void entityParser(char *text)
{
    int t = strncmp(text, "&amp", strlen("&amp"));
    printf("The value is %d \n", t);
}


int main()
{
    entityParser("&amp; is an HTML entity but &ambassador; is not.");
    return 0;
}
