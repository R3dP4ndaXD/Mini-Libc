#include <internal/io.h>
#include <string.h>

int puts(const char *s)
{
	int ret = write(1, s, strlen(s));
	if (ret < 0) {
		return -1;
	}
	ret = write(1, "\n", 1);
	if (ret < 0) {
		return -1;
	}
	return 1;
}
