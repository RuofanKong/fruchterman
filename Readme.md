<html>
<body>
<h1> Synopsis </h1>
This project is to implement the Fruchterman Reingold algorithm using C++ Boost, and provides the interface between C++ and Python such that it could be called from Python side and implemented in C++. 


<h1> Motivation </h1> 
The purpose of the project is to separate nodes in a network for aesthetic layout, provides the easy API in Python side and implements in very fast speed.

<h1> File Organization </h1>
The respository contains 3 files:
<ul style=”list-style-type:disc”>  
<li> "fruchterman_v3.cc" is the C++ source file that implements the fruchterman reingold algorithm and provides the interface between C++ and Python using C++ Boost. The name of interface Module is "fruchterman_v3". </li>
<li> "Makefile" is the C++ compile file. </li>
<li> "test2.py" is the simple test code from Python side. </li>
</ul>

<h1> Implementation </h1>
<ol type=”1”> 
<li> Make sure you installed the C++ boost library, and set the workspace correctly. </li>
<li> Put "fruchterman_v3.cc", "Makefile" and "test2.py" together in the same directory (Also make sure that you have the file "/dist-packages/numpy/core/include/numpy/ndarrayobject.h" in Python directory, otherwise, please download the boost numpy lib). </li>
<li> In "Makefile", please modify the values:
     <ul style=”list-style-type:disc”>
     <li> python version "PYTHON_VERSION" </li>
     <li> python work space path "PYTHON_INC" </li>
     <li> python boost include path "BOOST_INC" </li>
     <li> python boost library path "BOOST_LIB" </li>
     </ul> 
</li>
<li> In the command line, type "make". </li>
<li> When you call fruchterman source code in Python, please import  the interface module name "fruchterman_v3". The "test2.py" shows a simple example for usage. </li>
</ol>

<h1> API Reference </h1>
The source code of Fruchterman Reingold algorithm contains the following arguments needed to pass in from Python side:
<ul style=”list-style-type:disc”>
<li> data: The adjacency matrix of a network which is a 2-D numpy array. </li>
<li> size: The vertices number in the network. </li>
<li> width: Our desired width of the layout. </li>
<li> height: Our desired height of the layout. </li>
<li> iteration: The total iteration number of Fruchterman Reingold algorithm. </li>


</html>
