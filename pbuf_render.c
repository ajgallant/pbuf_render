/* $Id$ */

/*
 * pbuf_render.c - create an off-screen rendering context in OpenGL 2.1
 *
 * This OpenGL application requests a pbuffer rendering context using a valid
 * GLXFBConfig.  The size of the requested .....
 *
 * The upgrade to Mac OS 10.15 has broken the call to glXCreatePbuffer() as 
 * shown in this application.  The issue is still reproducing in Mac OS 11.1 
 * with XQuartz 2.8.0 (xorg-server 1.19.7).
 *
 * Documentation:
 *   man Xquartz
 * Logs:
 *   tail -f ~/Library/Logs/X11/org.xquartz.log
 */

#include <errno.h>
#include <stdio.h>

#include <GL/gl.h>
#include <GL/glx.h>


#define WINDOW_WIDTH  640
#define WINDOW_HEIGHT 480


int main(int argc, char *argv[]) {

  Display *dpy = XOpenDisplay(NULL);
  int screen = XDefaultScreen( dpy );

  // select a FBConfig with support for RGBA + pbuffer
  const int fbCfgAttribslist[] =
  {
      GLX_RENDER_TYPE, GLX_RGBA_BIT,
      GLX_DRAWABLE_TYPE, GLX_PBUFFER_BIT,
      None
  };
  int nElements = 0;
  GLXFBConfig * glxfbCfg = glXChooseFBConfig( dpy,
      screen,
      fbCfgAttribslist,
      & nElements );

  // print info for FBConfig
  printf("glXChooseFBConfig() found %d eligible FBConfig\n", nElements);
  int idx;
  //for (idx=0; idx < nElements; idx++) {
  for (idx=0; idx == 0; idx++) {
    int fbconfig_id, drawable_type, render_type;
    glXGetFBConfigAttrib(dpy, glxfbCfg[idx], GLX_FBCONFIG_ID, &fbconfig_id);
    glXGetFBConfigAttrib(dpy, glxfbCfg[idx], GLX_DRAWABLE_TYPE, &drawable_type);
    glXGetFBConfigAttrib(dpy, glxfbCfg[idx], GLX_RENDER_TYPE, &render_type);
    printf("fbCfg[%d] id: 0x%x, drawable_flags: %d (%d), render_flags: %d (%d)\n",
        idx, fbconfig_id, drawable_type, GLX_PBUFFER_BIT, render_type, GLX_RGBA_BIT);
    int max_w, max_h, max_pixels;
    glXGetFBConfigAttrib(dpy, glxfbCfg[idx], GLX_MAX_PBUFFER_WIDTH, &max_w);
    glXGetFBConfigAttrib(dpy, glxfbCfg[idx], GLX_MAX_PBUFFER_HEIGHT, &max_h);
    glXGetFBConfigAttrib(dpy, glxfbCfg[idx], GLX_MAX_PBUFFER_PIXELS, &max_pixels);
    printf("fbCfg[%d] max: w%d h%d p%d\n", idx, max_w, max_h, max_pixels);
  }

  // select a pbuffer supporting 640 x 480 pixels
  const int pbfCfg[] =
  {
      GLX_PBUFFER_WIDTH, WINDOW_WIDTH,
      GLX_PBUFFER_HEIGHT, WINDOW_HEIGHT,
      None
  };

  printf("glXCreatePbuffer() may throw an error\n");
  GLXPbuffer pBufferId = glXCreatePbuffer( dpy, glxfbCfg[0], pbfCfg );
  //printf("PBuffer OK?  pBufferId = %ld\n", pBufferId);
  
  // store visual info for later use
  XVisualInfo * visInfo = glXGetVisualFromFBConfig( dpy, glxfbCfg[0] );

  // create rendering context
  GLXContext  glCtx = glXCreateContext( dpy, visInfo, NULL, True );

  // switch to new rendering context
  glXMakeContextCurrent( dpy,
      pBufferId,
      pBufferId,
      glCtx );

  printf("Off-screen rendering context ready.\n");
}
