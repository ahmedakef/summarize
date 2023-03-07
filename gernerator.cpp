// compile using: g++ gernerator.cpp -o generator
#include <iostream>
#include <thread>

using namespace std;

int main()
{

    int numbers_count = 2000000000;
    while (numbers_count--)
    {
        // cout<<"the request took "<<rand() % 1000 << " seconds to complete"<<endl;
        cout << rand() % 1000 << endl;
        this_thread::sleep_for(chrono::milliseconds(300));
    }

    return 0;
}