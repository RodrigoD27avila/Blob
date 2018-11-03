#pragma once

#include "opengl.h"

class ShaderProgram {

//----------------------------------------------------------------------------

public:
	ShaderProgram();
	~ShaderProgram();

//-----------------------------------------------------------------------------
	virtual bool           load               () = 0;
	void                   free               ();
	bool                   bind               ();
	void                   unbind             ();
//-----------------------------------------------------------------------------

	static void            print_program_log  (GLuint program);
	static void            print_shader_log   (GLuint shader);
//-----------------------------------------------------------------------------

	GLuint      programid;
	
};
