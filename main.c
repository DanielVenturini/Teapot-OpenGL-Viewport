#include <GL/glut.h>
#include <stdio.h>

/// argumentos para funcionar o OpenGL
/// -lopengl32 -glu32 -lfreeglut

int init(void){

    glClearColor(1.0, 1.0, 1.0, 0.0);   // define a cor de fundo
    glMatrixMode(GL_PROJECTION);        // carrega a matriz de projeção
    //gluOrtho2D(0.0,100.0,0.0,100.0);  // define projeção ortogonal 2D

    gluOrtho2D(-100, 100, -100, 100);   /// definindo a janela de recorte
}

void display(void){

    glClear(GL_COLOR_BUFFER_BIT);           // desenha o fundo (limpa a janela)

    glColor3f(0.0, 0.0, 0.0);               /// altera a cor do fundo para branco
    glMatrixMode(GL_MODELVIEW);             /// carrega a matriz de projecao
    glLoadIdentity();                       // carrega a matriz identidade

    glViewport(-3, 3, -3, 3);       /// view port superior esquerdo
    glClearColor3f(1.0, 0.0, 0.0);  // define a cor de fundo
    desenha_objeto();

    glViewport(-3, 3, -3, 3);       /// view port superior direito
    glClearColor3f(0.0, 1.0, 0.0);  // define a cor de fundo
    desenha_objeto();

    glViewport(-3, 3, -3, 3);       /// view port inferior esquerdo
    glClearColor3f(0.0, 0.0, 1.0);  // define a cor de fundo
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

