#include "ssc.h"


unsigned int id_num = 2;
unsigned int maxid_for_one = 999999;

struct	docID {
	unsigned int	id1;
	unsigned int	id2;
} docID;


void create_docID(unsigned int num);
int main (int argc, char **argv)
{
	create_docID(80808080);
	return 0;
}

void init_docID(void)
{
	docID.id1 = 0;
	docID.id2 = 0;
}

void destory_docID(unsigned int docID)
{
}

void dump_docID(struct docID *pdocID)
{
	printf("%d", pdocID->id2);	
	printf("%d  ", pdocID->id1);	
}

void create_docID(unsigned int id_num)
{
	unsigned int i;
	unsigned int m;
	unsigned int tmp = 0;
	unsigned int id_max = maxid_for_one;

	init_docID();

	for (i = 0; i < id_num; i++){
		if (docID.id1 < id_max){
			docID.id1++;
		} else if (docID.id1 == id_max) {
			if (docID.id2 == id_max) {
				printf("\ndoc ID exceed the limit now.");
				exit(1);
			}
			docID.id2++;
			docID.id1 = 0;	
			tmp = (docID.id2 * (id_max + 1));
		}
		//dump_docID(&docID);
		printf("%d ", (tmp + docID.id1));
	}
}

