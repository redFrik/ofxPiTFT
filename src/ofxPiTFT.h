//
//  FtfMirror.h
//
//  Thanks to Matt Bell
//  http://forum.openframeworks.cc/t/pitft-adafruit-tft-touchscreen/15107/5
//
//  https://github.com/notro/fbtft
//
//  And Mark Williams
//  https://github.com/mwilliams03/Pi-Touchscreen-basic

#include "ofMain.h"

#ifdef TARGET_RASPBERRY_PI
#include <stdio.h>
#include <syslog.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <linux/input.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <bcm_host.h>

#include "linux_events.h"
#endif

class ofxPiTFT{
public:
    ofxPiTFT();
    ~ofxPiTFT();
    
    void setupTouchEvents(ofBaseApp *_app);
    
    void update(ofEventArgs & args);
    void draw(ofEventArgs & args);
    void exit(ofEventArgs & args);
    
private:
    
    ofBaseApp *app;
    
    void getTouchScreenDetails(int *screenXmin,int *screenXmax,int *screenYmin,int *screenYmax);
    void getTouchSample(int *rawX, int *rawY, int *rawPressure);
    int fd;
    int screenXmax, screenXmin;
	int screenYmax, screenYmin;
    int rawX, rawY, rawPressure;
	float scaleXvalue, scaleYvalue;
    
#ifdef TARGET_RASPBERRY_PI
    //DISPMANX_DISPLAY_HANDLE_T display;
    int display;
    DISPMANX_MODEINFO_T display_info;
    
    //DISPMANX_RESOURCE_HANDLE_T screen_resource;
    int screen_resource;
    VC_IMAGE_TRANSFORM_T transform;
    uint32_t image_prt;
    VC_RECT_T rect1;
    
    int ret;
    int fbfd;
    char *fbp;
    
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
#endif
};