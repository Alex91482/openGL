﻿
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <cmath>


void CreateTriangle();
void CreateCircle();
void CreateSquare();
void createCircleColor(int numberOfIterations, int iteration);

GLfloat rotate_z = 0;

int main(int argc, char* argv[])
{
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

		rotate_z += 0.5;

		glLoadIdentity();
		glRotatef(rotate_z, 0.0, 0.0, 1.0);

		//CreateSquare();
		//CreateCircle();
		CreateTriangle();

		glFlush();

		window.display();
	}

	return 0;
}


void CreateSquare()
{
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0); glVertex2f(-0.5f, -0.5f);
	glColor3f(0.0, 1.0, 0.0); glVertex2f(-0.5f, 0.5f);
	glColor3f(0.0, 0.0, 1.0); glVertex2f(0.5f, 0.5f);
	glColor3f(1.0, 1.0, 1.0); glVertex2f(0.5f, -0.5f);
	glEnd();
}

void CreateCircle()
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.0f, 0.0f);
	int iteration = 30;
	for (int i = 0; i <= iteration; i++) {
		float a = (float)i / 30.0f * 3.1415f * 2.0f;
		createCircleColor(i, iteration);
		glVertex2f(cos(a) * 0.5f, sin(a) * 0.5f);
	}
	glEnd();
}

void CreateTriangle()
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0); glVertex2f(-0.5f, -0.5f);
	glColor3f(0.0, 1.0, 0.0); glVertex2f(-0.5f, 0.5f);
	glColor3f(0.0, 0.0, 1.0); glVertex2f(0.5f, 0.0f);
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