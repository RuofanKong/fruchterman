/* The code implements the interface between C++ and Python for Frutcherman-Reingold algorithm using C++ Boost Python. The code accepts the adjacency matrix from Python, and calculates the coordinates for each vertex in a rectangle topology. The result returned to Python is a size* 3 matrix, where "size" is the total number of vertices, and each row contains the vertex_id, x-coordinate and y-coordinate, respectively. The descriptions for each argument are denoted as follow:

data: The ajacency matrix which is a numpy array.
size: The total number of vertices.
width: The width of the rectanglar topology.
height: The height of the rectanglar topology.
iteration: The iteration number for Fruchterman-Reingold algorithm.

The code is written by Ruofan (Ryan) Kong.
*/


#include <boost/graph/fruchterman_reingold.hpp>
#include <boost/graph/random_layout.hpp>
#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/topology.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/python/extract.hpp>
#include <boost/python/numeric.hpp>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <boost/random/linear_congruential.hpp>
#include <boost/progress.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <numpy/ndarrayobject.h> 

using namespace std;
using namespace boost;

// The topology for output is rectangle.
typedef boost::rectangle_topology<> topology_type;
typedef topology_type::point_type point_type;

// The graph data structure is adjacency matrix.
typedef adjacency_matrix<undirectedS, property<vertex_index_t, double> > Graph;
typedef graph_traits<Graph>::vertex_descriptor Vertex;


// Fruchterman Reingold Algorithm
boost::python::object fruchterman_reingold_layout(boost::python::numeric::array data, int size, int width, int height, int iteration){

  // Initializtion.
  Graph g(size); // Vertices' size
  int res_col = 3; // There are three componenets in each row: Vertex_id, x_coordinate, y_coordinate.
  // The results of fruchterman reingold algorithm.
  double* res = new double[size * res_col];



  // Get the graph information from the input, and this is for the undirected graph.
  for(int i = 0; i < size; i++){
    for(int j = 0; j<=i; j++){
      if((boost::python::extract<int>(data[i][j]) != 0) && (i != j))
        add_edge(i, j, g);       
    }
  }

  // Position Map.    
  typedef std::vector<point_type> PositionVec;
  PositionVec position_vec(num_vertices(g));
  typedef iterator_property_map<PositionVec::iterator, property_map<Graph, vertex_index_t>::type> PositionMap;
  PositionMap position(position_vec.begin(), get(vertex_index, g));

  // Generate the random graph as the initialization of the fruchterman reingold algorithm.
  minstd_rand gen;
  topology_type topo(gen, -width/2, -height/2, width/2, height/2);
  random_graph_layout(g, position, topo);

  // Fruchterman Reingold Algorithm.
  fruchterman_reingold_force_directed_layout(g, position, topo, cooling(linear_cooling<double>(iteration))); 
  
   
  // Store the results into the vector. 
  // The Dimension Information of the results
  npy_intp Dims[2];
  Dims[0] = size;
  Dims[1] = res_col;  

  // Iteratively store the data.
  int i = 0; // iterator.
  graph_traits<Graph>::vertex_iterator ui, ui_end;
  for(tie(ui, ui_end) = vertices(g); ui != ui_end; ui++){
    res[i++] = get(vertex_index, g, *ui); // Vertex_id
    res[i++] = position[*ui][0]; // x_coordinate
    res[i++] = position[*ui][1]; // y_coordinate
  }

  double* data1 = res;
  
  // Change the data structure to be compatible to Python.
  PyObject * pyObj = PyArray_SimpleNewFromData(2, Dims, NPY_DOUBLE, data1);
  boost::python::handle<> handle(pyObj);
  boost::python::numeric::array arr(handle);
  return arr;
}
    
// Boost Python Module for the interface
BOOST_PYTHON_MODULE(fruchterman_v3){
  using namespace boost::python;
 boost::python::numeric::array::set_module_and_type("numpy", "ndarray");
  import_array();
  def("fruchterman_reingold_layout", &fruchterman_reingold_layout);
}



