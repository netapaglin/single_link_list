#include <stdio.h>
#include<stdlib.h>
#include "ADTDefs.h"
#include "sll.h"

void MakeNull( Person * _list , int _size);
void TestInsertToExistList();
void TestInsertFirstTime();
void Print();
void TestRemoveFromHead();
void TestInsertByKeyToMiddle();
void TestInsertByKeyToBegin();
void TestInsertByKeyToEnd();
void TestInsertByKeyToMiddleRec();
void TestInsertByKeyTobeginRec();
void TestInsertByKeyToEndRec();
void TestInsertByKeyDuplicateRec();
void TestRemovetByKeyMiddle();
void TestRemovetByKeyBegin();
void TestRemovetByKeyMiddleRec();
void TestRemovetByKeyEnd();

Person list[5] = { 
	{11 , "Eli" , 30 , NULL},
	{33 , "Neta" , 29 , NULL},
	{55 , "Noga" , 28 , NULL},
	{77 , "Adi" , 27 , NULL},
	{99 , "Roni" , 26 , NULL}
};

int main (void)
{

	Print();
	/*TestInsertFirstTime();
	TestInsertToExistList();
	TestRemoveFromHead();
	TestInsertByKeyToMiddle();
	TestInsertByKeyToBegin();
	TestInsertByKeyToEnd();
	TestInsertByKeyToMiddleRec();
	TestInsertByKeyTobeginRec();
	TestInsertByKeyToEndRec();
	TestInsertByKeyDuplicateRec();
	TestRemovetByKeyMiddle();
	TestRemovetByKeyEnd();
	TestRemovetByKeyBegin();*/
	TestRemovetByKeyMiddleRec();
	
	return ERR_OK;
}

void MakeNull( Person * _list , int _size)
{
	int i;
	if (_size == 0)
	{
		return;
	}
	for (i=0 ; i < _size ; ++i )
	{
		list[i].m_next = NULL;
	}
}

void TestInsertFirstTime()
{
	Person * lst;
	if ( (lst = ListInsertHead(NULL , &list[0])) != NULL)
	{
		printf(" Test first in list     - PASS\n");
	}	else
	{
		printf(" Test first in list     - FAIL\n");
	}
	 MakeNull( list , 5);
}

void TestInsertToExistList()
{
	Person * lst;
	(lst = ListInsertHead(NULL , &list[0]));
		(lst = ListInsertHead(NULL , &list[3]));
	if ((lst = ListInsertHead(lst , &list[1])) != NULL)
	{
		printf(" Test insert head     - PASS\n");
	}	else
	{
		printf(" Test insert head    - FAIL\n");
	}
	 MakeNull( list , 5);

}

void Print()
{
	Person * lst;;
	lst = ListInsertHead(NULL , &list[0]);
	lst = ListInsertHead(lst , &list[1]);
	lst = ListInsertHead(lst, &list[2]);
	/*PrintList(lst);*/
	MakeNull( list , 5);
}

void TestRemoveFromHead()
{
	
	Person *item;
	Person * lst;

	lst = ListInsertHead(NULL , &list[0]);
	lst = ListInsertHead(lst , &list[1]);
	lst = ListInsertHead(lst, &list[2]);
	lst = ListRemoveHead(lst, &item);
	if (lst -> m_id == list[1].m_id)
	{
		printf(" Test remove head     - PASS\n");
	}	else
	{
		printf(" Test remove head    - FAIL\n");
	}

	MakeNull( list , 5);
}


void TestInsertByKeyToMiddle()
{
	Person *item;
	Person * lst;
		printf("**********************\n");
	lst = ListInsertHead(NULL , &list[3]);
	lst = ListInsertHead(lst , &list[1]);
	lst = ListInsertHead(lst, &list[0]);
	PrintList(lst);
	
			printf("**********************\n");
	lst =  ListInsertByKey(lst, 55, &list[2]);
	PrintList(lst);
	if (list[1].m_next == &list[2])
	{
		printf(" Test insert to the middle   - PASS\n");
	}	else
	{
		printf(" Test insert to the middle   - FAIL\n");
	}
	MakeNull( list , 5);
}

void TestInsertByKeyToBegin()
{
	
	Person *item;
	Person * lst;
	/*	printf("**********************\n");*/
	lst = ListInsertHead(NULL , &list[3]);
	lst = ListInsertHead(lst , &list[2]);
	lst = ListInsertHead(lst, &list[1]);
	lst =  ListInsertByKey(lst, 11, &list[0]);
	/*PrintList(lst);*/
	if (list[0].m_next == &list[1])
	{
		printf(" Test insert to the begin   - PASS\n");
	}	else
	{
		printf(" Test insert to the begin   - FAIL\n");
	}
	MakeNull( list , 5);
}

void TestInsertByKeyToEnd()
{
	Person *item;
	Person * lst;
		printf("**********************\n");
	lst = ListInsertHead(NULL , &list[3]);
	lst = ListInsertHead(lst , &list[2]);
	lst = ListInsertHead(lst, &list[1]);
	lst =  ListInsertByKey(lst, 99, &list[4]);
	PrintList(lst);
	if (list[3].m_next == &list[4])
	{
		printf(" Test insert to the end   - PASS\n");
	}	else
	{
		printf(" Test insert to the end   - FAIL\n");
	}
	MakeNull( list , 5);
}

