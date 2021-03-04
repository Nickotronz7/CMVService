#include <stdlib.h>
#include "../header/tools.h"
#include "../header/cJSON.h"
#include "../header/httpd.h"

int getlen(char line[])
{
    int len = 0;
    while (line[len] != '\n')
    {
        len++;
    }
    return len;
}

void parse_object(char* string) {
    clean_string(string);
    cJSON *json = cJSON_Parse(string);

//    printf("%s",cJSON_Print(json));

    cJSON *operation = NULL;
    cJSON *image = NULL;

    operation = cJSON_GetObjectItem(json, "operation");
    image = cJSON_GetObjectItem(json, "image");

    fprintf(stderr,"\x1b[32m + operation -> %d\x1b[0m\n", operation->valueint);
    fprintf(stderr,"\x1b[32m + image data -> %s\x1b[0m\n", image->valuestring);
}

void clean_string(char *string) {
    char buggi = *(string + 1);
    int j, n = (int)payload_size;
    for (int i = j = 0; i < n; i++)
        if (*(string + i) != buggi & *(string + i) != '\n' & *(string + i) != ' ')
            string[j++] = string[i];
    string[j] = '\0';
}