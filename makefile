all:
	c++ \
	-std=c++11 \
	-pthread \
	-o summarize \
	main.cpp utils/utils.cpp modules/summarizer.cpp \
	-l boost_program_options

# for mac os:

# all:
# 	c++ \
# 	-std=c++11 \
# 	-pthread \
# 	-o summarize \
# 	main.cpp utils/utils.cpp modules/summarizer.cpp \
# 	-I /opt/local/include \
# 	-L /opt/local/lib \
# 	-l boost_program_options-mt

