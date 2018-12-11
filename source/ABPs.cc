/* Test the initial process
"ic_new.cc"
13. March, 2017
Ting Wang
*/



#include <iostream>
#include <random>

#include <time.h> //timing

#include <mpi.h>


#include "myclass.h"
#include "ic.h"
#include "dyn.h"

//#include "pdf.h"
#include "field.h"

#include "obs.h"


#include<vector>


using namespace std;

//const int U_N=3, nd_N=120;
//double U[U_N]={0.000398107, 0.000630957, 0.0008};


const int U_N=1, nd_N=240;
//double U[U_N]={0.000251189};//, 0.000158489, 0.0001};
double U[U_N]={0.00251189};//, 0.000158489, 0.0001};
//double U[U_N]={0.00158489};
//double U[U_N]={0.001};


/*
double U[U_N]={0.001, 0.00158489, 0.00251189, 0.00398107, 0.00630957,
               0.01, 0.0158489, 0.0251189, 0.0398107, 0.0630957,
               0.1, 0.158489, 0.251189, 0.398107, 0.630957,
                1, 1.58489, 2.51189, 3.98107, 6.30957}; 
*/

/*
double U[U_N]={0.001 ,0.00158489 ,0.00251189 ,0.00398107 ,0.00630957 ,
               0.01 ,0.0158489 ,0.0251189 ,0.0398107 ,0.0630957, 
               0.1 ,0.158489 ,0.251189, 0.398107, 0.630957 ,
               1, 1.58489, 2.51189, 3.98107, 6.30957};
*/

int nd[nd_N];


//int nd[nd_N]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 ,26 ,27 ,28 ,29 ,30 ,31 ,32 ,33 ,34 ,35 ,36 ,37 ,38 ,39 ,40 ,41 ,42 ,43 ,44 ,45 ,46 ,47 ,48 ,49 ,50 ,51 ,52 ,53 ,54 ,55 ,56 ,57 ,58 ,59 ,60 ,61 ,62 ,63 ,64 ,65 ,66 ,67 ,68 ,69 ,70 ,71 ,72 ,73 ,74 ,75 ,76 ,77 ,78 ,79 ,80 ,81 ,82 ,83 ,84 ,85 ,86 ,87 ,88 ,89 ,90 ,91 ,92 ,93 ,94 ,95 ,96 ,97 ,98 ,99 ,100 ,101 ,102 ,103 ,104 ,105 ,106 ,107 ,108 ,109 ,110 ,111, 112 ,113, 114 ,115 ,116 ,117, 118, 119, 120};


//double U[U_N]={0.158489, 0.251189, 0.398107};
    



int main(int argc, char *args[]) {



  /*-------------------- initialize MPI environment */
  MPI_Init(NULL, NULL);
  //srand(time(NULL));

  
  int world_rank,world_size;
  int  namelen, numprocs;
  char processor_name[MPI_MAX_PROCESSOR_NAME] ; 


    /** processors numbers ? **/ 
  MPI_Comm_size(MPI_COMM_WORLD,&numprocs); 
  /** num du processeur courant **/ 
  MPI_Get_processor_name(processor_name,&namelen); 
  
  /** rank of current processor **/ 
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  /*total number of process */
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  /**************************************************/


   for (int i=0;i<nd_N;i++) nd[i]=i+1;

   int U_i=world_rank/nd_N;
   int nd_i=world_rank%nd_N;



    /***************start timming***********/
    clock_t t_start, t_end; t_start=clock();
    /***************************************/
 
 



    //define the Probe and N bath particles GP
    Particle Probe;
    Particle *GP; GP=new Particle[N];

    // reduced density calculation
    /*****************/
    Stat gr; 
    //gr.avg_n=1000; 
    gr.avg_n=10; 
    vector< vector<double> >  f(gr.Nx, vector<double> (gr.Ny));
    vector< vector<double> >  f1(gr.Nx, vector<double> (gr.Ny));
    vector< vector<double> >  f2(gr.Nx, vector<double> (gr.Ny));
    /*****************/

    // initialize 

    IC(GP,U[U_i],nd[nd_i]);
    IC(Probe);

    ofstream ofs_Fcol;
 
    int loop;
    if (U[U_i]>0) loop=int (running_length/U[U_i]/h);
    if (U[U_i]==0) loop=int (running_length/h);

    //int loop=10000;
    int dl=loop/100; 
    for (int i=0;i<=loop;i++){

    //    obs_gr(GP,gr,f,i);
        //obs_current(GP,gr,f1,f2,i);
        obs_Fcol (Probe, i,nd[nd_i],U[U_i],ofs_Fcol);

        Dyn (GP,Probe,U[U_i]);

       /*
        if ((i% (dl))==0){
            cout<< i/dl<<endl; 
            Output (GP,i, nd[nd_i], U[U_i]); 
        }
       */
    }


    cout<<"world_rank "<<world_rank<<"\t"<<U[U_i]<<"\t"<<nd[nd_i]<<endl; 

    delete [] GP;
    /*****************end-timing**************************/
    t_end=clock();
    double time=(t_end-t_start)/CLOCKS_PER_SEC;
    cout<<"running time: "<<time<<" seconds."<<endl;

    return 0;


}

