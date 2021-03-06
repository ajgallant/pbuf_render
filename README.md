# OpenGL GLXPbuffer Allocation Test

author: Andrew Gallant <br>
git uid: ajgallant

## Summary

This project is a test case for off-screen rendering in OpenGL 2.1 using
GLXPbuffers.  OpenGL throws a BadMatch error in the call to glXCreatePbuffer()
as indicated in the Application Output section.  This test was passing prior
to an upgrade to MacOS X 10.15.

## Dependencies

OS:        MacOS 11.1 (Big Sur) <br>
Graphics:  AMD Radeon Pro 575 <br>
X11:       XQuartz 2.8.0 (xorg-server 1.19.7) <br>
  OpenGL 2.1 <br>
  GLX 1.4 <br>
compiler:  Apple clang version 12.0.0 (clang-1200.0.32.28) <br>
           Target: x86_64-apple-darwin20.2.0 <br>


### Build

    make all


### Execute Application

    pbuf_render


## Application Output

```
glXChooseFBConfig() found 160 eligible FBConfig
fbCfg[0] id: 0x69, drawable_flags: 7 (4), render_flags: 1 (1)
fbCfg[0] max: w8192 h8192 p0
glXCreatePbuffer() may throw an error
X Error of failed request:  BadMatch (invalid parameter attributes)
  Major opcode of failed request:  149 (GLX)
  Minor opcode of failed request:  27 (X_GLXCreatePbuffer)
  Serial number of failed request:  20
  Current serial number in output stream:  20
```

**Note**

1.  GLX_MAX_PBUFFER_PIXELS == 0 for all selected GLXFBConfig from
    glXChooseFBConfig().  This would imply that only a pbuffer of size 0 may be
    allocated.

2.  glXCreatePbuffer() docs from https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/ reads: <p> BadMatch is generated if config does not support rendering to pixel buffers (e.g., GLX_DRAWABLE_TYPE does not contain GLX_PBUFFER_BIT).


## Additional Platform Information

