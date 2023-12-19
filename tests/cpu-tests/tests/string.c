#include "trap.h"

char *s[] = {
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	", World!\n",
	"Hello, World!\n",
	"#####"
};

char str1[] = "Hello";
char str[20];

int main() {
	check(strcmp(s[0], s[2]) == 0);
	check(strncmp(s[0], s[2], 10) == 0);
	check(strncmp(s[3], s[4], 10) < 0);
	check(strncmp(s[0], s[2], strlen(s[0])) == 0);
	check(strncmp(s[0], s[1], strlen(s[0])) < 0);
	check(strncmp(s[5], "######", 6) < 0);
	
	check(strcmp(s[0], s[1]) < 0);
	check(strcmp(s[0] + 1, s[1] + 1) < 0);
	check(strcmp(s[0] + 2, s[1] + 2) < 0);
	check(strcmp(s[0] + 3, s[1] + 3) < 0);

	check(strcmp( strcat(strcpy(str, str1), s[3]), s[4]) == 0);

	check(memcmp(strcpy(str, "#####"), s[5], 5) == 0);
	check(memcmp(memset(str, '#', 5), s[5], 5) == 0);

	check(strlen(s[5]) == 5);

	check(memcmp(strncpy(str, s[5], 4), "####", 4) == 0);
	check(memcmp(strncpy(str, s[5], 6), "#####", 5) == 0);
	return 0;
}
