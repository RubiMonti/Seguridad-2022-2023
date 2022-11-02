# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <openssl/sha.h>
# include <openssl/hmac.h>

unsigned char *parse_key(char *filename){
    int fd = open(filename,O_RDONLY);
    unsigned char *temp = malloc(read_size);
    int bytes_read = read(fd,temp, read_size);
    if (bytes_read < 20)
        printf("Warning: Key should be more than 20 characters long\n");
    if (bytes_read < 64)
        return temp;
    SHA_CTX ctx;
    if (SHA1_Init(&ctx) == 0){
        printf("Could not init SHA1\n");
        return -1;
    }
    while(bytes_read != 0){
        if (SHA1_Update(&ctx, temp, bytes_read) == 0){
            printf("Could not update SHA1\n");
            return -1;
        }
        bytes_read = read(fd,temp, read_size);
    }
    free(temp);
    unsigned char *result = malloc(SHA_DIGEST_LENGTH);
    if (SHA1_Final(result, &ctx) == 0){
        printf("Could not end SHA1\n");
        return -1;
    }
    return result;
}

int main(int argc, char* argv[]){
    if (argc != 3){
        printf("Usage: ./hmacsha1 datos.txt key\n");
        return -1;
    }

    unsigned char *key = parse_key(argv[2])
    SHA_CTX ctx;
    if (SHA1_Init(&ctx) == 0){
        printf("Could not init SHA1\n");
        return -1;
    }
    int read_size = 1024;
    int fd = open(argv[1],O_RDONLY);
    unsigned char *temp = malloc(read_size);
    int bytes_read = read(fd,temp, read_size);
    while(bytes_read != 0){
        if (SHA1_Update(&ctx, temp, bytes_read) == 0){
            printf("Could not update SHA1\n");
            return -1;
        }
        bytes_read = read(fd,temp, read_size);
    }
    free(temp);
    unsigned char *result = malloc(SHA_DIGEST_LENGTH);
    if (SHA1_Final(result, &ctx) == 0){
        printf("Could not end SHA1\n");
        return -1;
    }
    for (int i = 0; i < SHA_DIGEST_LENGTH; i++){
        printf("%hhx", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}