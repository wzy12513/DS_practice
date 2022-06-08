#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

int main() {
	LinkedList* list = create_list();
	/*add_before_head(list, 1);
	add_before_head(list, 2);
	add_before_head(list, 3);
	add_before_head(list, 4);
	add_before_head(list, 5);

	add_behind_rear(list, 6);
	add_behind_rear(list, 7);
	add_behind_rear(list, 8);
	add_behind_rear(list, 9);
	add_behind_rear(list, 10);*/

	add_node(list, 0, 1);
	add_node(list, 0, 2);
	add_node(list, 2, 3);
	add_node(list, 2, 4);

	/*delete_node(list, 2);
	delete_node(list, 2);*/
	
	int i=search_val(list, 2);

	destroy_list(list);

	return 0;
}