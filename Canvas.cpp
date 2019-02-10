#include "Canvas.h"

Canvas::Canvas(){
    long int screen_memory_size = 0;
    // Open the file for reading and writing
    framebuffer_device = open(FRAMEBUFFER_DEVICE_LOCATION.c_str(), O_RDWR);
    if(framebuffer_device){
        // Get variable screen information
        if(!ioctl(framebuffer_device, FBIOGET_VSCREENINFO, &vinfo)){
         // Store for reset (copy vinfo to vinfo_orig)
            memcpy(&orig_vinfo, &vinfo, sizeof(struct fb_var_screeninfo));
            // Get fixed screen information
            if(!ioctl(framebuffer_device, FBIOGET_FSCREENINFO, &finfo)){
                // map fb to user mem 
                screen_memory_size = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
                framebuffer = (char*)mmap(0, screen_memory_size, PROT_READ | PROT_WRITE, MAP_SHARED, framebuffer_device, 0);
            }
        }
    }
}

Canvas::~Canvas(){
    munmap(framebuffer, screen_memory_size);
    ioctl(framebuffer_device, FBIOPUT_VSCREENINFO, &orig_vinfo);
    close(framebuffer_device);
}