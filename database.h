#ifndef DATABASE_H
#define DATABASE_H

#include <QCoreApplication>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>
#include <QStringList>

class DataBase;

/**
 * @brief Класс, ответственный за уничтожение объекта DataBase.
 */
class DatabaseDestroyer
{
private:
    DataBase * p_instance; ///< Указатель на экземпляр DataBase.
public:
    /**
     * @brief Деструктор, уничтожает экземпляр DataBase.
     */
    ~DatabaseDestroyer();
    
    /**
     * @brief Инициализирует указатель на экземпляр DataBase.
     * @param p Указатель на экземпляр DataBase.
     */
    void initialize(DataBase * p);
};

/**
 * @brief Класс, реализующий паттерн Singleton для управления базой данных.
 */
class DataBase {
private:
    static DataBase *p_instance; ///< Указатель на единственный экземпляр DataBase.
    static DatabaseDestroyer destroyer; ///< Объект, ответственный за уничтожение экземпляра DataBase.
    QSqlDatabase db; ///< Объект базы данных.
    
    /**
     * @brief Приватный конструктор, чтобы предотвратить создание объектов извне.
     */
    DataBase();
    
    /**
     * @brief Приватный деструктор, чтобы предотвратить уничтожение объектов извне.
     */
    ~DataBase();
    
    /**
     * @brief Удалённый конструктор копирования.
     */
    DataBase(const DataBase&) = delete;
    
    /**
     * @brief Удалённый оператор присваивания.
     */
    void operator= (const DataBase&) = delete;
    
    /**
     * @brief Класс DatabaseDestroyer является другом для доступа к приватным членам.
     */
    friend class DatabaseDestroyer;

public:
    /**
     * @brief Создаёт таблицу в базе данных.
     * @return true, если таблица успешно создана, иначе false.
     */
    bool createTable();
    
    /**
     * @brief Возвращает единственный экземпляр DataBase.
     * @return Ссылка на экземпляр DataBase.
     */
    static DataBase& getInstance();
    
    /**
     * @brief Возвращает объект базы данных.
     * @return Ссылка на объект QSqlDatabase.
     */
    QSqlDatabase& getDatabase();
    
    /**
     * @brief Выполняет запрос к базе данных.
     * @param query Список строк, представляющих запрос.
     * @return Список строк с результатами запроса.
     */
    QStringList queryToDatabase(QStringList);
};

#endif
