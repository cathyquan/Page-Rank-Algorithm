# Page-Rank-Algorithm
Using graph data structures to implement Google's Page Rank Algorithm

Google's Page Rank Algorithm is an algorithm used to rank the importance of various webpages. For this project, I implemented this algorithm by using a directed graph data structure whose nodes consisted of different websites and their edges represent the links among the websites. The graph data structure was implemented using the map STL.

INPUT:
  - number of websites
  - number of power iterations
  - website links
  
  ex:
    7 2
    google.com gmail.com
    google.com maps.com
    facebook.com ufl.edu
    ufl.edu google.com
    ufl.edu gmail.com
    maps.com facebook.com
    gmail.com maps.com
  
OUTPUT:
  - websites listed in alphabetical order
  - respective rank of each website
  
  ex:
    facebook.com 0.20
    gmail.com 0.20
    google.com 0.10
    maps.com 0.30
    ufl.edu 0.20

