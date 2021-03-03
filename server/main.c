#include "header/httpd.h"
#include <stdlib.h>

#define MAXCHAR 1000

int getlen(char line[]);

int main(int c, char **v)
{
    char *t_port_val = (char *)malloc(MAXCHAR * sizeof(char));
    char *t_colores_val = (char *)malloc(MAXCHAR * sizeof(char));
    char *t_histo_val = (char *)malloc(MAXCHAR * sizeof(char));
    char *t_logs_val = (char *)malloc(MAXCHAR * sizeof(char));

    int *lens = (int *)malloc(4 * sizeof(int));

    FILE *fp = fopen("/home/nickotronz7/Documents/DevProjects/CMVService/server/config.conf", "r");

    if (fp == NULL)
    {
        printf("Could not open file");
        return 1;
    }

    else
    {
        fgets(t_port_val, MAXCHAR, fp);
        fgets(t_colores_val, MAXCHAR, fp);
        fgets(t_histo_val, MAXCHAR, fp);
        fgets(t_logs_val, MAXCHAR, fp);
    }

    *lens = getlen(t_port_val);
    *(lens + 1) = getlen(t_colores_val);
    *(lens + 2) = getlen(t_histo_val);
    *(lens + 3) = getlen(t_logs_val);

    char *port = (char *)malloc(*lens * sizeof(char));
    char *colores_path = (char *)malloc(*(lens + 1) * sizeof(char));
    char *histo_path = (char *)malloc(*(lens + 2) * sizeof(char));
    char *logs_path = (char *)malloc(*(lens + 3) * sizeof(char));

    int i = 0;
    while (i < *lens)
    {
        port[i] = t_port_val[i];
        i++;
    }
    i = 0;
    while (i < *(lens + 1))
    {
        colores_path[i] = t_colores_val[i];
        i++;
    }
    i = 0;
    while (i < *(lens + 2))
    {
        histo_path[i] = t_histo_val[i];
        i++;
    }
    i = 0;
    while (i < *(lens + 3))
    {
        logs_path[i] = t_logs_val[i];
        i++;
    }

    free(fp);
    free(lens);
    free(t_port_val);
    free(t_colores_val);
    free(t_histo_val);
    free(t_logs_val);
    

    // load_config();
    serve_forever(port);
    return 0;
}

void route()
{
    ROUTE_START()

    ROUTE_GET("/")
    {
        printf("HTTP/1.1 200 OK\r\n\r\n");
        printf("Hello! You are using %s", request_header("User-Agent"));
    }

    ROUTE_GET("/test")
    {
        printf("HTTP/1.1 200 OK\r\n\r\n");
        printf("List of request headers:\r\n\r\n");

        header_t *h = request_headers();

        while (h->name)
        {
            printf("%s: %s\n", h->name, h->value);
            h++;
        }
    }

    ROUTE_POST("/")
    {
        printf("HTTP/1.1 200 OK\r\n\r\n");
        printf("Wow, seems that you POSTED %lld bytes. \r\n", payload_size);
        printf("Data: %s", payload);
    }

    ROUTE_END()
}

int getlen(char line[])
{
    int len = 0;
    while (line[len] != '\n')
    {
        len++;
    }
    return len;
}
