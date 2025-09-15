#include"List.h"
ListNodetest1()
{
	LTNode* list=NULL;
	ListInit(&list);
	LTPushback(list,1);
	LTPushback(list, 2);
	LTPushback(list, 3);
	LTprint(list);
	LTpushFront(list, 0);
	LTprint(list);
	LTPopback(list);
	LTprint(list);
	LTPopFront(list);
	LTprint(list);






}



int main()
{
	ListNodetest1();
	return 0;
}