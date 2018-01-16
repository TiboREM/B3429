#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv) {
    if(argc == 0){
        cerr<<"nom fichier non valide"<<endl;
    }
    bool flagE = false;
    bool flagT = false;
    bool flagG = false;
    string logFile;
    string graphFile;
    int hour;
    cout<<argc<<endl;
    for(int i=1;i<argc;i++){
        cout<<i<<" "<<argv[i]<<endl;
        if(strcmp(argv[i],"-e")==0){
            flagE=true;
        }
        else if(strcmp(argv[i],"-g")==0){
            flagG=true;
            ++i;
            graphFile = string(argv[i]);

        }
        else if(strcmp(argv[i],"-t")==0){
            flagT=true;
            ++i;
            hour = atoi(argv[i]);
        }
        else if(argv[i][0]=='-'){
            cerr<<"unrecognised argument"<<endl;
        }
        else{
            logFile = string(argv[i]);
        }
    }
    cout<<"flagE="<<flagE<<endl;
    cout<<"flagT="<<flagT<<endl;
    cout<<"flagG="<<flagG<<endl;
    cout<<"logfile="<<logFile<<endl;
    cout<<"graphFile="<<graphFile<<endl;
    cout<<"hour="<<hour<<endl;

    if(flagG){ //si option graphe activé
        if (flagE && flagT==0){//option g et e
            cout<<"option g et e active"<<endl;
        }
        if (flagT && flagE ==0 ){
            //option g;e et ;t avec hour
            cout<<"option g et t  active"<<endl;
        }
        cout<<"option g active"<<endl;

    }




}
