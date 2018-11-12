//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"
#if (_MSC_VER > 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif


GLfloat blanco[] = { 1.0, 1.0, 1.0 };
GLfloat azul[] = { 0.0, 0.0, 1.0 };
GLfloat rojo[] = { 1.0, 0.0, 0.0 };
GLfloat verde[] = { 0.0, 1.0, 0.0 };
GLfloat amarillo[] = { 1.0, 1.0, 0.0 };
GLfloat negro[] = { 0.0, 0.0, 0.0 };

GLfloat posicion[] = { -30.0, 20.0, 0.0, 1.0 };

CFiguras figura;

//Variables para animaciones
bool animCajon, animBocinas, animBalon, animPerro = false;
bool bocinaE1 = true, bocinaE2 = false;
bool perro1 = true, perro2, perro3, perro4 = false;
float rotCajonY = 0, cajonZ = -1.85;
float bocinaX = 0;
float balonY= 27.5, balonZ= -5, t=0;
float perroX = 70, perroZ = 18, rotPerroY=-90;
 


CTexture ParedRoja;
CTexture Pared2;
CTexture Puerta;
CTexture Puerta2;
CTexture Piso;
CTexture Piso1;
CTexture Tela;
CTexture Madera;
CTexture Madera2;
CTexture Metal;
CTexture bocinatex;
CTexture malla;
CTexture control;
CTexture pantallabocina;
CTexture pantallatv;
CTexture balon;

//Modelos
CModel balto;

int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;


CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha

CTexture tree;

CFiguras sky;

