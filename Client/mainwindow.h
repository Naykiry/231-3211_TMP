#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief Класс MainWindow представляет главное окно приложения.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса MainWindow.
     * @param parent Родительский виджет.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса MainWindow.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Слот, вызываемый при нажатии на кнопку выхода.
     */
    void on_pushButtonExit_clicked();

    /**
     * @brief Слот, вызываемый при нажатии на кнопку задачи 3.
     */
    void on_pushButtonTask3_clicked();

    /**
     * @brief Слот, вызываемый при нажатии на кнопку задачи 1.
     */
    void on_pushButtonTask1_clicked();

    /**
     * @brief Слот, вызываемый при нажатии на кнопку задачи 2.
     */
    void on_pushButtonTask2_clicked();

public slots:
    /**
     * @brief Обработка решения.
     * @param text Текст решения.
     */
    void solution(QString text);

private:
    Ui::MainWindow *ui; ///< Указатель на интерфейсное представление главного окна.

signals:
    /**
     * @brief Сигнал для задачи 1.
     * @param text Текст сообщения.
     */
    void Task1(QString text);

    /**
     * @brief Сигнал для задачи 2.
     * @param text Текст сообщения.
     */
    void Task2(QString text);

    /**
     * @brief Сигнал для задачи 3.
     * @param func Функция.
     * @param x0 Начальная точка x0.
     * @param x1 Начальная точка x1.
     * @param epsilon Точность.
     * @param maxIter Максимальное количество итераций.
     */
    void Task3(QString func, QString x0, QString x1, QString epsilon, QString maxIter);
};

#endif // MAINWINDOW_H

