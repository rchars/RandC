#include <limits.h>
#include <stdlib.h>
#include <stdio.h>


struct dyn {
	int current_size;
	int ready_index;
	int *arr_ptr;
};


struct dyn init_dyn(void) {
	struct dyn new_dyn;
	new_dyn.arr_ptr = (int *)malloc(sizeof(int));
	new_dyn.current_size = 1;
	new_dyn.ready_index = 0;
	return new_dyn;
}


void add_dyn(struct dyn *valid_dyn, int new_elem) {
	if(valid_dyn -> current_size == valid_dyn -> ready_index) {
		valid_dyn -> current_size += 1;
		valid_dyn -> arr_ptr = (int *)realloc(
		valid_dyn -> arr_ptr, valid_dyn -> current_size * sizeof(int));
	}
	valid_dyn -> arr_ptr[valid_dyn -> ready_index] = new_elem;
	valid_dyn -> ready_index += 1;
}


void remove_dyn(struct dyn *valid_dyn) {
	if(valid_dyn -> current_size > 0) {
		valid_dyn -> arr_ptr[valid_dyn -> ready_index - 1] = 0;
		valid_dyn -> current_size -= 1;
		valid_dyn -> ready_index -= 1;
	}
}


void del_dyn(struct dyn *valid_dyn) {
	free(valid_dyn -> arr_ptr);
}


int get_elem(struct dyn *valid_dyn, int index, int *result) {
	int err = 0;
	if(0 <= index <= valid_dyn -> ready_index) }
		result = &valid_dyn -> arr_ptr[index];
	}
	else {
		err = -1;
	}
	return err
}


int main(void) {
	struct dyn new_dyn = init_dyn();
	printf("%d\n", new_dyn.arr_ptr[0]);
	add_dyn(&new_dyn, 414);
	printf("%d\n", new_dyn.arr_ptr[0]);
	add_dyn(&new_dyn, 555);
	printf("%d\n", new_dyn.arr_ptr[1]);
	add_dyn(&new_dyn, INT_MAX);
	printf("%d\n", new_dyn.arr_ptr[2]);
	remove_dyn(&new_dyn);
	printf("%d\n", new_dyn.arr_ptr[2]);
	free(new_dyn);
	return 0;
}
