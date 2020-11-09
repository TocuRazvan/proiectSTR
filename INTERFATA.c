#include <cvirte.h>		
#include <userint.h>
#include "INTERFATA.h"

#include <math.h>	
#include <userint.h>
#include "toolbox.h"
static int panelHandle;  

//VARIABILE GROLABLE
//PERIOADA DE ESANTIONARE
double te;
//Parametrii semnalului Atr-amplitudine semnal treapta
double Atr;
int SELECTIE_SEMNAL;
//semnal treapta
double semnal_treapta,semnal_treapta_1;
//Tk sunt valoarea semnalului la momentul atual, Tk_1  momentul precendet
double tk,tk_1;
//semnal rampa a – este panta semnalului rampa, b – este pozitionarea pe ordonata a semnalului(mai sus mai jos)

double a,b,semnal_rampa,semnal_rampa_1;
//semnal sinusoidal
double T,semnal_sinusoidal,semnal_sinusoidal_1,semnal_sinusoidal2,semnal_sinusoidal2_1;
double pi;
//constatnele C
double T1,T2,T3,C1,C2,C3,IeT1,InT1,IeT1_1,IeT2,InT2,IeT2_1,IeT3,IeT3_1,InT3;
#include "FUNCTII_UTILE.h" 
//FUNCTIA MAIN
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "INTERFATA.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}



//FUNCTIA START APLICATIE
int CVICALLBACK START_APLICATIE (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
//PERIOADA DE ESANTIONARE
			te=0.100;
			tk_1=0;
//VALOARE PI
				pi=Pi();
//calculare C-uri
			 T1=21;
			 T2=31;
			 T3=29;
			 C1=te/(te+T1);
			 C2=T1/(te+T2); 
			 C3=te/(te+T3);
//initializare SEMNAL rampa
			semnal_rampa_1=0;
//initalizare semnal sinusoidal
			semnal_sinusoidal_1=0;
			//initializare semnal treapta
			semnal_treapta_1=0;
			
//SETARE INVERVAL TIMP SI DE PORNIRE//
			SetCtrlAttribute (panelHandle,PANEL_TIMER, ATTR_INTERVAL,te);
				SetCtrlAttribute (panelHandle,PANEL_TIMER, ATTR_ENABLED,1);

			break;
	}
	return 0;
}

//Functia ce implementeaza perioada de esantionare

