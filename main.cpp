#include <iostream>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <vector>
#include <set>
#include <limits>
#include <iomanip>
#include <thread>
#include <chrono>


using namespace std;
bool continue_reading = true;

template <typename T>
void printElement(T t)
{
    cout << left << setw(10) << fixed << setprecision(2) << t;
}

template<typename T>
void printElements(vector<T> elements)
{
    for( auto element : elements )
    {
        printElement(element);
    }
}

class Summarizer
{
public:
    double sum;
    set<double> numbers;

    Summarizer()
    {
        sum = 0;
        numbers = set<double>();
    }

    void add_number(double number)
    {
        sum += number;
        numbers.insert(number);
    }

    void print_summery()
    {
        double count = numbers.size();
        double average = sum / count;

        set<double>::iterator it = numbers.begin();
        // minimum is the first item in the set
        double min = *it;
        // median exist at the center of the set: 0+50 = 50;
        std::advance(it, 0.50 * count);
        double median = *it;
        // p95 exists after 45% of the center: 0+50+45 = 95
        std::advance(it, 0.45 * count);
        double p95 = *it;
        // p99 exists after 4% of the p95: 0+50+45+4 = 99
        std::advance(it, 0.04 * count);
        double p99 = *it;
        // maximum exists at the end of the set: 0+50+45+4+1 = 100
        std::advance(it, 0.01 * count);
        double maximum = *it;
        printElements(vector<double>{average, min, median, p95, p99, maximum});
    }
};

bool is_number(const string &s)
{
    char *end;
    strtod(s.c_str(), &end);
    return *end == 0;
}

void handle_printing(Summarizer *summarizer) {
    printElements(vector<string>{"Average", "Min", "Median", "p95", "p99", "Max", "\n"});
    while(true){
        cout<<"\r";
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