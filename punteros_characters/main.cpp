#include <iostream>

using namespace std;

int cant_Iterativo(char *a)
{
    short tam;
    for (tam=0; *a!='\0'; a++)
    {
        ++tam;
    }
    return tam;
}

int cant_Recursivo(char *a, short tam=0)
{
    if (*a!='\0')
    {
        cant_Recursivo(++a, ++tam);
    }
    else
    {
        return tam;
    }
}

void invertir_Iterativo(char *a, int tam)
{
    char *b=a+tam;
    for (int i=0; i<tam; i++)
    {
        swap(*a,*b);
        a++;
        b--;
        tam--;
    }
}

void invertir_Recursiva(char *a, short tam, short i=0)
{
    char *b=a+tam-i;
    if (i<tam)
    {
        swap (*a,*b);
        invertir_Recursiva(++a,--tam,++i);
    }
}

bool palindrome_Iterativo(char *a,short tam)
{
    char *b=a+tam;
    for (short i=0; i<tam; i++)
    {
        if (*a!=*b)
        {
            return false;
        }
        a++;
        b--;
        tam--;
    }
    return true;
}

bool palindrome_Recursivo(char *a, short tam, short i=0)
{
    char *b=a+tam-i;
    if (*a!=*b)
    {
        return false;
    }
    else
    {
        palindrome_Recursivo(++a,--tam,++i);
    }
    return true;
}

int main()
{
    char frase[]="holaz";
    char *ptr=frase;
    cout<<ptr<<endl;
    short tam=cant_Iterativo(ptr)-1;

    cout<<"la cantidad de carecteres-ITERATIVO: ";
    cout<<cant_Iterativo(ptr)<<endl;

    cout<<"la cantidad de carecteres-RECURSIVO: ";
    cout<<cant_Recursivo(ptr)<<endl;

    cout<<"Ahora invertiremos la cadena-ITERATIVA: ";
    invertir_Iterativo(ptr,tam);
    cout<<ptr<<endl;

    cout<<"Ahora invertiremos la cadena-RECURSIVA: ";
    invertir_Recursiva(ptr,tam);
    cout<<ptr<<endl;

    char jaja[]="meza que mas aplaudaadualpa sam euq azem";
    ptr = jaja;

    cout<<ptr<<endl;

    tam=cant_Iterativo(ptr)-1;

    cout<<"será o no será palindrome-ITERATIVO: ";

    if (palindrome_Iterativo(jaja,tam))
    {
        cout<<"es"<<endl;
    }
    else
    {
        cout<<"no es"<<endl;
    }

    cout<<"será o no será palindrome-RECURSIVO: ";

    if (palindrome_Recursivo(jaja,tam))
    {
        cout<<"es"<<endl;
    }
    else
    {
        cout<<"no es"<<endl;
    }

    return 0;
}
