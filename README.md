# What is summarize?
Summarizer gives you Summary about stream of integers and it updates the summary every specified interval.
![example.gif](example.gif)

# Installation
```bash
curl 
```
# Usage
to summarize numbers from standard input:
```bash
summarizer
```

to summarize numbers from file:
```bash
summarizer -f file_name
```

other options:
```
  -h [ --help ]               Produce help message
  -f [ --file ] arg           Eead input from a file
  -d [ --delay ] arg (=1)     Delay time between re-calculating
  -p [ --precision ] arg (=2) Control the precision parameter
```

# Common Usage
Usally you won't get a stream of numbers in you logs, you will need to precess the logs first to extract the numers you want only
assume that `./generate` produce this logs:
```
the request took 383 seconds to complete
the request took 886 seconds to complete
the request took 777 seconds to complete
```
you can use `awk` first then pass the resut to `summarize`
```bash
./generator | awk -W interactive '{print $4}' | ./summarize
```