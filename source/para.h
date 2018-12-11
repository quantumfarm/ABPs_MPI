#ifndef __PARA_H_INCLUDED__

#define __PARA_H_INCLUDED__


//#include "Memory.h"

/*---------------------------------------------------------*/
#define D 2       //dimension

#define phi 0


#define Lx 32
#define Ly 32


//#define N 100000

#define N 1000

#define rho (N/(Lx*Ly-Pi*0.25))

//#define rho (N/(Lx*Ly))

#define BB 0




//#define N 100000
//#define Lx 32
//#define Ly 32

#define L_box 4   //small box size for neigbor list

#define R 0.5       // particle size

#define K 200

#define gam 1
#define T 0

#define h 0.005

#define running_length 10 // running time (seconds)
//#define running_length 100 // running time (seconds)

//#define running_time 1000

//#define Dr 0
//#define v0 1

#define Dr 50
#define v0 1

#define mu  0       //friction coefficient


#define Pi 3.1415926

//#define type "O"  //over-damped dynamics
//#define type "U" //under-damped dynamics








/*---------------------------------------------------------*/

//1.58489 2.51189 3.98107 6.30957

//#define U   1//6.30957//100      //pulling velocity
//#define nd 1 //10     //loop of ic

#endif
