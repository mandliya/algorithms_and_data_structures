#include <iostream>
#include <cstdio>

enum endianess {
  LITTLE_ENDIAN_MACHINE = 0,
  BIG_ENDIAN_MACHINE
};

endianess determine_endianess()
{
  unsigned int num = 1;
  char * c = (char *) &num;
  if (*c == 1) {
    return LITTLE_ENDIAN_MACHINE;
  } else {
    return BIG_ENDIAN_MACHINE;
  }
}

void printBytes( char * start, int size)
{
  for ( int i = 0; i < size; ++i ) {
    printf("%.2x ", start[i] );
  }
  std::cout << std::endl;
}

int reverseEndianNess( int num )
{
  int byte1, byte2, byte3, byte4;
  byte1 = (num & 0x000000FF) >> 0;
  byte2 = (num & 0x0000FF00) >> 8;
  byte3 = (num & 0x00FF0000) >> 16;
  byte4 = (num & 0xFF000000) >> 24;
  return ((byte1 << 24) | (byte2 << 16) | (byte3 << 8) | (byte4 << 0));
}

int main() {
  endianess sys_endianess = determine_endianess();
  if (sys_endianess == LITTLE_ENDIAN_MACHINE) {
    std::cout << "System is little endian\n\n";
  } else {
    std::cout << "System is big endian\n\n";
  }

  int num = 0x01234567;
  std::cout << "Num in decimal:    " << num << std::endl;
  std::ios::fmtflags f(std::cout.flags());
  std::cout << "Num in hexadecimal:" << std::hex << num << std::endl;
  std::cout.flags( f );
  std::cout << "Printing individual bytes:\n";
  printBytes((char*)&num, sizeof(num));

  std::cout << std::endl;
  std::cout << "Num in reversed endianness:\n";
  int num1 = reverseEndianNess(num);

  std::cout << "Num in decimal    :" << num1 << std::endl;

  f = std::cout.flags();
  std::cout << "Num in hexadecimal:" << std::hex << num1 << std::endl;
  std::cout.flags( f );
  std::cout << "Printing individual bytes:\n";
  printBytes((char*)&num1, sizeof(num1));

  return 0;

}
