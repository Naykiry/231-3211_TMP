#ifndef CHORDMETHOD_H
#define CHORDMETHOD_H

#include <QString>
#include <functional>
#include <stdexcept>

class ChordMethod
{
public:
    ChordMethod(const QString &function, double x0, double x1, double epsilon, int maxIter);
    double solve();

private:
    QString function;
    double x0;
    double x1;
    double epsilon;
    int maxIter;

    double evaluateFunction(double x);
    std::function<double(double)> parseFunction(const QString &function);

    // Utility functions for parsing
    double parseExpression(const QString &expression, int &pos);
    double parseTerm(const QString &expression, int &pos);
    double parseFactor(const QString &expression, int &pos);
};

#endif // CHORDMETHOD_H
