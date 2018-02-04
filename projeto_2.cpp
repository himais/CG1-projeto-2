/* Projeto 2 */ 
#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

GLfloat xf, yf, win;
GLint view_w, view_h;
float xx = 0, yy = 0;
float graus = 0;
float red = 0.0, green = 0.0, blue = 0.0;

typedef struct tNo{ 
	float x;
	float y; 
	struct tNo *prox;
} tNo;

tNo *LISTA = (tNo *) malloc(sizeof(tNo));

// Inicia lista
void inicia(tNo *LISTA){
	LISTA->prox = NULL;
}

//verifica lista vazia
int vazia(tNo *LISTA){
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}


//Inserir no fim
void insereFim(tNo *LISTA){     
	tNo *novo=(tNo *) malloc(sizeof(tNo));

	if(!novo){
		printf("N�o foi poss�vel alocar.\n");
		exit(1);
	}

	printf("Novo elemento x: "); 
	scanf("%f", &novo->x);
	printf("Novo elemento y: "); 
	scanf("%f", &novo->y);

	novo->prox = NULL;

	if(vazia(LISTA))
		LISTA->prox=novo;
	else{
		tNo *tmp = LISTA->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
}

//Desenha a fun��o da lista
void drawFigure(void){     
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//declara��o da lista
	tNo *aux;
	aux = LISTA->prox;


	glClear(GL_COLOR_BUFFER_BIT);

	//ponto central
	glPointSize(2.0);    
	glBegin(GL_POINTS);
	glVertex2f(0.0f, 0.0f);
	glEnd();

	//desenho com os pontos da lista
	glRotatef(graus, 0, 0, 1);
	glTranslatef(xx, yy, 0);
	glBegin(GL_LINE_LOOP);                           	

	while(aux != NULL){
		glVertex2f(aux->x, aux->y);
		aux = aux->prox;
	}

	glEnd();

	glFlush();        
}

/*
// Fun��o callback chamada para fazer o desenho
void Desenha(void){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glClear(GL_COLOR_BUFFER_BIT);
    // Desenha um ret�ngulo preenchido com a cor corrente
    
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glEnd();
    
    glRotatef(graus, 0, 0, 1);
    glTranslatef(xx, yy, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-25.0f, 0.0f);
    glVertex2f(25.0f, 0.0f);
    glVertex2f(0.0f, 50.0f);
    glEnd();
    
    glFlush();
}*/

// Inicializa par�metros de rendering
void Inicializa (void){   
	// Define a cor de fundo da janela de visualiza��o como preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	xf=50.0f;
	yf=50.0f;
	win=300.0f;

}

// Fun��o callback chamada quando o tamanho da janela � alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h){ 
	// Especifica as dimens�es da Viewport
	glViewport(0, 0, w, h);
	view_w = w;
	view_h = h;                   

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D (-150, 150, -150, 150);
}

// Fun��o callback chamada para gerenciar eventos de teclado
void GerenciaTeclado(unsigned char key, int x, int y){

	printf("%c - %i\n", key, key);
	switch (key) {
	case 'R': 
	case 'r':// muda a cor corrente para vermelho
		red += 0.1;
		glColor3f(red, 0.0f, 0.0f);
		break;
	case 'G':
	case 'g':// muda a cor corrente para verde
		green += 0.1;
		glColor3f(0.0f, green , 0.0f);
		break;
	case 'B':
	case 'b':// muda a cor corrente para azul
		blue += 0.1;
		glColor3f(0.0f, 0.0f, blue);
		break;
	case 'A':
	case 'a': //rota��o hor�rio
		graus -= 5;
		break;
	case 'l':
	case 'L': //rota��o anti-hor�rio
		graus += 5;
		break;
	case 'w':// muda a cor corrente para azul
		glColor3f(1.0f, 1.0f, 1.0f);
		red = 0.0;
		blue = 0.0;
		green = 0.0;
		break;
	case 27:
		exit(1);

	}
	glutPostRedisplay();
}

// Fun��o callback chamada para gerenciar eventos do mouse
/*
void GerenciaMouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON)
        if (state == GLUT_DOWN) {
        // Troca o tamanho do ret�ngulo, que vai do centro da 
        // janela at� a posi��o onde o usu�rio clicou com o mouse
        xf = ( (2 * win * x) / view_w) - win;
        yf = ( ( (2 * win) * (y-view_h) ) / -view_h) - win;
    }
    glutPostRedisplay();
}*/

// Fun��o callback chamada para gerenciar eventos do teclado   
// para teclas especiais, tais como F1, PgDn e Home

void TeclasEspeciais(int key, int x, int y){
	if(key == GLUT_KEY_UP)
		yy += 5;

	if(key == GLUT_KEY_DOWN) 
		yy -= 5;

	if(key == GLUT_KEY_RIGHT)
		xx += 5;

	if(key == GLUT_KEY_LEFT) 
		xx -= 5;

	glutPostRedisplay();
}

// Programa Principal 
int main(void){

	//chamada de fun��es para lista
	inicia(LISTA);
	insereFim(LISTA);
	insereFim(LISTA);
	insereFim(LISTA);
	insereFim(LISTA);        

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(10,10);
	glutCreateWindow("Projeto 2 - Lista e Rota��o");
	glutReshapeFunc(AlteraTamanhoJanela);

	//desenhar figura com os valores da lista
	glutDisplayFunc(drawFigure);     

	glutKeyboardFunc(GerenciaTeclado);
	glutSpecialFunc(TeclasEspeciais);      
	//glutMouseFunc(GerenciaMouse);
	//glutDisplayFunc(Desenha);
	Inicializa();
	glutMainLoop();

	return 0; 
}
