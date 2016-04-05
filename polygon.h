/* LO27 PROJECT : 2D Polygon library
*
*  File : polygon.h
*  This file is then header file of the library polygon.c
*	This file provides the different prototypes of all functions used in the file polygon.c 
*
*  File created by :
*
*  TSAGALOS Thibault
*  thibault.tsagalos@utbm.fr
*
*  DURANCE Aurélien
*  aurelien.durance@utbm.fr
*/

#ifndef POLYGON_H
#define POLYGON_H



/* Structures */



typedef struct{
    double x;
    double y;
}Point;

typedef struct elem{
    Point value;
    struct elem* next;
}Element;

typedef struct {
    Element* head;
    int length;
}Polygon;




/* Prototypes */




/* Function createPoint
*
*  This Function creates a 2D point according to the specified abscissa and 
*  ordinate by taking the two double variable and returning a Point variable.
*
*  a : a double variable corresponding to the abscissa of the point the user 
*  wants to create.
*  b : a double variable corresponding to the ordinate of the point the user 
*  wants to create.
*  p : a Point variable corresponding to the point the user wants to create.
*/

Point createPoint(double a, double b);

/* Function createPolygon
*
*  This Function creates and initializes an empty polygon, takes nothing and 
*  returns a Polygon.
*
*  p : a Polygon variable corresponding to the polygon the user wants to 
*  create.
*/

Polygon createPolygon();

/* Function addPoint
*
*  This function adds the specified point to the specified polygon, it takes a *  Polygon variable and a Point variable and returns the same polygon 
*  containing the new Point.
*
*  h : a Polygon variable corresponding to the polygon where the user wants to 
*  add a point (the polygon must have been created).
*  p : a Point variable corresponding to the point the user wants to add to  
*  the polygon h (the point must have been created).
*/

Polygon addPoint(Polygon h, Point p);

/* Function removePoint
*
*  This function removes the ith point from the specified polygon (points are 
*  indexed from 1 to N in a polygon), it takes a Polygon variable and an  
*  integer variable and returns the same polygon without the ith point.
 
*  i : an int variable corresponding to the ith point the user wants to remove 
*  (this value must correspond to an existing point in the specified polygon).
*  h : a Polygon variable corresponding to the polygon where the user wants to 
*  remove a point (the polygon must exist and must have the point the user 
*  wants to remove).
*/

Polygon removePoint(int i, Polygon h);

/* Function printPoint2
*  
*  This function prints a 2D-point on the console terminal, it takes a Point 
*  and returns nothing.
*
*  p : a Point variable corresponding to the point the user wants to print 
*  (the point must exist).
*/

void printPoint2(Point p);

/* Function printPolygon2
*
*  This function prints a 2D-Polygon on the console terminal, it takes a 
*  Polygon and returns nothing.

*  h : a Polygon variable corresponding to the polygon the user wants to print 
*  (the specified polygon must exist).
*/

void printPolygon2(Polygon h);

/* Function unionPolygon
*  
*  This function computes the union between two specified polygon, it takes 
*  two polygons and returns another polygon which is the union of the two 
*  polygons.
*
*  p : a Polygon variable corresponding to the first polygon the user wants to 
*  make the union (the polygon must have ben created and must have at least 3 
*  non-collinear points).
*  h : a Polygon variable corresponding to the second polygon the user wants 
*  to make the union (the polygon must have ben created and must have at least 
*  3 non-collinear points).
*	z : a Polygon variable representing the union of the two polygon in the non-
*  trivial cases.
*/

Polygon unionPolygon (Polygon h, Polygon p);

/* Function intersectionPolygon
*  
*  This function computes the intersection between two specified polygon, it 
*  takes two polygons and returns another polygon which is the intersection of 
*  the two polygons.
*
*  p : a Polygon variable corresponding to the first polygon the user wants to 
*  make the intersection (the polygon must have ben created and must have at 
*  least 3 non-collinear points).
*  h : a Polygon variable corresponding to the second polygon the user wants 
*  to make the intersection (the polygon must have ben created and must have 
*  at least 3 non-collinear points).
*	z : a Polygon variable representing the intersection of the two polygon in 
*  the non-trivial cases.
*/

Polygon intersectionPolygon (Polygon h, Polygon p);

/* Function exclusiveORPolygon
*  
*  This function computes the exclusiveOR between two specified polygon, it 
*  takes two polygons and returns another polygon which is the exclusiveOR of 
*  the two polygons.
*
*  p : a Polygon variable corresponding to the first polygon the user wants to 
*  make the exclusiveOR (the polygon must have ben created and must have at 
*  least 3 non-collinear points).
*  h : a Polygon variable corresponding to the second polygon the user wants 
*  to make the exclusiveOR (the polygon must have ben created and must have at 
*  least 3 non-collinear points).
*	
*  Note : In order to save memory, p is also used as the result of the function
*/

Polygon exclusiveORPolygons (Polygon h, Polygon p);

/* Function differencePolygon
*  
*  This function computes the difference between two specified polygon, it 
*  takes two polygons and returns another polygon which is the difference of 
*  the two polygons.
*
*  p : a Polygon variable corresponding to the first polygon the user wants to 
*  make the difference (the polygon must have ben created and must have at 
*  least 3 non-collinear points).
*  h : a Polygon variable corresponding to the second polygon the user wants 
*  to make the difference (the polygon must have ben created and must have at 
*  least 3 non-collinear points).
*	z : a Polygon variable representing the difference of the two polygon in 
*  the non-trivial cases.
*/

Polygon differencePolygons (Polygon h, Polygon p);

