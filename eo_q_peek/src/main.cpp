#include "app.h"
#include "logger.h"

int main(int argc, char* argv[]) 
{
    logger::init();

    const char* appName = (argc > 1) ? argv[1] : nullptr;

    app::App app;
    if (!app.init(appName)) 
    {
        logger::error("Failed to initialise app.");
        return 1;
    }

    app.run();
    return 0;
}