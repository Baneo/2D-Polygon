/* LO27 PROJECT : 2D Polygon library
*
*  File : status.h
*  This file provides the Status type, useful for the containsPolygon function 
*  created in the file polygon.c
*  
*  File created by :
*
*  TSAGALOS Thibault
*  thibault.tsagalos@utbm.fr
*
*  DURANCE Aurélien
*  aurelien.durance@utbm.fr
*/

#ifndef STATUS_H_
#define STATUS_H_

typedef enum {
    INSIDE = 0,
    OUTSIDE = 1,
    INTERSECT = 2,
    ENCLOSING = 3,
    EQUAL = 4
}Status;


#endif

