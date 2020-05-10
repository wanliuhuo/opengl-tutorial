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
//#include <GLUT/GLUT.h>
#include <GLUT/glut.h>
#include <stdlib.h>


GLfloat diffuseMaterial[4] = {0.5, 0.5, 0.5, 1.0};

void init(void) {
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    //GLfloat mat_shainness[] = {50.0};
    GLfloat light_pos[] = {1.0, 1.0, 1.0, 0.0};
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    
    glEnable(GL_DEPTH_TEST);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, 25.0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidSphere(1.0, 20, 16);
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if (w <= h) {
        glOrtho(-1.5, 1.5, -1.5*(GLfloat) h / (GLfloat) w, 1.5*(GLfloat) h / (GLfloat) w, -10.0,10.0);
    }
    else
        glOrtho(-1.5*(GLfloat) w / (GLfloat) h, 1.5*(GLfloat) w / (GLfloat) h, -1.5, 1.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 'l':
            diffuseMaterial[0] += 0.1;
            if (diffuseMaterial[0] > 1.0)
                diffuseMaterial[0] = 0.0;
            glColor4fv(diffuseMaterial);
            glutPostRedisplay();
            break;
        case 'm':
            diffuseMaterial[1] += 0.1;
            if (diffuseMaterial[1] > 1.0)
                diffuseMaterial[1] = 0.0;
            glColor4fv(diffuseMaterial);
            glutPostRedisplay();
        case 'r':
            diffuseMaterial[2] += 0.1;
            if (diffuseMaterial[2] > 1.0)
                diffuseMaterial[2] = 0.0;
            glColor4fv(diffuseMaterial);
            glutPostRedisplay();
        default:
            break;
    }
    
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GL_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}























