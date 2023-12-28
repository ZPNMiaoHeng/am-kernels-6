#include <klibtest.h>

#define N 32
uint8_t data[N];

void reset() {
  int i;
  for (i = 0; i < N; i ++) {
    data[i] = i + 1;
  }
}

void check_seq(int l, int r, int val) {
  int i;
  for (i = l; i < r; i ++) {
    assert(data[i] == val + i - l);
  }
}

void check_eq(int l, int r, int val) {
  int i;
  for (i = l; i < r; i ++) {
    assert(data[i] == val);
  }
}

void test_memset() {
  int l, r;
  for (l = 0; l < N; l ++) {
    for (r = l + 1; r <= N; r ++) {
      reset();
      uint8_t val = (l + r) / 2;
      memset(data + l, val, r - l);
      check_seq(0, l, 1);
      check_eq(l, r, val);
      check_seq(r, N, r + 1);
    }
  }
}

int main(const char *args) {
  const char *fmt =
    "\n"
    "Hello, AbstractMachine!\n"
    "mainargs = '%'.\n"
    "mem test!\n";

  for (const char *p = fmt; *p; p++) {
    // (*p == '%') ? putstr(args) : putch(*p);
    putch(*p);
  }
  printf("\nhello, world\n");
  reset();
  for(int i =0; i<N; i++) {
    printf("%d\t", data[i]);
  }
    test_memset();

  return 0;
}
