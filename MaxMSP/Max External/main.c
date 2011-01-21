/*
 *  �PROJECTNAME�.c
 *  �PROJECTNAME�
 *
 *  Created by �FULLUSERNAME� on �DATE�.
 *  Copyright �YEAR� �ORGANIZATIONNAME�. All rights reserved.
 */

#include "ext.h"
#include "ext_obex.h"

typedef struct _�PROJECTNAMEASIDENTIFIER�
{
	t_object m_obj;
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
		
		/* 1. Create inlets and outlets.
		 * i.e.	floatin((t_object*)x, 1);
		 *		x->m_outlet = floatout((t_object*)x, 1);
		 *
		 * 2. Initialize member variables.
		 */
	}
	
	return x;
}

void �PROJECTNAMEASIDENTIFIER�_free(t_�PROJECTNAMEASIDENTIFIER�* x) 
{
	/* Do any deallocation needed here. */
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
	class_addmethod(c, (method)�PROJECTNAMEASIDENTIFIER�_assist, "assist", A_CANT, 0);
	
	/* Add attributes */
	
	class_register(CLASS_BOX, c);
	s_�PROJECTNAMEASIDENTIFIER�_class = c;
	
	return 0;
}
