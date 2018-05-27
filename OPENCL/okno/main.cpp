#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <OpenCL/opencl.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <iomanip>
#include <fstream>

using namespace std;

struct delta
{
    double dx;
    double dy;
    double dz;
};

static int ile_iteracji = 10000;
delta lorenz[3][20001];
int sigma = 10;
double beta = 8/3;
int ro = 28;

double xp(double x, double y)
{
    return( sigma *(y - x));
}

double yp(double x, double y, double z)
{
    return(x * (ro - z) - y);
}

double zp(double x, double y, double z)
{
    return( x * y - beta * z);
}

void RK(double dh, int t, delta *lorenz)
{
    double x,y,z,k1x,k2x,k3x,k4x,k1y,k2y,k3y,k4y,k1z,k2z,k3z,k4z,dx,dy,dz,a,b,c,h;
    
    x = lorenz[t].dx;
    y = lorenz[t].dy;
    z = lorenz[t].dz;
    
    h = dh;
    k1x = xp(x,y);
    k1y = yp(x,y,z);
    k1z = zp(x,y,z);
    
    k2x=xp((x+(h*k1x)/2.),(y+(h*k1y)/2.));
    k2y=yp((x+(h*k1x)/2.) ,(y+(h*k1y)/2.),(z+(h*k1z)/2.));
    k2z=zp((x+(h*k1x)/2.),(y+(h*k1y)/2.),(z+(h*k1z)/2.));
    
    //  h+=dh/2;
    k3x=xp((x+(h*k2x)/2.),(y+(h*k2y)/2.));
    k3y=yp((x+(h*k2x)/2.),(y+(h*k2y)/2.),(z+(h*k2z)/2.));
    k3z=zp((x+(h*k2x)/2.),(y+(h*k2y)/2.),(z+(h*k2z)/2.));
    
    //  h+=dh;
    k4x=xp((x+h*k3x),(y+h*k3y));
    k4y=yp((x+h*k3x),(y+h*k3y),(z+h*k3z));
    k4z=zp((x+h*k3x),(y+h*k3y),(z+h*k3z));
    
    dx = h*(k1x + 2 * k2x + 2 * k3x + k4x) /6.;
    dy = h*(k1y + 2 * k2y + 2 * k3y + k4y) /6.;
    dz = h*(k1z + 2 * k2z + 2 * k3z + k4z) /6.;
    
    a = x + dx;
    b = y + dy;
    c = z + dz;
    
    lorenz[t+1].dx = a;
    lorenz[t+1].dy = b;
    lorenz[t+1].dz = c;
    //    cout<< a << " "<< endl;
}

void dane()
{
    double h = 0.01;   //step size
    lorenz[0][0].dx = 1;
    lorenz[0][0].dy = 1;
    lorenz[0][0].dz = 1;
    
    lorenz[1][0].dx = 10;
    lorenz[1][0].dy = 10;
    lorenz[1][0].dz = 10;
    
    lorenz[2][0].dx = 5;
    lorenz[2][0].dy = 5;
    lorenz[2][0].dz = 5;
    
    for (int i=0; i<3; i++)
    {
        for (int t=0; t<ile_iteracji; t++)
        {
            RK(h , t, lorenz[i]);
        }
    }
}

void display(void)
{
    /*  clear all pixels  */
    glClear (GL_COLOR_BUFFER_BIT);
    
    
    /*  draw white polygon (rectangle) with corners at
     *  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
     */
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    for (int i=0; i<ile_iteracji; i++)
    {
        glVertex3f (lorenz[0][i].dx, lorenz[0][i].dy, lorenz[0][i].dz);
    }
    glEnd();
    
    glColor3f (1.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    for (int i=0; i<ile_iteracji; i++)
    {
        glVertex3f (lorenz[1][i].dx, lorenz[1][i].dy, lorenz[1][i].dz);
    }
    glEnd();
    
    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    for (int i=0; i<ile_iteracji; i++)
    {
        glVertex3f (lorenz[2][i].dx, lorenz[2][i].dy, lorenz[2][i].dz);
    }
    glEnd();
    
    /*  don't wait!
     *  start processing buffered OpenGL routines
     */
    glFlush ();
}

void init (void)
{
    /*  select clearing (background) color       */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    
    /*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-7.0, 50.0, -30.0, 35.0, -50.0, 50.0);
    
    // move camera a distance r away from the center
    //glTranslatef(0, 0, -r);
    
    // rotate
    glRotatef(45, 0, 1, 0);
    glRotatef(30, 0, 0, 1);
    //glRotatef(anglex, 1, 0, 0);
    
    // move to center of circle
    //glTranslatef(-cx, -cy, -cz)
}

/*
 *  Declare initial window size, position, and display mode
 *  (single buffer and RGBA).  Open window with "hello"
 *  in its title bar.  Call initialization routines.
 *  Register callback function to display graphics.
 *  Enter main loop and process events.
 */
int main(int argc, char** argv)
{
    dane();
    //cout<< lorenz[0][1].dx<<" "<<lorenz[1][1].dx<< " "<< lorenz[2][1].dx;
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (750, 750);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;   /* ISO C requires main to return int. */
}
