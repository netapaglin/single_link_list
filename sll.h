#ifndef __SINGLE_LINK_LIST_H__
#define __SINGLE_LINK_LIST_H__
#include "ADTDefs.h"
#include<stdlib.h>

typedef struct Person Person;
struct Person
{
	int m_id; 
	char m_name[128];
	int m_age;
	Person* m_next;
};

Person* ListInsertHead(Person* _head ,Person* _p);
Person* ListRemoveHead(Person* _head, Person** _item);
Person* ListInsertByKey(Person* _head, int _key, Person* _p);
Person* ListInsertByKeyRec(Person* _head, int _key, Person* _p);
Person* ListRemoveByKey(Person* _head, int _key, Person* *_p);
Person* ListRemoveByKeyRec(Person* _head, int _key, Person**_p);
void PrintList(Person* _head);

#endif /* __SINGLE_LINK_LIST_H__*/