/* Function containsPoint
*
*  This function test if a specified poit is part of a specified polygon, it 
*  takes a polygon and a point and returns TRUE if the specified polygon 
*  contains the specified point, FALSE otherwise.

*  P : a Polygon variable corresponding to the polygon where the user wants to
*  search the specified point (the polygon must exist and must have at least 3 
*  non-collinear points).
*  T : a Point variable corresponding to the point the user wants to know if 
*  it's in the specified polygon or not (the point must exist).
*/

Boolean containsPoint(Polygon h, Point p);

/* Function containsPolygon
*
*  This function tests where is a specified polygon according to the position 
*  of another polygon,it takes two polygons and  returns a Status enumeration 
*  type that could take one of the following values : 
*  INSIDE : if the second polygon is fully inside the first one.
*  OUTSIDE : if the second polygon is fully outside the first one.
*  INTERSECT : if the second polygon is partially inside/outside the first 
*  one, if it's intersecting the first one.
*  ENCLOSING : if the first polygon is fully inside the second one. 
*  EQUAL : both polygons are exactly equal.
* 
*  p : a Polygon variable corresponding to the first polygon (this polygon 
*  must exist and must have at least 3 non-collinear points).
*  q : a Polygon variable corresponding to the second polygon (this polygon 
*  must exist and must have at least 3 non-collinear points).
*/

Status containsPolygon (Polygon h, Polygon p);

/* Function centralSymmetry
*
*  This function computes the central symmetry of the specified polygon 
*  according to the specified point( the point must have been created and the 
*  polygon too)
*
*  h : a Polygon variable corresponding to the polygon the user wants to make 
*  the symmetry
*  p : a Point variable corresponding to the point around the user wants to 
*  make the symmetry
*
*  Note : In order to save memory, h is also used as the result of the function
*/

Polygon centralSymmetry (Polygon h, Point p);

/* Function rotatePolygon
*
*  This function computes the rotation of the specified polygon 
*  according to the specified point with the specified angle(the point must 
*  have been created,the polygon too, and the angle must be in radians).
*
*  p : a Polygon variable corresponding to the polygon the user wants to 
*  rotate.
*  a : a Point variable corresponding to the point around the user wants to 
*  rotate the polygon.
*  angle : a double variable corresponding to the angle of the rotation
*
*  Note : In order to save memory, p is also used as the result of the function
*/

Polygon rotatePolygon (Polygon h, Point p, float i);

/* Function scalePolygon
*
*  This function scales the specified polygon with a specified factor (the polygon must have been created).
*
*  p : a Polygon variable corresponding to the polygon the user wants to 
*  scale.
*  k : a float variable corresponding to the factor of the scale.
*
*  Note : In order to save memory, p is also used as the result of the function
*/

Polygon scalePolygon(Polygon p, float i);

/* Function translatePolygon
*
*  This function computes the translation of the specified polygon
*  according to the vector defined by the two specified points
*  (vector going from the first specified point to the second one)
*
*  h : a Polygon variable corresponding to the polygon the user wants to 
*  translate (this polygon must have been created).
*  p : a Point variable corresponding to the first point of the vector the 
*  user want to translate the polygon with (this point must have been created).
*  q : a Point variable corresponding to the second point of the vector the 
*  user wants to translate the polygon with (this point must have been 
*  created).
*/

Polygon translatePolygon(Polygon h, Point p, Point q);

/* Function convexhullPolygon
*
*  This function computes the convex hull of a specified polygon using the 
*  Graham's method.
*
*  p : a Polygon variable corresponding to the polygon the user wants to make 
*  the convex hull (this polygon must have been created and must have at least 
*  3 non-collinear points).
*  
*  Note : This function is actually inactive, we didn't know how to do this 
*  function so it just returns the polygon in input.
*/

Polygon convexhullPolygon(Polygon p);

/* Function toString
*
*  This function print the specified polygon (the polygon must have been 
*  created).
*  
*  p : a Polygon variable corresponding to the polygon the user wants to print
*/

char* toString (Polygon p);

/* Function gotoPrevious
*
*  This function allow the user to get a pointer on the last point of a 
*  specified polygon, it takes a polygon and returns the same polygon with the 
*  head pointing on the last point.
*
*  p : a polygon variable corresponding to the specified polygon.
*/

Polygon gotoPrevious(Polygon p);

/* Function previous
*  
*  This function computes the previous point of a given polygon, it takes a 
*  polygon and returns a point
*   
*  p : a Polygon variable corresponding to the polygon the user wants to get 
*  the previous point
*/

Point previous(Polygon p);

/* Function intersection
*	
*  This function computes the intersection of two segments, it takes four 
*  points and returns a point (the intersection).
*  
*  a : a Point variable corresponding to the first point of the first segment
*  b : a Point variable corresponding to the second point of the first segment
*  c : a Point variable corresponding to the first point of the second segment
*  d : a Point variable corresponding to the second point of the second segment
*/

Point intersection(Point a, Point b, Point c, Point d);

/* Function isOnTheLine
*
*  This function verify if a specified point is on a line characterized by two 
*  other points, it takes three points and returns TRUE if the point is on the 
*  line and FALSE otherwise.
*
*  p : a Point variable corresponding to the point the user want to know if 
*  it's on the line (the point must exist).
*  q : a Point variable corresponding to a point of the line specified by the 
*  user (the point must exist)
*  t : a Point variable corresponding to another point of the line specified *  by the user (the point must exist)
*/

Boolean isOnTheLine (Point p, Point q, Point t);

#endif

