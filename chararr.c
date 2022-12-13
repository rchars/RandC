#include <string.h>
#include <stdlib.h>
#include <stdio.h>


struct MAD_STRING {
	char *mad_ptr;
	int last_index;
	int ready_index;
	int size;
};


struct MAD_STRING init_mad(void) {
	struct MAD_STRING new_mad;
	new_mad.mad_ptr = (char *)malloc(sizeof(char));
	new_mad.ready_index = 0;
	new_mad.last_index = 0;
	new_mad.size = 1;
	return new_mad;
}


void mad_add(struct MAD_STRING *mad, char *new_str) {
	int required_len = strlen(new_str);
	int avaiable_len = mad -> size - mad -> last_index;
	int missing_len = required_len - avaiable_len;
	if(missing_len > 0) {
		mad -> mad_ptr = realloc(mad -> mad_ptr, missing_len * sizeof(char));
		mad -> size += missing_len;
		mad -> last_index = mad -> size - 1;
	}
	for(int i = 0; i < required_len; i++) {
		
	}
	
}


int main(void) {
	struct MAD_STRING mad = init_mad();
	mad_add(&mad, "rrrmrrffarer");
	return EXIT_SUCCESS;
}
