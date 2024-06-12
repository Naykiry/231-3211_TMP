#ifndef CHORDMETHOD_H
#define CHORDMETHOD_H

#include <QString>
#include <functional>
#include <stdexcept>

/**
 * @class ChordMethod
 * @brief Класс для решения уравнений методом хорд.
 * 
 * Этот класс реализует метод хорд для численного решения уравнений вида f(x) = 0.
 */
class ChordMethod
{
public:
    /**
     * @brief Конструктор класса ChordMethod.
     * 
     * @param function Строка, содержащая математическое выражение функции.
     * @param x0 Начальное приближение x0.
     * @param x1 Начальное приближение x1.
     * @param epsilon Точность решения.
     * @param maxIter Максимальное количество итераций.
     */
    ChordMethod(const QString &function, double x0, double x1, double epsilon, int maxIter);

    /**
     * @brief Решает уравнение методом хорд.
     * 
     * @return Значение x, при котором f(x) приближается к нулю.
     * 
     * @throws std::runtime_error Если не удается достичь необходимой точности за заданное количество итераций.
     */
    double solve();

private:
    QString function; ///< Математическое выражение функции.
    double x0; ///< Начальное приближение x0.
    double x1; ///< Начальное приближение x1.
    double epsilon; ///< Точность решения.
    int maxIter; ///< Максимальное количество итераций.

    /**
     * @brief Вычисляет значение функции в точке x.
     * 
     * @param x Значение аргумента, в котором вычисляется функция.
     * @return Значение функции в точке x.
     */
    double evaluateFunction(double x);

    /**
     * @brief Парсит строку с математическим выражением в функцию.
     * 
     * @param function Строка с математическим выражением.
     * @return Функция, вычисляющая значение выражения.
     */
    std::function<double(double)> parseFunction(const QString &function);

    /**
     * @brief Парсит математическое выражение.
     * 
     * @param expression Строка с математическим выражением.
     * @param pos Текущая позиция в строке.
     * @return Значение выражения.
     */
    double parseExpression(const QString &expression, int &pos);

    /**
     * @brief Парсит член математического выражения.
     * 
     * @param expression Строка с математическим выражением.
     * @param pos Текущая позиция в строке.
     * @return Значение члена.
     */
    double parseTerm(const QString &expression, int &pos);

    /**
     * @brief Парсит множитель математического выражения.
     * 
     * @param expression Строка с математическим выражением.
     * @param pos Текущая позиция в строке.
     * @return Значение множителя.
     */
    double parseFactor(const QString &expression, int &pos);
};

#endif // CHORDMETHOD_H

