#include <iostream>
#include <vector>
#include <unordered_map>

unsigned long long merge(std::vector<int>& A, int start, int center, int end) {
    int i = start;
    int j = center;
    int k = 0;
    int size = end - start;
    std::vector<int> A_(size);
    unsigned long long swap = 0;

    while (i < center && j < end) {
        if (A[i] <= A[j]) {
            A_[k++] = A[i++];
        } else {
            A_[k++] = A[j++];
            swap += center - i;
        }
    }

    while (i < center) {
        A_[k++] = A[i++];
    }

    while (j < end) {
        A_[k] = A[j++];
    }

    for (k = 0; k < size; k++)
    {
        A[start + k] = A_[k];
    }
    

    return swap;
}

unsigned long long mergesort(std::vector<int>& A, int start, int end) {
    unsigned long long swap = 0;

    if (end - start > 1) {

    int center = (start + end) / 2;
    swap += mergesort(A, start, center);
    swap += mergesort(A, center, end);
    swap += merge(A, start, center, end);
    }

    return swap;
}

int main() {
    int N;
    std::cin >> N;

    if (N < 0) {
        exit(1);
    }

    std::vector<int> A1(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A1[i];
    }

    std::vector<int> A2(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A2[i];
    }

    std::vector<int> C1(N);
    std::vector<int> C2(N);

    /*int center = N / 2;
    A2.assign(A1.begin() + center, A1.end());
    A1.resize(center);*/

    for (int i = 0; i < N; ++i) {
        C1[A1[i]] = i;
    }

    for (int i = 0; i < N; ++i) {
        C2[i] = C1[A2[i]];
    }

    unsigned long long swap = mergesort(C2, 0, N);

    std::cout << swap << std::endl;

    return 0;
}
