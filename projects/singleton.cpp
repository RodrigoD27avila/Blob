#include <stdlib.h>

class Logger
{
public:
    static Logger *Instance();

private:
    Logger() {};
    Logger(const Logger&) {};
    Logger& operator=(const Logger&) {};
    static Logger *instance;
};

Logger *Logger::instance = NULL;

Logger *Logger::Instance()
{
    if (!instance)
        instance = new Logger;

    return instance;
}

int main()
{
    Logger::Instance();
    return 0;
}
