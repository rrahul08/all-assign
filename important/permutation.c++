#include <iostream>
#include <algorithm>
using namespace std;

void nextGreaterPermutation(int A[], int n) {
    int index = -1;

    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        reverse(A, A + n);
        return;
    }

    for (int i = n - 1; i > index; i--) {
        if (A[i] > A[index]) {
            swap(A[i], A[index]);
            break;
        }
    }

    reverse(A + index + 1, A + n);
}

int main() {
    int A[] = {2, 1, 5, 4, 3, 0, 0};
    int size = sizeof(A) / sizeof(A[0]);

    nextGreaterPermutation(A, size);

    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }

    return 0;
}
