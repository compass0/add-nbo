#include<string>
#include<stdint.h>
#include<fstream>
#include<netinet/in.h>

using namespace std;

uint32_t readInt(char * filename){
    uint32_t input4Byte;
    FILE* pFile = fopen(filename, "rb");
    size_t readLen = fread(&input4Byte, 1, sizeof(uint32_t), pFile);
    printf("fread return %lu\n", readLen);
    if(readLen != sizeof(uint32_t)){
        printf("fread return %lu\n", readLen);
        exit(-1);
    }
    input4Byte = ntohl(input4Byte);
    fclose(pFile);
    
    return input4Byte;
}

int main(int argc, char* argv[]){
    uint32_t thousand = readInt(argv[1]);
    uint32_t five_hundred = readInt(argv[2]);
    
    printf("%u(%x) + %u(%x) = %u(%x)\n", thousand, thousand, five_hundred, five_hundred, thousand + five_hundred, thousand + five_hundred);
    
    return 0;
}