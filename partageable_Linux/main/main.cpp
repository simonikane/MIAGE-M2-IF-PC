#include <iostream>
#include <iostream>
#include <dlfcn.h>

int main(int argc, char ** argv)
{
	int data1=3;
	int data2=5;

	int (* valeur1)(int, int);
	int (* valeur2)(int, int);
	char * (* versionComp1)();

	void *  hndl1;
        void *  hndl2;

	hndl1 = dlopen("./libComposant1.so",RTLD_LAZY);
        hndl2 = dlopen("./libComposant2.so",RTLD_LAZY);

        *(void **)(&valeur1) = dlsym(hndl1,"composant1");
        *(void **)(&valeur2) = dlsym(hndl2,"composant2");
    	*(void **)(&versionComp1) = dlsym(hndl1,"getComposant1Version");

	std::cout << "La version du composant 1 est : " << (*versionComp1)() << std::endl;
	std::cout << "Valeur 1 :" << (*valeur1)(data1,data2) << " Valeur 2 :" << (*valeur2)(data1,data2) << std::endl;
	
	dlclose(hndl1);
	dlclose(hndl2);

}

