#include <stdlib.h>
#include <string.h>

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

void parse_object(char *string)
{
    clean_string(string);
    cJSON *json = cJSON_Parse(string);

    cJSON *operation = NULL;
    cJSON *image = NULL;

    operation = cJSON_GetObjectItem(json, "operation");
    image = cJSON_GetObjectItem(json, "image");

    char *systemCall = (char *)malloc((strlen(image->valuestring) + 100) * sizeof(char));
    int res = 0;

    if (operation->valueint)
    {
        strcpy(systemCall, "python3 ");
        strcat(systemCall, pyS_path);
        strcat(systemCall, " ");
        strcat(systemCall, "colors.py ");
        strcat(systemCall, colores_path);
        strcat(systemCall, " ");
        strcat(systemCall, image->valuestring);
        res = system(systemCall);
    }
    else
    {
        strcpy(systemCall, "python3 ");
        strcat(systemCall, pyS_path);
        strcat(systemCall, " ");
        strcat(systemCall, "histograma.py ");
        strcat(systemCall, histo_path);
        strcat(systemCall, " ");
        strcat(systemCall, image->valuestring);
        res = system(systemCall);
    }
    free(systemCall);
}

void clean_string(char *string)
{
    char buggi = *(string + 1);
    int j, n = (int)payload_size;
    for (int i = j = 0; i < n; i++)
        if (*(string + i) != buggi & *(string + i) != '\n' & *(string + i) != ' ')
            string[j++] = string[i];
    string[j] = '\0';
}