#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include <time.h>


void drawText(float x, float y, int r, int g, int b, const char *string)
{
	int j = strlen(string);

	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}
void drawText1(float x, float y, int r, int g, int b, const char *string)
{
	int j = strlen(string);

	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
	}
}

void draw_circle(float x, float y, float radius) {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(x, y, 0.0f);
	static const int circle_points = 100;
	static const float angle = 2.0f * 3.1416f / circle_points;

	// this code (mostly) copied from question:
	glBegin(GL_POLYGON);
	double angle1 = 0.0;
	glVertex2d(radius * cos(0.0), radius * sin(0.0));
	int i;
	for (i = 0; i<circle_points; i++)
	{
		glVertex2d(radius * cos(angle1), radius *sin(angle1));
		angle1 += angle;
	}
	glEnd();
	glPopMatrix();
}
void DrawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
}

void table()
{
	glColor3f(0.35, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(46, 50);
	glVertex2f(50, 90);
	glVertex2f(146, 90);
	glVertex2f(150, 50);
	glEnd();
	//leftfrontleg
	glBegin(GL_POLYGON);
	glVertex2f(48.5, 50);
	glVertex2f(49.5, 50);
	glVertex2f(49.5, 20);
	glVertex2f(48.5, 20);
	glEnd();
	//leftbackleg
	glBegin(GL_POLYGON);
	glVertex2f(51, 50);
	glVertex2f(52, 50);
	glVertex2f(52, 30);
	glVertex2f(51, 30);
	glEnd();
	//rightfrontleg
	glBegin(GL_POLYGON);
	glVertex2f(147.5, 50);
	glVertex2f(146.5, 50);
	glVertex2f(146.5, 20);
	glVertex2f(147.5, 20);
	glEnd();
	//rightbackleg
	glBegin(GL_POLYGON);
	glVertex2f(145, 50);
	glVertex2f(144, 50);
	glVertex2f(144, 30);
	glVertex2f(145, 30);
	glEnd();
}
void indian(float x, float y)
{
	//legs
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0, 0);
	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x + 01, y + 2);
	glVertex2f(x, y + 2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0, 0);
	glVertex2f(x + 3, y);
	glVertex2f(x + 4, y);
	glVertex2f(x + 4, y + 02);
	glVertex2f(x + 3, y + 02);
	glEnd();
	//shoes
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(x - 0.5, y - 1);
	glVertex2f(x + 1, y - 1);
	glVertex2f(x + 1, y);
	glVertex2f(x - 0.5, y);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(x + 3, y - 1);
	glVertex2f(x + 4.5, y - 1);
	glVertex2f(x + 4.5, y);
	glVertex2f(x + 3, y);
	glEnd();
	//short
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(x - 0.5, y + 2);
	glVertex2f(x + 4.5, y + 2);
	glVertex2f(x + 4.5, y + 5);
	glVertex2f(x - 0.5, y + 5);
	glEnd();
	//shirt
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0);
	glVertex2f(x - 0.5, y + 5);
	glVertex2f(x + 4.5, y + 5);
	glVertex2f(x + 4.5, y + 9);
	glVertex2f(x - 0.5, y + 9);
	glEnd();
	//neck
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0, 0);
	glVertex2f(x + 1, y + 9);
	glVertex2f(x + 3, y + 9);
	glVertex2f(x + 3, y + 10.5);
	glVertex2f(x + 1, y + 10.5);
	glEnd();
	//hair
	glColor3f(0, 0, 0);
	draw_circle(x + 2, y + 13, 2);
	//face
	glColor3f(0.5, 0, 0);
	draw_circle(x + 2, y + 12, 2);
	//hands
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0, 0);
	glVertex2f(x + 4.5, y + 4);
	glVertex2f(x + 5.5, y + 4);
	glVertex2f(x + 5.5, y + 9);
	glVertex2f(x + 4.5, y + 9);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0, 0);
	glVertex2f(x - 1.5, y + 4);
	glVertex2f(x - 0.5, y + 4);
	glVertex2f(x - 0.5, y + 9);
	glVertex2f(x - 1.5, y + 9);
	glEnd();
}
void ukpolice(float x, float y)
{
	//legs
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x + 01, y + 2);
	glVertex2f(x, y + 2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(x + 3, y);
	glVertex2f(x + 4, y);
	glVertex2f(x + 4, y + 02);
	glVertex2f(x + 3, y + 02);
	glEnd();
	//shoes
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(x - 0.5, y - 1);
	glVertex2f(x + 1, y - 1);
	glVertex2f(x + 1, y);
	glVertex2f(x - 0.5, y);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(x + 3, y - 1);
	glVertex2f(x + 4.5, y - 1);
	glVertex2f(x + 4.5, y);
	glVertex2f(x + 3, y);
	glEnd();
	//short
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(x - 0.5, y + 2);
	glVertex2f(x + 4.5, y + 2);
	glVertex2f(x + 4.5, y + 5);
	glVertex2f(x - 0.5, y + 5);
	glEnd();
	//shirt
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1.0);
	glVertex2f(x - 0.5, y + 5);
	glVertex2f(x + 4.5, y + 5);
	glVertex2f(x + 4.5, y + 9);
	glVertex2f(x - 0.5, y + 9);
	glEnd();
	//neck
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(x + 1, y + 9);
	glVertex2f(x + 3, y + 9);
	glVertex2f(x + 3, y + 10.5);
	glVertex2f(x + 1, y + 10.5);
	glEnd();
	//hair
	glColor3f(0, 0, 0);
	draw_circle(x + 2, y + 13, 2);
	//face
	glColor3f(1, 1, 0);
	draw_circle(x + 2, y + 12, 2);
	//hands
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(x + 4.5, y + 4);
	glVertex2f(x + 5.5, y + 4);
	glVertex2f(x + 5.5, y + 9);
	glVertex2f(x + 4.5, y + 9);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(x - 1.5, y + 4);
	glVertex2f(x - 0.5, y + 4);
	glVertex2f(x - 0.5, y + 9);
	glVertex2f(x - 1.5, y + 9);
	glEnd();
}
void littleboys(float x, float y)
{
	//legs
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x + 01, y + 2);
	glVertex2f(x, y + 2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(x + 3, y);
	glVertex2f(x + 4, y);
	glVertex2f(x + 4, y + 02);
	glVertex2f(x + 3, y + 02);
	glEnd();
	//shoes
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(x - 0.5, y - 1);
	glVertex2f(x + 1, y - 1);
	glVertex2f(x + 1, y);
	glVertex2f(x - 0.5, y);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(x + 3, y - 1);
	glVertex2f(x + 4.5, y - 1);
	glVertex2f(x + 4.5, y);
	glVertex2f(x + 3, y);
	glEnd();
	//short
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(x - 0.5, y + 2);
	glVertex2f(x + 4.5, y + 2);
	glVertex2f(x + 4.5, y + 5);
	glVertex2f(x - 0.5, y + 5);
	glEnd();
	//shirt
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0.40);
	glVertex2f(x - 0.5, y + 5);
	glVertex2f(x + 4.5, y + 5);
	glVertex2f(x + 4.5, y + 9);
	glVertex2f(x - 0.5, y + 9);
	glEnd();
	//neck
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(x + 1, y + 9);
	glVertex2f(x + 3, y + 9);
	glVertex2f(x + 3, y + 10.5);
	glVertex2f(x + 1, y + 10.5);
	glEnd();
	//hair
	glColor3f(0, 0, 0);
	draw_circle(x + 2, y + 13, 2);
	//face
	glColor3f(1, 1, 0);
	draw_circle(x + 2, y + 12, 2);
	//hands
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(x + 4.5, y + 4);
	glVertex2f(x + 5.5, y + 4);
	glVertex2f(x + 5.5, y + 9);
	glVertex2f(x + 4.5, y + 9);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(x - 1.5, y + 4);
	glVertex2f(x - 0.5, y + 4);
	glVertex2f(x - 0.5, y + 9);
	glVertex2f(x - 1.5, y + 9);
	glEnd();
}
void littleboys1(float x, float y)
{
	//legs
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x + 01, y + 2);
	glVertex2f(x, y + 2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(x + 3, y);
	glVertex2f(x + 4, y);
	glVertex2f(x + 4, y + 02);
	glVertex2f(x + 3, y + 02);
	glEnd();
	//shoes
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(x - 0.5, y - 1);
	glVertex2f(x + 1, y - 1);
	glVertex2f(x + 1, y);
	glVertex2f(x - 0.5, y);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(x + 3, y - 1);
	glVertex2f(x + 4.5, y - 1);
	glVertex2f(x + 4.5, y);
	glVertex2f(x + 3, y);
	glEnd();
	//short
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(x - 0.5, y + 2);
	glVertex2f(x + 4.5, y + 2);
	glVertex2f(x + 4.5, y + 5);
	glVertex2f(x - 0.5, y + 5);
	glEnd();
	//shirt
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0.45);
	glVertex2f(x - 0.5, y + 5);
	glVertex2f(x + 4.5, y + 5);
	glVertex2f(x + 4.5, y + 9);
	glVertex2f(x - 0.5, y + 9);
	glEnd();
	//neck
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(x + 1, y + 9);
	glVertex2f(x + 3, y + 9);
	glVertex2f(x + 3, y + 10.5);
	glVertex2f(x + 1, y + 10.5);
	glEnd();
	//hair
	glColor3f(0, 0, 0);
	draw_circle(x + 2, y + 13, 2);
	//face
	glColor3f(1, 1, 0);
	draw_circle(x + 2, y + 12, 2);
	//hands
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(x + 4.5, y + 4);
	glVertex2f(x + 5.5, y + 4);
	glVertex2f(x + 5.5, y + 9);
	glVertex2f(x + 4.5, y + 9);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(x - 1.5, y + 4);
	glVertex2f(x - 0.5, y + 4);
	glVertex2f(x - 0.5, y + 9);
	glVertex2f(x - 1.5, y + 9);
	glEnd();
}
void indianflag() {
	//orange
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.0);
	glVertex2f(55, 85);
	glVertex2f(65, 85);
	glVertex2f(65, 82);
	glVertex2f(55, 82);
	glEnd();
	//white
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(55, 82);
	glVertex2f(65, 82);
	glVertex2f(65, 79);
	glVertex2f(55, 79);
	glEnd();
	//green
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(55, 79);
	glVertex2f(65, 79);
	glVertex2f(65, 76);
	glVertex2f(55, 76);
	glEnd();
	//ashokachakra
	glColor3f(0, 0, 1);
	DrawCircle(60, 80.5, 1.5, 30);
	//stick
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(54.5, 85);
	glVertex2f(55, 85);
	glVertex2f(55, 70);
	glVertex2f(54.5, 70);
	glEnd();
	//base
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(52, 70);
	glVertex2f(57.5, 70);
	glVertex2f(57.5, 65);
	glVertex2f(52, 65);
	glEnd();
}

