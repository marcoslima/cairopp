#ifndef CAIROPP_CONTEXT_H
#define CAIROPP_CONTEXT_H

#include "cairopp_surface.h"

namespace cairopp
{

class CContext
{
private:
    cairo_t * _context = nullptr;

public:
    CContext(CSurface& surface)
    {
        _context = cairo_create(surface.get());
    }

    ~CContext()
    {
        cairo_destroy(_context);
    }

    // Wrappler simples: cada funçao da api que recebe cairo_t* como parametro e reproduzida
    // aqui com a unica diferença de nao ter o parametro cairo_t* (e nem o prefixo "cairo_" no nome da funçao).
    inline void
    save(void)
    {
        cairo_save(_context);
    }

    inline void
    restore(void)
    {
        cairo_restore(_context);
    }

    inline void
    push_group(void)
    {
        cairo_push_group(_context);
    }

    inline void
    push_group_with_content(cairo_content_t content)
    {
        cairo_push_group_with_content(_context, content);
    }

    inline cairo_pattern_t *
    pop_group(void)
    {
        return cairo_pop_group(_context);
    }

    inline void
    pop_group_to_source(void)
    {
        cairo_pop_group_to_source(_context);
    }


    inline void
    set_operator(cairo_operator_t op)
    {
        cairo_set_operator(_context, op);
    }

    inline void
    set_source(cairo_pattern_t *source)
    {
        cairo_set_source(_context, source);
    }

    inline void
    set_source_rgb(double red, double green, double blue)
    {
        cairo_set_source_rgb(_context, red, green, blue);
    }

    inline void
    set_source_rgba(double red, double green, double blue, double alpha)
    {
        cairo_set_source_rgba(_context, red,  green,  blue, alpha);
    }

    inline void
    set_source_surface(cairo_surface_t *surface,
                  double	   x,
                  double	   y)
    {
        cairo_set_source_surface(_context, surface, x, y);
    }

    inline void
    set_tolerance(double tolerance)
    {
        cairo_set_tolerance(_context, tolerance);
    }
    inline void
    set_antialias(cairo_antialias_t antialias)
    {
        cairo_set_antialias(_context, antialias);
    }
    inline void
    set_fill_rule(cairo_fill_rule_t fill_rule)
    {
        cairo_set_fill_rule(_context, fill_rule);
    }
    inline void
    set_line_width(double width)
    {
        cairo_set_line_width(_context, width);
    }
    inline void
    set_line_cap(cairo_line_cap_t line_cap)
    {
        cairo_set_line_cap(_context, line_cap);
    }
    inline void
    set_line_join(cairo_line_join_t line_join)
    {
        cairo_set_line_join(_context, line_join);
    }
    inline void
    set_dash(const double *dashes,
            int	      num_dashes,
            double	      offset)
    {
        cairo_set_dash(_context, dashes, num_dashes, offset);
    }
    inline void
    set_miter_limit(double limit)
    {
        cairo_set_miter_limit(_context, limit);
    }

    inline void
    translate(double tx, double ty)
    {
        cairo_translate(_context, tx, ty);
    }
    inline void
    scale(double sx, double sy)
    {
        cairo_scale(_context, sx, sy);
    }
    inline void
    rotate(double angle)
    {
        cairo_rotate(_context, angle);
    }

