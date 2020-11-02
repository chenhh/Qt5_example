#ifdef Q_OS_WIN32
#include <windows.h>
#endif
#include <iostream>
#include <csignal>

using namespace std;

void signalHandler( int signum )
{
    cout << "Receiv signal (" << signum << ")." << endl;
}

int main()
{
     signal(SIGINT, signalHandler);
     while (1) {
        cout << "Go to sleep..." << endl;
        #ifdef Q_OS_WIN32
             Sleep(1);
        #elif Q_OS_LINUX
             sleep(1);
        #endif
     }
     return 0;
}
