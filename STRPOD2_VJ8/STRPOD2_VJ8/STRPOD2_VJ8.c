/*
Napisati program koji iz datoteke èita podatke o broju bodova koje je jedan student dobio na ispitu
(struct _student{char ime[128];char prezime[128];int broj_bodova; int relativni_broj_bodova;struct
_student *left; ;struct _student right;}) i sprema ih u binarno stablo pretraživanja. (Napomena : 0 <
broj_bodova <= 100). Ispisati binarno stablo na „inorder“ naèin.
U tako kreiranom binarnom stablu potrebno je za svakog od studenata izraèunati i relativan broj bodova
po formuli: relativan_broj_bodova=( broj_bodova / MAX(broj_bodova) ). Ispisati binarno stablo na
„preorder“ naèin.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

typedef struct student *node;
typedef struct student 
{
	char ime[128]; 
	char prezime[128]; 
	int broj_bodova; 
	float relativni_broj_bodova;
	int brojac;//ja sam ovo nadoda
	node left;
	node right;
}student;

node unosIzFilea(node);
node unosUStablo(node, node);
void printStabloInorder(node);
void printStabloPreorder(node);

int main()
{
	node stablo = NULL;
	stablo=unosIzFilea(stablo);
	printf("\nINORDER\n");
	printStabloInorder(stablo);
	printf("\nPREORDER\n");
	printStabloPreorder(stablo);
	return 0;
}

node unosIzFilea(node S)
{
	FILE *dat;
	dat = fopen("Bodovi.txt", "r");
	while (!feof(dat))
	{
		node temp = (node)malloc(sizeof(student));
		fscanf(dat, " %s %s %d", temp->ime, temp->prezime, &temp->broj_bodova);
		S = unosUStablo(temp, S);
	}
	fclose(dat);
	return S;
}

node unosUStablo(node temp, node S)//sansa da treba promjeni vece manje
{
	if (NULL == S)//standardno
	{
		S = (node)malloc(sizeof(student));
		S->left = NULL;
		S->right = NULL;
		strcpy(S->ime, temp->ime);
		strcpy(S->prezime, temp->prezime);
		S->broj_bodova = temp->broj_bodova;
		S->brojac = 1;
	}
	else if (strcmp(S->ime, temp->ime) == 0 && strcmp(S->prezime, temp->prezime) == 0)//isto ime i prezime, ista osoba
	{
		S->broj_bodova += temp->broj_bodova;
		S->brojac++;
	}
	else if (strcmp(S->prezime, temp->prezime) <= 0)//ode ce doc samo ako ima drukcije ime, a prezime moze bit isto ili posli po abecedi
	{
		S->right = unosUStablo(temp, S->right);
	}
	else if (strcmp(S->prezime, temp->prezime) > 0)
	{
		S->left = unosUStablo(temp, S->left);
	}
	return S;
}

void printStabloInorder(node S)
{
	if (NULL != S)
	{
		printStabloInorder(S->left);
		S->relativni_broj_bodova = (float)S->broj_bodova / ((float)S->brojac * 100);
		printf("\n\tIME: %s\n\tPREZIME: %s\n\tBROJ BODOVA: %d\n\tRELATIVNI BROJ BODOVA: %.2lf\n\n", S->ime, S->prezime, S->broj_bodova, S->relativni_broj_bodova);
		printStabloInorder(S->right);
	}
}

void printStabloPreorder(node S)
{
	if (NULL != S)
	{
		printStabloPreorder(S->left);
		S->relativni_broj_bodova = (float)S->broj_bodova / ((float)S->brojac * 100);
		printf("\n\tIME: %s\n\tPREZIME: %s\n\tBROJ BODOVA: %d\n\tRELATIVNI BROJ BODOVA: %.2lf\n\n", S->ime, S->prezime, S->broj_bodova, S->relativni_broj_bodova);
		printStabloPreorder(S->right);
	}
}