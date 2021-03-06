#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

#include "header/httpd.h"
#include "header/tools.h"
#include "header/cJSON.h"

int main(int c, char **v)
{

    // /* Our process ID and Session ID */
    // pid_t pid, sid;

    // /* Fork off the parent process */
    // pid = fork();
    // if (pid < 0)
    // {
    //     exit(EXIT_FAILURE);
    // }
    // /* If we got a good PID, then
    //        we can exit the parent process. */
    // if (pid > 0)
    // {
    //     exit(EXIT_SUCCESS);
    // }

    // /* Change the file mode mask */
    // umask(0);

    // /* Open any logs here */

    // /* Create a new SID for the child process */
    // sid = setsid();
    // if (sid < 0)
    // {
    //     /* Log the failure */
    //     exit(EXIT_FAILURE);
    // }

    // /* Change the current working directory */
    // if ((chdir("/")) < 0)
    // {
    //     /* Log the failure */
    //     exit(EXIT_FAILURE);
    // }

    // /* Close out the standard file descriptors */
    // close(STDIN_FILENO);
    // close(STDOUT_FILENO);
    // close(STDERR_FILENO);

    t_port_val = (char *)malloc(MAXCHAR * sizeof(char));
    t_colores_val = (char *)malloc(MAXCHAR * sizeof(char));
    t_histo_val = (char *)malloc(MAXCHAR * sizeof(char));
    t_logs_val = (char *)malloc(MAXCHAR * sizeof(char));
    t_pyS_val = (char *)malloc(MAXCHAR * sizeof(char));

    lens = (int *)malloc(5 * sizeof(int));

    FILE *fp = fopen("/etc/server/config.conf", "r");

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
        fgets(t_pyS_val, MAXCHAR, fp);
    }

    *lens = getlen(t_port_val);
    *(lens + 1) = getlen(t_colores_val);
    *(lens + 2) = getlen(t_histo_val);
    *(lens + 3) = getlen(t_logs_val);
    *(lens + 4) = getlen(t_pyS_val);

    port = (char *)malloc(*lens * sizeof(char));
    colores_path = (char *)malloc(*(lens + 1) * sizeof(char));
    histo_path = (char *)malloc(*(lens + 2) * sizeof(char));
    logs_path = (char *)malloc(*(lens + 3) * sizeof(char));
    pyS_path = (char *)malloc(*(lens + 4) * sizeof(char));

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
    i = 0;
    while (i < *(lens + 4))
    {
        pyS_path[i] = t_pyS_val[i];
        i++;
    }

    free(fp);
    free(lens);
    free(t_port_val);
    free(t_colores_val);
    free(t_histo_val);
    free(t_logs_val);
    free(t_pyS_val);

    // load_config();
    serve_forever(port);
    // exit(EXIT_SUCCESS);
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
        parse_object(payload);
        fprintf(stderr, "200 OK :D\n");
    }

    ROUTE_END()
}
