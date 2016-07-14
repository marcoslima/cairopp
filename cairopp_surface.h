#ifndef CAIROPP_SURFACE_H
#define CAIROPP_SURFACE_H

namespace cairopp
{

class CSurface
{
private:
    cairo_surface_t* _surface = nullptr;
    bool _bOk = false;

private:
    cairo_surface_t* get(void)
    {
        return _surface;
    }

    // Somente a CContext pode acessar esta funçao:
    friend class CContext;

public:
    typedef enum class types
    {
        PDF,
        PS,
        SVG
    } type_t;

public:
    ~CSurface()
    {
        if(_surface != nullptr)
        {
            cairo_surface_flush(_surface);
            cairo_surface_destroy(_surface);
        }
    }

    CSurface(const std::string sFilename, type_t type, size_t nWidth, size_t nHeight)
    {
        switch(type)
        {
        case types::PDF:
            _surface = cairo_pdf_surface_create(sFilename.c_str(), nWidth, nHeight);
            break;
        case types::PS:
            _surface = cairo_ps_surface_create(sFilename.c_str(), nWidth, nHeight);
            break;
        case types::SVG:
            _surface = cairo_svg_surface_create(sFilename.c_str(), nWidth, nHeight);
            break;
        }

        _bOk = _surface != nullptr;
        return;
    }

    bool ok(void){return _bOk;}

}; // class CSurface


} // namespace cairopp

#endif // CAIROPP_SURFACE_H
