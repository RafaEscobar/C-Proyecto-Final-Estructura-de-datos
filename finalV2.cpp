#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// VECTOR
int tama;
int arr_vect[0];
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// ARREGLO
int filas=0;
int columnas=0;
int arreglo[100][100];
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
// COLAS
struct dates {
 int date;                   
 dates *s;
 }*p,*aux,*u;

void insertar (int dat);
void borrar ();
void listar ();

void menuColas(){
	int opc,y;
	do{
	cout<<"1. Insertar"<<endl;
	cout<<"2. Borrar"<<endl;
	cout<<"3. Listar"<<endl;
	cout<<"4. Salir"<<endl;
	cout<<"Ingrese opcion: ";
	cin>>opc;
	switch(opc){
		case 1: cout<<"Ingrese date: ";
	 		cin>>y;
 			insertar(y);
 			cout<<endl<<"\ndate insertado!!"<<endl<<endl;
	 	break;
		case 2: 
			cout<<endl<<"==================================="; 
			borrar();
			cout<<"==================================="<<endl<<endl; 
 		break;
		case 3:
			cout<<"==================================="<<endl; 
			cout<<"#### Valores de la cola ####";
			listar();
			cout<<endl;
			cout<<"==================================="<<endl<<endl; 
		break;
		case 4:
	 		cout<<"==============================================="<<endl;
			cout<<"Saliendo de MENU DE LISTAS..."<<endl;
			cout<<"==============================================="<<endl<<endl;
			system("pause");
		break;
		default: 
			cout<<"\n Opcion no valida, ingrese una opción correcta..."<<endl; 
		break;
	}
	}while(opc!=4);
}

void insertar (int dat){
	aux=new(dates);
	aux->date=dat;
	if(u){
		u->s=aux;
		aux->s=NULL;
		u=aux;
	}else{
		p=u=aux;
	}
}

void borrar(){
	if(p){
		aux=p;
		cout<<endl<<"\nSe elimino: "<<p->date<<endl;
		p=aux->s;
		delete(aux);
	}else{
		cout<<"\n No hay dates";
	}
}

