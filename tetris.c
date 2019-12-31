#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include <math.h>

int game_over(char**board,int x,int y);
int score(int c_line,int c_round,int points);

 int main (){ 
 	srand((int)time(NULL)); //arxikopoioume ti rand me tin srand 
	int Y,X,i,j;
	char **board=NULL;
	int maxY=26;
	int minY=20;
	int maxX=13;
	int minX=10;
	char name[50];
	char type;
/*pinakes pou periexoun ta kommatia pou emfanizontai se kathe guro alla kai oi dunates peristrofes tous 
  epileksame na einai 4x4 wste na xwroun olous tous dunatous sundiasmous sumbolwn kai twn peristrfwn autwn*/
	char straight[4][4];	
	char p_straight[4][4];
	char tetragono[4][4];
	char g_left[4][4]; 
	char c_left[4][4];
	char c2_left[4][4];
	char a_left[4][4];
	char g_right[4][4];
	char c_right[4][4];
	char c2_right[4][4];
	char a_right[4][4];
	char tau[4][4];
	char c_tau[4][4];
	char c2_tau[4][4];
	char a_tau[4][4];
	char s[4][4];
	char p_s[4][4];
	char anap_s[4][4];
	char p_anap_s[4][4];
	int pin[4][4];
	double d;
	char ch,symbol;
	int counterC=0;
	int counterA=0;
	int counterL=0;
	int counterR =0; 
	int wrong=0;
	int m,kommatia,tux_kom,w,mer_kom,sym;
	int k,r,l,counter,p,ra;
	int round,lines;
	int noline,line,counterline,c_line;
	int c_round=-1;
	int points;
	points=lines=0;
	round=1;
	int a;

	 for(i=0;i<4;i++){				//to sumbolo @ @ @ @
   		 for(j=0;j<4;j++){
			if(i==0)
	  			straight[i][j]='@';
			 else 
      			 	straight[i][j]='.'; 
	 	}
	}
	for(i=0;i<4;i++){
   		 for(j=0;j<4;j++){			//	@
			if(j==2)			//	@
	  			p_straight[i][j]='@';   //	@
			 else 				//	@
      				p_straight[i][j]='.'; 
	 	}
	}
	
	
	
	for(i=0;i<4;i++){
      		for(j=0;j<4;j++){
			if (((i==0)&&((j==1) ||(j==2))) ||((i==1)&&((j==1)||(j==2))))	//	w w
	    			 tetragono[i][j]='w';					//	w w
	 		 else
	    			 tetragono[i][j]='.';
	  	}
   	}
   
    	for(i=0;i<4;i++){
   		 for(j=0;j<4;j++){						//	    x
	 		 if (((i==0) && (j==3)) || ((i==1) &&(j!=0)))		//	x x x
	    			g_right[i][j]='x';
	 		 else
	   			 g_right[i][j]='.';
		}
  	}
  	for(i=0;i<4;i++){
   		 for(j=0;j<4;j++){
	  		if (((i!=3) &&(j==1)) ||((i==2)&&(j==2)))		//	x
	    			c_right[i][j]='x';				//	x
	  		else							//	x x
	   			c_right[i][j]='.';
		}
  	}
  
   	for(i=0;i<4;i++){
    		for(j=0;j<4;j++){						//	x x x
	  		if (((i==0) &&(j!=0)) ||((i==1)&&(j==1)))		//	x
	 			c2_right[i][j]='x';
	  		else
	   			c2_right[i][j]='.';
		}
  	}
   	for(i=0;i<4;i++){
   		 for(j=0;j<4;j++){						//	x x
	  		if (((i!=3) &&(j==2)) ||((i==0)&&(j==1)))		//	  x
	 			a_right[i][j]='x';				//	  x
	 		else
	   			a_right[i][j]='.';
		}
  	}
 	for(i=0;i<4;i++){
   		for(j=0;j<4;j++){						//	o
    			if (((i==0) && (j==1)) || ((i==1) &&(j!=0)))		//	o o o
	   			g_left[i][j]='o';
			else
	   			g_left[i][j]='.';
    		}
	}
	for(i=0;i<4;i++){
    		for(j=0;j<4;j++){
	  		if (((i!=3) &&(j==1)) ||((i==0)&&(j==2)))		//	o o
	    			c_left[i][j]='o';				//	o
	  		else							//	o
	   			c_left[i][j]='.';
		}
  	}
 	for(i=0;i<4;i++){
    		for(j=0;j<4;j++){
	  		if (((i==0) &&(j!=0)) ||((i==1)&&(j==3)))		//	o o o
	    			c2_left[i][j]='o';				//	    o
	  		else
	  	 		c2_left[i][j]='.';
		}
  	} 
  	for(i=0;i<4;i++){
    		for(j=0;j<4;j++){						//	   o
	  		if (((i!=3) && (j==2)) ||((i==2)&&(j==1)))		//	   o
	    			a_left[i][j]='o';				//	 o o
	  		else
	   			a_left[i][j]='.';
		}
  	} 
 	for(i=0;i<4;i++){
    		for(j=0;j<4;j++){						//	  #
	  		if (((i==1) && (j!=0)) ||((i==0)&&(j==2)))		//	# # #
	    			tau[i][j]='#';
	  		else
	   			tau[i][j]='.';
		}
  	}

  	for(i=0;i<4;i++){
    		for(j=0;j<4;j++){						//        #
	  		if (((i!=3) && (j==2)) ||((i==1)&&(j==3)))		//	  # #
				c_tau[i][j]='#';				//	  #
	  		else
	   			c_tau[i][j]='.';
		}
  	} 
 	for(i=0;i<4;i++){
    		for(j=0;j<4;j++){						//	# # #
	  		if (((i==0) && (j!=0)) ||((i==1)&&(j==2)))		//	  #
	    			c2_tau[i][j]='#';
	  		else
	   			c2_tau[i][j]='.';
		}
  	}
   	for(i=0;i<4;i++){
    		for(j=0;j<4;j++){						//	  #
	  		if (((i!=3) && (j==2)) ||((i==1)&&(j==1)))		//	# #
	    			a_tau[i][j]='#';				//	  #
	  		else
	   			a_tau[i][j]='.';
		}
  	}
	for(i=0;i<4;i++){
   		for(j=0;j<4;j++){								//	  & &
    			if (((i==0) &&((j==2)||(j==3)))||((i==1) &&((j==1)||(j==2))))		//	& &
	       			s[i][j]='&';   
			else
	  			s[i][j]='.';	   
		}
	}
	for(i=0;i<4;i++){
   		for(j=0;j<4;j++){									//	& 
    			if (((i==0) &&(j==1) )||((i==1) &&((j==1)||(j==2)))||((i==2)&&(j==2)) )		//	& &
	       			p_s[i][j]='&';								//	  &
			else
	  			p_s[i][j]='.';
		   
		}
	}
	for(i=0;i<4;i++){
   		for(j=0;j<4;j++){								//	$ $
    			if (((i==0) &&((j==1)||(j==2))) ||((i==1)&&((j==2) ||(j==3))))		//	  $ $
	       			anap_s[i][j]='$';   
			else
	 			anap_s[i][j]='.';
		}   
	}
	for(i=0;i<4;i++){
   		for(j=0;j<4;j++){
    			if (((i==0) &&(j==2))||((i==1) &&((j==1)||(j==2))) ||((i==2)&&(j==1)))	//	  $
	       			p_anap_s[i][j]='$';						//	$ $
			else									//	$
	  			p_anap_s[i][j]='.';
		 }
	}
   
 
	printf("Give me the dimensions of board!!! \n");
	do{	
		printf("Give me the width between 10-13. \n"); 
		scanf("%d",&X);
		if((X<minX) || (X>maxX))			//elegxei an einai egkurh h timh tou platous tou pinaka
			printf("Invalid input!!");
	}while ((X<minX) || (X>maxX));
	do{
		printf("Give me the height between 20-26. \n"); 
		printf("The height must be at least 2*width!!!\n");
		scanf("%d",&Y);
		while(getchar()!='\n');				//katharizei to buffer eisodou apo to enter
		if((Y<minY) || (Y>maxY) || (Y<2*X)) 		//elegxei an einai egkurh h timh tou upsous tou pinaka
			printf("Type a value input!");
	}while ((Y<minY) || (Y>maxY) || (Y<2*X));
	printf("Give me the name \n");
	scanf("%s",name);
	while(getchar()!='\n');					
	
	do{
		printf("Give me the type of game easy/hard \n");
		scanf("%c",&type);				//zhtaei to tupo tou paixnidiou mexri o xrhsths na dwsei mia egkurh timh
		while(getchar()!='\n');
	}while ((type!='e') &&(type!='h'));
	//dunamikh desmeush tou tamplo
	if ((board = (char**) malloc(Y * sizeof(char*))) == NULL){	//desmeush tou upsous tou tamplo
		printf("No memory available, allocation failed!\n");
		exit(0);
		
	}
	for (i=0; i<Y; i++){ 
		
		if ((board[i] = (char *) malloc(X *sizeof(char))) == NULL){	//desmeush tou platous tou tamplo
			printf("No memory available, allocation failed!\n");
			exit(0);
		}
	}
  	for (i=0;i<Y;i++){		
		for(j=0;j<X;j++){
			board[i][j]='.';		//gemizoume to tamplo me teleies
		}
	}
	system("clear");				//katharizoume thn othonh apo ta prohgoumena
	do{		
		if ((type=='h') && (((round-1)%5)==0)){	//an exei epileksei to hard paixnidi,kathe 5 gurous prosthetontai tuxaia kommatia
			d=(double)rand()/((double)RAND_MAX+1);//sunolika posa tyxaia kommatia tha pesoun se auton to guro
			kommatia=(int)(d*4+2);	//prosthetontai apo 2-5 kommatia
		
			for (w=0;w<kommatia;w++){	//trexei oses fores einai ta tuxaia kommatia
			
				d=(double)rand()/((double)RAND_MAX+1); //epilegei anamesa sto 0 kai 1
				tux_kom=(int)(d*2);			
				if(tux_kom==0){			//an einai 0 to tuxaio kommati einai oloklhro
			
					d=(double)rand()/((double)RAND_MAX+1);
					d=(d*7+1);              //epilegei apo ta 7 arxika kommatia
					r=(int)d;
					switch (r){
						case 1:
							for(i=0;i<4;i++){		//eisagei ston pinaka pin to sumbolo @ @ @ @ apo ton
								for(j=0;j<4;j++){	//pinaka straight
									pin[i][j]=straight[i][j];		}
							}
						break;
						case 2:
							for(i=0;i<4;i++){
								for(j=0;j<4;j++){
									pin[i][j]=tetragono[i][j];		}
							}
						break;
						case 3:
							for(i=0;i<4;i++){
								for(j=0;j<4;j++){
									pin[i][j]=g_left[i][j];		}
							}
						break;
						case 4:
							for(i=0;i<4;i++){
								for(j=0;j<4;j++){
								pin[i][j]=g_right[i][j];		}
							}
						break;
						case 5:
							for(i=0;i<4;i++){
								for(j=0;j<4;j++){
									pin[i][j]=tau[i][j];		}
							}
						break;
						case 6:
                					for(i=0;i<4;i++){
								for(j=0;j<4;j++){
									pin[i][j]=s[i][j];		}
							}
						break;
						case 7:
        			        		for(i=0;i<4;i++){
								for(j=0;j<4;j++){
									pin[i][j]=anap_s[i][j];		}
							}
						break;
				
					}
				}
				else{	//an bgei to 1 apo thn random tote to tuxaio kommati den einai oloklhro
					d=(double)rand()/((double)RAND_MAX+1);
					d=(int)(d*7+1);//epilegei ena apo ta 7 sumbola pou tha exei to tuxaio kommati
					sym=(int)d;
					switch(sym){
						case 1:
							symbol='@';
						break;
						case 2:
							symbol='w';
						break;
						case 3:
							symbol='o';
						break;
						case 4:
							symbol='x';
						break;
						case 5:
							symbol='#';
						break;
						case 6:
							symbol='&';
						break;
						case 7:
							symbol='$';
						break;
					}
					if(symbol=='@'){
					d=(double)rand()/((double)RAND_MAX+1);
					d=(d*5+1);
					mer_kom=(int)d;
						switch (mer_kom){	//ta pithana merh tou kommatiou @ @ @ @
						case 1:
							for(i=0;i<4;i++){		// @
								for(j=0;j<4;j++)
									pin[i][j]='.';

							}
							pin[0][0]=symbol;
						break;
						case 2:
							for(i=0;i<4;i++){
								for(j=0;j<4;j++) 	// @ @
								pin[i][j]='.';

							}
							pin[0][2]=symbol;
							pin[0][3]=symbol;
						break;
						
						case 3:
							for(i=0;i<4;i++){		// @
								for(j=0;j<4;j++)	// @
									pin[i][j]='.';

							}
							pin[0][1]=pin[1][1]=symbol;
						break;
						case 4:
							for(i=0;i<4;i++){		// @ @ @
								for(j=0;j<4;j++)
									pin[i][j]='.';

							}
							pin[0][1]=pin[0][2]=pin[0][3]=symbol;
						break;
						case 5:
							for(i=0;i<4;i++){		// @
								for(j=0;j<4;j++)	// @
									pin[i][j]='.';	// @

							}
							pin[0][1]=pin[1][1]=pin[2][1]=symbol;
						break;

					}
				}else if((symbol=='w')||(symbol=='&')||(symbol=='$')){
				
					d=(double)rand()/((double)RAND_MAX+1);
					d=(d*7+1);
					mer_kom=(int)d;
						switch (mer_kom){	//ta pithana merh autwn twn sumbolwn einai ta parakatw
						case 1:
							for(i=0;i<4;i++){
								for(j=0;j<4;j++)     	// W 
									pin[i][j]='.';

							}
							pin[0][0]=symbol;
						break;
						case 2:
							for(i=0;i<4;i++){		// $ $
								for(j=0;j<4;j++)
								pin[i][j]='.';

							}
							pin[0][2]=symbol;
							pin[0][3]=symbol;
						break;
						case 3:
							for(i=0;i<4;i++){
								for(j=0;j<4;j++)	// & &
									pin[i][j]='.';	//   &

							}
							pin[0][1]=pin[0][2]=pin[1][2]=symbol;
						break;
						case 4:
							for(i=0;i<4;i++){		// w
								for(j=0;j<4;j++)	// w w
									pin[i][j]='.';

							}
							pin[0][0]=pin[1][0]=pin[1][1]=symbol;
						break;
						case 5:
							for(i=0;i<4;i++){		// $ $
								for(j=0;j<4;j++)	// $
									pin[i][j]='.';

							}
							pin[0][2]=pin[0][3]=pin[1][2]=symbol;
						break;
						case 6:
							for(i=0;i<4;i++){
								for(j=0;j<4;j++) 	// &
									pin[i][j]='.';	// &

							}
							pin[0][1]=pin[1][1]=symbol;
						break;
						case 7:
							for(i=0;i<4;i++){		//	  w
								for(j=0;j<4;j++)	//	w w
									pin[i][j]='.';

							}
							pin[0][3]=pin[1][2]=pin[1][3]=symbol;
						break;
						

					}
				}
				else{
					d=(double)rand()/((double)RAND_MAX+1);
					d=(d*9+1);
					mer_kom=(int)d;
						switch (mer_kom){	//aytes einai oi epiloges gia ta upoloipa kommatia
						case 1:
							for(i=0;i<4;i++){
								for(j=0;j<4;j++)
									pin[i][j]='.';

							}
							pin[0][0]=symbol;
						break;
						case 2:
							for(i=0;i<4;i++){
								for(j=0;j<4;j++)
								pin[i][j]='.';

							}
							pin[0][2]=symbol;
							pin[0][3]=symbol;
						break;
						case 3:
							for(i=0;i<4;i++){
								for(j=0;j<4;j++)
									pin[i][j]='.';

							}
							pin[0][1]=pin[0][2]=pin[1][2]=symbol;
						break;
						
						case 4:
							for(i=0;i<4;i++){
								for(j=0;j<4;j++)
									pin[i][j]='.';

							}
							pin[0][0]=pin[1][0]=pin[1][1]=symbol;
						break;
						case 5:
							for(i=0;i<4;i++){
								for(j=0;j<4;j++)
									pin[i][j]='.';

							}
							pin[0][2]=pin[0][3]=pin[1][2]=symbol;
						break;
						case 6:
							for(i=0;i<4;i++){
								for(j=0;j<4;j++)
									pin[i][j]='.';

							}
							pin[0][1]=pin[0][2]=pin[0][3]=symbol;
						break;
						case 7:
							for(i=0;i<4;i++){
								for(j=0;j<4;j++)
									pin[i][j]='.';

							}
							pin[0][1]=pin[1][1]=pin[2][1]=symbol;
						break;
						case 8:
							for(i=0;i<4;i++){
								for(j=0;j<4;j++)
									pin[i][j]='.';

							}
							pin[0][1]=pin[0][2]=pin[0][3]=symbol;
						
						break;
						case 9:
							for(i=0;i<4;i++){
								for(j=0;j<4;j++)
									pin[i][j]='.';

							}
							pin[0][1]=pin[1][1]=pin[2][1]=symbol;
						break;

					}
				
				
				
				
				}
				
				
				
		}
		
				a=X/2-2;	/*h metablhth a upologizei kata poses theseis aristera h deksia mporei na
                                                  metakinhthei o pinakas 4x4 pou periexei to tuxaio kommati wste na 
						   mh bgei ektos twn oriwn tou tamplo*/
				k=X/2-1;	//to k briskei to mesaio stoixeio tou tamplo
				d=(double)rand()/((double)RAND_MAX+1);
				ra=(int)(d*2*a+1-a);	//h random epilegei kata poses theseis tha metakinhthei o 4x4 pinakas metaksu twn 
							//dunatwn pou prokuptoun apo to a
				k+=ra;			//prosthetoume tis theseis metakinhshs sto mesaio stoixeio tou tamplo

				counter=0;
         			for(i=0;i<4;i++){	//diatrexoume to pinaka pin kai o counter metra se poses seires ekteinontai ta sumbola
	     				for(j=0;j<4;j++){	//tou tuxaiou kommatiou
						if(pin[i][j]!='.'){
							counter++;			
							break;
						}
					}
				}
        		for (i=1;i<Y-counter+1;i++)	//h for trexei apo th 2h seira tou tamplo mexri kai thn teleutaih dunath seira gia thn 
					for (j=0;j<counter;j++)	//opoia to tuxaio kommati tou pinaka pin xwraei sto tamplo 
						for (p=0;p<4;p++)
							if (pin[j][p]!='.')  //gia opou uparxei sumbolo ston pinaka pin elegxei sthn antistoixh
								if(board[i+j][k-1+p]!='.'){  //thesh sto tamplo an uparxei sumbolo
									i--;	//an uparxei,tote to tuxaio kommati tha prepei na metakinhthei
									goto ENDLOOP_2; //kata mia seira pros ta panw sto tamplo ,wste na mhn
								}	//peftei panw se alla sumbola tou tamplo

			i--;/*se periptwsh pou diatreksei olo to tamplo,dhladh to tamplo einai adeio apo alla sumbola,tote meiwnetai to i 
			etsi wste to tuxaio kommati na perastei sto telos tou tamplo kai na mhn bgei ektos oriwn (katw apo to tamplo) */

		ENDLOOP_2:
			for(j=0;j<counter;j++)
				for (p=0;p<4;p++)	
					if(pin[j][p]!='.')	//gia opou uparxei sumbolo ston pinaka pin
						board[i+j][k-1+p]=pin[j][p];//eisagetai sthn antistoixh thesh sto tamplo
			}
			
		}
            /*an o xrhsths epileksei to easy game paraleipontai ola ta parapanw */
               
  		d=(double)rand()/((double)RAND_MAX+1);
		d=(d*7+1);	//ayth h random epilegei to kommati pou tha emfanizetai epanw kai sto kentro tou tamplo se kathe guro
		r=(int)d;	//uparxoun 7 dunata kommatia
	
		do{	
			wrong=0;
			switch (r){
				case 1:
					for(i=0;i<4;i++){
						for(j=0;j<4;j++)	//eisagwgh kommatiou ston pinaka pin
				 			pin[i][j]=straight[i][j];	
					}
				break;
				case 2:
					for(i=0;i<4;i++){
						for(j=0;j<4;j++)
				 			pin[i][j]=tetragono[i][j];		
					}
				break;
				case 3:
					for(i=0;i<4;i++){
						for(j=0;j<4;j++)
				 			pin[i][j]=g_left[i][j];		
					}
				break;
				case 4:
					for(i=0;i<4;i++){
						for(j=0;j<4;j++)
				 			pin[i][j]=g_right[i][j];		
					}
				break;
				case 5:
					for(i=0;i<4;i++){
						for(j=0;j<4;j++)
				 			pin[i][j]=tau[i][j];		
					}
				break;
				case 6:
                       			 for(i=0;i<4;i++){
						for(j=0;j<4;j++)
							 pin[i][j]=s[i][j];		
					}
				break;
				case 7:
                        		for(i=0;i<4;i++){
						for(j=0;j<4;j++)
				 			pin[i][j]=anap_s[i][j];		
					}
				break;
			}
			k=X/2-1; //epanaprosdiorizoume to k wste na einai to mesaio stoixeio tou tamplo
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(pin[i][j]!='.')//eisagwgh tou kommatiou epanw kai sto kentro tou tamplo
						board[i][k-1+j]=pin[i][j];
					
				}
			}
		
			printf("Player %s, Round %d\n%d points, %d lines\n",name,round,points,lines);	/*se kathe guro emfanizetai
			to onoma tou paikth ,o guros ,oi pontoi kai oi grammes pou exoun sbhstei*/
			for(i=0;i<Y;i++){
				for(j=0;j<X;j++)	// ektupwnetai to tamplo(me to kommati epanw kai sto kentro)
					printf("%c ",board[i][j]);
				printf("\n");
			}
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){	
					if(pin[i][j]!='.')  	// sth sunexeia sbhnoume to kommati apo to tamplo
						board[i][k-1+j]='.';
				}
			}
			do{	
				printf("Enter your moves\n");	//dexetai tis kinhseis tou xrhsth
				while((ch=getchar())!='\n'){
					if ((ch=='c') || (ch=='C'))	//kai auksanei tous antistoixous counters
						counterC ++;
					else if ((ch=='a') || (ch=='A'))
						counterA ++;
					else if ((ch=='l') || (ch=='L'))
             					counterL ++;
					else if ((ch=='r') ||(ch =='R'))
						counterR ++;
					else if ((ch=='x') || (ch=='X')){	//an o xrhsths eisagei to x eleutheronetai h mnhmh pou 
						for (i=0; i<Y; i++)		//desmeusame gia to tamplo kai termatizei to programma
							free(board[i]);	
						free (board);
						exit(0);
			             	}
					else {
				 		ch='t';
						counterC=counterA=counterL=counterR=0;
						while(getchar()!='\n');
							printf("Type a valid input\n");
						break;
					}
				}
				
			}while(ch=='t');	//to loop epanalambanetai mexri o xrhsths na dwsei egkures times	
			system("clear");
			m=0;
			m=counterC-counterA;	//h peristrofh pros ta deksia auksanei to m ,enw pros ta aristera to meiwnei 
			counterC=counterA=0;
                	switch (r){
				case 1:
					m=m%2;	//gia to kommati @ @ @ @ ,oi dunates katastaseis einai 2 (h arxikh kai mia peristrofh)
					if(abs(m)==1 ){		//an m==1 tote ston pinaka pin eisagoume thn peristrofh tou kommatiou
						for(i=0;i<4;i++){	//alliws den allazei o pinakas pin
							for(j=0;j<4;j++)
						 		pin[i][j]=p_straight[i][j];
						}
					}
				break;
				case 2:
					//to kommati w w den exei peristrofes kai to pin den allazei
					//	     w w
				break;
				case 3:
					m=m%4;		//to kommati o     exei 4 dunates katastaseis
							//	     o o o
					if((m==1) || (m==-3)){ //mia peristrofh pros ta deksia tautizetai me treis peristrofes pros ta aristera
						for(i=0;i<4;i++){
							for(j=0;j<4;j++)
						 		pin[i][j]=c_left[i][j];
						}	
                                	}
					else if (abs(m)==2){ //duo peristrofes pros ta deksia tautizontai me duo peristrofes pros ta aristera
						for(i=0;i<4;i++){
							for(j=0;j<4;j++)
						 		pin[i][j]=c2_left[i][j];
						}
 					}
					else if((m==3)||(m==-1)){	//treis peristrofes pros ta deksia tautizontai me mia pros ta aristera
						for(i=0;i<4;i++){
							for(j=0;j<4;j++)
						 		pin[i][j]=a_left[i][j];
						}
					}
				break;	
				case 4:					//omoiws
					m=m%4;
					if((m==1) || (m==-3)){	
						for(i=0;i<4;i++){
							for(j=0;j<4;j++)
						 		pin[i][j]=c_right[i][j];
						}	
                                	}
					else if (abs(m)==2){
						for(i=0;i<4;i++){
							for(j=0;j<4;j++)
						 		pin[i][j]=c2_right[i][j];
						}
 					}
					else if((m==3)||(m==-1)){
						for(i=0;i<4;i++){
							for(j=0;j<4;j++)
						 		pin[i][j]=a_right[i][j];
						}
					}
				break;
				case 5:
					m=m%4;
					if((m==1) || (m==-3)){
						for(i=0;i<4;i++){
							for(j=0;j<4;j++)
						 		pin[i][j]=c_tau[i][j];
						}	
                                	}
					else if (abs(m)==2){
						for(i=0;i<4;i++){
							for(j=0;j<4;j++)
						 		pin[i][j]=c2_tau[i][j];
						}
 					}
					else if((m==3)||(m==-1)){
						for(i=0;i<4;i++){
							for(j=0;j<4;j++)
						 		pin[i][j]=a_tau[i][j];
						}
					}
				break;
				case 6:
					m=m%2;
					if(abs(m)==1 ){
						for(i=0;i<4;i++){
							for(j=0;j<4;j++)
						 		pin[i][j]=p_s[i][j];
						}
					}
				break;
				case 7:
					m=m%2;
					if(abs(m)==1 ){
						for(i=0;i<4;i++){
							for(j=0;j<4;j++)
						 		pin[i][j]=p_anap_s[i][j];
						}
					}
				break;
			}
			k=k+counterR-counterL;//o counterR metatopizei to k pros ta deksia (to auksanei) kai o counterL pros ta aristera      								//(to meiwnei)
			counterR=counterL=0;	
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(pin[i][j]!='.')	//opou o pin exei sumbolo elegxoume an sumfwna me tis kinhseis pou dwsame
						if(((k-1+j)<0)||((k-1+j)>X)){	// xwraei mesa sto tamplo
							printf("Out of limits choice!Give another choice!\n");
							wrong=1;	
							goto ENDLOOP;
						}
						else if (board[i][k-1+j]!='.'){	//elegxoume an to periestrameno kai metatopismeno an "xtupaei"
							printf("Wrong choice !!!Give another choice!\n"); //se alla sumbola sto tamplo 
							wrong=1;
							goto ENDLOOP;
						}
				}
			}
          		for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(pin[i][j]!='.')	//to eisagoume sto tamplo
						board[i][k-1+j]=pin[i][j];
					
				}
			}   
			printf("Player %s, Round %d\n%d points, %d lines\n",name,round,points,lines);  
	        	for(i=0;i<Y;i++){
				for(j=0;j<X;j++)	//ektupwnoume to tamplo (me to periestrameno kai metatopismeno kommati)
					printf("%c ",board[i][j]);
				printf("\n");
			}
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){	//sbhnoume to kommati apo to tamplo
					if(pin[i][j]!='.')
						board[i][k-1+j]='.';
				}
			}
			do{	
				printf("Drop piece? (Y/N)\n");	//o xrhsths epilegei an tha pesei to kommati opws einai h oxi
				ch=getchar();		
				while(getchar()!='\n');
			}while((ch!='n')&&(ch!='N')&&(ch!='y')&&(ch!='Y'));	//ekteleitai mexri na dwsei egkurh epilogh
			if((ch=='N')||(ch=='n'))	//an epileksei oxi tote eisagetai h timh wrong=1 wste na ektelestei pali to loop
			wrong=1;		//epilegontas  kainouries kinhseis
			system("clear");
			ENDLOOP :
		
	 		printf("\n");
		}while(wrong==1);	
	
	/*ta parakatw einai idia me ton kwdika tou hard game pou anaferetai sta tuxaia kommatia */
		/*topothetei to kommati sto tamplo san na epese*/
		counter=0; 
         	for(i=0;i<4;i++){
	     		for(j=0;j<4;j++){
				if(pin[i][j]!='.'){
				counter++;			
				break;
				}
			}
		}
        	
		
		for (i=1;i<Y-counter+1;i++)
					for (j=0;j<counter;j++)
						for (p=0;p<4;p++)
							if (pin[j][p]!='.')
								if(board[i+j][k-1+p]!='.'){
									i--;
									goto ENDLOOP_3;
								}
			i--;

		ENDLOOP_3:
			for(j=0;j<counter;j++)
				for (p=0;p<4;p++)
					if(pin[j][p]!='.')
						board[i+j][k-1+p]=pin[j][p];
	
		c_line=-1; 	//metrhths synexomenwn grammwn pou sbhnontai
		for(i=0;i<Y;i++){
			counterline=0;	//metraei posa sumbola exei kathe grammh tou tamplo
			for(j=0;j<X;j++){
				if (board[i][j]!='.')
					counterline++;
			}
			if(counterline==X){	//an exei sumplhrwthei mia grammh me sumbola 
				c_line++;	//auksanetai o metrhths synexomenwn grammwn
				lines++;	//kai o metrhths synolikwn sbhsmenwn  grammwn
				for(line=i;line>0;line--)	//apo thn trexousa sumplhrwmenh grammh kai pros ta panw
					for(j=0;j<X;j++)	
						board[line][j]=board[line-1][j];   //kathe grammh antigrafh thn apo panw ths 
				for(j=0;j<X;j++)
					board[0][j]='.';	//kai sthn prwth grammh eisagontai teleies
			}
			
			
		}
		
		if (c_line>-1){		//an exei sumplhrwthei estw kai mia grammh se auton to guro
			c_round++;	//auksanetai o metrhths synexomenwn gurwn (kata tous opoious sbhnontai grammes)
			points=score(c_line,c_round,points); //kai kaleitai h sunarthsh pou auksanei tous pontous
		}
		else 		//an den sumplhrwthei kapoia grammh se auton to guro tote
			c_round=-1;	//epanarxikopoieitai o metrhths sunexomenwn gurwn

		round++;	//auksanetai o guros tou game
	}while(game_over(board,X,Y)==0);	//to paixnidi sunexizetai gia oso h sunarthsh game_over epistrefei 0
	printf("GAME OVER\n");
                  
  	return 0;
  
}

int game_over(char**board,int x,int y){	//dexetai ws parametrous ton deikth pros to tamplo kai tis diastaseis tou tamplo
	int j;
	for (j=0;j<x;j++){
		if(board[1][j]!='.'){	//an uparxei sumbolo stis duo prwtes seires tou tamplo (dhladh an ta kommatia exoun sthvaxtei mexri
					//thn korufh tou tamplo tote					)
			for(j=0;j<y;j++)
				free(board[j]);	//eleytherwnetai h mnhmh pou exei desmeytei gia to tamplo kai epistrefei 1
			free (board);
			return 1;
		}
	}
	return 0;
}

int score(int c_line,int c_round,int points){	//dexetai ws parametrous to metrhth sunexomenwn sbhsmenwn grammwn ,to metrhth sunexomenwn 
						//gurwn kai tous sunolikous pontous tou paixnidiou
	points+=(( c_line*c_line + 1) + c_round*c_round)*10;	//upologizei mh grammika tous pontous
	return points;
}








