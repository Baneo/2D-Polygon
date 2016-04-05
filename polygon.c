/* LO27 PROJECT : 2D Polygon library
*
*  File : polygon.c
*  This file details all function which are in the Polygon library. 
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

#include <stdio.h>
#include <stdlib.h>
#include <polygon.h>
#include <status.h>
#include <boolean.h>
#include <math.h>
#include <string.h>


typedef struct{
    double x;
    double y;
}Point;

typedef struct elem{
    Point value;
    struct elem* next;
	 struct elem* prev;
}Element;

typedef struct {
    Element* head;
    int length;
}Polygon;


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

Point createPoint(double a, double b)
{
    Point p;
    p.x = a;
    p.y = b;
    return p;
}

/* Function createPolygon
*
*  This Function creates and initializes an empty polygon, takes nothing and 
*  returns a Polygon.
*
*  p : a Polygon variable corresponding to the polygon the user wants to 
*  create.
*/

Polygon createPolygon()
{
    Polygon P;
    P.head = NULL;
    P.length = 0;
    return P;
}

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

Polygon addPoint(Polygon h, Point p)
{
	 Element* newElem = (Element*)malloc(sizeof(Element));
	 newElem -> value = p;
    if (h.length == 0)
    {
       newElem -> prev = newElem;
	    newElem -> next = newElem;
	    h.head = newElem;
		 h.length = 1;
    }
    else
    {
        newElem->prev = h.head->prev;
        newElem->next = h.head;
        newElem->prev->next = newElem;
        newElem->next->prev = newElem;
		  h.length = h.length + 1;
    }

return h;
}

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

Polygon removePoint(int i, Polygon h)
{
    
    int j = 0;
    Element* m = h.head;
    if (h.length == 0)
    {
        return h;
    }
    else if (h.length == 1)
    {
        h.length = 0;
        free(h.head);
        h.head = NULL;
        return h;
    }
    else if (h.length == 2)
	 {
    	if (i == 1)
	 	{
			h.head = h.head -> next;		
		}
		free(h.head -> next);
		h.head -> next = h.head;
		h.head -> prev = h.head;
		h.length = 1;		
	 }
	 else
    {
        for (j=1 ; j<i ; j++)
        {
            m = m -> next;
        }
		  m -> next -> prev = m -> prev;
		  m -> prev -> next = m -> next;
		  free(m);
        h.length = h.length - 1;
        
    }
return h;
}


/* Function printPoint2
*  
*  This function prints a 2D-point on the console terminal, it takes a Point 
*  and returns nothing.
*
*  p : a Point variable corresponding to the point the user wants to print 
*  (the point must exist).
*/

void printPoint2(Point p)
{
    printf("[%.2f ;%.2f]", p.x, p.y);
}


/* Function printPolygon2
*
*  This function prints a 2D-Polygon on the console terminal, it takes a 
*  Polygon and returns nothing.

*  h : a Polygon variable corresponding to the polygon the user wants to print 
*  (the specified polygon must exist).
*/

void printPolygon2(Polygon h)
{
    int i = 1;
    for (i = 1 ; i <= h.length ; i++)
    {
        printPoint2(h.head -> value);
        h.head = h.head -> next;
    }
}


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

Polygon convexhullPolygon(Polygon p)
{
	return p;
}


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

