struct __attribute__((packed)) Foo {
  unsigned char a : 7;
  unsigned char b : 4;
};

int main() {
  volatile struct Foo f;
  f.a = 1;
  f.b = 2;
  return 0; // Break here
}
