#include <klibtest.h>

#define N 32
char data[2*N], data1[2*N];
char* p = data;

void reset() {
  int i;
  for (i = 0; i < 2 * N; i ++) {
    if(i < N) {
      data[i] = i + 1;
      data1[i] = i + 1;
    } else {
      data[i] = 0;
      data1[i] = 0;
    }
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

void printf_data() {
  for (int i = 0; i < 2*N; i ++) {
    printf("%d\t", data[i]);
  }
  printf("\n");
}

void test_strcat() {
  int l;
  for (l = 0; l < N; l ++) {
      reset();
      // printf("%d\n", l);
      // printf_data();
      strcat(data, data1 + l);
      // printf_data();
      check_seq(0, N, 1);
      check_seq(N, 2*N - l, l + 1);
      check_eq(2*N - l, 2 *N, 0);    
  }
}

int main(const char *args) {
  
  test_strcat();
 
      // reset();
      // printf_data();
      // strcat(data, data + 25);
      // printf_data();
      // check_seq(0, N, 1);
      // check_seq(N, 2*N - 25, 26);
      // check_eq(2*N - 25, 2*N, 0);

  return 0;
}