    inline void
    transform(const cairo_matrix_t *matrix)
    {
        cairo_transform(_context, matrix);
    }
    inline void
    set_matrix(const cairo_matrix_t *matrix)
    {
        cairo_set_matrix(_context, matrix);
    }
    inline void
    identity_matrix(void)
    {
        cairo_identity_matrix(_context);
    }
    inline void
    user_to_device(double *x, double *y)
    {
        cairo_user_to_device(_context, x, y);
    }
    inline void
    user_to_device_distance(double *dx, double *dy)
    {
        cairo_user_to_device_distance(_context, dx, dy);
    }
    inline void
    device_to_user(double *x, double *y)
    {
        cairo_device_to_user(_context, x, y);
    }
    inline void
    device_to_user_distance(double *dx, double *dy)
    {
        cairo_device_to_user_distance(_context, dx, dy);
    }
    inline void
    new_path(void)
    {
        cairo_new_path(_context);
    }
    inline void
    move_to(double x, double y)
    {
        cairo_move_to(_context, x, y);
    }
    inline void
    new_sub_path(void)
    {
        cairo_new_sub_path(_context);
    }
    inline void
    line_to(double x, double y)
    {
        cairo_line_to(_context, x, y);
    }
    inline void
    curve_to(double x1, double y1,
            double x2, double y2,
            double x3, double y3)
    {
        cairo_curve_to(_context, x1, y1, x2, y2, x3, y3);
    }
    inline void
    arc(double xc, double yc,
           double radius,
           double angle1, double angle2)
    {
        cairo_arc(_context, xc, yc, radius, angle1, angle2);
    }
    inline void
    arc_negative(double xc, double yc,
                double radius,
                double angle1, double angle2)
    {
        cairo_arc_negative(_context, xc, yc, radius, angle1, angle2);
    }
    inline void
    rel_move_to(double dx, double dy)
    {
        cairo_rel_move_to(_context, dx, dy);
    }
    inline void
    rel_line_to(double dx, double dy)
    {
        cairo_rel_line_to(_context, dx, dy);
    }
    inline void
    rel_curve_to(double dx1, double dy1,
                double dx2, double dy2,
                double dx3, double dy3)
    {
        cairo_rel_curve_to(_context, dx1, dy1, dx2, dy2, dx3, dy3);
    }
    inline void
    rectangle(double x, double y,
             double width, double height)
    {
        cairo_rectangle(_context, x, y, width, height);
    }
    inline void
    close_path(void)
    {
        cairo_close_path(_context);
    }
    inline void
    path_extents(double *x1, double *y1,
                double *x2, double *y2)
    {
        cairo_path_extents(_context, x1, y1, x2, y2);
    }
    inline void
    paint(void)
    {
        cairo_paint(_context);
    }
    inline void
    paint_with_alpha(double   alpha)
    {
        cairo_paint_with_alpha(_context, alpha);
    }

    inline void
    mask(cairo_pattern_t *pattern)
    {
        cairo_mask(_context, pattern);
    }

    inline void
    mask_surface(cairo_surface_t *surface,
                double           surface_x,
                double           surface_y)
    {
        cairo_mask_surface(_context, surface, surface_x, surface_y);
    }
    inline void
    stroke(void)
    {
        cairo_stroke(_context);
    }
    inline void
    stroke_preserve()
    {
        cairo_stroke_preserve(_context);
    }
    inline void
    fill(void)
    {
        cairo_fill(_context);
    }
    inline void
    fill_preserve(void)
    {
        cairo_fill_preserve(_context);
    }
    inline void
    copy_page(void)
    {
        cairo_copy_page(_context);
    }
    inline void
    show_page(void)
    {
        cairo_show_page(_context);
    }
    inline cairo_bool_t
    in_stroke(double x, double y)
    {
        return cairo_in_stroke(_context, x, y);
    }
    inline cairo_bool_t
    in_fill(double x, double y)
    {
        return cairo_in_fill(_context, x, y);
    }
    inline cairo_bool_t
    in_clip(double x, double y)
    {
        return cairo_in_clip(_context, x, y);
    }
    inline void
    stroke_extents(double *x1, double *y1,
                  double *x2, double *y2)
    {
        cairo_stroke_extents(_context, x1, y1, x2, y2);
    }
    inline void
    fill_extents(double *x1, double *y1,
                double *x2, double *y2)
    {
        cairo_fill_extents(_context, x1, y1, x2, y2);
    }
    inline void
    reset_clip(void)
    {
        cairo_reset_clip(_context);
    }
    inline void
    clip(void)
    {
        cairo_clip(_context);
    }
    inline void
    clip_preserve(void)
    {
        cairo_clip_preserve(_context);
    }
    inline void
    clip_extents(double *x1, double *y1,
                double *x2, double *y2)
    {
        cairo_clip_extents(_context, x1, y1, x2, y2);
    }
    inline cairo_rectangle_list_t *
    copy_clip_rectangle_list(void)
    {
        return cairo_copy_clip_rectangle_list(_context);
    }

    inline void
    rectangle_list_destroy(cairo_rectangle_list_t *rectangle_list)
    {
        cairo_rectangle_list_destroy(rectangle_list);
    }

    inline void
    select_font_face(const char           *family,
                cairo_font_slant_t   slant,
                cairo_font_weight_t  weight)
    {
        cairo_select_font_face(_context, family, slant, weight);
    }
    inline void
    set_font_size(double size)
    {
        cairo_set_font_size(_context, size);
    }
    inline void
    set_font_matrix(const cairo_matrix_t *matrix)
    {
        cairo_set_font_matrix(_context, matrix);
    }
    inline void
    get_font_matrix(cairo_matrix_t *matrix)
    {
        cairo_get_font_matrix(_context, matrix);
    }
    inline void
    set_font_options(const cairo_font_options_t *options)
    {
        cairo_set_font_options(_context, options);
    }
    inline void
    get_font_options(cairo_font_options_t *options)
    {
        cairo_get_font_options(_context, options);
    }
    inline void
    set_font_face(cairo_font_face_t *font_face)
    {
        cairo_set_font_face(_context, font_face);
    }
    inline cairo_font_face_t *
    get_font_face(void)
    {
        return cairo_get_font_face(_context);
    }
    inline void
    set_scaled_font(const cairo_scaled_font_t *scaled_font)
    {
        cairo_set_scaled_font(_context, scaled_font);
    }
    inline cairo_scaled_font_t *
    get_scaled_font(void)
    {
        return cairo_get_scaled_font(_context);
    }

