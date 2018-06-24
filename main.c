#include <GL/glut.h>
#include <stdio.h>

/// argumentos para funcionar o OpenGL
/// -lopengl32 -glu32 -lfreeglut    <- windowns
/// -lGL -lglut -lGLU   -> gcc main.c -o main.exe -lGL -lglut -lGLU     <- linux

static GLfloat spin = 0.0;

int init(void){

    glClearColor(1.0, 1.0, 1.0, 0.0);   // define a cor de fundo
    glEnable(GL_DEPTH_TEST);            /// habilitao teste de profundidade

    glMatrixMode(GL_PROJECTION);        /// carrega a matriz de projeção para criar a janela de recorte e a view port
    glLoadIdentity();                   /// carrega a matrix de identidade
    gluOrtho2D(-1.5, 1.72, -1.5, 1.5);  /// define a janela de recorte
}

void criaViewPortProjecao(int xvmin, int yvmin, int vnumber){
    glViewport(xvmin, yvmin, 400, 400); /// define a viewport

    glMatrixMode(GL_PROJECTION);        /// para criar projecoes ortogonal
    glLoadIdentity();                   /// carregando a matriz identidade para a nova operacao

    if(vnumber == 4){                       /// se for a quarta viewport
        gluPerspective(70, 1.0, 1.0, 50);   /// criando a projecao perspectiva
    } else {
        glOrtho(-3, 3, -3, 3, 1, 50);       /// cria projecao ortogonal
    }
}

void posicaoCamera(float x0, float y0, float z0, float vx, float vy, float vz, int vnumber){

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();           /// carregando a matriz identidade para a nova operacao
    gluLookAt( x0,  y0,  z0,    /// posição da câmera
              0.0, 0.0, 0.0,    /// camera apontando para a origem
               vx,  vy,  vz);   /// eixo - x, y, z - de visao da camera

    float sizeTeaPoat = 2.0;

    if(vnumber == 4){
        glLoadIdentity();
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        float valorF = spin;
        int valorI = valorF;
        int graus = valorI % 365;

        glRotatef(spin, 0.0, 0.0, 1.0);         /// rotacionando em <spin> graus no eixo z
        glRotatef(graus, 1.0, 0.0, 0.0);        /// rotacionando em 45 graus no eixo x
        //glRotatef(45, 1.0, 0.0, 0.0);         /// rotacionando em 45 graus no eixo x

        sizeTeaPoat = 0.6;
    }

    glutWireTeapot(sizeTeaPoat);               /// desenha o bule
}

void spinDisplay(void){
   spin = spin + 0.4;
   if (spin > 360.0)
      spin = 0;

   glutPostRedisplay();
}

void criaViewPort(){
    criaViewPortProjecao(000, 400, 1);     /// superior esquerdo
    posicaoCamera(0.0, 1.0, 0.0, 0.0, 0.0, -1.0, 1);    /// ultimo parametro eh o numero da viewport

    criaViewPortProjecao(400, 400, 2);     /// superior direito
    posicaoCamera(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 2);

    criaViewPortProjecao(000, 000, 3);     /// inferior esquerdo
    posicaoCamera(0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 3);

    criaViewPortProjecao(400, 000, 4);     /// inferior direito
    posicaoCamera(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 4);
}

void display(void){

    glClear(GL_COLOR_BUFFER_BIT |  GL_DEPTH_BUFFER_BIT);    // desenha o fundo (limpa a janela)
    glMatrixMode(GL_MODELVIEW);     /// carrega a matriz modelo
    glLoadIdentity();

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

    glutIdleFunc(spinDisplay);
    glutDisplayFunc(display);           // estabelece a função "display" como a função callback de exibição.

    init();                                             // executa função de inicialização
    glutMainLoop();                     // mostre tudo e espere
    return 0;
}
