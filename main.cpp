#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define pi 3.142
static GLfloat angle = 0;
static int submenu;
static int mainmenu;
static int value = -1;

void init()
{
    gluOrtho2D(-1000, 1000, -1000, 1000);
}
void circle(float rad)
{
    glBegin(GL_POINTS);
    glColor3f(2, 0, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(rad * cos(i), rad * sin(i));
    }
    glEnd();
}
void drawString(float x, float y, float z, char* string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char* c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);
    }
}

void drawhead(float x, float y, float z, char* string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char* c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}
void drawsubhead(float x, float y, float z, char* string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char* c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}
void nuc(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);
    for (float i = 0; i < (2 * pi); i = i + 0.00001)
    {
        glVertex2f(rad * cos(i), rad * sin(i));
    }
    glEnd();
}
void eleright(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(rad + 20 * cos(i), 20 * sin(i));
    }
    glEnd();
}
void eleleft(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-(rad + 20 * cos(i)), 20 * sin(i));
    }
    glEnd();
}
void eletop(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(20 * cos(i), rad + 20 * sin(i));
    }
    glEnd();
}
void eledown(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(20 * cos(i), -(rad + 20 * sin(i)));
    }
    glEnd();
}
void eletr(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + 20 * cos(i)), ((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}
void eletl(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 175) + 20 * cos(i)), ((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}
void eledl(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 175) + 20 * cos(i)), -((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}
void eledr(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + 20 * cos(i)), -((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}
void display()
{
    glClearColor(0, 0, 0.1, 0.9);

    if (value == -1)
    {
        char cn[] = "RV INSTITUTE OF TECHNOLOGY AND MANAGEMENT";
        drawhead(-620, 900, 0, cn);
        char pn[] = "J.P NAGAR 8TH PHASE";
        drawsubhead(-300, 850, 0, pn);

        char dn[] = "DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING";
        drawhead(-650, 650, 0, dn);

        char prn[] = "A Mini Project On";
        drawsubhead(-150, 450, 0, prn);
        char pro[] = "PERIODIC TABLE SIMULATION";
        drawhead(-250, 350, 0, pro);

        char pb[] = "PROJECT BY: ";
        drawhead(-690, -150, 0, pb);

        char p1[] = "DEERAJ KUMAR V S";
        drawhead(-690, -250, 0, p1);
        char p1u[] = "1RF19CS015";
        drawsubhead(-690, -300, 0, p1u);

        char p2[] = "DARSHAN M";
        drawhead(-690, -400, 0, p2);
        char p2u[] = "1RF19CS028";
        drawsubhead(-690, -450, 0, p2u);

        char gb[] = "GUIDED BY: ";
        drawhead(290, -150, 0, gb);

        char g1[] = "Dr. Mallangouda Patil";
        drawhead(290, -250, 0, g1);
        char d1[] = "Professor, Dept. Of CSE";
        drawsubhead(290, -300, 0, d1);



        char in[] = "Press enter to Continue";
        drawhead(-250, -700, 0, in);

        glutSwapBuffers();
        glutDetachMenu(GLUT_RIGHT_BUTTON);
    }
    if (value != -1)
    {
        nuc(250);
        char n[] = "NUCLEUS";
        drawString(-80, 20, 0, n);
        char d[] = "(NEUTRON + PROTON)";
        drawString(-155, -30, 0, d);
        if (value == 0)
        {
            char nu[] = "SELECT THE ELEMENT USING MENU";
            drawhead(-490, 900, 0, nu);
        }
    }
    if (value == 1)
    {
        char n[] = "HYDROGEN";
        drawhead(-100, 900, 0, n);
        circle(400);
        char o[] = "ORBIT";
        drawString(410, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        char e[] = "ELECTRON";
        drawString(420, 0, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 2)
    {
        char n[] = "HELIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        char o[] = "ORBIT";
        drawString(410, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        char e[] = "ELECTRON";
        drawString(420, 0, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 3)
    {
        char n[] = "LITHIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 4)
    {
        char n[] = "BERYLLIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 5)
    {
        char n[] = "BORON";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 6)
    {
        char n[] = "CARBON";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 7)
    {
        char n[] = "NITROGEN";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 8)
    {
        char n[] = "OXYGEN";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 9)
    {
        char n[] = "FLUORINE";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        eleleft(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 10)
    {
        char n[] = "NEON";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        eleleft(600);
        eleright(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 11)
    {
        char n[] = "SODIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        circle(800);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        eleleft(600);
        eleright(600);
        eletop(800);
        char e[] = "ELECTRON";
        drawString(0, 0, 820, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 12)
    {
        char n[] = "MAGNESIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        circle(800);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        eleleft(600);
        eleright(600);
        eletop(800);
        eledown(800);
        char e[] = "ELECTRON";
        drawString(0, 0, 820, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 13)
    {
        char n[] = "ALUMINIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        circle(800);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        eleleft(600);
        eleright(600);
        eletop(800);
        eledown(800);
        eleleft(800);
        char e[] = "ELECTRON";
        drawString(0, 0, 820, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 14)
    {
        char n[] = "SILICON";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        circle(800);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        eleleft(600);
        eleright(600);
        eletop(800);
        eledown(800);
        eleleft(800);
        eleright(800);
        char e[] = "ELECTRON";
        drawString(0, 0, 820, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 15)
    {
        char n[] = "PHOSPOROUS";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        circle(800);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        eleleft(600);
        eleright(600);
        eletop(800);
        eledown(800);
        eleleft(800);
        eleright(800);
        eledl(800);
        char e[] = "ELECTRON";
        drawString(0, 0, 820, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 16)
    {
        char n[] = "SULPHUR";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        circle(800);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        eleleft(600);
        eleright(600);
        eletop(800);
        eledown(800);
        eleleft(800);
        eleright(800);
        eledl(800);
        eletl(800);
        char e[] = "ELECTRON";
        drawString(0, 0, 820, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 17)
    {
        char n[] = "CHLORINE";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        circle(800);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        eleleft(600);
        eleright(600);
        eletop(800);
        eledown(800);
        eleleft(800);
        eleright(800);
        eledl(800);
        eletl(800);
        eletr(800);
        char e[] = "ELECTRON";
        drawString(0, 0, 820, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 18)
    {
        char n[] = "ARGON";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        circle(800);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        eleleft(600);
        eleright(600);
        eletop(800);
        eledown(800);
        eleleft(800);
        eleright(800);
        eledl(800);
        eledr(800);
        eletr(800);
        eletl(800);
        char e[] = "ELECTRON";
        drawString(0, 0, 820, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 19)
    {
        char n[] = "POTASSIUM";
        drawhead(-100, 900, 0, n);
        circle(300);
        circle(500);
        circle(700);
        circle(900);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        eletop(500);
        eledown(500);
        eletr(500);
        eledl(500);
        eletl(500);
        eledr(500);
        eleleft(500);
        eleright(500);
        eletop(700);
        eledown(700);
        eleleft(700);
        eleright(700);
        eledl(700);
        eledr(700);
        eletr(700);
        eletl(700);
        eletop(900);
        char e[] = "ELECTRON";
        drawString(0, 0, 820, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 20)
    {
        char n[] = "CALCIUM";
        drawhead(-100, 900, 0, n);
        circle(300);
        circle(500);
        circle(700);
        circle(900);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        eletop(500);
        eledown(500);
        eletr(500);
        eledl(500);
        eletl(500);
        eledr(500);
        eleleft(500);
        eleright(500);
        eletop(700);
        eledown(700);
        eleleft(700);
        eleright(700);
        eledl(700);
        eledr(700);
        eletr(700);
        eletl(700);
        eletop(900);
        eledown(900);
        char e[] = "ELECTRON";
        drawString(0, 0, 820, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 21)
    {
        char n[] = "SCANDIUM";
        drawhead(-100, 900, 0, n);
        circle(300);
        circle(500);
        circle(700);
        circle(900);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        eletop(500);
        eledown(500);
        eletr(500);
        eledl(500);
        eletl(500);
        eledr(500);
        eleleft(500);
        eleright(500);
        eletop(725);
        eletop(675);
        eledown(700);
        eleleft(700);
        eleright(700);
        eledl(700);
        eledr(700);
        eletr(700);
        eletl(700);
        eletop(900);
        eledown(900);
        char e[] = "ELECTRON";
        drawString(0, 0, 820, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 22)
    {
        char n[] = "TITANIUM";
        drawhead(-100, 900, 0, n);
        circle(300);
        circle(500);
        circle(700);
        circle(900);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        eletop(500);
        eledown(500);
        eletr(500);
        eledl(500);
        eletl(500);
        eledr(500);
        eleleft(500);
        eleright(500);
        eletop(725);
        eletop(675);
        eledown(725);
        eledown(675);
        eleleft(700);
        eleright(700);
        eledl(700);
        eledr(700);
        eletr(700);
        eletl(700);
        eletop(900);
        eledown(900);
        char e[] = "ELECTRON";
        drawString(0, 0, 820, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 23)
    {
        char n[] = "VANDIUM";
        drawhead(-100, 900, 0, n);
        circle(300);
        circle(500);
        circle(700);
        circle(900);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        eletop(500);
        eledown(500);
        eletr(500);
        eledl(500);
        eletl(500);
        eledr(500);
        eleleft(500);
        eleright(500);
        eletop(725);
        eletop(675);
        eledown(725);
        eledown(675);
        eleleft(725);
        eleleft(675);
        eleright(700);
        eledl(700);
        eledr(700);
        eletr(700);
        eletl(700);
        eletop(900);
        eledown(900);
        char e[] = "ELECTRON";
        drawString(0, 0, 820, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 24)
    {
        char n[] = "CHROMIUM";
        drawhead(-100, 900, 0, n);
        circle(300);
        circle(500);
        circle(700);
        circle(900);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        eletop(500);
        eledown(500);
        eletr(500);
        eledl(500);
        eletl(500);
        eledr(500);
        eleleft(500);
        eleright(500);
        eletop(725);
        eletop(675);
        eledown(725);
        eledown(675);
        eleleft(725);
        eleleft(675);
        eleright(675);
        eleright(725);
        eledl(700);
        eledr(700);
        eletr(700);
        eletl(700);
        eletop(900);
        eledown(900);
        char e[] = "ELECTRON";
        drawString(0, 0, 820, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 25)
    {
        char n[] = "MANGANESE";
        drawhead(-100, 900, 0, n);
        circle(300);
        circle(500);
        circle(700);
        circle(900);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        eletop(500);
        eledown(500);
        eletr(500);
        eledl(500);
        eletl(500);
        eledr(500);
        eleleft(500);
        eleright(500);
        eletop(725);
        eletop(675);
        eledown(725);
        eledown(675);
        eleleft(725);
        eleleft(675);
        eleright(675);
        eleright(725);
        eledl(650);
        eledl(690);
        eledr(700);
        eletr(700);
        eletl(700);
        eletop(900);
        eledown(900);
        char e[] = "ELECTRON";
        drawString(0, 0, 820, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 26)
    {
        char n[] = "IRON";
        drawhead(-100, 900, 0, n);
        circle(300);
        circle(500);
        circle(700);
        circle(900);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        eletop(500);
        eledown(500);
        eletr(500);
        eledl(500);
        eletl(500);
        eledr(500);
        eleleft(500);
        eleright(500);
        eletop(725);
        eletop(675);
        eledown(725);
        eledown(675);
        eleleft(725);
        eleleft(675);
        eleright(675);
        eleright(725);
        eledl(650);
        eledl(690);
        eledr(650);
        eledr(690);
        eletr(700);
        eletl(700);
        eletop(900);
        eledown(900);
        char e[] = "ELECTRON";
        drawString(0, 0, 820, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 27)
    {
        char n[] = "COBALT";
        drawhead(-100, 900, 0, n);
        circle(300);
        circle(500);
        circle(700);
        circle(900);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        eletop(500);
        eledown(500);
        eletr(500);
        eledl(500);
        eletl(500);
        eledr(500);
        eleleft(500);
        eleright(500);
        eletop(725);
        eletop(675);
        eledown(725);
        eledown(675);
        eleleft(725);
        eleleft(675);
        eleright(675);
        eleright(725);
        eledl(650);
        eledl(690);
        eledr(650);
        eledr(690);
        eletr(650);
        eletr(690);
        eletl(700);
        eletop(900);
        eledown(900);
        char e[] = "ELECTRON";
        drawString(0, 0, 820, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 28)
    {
        char n[] = "NICKEL";
        drawhead(-100, 900, 0, n);
        circle(300);
        circle(500);
        circle(700);
        circle(900);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        eletop(500);
        eledown(500);
        eletr(500);
        eledl(500);
        eletl(500);
        eledr(500);
        eleleft(500);
        eleright(500);
        eletop(725);
        eletop(675);
        eledown(725);
        eledown(675);
        eleleft(725);
        eleleft(675);
        eleright(675);
        eleright(725);
        eledl(650);
        eledl(690);
        eledr(650);
        eledr(690);
        eletr(650);
        eletr(690);
        eletl(650);
        eletl(690);
        eletop(900);
        eledown(900);
        char e[] = "ELECTRON";
        drawString(0, 0, 820, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 31)
    {
        char n[] = "GALLIUM";
        drawhead(-100, 900, 0, n);
        circle(300);
        circle(500);
        circle(700);
        circle(900);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        eletop(500);
        eledown(500);
        eletr(500);
        eledl(500);
        eletl(500);
        eledr(500);
        eleleft(500);
        eleright(500);
        eletop(725);
        eletop(675);
        eledown(725);
        eledown(675);
        eleleft(725);
        eleleft(675);
        eleright(675);
        eleright(725);
        eledl(650);
        eledl(690);
        eledr(650);
        eledr(690);
        eletr(650);
        eletr(690);
        eletl(650);
        eletl(690);
        eletop(900);
        eledown(900);
        eleleft(900);
        char e[] = "ELECTRON";
        drawString(0, 0, 820, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    glutSwapBuffers();
}
void rotate()
{
    angle = angle + 1.0;
    if (angle > 360)
    {
        angle = angle - 360;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
}
void mouseControl(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(rotate);
        break;
    default:
        break;
    }
}
void keyboard(unsigned char key, int x, int y)
{
    if (key == 13)
    {
        value = 0;
        glClear(GL_COLOR_BUFFER_BIT);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        glutPostRedisplay();
    }
    else if (key == 's')
    {
        glutIdleFunc(NULL);
    }
    else if (key == 32)
    {
        glutIdleFunc(rotate);
    }
    else if (key == 'q' || key == 'Q')
    {
        exit(0);
    }
    else if (key == 27)
    {
        glutReshapeWindow(700, 700);
    }
}
void fkey(int key, int x, int y)
{

    if (key == GLUT_KEY_F10)
    {
        glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    }
}
void menu(int option)
{
    if (option == 54)
    {
        exit(0);
    }
    else if (option == 52)
    {
        glutIdleFunc(rotate);
    }
    else if (option == 53)
    {
        glutIdleFunc(NULL);
    }
    else if (option == 55) {
        value = -1;
    }
    else
    {
        value = option;
    }
    glClear(GL_COLOR_BUFFER_BIT);

    glutPostRedisplay();
}
void createMenu(void)
{
    submenu = glutCreateMenu(menu);
    glutAddMenuEntry("HYDROGEN", 1);
    glutAddMenuEntry("HELIUM", 2);
    glutAddMenuEntry("LITHIUM", 3);
    glutAddMenuEntry("BERILIUM", 4);
    glutAddMenuEntry("BORON", 5);
    glutAddMenuEntry("CARBON", 6);
    glutAddMenuEntry("NITROGEN", 7);
    glutAddMenuEntry("OXYGEN", 8);
    glutAddMenuEntry("FLUORINE", 9);
    glutAddMenuEntry("NEON", 10);
    glutAddMenuEntry("SODIUM", 11);
    glutAddMenuEntry("MAGNESIUM", 12);
    glutAddMenuEntry("ALUMINIUM", 13);
    glutAddMenuEntry("SILICON", 16);
    glutAddMenuEntry("PHOSPOURUS", 15);
    glutAddMenuEntry("SULPHUR", 16);
    glutAddMenuEntry("CHOLORINE", 17);
    glutAddMenuEntry("ARGON", 18);
    glutAddMenuEntry("POTASSIUM", 19);
    glutAddMenuEntry("CALCIUM", 20);
    glutAddMenuEntry("SCANDIUM", 21);
    glutAddMenuEntry("TITANIUM", 22);
    glutAddMenuEntry("VANADIUM", 23);
    glutAddMenuEntry("CHROMIUM", 24);
    glutAddMenuEntry("MANGANESE", 25);
    glutAddMenuEntry("IRON", 26);
    glutAddMenuEntry("COBALT", 27);
    glutAddMenuEntry("NICKEL", 28);
    glutAddMenuEntry("COPPER", 29);
    glutAddMenuEntry("ZINC", 30);
    glutAddMenuEntry("GALLIUM", 31);
    glutAddMenuEntry("GERMANIUM", 32);
    glutAddMenuEntry("ARSENIC", 34);
    glutAddMenuEntry("SELENIUM", 35);
    glutAddMenuEntry("CHROMIUM", 36);
    glutAddMenuEntry("KRYPTON", 37);
    glutAddMenuEntry("RUBIDIUM", 38);
    glutAddMenuEntry("STRONTIUM", 39);
    glutAddMenuEntry("YTTRIUM", 40);
    glutAddMenuEntry("NIOBIUM", 41);
    glutAddMenuEntry("MOLYBDENUM", 42);
    glutAddMenuEntry("TECHNETIUM", 43);
    glutAddMenuEntry("RUTHENIUM", 44);
    mainmenu = glutCreateMenu(menu);
    glutAddSubMenu("SELECT THE ELEMENT", submenu);
    glutAddMenuEntry("START SIMULATION", 52);
    glutAddMenuEntry("STOP SIMULATION", 53);
    glutAddMenuEntry("GOTO HOME SCREEN", 55);
    glutAddMenuEntry("EXIT", 54);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1024, 800);
    glutCreateWindow("ATOM SIMULATION");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouseControl);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(fkey);
    createMenu();
    glutMainLoop();
    return 0;
}