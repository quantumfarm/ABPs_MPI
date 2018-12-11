#include "obs_field.h"


void obs_gr ( Particle GP[], int dl, int loop_i, int W){

    Field_1d gr;
    for (int i=0;i<N;i++){

        // get relative distance r=|r_i - r_probe| 
        double x=GP[i].pos[0]-Lx*0.5;
        double y=GP[i].pos[1]-Ly*0.5;
        double r= sqrt ( pow(x,2) +pow(y,2) ); // relative distance r=|r_i - r_probe|

        //counting number     
        gr.stat(r);

    }
    

    if ( (loop_i% (dl) )==0){
        stringstream ss;
        ss<<"../obs/"<<"gr_K"<<K<<"_T"<<T<<"_gam"<<gam<<"_phi"<<phi<<"_N"<<N<<"_L"<<Lx<<"_h"<<h<<"_Dr"<<Dr<<"_v"<<v0<<"_p"<<W<<"_t"<<loop_i*h;
        
        gr.output_gr(ss.str());    
     
    }


}



