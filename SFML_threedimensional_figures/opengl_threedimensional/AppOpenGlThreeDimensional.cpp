#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <math.h> 

void CreateTriangle();
void CreateCircle();
void CreateSquare();
void createCircleColor(int numberOfIterations, int iteration);

int main(int argc, char* argv[])
{
	GLfloat rotate_x = 0;
	GLfloat rotate_y = 0;
	
	sf::Window window(sf::VideoMode(600, 600), "OpenGL SFLM", sf::Style::Default, sf::ContextSettings(32));
	sf::Image image;
	image.create(16, 16);
	for (int i = 0; i < 16; ++i)
		for (int j = 0; j < 16; ++j)
			image.setPixel(i, j, {
				(sf::Uint8)(i * 16), (sf::Uint8)(j * 16), 0 });

	window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
	window.setVerticalSyncEnabled(true);
	window.setActive(true);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::Resized) {
				glViewport(0, 0, event.size.width, event.size.height);
			}
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		rotate_x += 0.5;
		rotate_y += 0.5;

		glLoadIdentity();
		glEnable(GL_DEPTH_TEST);

		glRotatef(rotate_x, 1.0, 0.0, 0.0);
		glRotatef(rotate_y, 0.0, 1.0, 0.0);

		//CreateSquare();
		//CreateTriangle();
		CreateCircle();

		glFlush();

		window.display();
	}

	return 0;
}


void CreateSquare()
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0); glVertex3f(-0.5, -0.5, -0.5);
	glColor3f(1.0, 1.0, 1.0); glVertex3f(-0.5, 0.5, -0.5);
	glColor3f(1.0, 0.0, 0.0); glVertex3f(0.5, 0.5, -0.5);
	glColor3f(0.0, 1.0, 0.0); glVertex3f(0.5, -0.5, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0); glVertex3f(0.5, -0.5, 0.5);
	glColor3f(0.0, 0.0, 1.0); glVertex3f(0.5, 0.5, 0.5);
	glColor3f(0.0, 1.0, 0.0); glVertex3f(-0.5, 0.5, 0.5);
	glColor3f(1.0, 0.0, 0.0); glVertex3f(-0.5, -0.5, 0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0); glVertex3f(0.5, -0.5, -0.5);
	glColor3f(1.0, 0.0, 0.0); glVertex3f(0.5, 0.5, -0.5);
	glColor3f(0.0, 0.0, 1.0); glVertex3f(0.5, 0.5, 0.5);
	glColor3f(1.0, 1.0, 1.0); glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0); glVertex3f(-0.5, -0.5, 0.5);
	glColor3f(0.0, 1.0, 0.0); glVertex3f(-0.5, 0.5, 0.5);
	glColor3f(1.0, 1.0, 1.0); glVertex3f(-0.5, 0.5, -0.5);
	glColor3f(0.0, 0.0, 1.0); glVertex3f(-0.5, -0.5, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0); glVertex3f(0.5, 0.5, 0.5);
	glColor3f(1.0, 0.0, 0.0); glVertex3f(0.5, 0.5, -0.5);
	glColor3f(1.0, 1.0, 1.0); glVertex3f(-0.5, 0.5, -0.5);
	glColor3f(0.0, 1.0, 0.0); glVertex3f(-0.5, 0.5, 0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0); glVertex3f(0.5, -0.5, -0.5);
	glColor3f(1.0, 1.0, 1.0); glVertex3f(0.5, -0.5, 0.5);
	glColor3f(1.0, 0.0, 0.0); glVertex3f(-0.5, -0.5, 0.5);
	glColor3f(0.0, 0.0, 1.0); glVertex3f(-0.5, -0.5, -0.5);
	glEnd();
}

void CreateTriangle()
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0); glVertex3f(-0.5, -0.5, -0.5);
	glColor3f(0.0, 1.0, 0.0); glVertex3f(0.0, 0.5, -0.5);
	glColor3f(1.0, 0.0, 0.0); glVertex3f(0.5, -0.5, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0); glVertex3f(-0.5, -0.5, -0.5);
	glColor3f(1.0, 1.0, 1.0); glVertex3f(0.0, 0.0, 0.5);
	glColor3f(0.0, 1.0, 0.0); glVertex3f(0.0, 0.5, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.1, 0.0); glVertex3f(0.0, 0.5, -0.5);
	glColor3f(1.0, 1.0, 1.0); glVertex3f(0.0, 0.0, 0.5);
	glColor3f(1.0, 0.0, 0.0); glVertex3f(0.5, -0.5, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.1); glVertex3f(-0.5, -0.5, -0.5);
	glColor3f(1.0, 1.0, 1.0); glVertex3f(0.0, 0.0, 0.5);
	glColor3f(1.0, 0.0, 0.0); glVertex3f(0.5, -0.5, -0.5);
	glEnd();
}

void CreateCircle()
{
	double r = 0.9; //радиус сферы
	int nx = 40;	//число сегментов по X
	int ny = 30;	//число сегментов по Y

	double dnx = 1.0 / (double)nx;
	double dny = 1.0 / (double)ny;

	glBegin(GL_QUAD_STRIP);
	double piy = M_PI * dny;
	double pix = M_PI * dnx;
	for (int iy = 0; iy < ny; iy++)
	{
		double diy = (double)iy;
		double ay = diy * piy;
		double sy = sin(ay);
		double cy = cos(ay);
		double ty = diy * dny;
		double ay1 = ay + piy;
		double sy1 = sin(ay1);
		double cy1 = cos(ay1);
		double ty1 = ty + dny;
		for (int ix = 0; ix <= nx; ix++)
		{
			double ax = 2.0 * ix * pix;
			double sx = sin(ax);
			double cx = cos(ax);
			double x = r * sy * cx;
			double y = r * sy * sx;
			double z = r * cy;
			double tx = (double)ix * dnx;
			glNormal3f(x, y, z);
			glTexCoord2f(tx, ty);
			glVertex3f(x, y, z);
			x = r * sy1 * cx;
			y = r * sy1 * sx;
			z = r * cy1;
			glNormal3f(x, y, z);
			glTexCoord2f(tx, ty1);
			glVertex3f(x, y, z);
			createCircleColor(ix, nx);
		}
	}
	glEnd();
}

void createCircleColor(int numberOfIterations, int iteration)
{
	int i = round(numberOfIterations * 100 / iteration);

	if (i <= 33)
	{
		glColor3f(1.0, 0.0, 0.0);
	}
	else if (i > 33 && i <= 66)
	{
		glColor3f(0.0, 1.0, 0.0);
	}
	else
	{
		glColor3f(0.0, 0.0, 1.0);
	}
}