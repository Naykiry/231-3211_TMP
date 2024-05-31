# Используем базовый образ Ubuntu
FROM ubuntu:latest

# Устанавливаем необходимые зависимости
RUN apt-get update \
    && apt-get install -y \
        build-essential \
        qtbase5-dev \
    && rm -rf /var/lib/apt/lists/*

# Устанавливаем рабочую директорию
WORKDIR /app

# Копируем все файлы в рабочую директорию
COPY . .

# Компиляция сервера
RUN qmake && make

# Открываем порт для сервера
EXPOSE 33333

# Команда для запуска сервера
CMD ["./TCPserver"]