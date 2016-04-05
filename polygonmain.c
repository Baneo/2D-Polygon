/* LO27 PROJECT : 2D Polygon library
*
*  File : polygonmain.c
*  This file is a testing file which allow to the user to test every functions 
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

#include <stdio.h>
#include <stdlib.h>
#include <polygon.c>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
	double x,y,angle;
	int choice, index, choice2, choice3, end;
	float factor;
	char* result_prompt;
	BOOL result;
	Status result2;
	Point a,b;
	Polygon P,Q,result_polygon;
	choice = 0;
	P = createPolygon();
	Q = createPolygon();
   
	
	printf("\n \n \nWelcome to this program which will allow you to play with polygons\n\n");
	printf("\nNow, you are going to create your first polygon \n");
	printf("\nEntering the first polygon\n");
	do
	{
		printf("\nWhat do you want to do ?\n");
		printf("1. Add a point to the polygon\n");
		printf("2. Remove a point to the polygon\n");
		printf("3. End the first polygon and move on to the second one\n");
		scanf("%d", &choice);
		while (choice != 1 && choice != 2 && choice != 3)
		{
			printf("Wrong choice, enter a new choice\n");
			scanf("%d", &choice);
		}
		if (choice ==1)
		{
		printf("\nPlease give the first coordinate (x) of the point of your first polygon\n");
		scanf("%lf", &x);
		printf("Please give the second coordinate (y) of the point of your first polygon\n");
		scanf("%lf", &y);
		a = createPoint(x,y);
		printf("Here is your point : \n");
		printPoint2(a);
		P = addPoint(P,a);
		printf("\nAnd here is your actual polygon\n");
		
		printPolygon2(P);
	}
	if (choice == 2)
	{
		printf("\nEnter the index of the point you want to delete\n");
		scanf("%d", &index);
		P = removePoint(index, P);
		printf("\nAnd here is your actual polygon\n");
		printPolygon2(P);
	}
	}while (choice == 2 || choice == 1);
	printf("\nEntering the second Polygon\n");
	do
	{
	printf("\nWhat do you want to do ?\n");
	printf("1. Add a point to the polygon\n");
	printf("2. Remove a point to the polygon\n");
	printf("3. End the second polygon and start to play ;)\n");
	scanf("%d", &choice);
	while (choice != 1 && choice != 2 && choice != 3)
	{
		printf("Wrong choice, enter a new choice\n");
		scanf("%d", &choice);
	}
	if (choice == 1)
	{
		printf("\nPlease give the first coordinate (x) of the point of your second polygon\n");
		scanf("%lf", &x);
		printf("\nPlease give the second coordinate (y) of the point of your second polygon\n");
		scanf("%lf", &y);
		a = createPoint(x,y);
		printf("\nHere is your point : \n");
		printPoint2(a);
		Q = addPoint(Q,a);
		printf("\nAnd here is your actual polygon : \n");
		
		printPolygon2(Q);
	}
	if (choice == 2)
	{
		printf("\nEnter the index of the point you want to delete\n");
		scanf("%d", &index);
		Q = removePoint(index, Q);
		printf("\nAnd here is your actual polygon : \n");
		printPolygon2(Q);
	}
	}while (choice == 2 || choice == 1);
	
	printf("\n\nNow let's play with these two polygons :3\n\n");

   do
	{
	end = 1;
	result_polygon = createPolygon();
	printf("\n\nWhat do you want to do ?\n\n");
	printf("1. Verify if a point is part of a polygon (Contains Point)\n");
	printf("2. Verify where the first polygon is, according to the position of the second one (Contains Polygon)\n");
	printf("3. Computes the union between the two polygons (inactive)\n");
	printf("4. Computes the intersection between the two polygons(inactive)\n");
	printf("5. Computes the difference between the two polygons(inactive)\n");
	printf("6. Computes the exclusive OR between the two polygons(inactive)\n");
	printf("7. Computes the central symmetry of a polygon according to a point\n");
	printf("8. Rotate a polygon according to a point with a given angle\n");
	printf("9. Scale a polygon\n");
	printf("10. Translate a polygon according to a vector\n");
	printf("11. Prompt a polygon\n");
	printf("12. EXIT (this is a dead end be careful)\n\n");
	printf("\n\nWhat is your choice ?\n");
	scanf("%d", &choice2);
	while(choice2 < 1 && choice2 > 11)
	{
		printf("\nWrong choice, enter a new choice\n");
		scanf("%d", &choice2);
	}
	switch (choice2)
	{
   case 1:
        printf("\nPlease give the first coordinate (x) of the point you want to use\n");
		  scanf("%lf", &x);
		  printf("Please give the second coordinate (y) of the point you want to use\n");
		  scanf("%lf", &y);
		  a = createPoint(x,y);
		  do
		  {
		  printf("\nWhich polygon do you want to use ?\n");
		  printf("1. The first one\n");
		  printf("2. The second one\n");
		  scanf("%d", &choice3);
		  }while(choice3 != 1 && choice3 != 2);
		  if (choice3 == 1)
		  {
				result = containsPoint(P,a);
		  }
		  if (choice3 == 2)
		  {
				result = containsPoint(Q,a);
		  }
		  if (result == TRUE)
		  {
				printf("\nThe point is inside the polygon\n");
		  }
		  if (result == FALSE)
		  {
				printf("\nThe point is not in the polygon\n");
		  }
        break;

	case 2:
		result2 = containsPolygon(P,Q);
		switch(result2)
		{
		case INSIDE:
			printf("\nThe first polygon is inside the second polygon\n");
			break;
		case OUTSIDE:
			printf("\nThe first polygon is outside the second polygon\n");
			break;
		case INTERSECT:
			printf("\nThe first polygon intersects the second polygon\n");
			break;
		case ENCLOSING:
			printf("\nThe first polygon encloses the second polygon\n");
			break;
		case EQUAL:
			printf("\nThe first polygon and the second polygon are equals\n");
			break;
		default :
			printf("\n\nFATAL ERROR !!\n\n");
			break;
		}		        
        
			break;
   case 3:
		  
        result_polygon = unionPolygon(P,Q);
		  printf("\nHere is the polygon representing the union between your two polygons\n");
		  printPolygon2(result_polygon);
        break;
   case 4:
        result_polygon = intersectionPolygon(P,Q);
		  printf("\nHere is the polygon representing the intersection between your two polygons\n");
		  printPolygon2(result_polygon);
        break;
   case 5:
		  result_polygon = differencePolygon(P,Q);
        printf("\nHere is the polygon representing the difference between your two polygons\n");
	     printPolygon2(result_polygon);
        break;
   case 6:
		  result_polygon = exclusiveORPolygon(P,Q);
        printf("\nHere is the reprensentation of the exclusive OR between your two polygons\n");
		  printPolygon2(result_polygon);
        break;
   case 7:
        printf("\nPlease give the first coordinate (x) of the point you want to use\n");
		  scanf("%lf", &x);
		  printf("\nPlease give the second coordinate (y) of the point you want to use\n");
		  scanf("%lf", &y);
		  a = createPoint(x,y);
		  do
		  {
		  printf("\nWhich polygon do you want to use ?\n");
		  printf("1. The first one\n");
		  printf("2. The second one\n");
		  scanf("%d", &choice3);
		  }while(choice3 != 1 && choice3 != 2);
		  if (choice3 == 1)
		  {
		  result_polygon = centralSymmetry (P,a);
		  }
		  if (choice3 == 2)
		  {
		  result_polygon = centralSymmetry (Q,a);	
		  }
		  
		  printf("\nHere is the polygon representing the central symmetry you wanted to do\n");
		  printPolygon2(result_polygon);
        break;
   case 8:
		  printf("\nPlease give the angle you want for the rotation of your polygon\n");
	     scanf("%lf", &angle);
        printf("\nPlease give the first coordinate (x) of the point you want to use\n");
		  scanf("%lf", &x);
		  printf("\nPlease give the second coordinate (y) of the point you want to use\n");
		  scanf("%lf", &y);
		  a = createPoint(x,y);
		  do
		  {
		  printf("\nWhich polygon do you want to use ?\n");
		  printf("1. The first one\n");
		  printf("2. The second one\n");
		  scanf("%d", &choice3);
		  }while(choice3 != 1 && choice3 != 2);
		  if (choice3 == 1);
		  {
		  result_polygon = rotatePolygon(P,a,angle);
		  }
		  if (choice3 == 2)
		  {
		  result_polygon = rotatePolygon(Q,a,angle);	
		  }
		  printf("\nHere is the polygon representing the rotation you wanted to do\n");
		  printPolygon2(result_polygon);
        break;
   case 9:
    	  do
		  {
		  printf("\nWhich polygon do you want to use ?\n");
		  printf("1. The first one\n");
		  printf("2. The second one\n");
		  scanf("%d", &choice3);
		  }while(choice3 != 1 && choice3 != 2);
		  printf("\nWhich factor do you want to use ?\n");
		  scanf("%f", &factor);
        if (choice3 == 1)
		  {
		  result_polygon = scalePolygon(P, factor);
		  }
		  if (choice3 == 2)		  
		  {
		  result_polygon = scalePolygon(Q, factor);
		  }
		  printf("\nHere is the polygon representing the scale you wanted to do\n");
        printPolygon2(result_polygon);
        break;
   case 10:
		  printf("\nPlease give the first coordinate (x) of the origin of the translation vector\n");
		  scanf("%lf", &x);
		  printf("\nPlease give the second coordinate (y) of the origin of the vector\n");
		  scanf("%lf", &y);
		  a = createPoint(x,y);

		  printf("\nPlease give the first coordinate (x) of the end of the vector\n");
		  scanf("%lf", &x);
		  printf("\nPlease give the second coordinate (y) of the end of the vector\n");
		  scanf("%lf", &y);
		  b = createPoint(x,y);
	 	  do
		  {
		  printf("\nWhich polygon do you want to use ?\n");
		  printf("1. The first one");
		  printf("2. The second one");
		  scanf("%d", &choice3);
		  }while(choice3 != 1 && choice3 != 2);
        if (choice3 == 1)
		  {
		  result_polygon = translatePolygon(P,a,b);
		  }
		  if (choice3 == 2)
		  {
		  result_polygon = translatePolygon(Q,a,b);
		  }
        
		  printf("\nHere is the polygon representing the translation you wanted to do\n");
		  printPolygon2(result_polygon);
        break;
   case 11:
		  do
		  {
		  printf("\nWhich polygon do you want to use ?\n");
		  printf("1. The first one\n");
		  printf("2. The second one\n");
		  scanf("%d", &choice3);
		  }while(choice3 != 1 && choice3 != 2);
        if (choice == 1)
		  {
		  result_prompt = toString(P);
		  }
		  if (choice == 2)
		  {
		  result_prompt = toString(Q);
		  }
        printf("\nHere is your polygon in a string variable :\n");
		  puts(result_prompt);
        break;
	case 12:
		  printf("\n\nThanks for using this program, it was written by Aurelien DURANCE and Thibault TSAGALOS for the LO27 course :3\n\n");
		  printf("Have a nice day :D\n");
		  end = 2;
   
	}
	while (end != 2 && end != 1)
	{
	printf("\nDo you want to continue to play ?\n\n");
	printf("1. Yes I want to continue to play I love this program\n");
	printf("2. No.\n");
	scanf("%d", &end);
	}
	
	}while (end == 1);
	
return 0;
}





