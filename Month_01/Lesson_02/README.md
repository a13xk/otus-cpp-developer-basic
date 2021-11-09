# Задание 2
Настройка локального окружения для дальнейшей работы
Пришла пора подготовить локальный стенд для работы на курсе. 
В самостоятельной работе требуется:
1. настроить любую понравившуюся IDE 
2. добиться сборки приложенных к материалам исходников (`source.zip`)
3. вынести реализацию функции `todo_move_me_out` из файла `hello_world.cpp` в отдельную пару исходников:
   a. `move_me_out.h` – заголовочный файл с объявлением функции
   b. `move_me_out.cpp` – исходный файл с реализацией функции
4. код функции main меняться не должен
5. в файл `hello_world.cpp` добавить  соответствующий `#include`
6. в `CMakeLists.txt` нужно добавить оба созданных файла
7. для сборки использовать CMake
8. выгрузить результат на github.com в свой аккаунт