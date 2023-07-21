#include <stdio.h>
#include <fcntl.h>
#include<string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd=0;
    int Mode=0;

    if (argc != 3) {
        printf("Invalid Number of Argumnets....");
        return -1;
    }

    if (strcmp(argv[2], "Read") == 0)
    {
        Mode = O_RDONLY;
    } 
    else if (strcmp(argv[2], "Write") == 0)
    { 
        Mode = O_WRONLY;
    }
     else 
    {
        printf("Invalid mode. Available modes are 'Read' or 'Write'.\n");
        return -1;
    }

    fd = open(argv[1], Mode);

    if (fd == -1)
     {
        printf("Unable to open the file in %s mode\n", argv[2]);
    }
     else {
        printf("File is Successfully opened  in %s mode\n", argv[2]);
        close(fd);
    }
    return 0;
}