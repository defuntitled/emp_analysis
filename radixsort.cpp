#include <fstream>
#include <time.h>
#include <iostream>

void LSD_sort(int *&indexes, int *&indexes_tmp, int indexes_sz, int m, int k,
              char **strs) {
    const int sz_count = 256;
    int count[sz_count];
    for (int i = 0; i < k; ++i) {
        int mm = m - i - 1;
        for (int & j : count)
            j = 0;
        for (int j = 0; j < indexes_sz; ++j)
            ++count[strs[indexes[j]][mm]];

        int offset = 0, tmp = 0;
        for (int &j: count) {
            tmp = j;
            j = offset;
            offset += tmp;
        }

        for (int j = 0; j < indexes_sz; ++j) {
            indexes_tmp[count[strs[indexes[j]][mm]]] = indexes[j];
            ++count[strs[indexes[j]][mm]];
        }

        std::swap(indexes, indexes_tmp);
    }
}

int main(int argc, char *argv[]) {
    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);
    int n, m, k;
    fin >> n >> m >> k;
    int *indexes = new int[n];
    int *indexes_tmp = new int[n];
    for (int i = 0; i < n; ++i)
        indexes[i] = i;

    auto **strs = new char *[n];
    for (int i = 0; i < n; ++i)
        strs[i] = new char[m];

    for (int j = 0; j < m; ++j)
        for (int i = 0; i < n; ++i)
            fin >> strs[i][j];
    auto time_before = clock();
    LSD_sort(indexes, indexes_tmp, n, m, k, strs);
    auto time_after = clock();
    auto result = (double)(time_after-time_before)/CLOCKS_PER_SEC;
    for (int i = 0; i < n; ++i)
        fout << strs[indexes[i]][0];

    delete[] indexes;
    delete[] indexes_tmp;
    for (int i = 0; i < n; ++i)
        delete[] strs[i];
    delete[] strs;
    fin.close();
    fout.close();
    std::cout<<result;
    return 0;
}

