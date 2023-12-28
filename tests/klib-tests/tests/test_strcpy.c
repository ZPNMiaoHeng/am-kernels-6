#include <klibtest.h>

#define N 32
char data[N];

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

void test_strcpy() {
  int l, r;
  for (l = 0; l < N; l ++) {
    for (r = l + 1; r <= N; r ++) {
      reset();
      // printf("%d\t%d\n", l, r);
      // printf_data();
      strcpy(data + l, data + r);
      // printf_data();
      check_seq(0, l, 1);
      check_seq(l, N - r, r + 1);
      check_eq(N - r + l, N - r + l + 1, 0);          // 检测字符串\0
      check_seq(N - r + l + 1, N, N - r + l + 2);   // 检测没有没覆盖的部分
    }
  }
}

int main(const char *args) {
  // reset();
  // printf_data();
  // strcpy(data + 0, data + 3);
  // printf_data();
  
 test_strcpy();

  return 0;
}
