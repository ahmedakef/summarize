all:
	c++ \
	-std=c++11 \
	-pthread \
	-o summarize \
	main.cpp utils/utils.cpp modules/summarizer.cpp \
	-lboost_program_options