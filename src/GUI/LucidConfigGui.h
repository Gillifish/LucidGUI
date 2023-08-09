#pragma once

#include <iostream>
#include <App.h>
#include <AccountManager.h>

class LucidConfigGui : public App
{
    // Function for registering keyboard actions
    void actionRegistry();

    void sImGui();
    void sDoAction(const Action &action);

public:
    LucidConfigGui(float x, float y, std::string title, float fr);
};