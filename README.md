# VJ8-Strukture-podataka
Vjezba 8

Napisati program koji iz datoteke čita podatke o broju bodova koje je jedan student dobio na ispitu
(struct _student{char ime[128];char prezime[128];int broj_bodova; int relativni_broj_bodova;struct
_student *left; ;struct _student right;}) i sprema ih u binarno stablo pretraživanja. (Napomena : 0 <
broj_bodova <= 100). Ispisati binarno stablo na „inorder“ način.
U tako kreiranom binarnom stablu potrebno je za svakog od studenata izračunati i relativan broj bodova
po formuli: relativan_broj_bodova=( broj_bodova / MAX(broj_bodova) ). Ispisati binarno stablo na
„preorder“ način.
