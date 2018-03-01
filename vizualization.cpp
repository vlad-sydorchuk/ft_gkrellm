#include <iostream>

#include "Window.h"
#include "Rect.h"
#include "libraries/SDL/SDL2_image.framework/Versions/A/Headers/SDL_image.h"
#include "libraries/SDL/SDL2.framework/Versions/A/Headers/SDL.h"
#include "libraries/SDL/SDL2_ttf.framework/Versions/A/Headers/SDL_ttf.h"

#include "Text.h"
#include "AllInfo.h"
#include "HostUserName.h"
#include "OsInfo.h"
#include "DataTime.h"
#include "Cpu.h"
#include "Ram.h"
#include "Network.h"

int vizualization(void)
{
    Window window("Rush01", 800, 600);

    Rect rect(100, 100, 0, 0, 100, 100, 100, 255);
    
    Rect rectImg(80, 80, 330, 411, "res/img/battery.png");
    
    int font_size = 35;
    Text text (font_size);

    AllInfo allInfo("e3r5p10.unit.ua", 28);
    HostUserName hostUser(35);
    OsInfo osInfo(35);
    DataTime dataTime(35);
    Cpu cpu(35);
    Ram ram(35);
    Network net(35);

    while (!window.isClosed())
    {

        rect.draw();
        
        
        rectImg.drawImg();
       	
        text.display(Window::renderer);
        
        if (window.getFlag() == 0)
            allInfo.showInfo(Window::renderer);
        else if (window.getFlag() == 1)
            hostUser.showInfo(Window::renderer);
        else if (window.getFlag() == 2)
            osInfo.showInfo(Window::renderer);
        else if (window.getFlag() == 3)
            dataTime.showInfo(Window::renderer);
        else if (window.getFlag() == 4)
            cpu.showInfo(Window::renderer);
        else if (window.getFlag() == 5)
            ram.showInfo(Window::renderer);
        else if (window.getFlag() == 6)
            net.showInfo(Window::renderer);
        window.update();
        window.pollEvents();
        window.clear();
        
    }
    return (0);
}