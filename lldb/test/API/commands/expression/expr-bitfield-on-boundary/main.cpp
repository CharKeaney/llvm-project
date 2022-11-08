// This test is to check that printing bitfields works across boundaries
// when a negative offset is generated.
//
// Note b is going across the byte boundary.
// In DWARFv2, b will have a negative offset of -1 bits
// from the second byte.
//
//          Byte 1                  Byte 2
//
//   7  6  5  4  3  2  1  0  7  6  5  4  3  2  1  0
// +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
// | 0: 0: 0: 0: 1: 1: 1: 1| 0: 0: 1:  :  :  :  :  |
// +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
// ^                    ^
// a                    b
//
// The value 9 was chosen for b so that one bit would be
// on both sides of the byte boundary.

struct __attribute__((packed)) Foo {
  unsigned char a : 7;
  unsigned char b : 4;
};

int main() {
  volatile struct Foo f;
  f.a = 7;
  f.b = 9;
  return 0; // Break here
}