void ukflag()
{
	//blue
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(135, 85);
	glVertex2f(145, 85);
	glVertex2f(145, 76);
	glVertex2f(135, 76);
	glEnd();
	//white stripes
	glColor3f(1, 1, 1);
	//horizontal
	glBegin(GL_POLYGON);
	glVertex2f(135, 81);
	glVertex2f(145, 81);
	glVertex2f(145, 79.5);
	glVertex2f(135, 79.5);
	glEnd();
	//vertical
	glBegin(GL_POLYGON);
	glVertex2f(139.5, 85);
	glVertex2f(141, 85);
	glVertex2f(141, 76);
	glVertex2f(139.5, 76);
	glEnd();
	//cross
	glBegin(GL_POLYGON);
	glVertex2f(135, 85);
	glVertex2f(136, 85);
	glVertex2f(145, 77);
	glVertex2f(145, 76);
	glVertex2f(144, 76);
	glVertex2f(135, 84);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(145, 85);
	glVertex2f(145, 84);
	glVertex2f(136, 76);
	glVertex2f(135, 76);
	glVertex2f(135, 77);
	glVertex2f(144, 85);
	glEnd();
	//red stripes
	glColor3f(1, 0, 0);
	//horizontal
	glBegin(GL_POLYGON);
	glVertex2f(135, 80.75);
	glVertex2f(145, 80.75);
	glVertex2f(145, 79.75);
	glVertex2f(135, 79.75);
	glEnd();
	//vertical
	glBegin(GL_POLYGON);
	glVertex2f(139.75, 85);
	glVertex2f(140.75, 85);
	glVertex2f(140.75, 76);
	glVertex2f(139.75, 76);
	glEnd();
	//cross
	glBegin(GL_POLYGON);
	glVertex2f(135, 85);
	glVertex2f(135.5, 85);
	glVertex2f(145, 76.5);
	glVertex2f(145, 76);
	glVertex2f(144.5, 76);
	glVertex2f(135, 84.5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(145, 85);
	glVertex2f(145, 84.5);
	glVertex2f(135.5, 76);
	glVertex2f(135, 76);
	glVertex2f(135, 76.5);
	glVertex2f(144.5, 85);
	glEnd();
	//stick
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(134.5, 85);
	glVertex2f(135, 85);
	glVertex2f(135, 70);
	glVertex2f(134.5, 70);
	glEnd();
	//base
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(132, 70);
	glVertex2f(137.5, 70);
	glVertex2f(137.5, 65);
	glVertex2f(132, 65);
	glEnd();
}

void zameen()
{
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex2f(0, 80);
	glVertex2f(250, 80);
	glVertex2f(250, 0);
	glVertex2f(0, 0);
	glEnd();
}

void windows()
{
	//left
	glColor3f(0.5, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(15, 115);
	glVertex2f(15, 132);
	glVertex2f(30, 132);
	glVertex2f(30, 115);
	glEnd();
	//centre
	glBegin(GL_POLYGON);
	glVertex2f(85, 120);
	glVertex2f(85, 137);
	glVertex2f(100, 137);
	glVertex2f(100, 120);
	glEnd();
	//right
	glBegin(GL_POLYGON);
	glVertex2f(165, 110);
	glVertex2f(165, 127);
	glVertex2f(180, 127);
	glVertex2f(180, 110);
	glEnd();
}

void building1()
{
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);
	glVertex2f(0, 150);
	glVertex2f(40, 150);
	glVertex2f(40, 85);
	glVertex2f(0, 85);
	glEnd();
	glColor3f(0, 0, 1);
	//windows
	for (int i = 0;i<4;i++)
		for (int j = 0;j<4;j++)
		{
			glBegin(GL_POLYGON);
			glVertex2f(2 + (i * 10), 140 - (j * 10));
			glVertex2f(6 + (i * 10), 140 - (j * 10));
			glVertex2f(6 + (i * 10), 135 - (j * 10));
			glVertex2f(2 + (i * 10), 135 - (j * 10));
			glEnd();
		}
	//door
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(15, 85);
	glVertex2f(15, 102);
	glVertex2f(25, 102);
	glVertex2f(25, 85);
	glEnd();
}

void building2()
{
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(40, 150);
	glVertex2f(90, 150);
	glVertex2f(90, 85);
	glVertex2f(40, 85);
	glEnd();
	glColor3f(1, 0, 0);
	//windows
	for (int i = 0;i<5;i++)
		for (int j = 0;j<4;j++)
		{
			glBegin(GL_POLYGON);
			glVertex2f(43 + (i * 10), 140 - (j * 10));
			glVertex2f(47 + (i * 10), 140 - (j * 10));
			glVertex2f(47 + (i * 10), 135 - (j * 10));
			glVertex2f(43 + (i * 10), 135 - (j * 10));
			glEnd();
		}
	//door
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(55, 85);
	glVertex2f(55, 102);
	glVertex2f(65, 102);
	glVertex2f(65, 85);
	glEnd();
}
void building3()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.0);
	glVertex2f(90, 130);
	glVertex2f(170, 130);
	glVertex2f(170, 85);
	glVertex2f(90, 85);
	glEnd();
	glColor3f(0.5, 0.5, 0.5);
	//windows
	for (int i = 0;i<8;i++)
		for (int j = 0;j<4;j++)
		{
			glBegin(GL_POLYGON);
			glVertex2f(92 + (i * 10), 125 - (j * 10));
			glVertex2f(96 + (i * 10), 125 - (j * 10));
			glVertex2f(96 + (i * 10), 120 - (j * 10));
			glVertex2f(92 + (i * 10), 120 - (j * 10));
			glEnd();
		}
}
void building4()
{
	glBegin(GL_POLYGON);
	glColor3f(0.85, 0, 0.15);
	glVertex2f(170, 150);
	glVertex2f(210, 150);
	glVertex2f(210, 85);
	glVertex2f(170, 85);
	glEnd();
	glColor3f(0.85, 0.85, 0.85);
	//windows
	for (int i = 0;i<4;i++)
		for (int j = 0;j<4;j++)
		{
			glBegin(GL_POLYGON);
			glVertex2f(172 + (i * 10), 140 - (j * 10));
			glVertex2f(176 + (i * 10), 140 - (j * 10));
			glVertex2f(176 + (i * 10), 135 - (j * 10));
			glVertex2f(172 + (i * 10), 135 - (j * 10));
			glEnd();
		}
	//door
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(185, 85);
	glVertex2f(185, 102);
	glVertex2f(195, 102);
	glVertex2f(195, 85);
	glEnd();
}
void skyandtrees()
{
	glColor3f(0.5, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(90, 130);
	glVertex2f(170, 130);
	glVertex2f(170, 150);
	glVertex2f(90, 150);
	glEnd();
	//tree topleft
	GLint x = 20;
	GLint y = 75;
	for (int i = 0; i <3; i++)
	{
		glBegin(GL_POLYGON);
		glColor3f(0.15, 0, 0);
		glVertex2i(x, y);
		glVertex2i(x + 2, y);
		glVertex2i(x + 2, y + 8);
		glVertex2i(x, y + 8);
		glEnd();
		glColor3f(0, 0.35, 0);
		draw_circle(x + 1, y + 12, 5);
		x = x + 20;

	}
	//tree bottomleft
	x = 20;
	y = 15;
	for (int i = 0; i < 2; i++)
	{
		glBegin(GL_POLYGON);
		glColor3f(0.15, 0, 0);
		glVertex2i(x, y);
		glVertex2i(x + 2, y);
		glVertex2i(x + 2, y + 8);
		glVertex2i(x, y + 8);
		glEnd();
		glColor3f(0, .35, 0);
		draw_circle(x + 1, y + 12, 5);
		x = x + 20;
	}
	//tree topright
	x = 148;
	y = 75;
	for (int i = 0; i < 2; i++)
	{
		glBegin(GL_POLYGON);
		glColor3f(0.15, 0, 0);
		glVertex2i(x, y);
		glVertex2i(x + 2, y);
		glVertex2i(x + 2, y + 8);
		glVertex2i(x, y + 8);
		glEnd();
		glColor3f(0, 0.35, 0);
		draw_circle(x - 1, y + 10.5, 3.5);
		draw_circle(x + 1, y + 14, 3.5);
		draw_circle(x + 3, y + 10.5, 3.5);
		x = x + 20;
	}
	//tree bottomright
	x = 148;
	y = 15;
	for (int i = 0; i < 3; i++)
	{
		glBegin(GL_POLYGON);
		glColor3f(0.15, 0, 0);
		glVertex2i(x, y);
		glVertex2i(x + 2, y);
		glVertex2i(x + 2, y + 8);
		glVertex2i(x, y + 8);
		glEnd();
		glColor3f(0, 0.35, 0);
		draw_circle(x - 1, y + 10.5, 3.5);
		draw_circle(x + 1, y + 14, 3.5);
		draw_circle(x + 3, y + 10.5, 3.5);
		x = x + 20;
	}
	//sun
	glColor3f(1, 1, 0);
	draw_circle(150, 140, 5);
}
void banner() {
	//left stick
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(71.5, 55);
	glVertex2f(72, 55);
	glVertex2f(72, 100);
	glVertex2f(71.5, 100);
	glEnd();
	//right stick
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(126.5, 55);
	glVertex2f(127, 55);
	glVertex2f(127, 100);
	glVertex2f(126.5, 100);
	glEnd();
	//banner
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(72, 100);
	glVertex2f(126.5, 100);
	glVertex2f(126.5, 80);
	glVertex2f(72, 80);
	glEnd();
}
void quad(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h)
{
	glBegin(GL_POLYGON);
	glVertex2f(a, b);
	glVertex2f(c, d);
	glVertex2f(e, f);
	glVertex2f(g, h);
	glEnd();
}
void DrawEllipse(float cx, float cy, float rx, float ry, int num_segments)
{
	float theta = 2 * 3.1415926 / float(num_segments);
	float c = cosf(theta);//precalculate the sine and cosine
	float s = sinf(theta);
	float t;

	float x = 1;//we start at angle = 0 
	float y = 0;

	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		//apply radius and offset
		glVertex2f(x * rx + cx, y * ry + cy);//output vertex 

											//apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	glEnd();
}
void blackflags(float x, float y) {
	//stick
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(x - 0.5, y);
	glVertex2f(x, y);
	glVertex2f(x, y + 20);
	glVertex2f(x - 0.5, y + 20);
	glEnd();
	//flag
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(x, y + 20);
	glVertex2f(x + 4.5, y + 20);
	glVertex2f(x + 4.5, y + 15);
	glVertex2f(x, y + 15);
	glEnd();
}
void delay(float secs)
{
	float end = clock() / CLOCKS_PER_SEC + secs;
	while ((clock() / CLOCKS_PER_SEC) < end);
}



void window1(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	zameen();
	for (int i = 0;i<50;i += 10) {
		littleboys(51 + i, 85);
	}
	for (int i = 50;i<100;i += 10) {
		littleboys1(51 + i, 85);
	}
	table();
	indianflag();
	ukflag();
	windows();
	glFlush();

}

void window2(void)
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	building1();
	building2();
	building3();
	building4();
	skyandtrees();
	for (i = 0;i<14;i++)
		indian(32 + i * 10,65);
	for (i = 0;i<8;i++)
		ukpolice(60 + i * 10, 17);

}
void window3(void)
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	building1();
	building2();
	building3();
	building4();
	skyandtrees();
	for (i = 0;i<14;i++) {
		if (i % 2 == 0) {
			littleboys(32 + i * 10, 50);
		}
		else {
			littleboys1(32 + i * 10, 50);
		}
	}
	for (i = 3;i<11;i++) {
		if (i % 2 == 0) {
			littleboys(32 + i * 10, 20);
		}
		else {
			littleboys1(32 + i * 10, 20);
		}
	}
	banner();
	for (i = 0;i<40;i += 10) {
		blackflags(32 + i, 55);
		blackflags(132 + i, 55);
		blackflags(82 + i, 55);
	}
	for (i = 3;i<11;i++) {
		blackflags(32 + i * 10, 25);
	}
	drawText(80, 87, 1, 0, 0, "SIMON ..  GO .. BACK !!!");

	glFlush();
}