int CVICALLBACK ESANTIONARE (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			//citire de pe interfata grafica valoare Amplitudine Semnal Treapta
			   	GetCtrlVal (panelHandle, PANEL_AMPLITUDINE_TR, &Atr);
			//citire de pe interfata grafica valoare A Semnal Rampa
			   	GetCtrlVal (panelHandle, PANEL_A_RAMPA, &a);
			//citire de pe interfata grafica valoare B Semnal Rampa
			   	GetCtrlVal (panelHandle, PANEL_B_RAMPA, &b);
			//citire de pe interfata grafica valoare Perioada Semnal
			   	GetCtrlVal (panelHandle, PANEL_PERIOADA, &T);
			///////////////////////////////////////////////////////
	
			//formare semnal treapta,Atr-amplitudinea Treapta;
				semnal_treapta = Atr;
			//formare semnal rampa,a – este panta semnalului rampa, b – este pozitionarea pe ordonata a semnalului(mai sus mai jos)  
				semnal_rampa=a*tk+b;
			//formare semnal sinusoidal,Atr-Amplitudinea,Tk sunt valoarea semnalului la momentul  actual
				semnal_sinusoidal=Atr*sin( ((2*pi)/T)*tk );
			
				 
				 
				if(SELECTIE_SEMNAL==1){
				//plotare semnal treapta;
				//formare semnal functie de transfer
				InT1=semnal_treapta;
		    	IeT1=IeT1_1+C1*(InT1-IeT1_1)+C2*(InT1-IeT1_1);
				InT2= IeT1;
				IeT2=IeT2_1+C3*(InT2-IeT2_1);
			
				PlotLine(panelHandle,PANEL_GRAFIC_SEMNAL_INTRARE,tk_1,semnal_treapta_1,tk,semnal_treapta, VAL_RED );
				//plotare tf
				
		  		PlotLine (panelHandle, PANEL_GRAFIC_SEMNAL_IESIRE, tk_1,IeT2_1, tk,  IeT2, VAL_CYAN);
				}
						
				
					if(SELECTIE_SEMNAL==2){
				//plotare semnal rampa;
				//formare semnal functie de transfer
				InT1=semnal_rampa;
		    	IeT1=IeT1_1+C1*(InT1-IeT1_1)+C2*(InT1-IeT1_1);
				InT2= IeT1;
				IeT2=IeT2_1+C3*(InT2-IeT2_1);
			
				PlotLine(panelHandle,PANEL_GRAFIC_SEMNAL_INTRARE,tk_1,semnal_rampa_1,tk,semnal_rampa,VAL_CYAN );
				//plotare tf
				PlotLine (panelHandle, PANEL_GRAFIC_SEMNAL_IESIR_2, tk_1,IeT2_1, tk,  IeT2, VAL_CYAN);  
				}
						if(SELECTIE_SEMNAL==3){
				//plotare semnal sinusoidal;
				//formare semnal functie de transfer
				InT1=semnal_sinusoidal;
		    	IeT1=IeT1_1+C1*(InT1-IeT1_1)+C2*(InT1-IeT1_1);
				InT2= IeT1;
				IeT2=IeT2_1+C3*(InT2-IeT2_1);
			
				PlotLine(panelHandle,PANEL_GRAFIC_SEMNAL_INTRARE,tk_1,semnal_sinusoidal_1, tk, semnal_sinusoidal,VAL_CYAN );
				//plotare tf
				PlotLine (panelHandle, PANEL_GRAFIC_SEMNAL_IESIR_3, tk_1,IeT2_1, tk,  IeT2, VAL_CYAN);    
				}
				
				
			
			 
		 	////Tk sunt valoarea semnalului la momentul actual respectiv momentul actual, Tk_1  momentul precendet    
				tk_1=tk; 
				 tk=tk+te;
		   //reactualizare semnal_treapta_1
				 semnal_treapta_1=semnal_treapta;
		   //reactualizare semnal_rampa_1 
				 semnal_rampa_1=semnal_rampa;
		   //reactualizare semnal_rampa_1
				 semnal_sinusoidal_1=semnal_sinusoidal;
		   //reactualizare T
				 IeT1_1=IeT1;
				 IeT2_1=IeT2;
				 IeT3_1=IeT3;
					
			break;
	}
	return 0;
}

//###################################################################################
//Functii Utilitare - Oprire aplicatie==Oprire Run-Time Engine
//###################################################################################
int CVICALLBACK QuitCallback (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);  //oprire run-time engine  
			break;
	}
	return 0;
}

//###################################################################################
//Functii Utilitare - Stergere continut grafice si pornire o noua afisare
//###################################################################################
int CVICALLBACK refresh_grafice (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			//stergere grafice desenate pe obiectele GRAPH
				DeleteGraphPlot (panelHandle,PANEL_GRAFIC_SEMNAL_INTRARE , -1, VAL_IMMEDIATE_DRAW );
				DeleteGraphPlot (panelHandle,PANEL_GRAFIC_SEMNAL_IESIRE , -1, VAL_IMMEDIATE_DRAW );
				DeleteGraphPlot (panelHandle,PANEL_GRAFIC_SEMNAL_IESIR_2 , -1, VAL_IMMEDIATE_DRAW ); 
				DeleteGraphPlot (panelHandle,PANEL_GRAFIC_SEMNAL_IESIR_3 , -1, VAL_IMMEDIATE_DRAW ); 
			//Reinitializare timp de afisare
				tk_1=0;
					tk=te;
					
			break;
	}
	return 0;
}
				
				

			
					   







