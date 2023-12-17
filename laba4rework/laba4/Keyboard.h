#pragma once

#include <iostream>
#include <functional>
#include <deque>
#include <map>
#include <cassert>
#include <vector>
#include <chrono>
#include <thread>



using Action = std::function<void()>;
using Keymap = std::map<std::string, std::pair<Action, Action>>;

class Keyboard
{
public:
    void regKey(const std::string& key, const Action& action, const Action& undoAction = []() {})
    {
        keymap[key] = { action, undoAction };
    }

    void pressKey(const std::string& key);
    void undo();

private:
    Keymap keymap;
    std::deque<std::string> history;
};

