#include "armadillo.hpp"
#define sign(x) (((x) < 0) ? -1 : ((x) > 0))

using namespace arma;

class LogReg
{
public:
    LogReg();
    void train(mat x, vec y, double alpha);
    int pred(rowvec x);

private:
    colvec w;
    double epsilon = 10e-7;
    double L_2norm = 1.;
};

LogReg::LogReg()
{
}

void LogReg::train(mat x, vec y, double alpha)
{
    // Weight of X
    w = colvec(x.n_cols, fill::zeros);
    for (;;)
    {
        colvec d_loss = colvec(x.n_cols, fill::zeros);
        // Gradient of loss function
        for (int row = 0; row < x.n_rows; row++)
        {
            d_loss += as_scalar(y(row) / (1 + exp(y(row) * (w.t() * x.row(row).t())))) * x.row(row).t();
        }
        d_loss = d_loss / x.n_rows;
        L_2norm = norm(d_loss);
        // Gradient Descent
        w += alpha * d_loss;
        if (L_2norm <= epsilon)
        {
            break;
        }
    }
}

int LogReg::pred(rowvec x)
{
    return sign(as_scalar(w.t() * x.t()));
}

int main(int argc, const char *argv[])
{
    mat X, test;
    vec y;
    X.load("dataX.dat");
    y.load("dataY.dat");
    test.load("dataXtest.dat");
    //test.load("dataX.dat");
    Col<int> labels(test.n_rows);

    LogReg lr = LogReg();
    lr.train(X, y, 0.5);
    for (int row = 0; row < test.n_rows; row++)
    {
        labels(row) = lr.pred(test.row(row));
    }

    labels.save("LogReg.dat", raw_ascii);
    

    return 0;
}