void listar(){
	int i;
	if(!u){
		cout<<"\n No hay dates en la cola"<<endl;
		return;
	}
	aux=p;
	while(aux){
		cout<<endl<<" -"<<aux->date;
		aux=aux->s;
	}
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
struct Noda{
 	int datao;
 	Noda *siguiente;
};

//Prototipos de Función
void agregarPila(Noda *&,int); 
void sacarPila(Noda *&,int &);

void agregarPila(Noda *&pila,int n){
 	Noda *nuevo_Noda = new Noda();
 	nuevo_Noda->datao = n;
 	nuevo_Noda->siguiente = pila;
 	pila = nuevo_Noda;
 	cout<<endl<<"\tElemento ("<<n<<") agregado!!"<<endl;
}

void sacarPila(Noda *&pila,int &n){
	 Noda *aux = pila;
 	n = aux->datao;
 	pila = aux->siguiente;
 	delete aux;
}

void menuPilas(){
 	Noda *pila = NULL;
	 int datao;
 	char rpt;
	int opc,y;
	do{
		cout<<endl<<"1. Insertar"<<endl;
		cout<<"2. Listar"<<endl;
		cout<<"3. Sacar"<<endl;
		cout<<"4. Salir"<<endl;
		cout<<"\n Ingrese opcion: ";cin>>opc;
	switch(opc){
		case 1: 
 		do{ 
  			cout<<"Digite un numero: ";
  			cin>>datao;
  			agregarPila(pila,datao);
  			cout<<"\nDesea agregar otro numero a pila(s/n): ";
  			cin>>rpt;
 		}while((rpt == 's')||(rpt=='S'));
 		break;
		case 2: 
			cout<<"\nMostrando los elementos de la pila: "<<endl;
			cout<<"====================================";
 			while(pila != NULL){
   				cout<<endl;
  				sacarPila(pila,datao);
  				if(pila != NULL){
	   				cout<<datao<<", ";
  				}else{
	   				cout<<datao<<"."<<endl;
   					cout<<"==========================="<<endl;
  				}
 			}
 		break;
 
		case 3: 
		cout<<"====================================="<<endl;
		cout<<"\nValores eliminados corectamente... "<<endl;
		cout<<"====================================="<<endl;
 		while(pila != NULL){
  			sacarPila(pila,datao);
  			if(pila != NULL){
	   			cout<<datao<<" , ";
  			}else{
   				cout<<datao<<".";
  			}
 		}
		break;
		case 4: 
			cout<<"==============================================="<<endl;
			cout<<"Saliendo de MENU DE ARBOL BINARIO..."<<endl;
			cout<<"==============================================="<<endl<<endl;
			system("pause");
		break;
		default: 
			cout<<"\n Opcion no valida!!"; 
		break;
	}
	}while(opc!=4);
}
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//LISTAS
//estructura Nodu
struct Nodu{
 int date;                   
 Nodu *siguiente;
 };
 
 //Prototipo de la funcion
void menuLista();
void eliminarLista(Nodu *&,int &);
void insertarLista(Nodu *&,int);
void mostarLista(Nodu *);

Nodu *lista =NULL;
//menu
void menuLista(){
	int opcion,date;
	
	do{
		cout<<"1. Insertar\n";
		cout<<"2. Mostrar\n";
		cout<<"3. Eliminar\n";
		cout<<"4. Salir\n";
		cout<<"\nIngrese opcion: ";
		cin>>opcion;
		switch(opcion){
			case 1:
				system("cls");
				cout<<"##### Insertar #####"<<endl;
				cout<<"Ingrese un numero"<<endl;
				cin>>date;  
				insertarLista(lista,date);
				cout<<"\n";
				system("pause");
			break;
			case 2:
				system("cls");
				cout<<"##### Mostrar #####"<<endl;
				mostarLista(lista);
				cout<<"\n";
				system("pause");
			break;
			case 3:
				while(lista != NULL){
					eliminarLista(lista, date);
					cout<<date<<"->";
				}
				cout<<endl;
				cout<<"ELIMINADOS...."<<endl<<endl;
				system("pause");	
			break;
			case 4:
				cout<<"==============================================="<<endl;
				cout<<"Saliendo de MENU DE LISTAS..."<<endl;
				cout<<"==============================================="<<endl<<endl;
				system("pause");
			break;
			default:
				cout<<"Opción incorrecta, digite una opción valida..."<<endl<<endl;;
		}
		system("cls");
	}while(opcion !=4);
 }

//Insertar elementos a lista
void insertarLista(Nodu *&lista,int n){
	Nodu *nuevo_Nodu = new Nodu();
	nuevo_Nodu->date=n;
	
	Nodu *aux1 = lista;
	Nodu *aux2;
	
	while((aux1 !=NULL)&& (aux1->date<n)){
		aux2 = aux1;
		aux1 = aux2->siguiente;
	}
	if(lista==aux1){
		lista=nuevo_Nodu;
	}else{
		aux2->siguiente=nuevo_Nodu;
	}
	nuevo_Nodu->siguiente=aux1;
	cout<<"Elemento ("<<n<<") insertado correctamente \n";
}

//Mostrar lista
void mostarLista(Nodu *lista){
	int i;
	Nodu *actual = new Nodu();
	actual = lista;
	if(actual == NULL){
		cout<<"No hay elementos en la lista";
	}
	while(actual != NULL){
		cout<<"\n"<<++i<<"->"<<actual->date<<endl;
		actual = actual->siguiente;
	}
}

void eliminarLista(Nodu *&lista,int &n){
	Nodu *aux = lista;
	n= aux ->date;
	lista = aux->siguiente;
	delete aux;
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// ARBOL BINARIO

struct Node{
	int date;
	Node *der;
	Node *izq;
};

// Prototipos
void menu();
Node *crearNode(int);
void insertarNode(Node *&, int);

Node *arbol = NULL;

Node *crearNode(int n){
	Node *nuevo_node = new Node();
	
	nuevo_node->date = n;
	nuevo_node->der = NULL;
	nuevo_node->izq = NULL;
	
	return nuevo_node;
}

void insertarNode(Node *&arbol, int n){
	if(arbol == NULL){
		Node *nuevo_node = crearNode(n);
		arbol = nuevo_node;
	}else{
		int valorRaiz = arbol->date;
		if(n<valorRaiz){
			insertarNode(arbol->izq,n);
		}else{
			insertarNode(arbol->der,n);
		}
	}
}

void mostrarArbol(Node *arbol, int cont){
	if(arbol == NULL){
		return;
	}else{
		mostrarArbol(arbol->der, cont+1);
		for(int i=0; i<cont; i++){
			cout<<"  ";
		}
		cout<<arbol->date<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}

void menuArbol(){
	int date, opcion, contador=0;
	
	do{
		cout<<"1. Insertar nuevo Nodu"<<endl;
		cout<<"2. Mostrar arbol"<<endl;
		cout<<"3. Salir"<<endl;
		cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"Digite un numero: ";
				cin>>date;
				insertarNode(arbol, date);
				cout<<endl;
				system("pause");
			break;
			case 2:
				cout<<"Visualización de arbol: "<<endl;
				mostrarArbol(arbol, contador);
				cout<<endl;
				system("pause");
			break;
			case 3:
				cout<<"==============================================="<<endl;
				cout<<"Saliendo de MENU DE LISTAS..."<<endl;
				cout<<"==============================================="<<endl<<endl;
				system("pause");
			break;
			default:
				cout<<"Opción incorrecta, ingrese una nueva opción...";
			break;
		}
	}while(opcion!=3);
}

////////////////////////////////////////////////////////////////////////////////
//VECTOR
// Dar tamaño
void darTV(){
	int tam;
	cout<<"Ingrese el tamaño del vector"<<endl;
	cin>>tam;
	tama=tam;
}
// Tamaño vector
int verTV(){
	return tama;
}
// Crear vector
int crearVector(){
	darTV();
	int tamanoV=verTV();
	for(int i=0; i<tamanoV; i++){
		cout<<"Ingrese un numero ["<<(i+1)<<"]: "<<endl;
		cin>>arr_vect[i];
	}
	return tamanoV;
}
// Mostrar vector
void verVector(){
	cout<<endl<<"==================================="<<endl;
	int lo = verTV();
	int bandera=0, control=0;
	for(int i=0;i<lo;i++){
		if(arr_vect[i]!=0){
			cout<<endl;
			cout<<"Posicion: "<<i<<", con valor: "<<arr_vect[i];
			control++;
		}else if(arr_vect[i]==0 && control>=1){
			cout<<endl;
			cout<<"Posicion: "<<i<<", con valor: "<<arr_vect[i];
		}else{
			bandera++;
		}
    }
    if(bandera==lo){
    	cout<<"Vector vacio";
	}
    cout<<endl<<"==================================="<<endl;
}
// Borrar vector
void delVector(){
	system("cls");
	int opcion;
	cout<<"Que posicion deseas eliminar?";
	cin>>opcion;
	if (opcion<tama){
		arr_vect[opcion]=0;
		cout<<"Se elimino la posicion: "<<opcion<<endl;
	}else{
		system("cls");
		cout<<"Posicion no existe..."<<endl;
		system("pause");
	}
	
}
////////////////////////////////////////////////////////////////////////////////

// MENU CRUD
void menuVector(){
	int opcVector, control=0;
	do{
	cout<<"\n 1. Agregar";
	cout<<"\n 2. Consultar";
	cout<<"\n 3. Eliminar";
	cout<<"\n 4. Salir";
	cout<<"\n Ingrese una opcion: ";
	cin>>opcVector;
	
	switch(opcVector){
		case 1:
			system("cls");
			cout<<"\n Agregar vector "<<endl;
			control=crearVector();
		break;
		
		case 2:
			system("cls");
			cout<<"\n Consultar vector ";
			verVector();
		break;
		
		case 3:
			system("cls");
			cout<<"\n Eliminar vector "<<endl;
			delVector();
		break;
		case 4: 
			cout<<"==============================================="<<endl;
			cout<<"Saliendo de MENU DE LISTAS..."<<endl;
			cout<<"==============================================="<<endl<<endl;
			system("pause");
		break;
		default:
			cout<<"Opcion incorrecta, elija una opción valida....";
		break;
		}
	}while(opcVector!=4);
}

///////////////////////////////////////////////////////////////////////////////>>>>>>>>>>>

////////////////////////////////////////////////////////////////////////////////
//ARREGLO
// Dar tamaño

int menuArreglo(){
	int opcVector=0, answer=0;
	
	cout<<"\n 1. Agregar";
	cout<<"\n 2. Consultar";
	cout<<"\n 3. Eliminar";
	cout<<"\n 4. Salir";
	cout<<"\n Ingrese una opcion: ";
	cin>>opcVector;
	
	return opcVector;	
}

void bidi(){
	
	int myOpc;
	int arreglo[100][100];
	int filas, columnas;
	int fiDel, colDel;
	do{
	myOpc = menuArreglo();
	
	if(myOpc==1){
		cout<<"========================"<<endl;
		cout<<"====== Crear ARRREGLO ====="<<endl;
		cout<<"Ingresa la cantidad de filas: ";
		cin>>filas;
		cout<<"Ingresa la cantidad de columnas: ";
		cin>>columnas;
	
		arreglo[filas][columnas];
		
		for(int i=0; i<filas; i++){
			for(int j=0; j<columnas; j++){
				cout<<"Ingresa el valor para la posicion: ["<<i<<"]"<<"["<<j<<"]"<<endl;
				cin>>arreglo[i][j];
				//cout<<i<<" - "<<j<<endl;
			}
		}
	}else if(myOpc==2){
		cout<<"========================"<<endl;
		cout<<"====== Mostrar ARRREGLO ====="<<endl;
		for(int i=0; i<filas; i++){
			for(int j=0; j<columnas; j++){
				cout<<"Valor => ("<<arreglo[i][j]<<"), para la posicion: ["<<i<<"]"<<"["<<j<<"]"<<endl;
				
			}
		}
		cout<<"========================"<<endl;
	}else if(myOpc==3){
		cout<<"========================"<<endl;
		cout<<"====== Mostrar ARRREGLO ====="<<endl;
		
		
		cout<<"Que posicion deseas eliminar?"<<endl;
		cout<<"Numero de fila: ";
		cin>>fiDel;
		cout<<"Numero de columna: ";
		cin>>colDel;
	
		if (fiDel<filas && colDel<columnas){
			arreglo[fiDel][colDel]=0;
			cout<<"Se elimino la posicion en la fila: "<<fiDel<<" y columna: "<<colDel<<endl;
		}else{
			system("cls");
			cout<<"Posicion no existe..."<<endl;
			system("pause");
		}
	}else if(myOpc==4){
		myOpc=0;
	}
	}while(myOpc!=0);
	
}

////////////////////////////////////////=======================================//////////////////////////////////////////////////////////////
// Menu principal
void menuP(){
	int opcMenuP;
	cout <<"\n  === Bienvenido al Proyecto final === ";
	cout<<"\n 1. Vector";
	cout<<"\n 2. Arreglo";
	cout<<"\n 3. Listas";
	cout<<"\n 4. Pilas";
	cout<<"\n 5. Colas";
	cout<<"\n 6. Arbol binario";
	cout<<"\n 7. Salir";
	cout<<"\n Ingrese una opcion: ";
	cin>>opcMenuP;
	system("cls");
	
	//Menu Grandote Opciones
	switch(opcMenuP){
		//Vector
		case 1:
			cout <<"\n === Vector ===";
			menuVector();
		break;
		//Array
		case 2:
			cout <<"\n === Arreglo ===";
			bidi();
		break;
		case 3:
			cout <<"\n === Listas ==="<<endl;
			menuLista();
		break;
		case 4: 
			cout <<"\n === PILAS ==="<<endl;
			menuPilas();
		break;
		case 5: 
			cout <<"\n === Colas ==="<<endl;
			menuColas();
		break;
		case 6:
			cout <<"\n === Arbol ==="<<endl;
			menuArbol();
		break;
		case 7:
			cout<<"==============================================="<<endl;
			cout<<"Saliendo..."<<endl;
			cout<<"==============================================="<<endl;
		break;
		default:
			cout<<"Opcion incorrecta..."<<endl;
		break;	
	}
}


int main(){
	menuP();
	
	return 0;
}


