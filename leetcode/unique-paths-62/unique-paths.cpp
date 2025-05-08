#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 40; // can go higher if needed

vector<vector<long long>> pascal;

void buildPascal()
{
    pascal.assign(MAX_N + 1, vector<long long>(MAX_N + 1, 0));
    pascal[0][0] = 1;
    for (int n = 1; n <= MAX_N; ++n)
    {
        pascal[n][0] = pascal[n][n] = 1;
        for (int k = 1; k < n; ++k)
        {
            pascal[n][k] = pascal[n - 1][k - 1] + pascal[n - 1][k];
        }
    }
}

long long countPaths(int M, int N)
{
    int totalMoves = M + N - 2;
    int downMoves = M - 1;
    return pascal[totalMoves][downMoves];
}

int main()
{
    buildPascal();

    int M = 7, N = 3;
    cout << "Paths in " << M << "x" << N << " grid: "
         << countPaths(M, N) << endl;

    return 0;
}