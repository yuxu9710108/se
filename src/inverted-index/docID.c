#include "ssc.h"

unsigned int cur_id;

struct	docID {
	unsigned int	id1;
	unsigned int	id2;
} docID;


void create_docID(unsigned int num);
int main (int argc, char **argv)
{
	create_docID(99);
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

	init_docID();

	for (i = 0; i < id_num; i++){
		if (docID.id1 < 9){
			docID.id1++;
		} else if (docID.id1 == 9) {
			docID.id2++;
			docID.id1 = 0;	
		}
		dump_docID(&docID);
	}
}

