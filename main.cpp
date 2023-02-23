#include <iostream>
#include <sstream>
#include <vector>
#include <thread>
#include "modules/summarizer.hpp"
#include "utils/utils.hpp"
#include <fcntl.h>
#include <boost/program_options.hpp>
namespace po = boost::program_options;

using namespace std;
bool continue_reading = true;

void handle_printing(Summarizer *summarizer, int delay)
{
    printElements(vector<string>{"Average", "Min", "Median", "p95", "p99", "Max", "\n"});
    while (true)
    {
        cout << "\r";
        summarizer->print_summery();
        this_thread::sleep_for(chrono::seconds(delay));
        if (continue_reading == false){
            cout<<endl;
            break;
        }
    }
}

void start(int delay) {
    int number;
    string line;
    Summarizer summarizer;

    thread timer(handle_printing, &summarizer, delay);

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
}

int main(int ac, char* av[])
{
    try {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help,h", "produce help message")
            ("file,f", po::value<string>(), "read input from a file")
            ("delay,d", po::value<int>(), "delay time between re-calculating")
        ;

        po::variables_map vm;        
        po::store(po::parse_command_line(ac, av, desc), vm);
        po::notify(vm); 

        if (vm.count("help")) {
            cout << desc << "\n";
            return 0;
        }

        if (vm.count("file")) {
            string file_name = vm["file"].as<string>();
            // close the stdin so when we open the file it take the lowest
            // available file descriptor which is 0
            close(0);
            int fd = open(file_name.c_str(), 0);
            if (fd < 0) {
                cout<<"cat: cannot open "<<file_name<<endl;
                exit(1);
            }
            
        }
        int delay = 1;
        if (vm.count("delay")) {
            delay = vm["delay"].as<int>();
        }
        start(delay);
    } catch(exception& e) {
        cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    catch(...) {
        cerr << "Exception of unknown type!\n";
    }
    
    return 0;
}