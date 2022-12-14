#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;


void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *small, int *large);
void merge_sort(int *array, size_t size);
void top_down_split_merge(int *array_copy, size_t start, size_t end, int *array);
void top_down_merge(int *array, size_t start, size_t mid, size_t end, int *array_copy);
void copy_array(int *array, size_t start, size_t end, int *array_copy);
int max (int *array, size_t size, size_t i, size_t j, size_t k);
void sift_down_heap (int *array, size_t size, size_t i);
void heap_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void hoare_quick_sort(int *array, int start, int end);
int hoare_partition(int *array, int start, int end);





#endif
