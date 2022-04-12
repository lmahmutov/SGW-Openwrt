#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "cJSON.h"

#define BUF_MAX       1024
#define SERVER_PORT   6677

enum {
    ZB_VERSION_REQ = 100,
    ZB_RFTEST_REQ,
    ZB_UPGRADE_REQ,
};

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif

struct subcmd {
    char *name;
    int (*cb)(int argc, char **argv);
};

static int version_handler(int argc, char **argv);
static int rftest_handler(int argc, char **argv);
static int upgrade_handler(int argc, char **argv);

struct subcmd cmds[] = {
    { "version", version_handler },
    { "rftest",  rftest_handler  },
    { "upgrade", upgrade_handler },
};

static void usage(void)
{
    printf("\nUsage: ztool <COMMAND> [OPTIONS]\n");
    
    printf("\nCOMMAND\n");
    printf("  version                         Read Zigbee module version\n");
    printf("  upgrade <file>                  Upgrade Zigbee module firmware\n");
    printf("  rftest <channel> <npacket>      RF testing\n");
    
    printf("\nExampels\n");
    printf("  $ ztool version\n");
    printf("  $ ztool rftest 11 100\n");
    printf("\n");
}

static void usock_set_nonblock(int sock)
{
    fcntl(sock, F_SETFL, fcntl(sock, F_GETFL) | O_NONBLOCK);
}

static int usock_connect(const char *ip, int port)
{
    int sockfd = 0;
    struct sockaddr_in svraddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        return -1;

    bzero(&svraddr, sizeof(svraddr));
    svraddr.sin_family = AF_INET;
    svraddr.sin_addr.s_addr = inet_addr(ip);
    svraddr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&svraddr, sizeof(svraddr)) != 0) {
        close(sockfd);
        return -1;
    }

    return sockfd;
}

static void send_req(char *req, char **resp, int timeout)
{
    int sockfd = 0;
    int retval = 0;
    ssize_t bytes = 0;
    char *ptmp = NULL;
    char buf[BUF_MAX] = {0};
    fd_set rfds;
    struct timeval tv;

    if (req == NULL)
        return;

    /* select timeout */
    tv.tv_sec = timeout;
    tv.tv_usec = 0;

    sockfd = usock_connect("127.0.0.1", SERVER_PORT);
    if (sockfd == -1)
        return;

    /* send request */
    write(sockfd, req, strlen(req));

    /* set timeout for recv */
    usock_set_nonblock(sockfd);  

    FD_ZERO(&rfds);
    FD_SET(sockfd, &rfds);

    retval = select(sockfd + 1, &rfds, NULL, NULL, &tv);
    if (retval == -1) {
        /* select error */
    } else if (retval == 0) {
        /* no data within tv */
    } else {
        /* data is available now */
        bytes = read(sockfd, buf, sizeof(buf));
        if (bytes > 0) {
            ptmp = malloc(bytes);
            memcpy(ptmp, buf, bytes);
            *resp = ptmp;
        }
    }
    
    close(sockfd);
}

static int parse_resp(const char *resp, const char *key)
{
    cJSON *root = NULL, *jobj = NULL;

    if ((resp == NULL) || (key == NULL))
        return -1;

    root = cJSON_Parse(resp);
    if (root == NULL)
        return -1;

    jobj = cJSON_GetObjectItem(root, key);
    if (jobj != NULL) {
        switch (jobj->type) {
            case cJSON_String:
                printf("%s\n", jobj->valuestring);
                break;
            case cJSON_Number:
                printf("%d\n", jobj->valueint);
                break;
        }
    }

    cJSON_Delete(root);

    return 0;
}

static int version_handler(int argc, char **argv)
{
    cJSON *root = NULL;
    char *req = NULL, *resp = NULL;

    root = cJSON_CreateObject();
    if (root == NULL)
        return -1;

    cJSON_AddNumberToObject(root, "cmd", ZB_VERSION_REQ);

    req = cJSON_PrintUnformatted(root);
    if (req == NULL) {
        cJSON_Delete(root);
        return -1;
    }

    send_req(req, &resp, 3);
    if (resp != NULL) {
        parse_resp(resp, "version");
        free(resp);
    }

    free(req);
    cJSON_Delete(root);

    return 0;
}

static int rftest_handler(int argc, char **argv)
{
    cJSON *root = NULL;
    char *req = NULL, *resp = NULL;
    int channel = 0;
    int npacket = 0;

    if (argc < 2) {
        usage();
        exit(EXIT_FAILURE);
    }

    channel = atoi(argv[0]);
    npacket = atoi(argv[1]);

    root = cJSON_CreateObject();
    if (root == NULL)
        return -1;
    
    cJSON_AddNumberToObject(root, "cmd", ZB_RFTEST_REQ);
    cJSON_AddNumberToObject(root, "channel", channel);
    cJSON_AddNumberToObject(root, "packet", npacket);

    req = cJSON_PrintUnformatted(root);
    if (req == NULL) {
        cJSON_Delete(root);
        return -1;
    }

    send_req(req, &resp, 20);
    if (resp != NULL) {
        parse_resp(resp, "packet");
        free(resp);
    }

    free(req);
    cJSON_Delete(root);

    return 0;
}

static int upgrade_handler(int argc, char **argv)
{
    cJSON *root = NULL;
    char *req = NULL, *resp = NULL;
    char *img = NULL;

    if (argc < 1) {
        usage();
        exit(EXIT_FAILURE);
    }

    img = argv[0];

    root = cJSON_CreateObject();
    if (root == NULL)
        return -1;
    
    cJSON_AddNumberToObject(root, "cmd", ZB_UPGRADE_REQ);
    cJSON_AddStringToObject(root, "img", img);
    
    req = cJSON_PrintUnformatted(root);
    if (req == NULL) {
        cJSON_Delete(root);
        return -1;
    }

    send_req(req, &resp, 20);
    if (resp != NULL) {
        parse_resp(resp, "status");
        free(resp);
    }

    free(req);
    cJSON_Delete(root);

    return 0;
}

int main(int argc, char **argv)
{
    int i = 0;
    char *cmd = NULL;

    if (argc < 2) {
        usage();
        exit(EXIT_FAILURE);
    }

    cmd = argv[1];

    for (i = 0; i < ARRAY_SIZE(cmds); i++) {
        if (!strcmp(cmd, cmds[i].name)) {
            /* offset to option */
            cmds[i].cb(argc - 2, argv + 2);
            break;
        }
    }

    return 0;
}