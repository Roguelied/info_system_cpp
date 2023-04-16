#include "Utility.h"
#include "Server.h"
#include "Client.h"
#include "Database.h"
#include "UserInterface.h"

string UserInterface::AdminPsswrd = "admin";

int main() {
    InitializeSettings();

    UserInterface::StartMenu();
    UserInterface::LogMenu();
    UserInterface::MainMenu();
    wait;

    /*
    Booking Booking;
    Booking.SaveCustomer(Booking); */

}

