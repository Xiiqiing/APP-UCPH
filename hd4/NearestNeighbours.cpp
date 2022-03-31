#include "armadillo.hpp"

using namespace arma;

colvec eucldist(mat A, rowvec B);
int KNN(mat X, mat y, mat test, int rwo, int k);

int main(int argc, const char *argv[])
{
    // Load files
    mat X, y, test;
    X.load("dataX.dat");
    y.load("dataY.dat");
    test.load("dataXtest.dat");
    // Store labels
    Col<int> labels(test.n_rows);
    // 5-NN
    for (int row = 0; row < test.n_rows; row++)
    {
        labels(row) = KNN(X, y, test, row, 5);
    }
    // Write labels
    labels.save("NN.dat", raw_ascii);

    return 0;
}

colvec eucldist(mat A, rowvec B)
{
    mat diff = A.each_row() - B;
    mat sqdiff = pow(diff, 2);
    return sqrt(sum(sqdiff, 1));
}

int KNN(mat X, mat y, mat test, int row, int k)
{
    // Calc diatence
    colvec dist = eucldist(X, test.row(row));
    // Sort, ascend
    uvec sorted_rank = sort_index(dist);
    // Majority vote
    uvec count = zeros<uvec>(2);
    for (int i = 0; i < k; i++)
    {
        int label = y(sorted_rank(i));
        if (label == -1)
        {
            label = 0;
        }
        count(label) += 1;
    }
    int res = count.index_max();
    if (res == 0)
    {
        res = -1;
    }
    return res;
}
