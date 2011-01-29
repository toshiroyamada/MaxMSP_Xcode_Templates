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
    
	t_object m_obj;
    
private:
};

#endif // _�PROJECTNAMEASIDENTIFIER�_h_