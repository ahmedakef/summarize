#include <iostream>
#include <sstream>
#include <vector>
#include <thread>
#include "modules/summarizer.hpp"
#include "utils/utils.hpp"
#include <fcntl.h>
#include <boost/program_options.hpp>
#include <atomic>
namespace po = boost::program_options;

using namespace std;
atomic<bool> continue_reading = {true};

void handle_printing(Summarizer *summarizer, int delay, int precision)
{
    print_elements(vector<string>{"Count", "Mean", "Min", "Max", "P95", "P99", "\n"}, precision);
    while (true)
    {
        cout << "\r";
        summarizer->print_summary(precision);
        if (continue_reading == false)
        {
            cout << endl;
            break;
        }
        this_thread::sleep_for(chrono::seconds(delay));
    }
}

void start(int delay, int precision)
{
    string line;
    Summarizer summarizer;

    thread timer(handle_printing, &summarizer, delay, precision);

    while (continue_reading)
    {
        if (!getline(cin, line))
        {
            // either an error hapened or we reached EOF
            continue_reading = false;
            break;
        }
        auto [number, ok] = is_number(line);
        if (!ok || line == "")
        {
            continue;
        }
        summarizer.add_number(number);
    }

    timer.join();
}

int main(int ac, char *av[])
{
    int delay, precision;

    try
    {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help,h", "Produce help message")
            ("file,f", po::value<string>(), "Read input from a file")
            ("delay,d", po::value<int>(&delay)->default_value(1), "Delay time between re-calculating")
            ("precision,p", po::value<int>(&precision)->default_value(2), "Control the precision parameter")
        ;

        po::positional_options_description p;
        p.add("file", 1);

        po::variables_map vm;
        po::store(po::command_line_parser(ac, av).
                  options(desc).positional(p).run(), vm);
        po::notify(vm);

        if (vm.count("help"))
        {
            cout << "summarize - Summarize a stream of numbers by printing some statistics every specified interval\n";
            cout << "Usage: summarize [file_name] [options]\n";
            cout << desc << "\n";
            return 0;
        }

        if (vm.count("file"))
        {
            string file_name = vm["file"].as<string>();
            // close the stdin so when we open the file it take the lowest
            // available file descriptor which is 0
            close(0);
            int fd = open(file_name.c_str(), 0);
            if (fd < 0)
            {
                cout << "cat: cannot open " << file_name << endl;
                exit(1);
            }
        }
        start(delay, precision);
    }
    catch (std::exception &e)
    {
        cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    catch (...)
    {
        cerr << "Exception of unknown type!\n";
    }

    return 0;
}