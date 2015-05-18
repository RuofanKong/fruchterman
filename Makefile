PYTHON_VERSION = 2.7# The environment variable of python version
PYTHON_INC = /usr/include/python$(PYTHON_VERSION)# python workspace   #location

# Location of the boost python include files and library
BOOST_INC = /usr/local/boost_1_57_0/prefix/include/
BOOST_LIB = /usr/lib/usr/local/boost_1_57_0/prefix/lib/

# compile mesh classes
#TARGET = fruchterman_v1
#TARGET = try1
TARGET = fruchterman_v3
#TARGET = TestModule

#-std=c++11
$(TARGET).so: $(TARGET).o 
	g++ -shared -Wl,--export-dynamic $(TARGET).o -L$(BOOST_LIB) -lboost_python -L/usr/lib/python$(PYTHON_VERSION)/config -lpython$(PYTHON_VERSION) -o $(TARGET).so

$(TARGET).o: $(TARGET).cc  
	g++ -I$(PYTHON_INC) -I$(BOOST_INC) -fPIC -c $(TARGET).cc
