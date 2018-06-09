#include <GL/glut.h>
#include <stdio.h>

/// argumentos para funcionar o OpenGL
/// -lopengl32 -glu32 -lfreeglut    <- windowns
/// -lGL -lglut -lGLU   -> gcc main.c -o main.exe -lGL -lglut -lGLU     <- linux

int init(void){

    glClearColor(1.0, 1.0, 1.0, 0.0);   // define a cor de fundo
    glEnable(GL_DEPTH_TEST);            /// habilitao teste de profundidade

    glMatrixMode(GL_PROJECTION);        /// carrega a matriz de projeção para criar a janela de recorte e a view port
    glLoadIdentity();                   /// carrega a matrix de identidade
    gluOrtho2D(-1.5, 1.72, -1.5, 1.5);  /// define a janela de recorte
}

void criaViewPortProjecao(int xvmin, int yvmin){
    glLoadIdentity();                   /// carregando a matriz identidade para a nova operacao
    glViewport(xvmin, yvmin, 400, 400); /// define a viewport

    glMatrixMode(GL_PROJECTION);        /// para criar projecoes ortogonal
    glOrtho(-3, 3, -3, 3, 1, 50);       /// cria projecao ortogonal

    posicaoCamera();
    glutWireTeapot(0.6f);               /// desenha o bule
}

void posicaoCamera(){
    glLoadIdentity();                   /// carregando a matriz identidade para a nova operacao

    glMatrixMode(GL_MODELVIEW); /// modelo de visao
    gluLookAt(0.0, 0.0, 1.0,    ///posição da câmera
              0.0, 0.0, 0.0,    /// camera apontando para a origem
              0.0, 1.0, 0.0);   /// eixo - x, y, z - de visao da camera

}

void criaViewPort(){
    criaViewPortProjecao(000, 400);     /// superior esquerdo
    criaViewPortProjecao(400, 400);     /// superior direito
    criaViewPortProjecao(000, 000);     /// inferior esquerdo
    criaViewPortProjecao(400, 000);     /// inferior direito
}

void display(void){

    glClear(GL_COLOR_BUFFER_BIT |  GL_DEPTH_BUFFER_BIT);    // desenha o fundo (limpa a janela)
    glMatrixMode(GL_MODELVIEW);     /// carrega a matriz modelo

    glColor3f(1.0f, 0.8f, 0.0f);    /// altera a cor para dourado
    criaViewPort();                 /// cria as viewport

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

