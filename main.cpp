#include <QCoreApplication>
#include <iostream>
#include <string>
using namespace std;

#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>

#include <cups/cups.h>

#include "cairopp.h"
using namespace cairopp;

// A4 width, height in points, from GhostView manual:
//   http://www.gnu.org/software/gv/manual/html_node/Paper-Keywords-and-paper-size-in-points.html
#define WIDTH  595
#define HEIGHT 842

void enumPrinters(void)
{
    cups_dest_t *dests, *dest = nullptr;
    int num_dests = cupsGetDests(&dests);
    int i;
    for(i = 0, dest = dests; i < num_dests; i++, dest++)
    {
        if(dest->instance == nullptr)
        {
            /* do something with dest */
            ui->cbPrinters->addItem(dest->name);
        }
    }

    cupsFreeDests(num_dests, dests);
}

int main()
{
//    QCoreApplication a(argc, argv);
//    return a.exec();

    const char* tmpfilename = "/home/marcos/teste.svg";
    CSurface surface(tmpfilename, CSurface::types::SVG, WIDTH, HEIGHT);
    if(!surface.ok())
    {
        cout << "Erro criando surface." << endl;
        return 0;
    }

    CContext ctx(surface);

    // draw some text
    ctx.select_font_face("Arial Black",
                           CAIRO_FONT_SLANT_NORMAL,
                           CAIRO_FONT_WEIGHT_NORMAL);
    ctx.set_font_size(30);
    ctx.move_to(WIDTH/2, HEIGHT/2);
    ctx.show_text("Hello Cairo++"); // the text we got as a parameter

    // draw a dotted box
    const double pattern[] = {15.0, 1.0};
    ctx.set_dash(pattern, 2, 0);
    ctx.set_line_width(5);
    ctx.rectangle(WIDTH*0.33, HEIGHT*0.33, WIDTH*0.5, WIDTH*0.5);
    ctx.stroke();

    // finish up
    ctx.show_page();

    return 0;
}
