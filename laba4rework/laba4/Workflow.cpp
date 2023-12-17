#include "Workflow.h"

void Workflow::press(const std::string& key)
{
    keyboard.pressKey(key);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Workflow::undo()
{
    keyboard.undo();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Workflow::start()
{
    for (const auto& action : actions)
    {
        action();
    }
}

void Workflow::addAction(const Action& action)
{
    actions.push_back(action);
}