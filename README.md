# Kruskal-and-Prim-Implementation
Implementation of Prim and Kruskal MST algorithms in C++. An adjacency matrix was used to represent the Graphs, which impacted performance. The function used to generate the random graph can be found in "GraphUtil.cpp". Profiling plots generated using Pyplot can also be found in the Results folder, and seen below. Best fit lines were computed using Scipy's [curve_fit function](https://docs.scipy.org/doc/scipy/reference/generated/scipy.optimize.curve_fit.html). The scripts used to generate these plots can be found in the Scripts folder.
 
 ## Profiling Results 
![alt text](https://github.com/danielenricocahall/Kruskal-and-Prim-Implementation/blob/master/Results/Prim_Kruskal_Fit_1.png)
![alt text](https://github.com/danielenricocahall/Kruskal-and-Prim-Implementation/blob/master/Results/Prim_Kruskal_Fit_2.png)
 
Each algorithm had a runtime which was best fit by O(|V|<sup>3</sup>), which was due to the use of an adjacency matrix. With an adjacency list and priority queue, the runtime of both implementations would drastically improve. 
 
 ## Conclusions 
 If you have any questions, feel free to email me at danielenricocahall@gmail.com.
