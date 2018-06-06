#include <GL/glut.h>
#include <stdio.h>

/// argumentos para funcionar o OpenGL
/// -lopengl32 -glu32 -lfreeglut
/// -lGL -lglut -lGLU   -> gcc main.c -o main.exe -lGL -lglut -lGLU

int init(void){

    glClearColor(1.0, 1.0, 1.0, 0.0);   // define a cor de fundo
    glEnable(GL_DEPTH_TEST);            /// habilitao teste de profundidade

    glMatrixMode(GL_MODELVIEW);         // carrega a matriz de projeção
    glLoadIdentity();                   /// carrega a matrix de identidade
    //gluOrtho2D(0.0,100.0,0.0,100.0);  // define projeção ortogonal 2D

    gluLookAt(4.0, 2.0, 2.0,    //posição da câmera
              0.0, 0.0, 0.0,    //para onde a câmera aponta
              0.0, 1.0, 0.0);   //vetor view

    glMatrixMode(GL_PROJECTION);         // carrega a matriz de projeção
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 10.0);
    //glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);   /// definindo a janela de recorte
}

void desenha_objeto() {
    glBegin(GL_TRIANGLES);      // desenha um t r i a n g u l o
        glVertex2i(50, -50);
        glVertex2i(0, 50);
        glVertex2i(-50, -50);
    glEnd();

    glBegin(GL_LINE_LOOP);      // desenha um quadrado
        glVertex2i(-99, -99);
        glVertex2i(99, -99);
        glVertex2i(99, 99);
        glVertex2i(-99, 99);
    glEnd();
}

void criaProjecoesOrtogonais(){
    glOrtho(-3, 3, -3, 3, 1, 50);   /// superior esquerdo
    glOrtho(-3, 3, -3, 3, 1, 50);   /// superior direito
    glOrtho(-3, 3, -3, 3, 1, 50);   /// inferior esquerdo
    ///glOrtho(-3, 3, -3, 3, 1, 50);   /// inferior direito
}

void display(void){

    glClear(GL_COLOR_BUFFER_BIT |  GL_DEPTH_BUFFER_BIT);    // desenha o fundo (limpa a janela)
    glMatrixMode(GL_MODELVIEW);     /// carrega a matriz modelo

     // desenha  um  cubo
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTeapot(1.0f);

    /*
    glColor3f(0.0, 0.0, 0.0);       /// altera a cor do fundo para branco
    glLoadIdentity();               // carrega a matriz identidade

    glViewport(-3, 3, -3, 3);       /// view port superior esquerdo
    glColor3f(1.0, 0.0, 0.0);       // define a cor de fundo
    desenha_objeto();

    glViewport(-3, 3, -3, 3);       /// view port superior direito
    glColor3f(0.0, 1.0, 0.0);       // define a cor de fundo
    desenha_objeto();

    glViewport(-3, 3, -3, 3);       /// view port inferior esquerdo
    glColor3f(0.0, 0.0, 1.0);       // define a cor de fundo
    desenha_objeto();

    /*
    glTranslatef(tx+(tamQuad/2), ty+(tamQuad/2), 0);
    glRotatef(theta, 0, 0, 1);
    glTranslatef(-tx-(tamQuad/2), -ty-(tamQuad/2), 0);

    glBegin(GL_POLYGON);                    // desenha uma linha
        glVertex2i(tx, ty);
        glVertex2i(tx, ty + tamQuad);
        glVertex2i(tx + tamQuad, ty + tamQuad);
        glVertex2i(tx + tamQuad, ty);
    glEnd();
    */

    glFlush();                            // desenha os comandos não executados
}

int main(int argc, char** argv) {

    glutInit(&argc,argv);                               //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);         //configura o modo de display
    glutInitWindowSize(800, 800);                       ///configura a largura e altura da janela de exibição
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Teapot In OpenGL by Venturini");  ///cria a janela de exibição

    init();                                             // executa função de inicialização

    glutDisplayFunc(display);           // estabelece a função "display" como a função callback de exibição.
    glutMainLoop();                     // mostre tudo e espere
    return 0;
}

