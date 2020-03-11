
#include <iostream>
#include <dlfcn.h>

int main(int argc, char ** argv)
{
	int data1=3;
	int data2=5;

	int *valeur1 (int );
	int *valeur2 (int );

	void *  hndl1;
    void *  hndl2;

	valeur1=composant1(data1,data2);
	valeur2=composant2(data1,data2);

	hndl1 = dlopen("./lib/libComposant1.so",RTLD_LAZY);
    hndl2 = dlopen("./lib/libComposant2.so",RTLD_LAZY);

    (void *)(&valeur1) = dlsym(hndl1,"composant1(data1,data2)");
    (void *)(&valeur2) = dlsym(hndl2,"composant2(data1,data2)");
    
	std::cout << dlsym(hndl1,"getComposant1Version()") << std::endl;
	std::cout << "valeur 1 :" << valeur1 << " valeur 2 :" << valeur2 << std::endl;
}