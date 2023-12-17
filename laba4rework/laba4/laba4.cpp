#include "Workflow.h"
#include "Keyboard.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    Keyboard keyboard;
    keyboard.regKey("A", []() { std::cout << "Нажали A\n"; }, []() { std::cout << "Отжали A\n"; });
    keyboard.regKey("Alt+F4", []() { std::cout << "Закрыли приложение\n"; }, []() { std::cout << "Обратно открыли приложение\n"; });

    Workflow workflow(keyboard);
    workflow.addAction([&]() { workflow.press("A"); });
    workflow.addAction([&]() { workflow.press("Alt+F4"); });
    workflow.addAction([&]() { workflow.undo(); });
    workflow.addAction([&]() { workflow.undo(); });

    workflow.start();
    std::cout << "\n";

    keyboard.regKey("A", []() { std::cout << "Нажали B\n"; }, []() { std::cout << "Отжали B\n"; });
    keyboard.regKey("Alt+F4", []() { std::cout << "Теперь это сочетание сдаёт лабораторную\n"; }, []() { std::cout << "Больше не сдаёт\n"; });

    workflow.start();

    return 0;
}
