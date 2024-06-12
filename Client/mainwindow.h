#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

/// Пространство имен для UI компонентов
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief Класс главного окна приложения
 * 
 * Этот класс отвечает за главное окно приложения и содержит слоты для обработки 
 * событий нажатий кнопок.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса MainWindow
     * @param parent Указатель на родительский виджет, по умолчанию nullptr
     */
    MainWindow(QWidget *parent = nullptr);
    
    /// Деструктор класса MainWindow
    ~MainWindow();

private slots:
    /**
     * @brief Слот для обработки нажатия кнопки выхода
     */
    void on_pushButtonExit_clicked();
    
    /**
     * @brief Слот для обработки нажатия кнопки для задачи 3
     */
    void on_pushButtonTask3_clicked();

    /**
     * @brief Слот для обработки нажатия кнопки для задачи 1
     */
    void on_pushButtonTask1_clicked();

    /**
     * @brief Слот для обработки нажатия кнопки для задачи 2
     */
    void on_pushButtonTask2_clicked();

public slots:
    /**
     * @brief Слот для обработки решения
     * @param text Текст решения
     */
    void solution(QString text);

private:
    /// Указатель на пользовательский интерфейс
    Ui::MainWindow *ui;

signals:
    /**
     * @brief Сигнал для задачи 1
     * @param text Текст задачи 1
     */
    void Task1(QString text);
    
    /**
     * @brief Сигнал для задачи 2
     * @param text Текст задачи 2
     */
    void Task2(QString text);
    
    /**
     * @brief Сигнал для задачи 3
     * @param func Функция
     * @param x0 Начальное значение x0
     * @param x1 Начальное значение x1
     * @param epsilon Погрешность
     * @param maxIter Максимальное количество итераций
     */
    void Task3(QString func, QString x0, QString x1, QString epsilon, QString maxIter);
};

#endif // MAINWINDOW_H
