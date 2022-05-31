#include "fractol.h"
void    zoom_compute(t_meta *meta, int sign);

void    zoom(t_meta *meta, int x, int y, int sign)
{
    double  backup_w;
    double  backup_h;
    double  new_zoom_w;
    double  new_zoom_h;
    t_comp  *cp;

    cp = meta->comp;
    backup_w = cp->rerange;
    backup_h = cp->imrange;
    zoom_compute(meta, sign);
    new_zoom_w = cp->rerange;
    new_zoom_h = cp->imrange;
    // top x axis limit = x / width -0.5 (to center) * (range_b4_compute - range_after_compute) * 2
    cp->remax -= (x / WW - 0.5) * (new_zoom_w - backup_w) * 2;
    cp->remin -= (x / WW - 0.5) * (new_zoom_w - backup_w) * 2;
    cp->imax -= (y / WH - 0.5) * (new_zoom_h - backup_h) * 2;
    cp->imin -= (y / WH - 0.5) * (new_zoom_h - backup_h) * 2;
    zoom_compute(meta, sign);
}

void    zoom_compute(t_meta *meta, int sign)
{
    double  backre;
    double  backim;
    //double  dre;
    //double  dim;
    t_comp  *cp;

    cp = meta->comp;
    backre = cp->rerange;
    backim = cp->imrange;
    if (sign == 1)
    {
        cp->rerange /= 1.1;
        cp->imrange /= 1.1;
    }
    else
    {
        cp->rerange *= 1.1;
        cp->imrange *= 1.1;
    }
    cp->remin -= (cp->rerange - backre) / 2;
    cp->remax += (cp->rerange - backre) / 2;
    cp->imin -= (cp->imrange - backim) / 2;
    cp->imax += (cp->imrange - backim) / 2;
    if (sign == 1)
        cp->itermax++;
    else if (sign == -1 && cp->itermax > 50)
        cp->itermax--;
}
