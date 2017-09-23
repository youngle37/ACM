#include <stdio.h>

void merge(int *arr, int l, int m, int r) {
    // left and right array length.
    int n1 = m - l + 1;
    int n2 = r - m;

    // create left and right temp array.
    int L[n1], R[n2];

    // copy data to temp array.
    for(int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    // merge temp array back to arr.
    int i = 0;
    int j = 0;
    int k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // copy the remaining elements of L[] and R[]
    while(i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while(j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void merge_sort(int *arr, int l, int r) {
    if(r > l) {
        int m = (r + l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    int *arr = new int [T];

    // reading data
    for(int i = 0; i < T; ++i)
        scanf("%d", &arr[i]);

    // merge sort
    merge_sort(arr, 0, T - 1);

    // print array
    for(int i = 0; i < T; ++i)
        printf("%d ", arr[i]);

    return 0;
}
