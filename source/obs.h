#include <iostream>
#include <random>

#include <time.h> //timing


#include "myclass.h"
#include "ic.h"
//#include "pdf.h"
#include "field.h"


#include<vector>


using namespace std;
    
void obs_gr (Particle GP[], Stat &gr, vector< vector<double> > &f, int num);
 

void Output (Particle GP[],int i, int W, double U);
void obs_current (Particle GP[], Stat &gr, vector< vector<double> > &f1,  vector< vector<double> > &f2,  int num);


void obs_Fcol (Particle &Probe, int i,int W, double U, ofstream& ofs);