void arbol()
{
	glPushMatrix();
					glDisable(GL_LIGHTING);
					glEnable( GL_ALPHA_TEST );
					//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
					glAlphaFunc( GL_GREATER, 0.1 );
					//glEnable(GL_BLEND);     // Turn Blending On
					//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
					glBindTexture(GL_TEXTURE_2D, tree.GLindex);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(-45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
					glDisable( GL_ALPHA_TEST );
					//glDisable(GL_BLEND);        // Turn Blending Off
					//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
					glEnable(GL_LIGHTING);
				
			glPopMatrix();
}

			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glDisable(GL_LIGHT0);

	glLightfv(GL_LIGHT1, GL_AMBIENT, negro);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, blanco);
	glLightfv(GL_LIGHT1, GL_SPECULAR, blanco);
	glLightfv(GL_LIGHT1, GL_POSITION, posicion);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
    
	
	
	ParedRoja.LoadTGA("ParedRoja.tga");
	ParedRoja.BuildGLTexture();
	ParedRoja.ReleaseImage();

	bocinatex.LoadTGA("Bocina.tga");
	bocinatex.BuildGLTexture();
	bocinatex.ReleaseImage();

	Pared2.LoadTGA("Pared2.tga");
	Pared2.BuildGLTexture();
	Pared2.ReleaseImage();

	Puerta.LoadTGA("Puerta.tga");
	Puerta.BuildGLTexture();
	Puerta.ReleaseImage();

	Puerta2.LoadTGA("Puerta1.tga");
	Puerta2.BuildGLTexture();
	Puerta2.ReleaseImage();

	Piso.LoadTGA("Piso.tga");
	Piso.BuildGLTexture();
	Piso.ReleaseImage();

	Piso1.LoadTGA("Madera.tga");
	Piso1.BuildGLTexture();
	Piso1.ReleaseImage();

    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadBMP("logopumas.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	tree.LoadTGA("tree01.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	Tela.LoadTGA("Tela.tga");
	Tela.BuildGLTexture();
	Tela.ReleaseImage();

	Madera.LoadTGA("Madera1.tga");
	Madera.BuildGLTexture();
	Madera.ReleaseImage();

	Madera2.LoadTGA("Madera2.tga");
	Madera2.BuildGLTexture();
	Madera2.ReleaseImage();

	Metal.LoadTGA("Metal.tga");
	Metal.BuildGLTexture();
	Metal.ReleaseImage();

	malla.LoadTGA("Malla.tga");
	malla.BuildGLTexture();
	malla.ReleaseImage();

	balon.LoadTGA("Balon.tga");
	balon.BuildGLTexture();
	balon.ReleaseImage();

	control.LoadTGA("Controles.tga");
	control.BuildGLTexture();
	control.ReleaseImage();

	pantallabocina.LoadTGA("Pantalla.tga");
	pantallabocina.BuildGLTexture();
	pantallabocina.ReleaseImage();

	pantallatv.LoadTGA("Pantalla1.tga");
	pantallatv.BuildGLTexture();
	pantallatv.ReleaseImage();

	balto._3dsLoad("modelos/balto.3ds");
	/*balto.LoadTextureImages();
	balto.GLIniTextures();
	balto.ReleaseTextureImages();*/

	
	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

}
void sillon1()
{
	glPushMatrix();
		glPushMatrix();//respaldo
			glScalef(10.0, 7.0, 1.0);
			figura.prisma(1.0, 1.0, 1.0, Tela.GLindex);
		glPopMatrix();
		glPushMatrix();//codera derecha
			glTranslatef(4.5, -1.0, 2.0);
			glPushMatrix();
				glScalef(1.0, 5.0, 3.0);
				figura.prisma(1.0, 1.0, 1.0, Madera.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//codera Izquierda
			glTranslatef(-4.5, -1.0, 2.0);
			glPushMatrix();
				glScalef(1.0, 5.0, 3.0);
				figura.prisma(1.0, 1.0, 1.0, Madera.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//aciento
			glTranslatef(0.0, -2.0,2.0);
			glPushMatrix();
				glScalef(8.0, 3.0, 3.0);
				figura.prisma(1.0, 1.0, 1.0, Tela.GLindex);
			glPopMatrix();
		glPopMatrix();
		//Patas
		glPushMatrix();
			glTranslatef(4.5, -3.75, 3.0);
			glPushMatrix();
				figura.cilindro(0.5, 0.5, 10, Madera.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(4.5, -3.75, 0.0);
				glPushMatrix();
				figura.cilindro(0.5, 0.5, 10, Madera.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-4.5, -3.75, 0.0);
				glPushMatrix();
				figura.cilindro(0.5, 0.5, 10, Madera.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-4.5, -3.75, 3.0);
				glPushMatrix();
				figura.cilindro(0.5, 0.5, 10, Madera.GLindex);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}


void sillon()
{
	glPushMatrix();
		glPushMatrix();//respaldo
			glScalef(10.0, 7.0, 1.0);
			figura.prisma(1.0, 1.0, 1.0, Tela.GLindex);
		glPopMatrix();
		glPushMatrix();//codera derecha
			glTranslatef(4.5, -1.0, 2.0);
			glPushMatrix();
				glScalef(1.0, 5.0, 3.0);
				figura.prisma(1.0, 1.0, 1.0, Tela.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//codera Izquierda
			glTranslatef(-4.5, -1.0, 2.0);
			glPushMatrix();
				glScalef(1.0, 5.0, 3.0);
				figura.prisma(1.0, 1.0, 1.0, Tela.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//aciento
			glTranslatef(0.0, -2.0,2.0);
			glPushMatrix();
				glScalef(8.0, 3.0, 3.0);
				figura.prisma(1.0, 1.0, 1.0, Tela.GLindex);
			glPopMatrix();
		glPopMatrix();
		//Patas
		glPushMatrix();
			glTranslatef(4.5, -3.75, 3.0);
			glPushMatrix();
				figura.cilindro(0.5, 0.5, 10, Madera.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(4.5, -3.75, 0.0);
				glPushMatrix();
				figura.cilindro(0.5, 0.5, 10, Madera.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-4.5, -3.75, 0.0);
				glPushMatrix();
				figura.cilindro(0.5, 0.5, 10, Madera.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-4.5, -3.75, 3.0);
				glPushMatrix();
				figura.cilindro(0.5, 0.5, 10, Madera.GLindex);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

void bar()
{
	glPushMatrix();
		glPushMatrix();//Superficie frontal
			glScalef(6.0, 0.2, 2.0);

			figura.prisma(1.0, 1.0, 1.0, Madera2.GLindex);
		glPopMatrix();
		glPushMatrix();//superficie derecha
			glTranslatef(2.0,0.0, -2.0);
			glPushMatrix();
				glScalef(2.0, 0.2, 2.0);
				figura.prisma(1.0, 1.0, 1.0, Madera2.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Tapa frontal
			glTranslatef(0.0, -4.0, 0.8);
			glPushMatrix();
				glScalef(5.8,7.8, 0.2);
				figura.prisma(1.0, 1.0, 1.0, Madera.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Tapa trasera
			glTranslatef(2.0, -4.0, -2.8);
			glPushMatrix();
				glScalef(1.8, 7.8, 0.2);
				figura.prisma(1.0, 1.0, 1.0, Madera.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Tapa Derecha
			glTranslatef(2.8, -4.0, -1.0);
			glPushMatrix();
				glScalef(0.2, 7.8, 3.8);
				figura.prisma(1.0, 1.0, 1.0, Madera.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Tapa izquierda
			glTranslatef(-2.8, -4.0, 0.0);
			glPushMatrix();
				glScalef(0.2, 7.8, 1.8);
				figura.prisma(1.0, 1.0, 1.0, Madera.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Repisa
			glTranslatef(0.0, -3.0, 0.0);
			glPushMatrix();
				glScalef(5.4, 0.2, 1.7);
				figura.prisma(1.0, 1.0, 1.0, Madera.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Repisa derecha
			glTranslatef(2.0, -3.0, -1.8);
			glPushMatrix();
				glScalef(1.7, 0.2, 1.9);
				figura.prisma(1.0, 1.0, 1.0, Madera.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Division
			glTranslatef(2.0, -1.5, -0.9);
			glPushMatrix();
				glScalef(1.7, 2.8, 0.2);
				figura.prisma(1.0, 1.0, 1.0, Madera.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Puerta
			glTranslatef(1.25, -1.5, cajonZ);
			glRotatef(rotCajonY, 0, 1, 0);
			glPushMatrix();
				glScalef(0.2, 2.8, 1.7);
				figura.prisma(1.0, 1.0, 1.0, Puerta2.GLindex);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

void pantalla()
{
	glPushMatrix();
		glPushMatrix();//pantalla
			glScalef(5.0, 4.0, 0.4);
			figura.prisma(1.0, 1.0, 1.0, bocinatex.GLindex);
		glPopMatrix();
		//patas
		glPushMatrix();//Tronco
			glTranslatef(0.0, -2.0, -0.25);
			glPushMatrix();
				glScalef(2.0, 1.0, 0.1);
				figura.prisma(1.0, 1.0, 1.0, bocinatex.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Base
			glTranslatef(0.0, -2.6, -0.25);
			glPushMatrix();
				figura.cilindro(1.3, 0.1, 15, bocinatex.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Pantalla
			glTranslatef(0.0, 0.0, 0.205);
			glPushMatrix();
				glScalef(4.8, 3.5, 0.01);
				figura.prisma(1.0, 1.0, 1.0, pantallatv.GLindex);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

void mesa()
{
	glPushMatrix();
		glPushMatrix();//Superficie
			glScalef(3.0, 0.2, 2.0);
			figura.prisma(1.0, 1.0, 1.0, Madera2.GLindex);
		glPopMatrix();
		//patas
		glPushMatrix();//derecha frontal
			glTranslatef(1.2, -4.9, 0.7);
			glPushMatrix();
				figura.cilindro(0.1, 4.8, 15, Metal.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Izquierda frontal
			glTranslatef(-1.2, -4.9, 0.7);
			glPushMatrix();
				figura.cilindro(0.1, 4.8, 15, Metal.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Izquierda Trasera
			glTranslatef(-1.2, -4.9, -0.7);
			glPushMatrix();
				figura.cilindro(0.1, 4.8, 15, Metal.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Derecha Trasera
			glTranslatef(1.2, -4.9, -0.7);
			glPushMatrix();
				figura.cilindro(0.1, 4.8, 15, Metal.GLindex);
			glPopMatrix();
		glPopMatrix();
		//Transversales
		glPushMatrix();//Frontal 
			glTranslatef(1.1, -0.2, 0.7);
			glRotatef(90, 0.0, 0.0, 1.0);
			glPushMatrix();
				figura.cilindro(0.07, 2.2, 15, Metal.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Frontal 
			glTranslatef(1.1, -0.2, -0.7);
			glRotatef(90, 0.0, 0.0, 1.0);
			glPushMatrix();
				figura.cilindro(0.07, 2.2, 15, Metal.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Pantalla 
			glRotated(180, 0.0, 1.0, 0.0);
			glTranslatef(0.0, 2.7, 0.1);
			glPushMatrix();
				//glScalef(0.5,0.5,0.5);
				pantalla();
		glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

void bocina()
{
	glPushMatrix();//Estructura 
		glPushMatrix();
			glScalef(3.0, 5.0, 2.0);
			glTranslatef(bocinaX, 0, 0);
			figura.prisma(1.0, 1.0, 1.0, bocinatex.GLindex);
		glPopMatrix();
		glPushMatrix();//Bocina grande
			glTranslatef(0.0, -1.5, 1.0);
			glRotated(90, 1.0, 0.0, 0.0);
			glPushMatrix();
				figura.cilindro(0.8, 0.1, 20, malla.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Bocina chica derecha
			glTranslatef(0.5, -0.5, 1.0);
			glRotated(90, 1.0, 0.0, 0.0);
			glPushMatrix();
				glColor3f(0.0, 0.0, 0.0);
				figura.cilindro(0.2, 0.1, 20, malla.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Bocina chica izquierda
			glTranslatef(-0.5, -0.5, 1.0);
			glRotated(90, 1.0, 0.0, 0.0);
			glPushMatrix();
				glColor3f(0.0,0.0,0.0);
				figura.cilindro(0.2, 0.1, 20, malla.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Entrada cd
			glTranslatef(0.0, 0.9, 1.05);
			glPushMatrix();
				glScalef(1.5, 0.1, 0.1);
				figura.prisma(1.0, 1.0, 1.0, 0);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Control de efectos
			glTranslatef(0.0, 2.55, -0.3);
			glPushMatrix();
				glScalef(0.4, 0.1, 1.0);
				figura.prisma(1.0, 1.0, 1.0, control.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Control de volumen
			glTranslatef(0.9, 2.5, 0.0);
			glPushMatrix();
				figura.cilindro(0.3, 0.1, 20, control.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Control de canciones
			glTranslatef(-0.9, 2.5, 0.0);
			glPushMatrix();
				figura.cilindro(0.3, 0.1, 20, control.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Pantalla
			glTranslatef(0.0, 2.55, 0.5);
			glPushMatrix();
				glScalef(1.0, 0.1, 0.4);
				figura.prisma(1.0, 1.0, 1.0, pantallabocina.GLindex);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				sky.skybox(300.0, 300.0, 300.0,text1.GLindex);
				glEnable(GL_LIGHTING);
				glColor3f(1.0,1.0,1.0);
			glPopMatrix();
			///*
			//Casa
			glPushMatrix();//lado izquierdo
				glTranslatef(15.0, 35.0, 1.0);
				glPushMatrix();
					glScalef(30.0,70.0,2.0);
					figura.prisma(1.0, 1.0, 1.0, ParedRoja.GLindex);
				glPopMatrix();
				glPushMatrix();//puerta
					glTranslatef(40.0,-10.0,0.0);
					glPushMatrix();
						glScalef(50.0,50.0,2.0);
						figura.prisma(1.0, 1.0, 1.0, Puerta.GLindex);
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//Lado derecho
					glTranslatef(80.0, -5.0, 0.0);
					glPushMatrix();
						glScalef(30.0, 60.0, 2.0);
						figura.prisma(1.0, 1.0, 1.0, Pared2.GLindex);
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//tejado puerta
					glTranslatef(40.0, 20.0, -19.0);
					glPushMatrix();
						glScalef(50.0, 10.0, 60.0);
						figura.prisma(1.0, 1.0, 1.0, ParedRoja.GLindex);
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//tejado derecho
					glTranslatef(80.0, 24.0, -24.0);
					glPushMatrix();
						glScalef(30.0, 2.0, 50.0);
						figura.prisma(1.0, 1.0, 1.0, ParedRoja.GLindex);
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//tejado izquierdo
					glTranslatef(0.0, 34.0, -24.0);
					glPushMatrix();
						glScalef(30.0, 2.0, 50.0);
						figura.prisma(1.0, 1.0, 1.0, ParedRoja.GLindex);
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//pared lateral izquierda 
					glTranslatef(-14.0, 0.0, -24.0);
					glPushMatrix();
						glScalef(2.0, 70.0, 46.0);
						figura.prisma(1.0, 1.0, 1.0, ParedRoja.GLindex);
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//pared lateral derecha 
					glTranslatef(94.0, -5.0, -24.0);
					glPushMatrix();
						glScalef(2.0, 60.0, 46.0);
						figura.prisma(1.0, 1.0, 1.0, Pared2.GLindex);
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//pared trasera izquierda 
					glTranslatef(0.0, 0.0, -48.0);
					glPushMatrix();
						glScalef(30.0, 70.0, 2.0);
						figura.prisma(1.0, 1.0, 1.0, ParedRoja.GLindex);
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//pared trasera derecha
					glTranslatef(80.0, -5.0, -48.0);
					glPushMatrix();
						glScalef(30.0, 60.0, 2.0);
						figura.prisma(1.0, 1.0, 1.0, ParedRoja.GLindex);
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//pared trasera medio
					glTranslatef(40.0, -10.0, -48.0);
					glPushMatrix();
						glScalef(50.0, 50.0, 2.0);
						figura.prisma(1.0, 1.0, 1.0, ParedRoja.GLindex);
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//hueco izquierdo
				glTranslatef(14.0, 30.0, -24.0);
					glPushMatrix();
						glScalef(2.0, 10.0, 46.0);
						figura.prisma(1.0, 1.0, 1.0, ParedRoja.GLindex);
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//Pasto
					glTranslatef(45.0, -36.0, -24.0);
					glPushMatrix();
						glScalef(300.0, 2.0, 300.0);
						figura.prisma(1.0, 1.0, 1.0, Piso.GLindex);
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//Piso
					glTranslatef(40.0, -34.8, -25.0);
					glPushMatrix();
						glScalef(110.0, 0.2, 48.0);
						figura.prisma(1.0, 1.0, 1.0, Piso1.GLindex);
					glPopMatrix();
				glPopMatrix();
				//muebles
				glPushMatrix();//sillon
					glTranslatef(65.0,-27.3,-34.0);
					glPushMatrix();
						glScalef(2.0,2.0,2.0);
						sillon();												
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//sillon2
					glTranslatef(65.0, -27.3, -5.0);
					glRotated(180,0.0,1.0,0.0);
					glPushMatrix();
						glScalef(2.0, 2.0, 2.0);
						sillon1();
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//sillon3
					glTranslatef(45.0, -27.3, -18.0);
					glRotated(90, 0.0, 1.0, 0.0);
						glPushMatrix();
						glScalef(2.0, 2.0, 2.0);
					sillon();
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//bar
					glTranslatef(50.0, -11.0, -38.0);
					glPushMatrix();
						glScalef(3.0, 3.0, 3.0);
						bar();
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//Mesa con pantalla
					glTranslatef(80.0, -25.0, -20.0);
					glRotated(90,0.0,1.0,0.0);
					glPushMatrix();
						glScalef(2.0, 2.0, 2.0);
						mesa();
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//Bocina
					glTranslatef(80, -30.0, -30.0);
					glRotated(-90,0.0,1.0,0.0);
					glPushMatrix();
						glScalef(2.0,2.0,2.0);
						bocina();
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//perrito
					glTranslated(perroX,-34.7,perroZ);
					glRotatef(rotPerroY, 0, 1, 0);
					glPushMatrix();
						glDisable(GL_LIGHTING);
						balto.GLrender(NULL, _SHADED, 1);

						glEnable(GL_LIGHTING);
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();//balon
					glTranslated(40, balonY, balonZ);
					figura.esfera(2.5, 15, 15, balon.GLindex);
				glPopMatrix();
				glColor3f(1.0, 1.0, 1.0);
			glPopMatrix();
			//*/
		//bocina();
		glPopMatrix();
		
		glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();

	glutSwapBuffers ( );

}


void animacion()
{
	if (animCajon) {
		rotCajonY = 90;
		cajonZ = -2.5;
	}
	if (animBocinas) {
		if (bocinaE1) {
			bocinaX = bocinaX - 0.1;
			if (bocinaX < -0.3) {
				bocinaE1 = false;
				bocinaE2 = true;
			}
		}
		if (bocinaE2) {
			rotPerroY = 0;
			bocinaX = bocinaX + 0.1;
			if (bocinaX > 0.3) {
				bocinaE1 = true;
				bocinaE2 = false;
			}
		}
	}
	if (animBalon) {
		t += 0.5;
		balonZ = 15 * cos(45)*t;
		balonY = 15 * sin(45)*t - 9.81 / 2 * t*t;//a ver que sale ggg
	}
	if (animPerro) {
		if (perro1) {
			rotPerroY = -90;
			perroX = perroX - 0.5;
			if (perroX < 20) {
				perro1 = false;
				perro2 = true;
			}
		}
		if (perro2) {
			rotPerroY = 0;
			perroZ = perroZ + 0.5;
			if (perroZ > 58) {
				perro2 = false;
				perro3 = true;
			}
		}
		if (perro3) {
			rotPerroY = 90;
			perroX = perroX + 0.5;
			if (perroX > 70) {
				perro3 = false;
				perro4 = true;
			}
		}
		if (perro4) {
			rotPerroY = 180;
			perroZ = perroZ - 0.5;
			if (perroZ < 10) {
				perro4 = false;
				perro1 = true;
			}
		}
	}

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 300.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;
		case 'p':
			animCajon = true;
			break;
		case 'P':
			animCajon = false;
			rotCajonY = 0;
			cajonZ = -1.85;
			break;
		case 'b':
			animBocinas = true;
			break;
		case 'B':
			animBocinas = false;
			break;
		case 'l':
			animBalon = true;
			break;
		case 'k':
			animPerro = true;
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (2000, 2000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto Laboratorio"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );


  glutMainLoop        ( );          // 

  return 0;
}
