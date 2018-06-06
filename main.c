#include <GL/glut.h>
#include <stdio.h>

/// argumentos para funcionar o OpenGL
/// -lopengl32 -glu32 -lfreeglut
/// -lGL -lglut -lGLU   -> gcc main.c -o main.exe -lGL -lglut -lGLU

int init(void){

    glClearColor(1.0, 1.0, 1.0, 0.0);   // define a cor de fundo
    glEnable(GL_DEPTH_TEST);            /// habilitao teste de profundidade

    //glMatrixMode(GL_MODELVIEW);         // carrega a matriz de projeção
    glMatrixMode(GL_PROJECTION);            // carrega a matriz de projeção
    glLoadIdentity();                   /// carrega a matrix de identidade
    //gluOrtho2D(0.0,100.0,0.0,100.0);  // define projeção ortogonal 2D

    /*gluLookAt(4.0, 2.0, 2.0,    //posição da câmera
              0.0, 0.0, 0.0,    //para onde a câmera aponta
              0.0, 1.0, 0.0);   //vetor view*/

    //glMatrixMode(GL_PROJECTION);         // carrega a matriz de projeção
    //glLoadIdentity();
    //gluPerspective(45.0, 1.0, 0.1, 10.0);
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);   /// definindo a janela de recorte
    glMatrixMode(GL_MODELVIEW);         // carrega a matriz de projeção
    glLoadIdentity();

    glColor3f(1.0f, 0.0f, 0.0f);            //alterao atributo de cor

    /*criaViewPortProjecao(0, 800, 400, 400);
    criaViewPortProjecao(0, 400, 400, 0);
    criaViewPortProjecao(400, 400, 800, 800);
    criaViewPortProjecao(400, 400, 800, 0);*/

}

void criaViewPortProjecao(int p1, int p2, int p3, int p4){
    glViewport(p1, p2, p3, p4);     /// define a primeira viewport
    glOrtho(-3, 3, -3, 3, 1, 50);   /// projecao ortogonal
}

void posicaoCamera(){

    gluLookAt(4.0, 2.0, 2.0,    //posição da câmera
              0.0, 0.0, 0.0,    //para onde a câmera aponta
              0.0, 1.0, 0.0);   //vetor view

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

     // desenha  um  TeaPot
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTeapot(1.0f);

    glFlush();      // desenha os comandos não executados
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

