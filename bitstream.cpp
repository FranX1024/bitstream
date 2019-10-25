#include <stdlib.h>

/*
Made by Fran 1024, 2019
*/

class bitStream {
private:
  char *data; // where bitstream is contained
  int size;   // size of the bitstream
public:
  // returns data as a byte array
  char *toByteArray() {
    return data;
  }
  /**************************/
  bool getbit(char x, int y) {
    return (x >> (7 - y)) & 1;
  }
  int chbit(int x, int i, bool v) {
    if(v) return x | (1 << (7 - i));
    return x & ~(1 << (7 - i));
  }
  /**************************/

  // opens an existing byte array as bitstream
  void openBytes(char *bytes, int _size) {
    data = bytes;
    size = _size;
  }
  // creates a new bit stream
  void open(int _size) {
    data = (char*)malloc(_size);
    size = _size;
  }
  // closes bit stream (frees memory)
  void close() {
    free(data);
  }
  // writes to bitstream
  void write(int ind, int bits, int dat) {
    ind += bits;
    while(dat) {
      data[ind / 8] = chbit(data[ind / 8], ind % 8, dat & 1);
      dat /= 2;
      ind--;
    }
  }
  // reads from bitstream
  int read(int ind, int bits) {
    int dat = 0;
    for(int i = ind; i < ind + bits; i++) {
      dat = dat * 2 + getbit(data[i / 8], i % 8);
    }
    return dat;
  }
};
