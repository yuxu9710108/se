#include </data-disk/ssc/se/src/inverted-index/ssc.h>

#define TEST_DATA	"/data-disk/ssc/se/src/sort/data"
#define MAX_ID_VAL	1024

unsigned int total_num;
unsigned int id_val;
unsigned buf[MAX_ID_VAL];

static void __quick_sort(unsigned int num[], int l, int r)
{
	unsigned int key;
	int low;
	int high;
	if (l < r) {
		int key = num[l];
		int low = l;
		int high = r;
		while (low < high) {
			while (low < high && num[high] >= key) {
				high--;
			}
			if (low < high)
				num[low++] = num[high];

			while (low < high && num[low] < key) {
				low++;
			}

			if (low < high)
				num[high--] = num[low];
		}
		num[low] = key;
		__quick_sort(num, l, low-1);
		__quick_sort(num, low+1, r);
	}

}

void quick_sort(void)
{
	__quick_sort(buf, 0, total_num - 1);
}

void merge_sort(void)
{
	//__merge_sort()
}

void insert_sort(void)
{
	//__insert_sort()
}

void heap_sort(void)
{
	//__heap_sort()
}

void shell_sort(void)
{
	//__shell_sort()
}


void print_result(const char *sorttype)
{
	int i = 0;

	printf("\n%s Result: \n", sorttype);	
	while(buf[i] != '\0') {
		printf("%d ", buf[i]);
		i++;
	}
	printf("\n\n");
}

void quick_test(void)
{
	quick_sort();
	print_result("Quick Sort ");
}


int open_file(char *pathname)
{
	int fd;

	if ((fd = open(TEST_DATA, O_RDONLY)) == -1) {
		printf("open error.\n");
		exit(1);
	}

	return fd;
}

//把一个字符转化为相应的十进制
static int str_to_dec(char c)
{
	return (c - '0');
}

int read_one_number(int fd, int *pdata)
{
	int i = 0;
	int val = 0;
	int ret;
	char ch;
	unsigned int d;

	do {
		ret = read(fd, &ch, 1);
		if (-1 == ret) {
			printf("read error.\n");
			exit(-1);
		} else if (0 == ret)
			break;

		if (ch != ' ' && ch != '\n' && ch != '	')
			d = str_to_dec(ch);
		else
			break;

		val = (10 * val) + d;
	} while(ret != 0);

	*pdata = val;
	return ret;
}	


//把文件中的数据读入数组中
void read_data(char *fname)
{
	int i = 0;
	int fd;

	fd = open_file(fname);
	while (read_one_number(fd, &id_val) != 0) {
		buf[i] = id_val; 
		i++;
	}
	total_num = i;
	printf("total numbers : %d\n", total_num);
}


void binary_search(unsigned int num[], unsigned int total)
{
	unsigned int n;
	int low = 0;
	int mid;
	int high = total - 1;
	int found = 0; 

	printf("\nSearch: ");
	scanf("%d", &n);
	printf("\n");

	while (low <= high) {
		mid = (high + low)/2;

		if (n == num[mid]) {
			found = 1;
			break;
		} else if (n > num[mid]) 
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (found == 1)
		printf("Find %d in buf[%d].\n", n, mid);
	else
		printf("NO number %d found.\n", n);
}

//val_id要大于0
int main(int argc, char **argv)
{
	char c;

	read_data(TEST_DATA);
	
	quick_test();

	c = getchar();
	while (c != 'q') {
		binary_search(buf, total_num - 1);
		c = getchar();
	}

	return 0;
}
