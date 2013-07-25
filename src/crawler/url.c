#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 1
#define dbg(format, arg...) \
	printf(format, ##arg)

#else

#define dbg(format, arg...)
#endif

#define	MAX_LEN	    (4096)
#define PATH_NAME	"/data-disk/search_engine/download/url.txt"
char buf[MAX_LEN];
char cbuf[MAX_LEN];

int open_file(char *pathname);
int get_one_line(int fd, int cnt);

int main (int argc, char **argv)
{
	int fd;
	int cnt;

	memset(buf, '\0', 4096);
	fd = open_file(PATH_NAME);
	cnt = sprintf(buf, "wget ");
	while ((get_one_line(fd, cnt)) != 0) {
		system(buf);
	}
 
	close(fd);
	return 0;
}


int open_file(char *pathname) {

	int fd;

	if ((fd = open(PATH_NAME, O_RDONLY)) == -1) {
		printf("open error.\n");
		exit(1);
	}
}
#if 0
void wget_web(void)
{
	int cnt;
	int fd;

	fd = open_file(PATH_NAME);

	cnt = sprintf(buf, "wget ");
	while ((get_one_line(fd, cnt)) != 0) {
		system(buf);
	}
}

#endif
int get_one_line(int fd, int cnt)
{
	int i = cnt;
	int ret;
	char ch;

	do {
		ret = read(fd, &ch, 1);

		if (ret == 0){
			dbg("read complete.\n");
			return ret;
		} else if (ret < 0) {
			printf("read fail.\n");
			exit(-1);
		}

		buf[i++] = ch;
		
	} while(ch != '\n');

	buf[i] = '\0';

	return ret;
}