    inline void
    show_text(const char *utf8)
    {
        cairo_show_text(_context, utf8);
    }
    inline void
    show_glyphs(const cairo_glyph_t *glyphs, int num_glyphs)
    {
        cairo_show_glyphs(_context, glyphs, num_glyphs);
    }
    inline void
    show_text_glyphs(const char		   *utf8,
                int			    utf8_len,
                const cairo_glyph_t	   *glyphs,
                int			    num_glyphs,
                const cairo_text_cluster_t *clusters,
                int			    num_clusters,
                cairo_text_cluster_flags_t  cluster_flags)
    {
        cairo_show_text_glyphs(_context, utf8, utf8_len, glyphs, num_glyphs,
            clusters, num_clusters, cluster_flags);
    }
    inline void
    text_path(const char *utf8)
    {
        cairo_text_path(_context, utf8);
    }
    inline void
    glyph_path(const cairo_glyph_t *glyphs, int num_glyphs)
    {
        cairo_glyph_path(_context, glyphs, num_glyphs);
    }
    inline void
    text_extents(const char    	 *utf8,
                cairo_text_extents_t *extents)
    {
        cairo_text_extents(_context, utf8, extents);
    }
    inline void
    glyph_extents(const cairo_glyph_t   *glyphs,
                 int                   num_glyphs,
                 cairo_text_extents_t  *extents)
    {
        cairo_glyph_extents(_context, glyphs, num_glyphs, extents);
    }
    inline void
    font_extents(cairo_font_extents_t *extents)
    {
        cairo_font_extents(_context, extents);
    }


    /* Query functions */
    inline cairo_operator_t
    get_operator(void)
    {
        return cairo_get_operator(_context);
    }

    inline cairo_pattern_t *
    get_source(void)
    {
        return cairo_get_source(_context);
    }

    inline double
    get_tolerance(void)
    {
        return cairo_get_tolerance(_context);
    }

    inline cairo_antialias_t
    get_antialias(void)
    {
        return cairo_get_antialias(_context);
    }

    inline cairo_bool_t
    has_current_point(void)
    {
        return cairo_has_current_point(_context);
    }

    inline void
    get_current_point(double *x, double *y)
    {
        cairo_get_current_point(_context, x, y);
    }
    inline cairo_fill_rule_t
    get_fill_rule(void)
    {
        return cairo_get_fill_rule(_context);
    }
    inline double
    get_line_width(void)
    {
        return cairo_get_line_width(_context);
    }
    inline cairo_line_cap_t
    get_line_cap(void)
    {
        return cairo_get_line_cap(_context);
    }

    inline cairo_line_join_t
    get_line_join(void)
    {
        return cairo_get_line_join(_context);
    }
    inline double
    get_miter_limit(void)
    {
        return cairo_get_miter_limit(_context);
    }

    inline int
    get_dash_count(void)
    {
        return cairo_get_dash_count(_context);
    }

    inline void
    get_dash(double *dashes, double *offset)
    {
        cairo_get_dash(_context, dashes, offset);
    }

    inline void
    get_matrix(cairo_matrix_t *matrix)
    {
        cairo_get_matrix(_context, matrix);
    }

    inline cairo_surface_t *
    get_target(void)
    {
        return cairo_get_target(_context);
    }

    inline cairo_surface_t *
    get_group_target(void)
    {
        return cairo_get_group_target(_context);
    }

    inline cairo_path_t *
    copy_path(void)
    {
        return cairo_copy_path(_context);
    }

    inline cairo_path_t *
    copy_path_flat(void)
    {
        return cairo_copy_path_flat(_context);
    }

    inline void
    append_path(const cairo_path_t	*path)
    {
        cairo_append_path(_context, path);
    }

    /* Error status queries */
    inline cairo_status_t
    status(void)
    {
        return cairo_status(_context);
    }

}; // class CContext

} // namespace cairopp

#endif // CAIROPP_CONTEXT_H
