#include<iostream>
#include<cstdlib>
#include<string.h>

using namespace std;

struct usuario {
    int tarjeta;
    int fecha;
    int NIP;
    int dineros;
    struct usuario *sig;
};

typedef struct usuario *nodo;

void almacenarDatos(nodo &lista);
void capturarDatos(nodo &lista);
void procesarDatos(nodo &d);
void consultarDatos(nodo &d);
void imprimirDatos(nodo d);
int menu(nodo &d);


int main(){
    int a;
    nodo lista=NULL;
    do{
        cout<<"\n\t\tCAJERO AUTOMATICO";
        cout<<"\n\t\t-----------------";
        cout<<"\n1-Crear usuario";
        cout<<"\n2-Ingresar";
        cout<<"\n3-Salir";
        cout<<"\nQue desea hacer? ";
        cin>>a;
        switch(a){
            case 1:{ system("cls");
            almacenarDatos(lista);
            }break;

            case 2:{ system("cls");
            capturarDatos(lista);
            }break;

            case 3: return 0;
            break;

            default: cout<<"\nPorfavor digite una opcion valida"; break;
        }
    }while(a!=4);
    return 0;
}

void almacenarDatos(nodo &lista){
    nodo x, d = new(struct usuario);
     cout<<"\t[ REGISTRAR USUARIO NUEVO ]\n";
    cin.ignore();cout<<"\nIngrese el numero de tarjeta: ";cin>>d->tarjeta;
    cin.ignore();cout<<"\nIngrese el anio de caducidad de su tarjeta: ";cin>>d->fecha;
    cin.ignore();cout<<"\nIngrese un NIP personalizado: ";cin>>d->NIP;
    cin.ignore();cout<<"\nIngrese su saldo inicial: ";cin>>d->dineros;
    d->sig=NULL;
    if(lista==NULL){
        lista = d;
    }
    else{
        x = lista;
        while(x->sig!=NULL){
            x = x->sig;
        }
        x->sig = d;
    }
}

void capturarDatos(nodo &lista){

    int valida;
    int numIn = 0;
    int caducidad;
    int id;
    nodo x;
    nodo d = lista;

    cout<<"\nPorfavor ingrese su tarjeta: ";cin>>valida;cout<<"\nFecha de vencimiento: ";cin>>caducidad;

    while(d!=NULL){
        if(d->tarjeta==valida){
                if(d->fecha>=caducidad){
            if(d==lista)
                lista=lista->sig;
            else
                x->sig=d->sig;
                while(numIn < 3){

           cout<<"\n\tIngresar al CA";
           cout<<"\nPorfavor ingrese su NIP: ";
           cin>>id;
    if(d->NIP==id){
            cout<<"\nUsted ha ingresado correctamente!!";
            system("cls");
            menu(d);
            }else{
             cout<<"\nNIP incorrecto!!";
             numIn = numIn + 1;
        }
    }
   }else{cout<<"\nTarjeta no valida...";
   return;
   }
   }else{
        x=d;
        d=d->sig;
      }
 }
 if(d==NULL)
 cout<<"\nTarjeta no valida...";
}

int menu(nodo &d){
    int c;
    do{
        cout<<"\n\tBienvenido al CA, porfavor seleccione una accion";
        cout<<"\n1-Consultar saldo actual";
        cout<<"\n2-Retirar o agregar saldo";
        cout<<"\n3-Imprimir la lista de usuarios";
        cout<<"\n4-Salir";
        cout<<"\nIngrese una opcion: ";
        cin>>c;

        switch(c){
        case 1: system("cls");
        consultarDatos(d);
        break;

        case 2: system("cls");
        procesarDatos(d);
        break;

        case 3: system("cls");
        imprimirDatos(d);
        break;

        case 4: system("cls");
        exit(0);
        break;

        default: cout<<"\nPorfavor digite una opcion valida"; break;
        }
    }while(c!=5);
}

void consultarDatos(nodo &d){
    cout<<"\nEste es su saldo actual: "<<d->dineros;cout<<"\n";
    system("pause");
    return;
}

void procesarDatos(nodo &d){
    int f;
    int MAX = 800; //saldo maximo
    int act;
    do{
        cout<<"Ingrese 1 para retirar dinero o 2 para agregar dinero a su saldo actual: ";
        cin>>f;

        switch(f){
        case 1: system("cls");
        cout<<"Ingrese el monto a retirar: ";
        cin>>act;
        if(act<=d->dineros){
            if(act<=MAX){
                d->dineros = d->dineros - act;
                cout<<"\nSe ha retirado el saldo correctamente.";
            }else cout<<"\nEl numero supera el limite de saldo a retirar..."; return;
        }else {cout<<"\nUsted tiene saldo insuficiente... "; return;}
        break;

        case 2: system("cls");
        cout<<"Ingrese el monto a ingresar: ";
        cin>>act;
        d->dineros = d->dineros + act;
        cout<<"Se ha agregado correctamente el saldo.";
        consultarDatos(d);
        break;

        default: cout<<"Esa opcion no es valida... \n"; break;
        }
    }while(f!=3);
}

void imprimirDatos(nodo d){

    int i=1;

    while(d!=NULL){

        cout<<"\n\n\tDATOS DEL USUARIO ";
        cout<<"\nNumero de tarjeta   : "<<d->tarjeta<<endl;
        cout<<"\nAño de vencimiento  : "<<d->fecha<<endl;
        cout<<"\nSu numero PIN       : "<<d->NIP<<endl;
        cout<<"\nSaldo actual        : "<<d->dineros<<endl;

        d=d->sig;

        i++;
    }
}















