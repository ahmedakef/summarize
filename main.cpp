#include <iostream>
#include <sstream>
#include <vector>
#include <thread>
#include "modules/summarizer.h"
#include "utils/utils.h"

using namespace std;
bool continue_reading = true;

void handle_printing(Summarizer *summarizer)
{
    printElements(vector<string>{"Average", "Min", "Median", "p95", "p99", "Max", "\n"});
    while (true)
    {
        cout << "\r";
        summarizer->print_summery();
        this_thread::sleep_for(chrono::seconds(1));
        if (continue_reading == false)
            break;
    }
}

int main()
{
    int number;
    string line;
    Summarizer summarizer;

    thread timer(handle_printing, &summarizer);

    while (continue_reading)
    {
        if (!getline(cin, line))
        {
            // either an error hapened or we reached EOF
            continue_reading = false;
            break;
        }
        if (!is_number(line))
        {
            continue;
        }
        stringstream(line) >> number;
        summarizer.add_number(number);
    }

    timer.join();
    return 0;
}