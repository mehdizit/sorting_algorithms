#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	int m;
	listint_t *cur;
	cur=*list;
	if (cur->next==NULL)
		return;
	
	listint_t *ptr,*tmp;
	cur=cur->next;

	while(cur!=NULL)
	{
		m=0;
		ptr=cur;
		tmp=cur->prev;
		cur=cur->next;

		while (tmp!=NULL && tmp->n>ptr->n)
		{
			m++;
			tmp=tmp->prev;
		}

		if (m)
		{
			
			ptr->prev->next=ptr->next;
			if (ptr->next!=NULL)
			ptr->next->prev=ptr->prev;
	
			if (tmp==NULL)
			{
				tmp=*list;
				ptr->prev=NULL;
				ptr->next=tmp;
				ptr->next->prev=ptr;
				*list=ptr;
			
			}
			
			else
			{
				tmp=tmp->next;
				tmp->prev->next=ptr;
				ptr->prev=tmp->prev;
				tmp->prev=ptr;
				ptr->next=tmp;
			
			
			}
			/*print_list(*list);*/
			
		}
		print_list(*list);


	}

}
