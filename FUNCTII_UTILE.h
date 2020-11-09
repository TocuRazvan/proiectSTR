
///////////////////SELECTIE SEMNAL TREAPTA
int CVICALLBACK start_semnal_treapta (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				SELECTIE_SEMNAL=1 ;
				DeleteGraphPlot (panelHandle,PANEL_GRAFIC_SEMNAL_INTRARE , -1, VAL_IMMEDIATE_DRAW );
				DeleteGraphPlot (panelHandle,PANEL_GRAFIC_SEMNAL_IESIRE , -1, VAL_IMMEDIATE_DRAW );
			    tk_1=0;
			    tk=te;
			  IeT3=0;
			  IeT2=0;
			  IeT1=0;
			  IeT3_1=0;
			  IeT2_1=0;
			  IeT1_1=0;
			break;
	}

	return 0;
}

///////////////////////SELECTIE SEMNAL RAMPA
int CVICALLBACK start_semnal_rampa (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			  SELECTIE_SEMNAL=2;
			  DeleteGraphPlot (panelHandle,PANEL_GRAFIC_SEMNAL_INTRARE , -1, VAL_IMMEDIATE_DRAW ); 
			  DeleteGraphPlot (panelHandle,PANEL_GRAFIC_SEMNAL_IESIR_2 , -1, VAL_IMMEDIATE_DRAW );
			  tk_1=0;
			  tk=te;
			  IeT3=0;
			  IeT2=0;
			  IeT1=0;
			  IeT3_1=0;
			  IeT2_1=0;
			  IeT1_1=0;
			break;
	}
	return 0;
}

////////////////////////SELECTIE SEMNAL SINUSOIDAL
int CVICALLBACK start_semnal_sinusoidal (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			SELECTIE_SEMNAL=3;
			  DeleteGraphPlot (panelHandle,PANEL_GRAFIC_SEMNAL_INTRARE , -1, VAL_IMMEDIATE_DRAW ); 
			  DeleteGraphPlot (panelHandle,PANEL_GRAFIC_SEMNAL_IESIR_3 , -1, VAL_IMMEDIATE_DRAW );
			  tk_1=0;
			  tk=te;
			   IeT3=0;
			  IeT2=0;
			  IeT1=0;
			  IeT3_1=0;
			  IeT2_1=0;
			  IeT1_1=0;
			  
			break;
	}
	return 0;
}
