CXX = g++
CXXFLAGS = -std=c++14

SRCS = src/main.cpp \
       src/LoginUI.cpp \
       src/SignUpUI.cpp \
       src/LoginController.cpp \
       src/SignUpController.cpp \
       src/User.cpp \
       src/Member.cpp

OBJS = $(SRCS:.cpp=.o)
TARGET = bicycle_rental

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean 