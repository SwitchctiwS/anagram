#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define LENGTH 10000

char* read_and_sort_string(unsigned int buffer);
unsigned int find_same_chars(char* arr_a, char* arr_b);
unsigned int deletions(char* arr_a, char* arr_b);
bool binary_search(char* arr, char key, unsigned int min_index, unsigned int max_index);
int compare(const void* a, const void* b);

int main(void) {
    int count;

    char* arr_a = read_and_sort_string(LENGTH);
    char* arr_b = read_and_sort_string(LENGTH);

    count = deletions(arr_a, arr_b);

    printf("%d\n", count);

    return 0;
}

unsigned int deletions(char* arr_a, char* arr_b) {
    unsigned int sum = (unsigned int)strlen(arr_a) + (unsigned int)strlen(arr_b);
    unsigned int same_chars = (strlen(arr_a) < strlen(arr_b)) ? find_same_chars(arr_a, arr_b) : find_same_chars(arr_b, arr_a);
    unsigned int difference = sum - 2 * same_chars;

    return difference;
}

unsigned int find_same_chars(char* arr_a, char* arr_b) {
    unsigned int count = 0;
    unsigned int i;

    for (i = 0; i < (unsigned int)strlen(arr_a); i++) {
        if (binary_search(arr_b, arr_a[i], 0, (unsigned int)strlen(arr_b) - 1)) {
            count++;
        }
    }

    return count;
}

char* read_and_sort_string(unsigned int buffer) {
    unsigned int i;
    char c;
    char* str = malloc(buffer * sizeof *str);

    i = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        str[i++] = c;

        if (i == buffer - 1) {
            while ((c = getchar()) != '\n' && c != EOF);
            break;
        }
    }
    str[i] = '\0';

    qsort(str, strlen(str), sizeof(char), compare);

    return str;
}

int compare(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

bool binary_search(char* arr, char key, unsigned int min_index, unsigned int max_index) {
    unsigned int middle_index;
    bool found_key;

    min_index--;
    max_index++;

    found_key = false;
    while (min_index + 1 != max_index) {
        middle_index = (min_index + max_index) / 2;

        if (key > arr[middle_index]) {
            min_index = middle_index;
        } else if (key < arr[middle_index]) {
            max_index = middle_index;
        } else {
            found_key = true;
            break;
        }
    }

    return found_key;
}
