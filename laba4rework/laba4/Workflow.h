#pragma once

#include "Keyboard.h"

class Workflow
{
public:
    explicit Workflow(Keyboard& keyboard) : keyboard(keyboard) {}
    
    void addAction(const Action& action);
    void start();

    void press(const std::string& key);
    void undo();

private:
    Keyboard& keyboard;
    std::vector<Action> actions;
};
