#include<stdio.h>
#include<stdlib.h>
#include"hashmap.h"

int main() {
	HashMap* map = HashMap_create();

	HashMap_put(map, "abcd ", 18);


	return 0;
}