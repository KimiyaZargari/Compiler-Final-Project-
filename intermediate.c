#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
double * top;
double * sp;
double ** atop;
double t0 , t1 , t2 , t3 , t4 , t5 , t6 , t7 , t8 , t9 , t10 , t11 , t12 , t13 , t14 , t15 , t16 , t17 , t18 , t19 , t20 , t21 , t22 , t23 , t24 , t25 , t26 , t27 , t28 , t29 , t30 , t31 , t32 , t33 , t34 , t35 , t36 , t37 , t38 , t39 , t40 , t41 ;
double *tt0 , *tt1 , *tt2 , *tt3 , *tt4 , *tt5 , *tt6 , *tt7 , *tt8 , *tt9 , *tt10 , *tt11 , *tt12 , *tt13 , *tt14 , *tt15 , *tt16 , *tt17 , *tt18 , *tt19 , *tt20 , *tt21 , *tt22 , *tt23 , *tt24 , *tt25 , *tt26 , *tt27 , *tt28 , *tt29 , *tt30 , *tt31 , *tt32 , *tt33 , *tt34 , *tt35 , *tt36 , *tt37 , *tt38 , *tt39 , *tt40 , *tt41 , *tt42 , *tt43 , *tt44 , *tt45 , *tt46 , *tt47 , *tt48 , *tt49 , *tt50 , *tt51 , *tt52 , *tt53 , *tt54 , *tt55 , *tt56 , *tt57 , *tt58 , *tt59 , *tt60 , *tt61 , *tt62 , *tt63 , *tt64 , *tt65 , *tt66 , *tt67 , *tt68 , *tt69 , *tt70 , *tt71 , *tt72 , *tt73 , *tt74 , *tt75 , *tt76 , *tt77 , *tt78 , *tt79 , *tt80 , *tt81 , *tt82 , *tt83 , *tt84 , *tt85 , *tt86 , *tt87 , *tt88 , *tt89 , *tt90 , *tt91 , *tt92 , *tt93 , *tt94 , *tt95 , *tt96 , *tt97 , *tt98 , *tt99 , *tt100 , *tt101 , *tt102 , *tt103 , *tt104 , *tt105 , *tt106 , *tt107 , *tt108 , *tt109 , *tt110 , *tt111 , *tt112 , *tt113 , *tt114 , *tt115 , *tt116 , *tt117 , *tt118 , *tt119 , *tt120 , *tt121 , *tt122 , *tt123 ;
double **v0 , **v1 , **v2 , **v3 , **v4 , **v5 , **v6 , **v7 ;
int i0 , i1 , i2 , i3 ;
int main() {
top = (double *) malloc(sizeof(double) *10001);
atop = (double **) malloc(sizeof(double*) *1001);
top = top + 10000;
atop = atop + 1000;
sp = top;

*top = 0;

	top = top - 1; 
		goto L9; 
L0:
	sp = top; 
//func decleration:  _main
	top = top - 4; 
L1:
L2:
L3:
//looking for: num 
//the variable is found! id and size: 1 4
//var is inside offset:  -1 
	tt0 = sp - 1; 
	*tt0 = 5523; 
L4:
//looking for: num 
//the variable is found! id and size: 1 4
//var is inside offset:  -1 
	tt1 = sp - 1; 
	t0 = *tt1; 
//looking for: t0 
//the variable is found! id and size: 1 -2
//var is inside offset:  -2 
	tt2 = sp - 2; 
// save temp val: stack add: tt2 t0
	*tt2 = t0; 
//function call: getPalindrome 
//arg: t0 
	top = top - 1; 
//looking for: t0 
//the variable is found! id and size: 1 -2
//var is inside offset:  -2 
	tt3 = sp - 2; 
// load temp val: stack add: tt3 t0
	t0 = *tt3; 
	*top = t0; 
//looking for: getPalindrome 
	top = top - 1; 
	*top = -10; 
	top = top - 1; 
	tt4 = &&L5; 
	atop = atop - 1; 
	*atop = tt4; 
	top = top - 1; 
	top = top - 1; 
	*top = -1; 
	atop = atop - 1; 
	*atop = sp; 
		goto L30; 
//return after func call  
L5:
	top = top + 1; 
	t1 = *top; 
	top = top + 2; 
	i0 = *top; 
	i0 = i0 + 1; 
	top = top + i0; 
	sp = *atop; 
	atop = atop + 2; 
//every thing is normal after func call: getPalindrome 
//looking for: t1 
//the variable is found! id and size: 1 -2
//var is inside offset:  -3 
	tt5 = sp - 3; 
// save temp val: stack add: tt5 t1
	*tt5 = t1; 
//looking for: num 
//the variable is found! id and size: 1 4
//var is inside offset:  -1 
	tt6 = sp - 1; 
	*tt6 = t1; 
L6:
//looking for: num 
//the variable is found! id and size: 1 4
//var is inside offset:  -1 
	tt7 = sp - 1; 
	t2 = *tt7; 
//looking for: t2 
//the variable is found! id and size: 1 -2
//var is inside offset:  -4 
	tt8 = sp - 4; 
// save temp val: stack add: tt8 t2
	*tt8 = t2; 
printf("%lf\n", t2 );
L7:
L8:
//return  
	top = top + 4; 
	v0 = atop + 1; 
	tt9 = *v0; 
		goto *tt9; 
L9:
//in topPlsLoclNum() 4 5
//in topPlsLoclNum() 4 87
//in topPlsLoclNum() 4 87
//num _main _main
		goto L29; 
L10:
	sp = top; 
//func decleration:  getPalindrome
	top = top - 14; 
//param entered in:  getPalindrome num
L11:
L12:
L13:
//looking for: pal 
//the variable is found! id and size: 2 4
//var is inside offset:  -1 
	tt10 = sp - 1; 
	*tt10 = 0; 
L14:
L15:
//looking for: num 
//the variable is found! id and size: 2 4
//var is inside offset:  1 
	tt11 = sp + 4; 
	t3 = *tt11; 
//looking for: t3 
//the variable is found! id and size: 2 -2
//var is inside offset:  -2 
	tt12 = sp - 2; 
// save temp val: stack add: tt12 t3
	*tt12 = t3; 
//looking for: t3 
//the variable is found! id and size: 2 -2
//var is inside offset:  -2 
	tt13 = sp - 2; 
// load temp val: stack add: tt13 t3
	t3 = *tt13; 
if ( t3 >= 0 )
		goto L18; 
L16:
		goto L25; 
L17:
L18:
L19:
L20:
//looking for: num 
//the variable is found! id and size: 2 4
//var is inside offset:  1 
	tt14 = sp + 4; 
	t4 = *tt14; 
//looking for: t4 
//the variable is found! id and size: 2 -2
//var is inside offset:  -4 
	tt15 = sp - 4; 
// save temp val: stack add: tt15 t4
	*tt15 = t4; 
//function call: getUnit 
//arg: t4 
	top = top - 1; 
//looking for: t4 
//the variable is found! id and size: 2 -2
//var is inside offset:  -4 
	tt16 = sp - 4; 
// load temp val: stack add: tt16 t4
	t4 = *tt16; 
	*top = t4; 
//looking for: getUnit 
	top = top - 1; 
	*top = -10; 
	top = top - 1; 
	tt17 = &&L21; 
	atop = atop - 1; 
	*atop = tt17; 
	top = top - 1; 
	top = top - 1; 
	*top = -1; 
	atop = atop - 1; 
	*atop = sp; 
		goto L50; 
//return after func call  
L21:
	top = top + 1; 
	t5 = *top; 
	top = top + 2; 
	i1 = *top; 
	i1 = i1 + 1; 
	top = top + i1; 
	sp = *atop; 
	atop = atop + 2; 
//every thing is normal after func call: getUnit 
//looking for: t5 
//the variable is found! id and size: 2 -2
//var is inside offset:  -5 
	tt18 = sp - 5; 
// save temp val: stack add: tt18 t5
	*tt18 = t5; 
//looking for: units 
//the variable is found! id and size: 2 4
//var is inside offset:  -3 
	tt19 = sp - 3; 
	*tt19 = t5; 
L22:
//looking for: pal 
//the variable is found! id and size: 2 4
//var is inside offset:  -1 
	tt20 = sp - 1; 
	t6 = *tt20; 
//looking for: t6 
//the variable is found! id and size: 2 -2
//var is inside offset:  -6 
	tt21 = sp - 6; 
// save temp val: stack add: tt21 t6
	*tt21 = t6; 
//looking for: t6 
//the variable is found! id and size: 2 -2
//var is inside offset:  -6 
	tt22 = sp - 6; 
// load temp val: stack add: tt22 t6
	t6 = *tt22; 
	t7 = t6 * 10; 
//looking for: t7 
//the variable is found! id and size: 2 -2
//var is inside offset:  -7 
	tt23 = sp - 7; 
// save temp val: stack add: tt23 t7
	*tt23 = t7; 
//looking for: units 
//the variable is found! id and size: 2 4
//var is inside offset:  -3 
	tt24 = sp - 3; 
	t8 = *tt24; 
//looking for: t8 
//the variable is found! id and size: 2 -2
//var is inside offset:  -8 
	tt25 = sp - 8; 
// save temp val: stack add: tt25 t8
	*tt25 = t8; 
//looking for: t7 
//the variable is found! id and size: 2 -2
//var is inside offset:  -7 
	tt26 = sp - 7; 
// load temp val: stack add: tt26 t7
	t7 = *tt26; 
//looking for: t8 
//the variable is found! id and size: 2 -2
//var is inside offset:  -8 
	tt27 = sp - 8; 
// load temp val: stack add: tt27 t8
	t8 = *tt27; 
	t9 = t7 + t8; 
//looking for: t9 
//the variable is found! id and size: 2 -2
//var is inside offset:  -9 
	tt28 = sp - 9; 
// save temp val: stack add: tt28 t9
	*tt28 = t9; 
//looking for: pal 
//the variable is found! id and size: 2 4
//var is inside offset:  -1 
	tt29 = sp - 1; 
	*tt29 = t9; 
L23:
//looking for: num 
//the variable is found! id and size: 2 4
//var is inside offset:  1 
	tt30 = sp + 4; 
	t10 = *tt30; 
//looking for: t10 
//the variable is found! id and size: 2 -2
//var is inside offset:  -10 
	tt31 = sp - 10; 
// save temp val: stack add: tt31 t10
	*tt31 = t10; 
//looking for: units 
//the variable is found! id and size: 2 4
//var is inside offset:  -3 
	tt32 = sp - 3; 
	t11 = *tt32; 
//looking for: t11 
//the variable is found! id and size: 2 -2
//var is inside offset:  -11 
	tt33 = sp - 11; 
// save temp val: stack add: tt33 t11
	*tt33 = t11; 
//looking for: t10 
//the variable is found! id and size: 2 -2
//var is inside offset:  -10 
	tt34 = sp - 10; 
// load temp val: stack add: tt34 t10
	t10 = *tt34; 
//looking for: t11 
//the variable is found! id and size: 2 -2
//var is inside offset:  -11 
	tt35 = sp - 11; 
// load temp val: stack add: tt35 t11
	t11 = *tt35; 
	t12 = t10 - t11; 
//looking for: t12 
//the variable is found! id and size: 2 -2
//var is inside offset:  -12 
	tt36 = sp - 12; 
// save temp val: stack add: tt36 t12
	*tt36 = t12; 
//looking for: t12 
//the variable is found! id and size: 2 -2
//var is inside offset:  -12 
	tt37 = sp - 12; 
// load temp val: stack add: tt37 t12
	t12 = *tt37; 
	t13 = t12 / 10; 
//looking for: t13 
//the variable is found! id and size: 2 -2
//var is inside offset:  -13 
	tt38 = sp - 13; 
// save temp val: stack add: tt38 t13
	*tt38 = t13; 
//looking for: num 
//the variable is found! id and size: 2 4
//var is inside offset:  1 
	tt39 = sp + 4; 
	*tt39 = t13; 
L24:
		goto L15; 
L25:
L26:
//saw return
  
//looking for: pal 
//the variable is found! id and size: 2 4
//var is inside offset:  -1 
	tt40 = sp - 1; 
	t14 = *tt40; 
//looking for: t14 
//the variable is found! id and size: 2 -2
//var is inside offset:  -14 
	tt41 = sp - 14; 
// save temp val: stack add: tt41 t14
	*tt41 = t14; 
	tt42 = sp + 1; 
	*tt42 = t14; 
//return  
	top = top + 14; 
	v1 = atop + 1; 
	tt43 = *v1; 
		goto *tt43; 
L27:
L28:
//return  
	top = top + 14; 
	v2 = atop + 1; 
	tt44 = *v2; 
		goto *tt44; 
L29:
//in topPlsLoclNum() 14 100
//in topPlsLoclNum() 14 332
//in topPlsLoclNum() 14 339
//in topPlsLoclNum() 14 339
//num getPalindrome getPalindrome
		goto L49; 
L30:
	sp = top; 
//func decleration:  getPalindrome
	top = top - 14; 
//param entered in:  getPalindrome num
L31:
L32:
L33:
//looking for: pal 
//the variable is found! id and size: 3 4
//var is inside offset:  -1 
	tt45 = sp - 1; 
	*tt45 = 0; 
L34:
L35:
//looking for: num 
//the variable is found! id and size: 3 4
//var is inside offset:  1 
	tt46 = sp + 4; 
	t15 = *tt46; 
//looking for: t15 
//the variable is found! id and size: 3 -2
//var is inside offset:  -2 
	tt47 = sp - 2; 
// save temp val: stack add: tt47 t15
	*tt47 = t15; 
//looking for: t15 
//the variable is found! id and size: 3 -2
//var is inside offset:  -2 
	tt48 = sp - 2; 
// load temp val: stack add: tt48 t15
	t15 = *tt48; 
if ( t15 >= 1 )
		goto L38; 
L36:
		goto L45; 
L37:
L38:
L39:
L40:
//looking for: num 
//the variable is found! id and size: 3 4
//var is inside offset:  1 
	tt49 = sp + 4; 
	t16 = *tt49; 
//looking for: t16 
//the variable is found! id and size: 3 -2
//var is inside offset:  -4 
	tt50 = sp - 4; 
// save temp val: stack add: tt50 t16
	*tt50 = t16; 
//function call: getUnit 
//arg: t16 
	top = top - 1; 
//looking for: t16 
//the variable is found! id and size: 3 -2
//var is inside offset:  -4 
	tt51 = sp - 4; 
// load temp val: stack add: tt51 t16
	t16 = *tt51; 
	*top = t16; 
//looking for: getUnit 
	top = top - 1; 
	*top = -10; 
	top = top - 1; 
	tt52 = &&L41; 
	atop = atop - 1; 
	*atop = tt52; 
	top = top - 1; 
	top = top - 1; 
	*top = -1; 
	atop = atop - 1; 
	*atop = sp; 
		goto L50; 
//return after func call  
L41:
	top = top + 1; 
	t17 = *top; 
	top = top + 2; 
	i2 = *top; 
	i2 = i2 + 1; 
	top = top + i2; 
	sp = *atop; 
	atop = atop + 2; 
//every thing is normal after func call: getUnit 
//looking for: t17 
//the variable is found! id and size: 3 -2
//var is inside offset:  -5 
	tt53 = sp - 5; 
// save temp val: stack add: tt53 t17
	*tt53 = t17; 
//looking for: units 
//the variable is found! id and size: 3 4
//var is inside offset:  -3 
	tt54 = sp - 3; 
	*tt54 = t17; 
L42:
//looking for: pal 
//the variable is found! id and size: 3 4
//var is inside offset:  -1 
	tt55 = sp - 1; 
	t18 = *tt55; 
//looking for: t18 
//the variable is found! id and size: 3 -2
//var is inside offset:  -6 
	tt56 = sp - 6; 
// save temp val: stack add: tt56 t18
	*tt56 = t18; 
//looking for: t18 
//the variable is found! id and size: 3 -2
//var is inside offset:  -6 
	tt57 = sp - 6; 
// load temp val: stack add: tt57 t18
	t18 = *tt57; 
	t19 = t18 * 10; 
//looking for: t19 
//the variable is found! id and size: 3 -2
//var is inside offset:  -7 
	tt58 = sp - 7; 
// save temp val: stack add: tt58 t19
	*tt58 = t19; 
//looking for: units 
//the variable is found! id and size: 3 4
//var is inside offset:  -3 
	tt59 = sp - 3; 
	t20 = *tt59; 
//looking for: t20 
//the variable is found! id and size: 3 -2
//var is inside offset:  -8 
	tt60 = sp - 8; 
// save temp val: stack add: tt60 t20
	*tt60 = t20; 
//looking for: t19 
//the variable is found! id and size: 3 -2
//var is inside offset:  -7 
	tt61 = sp - 7; 
// load temp val: stack add: tt61 t19
	t19 = *tt61; 
//looking for: t20 
//the variable is found! id and size: 3 -2
//var is inside offset:  -8 
	tt62 = sp - 8; 
// load temp val: stack add: tt62 t20
	t20 = *tt62; 
	t21 = t19 + t20; 
//looking for: t21 
//the variable is found! id and size: 3 -2
//var is inside offset:  -9 
	tt63 = sp - 9; 
// save temp val: stack add: tt63 t21
	*tt63 = t21; 
//looking for: pal 
//the variable is found! id and size: 3 4
//var is inside offset:  -1 
	tt64 = sp - 1; 
	*tt64 = t21; 
L43:
//looking for: num 
//the variable is found! id and size: 3 4
//var is inside offset:  1 
	tt65 = sp + 4; 
	t22 = *tt65; 
//looking for: t22 
//the variable is found! id and size: 3 -2
//var is inside offset:  -10 
	tt66 = sp - 10; 
// save temp val: stack add: tt66 t22
	*tt66 = t22; 
//looking for: units 
//the variable is found! id and size: 3 4
//var is inside offset:  -3 
	tt67 = sp - 3; 
	t23 = *tt67; 
//looking for: t23 
//the variable is found! id and size: 3 -2
//var is inside offset:  -11 
	tt68 = sp - 11; 
// save temp val: stack add: tt68 t23
	*tt68 = t23; 
//looking for: t22 
//the variable is found! id and size: 3 -2
//var is inside offset:  -10 
	tt69 = sp - 10; 
// load temp val: stack add: tt69 t22
	t22 = *tt69; 
//looking for: t23 
//the variable is found! id and size: 3 -2
//var is inside offset:  -11 
	tt70 = sp - 11; 
// load temp val: stack add: tt70 t23
	t23 = *tt70; 
	t24 = t22 - t23; 
//looking for: t24 
//the variable is found! id and size: 3 -2
//var is inside offset:  -12 
	tt71 = sp - 12; 
// save temp val: stack add: tt71 t24
	*tt71 = t24; 
//looking for: t24 
//the variable is found! id and size: 3 -2
//var is inside offset:  -12 
	tt72 = sp - 12; 
// load temp val: stack add: tt72 t24
	t24 = *tt72; 
	t25 = t24 / 10; 
//looking for: t25 
//the variable is found! id and size: 3 -2
//var is inside offset:  -13 
	tt73 = sp - 13; 
// save temp val: stack add: tt73 t25
	*tt73 = t25; 
//looking for: num 
//the variable is found! id and size: 3 4
//var is inside offset:  1 
	tt74 = sp + 4; 
	*tt74 = t25; 
L44:
		goto L35; 
L45:
L46:
//saw return
  
//looking for: pal 
//the variable is found! id and size: 3 4
//var is inside offset:  -1 
	tt75 = sp - 1; 
	t26 = *tt75; 
//looking for: t26 
//the variable is found! id and size: 3 -2
//var is inside offset:  -14 
	tt76 = sp - 14; 
// save temp val: stack add: tt76 t26
	*tt76 = t26; 
	tt77 = sp + 1; 
	*tt77 = t26; 
//return  
	top = top + 14; 
	v3 = atop + 1; 
	tt78 = *v3; 
		goto *tt78; 
L47:
L48:
//return  
	top = top + 14; 
	v4 = atop + 1; 
	tt79 = *v4; 
		goto *tt79; 
L49:
//in topPlsLoclNum() 14 353
//in topPlsLoclNum() 14 585
//in topPlsLoclNum() 14 592
//in topPlsLoclNum() 14 592
//num getPalindrome getPalindrome
		goto L73; 
L50:
	sp = top; 
//func decleration:  getUnit
	top = top - 16; 
//param entered in:  getUnit num
L51:
L52:
L53:
L54:
//looking for: q 
//the variable is found! id and size: 4 4
//var is inside offset:  -1 
	tt80 = sp - 1; 
	*tt80 = 0; 
L55:
//looking for: r 
//the variable is found! id and size: 4 4
//var is inside offset:  -2 
	tt81 = sp - 2; 
	*tt81 = 0; 
L56:
L57:
//looking for: q 
//the variable is found! id and size: 4 4
//var is inside offset:  -1 
	tt82 = sp - 1; 
	t27 = *tt82; 
//looking for: t27 
//the variable is found! id and size: 4 -2
//var is inside offset:  -3 
	tt83 = sp - 3; 
// save temp val: stack add: tt83 t27
	*tt83 = t27; 
//looking for: t27 
//the variable is found! id and size: 4 -2
//var is inside offset:  -3 
	tt84 = sp - 3; 
// load temp val: stack add: tt84 t27
	t27 = *tt84; 
	t28 = t27 * 10; 
//looking for: t28 
//the variable is found! id and size: 4 -2
//var is inside offset:  -4 
	tt85 = sp - 4; 
// save temp val: stack add: tt85 t28
	*tt85 = t28; 
//looking for: num 
//the variable is found! id and size: 4 4
//var is inside offset:  1 
	tt86 = sp + 4; 
	t29 = *tt86; 
//looking for: t29 
//the variable is found! id and size: 4 -2
//var is inside offset:  -5 
	tt87 = sp - 5; 
// save temp val: stack add: tt87 t29
	*tt87 = t29; 
//looking for: t28 
//the variable is found! id and size: 4 -2
//var is inside offset:  -4 
	tt88 = sp - 4; 
// load temp val: stack add: tt88 t28
	t28 = *tt88; 
//looking for: t29 
//the variable is found! id and size: 4 -2
//var is inside offset:  -5 
	tt89 = sp - 5; 
// load temp val: stack add: tt89 t29
	t29 = *tt89; 
if ( t28 < t29 )
		goto L60; 
L58:
		goto L61; 
L59:
L60:
//looking for: q 
//the variable is found! id and size: 4 4
//var is inside offset:  -1 
	tt90 = sp - 1; 
	t30 = *tt90; 
//looking for: t30 
//the variable is found! id and size: 4 -2
//var is inside offset:  -6 
	tt91 = sp - 6; 
// save temp val: stack add: tt91 t30
	*tt91 = t30; 
//looking for: t30 
//the variable is found! id and size: 4 -2
//var is inside offset:  -6 
	tt92 = sp - 6; 
// load temp val: stack add: tt92 t30
	t30 = *tt92; 
	t31 = t30 + 1; 
//looking for: t31 
//the variable is found! id and size: 4 -2
//var is inside offset:  -7 
	tt93 = sp - 7; 
// save temp val: stack add: tt93 t31
	*tt93 = t31; 
//looking for: q 
//the variable is found! id and size: 4 4
//var is inside offset:  -1 
	tt94 = sp - 1; 
	*tt94 = t31; 
		goto L57; 
L61:
L62:
//looking for: num 
//the variable is found! id and size: 4 4
//var is inside offset:  1 
	tt95 = sp + 4; 
	t32 = *tt95; 
//looking for: t32 
//the variable is found! id and size: 4 -2
//var is inside offset:  -8 
	tt96 = sp - 8; 
// save temp val: stack add: tt96 t32
	*tt96 = t32; 
//looking for: q 
//the variable is found! id and size: 4 4
//var is inside offset:  -1 
	tt97 = sp - 1; 
	t33 = *tt97; 
//looking for: t33 
//the variable is found! id and size: 4 -2
//var is inside offset:  -9 
	tt98 = sp - 9; 
// save temp val: stack add: tt98 t33
	*tt98 = t33; 
//looking for: t33 
//the variable is found! id and size: 4 -2
//var is inside offset:  -9 
	tt99 = sp - 9; 
// load temp val: stack add: tt99 t33
	t33 = *tt99; 
	t34 = t33 * 10; 
//looking for: t34 
//the variable is found! id and size: 4 -2
//var is inside offset:  -10 
	tt100 = sp - 10; 
// save temp val: stack add: tt100 t34
	*tt100 = t34; 
//looking for: t32 
//the variable is found! id and size: 4 -2
//var is inside offset:  -8 
	tt101 = sp - 8; 
// load temp val: stack add: tt101 t32
	t32 = *tt101; 
//looking for: t34 
//the variable is found! id and size: 4 -2
//var is inside offset:  -10 
	tt102 = sp - 10; 
// load temp val: stack add: tt102 t34
	t34 = *tt102; 
if ( t32 == t34 )
		goto L66; 
L63:
		goto L69; 
L64:
L65:
L66:
//saw return
  
	tt103 = sp + 1; 
	*tt103 = 0; 
//return  
	top = top + 16; 
	v5 = atop + 1; 
	tt104 = *v5; 
		goto *tt104; 
		goto L68; 
L67:
L68:
L69:
//looking for: q 
//the variable is found! id and size: 4 4
//var is inside offset:  -1 
	tt105 = sp - 1; 
	t35 = *tt105; 
//looking for: t35 
//the variable is found! id and size: 4 -2
//var is inside offset:  -11 
	tt106 = sp - 11; 
// save temp val: stack add: tt106 t35
	*tt106 = t35; 
//looking for: t35 
//the variable is found! id and size: 4 -2
//var is inside offset:  -11 
	tt107 = sp - 11; 
// load temp val: stack add: tt107 t35
	t35 = *tt107; 
	t36 = t35 - 1; 
//looking for: t36 
//the variable is found! id and size: 4 -2
//var is inside offset:  -12 
	tt108 = sp - 12; 
// save temp val: stack add: tt108 t36
	*tt108 = t36; 
//looking for: q 
//the variable is found! id and size: 4 4
//var is inside offset:  -1 
	tt109 = sp - 1; 
	*tt109 = t36; 
L70:
//saw return
  
//looking for: num 
//the variable is found! id and size: 4 4
//var is inside offset:  1 
	tt110 = sp + 4; 
	t37 = *tt110; 
//looking for: t37 
//the variable is found! id and size: 4 -2
//var is inside offset:  -13 
	tt111 = sp - 13; 
// save temp val: stack add: tt111 t37
	*tt111 = t37; 
//looking for: q 
//the variable is found! id and size: 4 4
//var is inside offset:  -1 
	tt112 = sp - 1; 
	t38 = *tt112; 
//looking for: t38 
//the variable is found! id and size: 4 -2
//var is inside offset:  -14 
	tt113 = sp - 14; 
// save temp val: stack add: tt113 t38
	*tt113 = t38; 
//looking for: t38 
//the variable is found! id and size: 4 -2
//var is inside offset:  -14 
	tt114 = sp - 14; 
// load temp val: stack add: tt114 t38
	t38 = *tt114; 
	t39 = t38 * 10; 
//looking for: t39 
//the variable is found! id and size: 4 -2
//var is inside offset:  -15 
	tt115 = sp - 15; 
// save temp val: stack add: tt115 t39
	*tt115 = t39; 
//looking for: t37 
//the variable is found! id and size: 4 -2
//var is inside offset:  -13 
	tt116 = sp - 13; 
// load temp val: stack add: tt116 t37
	t37 = *tt116; 
//looking for: t39 
//the variable is found! id and size: 4 -2
//var is inside offset:  -15 
	tt117 = sp - 15; 
// load temp val: stack add: tt117 t39
	t39 = *tt117; 
	t40 = t37 - t39; 
//looking for: t40 
//the variable is found! id and size: 4 -2
//var is inside offset:  -16 
	tt118 = sp - 16; 
// save temp val: stack add: tt118 t40
	*tt118 = t40; 
	tt119 = sp + 1; 
	*tt119 = t40; 
//return  
	top = top + 16; 
	v6 = atop + 1; 
	tt120 = *v6; 
		goto *tt120; 
L71:
L72:
//return  
	top = top + 1; 
	v7 = atop + 1; 
	tt121 = *v7; 
		goto *tt121; 
L73:
//in topPlsLoclNum() 16 606
//in topPlsLoclNum() 16 768
//in topPlsLoclNum() 16 864
//in topPlsLoclNum() 16 871
//in topPlsLoclNum() 16 871
//num getUnit getUnit
L74:
//function call: _main 
//looking for: _main 
//the variable is found! id and size: 0 -1
	top = top - 1; 
	*top = 0; 
	top = top - 1; 
	tt122 = &&L75; 
	atop = atop - 1; 
	*atop = tt122; 
	top = top - 1; 
	top = top - 1; 
	*top = 1; 
	atop = atop - 1; 
	*atop = sp; 
		goto L0; 
//return after func call  
L75:
	top = top + 1; 
	t41 = *top; 
	top = top + 2; 
	i3 = *top; 
	i3 = i3 + 1; 
	top = top + i3; 
	sp = *atop; 
	atop = atop + 2; 
//every thing is normal after func call: _main 
//looking for: t41 
//the variable is found! id and size: 0 -2
//var is inside offset:  -1 
	tt123 = sp - 1; 
// save temp val: stack add: tt123 t41
	*tt123 = t41; 
//in topPlsLoclNum() 1 0
//in topPlsLoclNum() 1 871
return 0;
}
