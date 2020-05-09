//
//  hello.cpp
//  light
//
//  Created by liuhuo wan on 5/5/20.
//  Copyright © 2020 liuhuo wan. All rights reserved.
//

#include <iostream>
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdlib.h>
#include <math.h>

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glShadeModel(GL_MODELVIEW);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glScalef(1.0, 2.0, 1.0);
    glutWireCube(1.0);
    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w,  (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0,  -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

































