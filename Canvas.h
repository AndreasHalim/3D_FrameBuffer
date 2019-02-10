/* Canvas.h */

#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h> 
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <cstring>
class Canvas {
	private:
		const std::string FRAMEBUFFER_DEVICE_LOCATION = "/dev/fb0";
		int framebuffer_device = 0;
		char *framebuffer = 0;
		long int screen_memory_size = 0;
		struct fb_var_screeninfo vinfo;
		struct fb_fix_screeninfo finfo;
    	struct fb_var_screeninfo orig_vinfo;
		
	public:
		Canvas();
		~Canvas();
};

#endif
