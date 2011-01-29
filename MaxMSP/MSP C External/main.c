/*
 *  �PROJECTNAME�.c
 *  �PROJECTNAME�
 *
 *  Created by �FULLUSERNAME� on �DATE�.
 *  Copyright �YEAR� �ORGANIZATIONNAME�. All rights reserved.
 */

#include "ext.h"
#include "ext_obex.h"
#include "z_dsp.h"

#pragma mark -
#pragma mark Object Struct
typedef struct _�PROJECTNAMEASIDENTIFIER�
{
	t_pxobject m_obj;
    double gain;
} t_�PROJECTNAMEASIDENTIFIER�;

#pragma mark -
#pragma mark Function Prototypes
void* �PROJECTNAMEASIDENTIFIER�_new(t_symbol* s, long argc, t_atom* argv);
void �PROJECTNAMEASIDENTIFIER�_free(t_�PROJECTNAMEASIDENTIFIER�* x);
void �PROJECTNAMEASIDENTIFIER�_assist(t_�PROJECTNAMEASIDENTIFIER�* x, void* b, long m, long a, char* s);
void �PROJECTNAMEASIDENTIFIER�_dsp(t_�PROJECTNAMEASIDENTIFIER�* x, t_signal** sp, short* count);
t_int* �PROJECTNAMEASIDENTIFIER�_perform(t_int* w);
void �PROJECTNAMEASIDENTIFIER�_long(t_�PROJECTNAMEASIDENTIFIER�* x, long i);
void �PROJECTNAMEASIDENTIFIER�_double(t_�PROJECTNAMEASIDENTIFIER�* x, double f);

// Global class pointer
static t_class* s_�PROJECTNAMEASIDENTIFIER�_class = NULL;

#pragma mark -
#pragma mark Alloc & Free
void* �PROJECTNAMEASIDENTIFIER�_new(t_symbol* s, long argc, t_atom* argv)
{
	t_�PROJECTNAMEASIDENTIFIER�* x = (t_�PROJECTNAMEASIDENTIFIER�*) object_alloc(s_�PROJECTNAMEASIDENTIFIER�_class);
	
	if (x != NULL) {
		
		/* Create inlet */
		dsp_setup((t_pxobject*)x, 1);
		/* Create outlet */
		outlet_new((t_object*)x, "signal");
		
		/* Initialize member variables. */
        x->gain = 1.0;
	}
	
	return x;
}

void �PROJECTNAMEASIDENTIFIER�_free(t_�PROJECTNAMEASIDENTIFIER�* x) 
{
	dsp_free((t_pxobject*)x);	/* Must call this first! */
    
	/* Do any deallocation needed here. */
}

#pragma mark -
#pragma mark Max Helpers
void �PROJECTNAMEASIDENTIFIER�_assist(t_�PROJECTNAMEASIDENTIFIER�* x, void* b, long m, long a, char* s)
{
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0:
				sprintf(s, "(signal) input\n(float/int) gain");
				break;
		}
	} 
	else {
		switch (a) {
			case 0:
				sprintf(s, "(signal) output");
				break;
		}		
	}
}

#pragma mark -
#pragma mark DSP
void �PROJECTNAMEASIDENTIFIER�_dsp(t_�PROJECTNAMEASIDENTIFIER�* x, t_signal** sp, short* count) 
{
	/* Change here if you have more/less inlets and outlets */
	dsp_add(�PROJECTNAMEASIDENTIFIER�_perform, 4, x, sp[0]->s_vec, sp[1]->s_vec, sp[0]->s_n);
}

t_int* �PROJECTNAMEASIDENTIFIER�_perform(t_int* w)
{
    t_�PROJECTNAMEASIDENTIFIER�* x = (t_�PROJECTNAMEASIDENTIFIER�*)w[1];
    t_sample* in = (t_sample*)w[2];
    t_sample* out = (t_sample*)w[3];
    int n = (int)w[4];
    
    while (n--) {
        /* Do any signal processing here */
        *out++ = *in++ * x->gain;
    }
    
    return w + 5;
}

#pragma mark -
#pragma mark Inlets
//! Inlet received long
void �PROJECTNAMEASIDENTIFIER�_long(t_�PROJECTNAMEASIDENTIFIER�* x, long i)
{
    �PROJECTNAMEASIDENTIFIER�_double(x, (double)i);
}

//! Inlet received double
void �PROJECTNAMEASIDENTIFIER�_double(t_�PROJECTNAMEASIDENTIFIER�* x, double f)
{
    long inlet = proxy_getinlet((t_object*)&x->m_obj);
    
    switch (inlet) {
        case 0:
            x->gain = f;
            break;
    }
}

#pragma mark -
#pragma mark Main
int main(void)
{
	t_class* c;
	
	c = class_new("�PROJECTNAME�", 
                  (method)�PROJECTNAMEASIDENTIFIER�_new, 
                  (method)�PROJECTNAMEASIDENTIFIER�_free, 
				  sizeof(t_�PROJECTNAMEASIDENTIFIER�), 
                  (method)0L, A_GIMME, 0);
	
	/* Add class methods */
    class_addmethod(c, (method)�PROJECTNAMEASIDENTIFIER�_assist, "assist", A_CANT, 0);
    class_addmethod(c, (method)�PROJECTNAMEASIDENTIFIER�_dsp, "dsp", A_CANT, 0);
    class_addmethod(c, (method)�PROJECTNAMEASIDENTIFIER�_long, "int", A_LONG, 0);
    class_addmethod(c, (method)�PROJECTNAMEASIDENTIFIER�_double, "float", A_FLOAT, 0);
	
	/* Add attributes */
	
	class_dspinit(c);
	class_register(CLASS_BOX, c);
	s_�PROJECTNAMEASIDENTIFIER�_class = c;
	
	return 0;
}
