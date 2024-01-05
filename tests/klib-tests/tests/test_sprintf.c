#include <klibtest.h>


char buf[128];

int main(const char *args) {

  memset(buf, '\0', sizeof(buf));
  sprintf(buf, "char = %s", "Hello world!\n");
  putstr(buf);

  memset(buf, '\0', sizeof(buf));
	sprintf(buf, "%d\n", 1);
  putstr(buf);
  
  memset(buf, '\0', sizeof(buf));
	sprintf(buf, "%d + %d = %d\n", 1, 1, 2);
  putstr(buf);

  // memset(buf, '\0', sizeof(buf));
	// sprintf(buf, "%d + %d = %d\n", 2, 10, 12);
  // putstr(buf);

/*
  memset(buf, '\0', sizeof(buf));
  sprintf(buf, "%s", "Hello world!\n");
  putstr(buf);

  memset(buf, '\0', sizeof(buf));
	sprintf(buf, "%d + %d = %d\n", 1, 1, 2);
  putstr(buf);

  memset(buf, '\0', sizeof(buf));
	sprintf(buf, "%d + %d = %d\n", 2, 10, 12);
  putstr(buf);
*/
  return 0;
}