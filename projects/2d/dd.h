//----------------------------------------------------------------------------
// ???????????????????????????????????????
// ???????????????????????????????????????
// Copyright (C) 2011 Rodrigo D'avila
// Contact: r0dra42@gmail.com
// 
// ??? is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
// 
// ??? is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with AGG; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, 
// MA 02110-1301, USA.
//----------------------------------------------------------------------------


#ifndef DD_H
#define DD_H

#include <string.h>

namespace dd
{
    //-----------------------------------------------------------------------
    typedef signed char        int8;
    typedef unsigned char      uint8;
    typedef signed short       int16;
    typedef unsigned short     uint16;
    typedef signed int         int32;
    typedef unsigned int       uint32;
    typedef signed long long   int64;
    typedef unsigned long long uint64;

    //===================================================================
    struct rgba8
    {
        uint8 r; //Red
        uint8 g; //Green
        uint8 b; //Blue
        uint8 a; //Alpha

        //---------------------------------------------------------------
        rgba8() : r(0), g(0), b(0), a(0) {}

        //---------------------------------------------------------------
        rgba8(unsigned _r, unsigned _g, unsigned _b, unsigned _a) :
            r(uint8(_r)), g(uint8(_g)), b(uint8(_b)), a(uint8(_a))

        //---------------------------------------------------------------
        void opacity(double _a)
        {
            if (_a < 0.0)  _a = 0.0;
            if (_a > 1.0)  _a = 1.0;
            a = uint8(_a * 255.0);
        }

        //---------------------------------------------------------------
        double opacity() const
        {
            return double(a) / 255.0;
        }

        //---------------------------------------------------------------
        rgba8 gradient(rgba8 c, double k) const
        {
            rgba8 ret;
            int ik = int(k * 256);
            ret.r = uint8(int(r) + (((int(c.r) - int(r)) * ik) >> 8));
            ret.g = uint8(int(g) + (((int(c.g) - int(g)) * ik) >> 8));
            ret.b = uint8(int(b) + (((int(c.b) - int(b)) * ik) >> 8));
            ret.a = uint8(int(a) + (((int(c.a) - int(a)) * ik) >> 8));
            return ret;
        }

        //---------------------------------------------------------------
        rgba8 pre() const
        {
            return rgba8((r*a) >> 8, (g*a) >> 8, (b*a) >> 8, a);
        }
    }

    //===================================================================
    class rendering_buffer
    {
    public:
        ~rendering_buffer();

        //-------------------------------------------------Initialization
        rendering_buffer(unsigned char *buf
                         unsigned width,
                         unsigned height,
                         int      stride);

        //-------------------------------------------------Initialization
        void attach(unsigned char *buf
                    unsigned width,
                    unsigned height,
                    int      stride);

        //-------------------------------------------------------Acessors
        const unsigned char* buf()    const {return m_buf;   }
        unsigned             width()  const {return m_width; }
        unsigned             height() const {return m_height;}
        int                  stride() const {return m_stride;}

        bool inbox(int x, int y) const
        {
            return x >= 0 && y >= 0 && x < int(m_width) && y < int(m_height);
        }

        unsigned abs_stride() const
        {
            return (m_stride < 0) ? unsigned(-m_stride) : unsigned(m_stride);
        }

        unsigned char* row(unsigned y) {return m_rows[y];}
        const unsigned char* row(unsigned y) {return m_rows[y];}

    private:
        rendering_buffer(const rendering_buffer&);
        const rendering_buffer& operator= (const rendering_buffer&);

        unsigned char*  m_buf;        // Pointer to rendering buffer
        unsigned char** m_rows;       // Pointers to earch row of the buffer
        unsigned        m_width;      // Width in pixels
        unsigned        m_height;     // Height in pixels
        int             m_stride;     // Number of bytes per row. Can be < 0
        unsigned        m_max_height; // Maximal current height
    };

    //===================================================================
    class scanline
    {
    public:
        enum {aa_shift = 8};

        class iterator
        {
        public:
            iterator(const scanline& sl) :
                m_covers(sl.m_covers),
                m_cur_count(sl.m_counts),
                m_cur_start_ptr(sl.m_start_ptrs)
            {
            }

            int next()
            {
                ++m_cur_count;
                ++m_cur_start_ptr;
                return int(*m_cur_start_ptr - m_counts);
            }

            int num_pix() const {return int(*m_cur_start_ptr);}
            const uint8* covers() const {return *m_cur_start_ptr;}

        private:
            const uint8*        m_covers;
            const uint16*       m_cur_count;
            const uint8* const* m_cur_start_ptr;
        };

        friend class iterator;

        ~scanline();
        scanline();

        void     reset(int min_x, int max_x, int dx=0, int dy=0);

        void     reset_spans();
        void     add_cell(int x, int y, unsigned cover);
        void     add_span(int x, int y, unsigned len, unsigned cover);
        int      is_ready(int y) const;
        int      base_x()         const {return m_min_x + m_dx;}
        int      y()              const {return m_last_y + m_dy;}
        unsigned num_spans() const {return m_num_spans;}

    private:
        scanline(const scanline&);
        const scanline operator= (const scanline&);

        int      m_min_x;
        unsigned m_max_len;
        int      m_dx;
        int      m_dy;
        int      m_last_x;
        int      m_last_y;
        uint8*   m_covers;
        uint8**  m_start_ptrs;
        uint16*  m_counts;
        unsigned m_num_spans;
        uint8**  m_cur_start_ptr;
        uint16*  m_cur_count;
    };

    //-------------------------------------------------------------------
    inline void scanline::reset_spans()
    {
        m_last_x        = 0x7FFF;
        m_last_y        = 0x7FFF;
        m_cur_count     = m_counts;
        m_cur_start_ptr = m_start_ptrs;
        m_num_spans     = 0;
    }


};
#endif //DD_H