void TestInsertByKeyToMiddleRec()
{

	Person *item;
	Person * lst;
		printf("**********************\n");
	lst = ListInsertHead(NULL , &list[3]);
	lst = ListInsertHead(lst , &list[1]);
	lst = ListInsertHead(lst, &list[0]);
	PrintList(lst);
	printf("**********************\n");
	lst =   ListInsertByKeyRec(lst, 55, &list[2]);
	PrintList(lst);
	if (list[2].m_next == &list[3])
	{
		printf(" Test rec insert to the middle   - PASS\n");
	}	else
	{
		printf(" Test rec insert to the middle   - FAIL\n");
	}
	MakeNull( list , 5);
}

void TestInsertByKeyTobeginRec()
{
	Person *item;
	Person * lst;
	lst = ListInsertHead(NULL , &list[3]);
	lst = ListInsertHead(lst , &list[2]);
	lst = ListInsertHead(lst, &list[1]);
	PrintList(lst);
	lst =   ListInsertByKeyRec(lst, 11, &list[0]);
	if (list[0].m_next == &list[1])
	{
		printf(" Test rec insert to the begin   - PASS\n");
	}	else
	{
		printf(" Test rec insert to the begin   - FAIL\n");
	}
	MakeNull( list , 5);
}

void TestInsertByKeyToEndRec()
{
	Person *item;
	Person * lst;
	lst = ListInsertHead(NULL , &list[3]);
	lst = ListInsertHead(lst , &list[2]);
	lst = ListInsertHead(lst, &list[1]);
	lst =   ListInsertByKeyRec(lst, 99, &list[4]);

	if (list[3].m_next == &list[4])
	{
		printf(" Test rec insert to the end   - PASS\n");
	}	else
	{
		printf(" Test rec insert to the end   - FAIL\n");
	}
	MakeNull( list , 5);
}

void TestInsertByKeyDuplicateRec()
{
	Person *item;
	Person * lst;
	lst = ListInsertHead(NULL , &list[3]);
	lst = ListInsertHead(lst , &list[2]);
	lst = ListInsertHead(lst, &list[1]);
	lst =   ListInsertByKeyRec(lst, 55, &list[2]);
	if (list[2].m_next == &list[3])
	{
		printf(" Test rec insert duplicate   - PASS\n");
	}	else
	{
		printf(" Test rec insert duplicate   - FAIL\n");
	}
	MakeNull( list , 5);
}



void TestRemovetByKeyBegin()
{
	Person * p;
	Person * lst;
		printf("**********************\n");
	lst = ListInsertHead(NULL , &list[3]);
	lst = ListInsertHead(lst , &list[2]);
	lst = ListInsertHead(lst , &list[1]);
	lst = ListInsertHead(lst, &list[0]);
	PrintList(lst);
	
			printf("**********************\n");
	lst = ListRemoveByKey(lst, 11, &p);
	PrintList(lst);
	if (list[1].m_next == &list[2])
	{
		printf(" Test remove from the begin   - PASS\n");
	}	else
	{
		printf(" Test remove from the begin   - FAIL\n");
	}
	MakeNull( list , 5);
}

void TestRemovetByKeyMiddle()
{
	Person * p;
	Person * lst;
		printf("**********************\n");
	lst = ListInsertHead(NULL , &list[3]);
	lst = ListInsertHead(lst , &list[2]);
	lst = ListInsertHead(lst , &list[1]);
	lst = ListInsertHead(lst, &list[0]);
	PrintList(lst);
	
			printf("**********************\n");
	lst = ListRemoveByKey(lst, 55, &p);
	PrintList(lst);
	if (list[1].m_next == &list[3])
	{
		printf(" Test remove from the middle   - PASS\n");
	}	else
	{
		printf(" Test remove from the middle   - FAIL\n");
	}
	MakeNull( list , 5);
}

void TestRemovetByKeyEnd()
{
	Person * p;
	Person * lst;
		printf("**********************\n");
	lst = ListInsertHead(NULL , &list[3]);
	lst = ListInsertHead(lst , &list[2]);
	lst = ListInsertHead(lst , &list[1]);
	lst = ListInsertHead(lst, &list[0]);
	PrintList(lst);
	
			printf("**********************\n");
	lst = ListRemoveByKey(lst, 77, &p);
	PrintList(lst);
	if (list[2].m_next == NULL)
	{
		printf(" Test remove from the end   - PASS\n");
	}	else
	{
		printf(" Test remove from the end   - FAIL\n");
	}
	MakeNull( list , 5);
}

void TestRemovetByKeyMiddleRec()
{
	Person * p;
	Person * lst;
		printf("**********************\n");
	lst = ListInsertHead(NULL , &list[3]);
	lst = ListInsertHead(lst , &list[2]);
	lst = ListInsertHead(lst , &list[1]);
	lst = ListInsertHead(lst, &list[0]);
	PrintList(lst);
	
			printf("**********************\n");
	lst =  ListRemoveByKeyRec(lst, 33, &p);
	PrintList(lst);
	if (list[1].m_next == &list[2])
	{
		printf(" Test  rec remove from the middle   - PASS\n");
	}	else
	{
		printf(" Test  rec remove from the middle   - FAIL\n");
	}
	MakeNull( list , 5);
}



