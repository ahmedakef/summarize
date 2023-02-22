all:
	g++ -I boost_1_81_0 \
	-std=c++11 \
	-pthread \
	-o summarizer \
	main.cpp utils/utils.cpp modules/summarizer.cpp