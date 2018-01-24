using namespace std;

#include <iostream>
#include <cstring>
#include "Graphe.h"
#include <sys/stat.h>

int main(int argc, char** argv) {
#ifdef TEST_TIB
    cout << "Nombre d'arguments = " << argc << endl;
    for(int i=0;i<argc;i++){
        cout << "Argument n°" << i << "  = " << argv[i]<< endl;
	}
#endif
    if(argc == 1){
        cerr<<"Aucun nom de fichier saisi."<<endl;
        return 1;
    }
    
    bool flagE = false;
    bool flagT = false;
    bool flagG = false;
    string logFile;
    string graphFile;
    unsigned int hour = 24;
    
    //Options
    for(int i=1;i<argc-1;i++){
        if(strcmp(argv[i],"-e")==0){
        	if(!flagE)
            	flagE=true;
            else
            {
            	cerr << "Vous ne pouvez pas mettre l'option -e en double."
		    													<< endl;
		    	return 1;
		    }
        }
        else if(strcmp(argv[i],"-g")==0){
        	if(!flagG)
        	{
		        flagG=true;
		        graphFile = string(argv[++i]);
		    }
		    else
		    {
		    	cerr << "Vous ne pouvez pas mettre l'option -g en double."
		    													<< endl;
		    	return 1;
		    }
        }
        else if(strcmp(argv[i],"-t")==0){
        	if(!flagT)
        	{
		        flagT=true;
		        hour = atoi(argv[++i]);
		    }
		    else
		    {
		    	cerr << "Vous ne pouvez pas mettre l'option -t en double."
		    													<< endl;
		    	return 1;
		    }
        }
        else{
            cerr << "L'argument " << argv[i] << " est inconnu."<< endl;
        	return 1;
        }
    }
    
    //nom de fichier .log
    logFile = string(argv[argc-1]);
    size_t indexSlash = logFile.find_last_of('/');
    if(indexSlash == string::npos)
        indexSlash = 0;
    size_t indexPoint = logFile.find_last_of('.');
    if(indexPoint != logFile.find_first_of('.',indexSlash)  ||
                            logFile.substr(indexPoint).compare(".log"))
    {
        cerr << "Le nom de fichier des logs " << logFile <<
                                        " n'est pas conforme." << endl;
        return 1;
    }
    struct stat buffer;   
    if(!(stat (logFile.c_str(), &buffer) == 0))
    {
        cerr << "Le fichier des logs " << logFile <<
                                        " n'existe pas." << endl;
        return 1;
    }

#ifdef TEST_TIB
    cout << "flagE=" << flagE << endl;
    cout << "flagT=" << flagT << endl;
    cout << "flagG=" << flagG << endl;
    cout << "logfile=" << logFile << endl;
    cout << "graphFile=" << graphFile << endl;
    cout << "hour=" << hour << endl;
#endif

    Graphe monGraphe(logFile, flagE, flagG, hour);
#ifdef TEST_FLO
	monGraphe.AfficheTEST_FLO();
#endif
    if(flagG){ //si option graphe activé
		monGraphe.Exporter(graphFile);
    }
    
    monGraphe.AfficherPlusConsultes();
}
