# Transformacoes-Geometricas-Usando-OpenGL

Projeto de Computação Gráfica, no qual consiste em, usando as bibliotecas OpenGL, transladar e rotacionar um quadrado vermelho na tela.

Ao iniciar o programa, estara no modo de translação. Então usando as teclas direcionais do teclado é possível transladar o quadrado. Porém, ao clicar a tecla 'r', entrará no modo de rotação, onde usando as teclas direcionais para a esquerda e direita, é possível rotacionar o quadrado.

O tamanho do quadrado é indicado por uma variável inteira tamQuad.

 - Para compilar no Windows:
	gcc main.c -o main -lopengl32 -lglu32 -lfreeglut

 - Para compilar no Linux:
	 gcc main.c -o main -lGL -lglut -lGLU