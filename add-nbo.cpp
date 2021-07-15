#include <stdint.h> // for uint32_t = 4byte int
#include <stdio.h> // for printf
#include <arpa/inet.h> // ntohl,s ...
#include <stdlib.h> // argc, argv

//smaple : add-nbo <file1> <file2>
//./add-nbo dataf1 dataf2

int main(int argc, char *argv[]) {
    FILE *dataf; // file1, file2 = dataf1, dataf2
    uint32_t prime1, prime2, score;

    // argv[First File]
    dataf = fopen(argv[1], "r"); // only read
    fread(&prime1, sizeof(prime1), 1, dataf);  // don't care about overflow

    // argv[Second File]
    dataf = fopen(argv[2], "r");
    fread(&prime2, sizeof(prime2), 1, dataf);  // don't care about overflow

    prime1 = ntohl(prime1); //32bit(4byte), long type data. IP addr = network byte to host byte
    prime2 = ntohl(prime2);

    score = prime1 + prime2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", prime1, prime1, prime2, prime2, score, score);
    // DECprimeN(HEXprimeN)


    return 0;
}
