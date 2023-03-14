#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/select.h>

#define DATA_NUM     64

int main(int argc, char *argv[])
{
    int fd;
    int r_len, w_len;
    char buf[DATA_NUM] = "hello world";
    memset(buf, 0, DATA_NUM);

    fd = open("/dev/hello", O_RDWR);
    if (-1 == fd) {
        printf("open file error!\n");
        return -1;
    }
    r_len = read(fd, buf, DATA_NUM);
    w_len = write(fd, buf, DATA_NUM);
    printf("buf: %s\n", buf);

    return 0;
}