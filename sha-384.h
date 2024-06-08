#ifndef SHA384_H
#define SHA384_H
#include <string>

/**
 * @brief Класс для вычисления хешей SHA-384.
 */
class SHA384
{
protected:
    /**
     * @typedef uint8
     * @brief Тип для представления 8-битного беззнакового целого числа.
     */
    typedef unsigned char uint8;
    
    /**
     * @typedef uint32
     * @brief Тип для представления 32-битного беззнакового целого числа.
     */
    typedef unsigned int uint32;
    
    /**
     * @typedef uint64
     * @brief Тип для представления 64-битного беззнакового целого числа.
     */
    typedef unsigned long long uint64;

    /**
     * @brief Константные значения для SHA-512.
     */
    const static uint64 sha512_k[];

    /**
     * @brief Размер блока SHA-384/512 в байтах.
     */
    static const unsigned int SHA384_512_BLOCK_SIZE = (1024/8);

public:
    /**
     * @brief Инициализация хеш-объекта.
     */
    void init();
    
    /**
     * @brief Обновление состояния хеш-объекта с новым сообщением.
     * @param message Указатель на сообщение.
     * @param len Длина сообщения в байтах.
     */
    void update(const unsigned char *message, unsigned int len);
    
    /**
     * @brief Завершение вычисления хеша и получение результата.
     * @param digest Указатель на массив для хранения результата.
     */
    void final(unsigned char *digest);

    /**
     * @brief Размер хеша в байтах.
     */
    static const unsigned int DIGEST_SIZE = ( 384 / 8);

protected:
    /**
     * @brief Трансформация одного блока сообщения.
     * @param message Указатель на блок сообщения.
     * @param block_nb Номер блока.
     */
    void transform(const unsigned char *message, unsigned int block_nb);
    
    /**
     * @brief Общая длина обработанного сообщения.
     */
    unsigned int m_tot_len;
    
    /**
     * @brief Длина текущего блока сообщения.
     */
    unsigned int m_len;
    
    /**
     * @brief Буфер для хранения блоков сообщения.
     */
    unsigned char m_block[2 * SHA384_512_BLOCK_SIZE];
    
    /**
     * @brief Хеш-состояние.
     */
    uint64 m_h[8];
};

/**
 * @brief Вычисление хеша SHA-384 для строки.
 * @param input Входная строка.
 * @return Строка с хешем.
 */
std::string sha384(std::string input);

#define SHA2_SHFR(x, n)    (x >> n)
/** 
 * @def SHA2_ROTR
 * @brief Циклический сдвиг вправо.
 * @param x Число для сдвига.
 * @param n Количество бит для сдвига.
 */
#define SHA2_ROTR(x, n)   ((x >> n) | (x << ((sizeof(x) << 3) - n)))

/** 
 * @def SHA2_ROTL
 * @brief Циклический сдвиг влево.
 * @param x Число для сдвига.
 * @param n Количество бит для сдвига.
 */
#define SHA2_ROTL(x, n)   ((x << n) | (x >> ((sizeof(x) << 3) - n)))

/** 
 * @def SHA2_CH
 * @brief Вычисление функции выбора.
 * @param x Первый аргумент.
 * @param y Второй аргумент.
 * @param z Третий аргумент.
 */
#define SHA2_CH(x, y, z)  ((x & y) ^ (~x & z))

/** 
 * @def SHA2_MAJ
 * @brief Вычисление функции большинства.
 * @param x Первый аргумент.
 * @param y Второй аргумент.
 * @param z Третий аргумент.
 */
#define SHA2_MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))

/** 
 * @def SHA512_F1
 * @brief Первая функция для SHA-512.
 * @param x Аргумент функции.
 */
#define SHA512_F1(x) (SHA2_ROTR(x, 28) ^ SHA2_ROTR(x, 34) ^ SHA2_ROTR(x, 39))

/** 
 * @def SHA512_F2
 * @brief Вторая функция для SHA-512.
 * @param x Аргумент функции.
 */
#define SHA512_F2(x) (SHA2_ROTR(x, 14) ^ SHA2_ROTR(x, 18) ^ SHA2_ROTR(x, 41))

/** 
 * @def SHA512_F3
 * @brief Третья функция для SHA-512.
 * @param x Аргумент функции.
 */
#define SHA512_F3(x) (SHA2_ROTR(x,  1) ^ SHA2_ROTR(x,  8) ^ SHA2_SHFR(x,  7))

/** 
 * @def SHA512_F4
 * @brief Четвёртая функция для SHA-512.
 * @param x Аргумент функции.
 */
#define SHA512_F4(x) (SHA2_ROTR(x, 19) ^ SHA2_ROTR(x, 61) ^ SHA2_SHFR(x,  6))

/** 
 * @def SHA2_UNPACK32
 * @brief Распаковка 32-битного числа в массив байтов.
 * @param x 32-битное число.
 * @param str Указатель на массив байтов.
 */
#define SHA2_UNPACK32(x, str)                 \
{                                             \
        *((str) + 3) = (uint8) ((x)      );   \
        *((str) + 2) = (uint8) ((x) >>  8);   \
        *((str) + 1) = (uint8) ((x) >> 16);   \
        *((str) + 0) = (uint8) ((x) >> 24);   \
}

/** 
 * @def SHA2_UNPACK64
 * @brief Распаковка 64-битного числа в массив байтов.
 * @param x 64-битное число.
 * @param str Указатель на массив байтов.
 */
#define SHA2_UNPACK64(x, str)                 \
{                                             \
        *((str) + 7) = (uint8) ((x)      );   \
        *((str) + 6) = (uint8) ((x) >>  8);   \
        *((str) + 5) = (uint8) ((x) >> 16);   \
        *((str) + 4) = (uint8) ((x) >> 24);   \
        *((str) + 3) = (uint8) ((x) >> 32);   \
        *((str) + 2) = (uint8) ((x) >> 40);   \
        *((str) + 1) = (uint8) ((x) >> 48);   \
        *((str) + 0) = (uint8) ((x) >> 56);   \
}

/** 
 * @def SHA2_PACK64
 * @brief Упаковка массива байтов в 64-битное число.
 * @param str Указатель на массив байтов.
 * @param x Указатель на 64-битное число.
 */
#define SHA2_PACK64(str, x)                   \
{                                             \
        *(x) =   ((uint64) *((str) + 7)      )    \
          | ((uint64) *((str) + 6) <<  8)    \
          | ((uint64) *((str) + 5) << 16)    \
          | ((uint64) *((str) + 4) << 24)    \
          | ((uint64) *((str) + 3) << 32)    \
          | ((uint64) *((str) + 2) << 40)    \
          | ((uint64) *((str) + 1) << 48)    \
          | ((uint64) *((str) + 0) << 56);   \
}

#endif // SHA384_H
