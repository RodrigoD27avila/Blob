    #include <stdio.h>  
    #include <fcntl.h>  
    #include <stdlib.h>  
    #include <errno.h>  
    #include <sys/mman.h>  
    #include <linux/fb.h>  
      
    #define FBDEV "/dev/fb0"  
    static char * default_framebuffer = FBDEV;  
      
    struct fb_dev  
    {  
        int fb;  
        void * fb_mem;  
        int fb_width,fb_height,fb_line_len,fb_size;  
        int fb_bpp;  
    };  
      
    static struct fb_dev fbdev;  
    #if 0  
    static void draw(int color)  
    {  
        int i,j;  
        unsigned short int *p = (unsigned short int*)fbdev.fb_mem;  
      
        for(i=0;i<fbdev.fb_height;i++,p+=fbdev.fb_line_len/2)  
        {  
            for(j=0;j<fbdev.fb_width;j++)  
                p[j] = color;  
        }  
      
    }  
    #endif  
      
    static void draw(void)  
    {  
        int i,j;  
        unsigned short int *p = (unsigned short int *)fbdev.fb_mem;  
          
        for(i=0;i<fbdev.fb_height;i++)  
        {  
            if(i<fbdev.fb_height/2)  
                for(j=0;j<fbdev.fb_width;j++)  
                    *p++ = 0xf800;  
            else  
                for(j=1;j<fbdev.fb_width;j++)  
                    *p++ = 0x1f;  
        }                 
    }             
    int framebuffer_open(void)  
    {  
        int fb;  
        struct fb_var_screeninfo fb_vinfo;  
        struct fb_fix_screeninfo fb_finfo;  
        char * fb_dev_name = NULL;  
      
        if(!(fb_dev_name = getenv("FRAMEBUFFER")))  
            fb_dev_name = default_framebuffer;  
      
        fb = open(fb_dev_name,O_RDWR);  
        if(fb<0)  
        {  
            printf("device %s open failed\n",fb_dev_name);  
            return -1;  
        }  
      
        if(ioctl(fb,FBIOGET_VSCREENINFO,&fb_vinfo))  
        {  
            printf("Can't get VSCREENINFO:%s\n",strerror(errno));  
            close(fb);  
            return -1;  
        }  
        ioctl(fb, FBIOPUT_VSCREENINFO, &fb_vinfo);  
      
        if(ioctl(fb,FBIOGET_FSCREENINFO,&fb_finfo))  
        {  
            printf("Can't get FSCREENINFO:%s\n",strerror(errno));  
            return -1;  
        }  
      
        fbdev.fb_bpp = fb_vinfo.red.length + fb_vinfo.green.length + fb_vinfo.blue.length + fb_vinfo.transp.length;  
      
        fbdev.fb_width = fb_vinfo.xres;  
        fbdev.fb_height = fb_vinfo.yres;  
        fbdev.fb_line_len = fb_finfo.line_length;  
        fbdev.fb_size = fb_finfo.smem_len;  
      
      
        printf("frame buffer:%d(%d)x%d,%dbpp,0x%xbyte\n",fbdev.fb_width,fbdev.fb_line_len,fbdev.fb_height,fbdev.fb_bpp,fbdev.fb_size);  
        if(fbdev.fb_bpp !=16)  
        {  
            printf("frame buffer must be 16bpp mode\n");  
            exit(0);  
        }  
      
        fbdev.fb_mem = mmap(NULL,fbdev.fb_size,PROT_READ|PROT_WRITE,MAP_SHARED,fb,0);  
        if(fbdev.fb_mem == NULL || (int)fbdev.fb_mem == -1)  
        {  
            fbdev.fb_mem = NULL;  
            printf("mmap failed\n");  
            close(fb);  
            return -1;  
        }  
      
        fbdev.fb = fb;  
        memset(fbdev.fb_mem,0x0,fbdev.fb_size);  
        return 0;  
    }  
      
    void framebuffer_close()  
    {  
        if(fbdev.fb_mem)  
        {  
            munmap(fbdev.fb_mem,fbdev.fb_size);  
            fbdev.fb_mem = NULL;  
        }  
        if(fbdev.fb)  
        {  
            close(fbdev.fb);  
            fbdev.fb =0;  
        }  
    }  
      
      
    int main(void)  
    {  
    //  int i;  
        framebuffer_open();  
    #if 0  
        for(i=0;i<16;i++)  
        {  
            printf("%d,color=0x%x",i,i<<i);  
            draw(1<<i);  
            getchar();  
          
        }  
    #endif  
        draw();  
        framebuffer_close();  
        return 0;  
    }  
