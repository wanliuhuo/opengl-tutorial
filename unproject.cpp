//
//  unproject.cpp
//  light
//
//  Created by liuhuo wan on 9/5/20.
//  Copyright © 2020 liuhuo wan. All rights reserved.
//

#include <stdio.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>
#include <stdlib.h>

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat) w / (GLfloat) h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void mouse(int button, int state, int x, int y) {
    GLint viewport[4];
    GLdouble mvmatrix[16], projmatrix[16];
    GLint realy;
    GLdouble wx, wy, wz;
    
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN) {
                glGetIntegerv(GL_VIEWPORT, viewport);
                glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
                glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);
                realy = viewport[3] - (GLint) y -1 ;
                printf("Coordinates at cursor are (%4d, %4d) \n", x, realy);
                gluUnProject((GLdouble) x, (GLdouble) realy, 0.0, mvmatrix, projmatrix, viewport, &wx, &wy, &wz);
                printf("Word coordinates at z = 1.0 are (%f, %f, %f)\n", wx, wy, wz);
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN) {
                exit(0);
            }
            break;
            
        default:
            break;
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}























