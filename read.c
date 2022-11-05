#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd; // read from the file indicated by the file descriptor fd
    int len; // the read() function reads len bytes of input
    char buf[101] = ""; // read into the memory area indicated by buf
    fd = open("text.txt", O_RDONLY);
    
    fd = read(fd, buf, 98);
    // Returns How many bytes were actually read on success
    //  0 on reaching end of file
    //  -1 on error or signal interrupt
    printf("%s  %d", buf, fd);

    return 0;
}
// Important points

// buf needs to point to a valid memory location with length not smaller than the specified size because of overflow.

// fd should be a valid file descriptor returned from open() to perform read operation,
//      because if fd is NULL then read should generate error.