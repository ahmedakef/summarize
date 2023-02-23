all:
	c++ \
	-std=c++11 \
	-pthread \
	-o summarizer \
	main.cpp utils/utils.cpp modules/summarizer.cpp \
	-lboost_program_options