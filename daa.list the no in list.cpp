#include <stdio.h>
#define MAX_SIZE 100
void insertNumber(int list[], int* size, int position, int number) {
    if (*size >= MAX_SIZE) {
        printf("List is full. Cannot insert more elements.\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        list[i] = list[i - 1];
    }
    list[position] = number;
    (*size)++;
}
void displayList(int list[], int size) {
    printf("List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}
int main() {
    int list[MAX_SIZE] = {2, 4, 5, 6, 7};
    int size = 5;
    int position, number;
    printf("Current list: ");
    displayList(list, size);
    printf("Enter the position to insert the number: ");
    scanf("%d", &position);
    if (position < 0 || position > size) {
        printf("Invalid position.\n");
        return 1;
    }
    printf("Enter the number to insert: ");
    scanf("%d", &number);
    insertNumber(list, &size, position, number);
    printf("Updated list: ");
    displayList(list, size);
    return 0;
}
