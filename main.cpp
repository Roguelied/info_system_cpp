#include "Utility.h"
#include "Client.h"
#include "UserInterface.h"

int main() {
    InitializeSettings();
    Client::Initialize();
    UserInterface::StartMenu();
    wait;
}

