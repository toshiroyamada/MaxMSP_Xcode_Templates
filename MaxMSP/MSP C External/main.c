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

typedef struct _�PROJECTNAMEASIDENTIFIER�
{
	t_pxobject m_obj;
} t_�PROJECTNAMEASIDENTIFIER�;

static t_class* s_�PROJECTNAMEASIDENTIFIER�_class = NULL;

void* �PROJECTNAMEASIDENTIFIER�_new(t_symbol* s, long argc, t_atom* argv)
{
	t_dictionary* d = object_dictionaryarg(argc, argv);
	
	if (d == NULL) {
		return NULL;
	}
	
	t_�PROJECTNAMEASIDENTIFIER�* x = (t_�PROJECTNAMEASIDENTIFIER�*) object_alloc(s_�PROJECTNAMEASIDENTIFIER�_class);
	
	if (x != NULL) {
		attr_dictionary_process(x, d);
		
		/* Create inlet */
		dsp_setup((t_pxobject*)x, 1);
		/* Create outlet */
		outlet_new((t_object*)x, "signal");
		
		/* Initialize member variables. */
	}
	
	return x;
}

void �PROJECTNAMEASIDENTIFIER�_free(t_�PROJECTNAMEASIDENTIFIER�* x) 
{
	/* Do any deallocation needed here. */
	dsp_free((t_pxobject*)x);	/* Must call this first! */
}

t_int* �PROJECTNAMEASIDENTIFIER�_perform(t_int* w)
{
	t_�PROJECTNAMEASIDENTIFIER�* x = (t_�PROJECTNAMEASIDENTIFIER�*)(w[1]);
	t_float* in = (t_float*)(w[2]);
	t_float* out = (t_float*)(w[3]);
	int n = (int)(w[4]);
	
	while (n--) {
		/* Do any signal processing here */
		*out++ = *in++;
	}
	
	return w + 5;
}

void �PROJECTNAMEASIDENTIFIER�_dsp(t_�PROJECTNAMEASIDENTIFIER�* x, t_signal** sp, short* count) 
{
	/* Change here if you have more/less inlets and outlets */
	dsp_add(�PROJECTNAMEASIDENTIFIER�_perform, 4, x, sp[0]->s_vec, sp[1]->s_vec, sp[0]->s_n);
}


void �PROJECTNAMEASIDENTIFIER�_assist(t_�PROJECTNAMEASIDENTIFIER�* x, void* b, long m, long a, char* s)
{
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0:
				sprintf(s, "1st Inlet");
				break;
		}
	} 
	else {
		switch (a) {
			case 0:
				sprintf(s, "1st Outlet");
				break;
		}		
	}
}

int main(void)
{
	t_class* c;
	
	c = class_new("�PROJECTNAME�", (method)�PROJECTNAMEASIDENTIFIER�_new, (method)�PROJECTNAMEASIDENTIFIER�_free, 
				  sizeof(t_�PROJECTNAMEASIDENTIFIER�), (method)0L, A_GIMME, 0);
	
	c->c_flags |= CLASS_FLAG_NEWDICTIONARY;
	
	/* Add class methods */
    class_addmethod(c, (method)�PROJECTNAMEASIDENTIFIER�_dsp, "dsp", A_CANT, 0);
    class_addmethod(c, (method)�PROJECTNAMEASIDENTIFIER�_assist, "assist", A_CANT, 0);
	
	/* Add attributes */
	
	class_dspinit(c);
	class_register(CLASS_BOX, c);
	s_�PROJECTNAMEASIDENTIFIER�_class = c;
	
	return 0;
}
