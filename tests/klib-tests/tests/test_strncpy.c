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
      uint8_t val = (l + r) / 2;
      // printf("%d\t%d\t%d\n", l, r, val);
      // printf_data();
      strncpy(data + l, data + val, r - l);
      // printf_data();
      check_seq(0, l, 1);
      
      if(r - l + val <= N) {
        check_seq(l, r, val + 1);
        check_seq(r, N, r + 1);
      } else {
        int zero_num = (r - l + val) - N;
        check_seq(l, r - zero_num, val + 1);
        check_eq(r - zero_num, r, 0);
        check_seq(r, N, r + 1);
      }

    }
  }
}

int main(const char *args) {
  
 test_strcpy();
 
      // reset();
      // printf_data();
      // strncpy(data, data + 11, 22);
      // printf_data();
      // check_seq(0, 0, 1);

      // check_seq(0, 22, 11 + 1);
      
      // check_eq(22, 22+1, 0);
      // check_seq(22+1, N, 22 + 1); // 23 , 32, 


  return 0;
}