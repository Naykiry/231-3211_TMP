#include "chordmethod.h"
#include <QtMath>
#include <cmath>
#include <stdexcept>

ChordMethod::ChordMethod(const QString &function, double x0, double x1, double epsilon, int maxIter)
    : function(function), x0(x0), x1(x1), epsilon(epsilon), maxIter(maxIter) {}

double ChordMethod::solve()
{
    std::function<double(double)> f = parseFunction(function);
    double f_x0 = f(x0);
    double f_x1 = f(x1);

    if (qAbs(f_x0) < epsilon) return x0;
    if (qAbs(f_x1) < epsilon) return x1;

    int iter = 0;
    while (iter < maxIter) {
        double x2 = x1 - f_x1 * (x1 - x0) / (f_x1 - f_x0);
        double f_x2 = f(x2);

        if (qAbs(f_x2) < epsilon) return x2;

        x0 = x1;
        f_x0 = f_x1;
        x1 = x2;
        f_x1 = f_x2;

        iter++;
    }

    throw std::runtime_error("Max iterations reached without convergence");
}

double ChordMethod::evaluateFunction(double x)
{
    // Dummy implementation; will be replaced by parseFunction
    return 0.0;
}

std::function<double(double)> ChordMethod::parseFunction(const QString &function)
{
    return [function, this](double x) -> double {
        QString expr = function;
        expr.replace("x", QString::number(x));

        int pos = 0;
        return parseExpression(expr, pos);
    };
}

double ChordMethod::parseExpression(const QString &expression, int &pos)
{
    double result = parseTerm(expression, pos);

    while (pos < expression.length()) {
        QChar op = expression[pos];
        if (op == '+' || op == '-') {
            ++pos;
            double term = parseTerm(expression, pos);
            if (op == '+') {
                result += term;
            } else {
                result -= term;
            }
        } else {
            break;
        }
    }

    return result;
}

double ChordMethod::parseTerm(const QString &expression, int &pos)
{
    double result = parseFactor(expression, pos);

    while (pos < expression.length()) {
        QChar op = expression[pos];
        if (op == '*' || op == '/') {
            ++pos;
            double factor = parseFactor(expression, pos);
            if (op == '*') {
                result *= factor;
            } else {
                result /= factor;
            }
        } else {
            break;
        }
    }

    return result;
}

double ChordMethod::parseFactor(const QString &expression, int &pos)
{
    double result;
    bool negative = false;

    if (expression[pos] == '-') {
        negative = true;
        ++pos;
    }

    if (expression[pos] == '(') {
        ++pos; // Skip '('
        result = parseExpression(expression, pos);
        if (expression[pos] == ')') {
            ++pos; // Skip ')'
        }
    } else {
        int startPos = pos;
        while (pos < expression.length() && (expression[pos].isDigit() || expression[pos] == '.')) {
            ++pos;
        }
        result = expression.mid(startPos, pos - startPos).toDouble();
    }

    if (negative) {
        result = -result;
    }

    return result;
}