BOOL isOnTheLine(Point p, Point q, Point t)
{
	BOOL colinear = FALSE, verificationX = FALSE, verificationY = FALSE;
	if (((p.x <= t.x) && (t.x <= q.x)) || ((q.x <= t.x)&&(t.x <= p.x)))
	{
		verificationX = TRUE;
	}
	if (((p.y <= t.y) && (t.y <= q.y)) || ((q.y <= t.y)&&(t.y <= p.y)))
	{
		verificationY = TRUE;
	}
	if (((t.y - p.y)*(t.x - q.x)) == ((t.y - q.y)*(t.x - p.x)))
	{
		colinear = TRUE;
	}
	if(verificationX && verificationY && colinear)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


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

BOOL containsPoint(Polygon P, Point T)
{
	Element* p = P.head;
	Element* q = P.head -> next;
	
	do
	{
	if (isOnTheLine(p -> value, q -> value, T))
		{
		return TRUE;
		}
	if (((p -> value.y < T.y) && (T.y < q -> value.y)) || ((q -> value.y < T.y) && (T.y < p -> value.y)))
		{
		if (p -> value.x < T.x && p -> value.x < T.x)
			{
			return TRUE;
			}
		if (T.x < p -> value.x && T.x < q -> value.x)
			{
			return FALSE;
			}
	else
		if (p -> value.x + (((T.y - p -> value.y) / (q -> value.y -p -> value.y)) * (q -> value.x - p -> value.x)) <= T.x)
		{
		return TRUE;
		}
		}
		p = p -> next;
		q = q -> next;
	}while (p != P.head);
return FALSE;	
}


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

Status containsPolygon (Polygon p, Polygon q)
{
	int i =0;
	Element* r = p.head; 
	Element* s = q.head;
	BOOL isequal = TRUE, isinside = TRUE, isoutside = TRUE;

	/*Case EQUAL */
	if (p.length == q.length) 
   {
		while (i < p.length && isequal != FALSE)
		{ 
			if ( r->value.x != s->value.x && r->value.y != s->value.y )
			{
				isequal = FALSE; 
			}
			i ++;
			r = r -> next;
			s = s -> next;
		}
		if (isequal == TRUE)
		{ 
			return EQUAL; 
		} 
	}

	/*Case INSIDE */
	r = p.head;
	s = q.head;
	i = 0;
	while (i < q.length && isinside == TRUE)
	{
		if (containsPoint(p,s -> value) == FALSE)
		{
			isinside = FALSE;
		}
		s = s -> next;
	}
   if(isinside == TRUE)
   {
		return INSIDE;
	}

   /*Case ENCLOSING */

	r = q.head;
	s = p.head;
	i = 0;
	isinside = TRUE;
	while (i < q.length && isinside == TRUE)
	{
		if (containsPoint(q,s -> value) == FALSE)
		{
			isinside = FALSE;
		}
		s = s -> next;
	}
   if(isinside == TRUE)
   {
		return ENCLOSING;
	}

	/*Case OUTSIDE */

	r = p.head;
	s = q.head;
	i = 0;
	while (i < q.length && isoutside == TRUE)
	{
		if (containsPoint(p,s -> value) == TRUE)
		{
			isoutside = FALSE;
		}
		s = s->next;
	}
	if(isoutside == TRUE)
	{
		return OUTSIDE;
	}

return INTERSECT; 
}


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


Point intersection(Point a, Point b, Point c, Point d)
{
	/* we'll create here x and w the two directing vectors of ab and cd*/
	double x,w;
	/* we'll create here u and v the two origin ordinate of ab and cd*/
	double u,v;
	/* and finally let's create the x and y of our point! */
	double s,p;
	Point q;
	Point EMPTY;
	/* let's now try to have the value of u,v,x,w*/
	if (b.x - a.x != 0 && d.x - c.x != 0)
	{ /* if the lines aren't vertical ( it will cause some problems for a division) */
		x = (b.y - a.y) / (b.x - a.x);
		w = (d.y - c.y) / (d.x - c.x);
		u = a.y - (w * a.x);
		v = c.y - (w * c.x);
		if (x == w)
		{ /* the vectors are colinear */
			if (u == v)
			{
				if (a.x <= c.x && d.x <= a.x) 
				{
					return a;
				}
		
				if (b.x <= c.x && d.x <= b.x)
				{
					return b;
				}
			}
			else 
			{
				return q;
			}
		}
	/* the vectors aren't colinears, normal case */
		s = (v-u)/(x-w);
		p = s*x+u;
		q = createPoint(s,p);
	/* let's verify if the point q is on both segments. */
		if (x == ((q.y-a.y)/(q.x-a.x)) && x == ((q.y-c.y)/(q.x-c.x))) 
		{
		/*q is on the the infinite line ab and cd.*/
			if ((q.x <= b.x && q.x >= a.x) && (q.x <= d.x && q.x >= c.x))
			{
		/* q is on the segment ab and ac. it's ok.*/
				return q;
			}
			else	
			{
			/* q is on the infinite line but not on the segment. */
				return EMPTY;
			}
		}
		else 
		{
			/* q is not on both infinite lines. */
			return EMPTY;
		}
	}
	
		
	else 
	{ /* managing the case of vertical lines */
		if (b.x-a.x == 0 && d.x - c.x == 0) 
		{
			if (a.x <= c.x && d.x <= a.x) 
			{
				return a;
			}
			if (b.x <= c.x && d.x <= b.x)
			{
				return b;
			}
			else 
			{
			return q;
			}
		}
	}
	return q;
}


/* Function previous
*  
*  This function computes the previous point of a given polygon, it takes a 
*  polygon and returns a point
*   
*  p : a Polygon variable corresponding to the polygon the user wants to get 
*  the previous point
*/

Point previous(Polygon p)
{
	int j;
	for (j = 1 ; j < p.length ; j++)
        {
            p.head = p.head -> next;
        }
   return p.head -> value;
}

/* Function gotoPrevious
*
*  This function allow the user to get a pointer on the last point of a 
*  specified polygon, it takes a polygon and returns the same polygon with the 
*  head pointing on the last point.
*
*  p : a polygon variable corresponding to the specified polygon.
*/


Polygon gotoPrevious(Polygon p)
{
	int j;
	for (j = 1 ; j < p.length ; j++)
        {
            p.head = p.head -> next;
        }
   return p;
}


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
*
*  Note : This function actually doesn't work
*/

Polygon unionPolygon(Polygon p, Polygon h){
	Polygon z = createPolygon();
	Polygon r = p;
	Polygon s = h;
	Point w,n;
	int way = 0;
	Polygon swit; /* to switch between polygon and point easily*/
	if (containsPolygon(p,h) == 4 || containsPolygon(p,h) == 5) 
	{
		return p;
	}
	else if (containsPolygon(p,h) == 1)
	{
		return convexhullPolygon(p);
	}
	else if (containsPolygon(p,h) == 0)
	{
		return p;
	}
	else if (containsPolygon(h,p) == 0)
	{
		return h;
	}
	if (containsPoint(p,h.head -> value))
	{
	r = h;
	s = p;
	}
	else 
	{
		do	
		{
			int i = 1;
			z = addPoint(z,r.head -> value);
			do 
			{
				if (way == 0) 
				{
					n = intersection(r.head -> value,r.head -> next -> value,s.head -> value,s.head -> next -> value);
					if (n.x != w.x && n.y != w.y) 
					{
						z = addPoint (z,intersection(r.head->value,r.head ->next->value,s.head->value,s.head->next->value));
						s.head = s.head -> next;
						swit = s;
						s = r;
						r = swit;
						i = 100000;
						if (containsPoint(s,previous(r)))
						{	
							z=addPoint(z,r.head->value);
							way = 0;
						}
						else 
						{
							z = addPoint (z,previous(r));
							way = 1;
						}
					}
					else 
					{
						s.head = s.head -> next;
						i = i + 1;
					}
				}
				else 
				{
					n = intersection(r.head->value,previous(r),s.head->value,s.head->next->value);
					if ((n.x =! w.x) && (n.y != w.y)) 
					{
						z = addPoint (z,intersection(r.head->value,previous(r),s.head->value,s.head->next->value));
						s.head = s.head -> next;
						swit = s;
						s = r;
						r = swit;
						i = 100000;
						if (containsPoint(s,previous(r)))
						{	
							z = addPoint(z,r.head->value);
							way = 0;
						}
						else 
						{
							z= addPoint (z,previous(r));
							way = 1;
						}
		
					}	
					else 
					{
						if (way == 1) 
						{
							s.head = s.head -> next;
							i = i + 1;
						}
						else 
						{
							s = gotoPrevious(s);
							i = i + 1;
						}
					}
				}
			} while (i < s.length);
		} while (r.head != p.head || r.head != h.head);
   }
	return z;
}

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
*
*  Note : This function actually doesn't work
*/

Polygon intersectionPolygon(Polygon p, Polygon h)
{
	Polygon z = createPolygon();
	Polygon r = p;
	Polygon s = h;
	Point w,n;
	int way = 0;
	Polygon swit; /* to switch between polygon and point easily*/
	if (containsPolygon(p,h) == 4 || containsPolygon(p,h) == 5) 
	{
		return p;
	}
	else if (containsPolygon(p,h) == 1)
	{
		return convexhullPolygon(p);
	}
	else if (containsPolygon(p,h) == 0)
	{
		return p;
	}
	else if (containsPolygon(h,p) == 0)
	{
		return h;
	}
	if (containsPoint(p,h.head -> value))
	{
		r = h;
		s = p;
	}
	else 
	{
		do
		{
			int i = 1;
			z = addPoint(z,r.head->value);
			do 
			{
				if (way == 0)
				{
					n = intersection(r.head->value,r.head->next->value,s.head->value,s.head->next->value);
					if ((n.x != w.x) && (n.y != w.y))   
					{
						z = addPoint (z,intersection(r.head -> value,r.head -> next -> value,s.head -> value,s.head -> next -> value));
						s.head = s.head -> next;
						swit = s;
						s = r;
						r = swit;
						i = 100000;
						if (containsPoint(s,previous(r)))
						{	
							z= addPoint (z,previous(r));
							way = 1;
						}
						else 
						{
							z = addPoint(z,r.head->value);
							way = 0;
						}
					}
					else
				   {
						s.head = s.head->next;
						i = i+1;
					}
				}
				else 
				{
    			n = intersection(r.head->value,previous(r),s.head->value,s.head->next->value);
				if ((n.x != w.x) && (n.y != w.y)) 
				{
					z = addPoint (z,intersection(r.head->value,previous(r),s.head->value,s.head->next->value));
					s.head = s.head -> next;
					swit = s;
					s = r;
					r = swit;
					i = 100000;
					if (containsPoint(s,previous(r)))
					{	
						z= addPoint (z,previous(r));
						way = 1;
					}
					else 
					{
						z=addPoint(z,r.head -> value);
						way = 0;
					}
		
				}	
				else
			   {
					if (way == 1) 
					{
						s.head = s.head->next;
						i = i+1;
					}
					else 
					{
						s = gotoPrevious(s);
						i=i+1;
					}
				}
			}
		} while (i < s.length);
	} while (r.head != p.head || r.head != h.head);
}
return z;
}

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
*
*  Note : This function actually doesn't work
*/


Polygon differencePolygon(Polygon p, Polygon h)
{
	Polygon z; 
	Polygon r;
	Polygon s;
	Point w,n;
	int way = 0;
	int inside = 0;
	Polygon swit; /* to switch between polygon and point easily*/
	z = createPolygon();
	r = createPolygon();
	r = p;
	s = createPolygon();
	s = h;
	
	if (containsPolygon(p,h) == 4 || containsPolygon(p,h) == 5) 
	{
		return p;
	}
	else if (containsPolygon(p,h) == 1)
	{
		return convexhullPolygon(p);
	}
	else if (containsPolygon(p,h) == 0)
	{
		return p;
	}
	else if (containsPolygon(h,p) == 0)
	{
		return h;
	}
	if (containsPoint (p,h.head -> value))
	{
		r = h;
		s = p;
	}
	else 
	{
		do
		{
			int i = 1;
			z = addPoint(z,r.head -> value);
			do 
			{
				if (inside == 1)
				{
					if (way == 0) 
					{
						n = intersection(r.head->value,r.head->next->value,s.head->value,s.head->next->value);
						if ((n.x != w.x) && (n.y != w.y)) 
						{
							z = addPoint (z,intersection(r.head->value,r.head -> next->value,s.head->value,s.head->next->value));
							s.head = s.head -> next;
							swit = s;
							s = r;
							r = swit;
							i = 100000;
							if (containsPoint(s,previous(r)))	
							{	
								z = addPoint(z,r.head->value);
								way = 0;
							}
							else 
							{
								z = addPoint(z,previous(r));
								way = 1;
							}
						}
						else 
						{
							s.head = s.head->next;
							i = i+1;
						}
					}
					else 
					{
						n = intersection(r.head->value,previous(r),s.head->value,s.head-> next->value);
						if ((n.x != w.x) && (n.y != w.y)) 
						{
							z = addPoint (z,intersection(r.head -> value,previous(r),s.head -> value,s.head -> next -> value));
							s.head = s.head -> next;
							swit = s;
							s = r;
							r = swit;
							i = 100000;
							if (containsPoint(s,previous(r)))
							{	
								z = addPoint(z,r.head->value);
								way = 0;
							}
							else 
							{
								z = addPoint (z,previous(r));
								way = 1;
							}
		
						}	
						else 
						{
							if (way == 1) 
							{
								s.head = s.head->next;
								i = i+1;
							}
							else 
							{
								s = gotoPrevious(s);
								i = i+1;
							}	
						}
					}
				}
		
				if(inside == 0)
				{
					if (way == 0) 
					{
						n = intersection(r.head->value,r.head->next->value,s.head->value,s.head->next->value);
						if ((n.x != w.x) && (n.y != w.y)) 
						{
							z = addPoint (z,intersection(r.head -> value,r.head -> next-> value,s.head -> value,s.head -> next -> value));
							s.head = s.head -> next;
							swit = s;
							s = r;
							r = swit;
							i = 100000;
							if (containsPoint(s,previous(r)))
							{	
								z = addPoint (z,previous(r));
								way = 1;
							}
							else 
							{
								z = addPoint(z,r.head->value);
								way = 0;
							}
						}
						else 
						{
							s.head = s.head->next;
							i = i+1;
						}
					}
					else 
					{
						n = intersection(r.head->value,previous(r),s.head->value,s.head->next->value);
						if ((n.x != w.x) && (n.y != w.y)) 
						{
							z = addPoint (z,intersection(r.head->value,previous(r),s.head->value,s.head->next->value));
							s.head = s.head -> next;
							swit = s;
							s = r;
							r = swit;
							i = 100000;
							if (containsPoint(s,previous(r)))
							{	
								z = addPoint (z,previous(r));
								way = 1;
							}
							else 
							{
								z = addPoint(z,r.head->value);
								way = 0;
							}
		
						}	
						else 
						{
							if (way == 1)
							{
								s.head = s.head->next;
								i = i+1;
							}
							else 
							{
								s = gotoPrevious(s);
								i = i+1;
							}
						}
					}	
				}
			} while (i < s.length);
		} while (r.head != p.head || r.head != h.head);
	}
	return z;
}


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
*
*  Note 2 : This function actually doesn't work
*/


Polygon exclusiveORPolygon (Polygon p,Polygon q)
{
	Polygon z;
	z = createPolygon();
	z = differencePolygon(unionPolygon(p,q),intersectionPolygon(p,q));
	return z;
}




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
*  Warning : This function will erase the polygon you'll use for this function
*/

Polygon centralSymmetry (Polygon h, Point p)
{
    Element* q = h.head;
    do
    {
        q -> value.x = q -> value.x + 2*(p.x - q -> value.x);
        q -> value.y = q -> value.y + 2*(p.y - q -> value.y);
        q = q -> next;
    } while (q != h.head);
return h;
}

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
*  Warning : This function will erase the polygon you'll use for this function
*/

Polygon rotatePolygon(Polygon p, Point a, double angle)
{
	int i = 0;
	double c,d;
	Polygon q;
	Point s;
	q = createPolygon();
	c = 0;
	d = 0;
	c = cos(angle);
	d = sin(angle);
	
	do
	{
		p.head->value.x = p.head->value.x - a.x;
		p.head->value.y = p.head->value.y - a.y;
		p.head = p.head -> next;
		i = i+1 ;
		
	}while (i == p.length - 1);
	
	
	i = 0;
	do
	{ /*We use the rotation of a imaginary number,adapted here to a 2D point */
		i = i + 1;
		s.x = a.x* c - p.head -> value.x*d;
		s.y = p.head -> value.y*c + a.y*d;
		q = addPoint(q, s);
		
	} while (i < p.length -1);
	i = 0;
	do
	{
	p.head->value.x = p.head->value.x + a.x;
	p.head->value.y = p.head->value.y + a.y;
	p.head = p.head -> next;
	i = i+1 ;
	} while (i < p.length - 1);
	return q;
}


/* Function scalePolygon
*
*  This function scales the specified polygon with a specified factor (the polygon must have been created).
*
*  p : a Polygon variable corresponding to the polygon the user wants to 
*  scale.
*  k : a float variable corresponding to the factor of the scale.
*
*  Note : In order to save memory, p is also used as the result of the function
*  Warning : This function will erase the polygon you'll use for this function
*/


Polygon scalePolygon(Polygon p, float k) 
{
	Element* q = p.head -> next;
	do 
	{ 
		q -> value.x = (((q->value.x - p.head->value.x)*k)+p.head->value.x);
		q -> value.y = (((q->value.y- p.head->value.y)*k)+p.head->value.y);
		q = q->next;
	} while (q != p.head);
return p;
}


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
*
*  Note : In order to save memory, p is also used as the result of the function
*  Warning : This function will erase the polygon you'll use for this function
*/

Polygon translatePolygon(Polygon h, Point p, Point s)
{
    Element* q = h.head;
    Point v;
    v.x = s.x - p.x;
    v.y = s.y - p.x;
    do
    {
        q -> value.x = (q -> value.x) + (v.x);
        q -> value.y = (q -> value.y) + (v.y);
        q = q -> next;
    }while (q != h.head);
return h;
}


/* Function toString
*
*  This function print the specified polygon (the polygon must have been 
*  created).
*  
*  p : a Polygon variable corresponding to the polygon the user wants to print
*/


char* toString(Polygon p)
{
	char* result;
	char chaine[20];
	int nb;
	int i = 0;
	int j = 0; 
	result = '\0';
	nb = (p.length * 20) + 2;
	result[0]='[';
	result = (char*)malloc(sizeof(char)*nb);

	do 
	{
		for (i=0;i<20;i++)
		{
			chaine[i]='\0';
		}
		sprintf(chaine,"[%.2f,%.2f],",p.head->value.x,p.head->value.y);
		strcat(chaine,result);
		p.head = p.head -> next;
		j=j+1;
	} while(i < p.length);
	sprintf(result,"]");
	return result;
}

	
#endif
	
