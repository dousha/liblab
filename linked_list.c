//
// Created by dousha on 17-10-14.
//

#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"

/**
 * @brief Get the n-th node of a linked list.
 * @details If n is greater than total list size, NULL will be returned.
 * @param link Linked list
 * @param n Index
 * @return Desired node. NULL if the node does not exist.
 */
const linked_list_t* linked_list_get(const linked_list_t* link, size_t n){
	size_t i = n;
	linked_list_t* now = link;
	while(i-->0){
		if(now->next == NULL){
			return NULL;
		}
		now = now->next;
	}
	return now;
}

/**
 * @brief Set the n-th node of a linked list.
 * @details If n == 0 or is greater than total list size, nothing is changed.
 * @param dest Target list
 * @param node Node
 * @param n Index
 */
void linked_list_set(linked_list_t* dest, linked_list_t* node, size_t n){
	if(n == 0) return;
	size_t i = n;
	linked_list_t *prev = dest, *next = dest->next;
	while(--i>0){
		if(next->next == NULL){
			return;
		}
		prev = next;
		next = next->next;
	}
	free(next->content);
	prev->next = node;
	node->next = next->next;
	free(next);
}

void linked_list_append(linked_list_t* list, void* content){
	linked_list_t* now = list;
	while(now->next != NULL){
		now = now->next;
	}
	now->next = (linked_list_t*) malloc(sizeof(linked_list_t));
	now->next->content = content;
	now->next->next = NULL;
}

void linked_list_insert(linked_list_t* list, void* content, size_t n){

}

void linked_list_remove(linked_list_t* list, size_t n){
	assert(n > 0);
}

const linked_list_t* linked_list_remove_first(linked_list_t* list){
	linked_list_t* node = list->next;
	free(list->content);
	free(list);
	return node;
}

void linked_list_remove_last(linked_list_t* list){
	linked_list_t *prev = list, *now = list;
	while(now->next != NULL){
		prev = now;
		now = now->next;
	}
	prev->next = NULL;
	free(now->content);
	free(now);
}

/**
 * @brief Concatenate two linked lists
 * @param dest Destination list
 * @param src Source list
 */
void linked_list_concat(linked_list_t*restrict dest, linked_list_t*restrict src){
	linked_list_t* now = dest;
	while(now->next != NULL){
		now = now->next;
	}
	now->next = src;
}

/**
 * @brief Splits a linked list.
 * @param list Self-explaining
 * @param n Index
 * @return The latter head of list
 */
const linked_list_t* linked_list_split(linked_list_t* list, size_t n){

}

/**
 * @brief Reverses a linked list.
 * @param list Self-explaining.
 * @return New head.
 */
linked_list_t* linked_list_reverse(linked_list_t* list){

}

uint8_t linked_list_is_closed(linked_list_t* list){
	linked_list_t *slower = list, *faster = list;
	for(;;){
		if(slower->next == NULL) return 0;
		if(faster->next == NULL) return 0;
		slower = slower->next;
		faster = faster->next;
		if(faster->next == NULL) return 0;
		if(faster == slower) return 1;
		faster = faster->next;
		if(faster == slower) return 1;
	}
}