/* Test the initial process
"ic_new.cc"
13. March, 2017
Ting Wang
*/

#include <iostream>
#include <random>

#include <time.h> //timing


#include "myclass.h"
#include "ic.h"
#include "dyn.h"



#include "obs_field.h"


#include<vector>

using namespace std;

    double U;
    int nd;


int main (){

    /***************start timming***********/
    clock_t t_start, t_end; t_start=clock();
    /***************************************/

    cin>>U;
    cin>>nd;

    //define the Probe and N bath particles GP
    Particle Probe;
    Particle *GP; GP=new Particle[N];

    // initialize 
    IC(GP,U,nd);
    IC(Probe);

 
    int loop;
    if (U>0) loop=int (running_length/U/h);
    if (U==0) loop=int (running_length/h);

    //int loop=10000;
    int dl=loop/10; 
    for (int i=0;i<=loop;i++){

        // record ABPs' velocity passing through the probe. (vn, vt)
        obs_gr (GP, dl, i, nd);
        
        Dyn (GP,Probe,U);
        
       
        //if ((i% (dl))==0){
        if ((i% (dl))==0){
            cout<< i/dl<<endl; 
        }
    }

    delete [] GP;


    /*****************end-timing**************************/
    t_end=clock();
    double time=(t_end-t_start)/CLOCKS_PER_SEC;
    cout<<"running time: "<<time<<" seconds."<<endl;

    return 0;

}

