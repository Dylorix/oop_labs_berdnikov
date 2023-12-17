#include "Keyboard.h"

void Keyboard::pressKey(const std::string& key)
{
    assert(keymap.count(key) && "Нажата неизвестная кнопка");
    history.push_back(key);
    keymap[key].first();
}

void Keyboard::undo()
{
    if (!history.empty())
    {
        keymap[history.back()].second();
        history.pop_back();
    }
}