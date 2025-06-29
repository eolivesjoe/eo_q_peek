#include "app/app.h"
#include "logger/logger.h"

int main(int argc, char* argv[]) 
{
    logger::init();

    const char* app_name = (argc > 1) ? argv[1] : nullptr;

    app::App app;
    if (!app.init(app_name)) 
    {
        logger::error("Failed to initialise app.");
        return 1;
    }

    app.run();
    return 0;
}