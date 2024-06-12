#ifndef SHA384_H
#define SHA384_H

#include <string>

/**
 * @brief Класс для вычисления SHA-384 хэш-функции.
 */
class SHA384
{
protected:
    typedef unsigned char uint8;    /**< Тип для 8-битных беззнаковых целых чисел */
    typedef unsigned int uint32;    /**< Тип для 32-битных беззнаковых целых чисел */
    typedef unsigned long long uint64; /**< Тип для 64-битных беззнаковых целых чисел */

    /**
     * @brief Массив констант для SHA-512.
     */
    const static uint64 sha512_k[];

    /**
     * @brief Размер блока SHA-384/SHA-512 в байтах.
     */
    static const unsigned int SHA384_512_BLOCK_SIZE = (1024 / 8);

public:
    /**
     * @brief Инициализирует контекст SHA-384.
     */
    void init();

    /**
     * @brief Обновляет контекст с новым сообщением.
     * @param message Сообщение для обновления.
     * @param len Длина сообщения.
     */
    void update(const unsigned char *message, unsigned int len);

    /**
     * @brief Завершает хэширование и формирует итоговый хэш.
     * @param digest Массив для хранения итогового хэша.
     */
    void final(unsigned char *digest);

    /**
     * @brief Размер итогового хэша в байтах.
     */
    static const unsigned int DIGEST_SIZE = (384 / 8);

protected:
    /**
     * @brief Трансформирует блок данных.
     * @param message Сообщение для трансформации.
     * @param block_nb Количество блоков.
     */
    void transform(const unsigned char *message, unsigned int block_nb);

    unsigned int m_tot_len;  /**< Общая длина обработанного сообщения */
    unsigned int m_len;      /**< Длина текущего блока */
    unsigned char m_block[2 * SHA384_512_BLOCK_SIZE]; /**< Блок данных для хэширования */
    uint64 m_h[8];           /**< Промежуточные хэш-значения */
};

/**
 * @brief Функция для вычисления SHA-384 хэша строки.
 * @param input Входная строка.
 * @return Хэш в виде строки.
 */
std::string sha384(std::string input);

#define SHA2_SHFR(x, n)    (x >> n) /**< Циклический сдвиг вправо */
#define SHA2_ROTR(x, n)   ((x >> n) | (x << ((sizeof(x) << 3) - n))) /**< Вращение вправо */
#define SHA2_ROTL(x, n)   ((x << n) | (x >> ((sizeof(x) << 3) - n))) /**< Вращение влево */
#define SHA2_CH(x, y, z)  ((x & y) ^ (~x & z)) /**< Выборочная функция SHA */
#define SHA2_MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z)) /**< Мажоритарная функция SHA */
#define SHA512_F1(x) (SHA2_ROTR(x, 28) ^ SHA2_ROTR(x, 34) ^ SHA2_ROTR(x, 39)) /**< Функция SHA-512 */
#define SHA512_F2(x) (SHA2_ROTR(x, 14) ^ SHA2_ROTR(x, 18) ^ SHA2_ROTR(x, 41)) /**< Функция SHA-512 */
#define SHA512_F3(x) (SHA2_ROTR(x,  1) ^ SHA2_ROTR(x,  8) ^ SHA2_SHFR(x,  7)) /**< Функция SHA-512 */
#define SHA512_F4(x) (SHA2_ROTR(x, 19) ^ SHA2_ROTR(x, 61) ^ SHA2_SHFR(x,  6)) /**< Функция SHA-512 */

#define SHA2_UNPACK32(x, str)                 \
{                                             \
        *((str) + 3) = (uint8) ((x)      );   \
        *((str) + 2) = (uint8) ((x) >>  8);   \
        *((str) + 1) = (uint8) ((x) >> 16);   \
        *((str) + 0) = (uint8) ((x) >> 24);   \
} /**< Распаковка 32-битного числа в массив байтов */

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
} /**< Распаковка 64-битного числа в массив байтов */

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
} /**< Упаковка массива байтов в 64-битное число */

#endif

