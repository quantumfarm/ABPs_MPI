/*************************************
// counting the probability distribution function  //

P(X) = dN/N /dX,

 
X=(x1,x2,..., xn) is a point in the n-dimension space, 
and the volume is dX=dx1*dx2*...dxn;

The total sampling is N. 
The number in the volume (x1, x2,..) , (x1+dx1, x2+dx2, ...,) is dN.

Ting Wang

*************************************/


#include "pdf.h"

void stat (vector<int>  &Box, const vector<double>  &point,  double x_min, double x_max, double dx);

//1d scale field
void pdf (const  vector<double>  &point,  double x_min, double x_max, double dx, string file_name){

    
    //creat counting Box
    const int Nx =ceil ( (x_max-x_min) /dx );
    vector<int>   Box(Nx);  // automatically, Box=0;
  
 

    //counting
    stat (Box, point, x_min,x_max,dx);
    
   
    
    //output 
    ofstream ofs; 
    ofs.open(file_name.c_str(),ios::out);

    int num=point.size();
    for (int i=0;i<Nx;i++){
        ofs
        <<x_min+i*dx+0.5*dx<<"\t" 
        <<Box[i]*1.0/num/dx<<"\t"    
        <<endl; 
    }

}




//stat for 1d scale field:  f(x) 
void stat (vector<int>  &Box, const vector<double>  &point,  double x_min, double x_max, double dx){


    int num=point.size();
    for (int i=0;i<num;i++){
        
        int n;

            double r=point[i];
            if ( (r>= x_min) && (r<=x_max) )
                n=floor( (r-x_min)/dx  );
            else return;
     
        Box[ n ]++;

    } //i


}






