# location of the Python header files
 
 
PYTHON_VERSION=2.7
PYTHON_INCLUDE=-I/usr/include/python2.7/
 
# compile mesh classes
TARGET = island_counter_ext
 
#$(TARGET).so: $(TARGET).o
#	g++ -shared -Wl,--export-dynamic $(TARGET).o -L$(BOOST_LIB) -lboost_python -lpthread -ldl -lutil -lm -lpython2.7 -Xlinker -export-dynamic -o $(TARGET).so
# 
#$(TARGET).o: $(TARGET).cpp
#	g++ -I$(BOOST_INC) -I$(PYTHON_INCLUDE) -fPIC -c $(TARGET).cpp


$(TARGET).so: $(TARGET).o
	$(CXX) -shared -Wl,--export-dynamic $(TARGET).o -lboost_python -lpthread -ldl -lutil -lm -lpython2.7 -Xlinker -export-dynamic -o $(TARGET).so island_counter.o
 
$(TARGET).o: $(TARGET).cpp
	$(CXX) -std=c++11 $(PYTHON_INCLUDE) -fPIC -c $(TARGET).cpp island_counter.cpp

clean:
	rm *.o *.so
