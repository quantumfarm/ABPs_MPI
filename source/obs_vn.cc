#include "obs.h"

double abs (const double x[], const double y[]);

inline bool exists_test0 (const string& name) {
            ifstream f(name.c_str());
                return f.good();
}



void obs_vnvt ( Particle GP[], int dl, int loop_i, int W){


    Pdf pdf_vn;
    Pdf pdf_vt;
    for (int i=0;i<N;i++){
        double x=GP[i].pos[0]-Lx*0.5;
        double y=GP[i].pos[1]-Ly*0.5;
        double dr= sqrt ( pow(x,2) +pow(y,2) );
    

        if (dr<1.0) {
            double nx=x/dr, ny=y/dr;
            double tx=-ny, ty=nx;

            double vn=GP[i].pos[0]*nx+GP[i].pos[1]*ny;
            double vt=GP[i].pos[0]*tx+GP[i].pos[1]*ty;
            cout<<"vn="<<vn<<"\tvt="<<vt<<endl;
            pdf_vn.stat(vn);
            pdf_vt.stat(vt);
        }

    }
    
    if ( (loop_i% (dl) )==0){
        stringstream fvn, fvt;
        fvn<<"../obs/"<<"pdf_vn_K"<<K<<"_T"<<T<<"_gam"<<gam<<"_phi"<<phi<<"_N"<<N<<"_L"<<Lx<<"_h"<<h<<"_Dr"<<Dr<<"_v"<<v0<<"_p"<<W<<"_t"<<loop_i*h;
        fvn<<"../obs/"<<"pdf_vt_K"<<K<<"_T"<<T<<"_gam"<<gam<<"_phi"<<phi<<"_N"<<N<<"_L"<<Lx<<"_h"<<h<<"_Dr"<<Dr<<"_v"<<v0<<"_p"<<W<<"_t"<<loop_i*h;
   
        pdf_vn.output(fvn.str());    
        pdf_vt.output(fvt.str());    
     
    }
}