```
~+ glxinfo

name of display: /private/tmp/com.apple.launchd.ofC9RLPwg2/org.xquartz:0
display: /private/tmp/com.apple.launchd.ofC9RLPwg2/org.xquartz:0  screen: 0
direct rendering: Yes
server glx vendor string: SGI
server glx version string: 1.4
server glx extensions:
    GLX_ARB_multisample, GLX_EXT_import_context, GLX_EXT_visual_info, 
    GLX_EXT_visual_rating, GLX_OML_swap_method, GLX_SGIS_multisample, 
    GLX_SGIX_fbconfig, GLX_SGIX_pbuffer, GLX_SGIX_visual_select_group, 
    GLX_SGI_make_current_read
client glx vendor string: Mesa Project and SGI
client glx version string: 1.4
client glx extensions:
    GLX_ARB_context_flush_control, GLX_ARB_create_context, 
    GLX_ARB_create_context_no_error, GLX_ARB_create_context_profile, 
    GLX_ARB_create_context_robustness, GLX_ARB_fbconfig_float, 
    GLX_ARB_framebuffer_sRGB, GLX_ARB_get_proc_address, GLX_ARB_multisample, 
    GLX_EXT_buffer_age, GLX_EXT_create_context_es2_profile, 
    GLX_EXT_create_context_es_profile, GLX_EXT_fbconfig_packed_float, 
    GLX_EXT_framebuffer_sRGB, GLX_EXT_import_context, GLX_EXT_swap_control, 
    GLX_EXT_swap_control_tear, GLX_EXT_texture_from_pixmap, 
    GLX_EXT_visual_info, GLX_EXT_visual_rating, GLX_INTEL_swap_event, 
    GLX_MESA_copy_sub_buffer, GLX_MESA_multithread_makecurrent, 
    GLX_MESA_query_renderer, GLX_MESA_swap_control, GLX_OML_swap_method, 
    GLX_OML_sync_control, GLX_SGIS_multisample, GLX_SGIX_fbconfig, 
    GLX_SGIX_pbuffer, GLX_SGIX_visual_select_group, GLX_SGI_make_current_read, 
    GLX_SGI_swap_control, GLX_SGI_video_sync
GLX version: 1.4
GLX extensions:
    GLX_ARB_get_proc_address, GLX_ARB_multisample, GLX_EXT_import_context, 
    GLX_EXT_visual_info, GLX_EXT_visual_rating, GLX_OML_swap_method, 
    GLX_SGIS_multisample, GLX_SGIX_fbconfig, GLX_SGIX_pbuffer, 
    GLX_SGIX_visual_select_group, GLX_SGI_make_current_read
OpenGL vendor string: ATI Technologies Inc.
OpenGL renderer string: AMD Radeon Pro 575 OpenGL Engine
OpenGL version string: 2.1 ATI-4.2.13
OpenGL shading language version string: 1.20
OpenGL extensions:
    GL_APPLE_aux_depth_stencil, GL_APPLE_client_storage, 
    GL_APPLE_element_array, GL_APPLE_fence, GL_APPLE_float_pixels, 
    GL_APPLE_flush_buffer_range, GL_APPLE_flush_render, 
    GL_APPLE_object_purgeable, GL_APPLE_packed_pixels, GL_APPLE_pixel_buffer, 
    GL_APPLE_rgb_422, GL_APPLE_row_bytes, GL_APPLE_specular_vector, 
    GL_APPLE_texture_range, GL_APPLE_transform_hint, 
    GL_APPLE_vertex_array_object, GL_APPLE_vertex_array_range, 
    GL_APPLE_vertex_point_size, GL_APPLE_vertex_program_evaluators, 
    GL_APPLE_ycbcr_422, GL_ARB_color_buffer_float, GL_ARB_depth_buffer_float, 
    GL_ARB_depth_clamp, GL_ARB_depth_texture, GL_ARB_draw_buffers, 
    GL_ARB_draw_elements_base_vertex, GL_ARB_draw_instanced, 
    GL_ARB_fragment_program, GL_ARB_fragment_program_shadow, 
    GL_ARB_fragment_shader, GL_ARB_framebuffer_object, 
    GL_ARB_framebuffer_sRGB, GL_ARB_half_float_pixel, 
    GL_ARB_half_float_vertex, GL_ARB_imaging, GL_ARB_instanced_arrays, 
    GL_ARB_multisample, GL_ARB_multitexture, GL_ARB_occlusion_query, 
    GL_ARB_pixel_buffer_object, GL_ARB_point_parameters, GL_ARB_point_sprite, 
    GL_ARB_provoking_vertex, GL_ARB_seamless_cube_map, GL_ARB_shader_objects, 
    GL_ARB_shader_texture_lod, GL_ARB_shading_language_100, GL_ARB_shadow, 
    GL_ARB_shadow_ambient, GL_ARB_sync, GL_ARB_texture_border_clamp, 
    GL_ARB_texture_compression, GL_ARB_texture_compression_rgtc, 
    GL_ARB_texture_cube_map, GL_ARB_texture_env_add, 
    GL_ARB_texture_env_combine, GL_ARB_texture_env_crossbar, 
    GL_ARB_texture_env_dot3, GL_ARB_texture_float, 
    GL_ARB_texture_mirrored_repeat, GL_ARB_texture_non_power_of_two, 
    GL_ARB_texture_rectangle, GL_ARB_texture_rg, GL_ARB_transpose_matrix, 
    GL_ARB_vertex_array_bgra, GL_ARB_vertex_blend, 
    GL_ARB_vertex_buffer_object, GL_ARB_vertex_program, GL_ARB_vertex_shader, 
    GL_ARB_window_pos, GL_ATI_blend_equation_separate, 
    GL_ATI_blend_weighted_minmax, GL_ATI_separate_stencil, 
    GL_ATI_texture_compression_3dc, GL_ATI_texture_env_combine3, 
    GL_ATI_texture_float, GL_ATI_texture_mirror_once, GL_EXT_abgr, 
    GL_EXT_bgra, GL_EXT_bindable_uniform, GL_EXT_blend_color, 
    GL_EXT_blend_equation_separate, GL_EXT_blend_func_separate, 
    GL_EXT_blend_minmax, GL_EXT_blend_subtract, GL_EXT_clip_volume_hint, 
    GL_EXT_debug_label, GL_EXT_debug_marker, GL_EXT_depth_bounds_test, 
    GL_EXT_draw_buffers2, GL_EXT_draw_range_elements, GL_EXT_fog_coord, 
    GL_EXT_framebuffer_blit, GL_EXT_framebuffer_multisample, 
    GL_EXT_framebuffer_object, GL_EXT_framebuffer_sRGB, 
    GL_EXT_geometry_shader4, GL_EXT_gpu_program_parameters, 
    GL_EXT_gpu_shader4, GL_EXT_multi_draw_arrays, GL_EXT_packed_depth_stencil, 
    GL_EXT_packed_float, GL_EXT_provoking_vertex, GL_EXT_rescale_normal, 
    GL_EXT_secondary_color, GL_EXT_separate_specular_color, 
    GL_EXT_shadow_funcs, GL_EXT_stencil_two_side, GL_EXT_stencil_wrap, 
    GL_EXT_texture_array, GL_EXT_texture_compression_dxt1, 
    GL_EXT_texture_compression_s3tc, GL_EXT_texture_env_add, 
    GL_EXT_texture_filter_anisotropic, GL_EXT_texture_integer, 
    GL_EXT_texture_lod_bias, GL_EXT_texture_mirror_clamp, 
    GL_EXT_texture_rectangle, GL_EXT_texture_sRGB, GL_EXT_texture_sRGB_decode, 
    GL_EXT_texture_shared_exponent, GL_EXT_timer_query, 
    GL_EXT_transform_feedback, GL_EXT_vertex_array_bgra, 
    GL_IBM_rasterpos_clip, GL_NV_blend_square, GL_NV_conditional_render, 
    GL_NV_depth_clamp, GL_NV_fog_distance, GL_NV_light_max_exponent, 
    GL_NV_texgen_reflection, GL_NV_texture_barrier, GL_SGIS_generate_mipmap, 
    GL_SGIS_texture_edge_clamp, GL_SGIS_texture_lod, GL_SGI_color_matrix

96 GLX Visuals
    visual  x   bf lv rg d st  colorbuffer  sr ax dp st accumbuffer  ms  cav
  id dep cl sp  sz l  ci b ro  r  g  b  a F gb bf th cl  r  g  b  a ns b eat
----------------------------------------------------------------------------
0x022 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 16  8  0  0  0  0  0 0 None
0x0e1 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0  0  0  0  0  0  0  0 0 Slow
0x0e2 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0  0  0  0  0  0  0 16 1 Slow
0x0e3 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 32  0  0  0  0  0  0 0 Slow
0x0e4 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 32  0  0  0  0  0 16 1 Slow
0x0e5 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0  0  8  0  0  0  0  0 0 Slow
0x0e6 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0  0  8  0  0  0  0 16 1 Slow
0x0e7 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 32  8  0  0  0  0  0 0 Slow
0x0e8 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 32  8  0  0  0  0 16 1 Slow
0x0e9 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0  0  0  0  0  0  0  0 0 Slow
0x0ea 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0  0  0  0  0  0  0 16 1 Slow
0x0eb 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 32  0  0  0  0  0  0 0 Slow
0x0ec 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 32  0  0  0  0  0 16 1 Slow
0x0ed 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0  0  8  0  0  0  0  0 0 Slow
0x0ee 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0  0  8  0  0  0  0 16 1 Slow
0x0ef 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 32  8  0  0  0  0  0 0 Slow
0x0f0 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 32  8  0  0  0  0 16 1 Slow
0x0f1 24 tc  1  32  0 r  . .   8  8  8  8 .  .  4  0  0  0  0  0  0  0 0 Slow
0x0f2 24 tc  1  32  0 r  . .   8  8  8  8 .  .  4  0  0  0  0  0  0 16 1 Slow
0x0f3 24 tc  1  32  0 r  . .   8  8  8  8 .  .  4 32  0  0  0  0  0  0 0 Slow
0x0f4 24 tc  1  32  0 r  . .   8  8  8  8 .  .  4 32  0  0  0  0  0 16 1 Slow
0x0f5 24 tc  1  32  0 r  . .   8  8  8  8 .  .  4  0  8  0  0  0  0  0 0 Slow
0x0f6 24 tc  1  32  0 r  . .   8  8  8  8 .  .  4  0  8  0  0  0  0 16 1 Slow
0x0f7 24 tc  1  32  0 r  . .   8  8  8  8 .  .  4 32  8  0  0  0  0  0 0 Slow
0x0f8 24 tc  1  32  0 r  . .   8  8  8  8 .  .  4 32  8  0  0  0  0 16 1 Slow
0x0f9 24 tc  1  32  0 r  y .   8  8  8  8 .  .  4  0  0  0  0  0  0  0 0 Slow
0x0fa 24 tc  1  32  0 r  y .   8  8  8  8 .  .  4  0  0  0  0  0  0 16 1 Slow
0x0fb 24 tc  1  32  0 r  y .   8  8  8  8 .  .  4 32  0  0  0  0  0  0 0 Slow
0x0fc 24 tc  1  32  0 r  y .   8  8  8  8 .  .  4 32  0  0  0  0  0 16 1 Slow
0x0fd 24 tc  1  32  0 r  y .   8  8  8  8 .  .  4  0  8  0  0  0  0  0 0 Slow
0x0fe 24 tc  1  32  0 r  y .   8  8  8  8 .  .  4  0  8  0  0  0  0 16 1 Slow
0x0ff 24 tc  1  32  0 r  y .   8  8  8  8 .  .  4 32  8  0  0  0  0  0 0 Slow
0x100 24 tc  1  32  0 r  y .   8  8  8  8 .  .  4 32  8  0  0  0  0 16 1 Slow
0x101 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0  0  0  0  0  0  0  0 0 None
0x102 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0  0  0  0  0  0  0  8 1 None
0x103 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 16  0  0  0  0  0  0 0 None
0x104 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 16  0  0  0  0  0  8 1 None
0x105 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 24  0  0  0  0  0  0 0 None
0x106 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 24  0  0  0  0  0  8 1 None
0x107 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 32  0  0  0  0  0  0 0 None
0x108 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 32  0  0  0  0  0  8 1 None
0x109 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0  0  8  0  0  0  0  0 0 None
0x10a 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0  0  8  0  0  0  0  8 1 None
0x10b 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 16  8  0  0  0  0  0 0 None
0x10c 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 16  8  0  0  0  0  8 1 None
0x10d 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 24  8  0  0  0  0  0 0 None
0x10e 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 24  8  0  0  0  0  8 1 None
0x10f 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 32  8  0  0  0  0  0 0 None
0x110 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 32  8  0  0  0  0  8 1 None
0x111 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0  0  0  0  0  0  0  0 0 None
0x112 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0  0  0  0  0  0  0  8 1 None
0x113 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 16  0  0  0  0  0  0 0 None
0x114 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 16  0  0  0  0  0  8 1 None
0x115 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 24  0  0  0  0  0  0 0 None
0x116 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 24  0  0  0  0  0  8 1 None
0x117 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 32  0  0  0  0  0  0 0 None
0x118 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 32  0  0  0  0  0  8 1 None
0x119 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0  0  8  0  0  0  0  0 0 None
0x11a 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0  0  8  0  0  0  0  8 1 None
0x11b 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 16  8  0  0  0  0  8 1 None
0x11c 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 24  8  0  0  0  0  0 0 None
0x11d 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 24  8  0  0  0  0  8 1 None
0x11e 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 32  8  0  0  0  0  0 0 None
0x11f 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 32  8  0  0  0  0  8 1 None
0x120 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2  0  0  0  0  0  0  0 0 None
0x121 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2  0  0  0  0  0  0  8 1 None
0x122 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 16  0  0  0  0  0  0 0 None
0x123 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 16  0  0  0  0  0  8 1 None
0x124 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 24  0  0  0  0  0  0 0 None
0x125 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 24  0  0  0  0  0  8 1 None
0x126 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 32  0  0  0  0  0  0 0 None
0x127 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 32  0  0  0  0  0  8 1 None
0x128 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2  0  8  0  0  0  0  0 0 None
0x129 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2  0  8  0  0  0  0  8 1 None
0x12a 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 16  8  0  0  0  0  0 0 None
0x12b 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 16  8  0  0  0  0  8 1 None
0x12c 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 24  8  0  0  0  0  0 0 None
0x12d 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 24  8  0  0  0  0  8 1 None
0x12e 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 32  8  0  0  0  0  0 0 None
0x12f 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 32  8  0  0  0  0  8 1 None
0x130 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2  0  0  0  0  0  0  0 0 None
0x131 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2  0  0  0  0  0  0  8 1 None
0x132 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 16  0  0  0  0  0  0 0 None
0x133 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 16  0  0  0  0  0  8 1 None
0x134 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 24  0  0  0  0  0  0 0 None
0x135 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 24  0  0  0  0  0  8 1 None
0x136 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 32  0  0  0  0  0  0 0 None
0x137 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 32  0  0  0  0  0  8 1 None
0x138 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2  0  8  0  0  0  0  0 0 None
0x139 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2  0  8  0  0  0  0  8 1 None
0x13a 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 16  8  0  0  0  0  0 0 None
0x13b 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 16  8  0  0  0  0  8 1 None
0x13c 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 24  8  0  0  0  0  0 0 None
0x13d 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 24  8  0  0  0  0  8 1 None
0x13e 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 32  8  0  0  0  0  0 0 None
0x13f 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 32  8  0  0  0  0  8 1 None

160 GLXFBConfigs:
    visual  x   bf lv rg d st  colorbuffer  sr ax dp st accumbuffer  ms  cav
  id dep cl sp  sz l  ci b ro  r  g  b  a F gb bf th cl  r  g  b  a ns b eat
----------------------------------------------------------------------------
0x041 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0  0  0  0  0  0  0  0 0 Slow
0x042 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0  0  0  0  0  0  0 16 1 Slow
0x043 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 32  0  0  0  0  0  0 0 Slow
0x044 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 32  0  0  0  0  0 16 1 Slow
0x045 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0  0  8  0  0  0  0  0 0 Slow
0x046 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0  0  8  0  0  0  0 16 1 Slow
0x047 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 32  8  0  0  0  0  0 0 Slow
0x048 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 32  8  0  0  0  0 16 1 Slow
0x049 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0  0  0  0  0  0  0  0 0 Slow
0x04a 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0  0  0  0  0  0  0 16 1 Slow
0x04b 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 32  0  0  0  0  0  0 0 Slow
0x04c 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 32  0  0  0  0  0 16 1 Slow
0x04d 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0  0  8  0  0  0  0  0 0 Slow
0x04e 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0  0  8  0  0  0  0 16 1 Slow
0x04f 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 32  8  0  0  0  0  0 0 Slow
0x050 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 32  8  0  0  0  0 16 1 Slow
0x051 24 tc  1  32  0 r  . .   8  8  8  8 .  .  4  0  0  0  0  0  0  0 0 Slow
0x052 24 tc  1  32  0 r  . .   8  8  8  8 .  .  4  0  0  0  0  0  0 16 1 Slow
0x053 24 tc  1  32  0 r  . .   8  8  8  8 .  .  4 32  0  0  0  0  0  0 0 Slow
0x054 24 tc  1  32  0 r  . .   8  8  8  8 .  .  4 32  0  0  0  0  0 16 1 Slow
0x055 24 tc  1  32  0 r  . .   8  8  8  8 .  .  4  0  8  0  0  0  0  0 0 Slow
0x056 24 tc  1  32  0 r  . .   8  8  8  8 .  .  4  0  8  0  0  0  0 16 1 Slow
0x057 24 tc  1  32  0 r  . .   8  8  8  8 .  .  4 32  8  0  0  0  0  0 0 Slow
0x058 24 tc  1  32  0 r  . .   8  8  8  8 .  .  4 32  8  0  0  0  0 16 1 Slow
0x059 24 tc  1  32  0 r  y .   8  8  8  8 .  .  4  0  0  0  0  0  0  0 0 Slow
0x05a 24 tc  1  32  0 r  y .   8  8  8  8 .  .  4  0  0  0  0  0  0 16 1 Slow
0x05b 24 tc  1  32  0 r  y .   8  8  8  8 .  .  4 32  0  0  0  0  0  0 0 Slow
0x05c 24 tc  1  32  0 r  y .   8  8  8  8 .  .  4 32  0  0  0  0  0 16 1 Slow
0x05d 24 tc  1  32  0 r  y .   8  8  8  8 .  .  4  0  8  0  0  0  0  0 0 Slow
0x05e 24 tc  1  32  0 r  y .   8  8  8  8 .  .  4  0  8  0  0  0  0 16 1 Slow
0x05f 24 tc  1  32  0 r  y .   8  8  8  8 .  .  4 32  8  0  0  0  0  0 0 Slow
0x060 24 tc  1  32  0 r  y .   8  8  8  8 .  .  4 32  8  0  0  0  0 16 1 Slow
0x061  0 tc  1  16  0 r  . .   5  5  5  1 .  .  0  0  0  0  0  0  0  0 0 None
0x062  0 tc  1  16  0 r  . .   5  5  5  1 .  .  0  0  0  0  0  0  0  8 1 None
0x063  0 tc  1  16  0 r  . .   5  5  5  1 .  .  0 16  0  0  0  0  0  0 0 None
0x064  0 tc  1  16  0 r  . .   5  5  5  1 .  .  0 16  0  0  0  0  0  8 1 None
0x065  0 tc  1  16  0 r  . .   5  5  5  1 .  .  0 24  0  0  0  0  0  0 0 None
0x066  0 tc  1  16  0 r  . .   5  5  5  1 .  .  0 24  0  0  0  0  0  8 1 None
0x067  0 tc  1  16  0 r  . .   5  5  5  1 .  .  0 32  0  0  0  0  0  0 0 None
0x068  0 tc  1  16  0 r  . .   5  5  5  1 .  .  0 32  0  0  0  0  0  8 1 None
0x069 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0  0  0  0  0  0  0  0 0 None
0x06a 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0  0  0  0  0  0  0  8 1 None
0x06b 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 16  0  0  0  0  0  0 0 None
0x06c 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 16  0  0  0  0  0  8 1 None
0x06d 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 24  0  0  0  0  0  0 0 None
0x06e 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 24  0  0  0  0  0  8 1 None
0x06f 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 32  0  0  0  0  0  0 0 None
0x070 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 32  0  0  0  0  0  8 1 None
0x071  0 tc  1  16  0 r  . .   5  5  5  1 .  .  0  0  8  0  0  0  0  0 0 None
0x072  0 tc  1  16  0 r  . .   5  5  5  1 .  .  0  0  8  0  0  0  0  8 1 None
0x073  0 tc  1  16  0 r  . .   5  5  5  1 .  .  0 16  8  0  0  0  0  0 0 None
0x074  0 tc  1  16  0 r  . .   5  5  5  1 .  .  0 16  8  0  0  0  0  8 1 None
0x075  0 tc  1  16  0 r  . .   5  5  5  1 .  .  0 24  8  0  0  0  0  0 0 None
0x076  0 tc  1  16  0 r  . .   5  5  5  1 .  .  0 24  8  0  0  0  0  8 1 None
0x077  0 tc  1  16  0 r  . .   5  5  5  1 .  .  0 32  8  0  0  0  0  0 0 None
0x078  0 tc  1  16  0 r  . .   5  5  5  1 .  .  0 32  8  0  0  0  0  8 1 None
0x079 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0  0  8  0  0  0  0  0 0 None
0x07a 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0  0  8  0  0  0  0  8 1 None
0x07b 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 16  8  0  0  0  0  0 0 None
0x07c 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 16  8  0  0  0  0  8 1 None
0x07d 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 24  8  0  0  0  0  0 0 None
0x07e 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 24  8  0  0  0  0  8 1 None
0x07f 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 32  8  0  0  0  0  0 0 None
0x080 24 tc  1  32  0 r  . .   8  8  8  8 .  .  0 32  8  0  0  0  0  8 1 None
0x081  0 tc  1  16  0 r  y .   5  5  5  1 .  .  0  0  0  0  0  0  0  0 0 None
0x082  0 tc  1  16  0 r  y .   5  5  5  1 .  .  0  0  0  0  0  0  0  8 1 None
0x083  0 tc  1  16  0 r  y .   5  5  5  1 .  .  0 16  0  0  0  0  0  0 0 None
0x084  0 tc  1  16  0 r  y .   5  5  5  1 .  .  0 16  0  0  0  0  0  8 1 None
0x085  0 tc  1  16  0 r  y .   5  5  5  1 .  .  0 24  0  0  0  0  0  0 0 None
0x086  0 tc  1  16  0 r  y .   5  5  5  1 .  .  0 24  0  0  0  0  0  8 1 None
0x087  0 tc  1  16  0 r  y .   5  5  5  1 .  .  0 32  0  0  0  0  0  0 0 None
0x088  0 tc  1  16  0 r  y .   5  5  5  1 .  .  0 32  0  0  0  0  0  8 1 None
0x089 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0  0  0  0  0  0  0  0 0 None
0x08a 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0  0  0  0  0  0  0  8 1 None
0x08b 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 16  0  0  0  0  0  0 0 None
0x08c 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 16  0  0  0  0  0  8 1 None
0x08d 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 24  0  0  0  0  0  0 0 None
0x08e 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 24  0  0  0  0  0  8 1 None
0x08f 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 32  0  0  0  0  0  0 0 None
0x090 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 32  0  0  0  0  0  8 1 None
0x091  0 tc  1  16  0 r  y .   5  5  5  1 .  .  0  0  8  0  0  0  0  0 0 None
0x092  0 tc  1  16  0 r  y .   5  5  5  1 .  .  0  0  8  0  0  0  0  8 1 None
0x093  0 tc  1  16  0 r  y .   5  5  5  1 .  .  0 16  8  0  0  0  0  0 0 None
0x094  0 tc  1  16  0 r  y .   5  5  5  1 .  .  0 16  8  0  0  0  0  8 1 None
0x095  0 tc  1  16  0 r  y .   5  5  5  1 .  .  0 24  8  0  0  0  0  0 0 None
0x096  0 tc  1  16  0 r  y .   5  5  5  1 .  .  0 24  8  0  0  0  0  8 1 None
0x097  0 tc  1  16  0 r  y .   5  5  5  1 .  .  0 32  8  0  0  0  0  0 0 None
0x098  0 tc  1  16  0 r  y .   5  5  5  1 .  .  0 32  8  0  0  0  0  8 1 None
0x099 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0  0  8  0  0  0  0  0 0 None
0x09a 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0  0  8  0  0  0  0  8 1 None
0x09b 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 16  8  0  0  0  0  0 0 None
0x09c 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 16  8  0  0  0  0  8 1 None
0x09d 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 24  8  0  0  0  0  0 0 None
0x09e 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 24  8  0  0  0  0  8 1 None
0x09f 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 32  8  0  0  0  0  0 0 None
0x0a0 24 tc  1  32  0 r  y .   8  8  8  8 .  .  0 32  8  0  0  0  0  8 1 None
0x0a1  0 tc  1  16  0 r  . .   5  5  5  1 .  .  2  0  0  0  0  0  0  0 0 None
0x0a2  0 tc  1  16  0 r  . .   5  5  5  1 .  .  2  0  0  0  0  0  0  8 1 None
0x0a3  0 tc  1  16  0 r  . .   5  5  5  1 .  .  2 16  0  0  0  0  0  0 0 None
0x0a4  0 tc  1  16  0 r  . .   5  5  5  1 .  .  2 16  0  0  0  0  0  8 1 None
0x0a5  0 tc  1  16  0 r  . .   5  5  5  1 .  .  2 24  0  0  0  0  0  0 0 None
0x0a6  0 tc  1  16  0 r  . .   5  5  5  1 .  .  2 24  0  0  0  0  0  8 1 None
0x0a7  0 tc  1  16  0 r  . .   5  5  5  1 .  .  2 32  0  0  0  0  0  0 0 None
0x0a8  0 tc  1  16  0 r  . .   5  5  5  1 .  .  2 32  0  0  0  0  0  8 1 None
0x0a9 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2  0  0  0  0  0  0  0 0 None
0x0aa 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2  0  0  0  0  0  0  8 1 None
0x0ab 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 16  0  0  0  0  0  0 0 None
0x0ac 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 16  0  0  0  0  0  8 1 None
0x0ad 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 24  0  0  0  0  0  0 0 None
0x0ae 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 24  0  0  0  0  0  8 1 None
0x0af 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 32  0  0  0  0  0  0 0 None
0x0b0 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 32  0  0  0  0  0  8 1 None
0x0b1  0 tc  1  16  0 r  . .   5  5  5  1 .  .  2  0  8  0  0  0  0  0 0 None
0x0b2  0 tc  1  16  0 r  . .   5  5  5  1 .  .  2  0  8  0  0  0  0  8 1 None
0x0b3  0 tc  1  16  0 r  . .   5  5  5  1 .  .  2 16  8  0  0  0  0  0 0 None
0x0b4  0 tc  1  16  0 r  . .   5  5  5  1 .  .  2 16  8  0  0  0  0  8 1 None
0x0b5  0 tc  1  16  0 r  . .   5  5  5  1 .  .  2 24  8  0  0  0  0  0 0 None
0x0b6  0 tc  1  16  0 r  . .   5  5  5  1 .  .  2 24  8  0  0  0  0  8 1 None
0x0b7  0 tc  1  16  0 r  . .   5  5  5  1 .  .  2 32  8  0  0  0  0  0 0 None
0x0b8  0 tc  1  16  0 r  . .   5  5  5  1 .  .  2 32  8  0  0  0  0  8 1 None
0x0b9 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2  0  8  0  0  0  0  0 0 None
0x0ba 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2  0  8  0  0  0  0  8 1 None
0x0bb 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 16  8  0  0  0  0  0 0 None
0x0bc 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 16  8  0  0  0  0  8 1 None
0x0bd 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 24  8  0  0  0  0  0 0 None
0x0be 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 24  8  0  0  0  0  8 1 None
0x0bf 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 32  8  0  0  0  0  0 0 None
0x0c0 24 tc  1  32  0 r  . .   8  8  8  8 .  .  2 32  8  0  0  0  0  8 1 None
0x0c1  0 tc  1  16  0 r  y .   5  5  5  1 .  .  2  0  0  0  0  0  0  0 0 None
0x0c2  0 tc  1  16  0 r  y .   5  5  5  1 .  .  2  0  0  0  0  0  0  8 1 None
0x0c3  0 tc  1  16  0 r  y .   5  5  5  1 .  .  2 16  0  0  0  0  0  0 0 None
0x0c4  0 tc  1  16  0 r  y .   5  5  5  1 .  .  2 16  0  0  0  0  0  8 1 None
0x0c5  0 tc  1  16  0 r  y .   5  5  5  1 .  .  2 24  0  0  0  0  0  0 0 None
0x0c6  0 tc  1  16  0 r  y .   5  5  5  1 .  .  2 24  0  0  0  0  0  8 1 None
0x0c7  0 tc  1  16  0 r  y .   5  5  5  1 .  .  2 32  0  0  0  0  0  0 0 None
0x0c8  0 tc  1  16  0 r  y .   5  5  5  1 .  .  2 32  0  0  0  0  0  8 1 None
0x0c9 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2  0  0  0  0  0  0  0 0 None
0x0ca 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2  0  0  0  0  0  0  8 1 None
0x0cb 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 16  0  0  0  0  0  0 0 None
0x0cc 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 16  0  0  0  0  0  8 1 None
0x0cd 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 24  0  0  0  0  0  0 0 None
0x0ce 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 24  0  0  0  0  0  8 1 None
0x0cf 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 32  0  0  0  0  0  0 0 None
0x0d0 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 32  0  0  0  0  0  8 1 None
0x0d1  0 tc  1  16  0 r  y .   5  5  5  1 .  .  2  0  8  0  0  0  0  0 0 None
0x0d2  0 tc  1  16  0 r  y .   5  5  5  1 .  .  2  0  8  0  0  0  0  8 1 None
0x0d3  0 tc  1  16  0 r  y .   5  5  5  1 .  .  2 16  8  0  0  0  0  0 0 None
0x0d4  0 tc  1  16  0 r  y .   5  5  5  1 .  .  2 16  8  0  0  0  0  8 1 None
0x0d5  0 tc  1  16  0 r  y .   5  5  5  1 .  .  2 24  8  0  0  0  0  0 0 None
0x0d6  0 tc  1  16  0 r  y .   5  5  5  1 .  .  2 24  8  0  0  0  0  8 1 None
0x0d7  0 tc  1  16  0 r  y .   5  5  5  1 .  .  2 32  8  0  0  0  0  0 0 None
0x0d8  0 tc  1  16  0 r  y .   5  5  5  1 .  .  2 32  8  0  0  0  0  8 1 None
0x0d9 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2  0  8  0  0  0  0  0 0 None
0x0da 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2  0  8  0  0  0  0  8 1 None
0x0db 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 16  8  0  0  0  0  0 0 None
0x0dc 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 16  8  0  0  0  0  8 1 None
0x0dd 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 24  8  0  0  0  0  0 0 None
0x0de 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 24  8  0  0  0  0  8 1 None
0x0df 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 32  8  0  0  0  0  0 0 None
0x0e0 24 tc  1  32  0 r  y .   8  8  8  8 .  .  2 32  8  0  0  0  0  8 1 None
```
