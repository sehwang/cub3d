// mlx_opengl.m
#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>
#import <AppKit/NSOpenGLView.h>

#include <stdio.h>

#include "mlx_int.h"
#include "mlx_new_window.h"

int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey)
{
	NSRect e = [[NSScreen mainScreen] frame];
	*sizex = (int)e.size.width;
	*sizey = (int)e.size.height;
	return (0);
}
