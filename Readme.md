<html>
<body>
<h1> Synopsis </h1>
This project is to implement the Fruchterman Reingold algorithm using C++ Boost, and provides the interface between C++ and Python such that it could be called from Python side and implemented in C++. 


<h2> Motivation </h2> 
The purpose of the project is to separate nodes in a network for aesthetic layout, provides the easy API in Python side and implements in very fast speed.

<h3> File Organization </h3>
The project contains 3 files:
<ul style=”list-style-type:disc”>  
<li> "fruchterman_v3.cc" is the C++ source file that implements the fruchterman reingold algorithm and provides the interface between C++ and Python using C++ Boost. The name of interface Module is "fruchterman_v3". </li>
<li> "Makefile" is the C++ compile file. </li>
<li> "test2.py" is the simple test code from Python side. </li>
</ul>

<h4> Implementation </h4>
1. Make sure you installed the C++ boost library, and set the workspace correctly.
2. Put "fruchterman_v3.cc", "Makefile" and "test2.py" together in the same directory (Also make sure that you have the file "/dist-packages/numpy/core/include/numpy/ndarrayobject.h" in Python directory, otherwise, please download the boost numpy lib).
3. In "Makefile", please modify the values:
    -python version "PYTHON_VERSION"
    -python work space path "PYTHON_INC"
    -python boost include path "BOOST_INC"
    -python boost library path "BOOST_LIB"
4. In the command line, type "make".
5. When you call fruchterman source code in Python, please import  the interface module name "fruchterman_v3". The "test2.py" shows a simple example for usage. 

<h5> API Reference </h5>
The source code of Fruchterman Reingold algorithm contains the following arguments needed to pass in from Python side:
data: The adjacency matrix of a network which is a 2-D numpy array.
size: The vertices number in the network.
width: Our desired width of the layout.
height: Our desired height of the layout.
iteration: The total iteration number of Fruchterman Reingold algorithm.

</html>
