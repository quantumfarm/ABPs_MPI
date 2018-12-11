#include "obs.h"


inline bool exists_test0 (const string& name) {
            ifstream f(name.c_str());
                return f.good();
}




void obs_gr (Particle GP[], Stat &gr, vector< vector<double> > &f, int num){
  
    

    vector< vector<double> >  point(N, vector<double> (2));

    for (int i=0;i<N;i++){
        point[i][0]=GP[i].pos[0];
        point[i][1]=GP[i].pos[1];
    }

    vector<double> value (N,1.0/rho);  // in order to rescaled the density 

    stringstream fn;
    //fn<<"gr_"<<num*h<<"s_avg"<<gr.avg_n<<"_T"<<T<<"_Dr"<<Dr<<"_v"<<v0<<"_k"<<K<<"_N"<<N<<"_h"<<h<<"_old.txt";
    fn<<"gr_"<<num*h<<"s_avg"<<gr.avg_n<<"_T"<<T<<"_Dr"<<Dr<<"_v"<<v0<<"_K"<<K<<"_N"<<N<<"_h"<<h<<"_dl"<<gr.dx<<"_left.txt";

    field ( point, value, gr, f, fn.str(), num);

}

void obs_current (Particle GP[], Stat &gr, vector< vector<double> > &f1,  vector< vector<double> > &f2,  int num){
    
    vector< vector<double> >  point(N, vector<double> (2));

    for (int i=0;i<N;i++){
        point[i][0]=GP[i].pos[0];
        point[i][1]=GP[i].pos[1];
    }

    vector<double> value0 (N);  
    vector<double> value1 (N);  
    
    for (int i=0;i<N;i++){
        value0[i]=GP[i].vel[0]/rho;
        value1[i]=GP[i].vel[1]/rho;
    }

    stringstream fn;
    //fn<<"gr_"<<num*h<<"s_avg"<<gr.avg_n<<"_T"<<T<<"_Dr"<<Dr<<"_v"<<v0<<"_k"<<K<<"_N"<<N<<"_h"<<h<<"_old.txt";
    fn<<"current_"<<num*h<<"s_avg"<<gr.avg_n<<"_T"<<T<<"_Dr"<<Dr<<"_v"<<v0<<"_K"<<K<<"_N"<<N<<"_h"<<h<<"_dl"<<gr.dx<<"_left.txt";

    field ( point, value0, value1, gr, f1,f2, fn.str(), num);

}

void obs_vn (Particle GP[], Stat &gr ){

    for (int i=0;i<N;i++){
        double dx=GP[i].pos[0]-Lx*0.5;
        double dy=GP[i].pos[1]-Ly*0.5;
        double dr= sqrt ( pow(dx,2) +pow(dy,2) );
    

        if (dr<1.0) {
         
        }

    }

  
}



void Output (Particle GP[],int i, int W, double u){

    stringstream file_name;
    file_name<<"../obs/xv/xv"<<"_K"<<K<<"_T"<<T<<"_gam"<<gam<<"_phi"<<phi<<"_N"<<N<<"_L"<<Lx<<"_h"<<h<<"_Dr"<<Dr<<"_v"<<v0<<"_U"<<u<<"_p"<<W<<"_i"<<i;
    //file_name<<"xv"<<dyn_type<<"N"<<N<<"L"<<Lx<<"k"<<K<<"_"<<i;

    ofstream ofs;
    ofs.open(file_name.str().c_str(),ios::out);
    ofs<<"#particle\t"<<"x0\t"<<"x1\t"<<"v0\t"<<"v1\t"<<"f0\t"<<"f1\t"<<"angle\t"<< endl;

   for (int i=0;i<N;i++)
    ofs<<i<<"\t"
       <<GP[i].pos[0]<<"\t"<<GP[i].pos[1]<<"\t"
       <<GP[i].vel[0]<<"\t"<<GP[i].vel[1]<<"\t"
       <<GP[i].f[0]<<"\t"<<GP[i].f[1]<<"\t"
       <<GP[i].ang<<endl;


}

void obs_Fcol (Particle &Probe, int i,int W, double u, ofstream& ofs){


    if ((i==0)) {
        stringstream file_name;
        file_name<<"../obs/f/F"<<"_K"<<K<<"_T"<<T<<"_gam"<<gam<<"_phi"<<phi<<"_N"<<N<<"_L"<<Lx<<"_h"<<h<<"_Dr"<<Dr<<"_v"<<v0<<"_U"
<<u<<"_p"<<W;
        if ( exists_test0( file_name.str().c_str() ) )  remove( file_name.str().c_str() );
        ofs.open(file_name.str().c_str(),ofstream::app);
        ofs<<"#t\t"<<"F_x\t"<<"F_y\t"<<endl;
    }

    ofs<<i*h<<"\t"<<Probe.f[0]/rho<<"\t"<<Probe.f[1]/rho<<endl; // force is rescaled by the density rho

}
