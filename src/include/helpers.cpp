//
// Created by jakub on 13.03.2026.
//

#include "helpers.h"

void swap(int* arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}