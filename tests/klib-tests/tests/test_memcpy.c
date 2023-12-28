#include <klibtest.h>

#define N 32
uint8_t data[N];

void reset() {
  int i;
  for (i = 0; i < N; i ++) {
    data[i] = i + 1;
  }
}

void printf_data() {
  for (int i = 0; i < N; i ++) {
    printf("%d\t", data[i]);
  }
  printf("\n");
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

void test_memcpy() {
  int l, r;
  for (l = 0; l < N; l ++) {
    for (r = l + 1; r <= N; r ++) {
      reset();
      uint8_t val = (l + r) / 2;
      // printf("%d\t%d\t%d\n", l, r, val);
      if(r - l + val > N) {
        break;
      }
      memcpy(data + l, data + val, r - l);
      check_seq(0, l, 1);
      check_seq(l, r, val + 1);
      check_seq(r, N, r + 1);
    }
  }
}

int main(const char *args) {
  // test_memcpy();
  // l =10 r=12 val = 11
  // reset();
  // printf_data();
  // memcpy(data + 10, data + 11, 2);
  // printf_data();
  // check_seq(0, 10, 1);
  // check_seq(10, 12, 12);
  // check_seq(12, N, 12 + 1);
  
  // assert(0);
  test_memcpy();

  return 0;
}
