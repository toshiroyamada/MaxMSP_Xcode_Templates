/*
 *  �PROJECTNAME�.h
 *  �PROJECTNAME�
 *
 *  Created by �FULLUSERNAME� on �DATE�.
 *  Copyright (C) �YEAR� �ORGANIZATIONNAME�. All rights reserved.
 */
#ifndef _�PROJECTNAMEASIDENTIFIER�_h_
#define _�PROJECTNAMEASIDENTIFIER�_h_

extern "C" {
#include "ext.h"
#include "ext_obex.h"
#include "z_dsp.h"
}

class �PROJECTNAMEASIDENTIFIER�
{
public:
    �PROJECTNAMEASIDENTIFIER�() {}
    ~�PROJECTNAMEASIDENTIFIER�() {}
    
    //! Called when Max creates the object
    static void* alloc(t_symbol* s, long argc, t_atom* argv);
    
    //! Called when object is deleted
    static void free(�PROJECTNAMEASIDENTIFIER�* x);
    
    //! Inlet and outlet assistant messages
    static void assist(�PROJECTNAMEASIDENTIFIER�* x, void* b, long m, long a, char* s);
    
    //! DSP method
    static void dsp(�PROJECTNAMEASIDENTIFIER�* x, t_signal** sp, short* count);
    
    //! Perform method
    static t_int* perform(t_int* w);
    
    //! Inlet received long
    static void in_long(�PROJECTNAMEASIDENTIFIER�* x, long i);
    
    //! Inlet received double
    static void in_double(�PROJECTNAMEASIDENTIFIER�* x, double f);
    
	t_pxobject m_obj;
    
private:
    
    double gain;
};

#endif // _�PROJECTNAMEASIDENTIFIER�_h_