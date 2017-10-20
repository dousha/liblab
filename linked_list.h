#ifndef LIBLAB_LINKED_LIST_H
#define LIBLAB_LINKED_LIST_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Linked list
 * @details Content is stored as a void*, you will have to cast it all the time.
 * It's a single-way implementation. For duo-way implementation, see chain_list_t.
 * @see chain_list_t
 */
typedef
struct linked_list{
	void* content;
	struct linked_list* next;
}
linked_list_t;

/**
 * @brief Chained list
 * @details Content is stored as a void*, you will have to cast it all the time.
 * It's a duo-way implementation. For single-way implementation, see linked_list_t.
 * @see linked_list_t
 */
typedef
struct chain_list{
	void* content;
	struct chain_list* prev;
	struct chain_list* next;
}
chain_list_t;

extern const linked_list_t* linked_list_get(const linked_list_t*, size_t);
extern void linked_list_set(linked_list_t*, linked_list_t*, size_t);
extern void linked_list_append(linked_list_t*, void*);
extern void linked_list_insert(linked_list_t*, void*, size_t);
extern void linked_list_remove(linked_list_t*, size_t);
extern const linked_list_t* linked_list_remove_first(linked_list_t*);
extern void linked_list_remove_last(linked_list_t*);
extern void linked_list_concat(linked_list_t*restrict, linked_list_t*restrict);
extern const linked_list_t* linked_list_split(linked_list_t*, size_t);
extern linked_list_t* linked_list_reverse(linked_list_t*);
extern uint8_t linked_list_is_closed(linked_list_t*);

#endif //LIBLAB_LINKED_LIST_H
