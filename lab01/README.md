# Лабораторна робота № 1

Розгортання середовища розробки та перший проєкт вузла IoT (ESP32, ESP-IDF v6.1, MicroPython, Wokwi, QEMU).

## Структура
- `lab01_hello_node/` — проєкт ESP-IDF мовою C
- `micropython/` — реалізація мовою MicroPython для Wokwi

## Запуск проєкту на C
idf.py set-target esp32
idf.py build
idf.py qemu monitor
