#include "app/app.h"
#include "logger/logger.h"

int main(int argc, char* argv[]) 
{
    logger::Init();

    const char* appName = (argc > 1) ? argv[1] : nullptr;

    app::App app;
    if (!app.Init(appName)) 
    {
        logger::Error("Failed to initialise app.");
        return 1;
    }

    app.Run();
    return 0;
}