#include <stdio.h>
#include<stdlib.h>
#include "ADTDefs.h"
#include "sll.h"

Person* ListInsertHead(Person* _head ,Person* _p)
{
	if (_p == NULL)
	{
		return _head;
	}
	 _p -> m_next =  _head ;
	return _p;
}

void PrintList(Person* _head)
{
	Person * temp;
	temp = _head;
	if (_head == NULL)
	{
		return;
	}
	do 
	{
	 	printf(" id: %d, name: %s age: %d \n" , temp ->m_id, temp -> m_name , temp -> m_age);
	 	if (temp -> m_next == NULL)
	 	{
	 		return;
	 	}
	 	temp = temp -> m_next;
	}while (temp  != NULL);
}

Person* ListRemoveHead(Person* _head, Person** _item)
{
	if (_head == NULL || _item == NULL)
	{
		return NULL;
	}
	*_item =  _head ;
	return _head -> m_next;
}


Person* ListInsertByKey(Person* _head, int _key, Person* _p)
{
	Person * point1;
	Person * point2;
	if( _p == NULL)
	{
		return _head;
	}
	point1 = _head;
	point2 = _head;
  if (_head == NULL || _key < _head -> m_id)
	{
		 _p -> m_next =  _head ;
		 return _p;
	}
	while (point2 != NULL && _key  > point2-> m_id )
	{
	
		point1 = point2;
		point2 = point2 -> m_next;
		
	}

	if (_key == point2-> m_id)
	{
		return _head;
	}
		_p -> m_next = point2;
		point1 -> m_next = _p;

	return _head;
}

Person* ListInsertByKeyRec(Person* _head, int _key, Person* _p)
{
	Person * lst;
	if( _p == NULL)
	{
		return _head;
	}
	if (_head == NULL || _key < _head-> m_id  )
	{
		_p -> m_next = _head;
		return _p;
	}
	if (_key == _head -> m_id)
	{
		return _head;
	}
	_head -> m_next = ListInsertByKeyRec(_head -> m_next, _key, _p);
	return _head;
}


Person* ListRemoveByKey(Person* _head, int _key, Person* *_p)
{
	Person * point1;
	Person * point2;
	if (_head == NULL || _key == NULL || _p == NULL || _key < _head-> m_id )
	{
		*-P = NULL;
		return _head;
	}
	point1 = _head;
	point2 = _head;
	if (_key == _head-> m_id  )
	{
		
		return _head -> m_next;
	}
	if (_key == _head -> m_id)
	{
		return _head -> m_next;
	}
	while (point2 != NULL && _key < point2-> m_id )
	{
		point1 = point2;
		point2 = point2 -> m_next;
	}
	if (point2 == NULL)
	{
		return _head;
	}
		if (_key == point2-> m_id)
	{
		*-P = point2;
		point1-> m_next = point2 -> m_next;
	}
	
	return _head;
}

Person* ListRemoveByKeyRec(Person* _head, int _key, Person**_p)
{
	if( _p == NULL)
	{
		return _head;
	}
	if( _head== NULL|| _head -> m_id > _key)
	{
		*_p = NULL;
		return _head;
	}
	
	if (_key == _head-> m_id )
	{
	    *_p = _head;
		return _head -> m_next;
	}
	_head -> m_next = ListInsertByKeyRec(_head -> m_next, _key,*_p);
	return _head;
}
/*
Person* ListInsertByKeyRec(Person* _head, int _key, Person* _p)
{
	Person * lst;
	if( _p == NULL)
	{
		return _head;
	}
	if (_head == NULL || _key < _head-> m_id  )
	{
		_p -> m_next = _head;
		return _p;
	}
	if (_key == _head -> m_id)
	{
		return _head;
	}
	_head -> m_next = ListInsertByKeyRec(_head -> m_next, _key, _p);
	return _head;
}*/