void window4(void)
{
	
}


void screen1()
{
	glClearColor(1.0, 0.45, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 200, 0, 150);
	window1();
	glutSwapBuffers();
}
void screen2()
{
	glClearColor(0.0, 0.85, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 200, 0, 150);
	window2();
	glutSwapBuffers();

}
void screen3()
{
	glClearColor(0.0, 0.85, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 200, 0, 150);
	window3();
	glutSwapBuffers();
}
void screen4()
{


}
void manual()
{

	glClearColor(0.184, 0.310, 0.310, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawText(20, 120, 1, 0, 0, "CONTENTS");
	drawText(30, 100, 1.000, 0.271, 0.000, "Press 's' to go back to Home Page");
	drawText(30, 80, 1.000, 0.271, 0.000, "press '1' to goto First window ");
	drawText(30, 60, 1.000, 0.271, 0.000, "press '2' to goto Second window");
	drawText(30, 40, 1.000, 0.271, 0.000, "press '3' to goto third window");
	drawText(30, 20, 1.000, 0.271, 0.000, "press '4' to goto third window");

	drawText(20, 0, 1.000, 0.271, 0.000, "press 'q' to Exit");

	glEnd();
	glFlush();
	glutSwapBuffers();
}
void Normalkey(unsigned char k, int x, int y)
{
	switch (k)
	{
	case 'm':manual();
		break;
	case '1':screen1();
		break;
	case '2':screen2();
		break;
	case '3':screen3();
		break;
	case '4':screen4();
		break;

	case 'q': exit(0);
	default:exit(0);
	}
}


void display()
{
	glClearColor(0.184, 0.310, 0.310, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawText(60, 130, 1, 1, 1, "PROJECT TITLE:");
	drawText(40, 120, 1, 0, 1, "INDIA'S STRUGGLE FOR INDEPENDENCE");

	drawText(10, 110, 1, 1, 1, "Developed By:");

	drawText(20, 100, 0, 1, 1, " AYUSH SHRIVASTAVA");
	drawText(25, 90, 1, 1, 1, "(1DS15CS033)");

	drawText(20, 80, 0, 1, 1, "AKASH RAI");
	drawText(25, 70, 1, 1, 1, "(1DS15CS009)");

	drawText(20, 60, 0, 1, 1, "ANUJ AGARWAL");
	drawText(25, 50, 1, 1, 1, "(1DS15CS018)");


	drawText(75, 110, 1, 1, 1, "Under the guidance of :");
	drawText(100, 100, 0, 1, 1, "Prof.Pramitha pai");
	drawText1(100, 95, 1, 1, 1, "Assistant Professor,Dept of CSE");

	drawText(100, 80, 0, 1, 1, "Prof.Kusuma");
	drawText1(100, 75, 1, 1, 1, " Professor,Dept of CSE");

	drawText(100, 60, 0, 1, 1, "Prof.Shuba Bhut");
	drawText1(100, 55, 1, 1, 1, "Assistant Professor,Dept of CSE");


	drawText(50, 30, 1, 1, 0, "PRESS 'M' FOR MANUAL PAGE");
	glEnd();
	glFlush();

	glutSwapBuffers();
}
void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	//glColor3f(0.686, 0.933, 0.933);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 200, 0, 150);
}
void main(int argc, char** argv)

{


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1500, 900);
	glutCreateWindow("War and Peace");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(Normalkey);
	glutMainLoop();

}
